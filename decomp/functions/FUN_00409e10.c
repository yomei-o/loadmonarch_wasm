/* 00409e10 */

void FUN_00409e10(void)

{
  int *piVar1;
  
  if (DAT_004344e8 != (int *)0x0) {
    (**(code **)(*DAT_004344e8 + 0x10))();
  }
  if (DAT_004344f0 != (int *)0x0) {
    (**(code **)(*DAT_004344f0 + 0x10))();
  }
  if (DAT_004344ec != (int *)0x0) {
    (**(code **)(*DAT_004344ec + 0x10))();
  }
  if (DAT_004344f4 != (int *)0x0) {
    (**(code **)(*DAT_004344f4 + 0x10))();
  }
  piVar1 = &DAT_004344f8;
  do {
    if ((int *)*piVar1 != (int *)0x0) {
      (**(code **)(*(int *)*piVar1 + 0x10))();
    }
    piVar1 = piVar1 + 1;
  } while (piVar1 < &DAT_00434508);
  return;
}


