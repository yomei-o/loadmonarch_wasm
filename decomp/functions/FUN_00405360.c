/* 00405360 */

void FUN_00405360(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = DAT_0043453c + iVar2;
    iVar2 = iVar2 + 0x18;
    *(undefined1 *)(iVar1 + 4) = *(undefined1 *)(iVar1 + 5);
    *(undefined4 *)(DAT_0043453c + -0x10 + iVar2) = 0x1f0;
  } while (iVar2 < 0xd800);
  return;
}


