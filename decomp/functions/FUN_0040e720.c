/* 0040e720 */

void __fastcall FUN_0040e720(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00430250;
  if (param_1[0x8c] != 0) {
    KillTimer((HWND)param_1[1],param_1[0x8c]);
    param_1[0x8c] = 0;
  }
  if ((HDC)param_1[0x89] != (HDC)0x0) {
    DeleteDC((HDC)param_1[0x89]);
  }
  if ((HGDIOBJ)param_1[0x8a] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)param_1[0x8a]);
  }
  return;
}


