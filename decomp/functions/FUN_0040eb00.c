/* 0040eb00 */

void __fastcall FUN_0040eb00(int *param_1)

{
  HDC hdc;
  HPALETTE hPal;
  tagPAINTSTRUCT local_40;
  
  hdc = BeginPaint((HWND)param_1[1],&local_40);
  if (hdc != (HDC)0x0) {
    hPal = SelectPalette(hdc,DAT_004365f4,0);
    SelectPalette((HDC)param_1[0x89],DAT_004365f4,0);
    RealizePalette(hdc);
    (**(code **)(*param_1 + 0x1c))(hdc);
    SelectPalette(hdc,hPal,1);
    EndPaint((HWND)param_1[1],(PAINTSTRUCT *)&stack0xffffffbc);
  }
  return;
}


