/* 0041a3d0 */

void __fastcall FUN_0041a3d0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1[5] & 0xffff;
  uVar1 = (uint)param_1[5] >> 0x10;
  if ((((0x60 < uVar2) && (uVar2 < 0x70)) && (0x28 < uVar1)) && (uVar1 < 0x38)) {
    DAT_0043769c = DAT_0043769c + 1 & 1;
  }
  InvalidateRect((HWND)param_1[2],(RECT *)0x0,0);
  (**(code **)(*param_1 + 0x18))();
  return;
}


