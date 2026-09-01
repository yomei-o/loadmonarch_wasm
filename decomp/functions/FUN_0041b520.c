/* 0041b520 */

uint __cdecl FUN_0041b520(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x224 + DAT_00434538;
  bVar1 = *(byte *)(iVar3 + 4);
  if (bVar1 == 4) {
    if ((*(byte *)(iVar3 + 0x10) & 2) != 0) {
      return (uint)(*(byte *)(iVar3 + 0xe) | 200);
    }
    return (uint)(*(byte *)(iVar3 + 0xc) & 6) | (DAT_00435b1c & 2 | 0x180) >> 1;
  }
  if ((*(byte *)(iVar3 + 0x10) & 2) != 0) {
    return (-(uint)((*(byte *)(iVar3 + 0xd) & 0x20) == 0) & 0xfffffffc) + 0xa4 |
           (uint)*(byte *)(iVar3 + 0xe) | (uint)bVar1 << 3;
  }
  if ((*(byte *)(iVar3 + 0x10) & 1) != 0) {
    if ((*(byte *)(iVar3 + 0xd) & 0x20) == 0) {
      if (*(uint *)(iVar3 + 8) < 1000) {
        uVar2 = 0x80;
      }
      else {
        uVar2 = (-(uint)(*(uint *)(iVar3 + 8) < 10000) & 0xfffffffe) + 0x84;
      }
    }
    else {
      uVar2 = 0x86;
    }
    return uVar2 | (uint)bVar1 << 3 | (DAT_00435b1c & 2) >> 1;
  }
  if ((*(byte *)(iVar3 + 0xd) & 0x20) == 0) {
    if (*(uint *)(iVar3 + 8) < 1000) {
      uVar2 = 0;
    }
    else {
      uVar2 = (-(uint)(*(uint *)(iVar3 + 8) < 10000) & 0xffffffe0) + 0x40;
    }
  }
  else {
    uVar2 = 0x60;
  }
  return uVar2 | *(byte *)(iVar3 + 0xc) & 6 | (uint)bVar1 << 3 | (DAT_00435b1c & 2) >> 1;
}


