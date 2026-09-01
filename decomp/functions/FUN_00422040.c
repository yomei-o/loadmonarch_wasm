/* 00422040 */

undefined4 FUN_00422040(void)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined2 local_8;
  int local_4;
  
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  bVar1 = FUN_0041caf0(&local_8);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    return 0;
  }
  iVar2 = DAT_0043756c * 0x224 + DAT_00434538;
  if (*(uint *)(iVar2 + 8) < (uint)(local_4 * 2)) {
    return 0;
  }
  *(undefined2 *)(iVar2 + 2) = local_8;
  iVar2 = FUN_00405000(DAT_0043756c,(uint)(byte)local_8,(uint)local_8._1_1_);
  if (iVar2 == 1) {
    *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 3;
    *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
    return 1;
  }
  return 0;
}


