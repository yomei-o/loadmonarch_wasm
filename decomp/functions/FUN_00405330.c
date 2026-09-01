/* 00405330 */

void FUN_00405330(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = DAT_0043453c + iVar2;
    *(undefined1 *)(iVar1 + 5) = 1;
    if (*(byte *)(iVar1 + 0x10) < 0x30) {
      *(undefined1 *)(iVar1 + 5) = 0;
    }
    iVar2 = iVar2 + 0x18;
  } while (iVar2 < 0xd800);
  return;
}


