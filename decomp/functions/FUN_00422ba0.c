/* 00422ba0 */

void __fastcall FUN_00422ba0(int param_1)

{
  tagRECT local_20;
  tagRECT local_10;
  
  GetWindowRect(*(HWND *)(param_1 + 8),&local_20);
  local_20.top = local_20.top + *(int *)(param_1 + 0x1c);
  local_20.left = local_20.left + *(int *)(param_1 + 0x18);
  GetClientRect(*(HWND *)(param_1 + 8),&local_10);
  local_20.right = local_10.right + local_20.left;
  local_20.bottom = local_10.bottom + local_20.top;
  ClipCursor(&local_20);
  *(undefined4 *)(param_1 + 0x17f4) = 6;
  *(uint *)(param_1 + 0x17ec) = *(uint *)(param_1 + 0x14) & 0xffff;
  *(uint *)(param_1 + 0x17f0) = *(uint *)(param_1 + 0x14) >> 0x10;
  return;
}


