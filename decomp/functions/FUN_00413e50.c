/* 00413e50 */

undefined4 * __thiscall FUN_00413e50(void *this,WPARAM param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00413ee2;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  *(undefined ***)this = &PTR_FUN_00430550;
  *(undefined1 *)((int)this + 0x9388) = DAT_004365cd;
  *(undefined4 *)((int)this + 0x23c) = 0;
  *(undefined4 *)((int)this + 0x238) = 0;
  *(undefined4 *)((int)this + 0x254) = 0;
  *(undefined4 *)((int)this + 600) = 0;
  *(undefined4 *)((int)this + 0x25c) = 0;
  *(undefined1 *)((int)this + 0x9394) = DAT_004376a1;
  *unaff_FS_OFFSET = local_10;
  DAT_004376a1 = 1;
  return this;
}


