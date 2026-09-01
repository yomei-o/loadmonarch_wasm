/* 004146f0 */

void __fastcall FUN_004146f0(void *param_1)

{
  int iVar1;
  HWND pHVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  
  *(undefined4 *)((int)param_1 + 0x238) = 0;
  *(undefined4 *)((int)param_1 + 0x254) = 0;
  iVar1 = 0x19;
  puVar3 = (undefined1 *)((int)param_1 + 0x9130);
  do {
    *puVar3 = 0x14;
    iVar1 = iVar1 + -1;
    puVar3[0x10] = 0;
    puVar3 = puVar3 + 0x18;
  } while (iVar1 != 0);
  iVar1 = 0x14;
  puVar4 = (undefined4 *)((int)param_1 + 0x6678);
  do {
    *puVar4 = 0x1e;
    iVar1 = iVar1 + -1;
    puVar4[-4] = 1000;
    *(undefined1 *)(puVar4 + -3) = 6;
    *(undefined1 *)(puVar4 + 0x82) = 0xff;
    *(undefined1 *)(puVar4 + -2) = 0;
    puVar4 = puVar4 + 0x89;
  } while (iVar1 != 0);
  SendDlgItemMessageA(*(HWND *)((int)param_1 + 4),0x462,0x14e,*(WPARAM *)((int)param_1 + 0x23c),0);
  puVar4 = *(undefined4 **)((int)param_1 + 0x22c);
  for (iVar1 = 0x1900; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = 0x70707070;
    puVar4 = puVar4 + 1;
  }
  if (*(int *)((int)param_1 + 0x23c) == 0) {
    FUN_0040ed80(param_1,0x461,1);
    FUN_0040ed80(param_1,0x460,0);
    pHVar2 = GetDlgItem(*(HWND *)((int)param_1 + 4),0x461);
    if (pHVar2 != (HWND)0x0) {
      SetFocus(pHVar2);
    }
  }
  else if (*(int *)((int)param_1 + 0x23c) == 0x11) {
    FUN_0040ed80(param_1,0x461,0);
    FUN_0040ed80(param_1,0x460,1);
    pHVar2 = GetDlgItem(*(HWND *)((int)param_1 + 4),0x460);
    if (pHVar2 != (HWND)0x0) {
      SetFocus(pHVar2);
    }
  }
  else {
    FUN_0040ed80(param_1,0x461,1);
    FUN_0040ed80(param_1,0x460,1);
  }
  InvalidateRect(*(HWND *)((int)param_1 + 4),(RECT *)0x0,0);
  UpdateWindow(*(HWND *)((int)param_1 + 4));
  return;
}


