/* 00421660 */

undefined4 FUN_00421660(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  iVar5 = DAT_00437580 * 0x38 + DAT_00434534;
  uVar4 = (uint)*(byte *)(iVar5 + 8);
  uVar3 = (uint)*(byte *)(iVar5 + 9);
  uVar2 = *(uint *)(DAT_0043453c + 8 + (uVar4 * 0x30 + uVar3) * 0x18);
  if (0x1ef < uVar2) {
    return 0;
  }
  if (*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) < uVar2 * 2) {
    return 0;
  }
  iVar5 = FUN_00405000(DAT_0043756c,uVar4,uVar3);
  if (iVar5 == 0) {
    return 0;
  }
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  puVar1 = (uint *)(DAT_00434534 + 4 + DAT_00437580 * 0x38);
  *puVar1 = *puVar1 & 0xfffffffd;
  puVar1 = (uint *)(DAT_00434534 + 4 + DAT_00437580 * 0x38);
  *puVar1 = *puVar1 & 0xfffffffb;
  return 1;
}


