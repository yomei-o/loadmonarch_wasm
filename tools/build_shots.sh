#!/bin/sh
# The screenshot tools, which draw what the port draws so it can be looked at
# without opening a window.  They are not built with the checks because this
# machine spends about twelve seconds per executable in the linker.
#
#   sh tools/build_shots.sh
#   ./tests/frame_dump.exe ds7e.zip B_000.MAP tmp/out.ppm 400 1 panels:5,6
#   ./tests/endstage_shot.exe ds7e.zip 0 tmp/end.ppm 120
set -e
cd "$(dirname "$0")/.."
sh tools/build_tests.sh >/dev/null    # so the objects are there and current
OBJ=
for f in src/sim.c src/state.c src/world.c src/render.c src/orders.c src/ui.c \
         src/dlg.c src/dlgdefs.c src/dlgrun.c src/dlgload.c src/rsrc.c \
         src/rsrc_sjis.c src/toolbar.c src/panels.c src/endstage.c \
         src/notice.c src/awards.c src/picture.c src/font.c src/font16.c \
         src/bz.c src/gfx.c src/host.c src/zip.c; do
    OBJ="$OBJ tmp/obj/$(basename "$f" .c).obj"
done
for t in frame_dump endstage_shot; do
    sh tools/cc.sh -O2 -Wall -Isrc -o "tests/$t.exe" "tests/$t.c" $OBJ
    echo "built tests/$t.exe"
done
