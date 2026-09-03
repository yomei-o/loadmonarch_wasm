#!/bin/sh
# Build the WebAssembly module into docs/, which GitHub Pages serves.
# Needs emsdk; EMCC can name the compiler if it is not on PATH.
set -e
cd "$(dirname "$0")/.."
# The .exe matters: lowpri.sh hands the command to cmd, and cmd cannot run
# the extensionless shell wrapper beside it.
EMCC="${EMCC:-/c/prog/emsdk/emsdk/upstream/emscripten/emcc.exe}"
mkdir -p docs

EXPORTS=_lm_open_zip,_lm_message,_lm_width,_lm_height,_lm_stage_name,_lm_stage,_lm_step,_lm_timer,_lm_frame,_lm_scroll,_lm_scroll_by,_lm_set_zoom,_lm_zoom,_lm_load_stage,_lm_pause,_lm_running,_lm_click,_lm_last_action,_lm_last_col,_lm_last_row,_lm_sweeps,_lm_scenery,_lm_funds,_lm_tax,_lm_losses,_lm_out,_lm_count,_lm_alloc,_lm_free,_lm_music_play,_lm_tune_name,_lm_tune_loops,_lm_music_wanted,_lm_music_stop,_lm_music_playing,_lm_music_render,_lm_music_render2,_lm_music_capacity2,_lm_music_rate,_lm_music_capacity,_lm_set_order,_lm_order,_lm_order_all,_lm_set_cursor,_lm_cursor_col,_lm_cursor_row,_lm_show_orders,_lm_orders_shown,_lm_strength,_lm_country_name,_lm_country_colour,_lm_order_name,_lm_select_all,_lm_recall_leader,_lm_select_at,_lm_select_rect,_lm_unit_here,_lm_menu_open,_lm_menu_up,_lm_menu_close,_lm_menu_hover,_lm_menu_click,_lm_bar_click,_lm_bar_hover,_lm_bar_open,_lm_tool_tip,_lm_tool_hot,_lm_bar_height,_lm_menu_height,_lm_panel_hit,_lm_panel_drag,_lm_progress_origin,_lm_auto_tax,_lm_command,_lm_show_leader,_lm_dialog_open,_lm_dialog_up,_lm_dialog_hover,_lm_dialog_click,_lm_slot_action,_lm_slot_wanted,_lm_slot_count,_lm_slot_set_name,_lm_speed,_lm_set_speed,_lm_window_shown,_lm_selected,_lm_clear_selection,_lm_order_at,_lm_aim,_lm_update_areas,_lm_area,_lm_leader_strength,_lm_outcome,_lm_notice_up,_lm_notice_kind,_lm_notice_faction,_lm_notice_click,_lm_end_up,_lm_end_mode,_lm_end_tick,_lm_end_click,_lm_campaign_reached,_lm_quest,_lm_campaign_record,_lm_campaign_set,_lm_end_rank_up,_lm_dialog_request,_lm_awards_up,_lm_awards_rank,_lm_awards_click,_lm_campaign_rank,_lm_set_human,_lm_set_view,_lm_human,_lm_save,_lm_save_size,_lm_days,_lm_days_left,_lm_ui_region,_lm_terrain_tile,_lm_load,_lm_picture_show,_lm_picture_up,_lm_picture_dismiss,_lm_drag_rect,_lm_cheat_funds,_lm_stage_title,_lm_quest_name,_lm_stage_count,_lm_cursor_terrain,_lm_cursor_value,_lm_cursor_unit,_lm_cursor_unit_faction,_lm_graph_wheel

# Not through lowpri.sh: this is one process with no parallelism to starve
# the desktop with, and cmd's `start /WAIT` loses emcc's exit status - a
# failed link then looked like a build that left no status at all.
"$EMCC" -O2 \
    src/wasm_main.cpp src/world.c src/state.c src/sim.c src/render.c \
    src/font.c src/font16.c src/orders.c src/ui.c src/dlg.c src/dlgdefs.c src/dlgrun.c src/dlgload.c src/toolbar.c src/panels.c \
    src/rsrc.c src/rsrc_sjis.c src/endstage.c src/notice.c src/awards.c src/bz.c src/gfx.c src/host.c src/zip.c src/midi.c src/synth.c src/smf.c src/picture.c \
    -sALLOW_MEMORY_GROWTH=1 -sSINGLE_FILE=1 \
    -sMODULARIZE=1 -sEXPORT_NAME=createLordMonarch \
    -sEXPORTED_RUNTIME_METHODS=HEAPU8,HEAPU32,UTF8ToString \
    -sEXPORTED_FUNCTIONS="$EXPORTS" \
    -o docs/loadmonarch.js

# A new build is a new URL, so a browser can never pair fresh HTML with a
# cached module - the trap that cost an afternoon on the simtower port.
#
# That is only half of it, though: the stamp lives inside the page, and GitHub
# Pages serves the page itself with max-age=600.  A browser holding a
# ten-minute-old page therefore holds a ten-minute-old module with it, and the
# build looks stale however often it is pushed.  So the stamp also goes in a
# file of its own, which the page asks for past the cache and uses to step onto
# the new build by itself.
V="$(date -u '+%Y%m%d%H%M%S')"
printf '%s' "$V" > docs/version.txt
sed -e "s/loadmonarch\.js/loadmonarch.js?v=$V/" \
    -e "s/__BUILD__/$V/" web/index.html > docs/index.html
echo "built docs/loadmonarch.js + docs/index.html (v=$V)"
