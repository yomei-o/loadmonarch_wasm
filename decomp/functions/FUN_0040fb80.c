/* 0040fb80 */

undefined4 * __thiscall FUN_0040fb80(void *this,WPARAM param_1,undefined4 param_2)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040fc05;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  *(undefined ***)this = &PTR_FUN_004303d0;
  *(undefined4 *)((int)this + 0x23c) = param_2;
  *(undefined4 *)((int)this + 0x238) = 0;
  *(undefined4 *)((int)this + 0x5838) = 0;
  *(undefined4 *)((int)this + 0x244) = 0;
  *(undefined4 *)((int)this + 0x248) = 0;
  *(undefined4 *)((int)this + 0x24c) = 0;
  *(undefined4 *)((int)this + 0x250) = 0;
  *(undefined4 *)((int)this + 0x254) = 0;
  *unaff_FS_OFFSET = local_10;
  return this;
}


