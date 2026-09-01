/* 004084e0 */

void __fastcall FUN_004084e0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  DAT_00435b1c = 1;
  piVar1 = (int *)FUN_0040a0c0(60000);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea61);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea63);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea62);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))();
  }
  iVar2 = 0;
  do {
    piVar1 = (int *)FUN_0040a0c0(iVar2 + 0xea66);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x14))();
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  FUN_00408aa0(param_1);
  FUN_0040a210();
  FUN_00408e40();
  return;
}


