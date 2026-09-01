# Launch the native build, give it a moment, and photograph its window.
param([string]$Exe = "loadmonarch.exe", [string]$Out = "tests/native.png",
      [int]$Wait = 2500, [string]$Keys = "", [int]$After = 0)
Add-Type -AssemblyName System.Drawing, System.Windows.Forms
$proc = Start-Process -FilePath $Exe -PassThru
Start-Sleep -Milliseconds $Wait
if ($Keys -ne "") {
    [System.Windows.Forms.SendKeys]::SendWait($Keys)
    Start-Sleep -Milliseconds 900
}
# -After lets the simulation run on after the keys, which is the only way to
# watch it: reloading a stage resets its sweep counter.
if ($After -gt 0) { Start-Sleep -Milliseconds $After }
Add-Type @"
using System;
using System.Runtime.InteropServices;
public struct R { public int L, T, Rr, B; }
public class W {
  [DllImport("user32.dll")] public static extern bool GetClientRect(IntPtr h, out R r);
  [DllImport("user32.dll")] public static extern bool ClientToScreen(IntPtr h, ref System.Drawing.Point p);
  [DllImport("user32.dll")] public static extern bool SetForegroundWindow(IntPtr h);
}
"@ -ReferencedAssemblies System.Drawing
$h = $proc.MainWindowHandle
[void][W]::SetForegroundWindow($h)
$r = New-Object R
[void][W]::GetClientRect($h, [ref]$r)
$origin = New-Object System.Drawing.Point 0, 0
[void][W]::ClientToScreen($h, [ref]$origin)
$bmp = New-Object System.Drawing.Bitmap ($r.Rr), ($r.B)
$g = [System.Drawing.Graphics]::FromImage($bmp)
$g.CopyFromScreen($origin.X, $origin.Y, 0, 0, $bmp.Size)
$bmp.Save((Resolve-Path -LiteralPath ".").Path + "\" + $Out.Replace("/", "\"))
$g.Dispose(); $bmp.Dispose()
Stop-Process -Id $proc.Id -Force
Write-Output "shot $Out"
