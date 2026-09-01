/* 0040ed80 */

void __thiscall FUN_0040ed80(void *this,int param_1,BOOL param_2)

{
  HWND hWnd;
  
  hWnd = GetDlgItem(*(HWND *)((int)this + 4),param_1);
  if (hWnd != (HWND)0x0) {
    EnableWindow(hWnd,param_2);
  }
  return;
}


