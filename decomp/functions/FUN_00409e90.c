/* 00409e90 */

int FUN_00409e90(void)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = 0;
  iVar5 = 0;
  iVar6 = 0;
  do {
    bVar1 = *(byte *)(DAT_0043453c + iVar6);
    if ((bVar1 < 0x40) && ((*(byte *)(DAT_00434538 + 0xd + (uint)bVar1 * 0x224) & 0x20) == 0)) {
      iVar2 = FUN_0040a020((uint)bVar1,iVar5 / 0x30,iVar5 % 0x30,1);
      if (iVar2 == 1) {
        iVar4 = iVar4 + 1;
      }
    }
    iVar6 = iVar6 + 0x18;
    iVar5 = iVar5 + 1;
  } while (iVar6 < 0xd800);
  piVar3 = (int *)FUN_0040a0c0(60000);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 100))();
  }
  return iVar4;
}


