/* 0040f5f0 */

void FUN_0040f5f0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_0040f642;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0;
  FUN_0040f634();
  local_8 = 0xffffffff;
  FUN_0040f64c();
  *unaff_FS_OFFSET = local_10;
  return;
}


