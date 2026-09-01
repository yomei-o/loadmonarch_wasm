/* 0040e9b0 */

undefined4 __fastcall FUN_0040e9b0(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  wsprintfA((LPSTR)(param_1 + 0x1c),s_Pos_d_00433518,*(undefined4 *)(param_1 + 0x14));
  bVar1 = FUN_00424fa0(DAT_00436460,(LPSTR)(param_1 + 0x1c));
  if (CONCAT31(extraout_var,bVar1) == 1) {
    iVar2 = GetSystemMetrics(0);
    if ((iVar2 <= *(int *)((int)DAT_00436460 + 0x34)) ||
       (iVar2 = GetSystemMetrics(1), iVar2 <= *(int *)((int)DAT_00436460 + 0x38))) {
      *(undefined4 *)((int)DAT_00436460 + 0x34) = 0;
      *(undefined4 *)((int)DAT_00436460 + 0x38) = 0;
    }
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0x0,*(int *)((int)DAT_00436460 + 0x34),
                 *(int *)((int)DAT_00436460 + 0x38),0,0,5);
    return 1;
  }
  return 1;
}


