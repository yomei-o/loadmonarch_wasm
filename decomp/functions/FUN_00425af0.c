/* 00425af0 */

void __fastcall FUN_00425af0(int param_1)

{
  if (*(HWND *)(param_1 + 8) != (HWND)0x0) {
    FUN_00425010(DAT_00436460,(LPCSTR)(param_1 + 0x14c),*(HWND *)(param_1 + 8));
    DestroyWindow(*(HWND *)(param_1 + 8));
  }
  FUN_00408e40();
  return;
}


