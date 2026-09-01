# RESUME - Lord Monarch (DS7E_WIN) を C に戻して native -> WASM

## 対象

Nihon Falcom "Lord Monarch Online" (DS7E_WIN.EXE, 249,856 bytes)。
ユーザー配布の ds7e.zip を orig/ に展開して使う（**リポジトリにはコミットしない**）。

## バイナリの素性（実測）

| | |
|---|---|
| 形式 | PE32 / x86 32bit フラット、6セクション、ImageBase 0x400000 |
| コード | .text 185KB、64,044 命令、**関数 792**（Ghidra が全部復元、失敗0） |
| 言語 | **純 C**（C++ マングル名ゼロ）、MSVC 4.x / linker 3.0 |
| 依存 | KERNEL32/USER32/GDI32/comdlg32/ADVAPI32/WINMM/COMCTL32 のみ。**DirectX 無し** |
| 描画 | CreateDIBSection + StretchBlt + パレット（simtower のシムと同じ形） |
| 音 | MCI (mciSendCommand) で MIDI、timeSetEvent |

## データ形式（全部解読済み）

| | |
|---|---|
| `.256` | uint32 幅 + uint32 高さ + 8bit インデックス。**LOGO をPNG復元して確認済み** |
| `.PAL` | 256 × RGBQUAD (B,G,R,0) = Windows の DIB カラーテーブル |
| `.MAP` | 48×48 の地形バイト + 末尾 uint16（10/20/30/40/50 の難易度par）。先頭にヘッダは無い |
| `NAME.TXT` | INI（`MAP=15`、`[0]`..`[14]` に NAME=/FILE=） |
| `SOUND.CFG` | テキスト（LOOP=/CD=/WAVE=） |
| `.MID` | 標準 MIDI |
| `.BZ` | Falcom 自前 LZ。**src/bz.c に再実装済み**（下記） |

## .BZ コーデック（0041fe40 / 0041fef0 / 00420240）

コンテナは行単位: uint16 の行長 -> 次の1バイトが 0 ならビット詰め版(00420240)、
それ以外ならバイトオペコード版(0041fef0)。行末に区切り1バイト。
BG/CHR は 1ファイル=1行で、展開後はちょうど **0x8030 = 32,816 バイト**
（ゲーム側が確保するバッファと一致 = 検証になる）。

* バイト版オペコード: bit7 で LZ マッチ（距離13bit/長さ4..7、続く 0x60..0x7f で
  同じマッチを延長）、bit6 で RLE（長さ4bit or 12bit）、bit5 で長リテラル(12bit)、
  それ以外で短リテラル(5bit)。
* ビット版: 0ビット=リテラル1バイト。1ビットの後、続く1ビットが0なら距離1バイト、
  1なら距離 = 5bit(MSB先頭) << 8 | 1バイト。距離0で行終端、距離1は長RLEのエスケープ。
  長さは 2/3/4/5/(3bit+6)/(1バイト+14) のユナリ。
* **`FUN_004204c0` は MSB ファースト**（v = v*2 + bit）。ここを LSB にすると全部壊れる。

## 手順（この順で）

1. **BZ 展開**（済） -> タイル並べ替え `FUN_00406810(dest, out, tileSize)` を読んで
   BG/CHR を実際のスプライトとして PNG 化する。ここまでで全アセットが手に入る
2. **ネイティブ版**を Win32+GDI で。VS2022 と mingw の両方でビルドできること
3. **WASM 化**。描画が DIB+StretchBlt なので simtower_wasm のシムがほぼ流用できる

## 環境

* Ghidra 12.1.3 + JDK 21 を `C:\prog\ghidra` に。再実行:
  `JAVA_HOME=C:/prog/ghidra/jdk-21.0.12.1+1 /c/prog/ghidra/ghidra_12.1.3_PUBLIC/support/analyzeHeadless.bat <proj> lm -import <exe> -scriptPath tools/ghidra_scripts -postScript DecompileAll.java <outdir>`
  プロジェクトディレクトリは**事前に mkdir が要る**（無いと即 abort）
* 出力 decomp/（all.c 32,240行、functions/*.c、index.csv）は git 管理外
* ビルドマシン 192.168.6.14 はこの時点で SSH 不通だったのでローカルで実行
