/* 0040f260 */

undefined4 * __thiscall FUN_0040f260(void *this,WPARAM param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040f2d4;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  local_8 = 0;
  FUN_0041f8b0((int)this + 0x238);
  *(undefined ***)this = &PTR_LAB_00430310;
  *unaff_FS_OFFSET = local_10;
  return this;
}


