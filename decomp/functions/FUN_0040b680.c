/* 0040b680 */

undefined4 FUN_0040b680(void)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar5 = DAT_0043756c * 0x224 + DAT_00434538;
  uVar3 = (uint)*(byte *)(iVar5 + 2);
  bVar2 = *(byte *)(iVar5 + 3);
  uVar8 = (uint)bVar2;
  iVar5 = FUN_0041ac10(DAT_0043644c,DAT_00436450,uVar3,uVar8);
  if (iVar5 == 0) {
    FUN_00421750();
    return 3;
  }
  if (iVar5 != 1) {
    return 3;
  }
  if ((((uVar3 == 0) || (uVar8 == 0)) || (0x2e < uVar3)) || (0x2e < bVar2)) {
    return 3;
  }
  iVar5 = (uVar3 * 0x30 + uVar8) * 0x18;
  iVar4 = DAT_0043453c + iVar5;
  bVar2 = *(byte *)(iVar4 + 0x10);
  if (bVar2 == 0x7a) {
    iVar6 = 2;
    uVar7 = *(int *)(iVar4 + 0xc) + 0xff;
  }
  else {
    if ((bVar2 < 0x30) || (0x5f < bVar2)) {
      return 3;
    }
    iVar6 = 0x1e;
    uVar7 = *(int *)(iVar4 + 0xc) + 1;
  }
  uVar9 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 4;
  if (uVar7 < uVar9) {
    uVar9 = uVar7;
  }
  iVar4 = FUN_0041a8d0(uVar9 * iVar6);
  if (iVar4 == 0) {
    FUN_0041ac40();
    return 2;
  }
  puVar1 = (uint *)(DAT_0043453c + 0xc + iVar5);
  uVar7 = *puVar1;
  if (uVar9 < uVar7) {
    *puVar1 = uVar7 - uVar9;
    FUN_0041ac40();
    return 4;
  }
  *puVar1 = ~(uVar7 - uVar9) + 1;
  *(undefined1 *)(DAT_0043453c + 0x10 + iVar5) = 0x20;
  FUN_0041acc0(uVar3,uVar8);
  FUN_0041ad90();
  FUN_0041ac40();
  FUN_0040cd20(&DAT_00435db0,DAT_00434514 * 100 + 7,1);
  return 1;
}


