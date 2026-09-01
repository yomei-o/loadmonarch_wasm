/* 0040ef20 */

undefined4 * __thiscall FUN_0040ef20(void *this,WPARAM param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040ef7b;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  *(undefined ***)this = &PTR_FUN_004302d0;
  *(undefined4 *)((int)this + 0x234) = 0;
  *unaff_FS_OFFSET = local_10;
  return this;
}


