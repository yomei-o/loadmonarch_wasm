/* 00408830 */

void __fastcall FUN_00408830(int param_1)

{
  tagRECT local_10;
  
  GetWindowRect(*(HWND *)(param_1 + 8),&local_10);
  *(LONG *)(param_1 + 0x270) = local_10.left;
  *(LONG *)(param_1 + 0x274) = local_10.top;
  GetCursorPos((LPPOINT)(param_1 + 0x268));
  return;
}


