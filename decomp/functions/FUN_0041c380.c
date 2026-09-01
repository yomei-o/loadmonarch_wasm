/* 0041c380 */

void FUN_0041c380(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  LONG LVar1;
  
  if (param_2 == 0x201) {
    LVar1 = FUN_0040a0c0(0xea65);
    if (LVar1 != 0) {
      BringWindowToTop(*(HWND *)(LVar1 + 8));
    }
  }
  else if (param_2 == 0x203) {
    FUN_0041c3e0();
  }
  CallWindowProcA(DAT_00433fa4,param_1,param_2,param_3,param_4);
  return;
}


