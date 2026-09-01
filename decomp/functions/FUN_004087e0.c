/* 004087e0 */

bool __fastcall FUN_004087e0(int param_1)

{
  UINT_PTR UVar1;
  
  if (*(UINT_PTR *)(param_1 + 0x39c) != 0) {
    KillTimer(*(HWND *)(param_1 + 8),*(UINT_PTR *)(param_1 + 0x39c));
    *(undefined4 *)(param_1 + 0x39c) = 0;
  }
  UVar1 = SetTimer(*(HWND *)(param_1 + 8),0x15,100,(TIMERPROC)0x0);
  *(UINT_PTR *)(param_1 + 0x39c) = UVar1;
  return (bool)('\x01' - (UVar1 == 0));
}


