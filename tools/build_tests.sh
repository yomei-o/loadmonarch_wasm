#!/bin/sh
# Build the format-checking tools, at low priority.
set -e
cd "$(dirname "$0")/.."
# tools/cc.sh picks gcc when there is one and Visual Studio's cl when there is
# not - this machine has no gcc - and routes gcc through lowpri.sh itself.
CC_SH="sh tools/cc.sh"
$CC_SH -O2 -Wall -Wextra -o tests/zip_test.exe     tests/zip_test.c src/zip.c
echo "built tests/zip_test.exe"
for t in bz_test tiles_test map_test data1_test; do
    $CC_SH -O2 -Wall -o "tests/$t.exe" "tests/$t.c"         src/bz.c src/gfx.c
    echo "built tests/$t.exe"
done
$CC_SH -O2 -Wall -Isrc -o tests/unit_window.exe    tests/unit_window.c src/world.c src/host.c src/zip.c src/bz.c src/gfx.c
echo "built tests/unit_window.exe"
$CC_SH -O2 -Wall -Isrc -o tests/progress_window.exe tests/progress_window.c src/world.c src/host.c src/zip.c src/bz.c src/gfx.c
echo "built tests/progress_window.exe"
SIM="src/sim.c src/state.c src/world.c src/render.c src/orders.c src/ui.c src/dlg.c src/dlgdefs.c src/dlgrun.c src/toolbar.c src/panels.c src/endstage.c src/notice.c src/awards.c src/picture.c src/font.c src/font16.c src/bz.c src/gfx.c src/host.c src/zip.c"
$CC_SH -O2 -Wall -Wextra -o tests/state_test.exe     tests/state_test.c $SIM
echo "built tests/state_test.exe"
$CC_SH -O2 -Wall -Wextra -o tests/growth_test.exe    tests/growth_test.c $SIM
echo "built tests/growth_test.exe"
# The music: the synthesiser from the sibling port, driven through src/midi.c.
$CC_SH -O2 -Wall -Isrc -o tests/midi_test.exe       tests/midi_test.c src/midi.c src/synth.c src/smf.c src/host.c src/zip.c
echo "built tests/midi_test.exe"
$CC_SH -O2 -Wall -Isrc -o tests/dialog_test.exe     tests/dialog_test.c $SIM
echo "built tests/dialog_test.exe"
$CC_SH -O2 -Wall -Wextra -o tests/menu_test.exe      tests/menu_test.c $SIM
echo "built tests/menu_test.exe"
$CC_SH -O2 -Wall -Wextra -o tests/font_test.exe      tests/font_test.c $SIM
echo "built tests/font_test.exe"
$CC_SH -O2 -Wall -Wextra -o tests/orders_test.exe    tests/orders_test.c $SIM
echo "built tests/orders_test.exe"
$CC_SH -O2 -Wall -Wextra -o tests/stress_test.exe    tests/stress_test.c $SIM
echo "built tests/stress_test.exe"
$CC_SH -O2 -Wall -Isrc -o tests/rsrc_test.exe       tests/rsrc_test.c src/rsrc.c $SIM
echo "built tests/rsrc_test.exe"
$CC_SH -O2 -Wall -Wextra -o tests/endstage_test.exe  tests/endstage_test.c $SIM
echo "built tests/endstage_test.exe"
$CC_SH -O2 -Wall -Isrc -o tests/endstage_shot.exe   tests/endstage_shot.c $SIM
echo "built tests/endstage_shot.exe"
$CC_SH -O2 -Wall -Wextra -o tests/sim_harness.exe     tests/sim_harness.c $SIM
echo "built tests/sim_harness.exe"
# It draws the board through the same sim, so it goes stale exactly when it
# would be most misleading to look at.
$CC_SH -O2 -Wall -Isrc -o tests/frame_dump.exe      tests/frame_dump.c $SIM
echo "built tests/frame_dump.exe"
./tests/state_test.exe
./tests/dialog_test.exe
./tests/menu_test.exe
./tests/font_test.exe ds7e.zip
./tests/font_test.exe ds7j.zip
./tests/orders_test.exe
./tests/stress_test.exe
./tests/growth_test.exe
./tests/endstage_test.exe ds7e.zip
./tests/rsrc_test.exe ds7e.zip
