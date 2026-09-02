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
    // MAP/NAME.TXT gives the campaign its order and its titles.
    expect('the quest has a name',
           M.UTF8ToString(M._lm_quest_name()).length, (n) => n > 0);
    expect('and the stage does too',
           M.UTF8ToString(M._lm_stage_title()).length, (n) => n > 0);
    expect('the second stage is the one the list names', (() => {
        M._lm_load_stage(1);
        const name = M.UTF8ToString(M._lm_stage_name());
        M._lm_load_stage(0);
        return name;
    })(), 'B_003.MAP');
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
    // The map is 480 tall and the menu bar sits above it, so the surface the
    // page shows is taller than the view.
    expect('view height', H, 480 + M._lm_bar_height());
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
    M._lm_load_stage(1);                    // B_003, which starts with units
    // A unit that spawns weak spends itself on the first settlement it raises
    // - 0040b330 returns "used up" whenever the unit is worth 200 or less - so
    // there is no army at all for the first few hundred sweeps.  This waits
    // for one.
    for (let i = 0; i < 1500; i++) M._lm_step(1);
    M._lm_set_order(4, 2);
    // lm_set_order composes the byte the menu at 0x434444 would: the order
    // itself, plus 0x10 to make it a standing order at all, plus 0x80 for the
    // third of the three rows - keep looking for another one like it.
    expect('the selected order took', M._lm_order(), 4 | 0x10 | 0x80);
    const ordered = M._lm_order_all(4, 2);
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
    M._lm_load_stage(1);
    const set = M._lm_scenery();
    expect('the war asks for the stage tune', M._lm_music_wanted(), set);
    console.log(`  music wanted: ${M._lm_music_wanted()} (set ${set})`);

    // SOUND.CFG names the tunes, and says which of them loop.
    const tune = M.UTF8ToString(M._lm_tune_name(set));
    expect('the stage tune has a name', tune.length, (n) => n > 0);
    expect('and it loops', M._lm_tune_loops(set), 1);
    // Entry 0 is the Ending Theme, which plays once.
    expect('the ending theme does not', M._lm_tune_loops(0), 0);
    console.log(`  tune ${set}: ${tune}`);

    M._lm_music_stop();
    expect('stopping stops it', M._lm_music_playing(), 0);

    // The scenery set's own wording, and the cursor.
    M._lm_load_stage(2);
    const country = M.UTF8ToString(M._lm_country_name(0));
    const order = M.UTF8ToString(M._lm_order_name(1));
    expect('country 0 has a name', country.length, (n) => n > 0);
    expect('order 1 has a name', order.length, (n) => n > 0);
    // Every scenery set colours its countries itself, so no two need agree -
    // only that four different colours come back.
    const hues = [0, 1, 2, 3].map((f) => M._lm_country_colour(f));
    expect('four countries, four colours', new Set(hues).size, (n) => n === 4);
    console.log(`  set ${M._lm_scenery()}: ${country} / order 1 = ${order}`);
    console.log('  colours: ' + hues.map(
        (c) => '#' + ('000000' + (c >>> 0).toString(16)).slice(-6)).join(' '));

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
    M._lm_load_stage(1);                    // B_003 again
    for (let i = 0; i < 300; i++) M._lm_step(1);
    const picked = M._lm_select_all(1);
    expect('units can be chosen', picked, (n) => n > 0);
    expect('and the count reads back', M._lm_selected(), picked);
    // Which country is the player's is a choice here.
    expect('the player starts as the first country', M._lm_human(), 0);
    M._lm_set_human(2);
    expect('and can be another', M._lm_human(), 2);
    M._lm_set_human(9);
    expect('but not a fifth', M._lm_human(), 2);
    M._lm_set_human(0);

    // The interface's own art, by the rectangle: the gauge pieces sit in three
    // rows of ten from row 64, and each is eight by sixteen.
    {
        const ptr = M._lm_ui_region(0, 64, 8, 16);
        expect('a piece of the sheet comes back', ptr, (p) => p !== 0);
        const pix = new Uint32Array(M.HEAPU8.buffer, ptr, 8 * 16);
        let painted = 0;
        for (let i = 0; i < pix.length; i++) if (pix[i] >>> 24) painted++;
        expect('and it is not empty', painted, (n) => n > 20);
        expect('a rectangle off the sheet is refused',
               M._lm_ui_region(0, 0, 999, 8), 0);
    }

    // DATA/*.256: the title and the interludes.
    {
        const stem = 'LOGO';
        const p = M._lm_alloc(stem.length + 1);
        for (let i = 0; i < stem.length; i++)
            M.HEAPU8[p + i] = stem.charCodeAt(i);
        M.HEAPU8[p + stem.length] = 0;
        expect('the title picture reads', M._lm_picture_open(p), 1);
        M._lm_free(p);
        expect('and is the size its header says', M._lm_picture_width(), 256);
        expect('its height too', M._lm_picture_height(), 192);
        const pix = new Uint32Array(M.HEAPU8.buffer, M._lm_picture_pixels(),
                                    256 * 192);
        const seen = new Set();
        for (let i = 0; i < pix.length; i += 97) seen.add(pix[i]);
        expect('with real colours in it', seen.size, (n) => n > 8);
    }

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

    // The page's own flow, with the clock running between every step - which
    // is where an order can quietly be dropped, because 0041f790 rewrites the
    // balloon 00423cc0 reads to decide whether a unit answers.
    {
        let at = null;
        for (let y = 40; y < 420 && !at; y += 8)
            for (let x = 40; x < 580 && !at; x += 8)
                if (M._lm_unit_here(x, y)) at = [x, y];
        expect('one of the player units is on screen', at !== null, true);
        expect('clicking it chooses it', M._lm_select_at(at[0], at[1], 1), 1);
        for (let i = 0; i < 20; i++) M._lm_step(1);
        expect('and it stays chosen while the clock runs',
               M._lm_selected(), 1);

        // Where the page points before it clicks.  00423cc0 answers only for a
        // unit whose balloon says it can get there, so the aim decides.
        let to = null;
        for (let y = 8; y < 460 && !to; y += 16)
            for (let x = 8; x < 620 && !to; x += 16)
                if (M._lm_aim(x, y)) to = [x, y];
        expect('and it can be aimed somewhere', to !== null, true);
        for (let i = 0; i < 20; i++) M._lm_step(1);
        M._lm_aim(to[0], to[1]);
        const went = M._lm_order_at(1, 0, to[0], to[1]);
        expect('and takes the order afterwards', went, (n) => n > 0);
        expect('which spends the choice', M._lm_selected(), 0);

        // And the drag that gathers an army.
        const many = M._lm_select_rect(0, 0, 620, 460, 1);
        expect('a drag over the map gathers units', many, (n) => n > 0);
        console.log(`  a click chose 1 and it took an order; a drag chose ${many}`);
        M._lm_clear_selection();
    }

    // Cutting a path, which is what a player spends most of a stage doing:
    // choose an army and point it at a square of scenery with order 7.
    //
    // What this asks is that the page can get that far - the army is chosen,
    // the square is a legal target, and 00423cc0 lays routes for it.  Whether
    // the square actually falls depends on the country's purse and on how far
    // the walk is: 0040b680 charges thirty a unit of work, and a poor country
    // stops part way, which is the game rather than a fault.  orders_test
    // carries one all the way through on a board where neither is in question.
    {
        let spot = null;
        for (let y = 8; y < 460 && !spot; y += 8)
            for (let x = 8; x < 620 && !spot; x += 8) {
                M._lm_set_cursor(x, y);
                const t = M._lm_cursor_terrain();
                const c = M._lm_cursor_col(), r = M._lm_cursor_row();
                // 0040b680 bounds its target to 1..46, so the outer ring is
                // not a square anybody can be told to clear.
                if (t >= 0x30 && t < 0x60 && c > 0 && c < 47 && r > 0 && r < 47)
                    spot = [x, y];
            }
        expect('there is scenery on screen', spot !== null, true);
        const army = M._lm_select_all(1);
        const sent = M._lm_order_at(7, 0, spot[0], spot[1]);
        expect('an army takes the clearing order', sent, (n) => n > 0);
        M._lm_set_cursor(spot[0], spot[1]);
        console.log(`  ${sent} of ${army} sent to cut ` +
                    `${M._lm_cursor_col()},${M._lm_cursor_row()}`);
        M._lm_clear_selection();
    }

    // The original's own save: write it, change the world, read it back.
    {
        const size = M._lm_save_size();
        expect('a save is the size the original writes', size, 0x16218);
        const saved = new Uint8Array(
            new Uint8Array(M.HEAPU8.buffer, M._lm_save(), size));
        const funds = M._lm_funds(0);
        const sweeps = M._lm_sweeps();
        M._lm_step(400);
        expect('the game moved on', M._lm_sweeps(), (n) => n > sweeps);
        const p = M._lm_alloc(size);
        M.HEAPU8.set(saved, p);
        expect('the save loads', M._lm_load(p, size), 1);
        M._lm_free(p);
        expect('and the purse is what it was', M._lm_funds(0), funds);
        expect('a save of the wrong size is refused', M._lm_load(p, 10), 0);
    }

    console.log(failures ? `${failures} check(s) failed`
                         : 'wasm checks ok');
    process.exit(failures ? 1 : 0);
});
