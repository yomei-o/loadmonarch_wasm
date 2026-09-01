/* 00429fb0 */

void FUN_00429fb0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  uStack_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_00430a20;
  puStack_10 = &LAB_0042b3d8;
  *unaff_FS_OFFSET = &uStack_14;
  if (PTR_FUN_0043479c != (undefined *)0x0) {
    local_8 = 1;
    (*(code *)PTR_FUN_0043479c)();
  }
  local_8 = 0xffffffff;
  FUN_00429f30();
  return;
}


