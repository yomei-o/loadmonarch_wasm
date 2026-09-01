/* 0041fbe0 */

uint __fastcall FUN_0041fbe0(int param_1)

{
  DWORD DVar1;
  
  if (*(HANDLE *)(param_1 + 0x108) == (HANDLE)0x0) {
    return 0;
  }
  DVar1 = GetFileSize(*(HANDLE *)(param_1 + 0x108),(LPDWORD)0x0);
  return (DVar1 == 0xffffffff) - 1 & DVar1;
}


