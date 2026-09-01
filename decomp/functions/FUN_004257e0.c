/* 004257e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004257e0(int *param_1)

{
  int iVar1;
  HDC hdc;
  HDC pHVar2;
  HBITMAP pHVar3;
  
  _DAT_00435fdc = param_1[8];
  _DAT_00435fe0 = -param_1[9];
  _DAT_00435fec = 0;
  if ((HDC)param_1[0x95] != (HDC)0x0) {
    DeleteDC((HDC)param_1[0x95]);
    param_1[0x95] = 0;
  }
  if ((HGDIOBJ)param_1[0x96] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)param_1[0x96]);
    param_1[0x96] = 0;
  }
  hdc = GetDC((HWND)param_1[2]);
  pHVar2 = CreateCompatibleDC(hdc);
  param_1[0x95] = (int)pHVar2;
  pHVar3 = CreateDIBSection((HDC)param_1[0x95],(BITMAPINFO *)&DAT_00435fd8,0,
                            (void **)(param_1 + 0x97),(HANDLE)0x0,0);
  param_1[0x96] = (int)pHVar3;
  ReleaseDC((HWND)param_1[2],hdc);
  if (param_1[0x96] == 0) {
    return 0;
  }
  SetBkMode((HDC)param_1[0x95],1);
  SetTextColor((HDC)param_1[0x95],0xffffff);
  SelectPalette((HDC)param_1[0x95],DAT_004365f4,0);
  SelectObject((HDC)param_1[0x95],(HGDIOBJ)param_1[0x96]);
  iVar1 = *param_1;
  (**(code **)(iVar1 + 0x1c))();
  (**(code **)(iVar1 + 0x18))();
  return 1;
}


