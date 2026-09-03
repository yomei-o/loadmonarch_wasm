// Every check in one binary.
//
//   tests/checks.exe [zip] [full]
//
// This machine takes about twelve seconds to link an executable however small
// the change - it is the linker and the virus scanner, not the compiler - so a
// dozen check programs cost three minutes of linking to run six seconds of
// checks.  Each check keeps its own file and its own main; the build compiles
// them with `-Dmain=<name>_main` and links them together with this, so there
// is one link and the checks stay separate files.
#include <stdio.h>
#include <string.h>

int state_test_main(void);
int dialog_test_main(void);
int menu_test_main(void);
int orders_test_main(void);
int font_test_main(int argc, char **argv);
int endstage_test_main(int argc, char **argv);
int panels_test_main(int argc, char **argv);
int rsrc_test_main(int argc, char **argv);
int growth_test_main(int argc, char **argv);
int stress_test_main(int argc, char **argv);

static int bad;

static void plain(const char *name, int (*fn)(void)) {
    const int rc = fn();
    if (rc) { printf("!! %s answered %d\n", name, rc); bad = 1; }
}

static void with(const char *name, int (*fn)(int, char **), const char *arg) {
    char *argv[3];
    int argc = 1;
    argv[0] = (char *)name;
    if (arg) argv[argc++] = (char *)arg;
    argv[argc] = NULL;
    const int rc = fn(argc, argv);
    if (rc) { printf("!! %s %s answered %d\n", name, arg ? arg : "", rc); bad = 1; }
}

int main(int argc, char **argv) {
    const char *zip = "ds7e.zip";
    int full = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "full") == 0) full = 1;
        else zip = argv[i];
    }
    plain("state_test", state_test_main);
    plain("dialog_test", dialog_test_main);
    plain("menu_test", menu_test_main);
    plain("orders_test", orders_test_main);
    with("font_test", font_test_main, "ds7e.zip");
    with("font_test", font_test_main, "ds7j.zip");
    with("endstage_test", endstage_test_main, zip);
    with("panels_test", panels_test_main, zip);
    with("rsrc_test", rsrc_test_main, "ds7e.zip");
    with("rsrc_test", rsrc_test_main, "ds7j.zip");
    if (full) {
        // Twenty thousand sweeps apiece.
        with("growth_test", growth_test_main, zip);
        with("stress_test", stress_test_main, zip);
    }
    if (bad) { printf("some checks failed\n"); return 1; }
    printf("all checks ok%s\n", full ? " (with the long runs)" : "");
    return 0;
}
