/* 00423140 */

void __fastcall FUN_00423140(int *param_1)

{
  int iVar1;
  int iVar2;
  tagPOINT local_18;
  tagRECT local_10;
  
  GetCursorPos(&local_18);
  ScreenToClient((HWND)param_1[2],&local_18);
  iVar2 = param_1[0xe6];
  param_1[0xe7] = ((local_18.x + param_1[0x98]) / iVar2) * iVar2 - param_1[0x98];
  param_1[0xe8] = ((local_18.y + param_1[0x99]) / iVar2) * iVar2 - param_1[0x99];
  param_1[0xe9] = -1;
  param_1[0xea] = -1;
  GetWindowRect((HWND)param_1[2],&local_10);
  iVar2 = param_1[7];
  local_10.top = local_10.top + iVar2;
  local_10.left = local_10.left + param_1[6];
  local_10.right = local_10.right - param_1[6];
  iVar1 = GetSystemMetrics(0x33);
  local_10.bottom = local_10.bottom + (iVar1 - iVar2);
  ClipCursor(&local_10);
  iVar2 = (uint)*(byte *)(param_1 + 0xf0) * 0x30 + (uint)*(byte *)((int)param_1 + 0x3c1);
  *(undefined1 *)((int)param_1 + iVar2 * 2 + 0x3c6) = 0xff;
  *(undefined1 *)((int)param_1 + iVar2 * 2 + 0x3c7) = 1;
  FUN_00424770(param_1);
  return;
}


