/* 0040b840 */

undefined4 FUN_0040b840(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  
  iVar2 = DAT_0043756c * 0x224 + DAT_00434538;
  uVar3 = (uint)*(byte *)(iVar2 + 2);
  uVar1 = (uint)*(byte *)(iVar2 + 3);
  iVar2 = FUN_0041ac10(DAT_0043644c,DAT_00436450,uVar3,uVar1);
  if (iVar2 == 0) {
    FUN_00421750();
    return 4;
  }
  if (iVar2 != 1) {
    return 3;
  }
  iVar2 = (uVar3 * 0x30 + uVar1) * 0x18;
  iVar4 = DAT_0043453c + iVar2;
  if (*(char *)(iVar4 + 0x10) != '{') {
    return 3;
  }
  puVar5 = (uint *)(iVar4 + 0xc);
  uVar1 = *puVar5;
  uVar3 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 5;
  if (uVar1 != 0) {
    if (uVar3 < uVar1) {
      *puVar5 = uVar1 - uVar3;
      FUN_0041ac40();
      return 4;
    }
    *puVar5 = 0;
  }
  *(undefined1 *)(DAT_0043453c + 0x10 + iVar2) = 0;
  FUN_0041ad90();
  FUN_0041ac40();
  FUN_0040cd20(&DAT_00435db0,DAT_00434514 * 100 + 4,1);
  return 1;
}


