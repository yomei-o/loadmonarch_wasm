/* 00421050 */

undefined4 FUN_00421050(void)

{
  byte *pbVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined2 local_8;
  int local_4;
  
  iVar3 = FUN_0041ec60(100);
  if (iVar3 == 0) {
    return 0;
  }
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  bVar2 = FUN_0041c690((undefined1 *)&local_8);
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
  *pbVar1 = *pbVar1 & 0x95 | 5;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  return 1;
}


