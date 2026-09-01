# The decompilation

Ghidra's output for `DS7E_WIN.EXE`, the Windows release of Falcom's Lord
Monarch. It is machine-generated, not written by anybody, and it is here as the
working record of the analysis: `RESUME.md` cites this code by address and by
line number, so the port cannot be followed without it.

| | |
|---|---|
| `all.c` | every function in one file, 32,240 lines |
| `functions/*.c` | the same, one file per function, named as Ghidra named it |
| `index.csv` | address, name, size and caller count for all 792 |

The executable itself is not here and never will be — a player supplies their
own copy of the game. Nothing in this directory is compiled or shipped; the
port under `src/` is written by hand from what is read here.

## Regenerating it

Ghidra 12.1.3 with JDK 21, and your own copy of the executable:

```sh
JAVA_HOME=C:/prog/ghidra/jdk-21.0.12.1+1 \
  /c/prog/ghidra/ghidra_12.1.3_PUBLIC/support/analyzeHeadless.bat <proj> lm \
  -import <path to DS7E_WIN.EXE> \
  -scriptPath tools/ghidra_scripts -postScript DecompileAll.java decomp
```

`tools/ghidra_scripts/DecompileAll.java` is the whole of the export. Ghidra
recovered all 792 functions with no failures, so a rerun on the same binary
should reproduce these files; a different Ghidra version will rename and
renumber things, which is what the committed copy protects against.

## Reading it

Names are Ghidra's: `FUN_<address>` for code, `DAT_<address>` for data. The
addresses are the currency of `RESUME.md` — every ported routine is recorded
there by the address it came from, along with what each unnamed field turned
out to mean.

Two habits worth keeping. Globals that look unrelated often are not: the game
keeps its cell array, entity array and faction array behind `DAT_0043453c`,
`DAT_00434538` and `DAT_00434534`, and almost every routine reaches them
directly. And a decompiled `switch` on a small integer is usually a table the
original wrote as one — the sixteen orders in `00403170` are the clearest case.
