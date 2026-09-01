/* 00418a10 */

void __fastcall FUN_00418a10(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00418a4d;
  *param_1 = &PTR_FUN_004305d0;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_00418a57();
  *unaff_FS_OFFSET = local_10;
  return;
}


