/* 00421910 */

undefined4 FUN_00421910(void)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  byte bVar4;
  
  iVar3 = DAT_00437690 * 0x18 + DAT_0043453c;
  bVar4 = *(char *)(iVar3 + 0x10) - 8;
  if ((bVar4 < 4) && (bVar4 == DAT_00437580)) {
    piVar1 = (int *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
    *piVar1 = *piVar1 + *(int *)(iVar3 + 0xc);
    puVar2 = (uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
    if (100000 < *puVar2) {
      *puVar2 = 100000;
    }
    *(undefined1 *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) = 0;
    *(undefined4 *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18) = 100;
    return 1;
  }
  return 0;
}


