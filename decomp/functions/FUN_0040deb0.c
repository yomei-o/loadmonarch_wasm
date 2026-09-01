/* 0040deb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0040deb0(void *this,int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(DAT_00435db0 + 0x110 + param_1 * 0x220) == 0) {
    return 0;
  }
  if (*(short *)((int)this + 6) == 0) {
    iVar2 = (**(code **)(*(int *)this + 4))();
    if (iVar2 == 0) {
      return 0;
    }
  }
  uVar1 = *(uint *)(DAT_00435db0 + 0x110 + param_1 * 0x220);
  uVar3 = uVar1 & 0xff;
  *(uint *)((int)this + 0x20) = uVar3;
  *(uint *)((int)this + 0x2c) = uVar3;
  uVar1 = *(uint *)((int)this + uVar1 * 4 + 0x5c);
  *(uint *)((int)this + 0x24) =
       ((uVar1 >> 0x10 & 0xff) << 0x10 | uVar1 & 0xff) << 8 | ((uVar1 & 0xffff) >> 8) << 0x10 |
       uVar3;
  _DAT_004358c4 = 0;
  mciSendCommandA((uint)*(ushort *)((int)this + 6),0x806,0xd,(int)this + 0x1c);
  if (*(ushort *)((int)this + 6) < 7) {
    *(int *)(&DAT_004358a8 + (uint)*(ushort *)((int)this + 6) * 4) = param_1;
  }
  return 1;
}


