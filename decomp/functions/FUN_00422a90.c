/* 00422a90 */

void __fastcall FUN_00422a90(int *param_1)

{
  int iVar1;
  tagPOINT local_8;
  
  if (DAT_00434524 != 0) {
    return;
  }
  if (DAT_004365dc == 1) {
    iVar1 = FUN_00423760(param_1,(uint)*(byte *)(param_1 + 0xf0),
                         (uint)*(byte *)((int)param_1 + 0x3c1));
    if (iVar1 == 1) {
      GetCursorPos(&local_8);
      FUN_00424770(param_1);
      if (DAT_00434440 < 0x40) {
        FUN_00423cc0(param_1,0,0);
      }
      else {
        iVar1 = FUN_00423940(param_1,&local_8.x);
        if ((iVar1 == 0) && (DAT_004365dc == 3)) {
          DAT_004365dc = 5;
        }
      }
    }
    else {
      DAT_004321c0 = 2;
      DAT_004321b8 = 0;
      FUN_0040a1c0(0x15f95);
      FUN_00424770(param_1);
    }
  }
  else {
    if (DAT_004365dc == 2) {
      iVar1 = FUN_004235a0((int)param_1);
      if (iVar1 != 1) {
        DAT_004365dc = 0;
        goto LAB_00422b8d;
      }
      FUN_0040a1c0(90000);
    }
    else if (DAT_004365dc != 5) goto LAB_00422b8d;
    DAT_004365dc = 1;
  }
LAB_00422b8d:
  FUN_00424770(param_1);
  return;
}


