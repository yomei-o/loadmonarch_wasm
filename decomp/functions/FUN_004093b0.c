/* 004093b0 */

void FUN_004093b0(void)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_0040a0c0(0xea65);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))();
  }
  piVar1 = (int *)FUN_0040a0c0(60000);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea61);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea63);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea62);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea66);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea67);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea68);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea69);
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00409485. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0x3c))();
    return;
  }
  return;
}


