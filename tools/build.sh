#!/bin/sh
# Build the native app with mingw, at low priority.  See tools/lowpri.sh.
set -e
cd "$(dirname "$0")/.."
GCC="${GCC:-/c/prog/w64devkit/bin/gcc}"
sh tools/lowpri.sh "$GCC" -O2 -Wall -Wextra -mwindows -o loadmonarch.exe     src/win32_main.c src/world.c src/render.c src/bz.c src/gfx.c -lgdi32
echo "built loadmonarch.exe"
