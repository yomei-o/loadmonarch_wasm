/* 00412f70 */

void __fastcall FUN_00412f70(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00412fd4;
  *param_1 = &PTR_FUN_00430490;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0;
  if ((param_1[0x91] != -1) && (DAT_004344e8 != (void *)0x0)) {
    FUN_00424620(DAT_004344e8,(ushort *)(param_1 + 0x91));
  }
  local_8 = 0xffffffff;
  FUN_00412fde();
  *unaff_FS_OFFSET = local_10;
  return;
}


