/* 004273b0 */

void FUN_004273b0(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 0x18;
    *(undefined1 *)(DAT_0043453c + -8 + iVar1) = 0x30;
    *(undefined4 *)(DAT_0043453c + -0xc + iVar1) = 100;
  } while (iVar1 < 0xd800);
  DAT_004365a0 = 0xffffffff;
  return;
}


