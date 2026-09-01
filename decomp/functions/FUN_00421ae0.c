/* 00421ae0 */

void FUN_00421ae0(void)

{
  int iVar1;
  
  if (DAT_004365cd != DAT_00437580) {
    iVar1 = FUN_00420ef0();
    if (iVar1 == 1) {
      return;
    }
    iVar1 = FUN_00421140();
    if (iVar1 == 1) {
      return;
    }
    if ((1000 < *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224)) &&
       (iVar1 = FUN_00421270(), iVar1 == 1)) {
      return;
    }
    iVar1 = FUN_0041abd0(100);
    if (0x59 < (byte)iVar1) {
      iVar1 = FUN_00421d30();
      if (iVar1 == 1) {
        return;
      }
      iVar1 = FUN_00422040();
      if (iVar1 == 1) {
        return;
      }
      FUN_00422110();
      return;
    }
    if ((0x50 < (byte)iVar1) && (iVar1 = FUN_00421f20(), iVar1 == 1)) {
      return;
    }
  }
  iVar1 = FUN_00421ba0(0x1f0);
  if ((iVar1 != 1) && (iVar1 = FUN_00422040(), iVar1 != 1)) {
    FUN_00422110();
    return;
  }
  return;
}


