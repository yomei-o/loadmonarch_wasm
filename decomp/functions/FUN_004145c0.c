/* 004145c0 */

void __fastcall FUN_004145c0(int param_1)

{
  HWND hWnd;
  HDC hdc;
  HGDIOBJ h;
  int mode;
  COLORREF color;
  tagRECT local_10;
  
  hWnd = GetDlgItem(*(HWND *)(param_1 + 4),0x463);
  if (hWnd != (HWND)0x0) {
    hdc = GetDC(hWnd);
    if (hdc != (HDC)0x0) {
      GetClientRect(hWnd,&local_10);
      h = SelectObject(hdc,*(HGDIOBJ *)(DAT_004344e4 + 0x3a4));
      mode = SetBkMode(hdc,1);
      color = SetTextColor(hdc,0x10000);
      SetWindowTextA(hWnd,(&PTR_s_Lord_Monarch_is_a_game_where_you_004334d0)
                          [*(int *)(param_1 + 0x23c)]);
      SetTextColor(hdc,color);
      SetBkMode(hdc,mode);
      SelectObject(hdc,h);
      ReleaseDC(hWnd,hdc);
    }
  }
  return;
}


