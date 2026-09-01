/* 0040b330 */

undefined4 FUN_0040b330(void)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  bVar2 = *(byte *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18);
  if ((bVar2 != 0) && ((bVar2 < 0xc || (0x10 < bVar2)))) {
    return 3;
  }
  iVar4 = FUN_0041e670(DAT_0043644c,DAT_00436450);
  if (iVar4 != 0) {
    return 3;
  }
  iVar4 = FUN_0041a8d0(100);
  if (iVar4 == 0) {
    return 2;
  }
  uVar5 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
  if (199 < uVar5) {
    uVar5 = 200;
  }
  *(char *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) = (char)DAT_00437580 + '\b';
  *(uint *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18) = (uVar5 >> 1) + 1;
  puVar1 = (uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
  uVar3 = *puVar1;
  if (uVar3 <= uVar5) {
    FUN_00420b30(DAT_0043756c,DAT_0043644c,DAT_00436450);
    return 6;
  }
  *puVar1 = uVar3 - uVar5;
  return 1;
}


