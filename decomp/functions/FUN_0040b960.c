/* 0040b960 */

undefined4 FUN_0040b960(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = DAT_0043756c * 0x224 + DAT_00434538;
  uVar5 = (uint)*(byte *)(iVar3 + 2);
  uVar2 = (uint)*(byte *)(iVar3 + 3);
  iVar3 = FUN_0041ac10(DAT_0043644c,DAT_00436450,uVar5,uVar2);
  if (iVar3 == 0) {
    FUN_00421750();
    return 4;
  }
  if (iVar3 != 1) {
    return 3;
  }
  iVar3 = (uVar5 * 0x30 + uVar2) * 0x18;
  iVar4 = DAT_0043453c + iVar3;
  if (*(char *)(iVar4 + 0x10) == 'z') {
    *(int *)(iVar4 + 0xc) =
         *(int *)(iVar4 + 0xc) + (*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 5);
    puVar1 = (uint *)(DAT_0043453c + 0xc + iVar3);
    if (0xff < *puVar1) {
      *puVar1 = 0xff;
    }
    FUN_0041ac40();
    return 1;
  }
  if (0xf < (byte)(*(char *)(iVar4 + 0x10) - 0x20U)) {
    return 3;
  }
  uVar5 = *(int *)(iVar4 + 0xc) + 0xff;
  uVar2 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 5;
  if ((int)uVar5 <= (int)uVar2) {
    uVar2 = uVar5;
  }
  iVar6 = *(int *)(iVar4 + 0xc) - uVar2;
  if (0 < iVar6) {
    *(int *)(iVar4 + 0xc) = iVar6;
    FUN_0041ac40();
    return 4;
  }
  *(int *)(iVar4 + 0xc) = 0;
  *(undefined1 *)(DAT_0043453c + 0x10 + iVar3) = 0x7a;
  FUN_00405330();
  if (*(byte *)(DAT_0043453c + iVar3) < 0x40) {
    FUN_00420aa0((uint)*(byte *)(DAT_0043453c + iVar3),(char)DAT_00437580);
  }
  FUN_0041ac40();
  FUN_0040cd20(&DAT_00435db0,DAT_00434514 * 100 + 5,1);
  return 1;
}


