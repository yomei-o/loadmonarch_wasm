/* 00422870 */

void __fastcall FUN_00422870(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_004228b7;
  *param_1 = &PTR_FUN_004307c0;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  DAT_004344e8 = 0;
  FUN_004228c1();
  *unaff_FS_OFFSET = local_10;
  return;
}


