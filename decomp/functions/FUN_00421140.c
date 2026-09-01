/* 00421140 */

undefined4 FUN_00421140(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  
  iVar3 = DAT_00437580 * 0x38 + DAT_00434534;
  if ((*(byte *)(iVar3 + 4) & 0x20) == 0) {
    return 0;
  }
  iVar3 = *(int *)(iVar3 + 0xc);
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  pbVar4 = (byte *)(iVar3 * 0x224 + DAT_00434538);
  if (*(int *)(pbVar4 + 0x18) == 0x1f0) {
    bVar1 = *pbVar4;
    bVar2 = pbVar4[1];
  }
  else {
    bVar1 = pbVar4[2];
    bVar2 = pbVar4[3];
  }
  iVar3 = DAT_0043756c * 0x224 + DAT_00434538;
  if (*(uint *)(iVar3 + 8) < *(uint *)(DAT_0043453c + 8 + ((uint)bVar1 * 0x30 + (uint)bVar2) * 0x18)
     ) {
    return 0;
  }
  *(byte *)(iVar3 + 2) = bVar1;
  *(byte *)(DAT_00434538 + 3 + DAT_0043756c * 0x224) = bVar2;
  iVar3 = FUN_00405000(DAT_0043756c,(uint)bVar1,(uint)bVar2);
  if (iVar3 == 0) {
    return 0;
  }
  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 2;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  return 1;
}


