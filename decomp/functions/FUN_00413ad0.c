/* 00413ad0 */

undefined4 * __thiscall FUN_00413ad0(void *this,WPARAM param_1)

{
  uint uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00413b4a;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  *(undefined ***)this = &PTR_LAB_00430510;
  *(uint *)((int)this + 0x234) = DAT_004365e4 / 3;
  uVar1 = DAT_004365e4 % 3;
  *unaff_FS_OFFSET = local_10;
  *(uint *)((int)this + 0x238) = uVar1;
  return this;
}


