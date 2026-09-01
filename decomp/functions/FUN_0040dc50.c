/* 0040dc50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __thiscall FUN_0040dc50(void *this,int param_1)

{
  int iVar1;
  MCIERROR MVar2;
  
  *(int *)((int)this + 0x14) = param_1 * 0x220 + DAT_00435db0 + 0x114;
  iVar1 = (**(code **)(*(int *)this + 4))();
  if (iVar1 == 0) {
    return false;
  }
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  _DAT_004358c4 = 0;
  MVar2 = mciSendCommandA((uint)*(ushort *)((int)this + 6),0x806,1,(int)this + 0x1c);
  *(MCIERROR *)((int)this + 0x4c) = MVar2;
  if (*(ushort *)((int)this + 6) < 7) {
    *(int *)(&DAT_004358a8 + (uint)*(ushort *)((int)this + 6) * 4) = param_1;
  }
  return *(int *)((int)this + 0x4c) == 0;
}


