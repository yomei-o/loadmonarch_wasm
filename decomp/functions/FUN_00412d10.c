/* 00412d10 */

void __fastcall FUN_00412d10(int param_1)

{
  LPSTR lParam;
  int iVar1;
  char *pcVar2;
  WPARAM wParam;
  int iVar3;
  
  SendDlgItemMessageA(*(HWND *)(param_1 + 4),0x3ea,0x184,0,0);
  if (0 < DAT_004376cc) {
    lParam = (LPSTR)(param_1 + 0x1c);
    iVar3 = 0;
    do {
      iVar1 = iVar3 + 1;
      pcVar2 = FUN_0041a620(&DAT_004376c8,iVar3);
      FUN_00409490(lParam,&DAT_00432120,pcVar2);
      pcVar2 = FUN_0041a650(&DAT_004376c8,iVar3);
      wsprintfA(lParam,s_Map__3d___s_004339f0,iVar1,pcVar2);
      SendDlgItemMessageA(*(HWND *)(param_1 + 4),0x3ea,0x180,0,(LPARAM)lParam);
      iVar3 = iVar1;
    } while (iVar1 < DAT_004376cc);
  }
  wParam = 0;
  if (DAT_0043450c != 0xffffffff) {
    wParam = DAT_0043450c;
  }
  SendDlgItemMessageA(*(HWND *)(param_1 + 4),0x3ea,0x186,wParam,0);
  return;
}


