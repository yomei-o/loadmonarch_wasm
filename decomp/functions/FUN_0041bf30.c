/* 0041bf30 */

void __fastcall FUN_0041bf30(int param_1)

{
  LPVOID pvVar1;
  
  pvVar1 = *(LPVOID *)(param_1 + 0x394);
  if (pvVar1 != (LPVOID)0x0) {
    FUN_0041c0c0((int)pvVar1);
    FUN_00427f80(pvVar1);
    *(undefined4 *)(param_1 + 0x394) = 0;
  }
  return;
}


