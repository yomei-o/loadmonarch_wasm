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

開くだけで動きます。ファルコムが
[今も配布している](https://www.falcom.co.jp/monarch/) `ds7e.zip`（英語版）と
`ds7j.zip`（日本語版）をリポジトリに置いてあり、ページが自分で取りに行きます。
上のボタンで English / 日本語 を切り替えられます。

お手元の zip を落とせばそちらを読みます。読み込んだ zip はブラウザの中だけで
扱われ、どこにも送られません（zip の展開も inflate も WebAssembly 側の C
コードがやっています）。

国名と16種の命令名はシナリオごとに違い、大きい背景ファイルの中の表から
読んでいます。日本語版は Shift-JIS なので、ページ側でそう復号しています。

面の順と面の名前は `MAP/NAME.TXT` から読んでいます（Conqueror's trial、
Backroad Euromap、…）。ファイル名の辞書順ではありません。

### 遊び方

ゲーム自身のクイックルール（ヘルプの3ページ目）がそのまま操作方法です。
**左ボタンだけ**で遊べます。

| | |
|---|---|
| 部隊を左クリック | 選ぶ。頭に「!」が出て、**時間が止まる** |
| 行き先を左クリック | 行けるなら**命令の一覧**が出る（行けなければ部隊を放す） |
| 一覧の命令 → 出てきた段 | 発令。部隊が動き出して時間も動き出す |
| 左ドラッグ | 枠の中の自分の部隊をまとめて選ぶ |
| Shift + 左クリック | 選び直す（普通のクリックは「行き先」なので） |
| 右ドラッグ | 地図を動かす |
| 矢印 / ホイール | スクロール |
| `[` / `]` | 前の面 / 次の面 |
| 棒グラフに触る | その棒が何かを吹き出しで言う |

メニューとツールバーは原作のもので、開始・一時停止・速度・ズーム・
セーブ・同盟・システム設定・ヘルプは全部そこから。

ポインタを別のマスへ動かすと**一瞬（既定 6 tick）時間が止まります**。
原作の仕掛け（`00422d98`）で、これがないと歩いている兵を掴めません。

## 移植の状況

実行ファイルから移植したもの:

* 地形・スプライト（8/16/32px の3バンクを正しい番号体系で）・パレットの脈動
* セルの掃引（領土の拡大、税、維持費、中立の湧き）
* エンティティ64体の行動 — 戦闘・合流・踏み荒らし・歩行
* **経路探索**（距離場を塗って勾配を降りる）と**命令16種**
* **税は首都から歩いて行ける領地からしか集まらない**
* **コンピュータの行動一式** — 近傍の仕事探し、広域探索、王への合流、
  敵王の狩り、無作為の開拓。独立した AI は無く、
  「命令を持たないユニット」の処理の中に入っている
* **王が兵を生む**（国力が王の半分未満なら王の戦力の1/4）、
  **自分の集落を拾って軍に戻す**
* 国の滅亡と面の決着、音楽の切り替え、状態の吹き出し

画面のものはほぼ原作から読んでいます:

* **メニューとダイアログ**は実行ファイルの resource から読む（日本語版は
  日本語のまま出る）。ヘルプ18ページと命令の説明も .data から
* **Unit / Progress / Graph の3つの窓**と国別の Status 窓。Graph は
  5か国×4本の棒グラフで、棒の頭に王・兵・家・コインが載り、
  1 tick に 1px ずつ伸びる。棒に触ると原作と同じ文がツールチップで出る
* **面の終わりの窓**（5つの場面と17行）と、**兵の行進**
* **表彰状**（クラスと段位、季節の絵）、**エンディング**、国の**滅亡通知**
* カーソルの枠、吹き出し、パレットの脈動

まだのもの: `00420ef0` の一部、`0041e920`、日本語版のダイアログに
書き込む数字の位置。詳細は `RESUME.md`。

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

| キー / 操作 | |
|---|---|
| 矢印 | スクロール |
| 1 / 2 / 3 | ズーム（8 / 16 / 32 px タイル） |
| PgUp / PgDn / `[` / `]` | 面の切替（`MAP/NAME.TXT` の順） |
| 右クリック | 手空きの部隊を選ぶ（もう一度で解除） |
| A | 命令中の部隊も含めて全部選ぶ |
| O | 送る命令を切り替える（16種） |
| 左クリック | 選択中なら派遣先、そうでなければユニット設置 |
| Space / S | 一時停止 / 1掃引だけ進める |
| F5 / F9 | 保存 / 再開（`loadmonarch.sav`、原作と同じ形式） |
| H | 情報表示 |
| Esc | 終了 |
