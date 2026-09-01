/* 0041f900 */

void __fastcall FUN_0041f900(undefined2 *param_1)

{
  HCURSOR hCursor;
  
  hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  SetCursor(hCursor);
  if (*(int *)(param_1 + 0x84) != 0) {
    FUN_0041fa40(param_1);
  }
  return;
}


