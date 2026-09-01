/* 00426760 */

void __fastcall FUN_00426760(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_004267a7;
  *param_1 = &PTR_FUN_004308a0;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  DAT_004344f0 = 0;
  FUN_004267b1();
  *unaff_FS_OFFSET = local_10;
  return;
}


