/* 0041cdc0 */

int FUN_0041cdc0(void)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = 0;
  pbVar2 = (byte *)(DAT_00434538 + 0x10);
  do {
    if ((*pbVar2 & 0x80) != 0) {
      return iVar1;
    }
    pbVar2 = pbVar2 + 0x224;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x40);
  return 0x40;
}


