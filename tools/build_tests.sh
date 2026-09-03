#!/bin/sh
# Build and run the checks.
#
#   sh tools/build_tests.sh          what has changed, then the quick checks
#   sh tools/build_tests.sh full     also the two twenty-thousand-sweep runs
#                                    and the tools that only dump
#
# Three things keep this short enough to run after every edit:
#
#   * the port's sources are compiled ONCE into tmp/obj and linked from there;
#   * every check goes into ONE executable (tests/checks.exe, see its own
#     comment) - this machine spends about twelve seconds in the linker per
#     executable however small the change, so a dozen of them cost minutes;
#   * nothing is rebuilt whose output is newer than what it is made from.
#
# Any header counts as a change to everything, which is crude and right: the
# headers carry the structures the whole port agrees on.
set -e
cd "$(dirname "$0")/.."
# tools/cc.sh picks gcc when there is one and Visual Studio's cl when there is
# not - this machine has no gcc - and routes gcc through lowpri.sh itself.
CC_SH="sh tools/cc.sh"
FULL=
case "$1" in full|all|-a) FULL=1 ;; esac

SIMSRC="src/sim.c src/state.c src/world.c src/render.c src/orders.c src/ui.c src/dlg.c src/dlgdefs.c src/dlgrun.c src/dlgload.c src/rsrc.c src/rsrc_sjis.c src/toolbar.c src/panels.c src/endstage.c src/notice.c src/awards.c src/picture.c src/font.c src/font16.c src/bz.c src/gfx.c src/host.c src/zip.c"
CHECKS="state_test dialog_test menu_test orders_test font_test endstage_test panels_test rsrc_test growth_test stress_test"
mkdir -p tmp/obj

# The newest header: everything depends on it.
newest=
for h in src/*.h; do
    if [ -z "$newest" ] || [ "$h" -nt "$newest" ]; then newest="$h"; fi
done

stale=
OBJ=
for f in $SIMSRC; do
    o="tmp/obj/$(basename "$f" .c).obj"
    OBJ="$OBJ $o"
    if [ ! -f "$o" ] || [ "$f" -nt "$o" ] || [ "$newest" -nt "$o" ]; then
        stale="$stale $f"
    fi
done
[ -z "$stale" ] || { echo "compiling:$stale"; $CC_SH -O2 -Wall -Isrc -c $stale; }

# The checks themselves, each with its main renamed so they can share one
# executable.  They are thin, so they are compiled without optimisation: the
# work they measure is in the objects above.
# Their objects go in a directory of their own: cl names an object after the
# source's basename, and building tests/state_test.c as an executable would
# leave a tmp/obj/state_test.obj with a main() in it.
mkdir -p tmp/obj/checks
for t in $CHECKS; do
    o="tmp/obj/checks/$t.obj"
    OBJ="$OBJ $o"
    if [ ! -f "$o" ] || [ "tests/$t.c" -nt "$o" ] || [ "$newest" -nt "$o" ]; then
        echo "compiling tests/$t.c"
        OBJDIR="$PWD/tmp/obj/checks" $CC_SH -O2 -Wall -Isrc "-Dmain=${t}_main" -c "tests/$t.c"
    fi
done

newobj=
for o in $OBJ; do
    if [ -z "$newobj" ] || [ "$o" -nt "$newobj" ]; then newobj="$o"; fi
done
if [ ! -f tests/checks.exe ] || [ tests/checks.c -nt tests/checks.exe ] \
   || [ "$newobj" -nt tests/checks.exe ]; then
    echo "linking tests/checks.exe"
    $CC_SH -O2 -Wall -Isrc -o tests/checks.exe tests/checks.c $OBJ
fi

if [ -n "$FULL" ]; then
    ./tests/checks.exe ds7e.zip full
else
    ./tests/checks.exe ds7e.zip
fi

[ -n "$FULL" ] || exit 0

# The eyes and the dumps: built with the rest only when everything is asked
# for.  sh tools/build_shots.sh builds just the two screenshot tools.
sh tools/build_shots.sh
$CC_SH -O2 -Wall -Wextra -o tests/zip_test.exe  tests/zip_test.c src/zip.c
for t in bz_test tiles_test map_test data1_test; do
    $CC_SH -O2 -Wall -o "tests/$t.exe" "tests/$t.c" src/bz.c src/gfx.c
done
PARTS="tmp/obj/world.obj tmp/obj/host.obj tmp/obj/zip.obj tmp/obj/bz.obj tmp/obj/gfx.obj"
$CC_SH -O2 -Wall -Isrc -o tests/unit_window.exe     tests/unit_window.c $PARTS
$CC_SH -O2 -Wall -Isrc -o tests/progress_window.exe tests/progress_window.c $PARTS
$CC_SH -O2 -Wall -Isrc -o tests/midi_test.exe       tests/midi_test.c src/midi.c src/synth.c src/smf.c tmp/obj/host.obj tmp/obj/zip.obj
$CC_SH -O2 -Wall -Isrc -o tests/sim_harness.exe     tests/sim_harness.c $OBJ
echo "built the dumps"
./tests/zip_test.exe
./tests/bz_test.exe disk/DATA/DATA1.BZ 2>/dev/null || true
