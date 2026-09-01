/* 00425180 */

void __fastcall FUN_00425180(undefined4 *param_1)

{
  HMENU hMenu;
  
  *param_1 = &PTR_FUN_00430830;
  param_1[2] = 0;
  if ((HDC)param_1[0x95] != (HDC)0x0) {
    DeleteDC((HDC)param_1[0x95]);
    param_1[0x95] = 0;
  }
  if ((HGDIOBJ)param_1[0x96] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)param_1[0x96]);
    param_1[0x96] = 0;
  }
  hMenu = GetMenu((HWND)param_1[0x94]);
  if (hMenu != (HMENU)0x0) {
    DeleteMenu(hMenu,param_1[1] + 1000,0);
  }
  return;
}


