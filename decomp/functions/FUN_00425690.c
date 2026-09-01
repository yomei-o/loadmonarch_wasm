/* 00425690 */

void __fastcall FUN_00425690(int *param_1)

{
  if (param_1[0x97] != 0) {
    GdiFlush();
    (**(code **)(*param_1 + 0x18))();
    InvalidateRect((HWND)param_1[2],(RECT *)0x0,0);
    UpdateWindow((HWND)param_1[2]);
  }
  return;
}


