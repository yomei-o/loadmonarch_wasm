/* 0041b8a0 */

void __fastcall FUN_0041b8a0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  tagRECT local_24;
  undefined4 *local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_0041b938;
  *param_1 = &PTR_FUN_004306e0;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0;
  local_14 = param_1;
  FUN_0041bf30((int)param_1);
  if (DAT_004344e4 != 0) {
    GetClientRect(*(HWND *)(DAT_004344e4 + 8),&local_24);
  }
  InvalidateRect(*(HWND *)(DAT_004344e4 + 8),(RECT *)0x0,0);
  UpdateWindow(*(HWND *)(DAT_004344e4 + 8));
  local_8 = 0xffffffff;
  DAT_004376b0 = local_14[0xe7];
  FUN_0041b942();
  *unaff_FS_OFFSET = local_10;
  return;
}


