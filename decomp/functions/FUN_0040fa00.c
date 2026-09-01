/* 0040fa00 */

undefined4 * __thiscall FUN_0040fa00(void *this,WPARAM param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040fa57;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040f260(this,param_1);
  *(undefined ***)this = &PTR_LAB_00430390;
  *unaff_FS_OFFSET = local_10;
  return this;
}


