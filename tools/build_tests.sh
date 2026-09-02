#!/bin/sh
# Build the format-checking tools, at low priority.
set -e
cd "$(dirname "$0")/.."
GCC="${GCC:-/c/prog/w64devkit/bin/gcc}"
sh tools/lowpri.sh "$GCC" -O2 -Wall -Wextra -o tests/zip_test.exe     tests/zip_test.c src/zip.c
echo "built tests/zip_test.exe"
for t in bz_test tiles_test map_test data1_test; do
    sh tools/lowpri.sh "$GCC" -O2 -Wall -o "tests/$t.exe" "tests/$t.c"         src/bz.c src/gfx.c
    echo "built tests/$t.exe"
done
sh tools/lowpri.sh "$GCC" -O2 -Wall -o tests/unit_window.exe    tests/unit_window.c src/world.c src/host.c src/zip.c src/bz.c src/gfx.c
echo "built tests/unit_window.exe"
sh tools/lowpri.sh "$GCC" -O2 -Wall -o tests/progress_window.exe tests/progress_window.c src/world.c src/host.c src/zip.c src/bz.c src/gfx.c
echo "built tests/progress_window.exe"
SIM="src/sim.c src/state.c src/world.c src/render.c src/bz.c src/gfx.c src/host.c src/zip.c"
sh tools/lowpri.sh "$GCC" -O2 -Wall -Wextra -o tests/state_test.exe     tests/state_test.c $SIM
echo "built tests/state_test.exe"
sh tools/lowpri.sh "$GCC" -O2 -Wall -Wextra -o tests/growth_test.exe    tests/growth_test.c $SIM
echo "built tests/growth_test.exe"
sh tools/lowpri.sh "$GCC" -O2 -Wall -Wextra -o tests/stress_test.exe    tests/stress_test.c $SIM
echo "built tests/stress_test.exe"
sh tools/lowpri.sh "$GCC" -O2 -Wall -Wextra -o tests/sim_harness.exe     tests/sim_harness.c $SIM
echo "built tests/sim_harness.exe"
./tests/state_test.exe
./tests/stress_test.exe
./tests/growth_test.exe
