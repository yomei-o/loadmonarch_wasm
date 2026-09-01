/* 0040e640 */

void __fastcall FUN_0040e640(int param_1)

{
  HDC hdc;
  HPALETTE hPal;
  
  hdc = CreateDCA(s_DISPLAY_004326e8,(LPCSTR)0x0,(LPCSTR)0x0,(DEVMODEA *)0x0);
  if (hdc != (HDC)0x0) {
    hPal = SelectPalette(hdc,*(HPALETTE *)(param_1 + 4),0);
    RealizePalette(hdc);
    SelectPalette(hdc,hPal,1);
    DeleteDC(hdc);
  }
  return;
}


