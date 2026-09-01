/* 00425a30 */

void __fastcall FUN_00425a30(int param_1)

{
  tagRECT local_10;
  
  GetWindowRect(*(HWND *)(param_1 + 0x250),&local_10);
  if (*(int *)(DAT_004344e4 + 8) == *(int *)(param_1 + 8)) {
    local_10.left = 0;
    local_10.top = 0;
    local_10.right = GetSystemMetrics(0);
    local_10.bottom = GetSystemMetrics(1);
  }
  ClipCursor(&local_10);
  GetWindowRect(*(HWND *)(param_1 + 8),&local_10);
  ((LPPOINT)(param_1 + 0x270))->x = local_10.left;
  *(LONG *)(param_1 + 0x274) = local_10.top;
  if (*(HWND *)(param_1 + 0x250) != (HWND)0x0) {
    ScreenToClient(*(HWND *)(param_1 + 0x250),(LPPOINT)(param_1 + 0x270));
  }
  GetCursorPos((LPPOINT)(param_1 + 0x268));
  return;
}


