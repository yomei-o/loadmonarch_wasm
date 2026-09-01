/* 00408b30 */

void FUN_00408b30(int param_1)

{
  LONG LVar1;
  
  LVar1 = FUN_0040a0c0(param_1);
  if (LVar1 != 0) {
    BringWindowToTop(*(HWND *)(LVar1 + 8));
  }
  return;
}


