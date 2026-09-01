// The native shell: a window, a CreateDIBSection surface, and StretchBlt -
// the same three things the original uses, so what works here transfers.
//
// Nothing of the game's logic lives in this file.  It loads a stage, scrolls
// it, and switches zoom; every pixel comes from render.c.
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "render.h"
#include "world.h"

#define VIEW_W 640
#define VIEW_H 480
#define STAGES 15

static const char *kStages[STAGES] = {
    "B_000.MAP", "B_002.MAP", "B_003.MAP", "B_004.MAP", "B_005.MAP",
    "B_006.MAP", "B_009.MAP", "B_103.MAP", "B_104.MAP", "B_105.MAP",
    "S_101.MAP", "S_105.MAP", "S_115.MAP", "S_201.MAP", "T_000.MAP",
};

typedef struct {
    World world;
    Surface surface;
    HBITMAP dib;
    HDC memoryDc;
    unsigned char *bits;
    BITMAPINFO *info;           // header plus a 256-entry colour table
    int zoom;                   // 0 small, 1 medium, 2 large
    int viewX, viewY;
    int stage;
    int transpose;              // which half of the cell index is screen x
    char dataDir[512];
} App;

static App g_app;

// The colour table comes from the bank the current zoom draws with, so a zoom
// change repaints the palette too - exactly what 004065e0 does when a stage
// loads.
static void applyPalette(App *app) {
    const TileBank *bank = worldBank(&app->world, app->zoom);
    RGBQUAD *table = (RGBQUAD *)(app->info->bmiColors);
    for (int i = 0; i < 256; i++) {
        table[i].rgbRed = bank->palette[i][0];
        table[i].rgbGreen = bank->palette[i][1];
        table[i].rgbBlue = bank->palette[i][2];
        table[i].rgbReserved = 0;
    }
    SetDIBColorTable(app->memoryDc, 0, 256, table);
}

static void clampView(App *app) {
    const TileBank *bank = worldBank(&app->world, app->zoom);
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
    if (!worldLoadStage(&fresh, app->dataDir, kStages[stage], message, size))
        return 0;
    worldFree(&app->world);
    app->world = fresh;
    app->stage = stage;
    // Centre on the map rather than starting in a corner.
    const TileBank *bank = worldBank(&app->world, app->zoom);
    const int span = WORLD_GRID * (bank->tileSize > 0 ? bank->tileSize : 16);
    app->viewX = (span - VIEW_W) / 2;
    app->viewY = (span - VIEW_H) / 2;
    clampView(app);
    applyPalette(app);
    return 1;
}

static void paint(App *app, HDC dc) {
    renderWorld(&app->world, app->zoom, app->viewX, app->viewY,
                app->transpose, &app->surface);
    BitBlt(dc, 0, 0, VIEW_W, VIEW_H, app->memoryDc, 0, 0, SRCCOPY);
}

static void updateTitle(HWND window, const App *app) {
    static const char *zoomName[3] = {"8px", "16px", "32px"};
    char title[256];
    snprintf(title, sizeof title,
             "Lord Monarch - %s  scenery %u  tiles %s  index %s  "
             "(arrows, 1/2/3 zoom, PgUp/PgDn stage, T transpose)",
             kStages[app->stage], app->world.scenerySet,
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
        const TileBank *bank = worldBank(&app->world, app->zoom);
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
                const TileBank *to = worldBank(&app->world, wanted);
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
        "DS7E_WIN", "orig/DS7E_WIN", "../orig/DS7E_WIN",
        "../../orig/DS7E_WIN",
    };
    for (unsigned i = 0; i < sizeof candidates / sizeof candidates[0]; i++) {
        char probe[1024];
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

    if (cmdLine && *cmdLine) {
        snprintf(app->dataDir, sizeof app->dataDir, "%s", cmdLine);
    } else if (!findData(app->dataDir, sizeof app->dataDir)) {
        MessageBoxA(NULL,
                    "Could not find the game's files.  Pass the DS7E_WIN "
                    "directory on the command line.",
                    "Lord Monarch", MB_OK | MB_ICONERROR);
        return 1;
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
    ShowWindow(window, SW_SHOW);

    MSG msg;
    while (GetMessageA(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
    worldFree(&app->world);
    return 0;
}
