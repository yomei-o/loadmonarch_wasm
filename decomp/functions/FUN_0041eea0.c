/* 0041eea0 */

int __cdecl FUN_0041eea0(uint param_1,int param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  iVar3 = 1;
  do {
    bVar1 = *(byte *)(DAT_0043453c +
                     (((char)(&DAT_00434400)[iVar3] + param_2) * 0x30 +
                      (int)(char)(&DAT_00434410)[iVar3] + param_3) * 0x18);
    if ((((bVar1 < 0x40) && (bVar1 != param_1)) &&
        (iVar5 = (uint)bVar1 * 0x224 + DAT_00434538, *(byte *)(iVar5 + 4) != DAT_00437580)) &&
       (*(char *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) != *(char *)(iVar5 + 4))) {
      uVar2 = *(int *)(iVar5 + 8) + uVar4;
      uVar4 = 0xffffffff;
      if (uVar2 != 0xffffffff) {
        uVar4 = uVar2;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 5);
  if (uVar4 == 0) {
    return 8;
  }
  return (-(uint)(uVar4 < *(uint *)(DAT_00434538 + 8 + param_1 * 0x224)) & 0xfffffffe) + 9;
}


