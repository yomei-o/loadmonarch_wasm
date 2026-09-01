/* 00425c50 */

int __fastcall FUN_00425c50(int *param_1)

{
  LPVOID pvVar1;
  
  if ((HGLOBAL)param_1[1] == (HGLOBAL)0x0) {
    return 0;
  }
  if (*param_1 == 0) {
    pvVar1 = GlobalLock((HGLOBAL)param_1[1]);
    param_1[2] = (int)pvVar1;
    if (pvVar1 != (LPVOID)0x0) {
      *param_1 = 1;
    }
  }
  return param_1[2];
}


