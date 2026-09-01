/* 0041bab0 */

undefined4 __fastcall FUN_0041bab0(int param_1)

{
  uint uVar1;
  undefined1 local_10 [16];
  
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < 0x112) {
    if (uVar1 == 0x111) {
      SendMessageA(*(HWND *)(DAT_004344e4 + 8),0x111,*(WPARAM *)(param_1 + 0x10),
                   *(LPARAM *)(param_1 + 0x14));
      return 1;
    }
    if (uVar1 == 0x4e) {
      if (*(int *)(*(int *)(param_1 + 0x14) + 8) != -0x208) {
        return 1;
      }
      FUN_0041c300(*(int *)(param_1 + 0x14));
      return 1;
    }
    return 0;
  }
  if (0x113 < uVar1) {
    if (uVar1 < 0x116) {
      return 1;
    }
    if (uVar1 == 0x232) {
      if (*(int *)(param_1 + 0x394) == 0) {
        return 1;
      }
      SendMessageA(*(HWND *)(*(int *)(param_1 + 0x394) + 0x28),0x427,
                   *(ushort *)(param_1 + 0x39c) | 0x10000,(LPARAM)local_10);
      return 1;
    }
  }
  return 0;
}


