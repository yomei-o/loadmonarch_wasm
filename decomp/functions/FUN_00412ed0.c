/* 00412ed0 */

undefined4 * __thiscall FUN_00412ed0(void *this,WPARAM param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00412f38;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  *(undefined ***)this = &PTR_FUN_00430490;
  *(undefined4 *)((int)this + 0x240) = 0;
  *(undefined4 *)((int)this + 0x244) = 0xffffffff;
  *(undefined4 *)((int)this + 0x248) = 0xffffffff;
  *unaff_FS_OFFSET = local_10;
  return this;
}


