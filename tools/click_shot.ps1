# Start the native build, click a few cells near the player's castle, and
# photograph the result - the only way to see whether the raise-a-unit order
# takes and whether the country then grows from it.
param([string]$Out = "tests/click.png", [int]$Wait = 3000,
      [string]$Keys = "", [int]$After = 0,
      [int]$ClickX = 320, [int]$ClickY = 240, [int]$Clicks = 1,
      [int]$Spread = 40)
Add-Type -AssemblyName System.Drawing
Add-Type -AssemblyName System.Windows.Forms
Add-Type -TypeDefinition @'
using System;
using System.Runtime.InteropServices;
public struct RC { public int L, T, R, B; }
public static class Nat {
  [DllImport("user32.dll")] public static extern bool GetClientRect(IntPtr h, out RC r);
  [DllImport("user32.dll")] public static extern bool ClientToScreen(IntPtr h, ref System.Drawing.Point p);
  [DllImport("user32.dll")] public static extern bool SetForegroundWindow(IntPtr h);
  [DllImport("user32.dll")] public static extern bool SetCursorPos(int x, int y);
  [DllImport("user32.dll")] public static extern void mouse_event(uint f, int dx, int dy, uint d, IntPtr e);
}
'@ -ReferencedAssemblies System.Drawing
$here = (Get-Location).Path
$proc = Start-Process -FilePath "$here\loadmonarch.exe" -PassThru
Start-Sleep -Milliseconds $Wait
$h = $proc.MainWindowHandle
[void][Nat]::SetForegroundWindow($h)
Start-Sleep -Milliseconds 400
if ($Keys -ne "") {
    [System.Windows.Forms.SendKeys]::SendWait($Keys)
    Start-Sleep -Milliseconds 900
}
$origin = New-Object System.Drawing.Point 0, 0
[void][Nat]::ClientToScreen($h, [ref]$origin)
for ($i = 0; $i -lt $Clicks; $i++) {
    $x = $origin.X + $ClickX + $i * $Spread
    $y = $origin.Y + $ClickY
    [void][Nat]::SetCursorPos($x, $y)
    [Nat]::mouse_event(2, 0, 0, 0, [IntPtr]::Zero)
    [Nat]::mouse_event(4, 0, 0, 0, [IntPtr]::Zero)
    Start-Sleep -Milliseconds 500
}
if ($After -gt 0) { Start-Sleep -Milliseconds $After }
$r = New-Object RC
[void][Nat]::GetClientRect($h, [ref]$r)
$bmp = New-Object System.Drawing.Bitmap ($r.R), ($r.B)
$g = [System.Drawing.Graphics]::FromImage($bmp)
$g.CopyFromScreen($origin.X, $origin.Y, 0, 0, $bmp.Size)
$bmp.Save("$here\" + $Out.Replace("/", "\"))
$g.Dispose()
$bmp.Dispose()
Stop-Process -Id $proc.Id -Force
Write-Output "shot $Out"
