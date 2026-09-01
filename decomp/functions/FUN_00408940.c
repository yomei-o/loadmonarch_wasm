/* 00408940 */

void __fastcall FUN_00408940(int param_1)

{
  HMENU pHVar1;
  UINT UVar2;
  uint uVar3;
  int iVar4;
  
  pHVar1 = GetMenu(*(HWND *)(param_1 + 8));
  UVar2 = GetMenuState(pHVar1,0x9c73,0);
  if (UVar2 == 0xffffffff) {
    pHVar1 = LoadMenuA(DAT_004344d0,(LPCSTR)0x65);
    if (pHVar1 != (HMENU)0x0) {
      uVar3 = GetWindowLongA(DAT_004344d4,-0x10);
      SetWindowLongA(DAT_004344d4,-0x10,uVar3 | 0xc00000);
      SetMenu(*(HWND *)(param_1 + 8),pHVar1);
      DAT_004376ab = 1;
      FUN_0040a210();
      FUN_00408aa0(param_1);
      DrawMenuBar(*(HWND *)(param_1 + 8));
      InvalidateRect(*(HWND *)(param_1 + 8),(RECT *)0x0,0);
      UpdateWindow(*(HWND *)(param_1 + 8));
      FUN_00408e40();
      iVar4 = GetSystemMetrics(0x20);
      *(int *)(param_1 + 0x18) = iVar4 * 2;
      iVar4 = GetSystemMetrics(0x21);
      *(int *)(param_1 + 0x1c) = iVar4 * 2;
      iVar4 = GetSystemMetrics(4);
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + iVar4;
      return;
    }
  }
  else {
    uVar3 = GetWindowLongA(DAT_004344d4,-0x10);
    SetWindowLongA(DAT_004344d4,-0x10,uVar3 & 0xff3fffff);
    pHVar1 = GetMenu(*(HWND *)(param_1 + 8));
    UVar2 = GetMenuState(pHVar1,0xea61,0);
    if (UVar2 != 0xffffffff) {
      DAT_004376ab = 0;
      DestroyMenu(pHVar1);
      DrawMenuBar(*(HWND *)(param_1 + 8));
      iVar4 = GetSystemMetrics(8);
      *(int *)(param_1 + 0x1c) = iVar4 * 2;
      iVar4 = GetSystemMetrics(7);
      *(int *)(param_1 + 0x18) = iVar4 * 2;
      InvalidateRect(*(HWND *)(param_1 + 8),(RECT *)0x0,0);
      UpdateWindow(*(HWND *)(param_1 + 8));
    }
  }
  return;
}


