/* 0040a800 */

void FUN_0040a800(void)

{
  if (DAT_004344e8 != (int *)0x0) {
    (**(code **)(*DAT_004344e8 + 100))();
  }
  if (DAT_004344f0 != (int *)0x0) {
    (**(code **)(*DAT_004344f0 + 100))();
  }
  if (DAT_004344f4 != (int *)0x0) {
    (**(code **)(*DAT_004344f4 + 100))();
  }
  if (DAT_004344ec != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0040a861. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_004344ec + 100))();
    return;
  }
  return;
}


