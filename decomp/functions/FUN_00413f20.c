/* 00413f20 */

void __fastcall FUN_00413f20(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00413f6f;
  *param_1 = &PTR_FUN_00430550;
  *unaff_FS_OFFSET = &local_10;
  DAT_004376a1 = *(undefined1 *)(param_1 + 0x24e5);
  local_8 = 0xffffffff;
  FUN_00413f79();
  *unaff_FS_OFFSET = local_10;
  return;
}


