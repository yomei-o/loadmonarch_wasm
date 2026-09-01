@echo off
rem Build the native app with MSVC.  Run from the repository root.
for /f "usebackq tokens=*" %%i in (`"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products * -property installationPath`) do set VSPATH=%%i
call "%VSPATH%\VC\Auxiliary\Build\vcvars64.bat" >nul
cl /nologo /O2 /W4 /Fe:loadmonarch_msvc.exe ^
   src\win32_main.c src\world.c src\render.c src\bz.c src\gfx.c ^
   /link /SUBSYSTEM:WINDOWS gdi32.lib user32.lib
