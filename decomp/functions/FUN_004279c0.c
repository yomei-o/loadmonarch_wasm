/* 004279c0 */

bool __fastcall FUN_004279c0(undefined4 *param_1)

{
  HWND pHVar1;
  
  pHVar1 = CreateWindowExA(0x80,s_tooltips_class32_004345c4,(LPCSTR)0x0,0x80000001,-0x80000000,
                           -0x80000000,-0x80000000,-0x80000000,(HWND)param_1[1],(HMENU)0x0,
                           DAT_004344d0,(LPVOID)0x0);
  *param_1 = pHVar1;
  return (bool)('\x01' - (pHVar1 == (HWND)0x0));
}


