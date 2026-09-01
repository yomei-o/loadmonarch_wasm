/* 00419a00 */

void __fastcall FUN_00419a00(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00419a47;
  *param_1 = &PTR_FUN_00430650;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  DAT_004344f4 = 0;
  FUN_00419a51();
  *unaff_FS_OFFSET = local_10;
  return;
}


