/* 0041f6c0 */

void FUN_0041f6c0(void)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  uVar1 = 0;
  DAT_004365d4 = 0xffffffff;
  if (-1 < DAT_00436a00) {
    puVar3 = &DAT_00436a0c;
    iVar2 = DAT_00436a00 + 1;
    do {
      if (uVar1 < *puVar3) {
        uVar1 = *puVar3;
      }
      puVar3 = puVar3 + 0xe;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if (uVar1 < 100000) {
    if (uVar1 < 10000) {
      uVar1 = uVar1 / 1000;
    }
    else {
      uVar1 = uVar1 / 10000 + 9;
    }
  }
  else {
    uVar1 = 0x13;
  }
  if (DAT_004376cc - DAT_0043450c == 1) {
    DAT_00436a00 = DAT_004376cc + -1;
    DAT_00436a04 = uVar1;
    FUN_00409570();
  }
  else {
    if (((int)DAT_00436a04 < (int)uVar1) && (uVar1 != 0)) {
      DAT_00436a04 = uVar1;
      FUN_004095d0(0x72,0,*(HWND *)(DAT_004344e4 + 8));
    }
    if (DAT_0043450c - DAT_00436a00 == -1) {
      FUN_004067c0();
      return;
    }
  }
  return;
}


