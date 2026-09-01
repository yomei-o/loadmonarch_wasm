/* 00429f30 */

void FUN_00429f30(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  uStack_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_00430a08;
  puStack_10 = &LAB_0042b3d8;
  *unaff_FS_OFFSET = &uStack_14;
  if (DAT_00434794 != (code *)0x0) {
    local_8 = 1;
    (*DAT_00434794)();
  }
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _abort();
}


