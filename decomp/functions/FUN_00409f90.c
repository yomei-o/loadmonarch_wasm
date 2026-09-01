/* 00409f90 */

void FUN_00409f90(void)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  FUN_0040a1c0(0x15f91);
  do {
    iVar3 = DAT_00434538 + iVar4;
    if ((*(byte *)(iVar3 + 0x21c) & 1) != 0) {
      *(undefined1 *)(iVar3 + 0xc) = *(undefined1 *)(iVar3 + 0xe);
      puVar1 = (uint *)(DAT_00434538 + 0x21c + iVar4);
      *puVar1 = *puVar1 & 0xfffffffe;
      *(undefined1 *)(DAT_00434538 + 0x220 + iVar4) = 0xff;
    }
    iVar4 = iVar4 + 0x224;
  } while (iVar4 < 0x8900);
  piVar2 = (int *)FUN_0040a0c0(60000);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 100))();
  }
  DAT_004365dc = 0;
  DAT_004321c8 = 0;
  FUN_00408e40();
  return;
}


