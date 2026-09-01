/* 00413cf0 */

void __fastcall FUN_00413cf0(void *param_1)

{
  int iVar1;
  HWND hWnd;
  
  iVar1 = FUN_0040edd0(param_1,0x465);
  if (iVar1 != -1) {
    *(int *)((int)param_1 + 0x234) = iVar1;
  }
  iVar1 = FUN_0040edd0(param_1,0x466);
  if (iVar1 != -1) {
    *(int *)((int)param_1 + 0x238) = iVar1;
  }
  hWnd = GetDlgItem(*(HWND *)((int)param_1 + 4),0x466);
  SendMessageA(hWnd,0x14b,0,0);
  if ((*(int *)((int)param_1 + 0x234) != 0) && (*(int *)((int)param_1 + 0x234) != 6)) {
    FUN_0040ed80(param_1,0x466,1);
    FUN_0040edb0(param_1,0x466,0x435b97);
    FUN_0040edb0(param_1,0x466,0x435b86);
    wsprintfA((LPSTR)((int)param_1 + 0x1c),s__s_continue_00432470,
              &DAT_00435b86 + (char)(&DAT_00434444)[*(int *)((int)param_1 + 0x234)] * 0x11);
    FUN_0040edb0(param_1,0x466,(LPARAM)((int)param_1 + 0x1c));
    FUN_0040edf0(param_1,0x466,*(WPARAM *)((int)param_1 + 0x238));
    return;
  }
  FUN_0040ed80(param_1,0x466,0);
  return;
}


