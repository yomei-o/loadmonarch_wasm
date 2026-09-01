// The native shell: a window, a CreateDIBSection surface, and StretchBlt -
// the same three things the original uses, so what works here transfers.
//
// Nothing of the game's logic lives in this file.  It loads a stage, scrolls
// it, and switches zoom; every pixel comes from render.c.
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "host.h"
#include "render.h"
#include "sim.h"
#include "state.h"
#include "world.h"

#define VIEW_W 640
#define VIEW_H 480
#define STAGES 15

static const char *kStages[STAGES] = {
    "B_000.MAP", "B_002.MAP", "B_003.MAP", "B_004.MAP", "B_005.MAP",
    "B_006.MAP", "B_009.MAP", "B_103.MAP", "B_104.MAP", "B_105.MAP",
    "S_101.MAP", "S_105.MAP", "S_115.MAP", "S_201.MAP", "T_000.MAP",
};

#define SIM_TIMER 1
#define SIM_TIMER_MS 50

typedef struct {
    GameState game;             // the world plus the entities and factions
    Sim sim;
    int running;
    Surface surface;
    HBITMAP dib;
    HDC memoryDc;
    unsigned char *bits;
    BITMAPINFO *info;           // header plus a 256-entry colour table
    int zoom;                   // 0 small, 1 medium, 2 large
    int viewX, viewY;
    int stage;
    int transpose;              // which half of the cell index is screen x
    int showHud;
    int lastAction;             // 0040b330's return code, for the read-out
    unsigned lastCol, lastRow;
    Host host;                  // the directory or zip the files come from
    unsigned char *archive;     // the zip's bytes, when one was given
    char dataDir[512];
} App;

static App g_app;

// The colour table comes from the bank the current zoom draws with, so a zoom
// change repaints the palette too - exactly what 004065e0 does when a stage
// loads.
static void applyPalette(App *app) {
    unsigned char colours[256][3];
    renderPalette(&app->game, app->zoom, colours);
    RGBQUAD *table = (RGBQUAD *)(app->info->bmiColors);
    for (int i = 0; i < 256; i++) {
        table[i].rgbRed = colours[i][0];
        table[i].rgbGreen = colours[i][1];
        table[i].rgbBlue = colours[i][2];
        table[i].rgbReserved = 0;
    }
    SetDIBColorTable(app->memoryDc, 0, 256, table);
}

static void clampView(App *app) {
    const TileBank *bank = worldBank(&app->game.world, app->zoom);
    const int span = WORLD_GRID * (bank->tileSize > 0 ? bank->tileSize : 16);
    const int maxX = span - VIEW_W, maxY = span - VIEW_H;
    if (app->viewX > maxX) app->viewX = maxX;
    if (app->viewY > maxY) app->viewY = maxY;
    if (app->viewX < 0) app->viewX = 0;
    if (app->viewY < 0) app->viewY = 0;
}

static int loadStage(App *app, int stage, char *message, unsigned size) {
    if (stage < 0) stage = STAGES - 1;
    if (stage >= STAGES) stage = 0;
    World fresh;
    if (!worldLoadStage(&fresh, &app->host, kStages[stage], message, size))
        return 0;
    worldFree(&app->game.world);
    app->game.world = fresh;
    app->stage = stage;
    // The chain 00407790 runs after a map is read.
    stateStartStage(&app->game);
    simInit(&app->sim, &app->game);
    simSeedLeaders(&app->sim);
    app->lastAction = 0;
    // Centre on the map rather than starting in a corner.
    const TileBank *bank = worldBank(&app->game.world, app->zoom);
    const int span = WORLD_GRID * (bank->tileSize > 0 ? bank->tileSize : 16);
    app->viewX = (span - VIEW_W) / 2;
    app->viewY = (span - VIEW_H) / 2;
    clampView(app);
    applyPalette(app);
    return 1;
}

// A debug read-out of the simulation, so its progress is visible before the
// game's own interface exists.  Counts the cells each faction holds by the
// terrain encoding the sweep uses.
static void paintHud(App *app, HDC dc) {
    unsigned units[FACTION_COUNT] = {0}, ground[FACTION_COUNT] = {0};
    unsigned castles[FACTION_COUNT] = {0}, neutral = 0, entities = 0;
    for (int i = 0; i < WORLD_CELLS; i++) {
        const unsigned char t = app->game.world.cells[i].terrain;
        if (t == 5) neutral++;
        else if (t >= 8 && t <= 0x0b) units[t - 8]++;
        else if (t >= 0x0c && t <= 0x0f) ground[t - 0x0c]++;
        else if (t >= 0x14 && t <= 0x17) castles[t - 0x14]++;
    }
    for (int i = 0; i < ENTITY_COUNT; i++)
        if ((app->game.entities[i].flags & 0x80) == 0) entities++;

    SetBkMode(dc, OPAQUE);
    SetBkColor(dc, RGB(0, 0, 0));
    SetTextColor(dc, RGB(220, 240, 255));
    char line[200];
    int y = 4;
    static const char *actionName[7] = {
        "-", "placed", "no funds", "refused", "-", "-", "spent the unit",
    };
    snprintf(line, sizeof line,
             "sweep %llu  %s   neutral %u   entities %u   click %u,%u %s",
             app->sim.frames, app->running ? "running" : "paused",
             neutral, entities, app->lastCol, app->lastRow,
             actionName[app->lastAction >= 0 && app->lastAction < 7
                            ? app->lastAction : 0]);
    TextOutA(dc, 4, y, line, (int)strlen(line));
    y += 16;
    for (int f = 0; f < FACTION_COUNT; f++) {
        snprintf(line, sizeof line,
                 "faction %d  funds %6u  tax %3u  castles %u  units %3u  "
                 "ground %4u%s",
                 f, app->game.factions[f].funds, app->game.factions[f].taxRate,
                 castles[f], units[f], ground[f],
                 (app->game.factions[f].flags & 0x10) ? "  out" : "");
        TextOutA(dc, 4, y, line, (int)strlen(line));
        y += 16;
    }
}

static void paint(App *app, HDC dc) {
    renderWorld(&app->game.world, app->zoom, app->viewX, app->viewY,
                app->transpose, &app->surface);
    renderUnits(&app->game, app->zoom, app->viewX, app->viewY,
                app->transpose, &app->surface);
    // 0041b370 runs on a stage load and when the original's info window
    // refreshes - so here, before the strip is drawn.
    renderStatus(&app->game, &app->surface);
    BitBlt(dc, 0, 0, VIEW_W, VIEW_H, app->memoryDc, 0, 0, SRCCOPY);
    if (app->showHud) paintHud(app, dc);
}

static void updateTitle(HWND window, const App *app) {
    static const char *zoomName[3] = {"8px", "16px", "32px"};
    char title[256];
    snprintf(title, sizeof title,
             "Lord Monarch - %s  scenery %u  tiles %s  index %s  "
             "(click to raise a unit, arrows, 1/2/3 zoom, PgUp/PgDn stage, "
             "Space run, H hud)",
             kStages[app->stage], app->game.world.scenerySet,
             zoomName[app->zoom],
             app->transpose ? "x*48+y" : "y*48+x");
    SetWindowTextA(window, title);
}

static LRESULT CALLBACK windowProc(HWND window, UINT message, WPARAM wparam,
                                   LPARAM lparam) {
    App *app = &g_app;
    switch (message) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC dc = BeginPaint(window, &ps);
        paint(app, dc);
        EndPaint(window, &ps);
        return 0;
    }
    case WM_KEYDOWN: {
        const TileBank *bank = worldBank(&app->game.world, app->zoom);
        const int step = bank->tileSize > 0 ? bank->tileSize : 16;
        char reason[256];
        switch (wparam) {
        case VK_LEFT:  app->viewX -= step; break;
        case VK_RIGHT: app->viewX += step; break;
        case VK_UP:    app->viewY -= step; break;
        case VK_DOWN:  app->viewY += step; break;
        case '1': case '2': case '3': {
            const int wanted = (int)(wparam - '1');
            if (wanted != app->zoom) {
                // Keep the centre of the view over the same cell.
                const TileBank *to = worldBank(&app->game.world, wanted);
                const double scale = (double)to->tileSize / bank->tileSize;
                app->viewX = (int)((app->viewX + VIEW_W / 2) * scale) - VIEW_W / 2;
                app->viewY = (int)((app->viewY + VIEW_H / 2) * scale) - VIEW_H / 2;
                app->zoom = wanted;
                applyPalette(app);
            }
            break;
        }
        case VK_PRIOR:
            if (!loadStage(app, app->stage - 1, reason, sizeof reason))
                MessageBoxA(window, reason, "Lord Monarch", MB_OK);
            break;
        case VK_NEXT:
            if (!loadStage(app, app->stage + 1, reason, sizeof reason))
                MessageBoxA(window, reason, "Lord Monarch", MB_OK);
            break;
        case 'T':
            app->transpose = !app->transpose;
            break;
        case VK_SPACE:
            app->running = !app->running;
            break;
        case 'H':
            app->showHud = !app->showHud;
            break;
        case 'S':                       // one sweep, for watching it step
            simStep(&app->sim);
            break;
        case VK_ESCAPE:
            DestroyWindow(window);
            return 0;
        default:
            return 0;
        }
        clampView(app);
        updateTitle(window, app);
        InvalidateRect(window, NULL, FALSE);
        return 0;
    }
    case WM_MOUSEMOVE: {
        // 0040b270 moves the cursor a cell at a time from the keyboard.  A cell
        // is a cell however it is chosen, so it follows the pointer here.
        const TileBank *bank = worldBank(&app->game.world, app->zoom);
        const int ts = bank->tileSize > 0 ? bank->tileSize : 16;
        stateMoveCursor(&app->game, (app->viewX + (short)LOWORD(lparam)) / ts,
                        (app->viewY + (short)HIWORD(lparam)) / ts);
        return 0;
    }
    case WM_LBUTTONDOWN: {
        // The original routes an order to a chosen entity and lets it walk to
        // the target; that selection and the movement are not ported yet, so
        // the click applies 0040b330 directly through the player's first
        // entity.  The action itself is the executable's.
        const TileBank *bank = worldBank(&app->game.world, app->zoom);
        const int ts = bank->tileSize > 0 ? bank->tileSize : 16;
        const int worldX = app->viewX + (short)LOWORD(lparam);
        const int worldY = app->viewY + (short)HIWORD(lparam);
        const unsigned col = (unsigned)(worldX / ts);
        const unsigned row = (unsigned)(worldY / ts);
        const unsigned actor = simHumanActor(&app->sim);
        app->lastCol = col;
        app->lastRow = row;
        app->lastAction = actor < ENTITY_COUNT
            ? (int)simBuildUnitCell(&app->sim, actor, col, row)
            : (int)SIM_ACTION_REFUSED;
        InvalidateRect(window, NULL, FALSE);
        return 0;
    }
    case WM_TIMER:
        if (wparam == SIM_TIMER && app->running) {
            simStep(&app->sim);
            InvalidateRect(window, NULL, FALSE);
        }
        return 0;
    case WM_ERASEBKGND:
        return 1;               // the blit covers everything
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        break;
    }
    return DefWindowProcA(window, message, wparam, lparam);
}

// Looks for the extracted game beside the executable, then in orig/.
static int findData(char *out, unsigned size) {
    static const char *candidates[] = {
        "ds7e.zip", "DS7E_WIN", "orig/DS7E_WIN", "../orig/DS7E_WIN",
        "../../orig/DS7E_WIN", "../ds7e.zip",
    };
    for (unsigned i = 0; i < sizeof candidates / sizeof candidates[0]; i++) {
        char probe[1024];
        const size_t length = strlen(candidates[i]);
        if (length > 4 && _stricmp(candidates[i] + length - 4, ".zip") == 0)
            snprintf(probe, sizeof probe, "%s", candidates[i]);
        else
            snprintf(probe, sizeof probe, "%s/MAP/B_000.MAP", candidates[i]);
        FILE *f = fopen(probe, "rb");
        if (f) {
            fclose(f);
            snprintf(out, size, "%s", candidates[i]);
            return 1;
        }
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE prev, LPSTR cmdLine,
                   int show) {
    (void)prev; (void)show;
    App *app = &g_app;
    app->zoom = 1;
    // The original's cell index is `a * 0x30 + b`; taking a as the column is
    // what matches the game on screen.  T flips it back for comparison.
    app->transpose = 1;
    app->showHud = 1;
    app->running = 1;

    // Either an extracted directory or the player's own zip, named on the
    // command line; failing that, look for the directory beside the exe.
    if (cmdLine && *cmdLine) {
        snprintf(app->dataDir, sizeof app->dataDir, "%s", cmdLine);
    } else if (!findData(app->dataDir, sizeof app->dataDir)) {
        MessageBoxA(NULL,
                    "Could not find the game's files.  Pass the DS7E_WIN "
                    "directory, or ds7e.zip, on the command line.",
                    "Lord Monarch", MB_OK | MB_ICONERROR);
        return 1;
    }
    {
        const size_t length = strlen(app->dataDir);
        int ok;
        if (length > 4 && _stricmp(app->dataDir + length - 4, ".zip") == 0) {
            FILE *f = fopen(app->dataDir, "rb");
            if (!f) {
                MessageBoxA(NULL, app->dataDir, "Cannot open",
                            MB_OK | MB_ICONERROR);
                return 1;
            }
            fseek(f, 0, SEEK_END);
            const long size = ftell(f);
            fseek(f, 0, SEEK_SET);
            app->archive = (unsigned char *)malloc((size_t)size);
            ok = app->archive &&
                 fread(app->archive, 1, (size_t)size, f) == (size_t)size;
            fclose(f);
            ok = ok && hostUseZip(&app->host, app->archive, (unsigned)size);
        } else {
            ok = hostUseDirectory(&app->host, app->dataDir);
        }
        if (!ok) {
            MessageBoxA(NULL, app->dataDir, "Cannot read the game's files",
                        MB_OK | MB_ICONERROR);
            return 1;
        }
    }

    WNDCLASSA cls;
    memset(&cls, 0, sizeof cls);
    cls.lpfnWndProc = windowProc;
    cls.hInstance = instance;
    cls.hCursor = LoadCursor(NULL, IDC_ARROW);
    cls.lpszClassName = "LordMonarchNative";
    if (!RegisterClassA(&cls)) return 1;

    RECT frame = {0, 0, VIEW_W, VIEW_H};
    AdjustWindowRect(&frame, WS_OVERLAPPEDWINDOW, FALSE);
    HWND window = CreateWindowA(
        cls.lpszClassName, "Lord Monarch", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, frame.right - frame.left,
        frame.bottom - frame.top, NULL, NULL, instance, NULL);
    if (!window) return 1;

    // An eight-bit DIB section: the surface the renderer writes and GDI blits.
    app->info = (BITMAPINFO *)calloc(1, sizeof(BITMAPINFOHEADER) +
                                        256 * sizeof(RGBQUAD));
    app->info->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    app->info->bmiHeader.biWidth = VIEW_W;
    app->info->bmiHeader.biHeight = -VIEW_H;     // top-down, like the renderer
    app->info->bmiHeader.biPlanes = 1;
    app->info->bmiHeader.biBitCount = 8;
    app->info->bmiHeader.biCompression = BI_RGB;
    app->info->bmiHeader.biClrUsed = 256;

    HDC screen = GetDC(window);
    app->memoryDc = CreateCompatibleDC(screen);
    app->dib = CreateDIBSection(screen, app->info, DIB_RGB_COLORS,
                                (void **)&app->bits, NULL, 0);
    ReleaseDC(window, screen);
    if (!app->dib) return 1;
    SelectObject(app->memoryDc, app->dib);
    surfaceInit(&app->surface, VIEW_W, VIEW_H, app->bits);

    char message[256];
    if (!loadStage(app, 0, message, sizeof message)) {
        MessageBoxA(window, message, "Lord Monarch", MB_OK | MB_ICONERROR);
        return 1;
    }
    updateTitle(window, app);
    SetTimer(window, SIM_TIMER, SIM_TIMER_MS, NULL);
    ShowWindow(window, SW_SHOW);

    MSG msg;
    while (GetMessageA(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
    KillTimer(window, SIM_TIMER);
    worldFree(&app->game.world);
    return 0;
}
