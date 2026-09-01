/* 00425c20 */

void __fastcall FUN_00425c20(int *param_1)

{
  HGLOBAL pvVar1;
  
  if (param_1[1] != 0) {
    if (*param_1 != 0) {
      FUN_00425c80(param_1);
    }
    pvVar1 = GlobalFree((HGLOBAL)param_1[1]);
    param_1[1] = (int)pvVar1;
  }
  return;
}


