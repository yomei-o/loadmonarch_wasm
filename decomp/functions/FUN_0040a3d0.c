/* 0040a3d0 */

void FUN_0040a3d0(void)

{
  HWND hWnd;
  LONG LVar1;
  int iVar2;
  
  hWnd = *(HWND *)(DAT_004344e4 + 8);
  if (DAT_004376a2 != '\0') {
    SendMessageA(hWnd,0x111,0xea65,0);
  }
  SendMessageA(hWnd,0x111,60000,0);
  if (DAT_004376a4 != '\0') {
    SendMessageA(hWnd,0x111,0xea61,0);
  }
  if (DAT_004376a5 != '\0') {
    SendMessageA(hWnd,0x111,0xea63,0);
  }
  if (DAT_004376a6 != '\0') {
    SendMessageA(hWnd,0x111,0xea62,0);
  }
  iVar2 = 0;
  do {
    if ((&DAT_004376a7)[iVar2] != '\0') {
      SendMessageA(hWnd,0x111,iVar2 + 0xea66,0);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  if ((DAT_004376a2 != '\0') && (LVar1 = FUN_0040a0c0(0xea65), LVar1 != 0)) {
    BringWindowToTop(*(HWND *)(LVar1 + 8));
  }
  FUN_0040a210();
  return;
}


