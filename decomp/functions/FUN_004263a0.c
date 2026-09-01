/* 004263a0 */

void FUN_004263a0(void)

{
  int *piVar1;
  
  if (DAT_004344f0 != (int *)0x0) {
    (**(code **)(*DAT_004344f0 + 100))();
  }
  if (DAT_004344f4 != (int *)0x0) {
    (**(code **)(*DAT_004344f4 + 100))();
  }
  if (DAT_004344ec != (int *)0x0) {
    (**(code **)(*DAT_004344ec + 100))();
  }
  piVar1 = &DAT_004344f8;
  do {
    if ((int *)*piVar1 != (int *)0x0) {
      (**(code **)(*(int *)*piVar1 + 100))();
    }
    piVar1 = piVar1 + 1;
  } while (piVar1 < &DAT_00434508);
  return;
}


