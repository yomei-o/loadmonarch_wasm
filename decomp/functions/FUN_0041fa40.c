/* 0041fa40 */

undefined4 __fastcall FUN_0041fa40(undefined2 *param_1)

{
  BOOL BVar1;
  
  if (*(HANDLE *)(param_1 + 0x84) == (HANDLE)0xffffffff) {
    return 1;
  }
  BVar1 = CloseHandle(*(HANDLE *)(param_1 + 0x84));
  if (BVar1 == 0) {
    FUN_0041fc90(param_1);
    return 0;
  }
  *(undefined4 *)(param_1 + 0x84) = 0xffffffff;
  return 1;
}


