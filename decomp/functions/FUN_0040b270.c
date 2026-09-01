/* 0040b270 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040b270(void)

{
  int iVar1;
  int iVar2;
  char local_a;
  char local_9;
  
  if (DAT_00437570 != 0) {
    *(undefined4 *)(DAT_0043453c + 0x14 + (DAT_00437574 * 0x30 + _DAT_00437578) * 0x18) = 0;
    FUN_0041d6d0((int)DAT_0043757d,&local_a);
    iVar2 = (int)local_a * (int)DAT_0043757c + DAT_00437574;
    iVar1 = (int)local_9 * (int)DAT_0043757c + _DAT_00437578;
    if ((((-1 < iVar2) && (-1 < iVar1)) && (iVar2 < 0x30)) && (iVar1 < 0x30)) {
      DAT_00437574 = iVar2;
      _DAT_00437578 = iVar1;
      *(int *)(DAT_0043453c + 0x14 + (iVar2 * 0x30 + iVar1) * 0x18) = DAT_00437570;
      return;
    }
    DAT_00437570 = 0;
  }
  return;
}


