/* 0041c0c0 */

void __fastcall FUN_0041c0c0(int param_1)

{
  BOOL BVar1;
  
  BVar1 = IsWindow(*(HWND *)(param_1 + 0x28));
  if (BVar1 != 0) {
    DestroyWindow(*(HWND *)(param_1 + 0x28));
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (*(LPVOID *)(param_1 + 0x18) != (LPVOID)0x0) {
    FUN_00427f80(*(LPVOID *)(param_1 + 0x18));
  }
  if (*(LPVOID *)(param_1 + 0x1c) != (LPVOID)0x0) {
    FUN_00427f80(*(LPVOID *)(param_1 + 0x1c));
  }
  return;
}


