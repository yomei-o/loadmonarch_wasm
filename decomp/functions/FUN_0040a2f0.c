/* 0040a2f0 */

void FUN_0040a2f0(void)

{
  WPARAM wParam;
  undefined4 *unaff_FS_OFFSET;
  tagPOINT local_1c;
  HMENU local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040a3ba;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e2f0(&local_14);
  local_8 = 0;
  FUN_0040b180(&local_14);
  FUN_0040e400(&local_14);
  FUN_0040e330(&local_14,0,0x9cc5,0);
  GetCursorPos(&local_1c);
  wParam = TrackPopupMenu(local_14,0x102,local_1c.x,local_1c.y,0,*(HWND *)(DAT_004344e4 + 8),
                          (RECT *)0x0);
  if (wParam == 0) {
    local_8 = 0xffffffff;
    FUN_0040a3c4();
    *unaff_FS_OFFSET = local_10;
    return;
  }
  SendMessageA(*(HWND *)(DAT_004344e4 + 8),0x111,wParam,0);
  local_8 = 0xffffffff;
  FUN_0040a3c4();
  *unaff_FS_OFFSET = local_10;
  return;
}


