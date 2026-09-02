#!/bin/sh
# Run a build at low priority so the rest of the machine stays usable.
#
# A parallel compile here starves the desktop, so every build in this
# repository goes through this.  cmd's `start /LOW` sets the priority class at
# creation and every child the compiler driver spawns inherits it, which is
# both lighter and more reliable than watching for processes and renicing them
# afterwards.
#
#   sh tools/lowpri.sh gcc -O2 ... -o out.exe
#
# LOWPRI=BELOWNORMAL picks the gentler class when a build is long enough that
# idle priority would crawl.
#
# `start /WAIT` waits, but its exit status does not survive the trip back out
# through `cmd /c` - this script used to return 0 for a compile that had
# failed, so a build script with `set -e` sailed past the error and the tests
# then ran against the previous binary.  The command therefore goes into a
# small batch file that records the real exit code, and that is what is
# returned here.
set -e
[ $# -gt 0 ] || { echo "usage: lowpri.sh <command>..." >&2; exit 2; }
CLASS="${LOWPRI:-LOW}"

work="$(mktemp -d)"
trap 'rm -rf "$work"' EXIT
batch="$work/run.bat"
status="$work/status"

{
    printf '@echo off\r\n'
    # Each argument quoted, so paths with spaces survive - and any that looks
    # like a POSIX path becomes a Windows one first.  MSYS does that itself
    # when handing arguments to a native program, but not when they are
    # written into a file, and cmd cannot run /c/prog/w64devkit/bin/gcc.
    for arg in "$@"; do
        case "$arg" in
            # cygpath renders this as \\.\NUL, which the assembler will not
            # open; cmd's own name for it is what tools expect.
            /dev/null) arg="nul" ;;
            /*) arg="$(cygpath -w "$arg")" ;;
        esac
        printf '"%s" ' "$arg"
    done
    printf '\r\n'
    # The redirection goes first on purpose.  Written the natural way round,
    # `echo %ERRORLEVEL%> "file"` expands to `echo 0> "file"`, and cmd reads
    # the `0>` as a redirection of stdin - so echo prints "ECHO is off" to the
    # console and the file is left empty.
    printf '>"%s" echo %%ERRORLEVEL%%\r\n' "$(cygpath -w "$status")"
} > "$batch"

# //c and //B rather than /c and /B: MSYS would otherwise treat them as paths.
# The batch runs under its own `cmd /c` rather than being handed to `start`
# directly, which is what keeps a stray command prompt out of the build log.
cmd //c start "//${CLASS}" //B //WAIT cmd //c "$(cygpath -w "$batch")"

[ -f "$status" ] || { echo "lowpri.sh: the build left no exit status" >&2; exit 1; }
read -r code < "$status"
# Strip the stray whitespace cmd's echo leaves behind.
code="$(printf '%s' "$code" | tr -d ' \r')"
case "$code" in
    ''|*[!0-9]*) exit 1 ;;
esac
exit "$code"
