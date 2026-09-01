/* 0040bc20 */

undefined4 FUN_0040bc20(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00437690 * 0x18 + DAT_0043453c;
  if (3 < (byte)(*(char *)(iVar2 + 0x10) - 1U)) {
    return 3;
  }
  iVar1 = *(int *)(iVar2 + 0xc) - (*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 1);
  if (iVar1 < 1) {
    *(undefined1 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18) = 100;
    FUN_0041acc0(DAT_0043644c,DAT_00436450);
    return 1;
  }
  *(int *)(iVar2 + 0xc) = iVar1;
  return 4;
}


