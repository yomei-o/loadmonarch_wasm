/* 004256d0 */

void __fastcall FUN_004256d0(int param_1)

{
  HDC hdc;
  HPALETTE hPal;
  HGDIOBJ h;
  tagRECT local_50;
  tagPAINTSTRUCT local_40;
  
  hdc = BeginPaint(*(HWND *)(param_1 + 8),&local_40);
  if (hdc != (HDC)0x0) {
    hPal = SelectPalette(local_40.hdc,DAT_004365f4,0);
    SelectPalette(*(HDC *)(param_1 + 0x254),DAT_004365f4,0);
    RealizePalette(hdc);
    h = SelectObject(hdc,*(HGDIOBJ *)(DAT_004344e4 + 0x3a4));
    GetClientRect(*(HWND *)(param_1 + 8),&local_50);
    StretchBlt(local_40.hdc,0,0,local_50.right,local_50.bottom,*(HDC *)(param_1 + 0x254),
               *(int *)(param_1 + 0x260),*(int *)(param_1 + 0x264),local_50.right,local_50.bottom,
               0xcc0020);
    SelectObject(hdc,h);
    SelectPalette(hdc,hPal,1);
    EndPaint(*(HWND *)(param_1 + 8),&local_40);
  }
  return;
}


