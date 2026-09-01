/* 0040bb10 */

undefined4 FUN_0040bb10(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  
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
  pbVar4 = (byte *)((uVar3 * 0x30 + uVar1) * 0x18 + DAT_0043453c);
  if (pbVar4[0x10] != 5) {
    return 3;
  }
  if (*pbVar4 < 0x40) {
    FUN_0041ac40();
    return 4;
  }
  iVar2 = *(int *)(pbVar4 + 0xc) - (*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 3);
  if (-1 < iVar2) {
    *(int *)(pbVar4 + 0xc) = iVar2;
    FUN_0041ac40();
    return 4;
  }
  pbVar4[0x10] = 0x60;
  FUN_0041acc0(DAT_0043644c,DAT_00436450);
  FUN_0041ad90();
  return 1;
}


