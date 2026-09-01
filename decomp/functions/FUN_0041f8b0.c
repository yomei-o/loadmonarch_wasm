/* 0041f8b0 */

int __fastcall FUN_0041f8b0(int param_1)

{
  HCURSOR hCursor;
  
  hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
  SetCursor(hCursor);
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  wsprintfA((LPSTR)(param_1 + 0x110),&DAT_00433ff4);
  return param_1;
}


