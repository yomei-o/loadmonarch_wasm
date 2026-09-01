/* 0040ed20 */

void __thiscall FUN_0040ed20(void *this,int param_1,LPCSTR param_2)

{
  HWND hWnd;
  
  hWnd = GetDlgItem(*(HWND *)((int)this + 4),param_1);
  SetWindowTextA(hWnd,param_2);
  return;
}


