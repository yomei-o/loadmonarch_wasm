/* 0041c270 */

int __fastcall FUN_0041c270(int param_1)

{
  tagRECT local_10;
  
  GetWindowRect(*(HWND *)(param_1 + 0x28),&local_10);
  return local_10.bottom - local_10.top;
}


