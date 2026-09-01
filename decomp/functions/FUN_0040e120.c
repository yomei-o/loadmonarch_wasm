/* 0040e120 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0040e120(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  MCIERROR MVar3;
  
  iVar1 = *(int *)this;
  *(int *)((int)this + 0x14) = param_1 * 0x220 + DAT_00435db0 + 0x114;
  iVar2 = (**(code **)(iVar1 + 4))();
  if (iVar2 == 0) {
    return 0;
  }
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  _DAT_004358c4 = 0;
  MVar3 = mciSendCommandA((uint)*(ushort *)((int)this + 6),0x806,1,(int)this + 0x1c);
  *(MCIERROR *)((int)this + 0x4c) = MVar3;
  if (MVar3 != 0) {
    (**(code **)(iVar1 + 0xc))();
    return 0;
  }
  if (*(ushort *)((int)this + 6) < 7) {
    *(int *)(&DAT_004358a8 + (uint)*(ushort *)((int)this + 6) * 4) = param_1;
  }
  return 1;
}


