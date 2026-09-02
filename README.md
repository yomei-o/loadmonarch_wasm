# lord_monarch_online_wasm

Nihon Falcom の「Lord Monarch Online」(DS7E_WIN) を読み解いて、
ネイティブ、そしてブラウザで動かすための作業場。

原作の実行ファイルとデータはリポジトリに置かない。手元の ds7e.zip を
`orig/` に展開して使う。

* `tools/dump_assets.py` — .256/.PAL/.MAP を PNG に出す（形式の実証つき）
* `tools/ghidra_scripts/DecompileAll.java` — 792関数を C に落とす Ghidra スクリプト
* `src/world.c` — ステージ（48x48 セル）と背景バンクの読み込み
* `src/render.c` — 8bit インデックス面への描画（ネイティブと WASM で共通）
* `src/win32_main.c` — ネイティブの器（ウィンドウ、DIB、BitBlt）
* `RESUME.md` — 解析結果と次の手順

## 試す

```sh
python tools/dump_assets.py orig/DS7E_WIN tests/assets     # .256/.PAL/.MAP
gcc -O2 -o tests/bz_test.exe tests/bz_test.c src/bz.c
./tests/bz_test.exe orig/DS7E_WIN/BG/*.BZ                  # 全40ファイルの展開

# タイルバンクを絵にする（8/16/32）
gcc -O2 -o tests/tiles_test.exe tests/tiles_test.c src/bz.c src/gfx.c
./tests/tiles_test.exe orig/DS7E_WIN/CHR/C_010M.BZ 16 orig/DS7E_WIN/DATA/DATA1.RGB out.ppm

# ステージを丸ごと描く（地形 + そのマップが指定する背景セット）
gcc -O2 -o tests/map_test.exe tests/map_test.c src/bz.c src/gfx.c
./tests/map_test.exe orig/DS7E_WIN/MAP/B_000.MAP orig/DS7E_WIN/BG/B_010M.BZ 16 map.ppm

# UI シート（256x1024）
gcc -O2 -o tests/data1_test.exe tests/data1_test.c src/bz.c
./tests/data1_test.exe orig/DS7E_WIN/DATA/DATA1.BZ ui.pgm
```

## ブラウザで動かす

**https://yomei-o.github.io/lord_monarch_online_wasm/**

お手元の `ds7e.zip` をページに落とすと動きます。ゲームのデータはこのリポジトリにも
ページにも入っていません。読み込んだ zip はブラウザの中だけで扱われ、どこにも
送られません（zip の展開も inflate も WebAssembly 側の C コードがやっています）。

| | |
|---|---|
| クリック | ユニットを置く（資金100） |
| 矢印 | スクロール |
| 1 / 2 / 3 | ズーム（8 / 16 / 32px タイル） |
| Space | 一時停止 |
| 音楽ボタン | 曲を鳴らす（`.MID` を C 側で合成） |

音は原作の `.MID` をそのまま使います。ブラウザにシンセサイザは無いので、
`src/midi.c` が MIDI を解析して自前の音源で PCM を作り、ページはそれを
Web Audio に流すだけです（General MIDI の音色ではなく、音程と長さを再現する
簡易音源）。`tests/midi_test.exe` が同じ合成結果を WAV に書き出せます。

```sh
sh tools/build_wasm.sh          # -> docs/loadmonarch.js + docs/index.html
node tests/wasm_check.js        # ブラウザ無しで WASM 版を検証
```

## ネイティブ版

```sh
# mingw
gcc -O2 -mwindows -o loadmonarch.exe     src/win32_main.c src/world.c src/render.c src/bz.c src/gfx.c -lgdi32
# MSVC
tools/build_msvc.bat
```

`loadmonarch.exe` に DS7E_WIN ディレクトリを渡す（省略時は `orig/DS7E_WIN` を探す）。

| キー | |
|---|---|
| 矢印 | スクロール |
| 1 / 2 / 3 | ズーム（8 / 16 / 32 px タイル） |
| PgUp / PgDn | ステージ切替（全15面） |
| Esc | 終了 |
