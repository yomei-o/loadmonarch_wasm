/* 0041a1b0 */

void __fastcall FUN_0041a1b0(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  tagRECT local_10;
  
  uVar3 = param_1[5] & 0xffff;
  uVar1 = (uint)param_1[5] >> 0x10;
  iVar2 = GetSystemMetrics(7);
  if (uVar3 < 0x18) {
LAB_0041a365:
    if (((0x60 < uVar3) && (uVar3 < 0x70)) && ((0x28 < uVar1 && (uVar1 < 0x38)))) {
      GetWindowRect((HWND)param_1[2],&local_10);
      local_10.right = local_10.left + 0x70;
      local_10.bottom = local_10.top + 0x38;
      local_10.left = local_10.left + 0x66;
      local_10.top = local_10.top + 0x2e;
      ClipCursor(&local_10);
      return;
    }
    FUN_00425970((int)param_1);
    return;
  }
  if (((iVar2 + 0x90 < (int)uVar3) || (uVar1 < 0x10)) || (0x20 < uVar1)) {
    if (((uVar3 < 0x18) || (iVar2 + 0x90 < (int)uVar3)) || ((uVar1 < 0x90 || (0xa0 < uVar1))))
    goto LAB_0041a365;
    GetWindowRect((HWND)param_1[2],&local_10);
    local_10.left = local_10.left + 0x1c;
    local_10.right = local_10.right + -0x20;
    local_10.bottom = local_10.top + 0xa0;
    local_10.top = local_10.top + 0x98;
    ClipCursor(&local_10);
    if (uVar3 < 0x18) {
      uVar3 = 0x18;
    }
    if (0xdc < uVar3) {
      uVar3 = 0xdc;
    }
    iVar2 = uVar3 - 0x18;
    if (0x7c < iVar2) {
      iVar2 = 0x7c;
    }
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    DAT_00437698 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
    if (0x1e < DAT_00437698) {
      DAT_00437698 = 0x1e;
    }
  }
  else {
    GetWindowRect((HWND)param_1[2],&local_10);
    local_10.left = local_10.left + 0x1c;
    local_10.right = local_10.right + -0x20;
    local_10.bottom = local_10.top + 0x20;
    local_10.top = local_10.top + 0x18;
    ClipCursor(&local_10);
    if (uVar3 < 0x18) {
      uVar3 = 0x18;
    }
    if (0xdc < uVar3) {
      uVar3 = 0xdc;
    }
    iVar2 = uVar3 - 0x18;
    if (0x7c < iVar2) {
      iVar2 = 0x7c;
    }
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    iVar2 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
    if (0x1e < iVar2) {
      iVar2 = 0x1e;
    }
    *(char *)(DAT_00434534 + 0x1c + (uint)DAT_004365cd * 0x38) = (char)iVar2;
    DAT_0043769c = 0;
    *(undefined1 *)(param_1 + 0xe9) = 1;
  }
  (**(code **)(*param_1 + 0x18))();
  InvalidateRect((HWND)param_1[2],(RECT *)0x0,0);
  UpdateWindow((HWND)param_1[2]);
  return;
}


