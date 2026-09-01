/* 0041f090 */

void FUN_0041f090(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = 0;
  do {
    uVar1 = *(uint *)(DAT_00434534 + 4 + iVar3);
    if (((uVar1 & 0x40) == 0) && (((uVar1 >> 4 | uVar1) & 1) != 0)) {
      FUN_0041f0d0(uVar2);
    }
    iVar3 = iVar3 + 0x38;
    uVar2 = uVar2 + 1;
  } while (iVar3 < 0xe0);
  return;
}


