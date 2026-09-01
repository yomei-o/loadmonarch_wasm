/* 0040a0c0 */

LONG __cdecl FUN_0040a0c0(int param_1)

{
  HWND hWnd;
  LONG LVar1;
  
  hWnd = GetWindow(*(HWND *)(DAT_004344e4 + 8),5);
  while( true ) {
    if (hWnd == (HWND)0x0) {
      return 0;
    }
    LVar1 = GetWindowLongA(hWnd,-0x15);
    if ((LVar1 != 0) && (*(int *)(LVar1 + 4) == param_1)) break;
    hWnd = GetWindow(hWnd,2);
  }
  return LVar1;
}


