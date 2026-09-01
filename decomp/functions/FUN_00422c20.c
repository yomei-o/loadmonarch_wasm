/* 00422c20 */

void __fastcall FUN_00422c20(int *param_1)

{
  tagPOINT local_24;
  tagMSG local_1c;
  
  ClipCursor((RECT *)0x0);
  if (param_1[0x5fa] != 0) {
    PeekMessageA(&local_1c,(HWND)param_1[2],0x200,0x209,1);
    param_1[0x5fa] = 0;
    return;
  }
  if (((DAT_004365dc == 1) || (DAT_00434524 == 0)) || (DAT_004365dc == 0)) {
    switch(DAT_004365dc) {
    case 0:
      DAT_004365dc = 3;
      GetCursorPos(&local_24);
      FUN_0040a980(&local_24.x);
      break;
    case 1:
      FUN_00409f90();
      break;
    case 2:
      FUN_00423480((int)param_1);
      DAT_004365dc = 0;
      break;
    case 3:
      DAT_004365dc = 1;
      (**(code **)(*param_1 + 100))();
      break;
    case 4:
      FUN_00409f90();
    case 5:
      DAT_004365dc = 1;
    }
    FUN_00424770(param_1);
  }
  return;
}


