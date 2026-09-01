/* 00408290 */

void __fastcall FUN_00408290(int param_1)

{
  DAT_004344e0 = 0xffffffff;
  if (*(UINT *)(param_1 + 0x398) != 0) {
    timeKillEvent(*(UINT *)(param_1 + 0x398));
    DAT_004344e0 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x398) = 0;
  }
  if (*(UINT_PTR *)(param_1 + 0x39c) != 0) {
    KillTimer(*(HWND *)(param_1 + 8),*(UINT_PTR *)(param_1 + 0x39c));
    *(undefined4 *)(param_1 + 0x39c) = 0;
  }
  return;
}


