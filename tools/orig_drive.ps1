# Click through the original's opening and photograph each screen, so the port
# has ground truth for the map's orientation.
param([int]$Shots = 8, [int]$Step = 2200)
Add-Type -AssemblyName System.Drawing
Add-Type -AssemblyName System.Windows.Forms
Add-Type @"
using System; using System.Runtime.InteropServices;
public struct RC { public int L,T,R,B; }
public class Win {
  [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h, out RC r);
  [DllImport("user32.dll")] public static extern bool SetForegroundWindow(IntPtr h);
  [DllImport("user32.dll")] public static extern bool SetCursorPos(int x, int y);
  [DllImport("user32.dll")] public static extern void mouse_event(uint f, int dx, int dy, uint d, IntPtr e);
}
"@
$here = (Get-Location).Path
Get-Process DS7E_WIN -ErrorAction SilentlyContinue | Stop-Process -Force
Start-Sleep -Milliseconds 500
$p = Start-Process -FilePath "$here\orig\DS7E_WIN\DS7E_WIN.EXE" -WorkingDirectory "$here\orig\DS7E_WIN" -PassThru
Start-Sleep -Milliseconds 3500
$h = $p.MainWindowHandle
for ($i = 0; $i -lt $Shots; $i++) {
    [void][Win]::SetForegroundWindow($h)
    Start-Sleep -Milliseconds 400
    $r = New-Object RC
    [void][Win]::GetWindowRect($h, [ref]$r)
    $w = $r.R - $r.L; $ht = $r.B - $r.T
    if ($w -gt 0 -and $ht -gt 0) {
        $bmp = New-Object System.Drawing.Bitmap $w, $ht
        $g = [System.Drawing.Graphics]::FromImage($bmp)
        $g.CopyFromScreen($r.L, $r.T, 0, 0, $bmp.Size)
        $bmp.Save(("{0}\tests\drive{1:d2}.png" -f $here, $i))
        $g.Dispose(); $bmp.Dispose()
        Write-Output ("drive{0:d2}.png {1}x{2}" -f $i, $w, $ht)
    }
    $cx = [int](($r.L + $r.R) / 2); $cy = [int](($r.T + $r.B) / 2)
    [void][Win]::SetCursorPos($cx, $cy)
    [Win]::mouse_event(0x0002, 0, 0, 0, [IntPtr]::Zero)
    [Win]::mouse_event(0x0004, 0, 0, 0, [IntPtr]::Zero)
    Start-Sleep -Milliseconds 300
    [System.Windows.Forms.SendKeys]::SendWait("{ENTER}")
    Start-Sleep -Milliseconds $Step
}
Get-Process DS7E_WIN -ErrorAction SilentlyContinue | Stop-Process -Force
