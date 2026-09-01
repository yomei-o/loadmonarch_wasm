#!/bin/sh
# Build the WebAssembly module into docs/, which GitHub Pages serves.
# Needs emsdk; EMCC can name the compiler if it is not on PATH.
set -e
cd "$(dirname "$0")/.."
EMCC="${EMCC:-/c/prog/emsdk/emsdk/upstream/emscripten/emcc}"
mkdir -p docs

EXPORTS=_lm_open_zip,_lm_message,_lm_width,_lm_height,_lm_stage_name,_lm_stage,_lm_step,_lm_frame,_lm_scroll,_lm_set_zoom,_lm_zoom,_lm_load_stage,_lm_pause,_lm_running,_lm_click,_lm_last_action,_lm_last_col,_lm_last_row,_lm_sweeps,_lm_scenery,_lm_funds,_lm_tax,_lm_losses,_lm_out,_lm_count,_lm_alloc,_lm_free,_lm_music_play,_lm_music_stop,_lm_music_playing,_lm_music_render,_lm_music_capacity,_lm_set_order,_lm_order,_lm_order_all,_lm_set_cursor,_lm_cursor_col,_lm_cursor_row,_lm_show_orders,_lm_orders_shown,_lm_strength,_lm_country_name,_lm_order_name

sh tools/lowpri.sh "$EMCC" -O2 \
    src/wasm_main.cpp src/world.c src/state.c src/sim.c src/render.c \
    src/bz.c src/gfx.c src/host.c src/zip.c src/midi.c \
    -sALLOW_MEMORY_GROWTH=1 -sSINGLE_FILE=1 \
    -sMODULARIZE=1 -sEXPORT_NAME=createLordMonarch \
    -sEXPORTED_RUNTIME_METHODS=HEAPU8,HEAPU32,UTF8ToString \
    -sEXPORTED_FUNCTIONS="$EXPORTS" \
    -o docs/loadmonarch.js

# A new build is a new URL, so a browser can never pair fresh HTML with a
# cached module - the trap that cost an afternoon on the simtower port.
V="$(date -u '+%Y%m%d%H%M%S')"
sed "s/loadmonarch\.js/loadmonarch.js?v=$V/" web/index.html > docs/index.html
echo "built docs/loadmonarch.js + docs/index.html (v=$V)"
