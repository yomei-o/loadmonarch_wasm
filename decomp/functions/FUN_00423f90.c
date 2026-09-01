/* 00423f90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00423f90(void *this,int param_1,int param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  LONG LVar2;
  int iVar3;
  int iVar4;
  tagRECT local_10;
  
  GetClientRect(*(HWND *)((int)this + 8),&local_10);
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)((int)this + 0x260);
    param_3[1] = *(undefined4 *)((int)this + 0x264);
  }
  if ((((0x2e < param_1) || (0x2e < param_2)) || (param_1 < 1)) || (param_2 < 1)) {
    _DAT_00434454 = _DAT_00434454 + 1;
  }
  if (param_4 != 0) {
    FUN_00422fd0(this,(uint)*(byte *)((int)this + 0x3c4),(uint)*(byte *)((int)this + 0x3c5));
    *(char *)((int)this + 0x3c0) = (char)param_1;
    *(undefined1 *)((int)this + 0x3c1) = (undefined1)param_2;
  }
  iVar3 = 0;
  iVar4 = 0;
  iVar1 = *(int *)((int)this + 0x398);
  if (local_10.right / 2 <= param_1 * iVar1) {
    iVar3 = ((param_1 * iVar1 - local_10.right / 2) / iVar1) * iVar1;
  }
  if (local_10.bottom / 2 <= param_2 * iVar1) {
    iVar4 = ((param_2 * iVar1 - local_10.bottom / 2) / iVar1) * iVar1;
  }
  FUN_00424b90(this,CONCAT31((int3)((uint)(iVar3 << 0x10) >> 8),4));
  FUN_00424cc0(this,CONCAT31((int3)((uint)(iVar4 << 0x10) >> 8),4));
  LVar2 = FUN_0040a0c0(0xea61);
  if (LVar2 != 0) {
    InvalidateRect(*(HWND *)(LVar2 + 8),(RECT *)0x0,0);
    UpdateWindow(*(HWND *)(LVar2 + 8));
  }
  return;
}


