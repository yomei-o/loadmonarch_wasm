# Photograph the original game's window - the ground truth this port is
# checked against.
param([string]$Out = "orig1.png", [int]$Wait = 4000, [string]$Keys = "")
Add-Type -AssemblyName System.Drawing, System.Windows.Forms
Get-Process DS7E_WIN -ErrorAction SilentlyContinue | Stop-Process -Force
Start-Sleep -Milliseconds 400
$here = (Get-Location).Path
$proc = Start-Process -FilePath "$here\orig\DS7E_WIN\DS7E_WIN.EXE" -WorkingDirectory "$here\orig\DS7E_WIN" -PassThru
Start-Sleep -Milliseconds $Wait
Add-Type @"
using System; using System.Runtime.InteropServices;
public struct R { public int L,T,Rr,B; }
public class W {
  [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h, out R r);
  [DllImport("user32.dll")] public static extern bool SetForegroundWindow(IntPtr h);
}
"@
$h = $proc.MainWindowHandle
[void][W]::SetForegroundWindow($h)
Start-Sleep -Milliseconds 600
if ($Keys -ne "") { [System.Windows.Forms.SendKeys]::SendWait($Keys); Start-Sleep -Milliseconds 2000 }
$r = New-Object R
[void][W]::GetWindowRect($h, [ref]$r)
$w = $r.Rr - $r.L; $ht = $r.B - $r.T
$bmp = New-Object System.Drawing.Bitmap $w, $ht
$g = [System.Drawing.Graphics]::FromImage($bmp)
$g.CopyFromScreen($r.L, $r.T, 0, 0, $bmp.Size)
$bmp.Save("$here\tests\$Out")
$g.Dispose(); $bmp.Dispose()
Write-Output "shot tests/$Out ${w}x${ht}"
