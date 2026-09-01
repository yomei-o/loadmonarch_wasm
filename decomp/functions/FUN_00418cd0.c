/* 00418cd0 */

undefined4 * __thiscall FUN_00418cd0(void *this,WPARAM param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00418d43;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  iVar1 = 0;
  *(undefined ***)this = &PTR_FUN_00430610;
  puVar2 = (undefined4 *)((int)this + 0x22994);
  do {
    *puVar2 = 0xffffffff;
    iVar1 = iVar1 + 1;
    puVar2[0x200] = 0xffffffff;
    puVar2 = puVar2 + 2;
  } while (iVar1 < 0x100);
  *unaff_FS_OFFSET = local_10;
  return this;
}


