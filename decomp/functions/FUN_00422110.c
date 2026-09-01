/* 00422110 */

undefined4 FUN_00422110(void)

{
  byte *pbVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined2 local_8;
  int local_4;
  
  if ((uint)*(byte *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) - DAT_00437580 == 8) {
    *(undefined4 *)(DAT_00434538 + 0x18 + DAT_0043756c * 0x224) = 0x1f0;
    *(undefined1 *)(DAT_00434538 + 2 + DAT_0043756c * 0x224) = (undefined1)DAT_0043644c;
    *(undefined1 *)(DAT_00434538 + 3 + DAT_0043756c * 0x224) = (undefined1)DAT_00436450;
    pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
    if ((*pbVar1 & 0x20) == 0) {
      *pbVar1 = 2;
    }
    return 1;
  }
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  bVar2 = FUN_0041cbc0((byte *)&local_8);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    return 0;
  }
  iVar3 = DAT_0043756c * 0x224 + DAT_00434538;
  if (*(uint *)(iVar3 + 8) < (uint)(local_4 * 2)) {
    return 0;
  }
  *(undefined2 *)(iVar3 + 2) = local_8;
  iVar3 = FUN_00405000(DAT_0043756c,(uint)(byte)local_8,(uint)local_8._1_1_);
  if (iVar3 == 0) {
    return 0;
  }
  pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
  if ((*pbVar1 & 0x20) == 0) {
    *pbVar1 = 2;
  }
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  return 1;
}


