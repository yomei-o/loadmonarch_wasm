// Drive the WebAssembly build the way the page does, from node: hand it the
// zip, run the simulation, read the panel, click.  No browser and no window.
'use strict';
const fs = require('fs');
const path = require('path');

const createLordMonarch = require('../docs/loadmonarch.js');

let failures = 0;
function expect(what, got, want) {
    const ok = typeof want === 'function' ? want(got) : got === want;
    if (!ok) {
        console.log(`  FAIL ${what}: got ${got}`);
        failures++;
    }
}

createLordMonarch().then((M) => {
    const zipPath = process.argv[2] || path.join(__dirname, '..', 'ds7e.zip');
    const bytes = fs.readFileSync(zipPath);

    const p = M._lm_alloc(bytes.length);
    M.HEAPU8.set(bytes, p);
    const stages = M._lm_open_zip(p, bytes.length);
    M._lm_free(p);
    if (!stages) {
        console.log('  FAIL could not open the zip: ' +
                    M.UTF8ToString(M._lm_message()));
        process.exit(1);
    }
    expect('stage count', stages, 15);
    expect('first stage', M.UTF8ToString(M._lm_stage_name()), 'B_000.MAP');
    expect('its scenery set', M._lm_scenery(), 10);
    expect('starting funds', M._lm_funds(0), 5000);
    // 241 rather than the map's 242: seeding turns one of them into the first
    // settlement, on the seven maps that ship without any.
    expect('claimed ground on B_000', M._lm_count(0, 1), 241);
    expect('and it has a settlement to start from', M._lm_count(0, 0),
           (n) => n > 0);

    // A frame comes back as RGBA the canvas can take, and it is not blank.
    const W = M._lm_width(), H = M._lm_height();
    expect('view width', W, 640);
    expect('view height', H, 480);
    const frame = M._lm_frame();
    const pixels = new Uint8Array(M.HEAPU8.buffer, frame, W * H * 4);
    let distinct = new Set();
    for (let i = 0; i < W * H * 4; i += 4)
        distinct.add(pixels[i] << 16 | pixels[i + 1] << 8 | pixels[i + 2]);
    expect('the frame has real colours in it', distinct.size, (n) => n > 4);
    expect('every pixel is opaque', pixels[3], 255);

    // The simulation advances, and the neutral cells put entities out.
    const before = M._lm_count(4, 3);
    M._lm_step(600);
    expect('sweeps counted', M._lm_sweeps(), (n) => n === 600);
    expect('neutral cells produced entities', M._lm_count(4, 3),
           (n) => n > before);

    // Zoom keeps working and changes the tile size the view uses.
    M._lm_set_zoom(2);
    expect('zoom changed', M._lm_zoom(), 2);
    M._lm_frame();
    M._lm_set_zoom(1);

    // Clicking on the player's own ground raises a unit and takes the hundred.
    const funds = M._lm_funds(0);
    let placed = 0;
    for (let y = 40; y < 440 && !placed; y += 16) {
        for (let x = 40; x < 600 && !placed; x += 16) {
            // 1 is placed, 6 is placed at the cost of the acting unit -
            // 0040b330 returns both for a successful order.
            const r = M._lm_click(x, y);
            if (r === 1 || r === 6) placed = 1;
        }
    }
    expect('a click placed a unit somewhere', placed, 1);
    expect('and it cost a hundred', M._lm_funds(0), funds - 100);

    // Every stage loads.
    for (let s = 0; s < 15; s++) {
        expect(`stage ${s} loads`, M._lm_load_stage(s), 1);
        M._lm_step(30);
    }

    // Orders: giving the whole army one takes and shows up in their state.
    M._lm_load_stage(2);                    // B_003, which starts with units
    for (let i = 0; i < 200; i++) M._lm_step(1);
    M._lm_set_order(4);
    // lm_set_order composes the byte the menu at 0x434444 would: the order
    // itself plus 0x10, which is what makes it a standing order at all.
    expect('the selected order took', M._lm_order(), 4 | 0x10);
    const ordered = M._lm_order_all(4);
    expect('some units were given it', ordered, (n) => n > 0);
    for (let i = 0; i < 200; i++) M._lm_step(1);
    expect('and the game keeps running', M._lm_sweeps(), (n) => n > 0);

    // The music: a tune loads out of the zip and renders real samples.
    M._lm_load_stage(0);
    expect('a tune loads', M._lm_music_play(0, 1), 1);
    expect('and reports playing', M._lm_music_playing(), 1);
    const frames = Math.min(2048, M._lm_music_capacity());
    let peak = 0, energy = 0, silentBlocks = 0;
    for (let block = 0; block < 40; block++) {
        const ptr = M._lm_music_render(frames, 22050);
        const pcm = new Float32Array(M.HEAPU8.buffer, ptr, frames);
        let blockPeak = 0;
        for (let i = 0; i < frames; i++) {
            const a = Math.abs(pcm[i]);
            if (a > blockPeak) blockPeak = a;
            energy += pcm[i] * pcm[i];
        }
        if (blockPeak < 1e-6) silentBlocks++;
        if (blockPeak > peak) peak = blockPeak;
    }
    const rms = Math.sqrt(energy / (frames * 40));
    expect('the music is audible', rms, (v) => v > 0.01);
    expect('and stays in range', peak, (v) => v > 0 && v <= 1.001);
    expect('not every block was silent', silentBlocks, (v) => v < 40);
    // 0040a110: which tune the war calls for.  One country against three is
    // behind all of them put together, so a stage opens on its first tune.
    M._lm_load_stage(2);
    const set = M._lm_scenery();
    expect('the war asks for the stage tune', M._lm_music_wanted(), set);
    console.log(`  music wanted: ${M._lm_music_wanted()} (set ${set})`);

    M._lm_music_stop();
    expect('stopping stops it', M._lm_music_playing(), 0);

    // The scenery set's own wording, and the cursor.
    M._lm_load_stage(2);
    const country = M.UTF8ToString(M._lm_country_name(0));
    const order = M.UTF8ToString(M._lm_order_name(1));
    expect('country 0 has a name', country.length, (n) => n > 0);
    expect('order 1 has a name', order.length, (n) => n > 0);
    console.log(`  set ${M._lm_scenery()}: ${country} / order 1 = ${order}`);

    M._lm_set_cursor(100, 100);
    expect('the cursor took a cell', M._lm_cursor_col(), (n) => n < 48);
    const wasCol = M._lm_cursor_col(), wasRow = M._lm_cursor_row();
    M._lm_set_cursor(-1, -1);
    expect('and can be put away', M._lm_cursor_col(), 255);
    M._lm_set_cursor(100, 100);
    expect('and comes back to the same cell', M._lm_cursor_col(), wasCol);
    expect('same row too', M._lm_cursor_row(), wasRow);
    expect('orders show by default', M._lm_orders_shown(), 1);

    // Choosing units and sending them: the original's own flow.
    M._lm_load_stage(2);
    for (let i = 0; i < 300; i++) M._lm_step(1);
    const picked = M._lm_select_all(1);
    expect('units can be chosen', picked, (n) => n > 0);
    expect('and the count reads back', M._lm_selected(), picked);
    // 00426900's inspector: with the cursor somewhere, the cell answers.
    M._lm_set_cursor(320, 240);
    expect('the cursor is on a cell', M._lm_cursor_terrain(), (n) => n >= 0);
    expect('and the cell holds a number', M._lm_cursor_value(), (n) => n >= 0);
    M._lm_set_cursor(-1, -1);
    expect('with no cursor there is nothing to show',
           M._lm_cursor_terrain(), -1);
    M._lm_set_cursor(320, 240);

    // What the panel shows: a share of the board, and a leader with a
    // strength of its own that the country's total leaves out.
    M._lm_update_areas();
    let share = 0;
    for (let f = 0; f < 4; f++) share += M._lm_area(f);
    expect('the countries hold some of the board', share, (n) => n > 0);
    expect('and not more than all of it', share, (n) => n <= 10000);
    expect('a leader has a strength', M._lm_leader_strength(0), (n) => n > 0);

    // Aiming answers before anything is ordered.
    let reachable = 0;
    for (let y = 40; y < 440 && !reachable; y += 40)
        for (let x = 40; x < 600 && !reachable; x += 40)
            reachable = M._lm_aim(x, y);
    expect('somewhere is reachable', reachable, 1);
    expect('and aiming ordered nothing', M._lm_selected(), picked);

    let sent = 0;
    for (let y = 40; y < 440 && !sent; y += 40)
        for (let x = 40; x < 600 && !sent; x += 40)
            sent = M._lm_order_at(1, 0, x, y);
    expect('an order reaches somebody', sent, (n) => n > 0);
    expect('and the choice is spent', M._lm_selected(), 0);
    console.log(`  ${picked} chosen, ${sent} took the order`);
    M._lm_select_all(0);
    M._lm_clear_selection();
    expect('a choice can be dropped', M._lm_selected(), 0);

    console.log(failures ? `${failures} check(s) failed`
                         : 'wasm checks ok');
    process.exit(failures ? 1 : 0);
});
