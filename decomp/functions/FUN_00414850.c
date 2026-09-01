/* 00414850 */

uint __thiscall FUN_00414850(void *this,int param_1)

{
  byte bVar1;
  uint uVar2;
  
  if (*(char *)((int)this + param_1 * 0x224 + 0x6664) == '\x04') {
    if ((*(byte *)((int)this + param_1 * 0x224 + 0x6670) & 2) != 0) {
      return (uint)(*(byte *)((int)this + param_1 * 0x224 + 0x666e) | 200);
    }
    return (uint)(*(byte *)((int)this + param_1 * 0x224 + 0x666c) & 6) |
           (*(uint *)((int)this + 0x238) & 2) >> 1 | 0xc0;
  }
  bVar1 = *(byte *)((int)this + param_1 * 0x224 + 0x6670);
  if ((bVar1 & 2) != 0) {
    return (-(uint)((*(byte *)((int)this + param_1 * 0x224 + 0x666d) & 0x20) == 0) & 0xfffffffc) +
           0xa4 | (uint)*(byte *)((int)this + param_1 * 0x224 + 0x666e) |
                  (uint)*(byte *)((int)this + param_1 * 0x224 + 0x6664) << 3;
  }
  if ((bVar1 & 1) != 0) {
    if ((*(byte *)((int)this + param_1 * 0x224 + 0x666d) & 0x20) == 0) {
      uVar2 = *(uint *)((int)this + param_1 * 0x224 + 0x6668);
      if (uVar2 < 1000) {
        uVar2 = 0x80;
      }
      else {
        uVar2 = (-(uint)(uVar2 < 10000) & 0xfffffffe) + 0x84;
      }
    }
    else {
      uVar2 = 0x86;
    }
    return uVar2 | (*(uint *)((int)this + 0x238) & 2) >> 1 |
                   (uint)*(byte *)((int)this + param_1 * 0x224 + 0x6664) << 3;
  }
  if ((*(byte *)((int)this + param_1 * 0x224 + 0x666d) & 0x20) == 0) {
    uVar2 = *(uint *)((int)this + param_1 * 0x224 + 0x6668);
    if (uVar2 < 1000) {
      uVar2 = 0;
    }
    else {
      uVar2 = (-(uint)(uVar2 < 10000) & 0xffffffe0) + 0x40;
    }
  }
  else {
    uVar2 = 0x60;
  }
  return uVar2 | (uint)(*(byte *)((int)this + param_1 * 0x224 + 0x666c) & 6) |
                 (*(uint *)((int)this + 0x238) & 2) >> 1 |
                 (uint)*(byte *)((int)this + param_1 * 0x224 + 0x6664) << 3;
}


