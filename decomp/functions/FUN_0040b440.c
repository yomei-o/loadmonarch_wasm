/* 0040b440 */

undefined4 FUN_0040b440(void)

{
  uint *puVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  iVar5 = DAT_0043756c * 0x224 + DAT_00434538;
  uVar7 = (uint)*(byte *)(iVar5 + 2);
  uVar6 = (uint)*(byte *)(iVar5 + 3);
  iVar5 = FUN_0041ac10(DAT_0043644c,DAT_00436450,uVar7,uVar6);
  if (iVar5 == 0) {
    FUN_00421750();
    return 3;
  }
  if (iVar5 != 1) {
    return 3;
  }
  iVar5 = (uVar7 * 0x30 + uVar6) * 0x18;
  pbVar3 = (byte *)(DAT_0043453c + iVar5);
  if (*pbVar3 < 0x40) {
    FUN_0041ac40();
    return 2;
  }
  bVar2 = pbVar3[0x10];
  if (bVar2 == 0x7b) {
    uVar6 = ~(*(int *)(pbVar3 + 0xc) - 0xffU) + 1;
    uVar7 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 4;
    if ((int)uVar6 < (int)uVar7) {
      uVar7 = uVar6;
    }
    iVar4 = FUN_0041a8d0((int)(uVar7 + ((int)uVar7 >> 0x1f & 3U)) >> 2);
    if (iVar4 == 0) {
      FUN_0041ac40();
      return 2;
    }
    puVar1 = (uint *)(DAT_0043453c + 0xc + iVar5);
    if (*puVar1 < 0xff) {
      *puVar1 = *puVar1 + uVar7;
    }
    else {
      *puVar1 = 0xff;
    }
    FUN_0041ac40();
    return 1;
  }
  if ((bVar2 == 0) || ((byte)(bVar2 - 0xc) < 5)) {
    uVar7 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 4;
    if ((int)(*(int *)(pbVar3 + 0xc) + 0xffU) < (int)uVar7) {
      uVar7 = *(int *)(pbVar3 + 0xc) + 0xffU;
    }
    iVar4 = FUN_0041a8d0((int)(uVar7 + ((int)uVar7 >> 0x1f & 3U)) >> 2);
    if (iVar4 == 0) {
      FUN_0041ac40();
      return 2;
    }
    puVar1 = (uint *)(DAT_0043453c + 0xc + iVar5);
    uVar6 = *puVar1;
    if (uVar6 < uVar7) {
      *puVar1 = ~(uVar6 - uVar7);
      *(undefined1 *)(DAT_0043453c + 0x10 + iVar5) = 0x7b;
      FUN_00405330();
      FUN_0040cd20(&DAT_00435db0,DAT_00434514 * 100 + 6,1);
      return 1;
    }
    *puVar1 = uVar6 - uVar7;
    FUN_0041ac40();
    return 4;
  }
  iVar5 = FUN_004208b0(uVar7,uVar6);
  if (iVar5 == 1) {
    FUN_0041ac40();
    return 2;
  }
  iVar5 = FUN_00421910();
  if (iVar5 == 1) {
    FUN_0041ac40();
    return 2;
  }
  return 3;
}


