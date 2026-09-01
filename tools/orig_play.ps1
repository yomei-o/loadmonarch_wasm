# Get the original into a stage and photograph it, with as little input as
# possible: clicks inside the game window issue orders and can wedge it.
$ErrorActionPreference = "Continue"
Add-Type -AssemblyName System.Drawing
Add-Type -AssemblyName System.Windows.Forms
Add-Type -TypeDefinition @'
using System;
using System.Runtime.InteropServices;
public struct RC { public int L, T, R, B; }
public static class Nat {
  [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h, out RC r);
  [DllImport("user32.dll")] public static extern bool SetForegroundWindow(IntPtr h);
}
'@
$here = (Get-Location).Path
Get-Process DS7E_WIN -ErrorAction SilentlyContinue | Stop-Process -Force
Start-Sleep -Milliseconds 600
$p = Start-Process -FilePath "$here\orig\DS7E_WIN\DS7E_WIN.EXE" -WorkingDirectory "$here\orig\DS7E_WIN" -PassThru
Start-Sleep -Seconds 4
# One Enter clears the splash; the game then loads the first stage by itself.
[void][Nat]::SetForegroundWindow($p.MainWindowHandle)
[System.Windows.Forms.SendKeys]::SendWait("{ENTER}")
for ($i = 0; $i -lt 6; $i++) {
  Start-Sleep -Seconds 3
  $proc = Get-Process DS7E_WIN -ErrorAction SilentlyContinue |
          Where-Object { $_.MainWindowHandle -ne 0 } | Select-Object -First 1
  if (-not $proc) { Write-Host "gone at $i"; break }
  $h = $proc.MainWindowHandle
  [void][Nat]::SetForegroundWindow($h)
  Start-Sleep -Milliseconds 700
  $r = New-Object RC
  [void][Nat]::GetWindowRect($h, [ref]$r)
  $w = $r.R - $r.L
  $ht = $r.B - $r.T
  Write-Host ("play{0:00}  {1}x{2}  '{3}'" -f $i, $w, $ht, $proc.MainWindowTitle)
  if ($w -gt 0 -and $ht -gt 0) {
    $bmp = New-Object System.Drawing.Bitmap $w, $ht
    $g = [System.Drawing.Graphics]::FromImage($bmp)
    $g.CopyFromScreen($r.L, $r.T, 0, 0, $bmp.Size)
    $bmp.Save("$here\tests\play" + $i.ToString("00") + ".png")
    $g.Dispose(); $bmp.Dispose()
  }
}
Get-Process DS7E_WIN -ErrorAction SilentlyContinue | Stop-Process -Force
