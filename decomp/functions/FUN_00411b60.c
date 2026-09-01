/* 00411b60 */

void __fastcall FUN_00411b60(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00411b9d;
  *param_1 = &PTR_FUN_00430410;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_00411ba7();
  *unaff_FS_OFFSET = local_10;
  return;
}


