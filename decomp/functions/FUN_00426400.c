/* 00426400 */

void FUN_00426400(void)

{
  DAT_004344dc = 1;
  FUN_00409370(s_A_problem_has_occurred__Aborting_00434554,0);
  if (DAT_004344e4 != (int *)0x0) {
    (**(code **)(*DAT_004344e4 + 0x3c))();
    DAT_004344e4 = (int *)0x0;
  }
  return;
}


