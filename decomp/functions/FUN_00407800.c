/* 00407800 */

undefined4 FUN_00407800(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (DAT_004376b5 != '\0') {
    iVar1 = FUN_00405860();
    if (iVar1 == 1) {
      uVar2 = DAT_00436a00;
    }
    if (DAT_004376b5 != '\0') {
      iVar1 = FUN_00405900(0x432268);
      if (iVar1 != 0) {
        FUN_00409510();
        return 1;
      }
      iVar1 = FUN_00405de0(uVar2);
      if (iVar1 != 0) {
        return 1;
      }
      FUN_00409370(s_Could_not_load_mapfile__00432250,0);
      return 0;
    }
  }
  iVar1 = FUN_00405de0(uVar2);
  if (iVar1 != 0) {
    return 1;
  }
  FUN_00409370(s_Could_not_load_mapfile__00432250,0);
  return 0;
}


