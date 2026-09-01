/* 0041dec0 */

void FUN_0041dec0(void)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = (uint *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18);
  uVar3 = *puVar2;
  if (uVar3 < 0xf5) {
    *puVar2 = uVar3 + 10;
    return;
  }
  *puVar2 = uVar3 - 0xf5;
  if (0x3f < DAT_0043756c) {
    uVar3 = FUN_0041cdc0();
    if (uVar3 < 0x40) {
      iVar1 = uVar3 * 0x224;
      *(undefined1 *)(DAT_00434538 + iVar1) = (undefined1)DAT_0043644c;
      *(undefined1 *)(DAT_00434538 + 1 + iVar1) = (undefined1)DAT_00436450;
      ((undefined2 *)(DAT_00434538 + iVar1))[1] = *(undefined2 *)(DAT_00434538 + iVar1);
      *(undefined1 *)(DAT_00434538 + 0x10 + iVar1) = 0;
      *(undefined1 *)(DAT_00434538 + 0xc + iVar1) = 6;
      *(undefined1 *)(DAT_00434538 + 0xd + iVar1) = 0xe;
      *(undefined1 *)(DAT_00434538 + 4 + iVar1) = 4;
      *(undefined4 *)(DAT_00434538 + 8 + iVar1) = 200;
      *(undefined4 *)(DAT_00434538 + 0x18 + iVar1) = 0x1f0;
      *(undefined1 *)(DAT_00434538 + 0xf + iVar1) = 10;
      *(char *)(DAT_0043453c + DAT_00437690 * 0x18) = (char)uVar3;
    }
  }
  return;
}


