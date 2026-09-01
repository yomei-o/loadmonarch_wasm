/* 00425c80 */

undefined4 __fastcall FUN_00425c80(int *param_1)

{
  if ((*param_1 != 0) && ((HGLOBAL)param_1[1] != (HGLOBAL)0x0)) {
    GlobalUnlock((HGLOBAL)param_1[1]);
    GetLastError();
    *param_1 = 0;
    return 1;
  }
  return 0;
}


