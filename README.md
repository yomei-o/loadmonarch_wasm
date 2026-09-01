# loadmonarch_wasm

Nihon Falcom の「Lord Monarch Online」(DS7E_WIN) を読み解いて、
ネイティブ、そしてブラウザで動かすための作業場。

原作の実行ファイルとデータはリポジトリに置かない。手元の ds7e.zip を
`orig/` に展開して使う。

* `tools/dump_assets.py` — .256/.PAL/.MAP を PNG に出す（形式の実証つき）
* `tools/ghidra_scripts/DecompileAll.java` — 792関数を C に落とす Ghidra スクリプト
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
