#!/bin/sh
# Build the format-checking tools, at low priority.
set -e
cd "$(dirname "$0")/.."
GCC="${GCC:-/c/prog/w64devkit/bin/gcc}"
for t in bz_test tiles_test map_test data1_test; do
    sh tools/lowpri.sh "$GCC" -O2 -Wall -o "tests/$t.exe" "tests/$t.c"         src/bz.c src/gfx.c
    echo "built tests/$t.exe"
done
