/* 0042c500 */

int FUN_0042c500(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    FUN_00429f30();
    return 1;
  }
  if (DAT_00437934 != (_func_int *)0x0) {
    iVar2 = _ValidateExecute(DAT_00437934);
    if (iVar2 != 0) {
      iVar2 = (*DAT_00437934)(param_1);
      return iVar2;
    }
  }
  return 0;
}


