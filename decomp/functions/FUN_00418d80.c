/* 00418d80 */

void __fastcall FUN_00418d80(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00418e1a;
  *param_1 = &PTR_FUN_00430610;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0;
  DAT_0043769f = *(char *)((int)param_1 + 0x23995);
  DAT_0043769e = *(char *)(param_1 + 0x8e65);
  if (DAT_0043769e == '\0') {
    FUN_0040ccf0(0);
  }
  else if (param_1[0x8961] != -1) {
    FUN_0040cd20(&DAT_00435db0,param_1[0x8961],0);
  }
  if (DAT_0043769f == '\0') {
    FUN_0040ccf0(1);
  }
  local_8 = 0xffffffff;
  FUN_00418e24();
  *unaff_FS_OFFSET = local_10;
  return;
}


