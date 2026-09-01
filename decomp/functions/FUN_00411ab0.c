/* 00411ab0 */

undefined4 * __thiscall FUN_00411ab0(void *this,WPARAM param_1,uint param_2)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00411b22;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  *(undefined ***)this = &PTR_FUN_00430410;
  *(undefined4 *)((int)this + 0x23c) = 0;
  *unaff_FS_OFFSET = local_10;
  *(uint *)((int)this + 0x234) = param_2 >> 0x10;
  *(uint *)((int)this + 0x238) = param_2 & 0xffff;
  return this;
}


