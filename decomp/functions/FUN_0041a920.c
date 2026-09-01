/* 0041a920 */

undefined4 FUN_0041a920(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (uint)*(byte *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18);
  iVar2 = uVar3 - 0x14;
  if ((iVar2 < 4) && (-1 < iVar2)) {
    iVar2 = FUN_0041a8d0(*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 0xb);
    if (iVar2 == 1) {
      return 1;
    }
  }
  else if (uVar3 - DAT_00437580 == 8) {
    iVar2 = FUN_0041a8d0(*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 0xb);
    if (iVar2 == 1) {
      return 1;
    }
  }
  puVar1 = (uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
  uVar3 = *puVar1;
  uVar4 = (uVar3 >> 8) + 1;
  if (uVar3 <= uVar4) {
    FUN_00420aa0(DAT_0043756c,4);
    return 0;
  }
  *puVar1 = uVar3 - uVar4;
  return 1;
}


