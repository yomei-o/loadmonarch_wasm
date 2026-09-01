/* 00424770 */

void __fastcall FUN_00424770(int *param_1)

{
  LONG LVar1;
  
  (**(code **)(*param_1 + 100))();
  LVar1 = FUN_0040a0c0(0xea61);
  if (LVar1 != 0) {
    InvalidateRect(*(HWND *)(LVar1 + 8),(RECT *)0x0,0);
    UpdateWindow(*(HWND *)(LVar1 + 8));
  }
  return;
}


