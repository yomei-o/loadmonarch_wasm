/* 00408de0 */

void __cdecl FUN_00408de0(int param_1)

{
  if (param_1 == 1) {
    DAT_0043452c = DAT_0043452c + 1;
    return;
  }
  if ((param_1 == 0) && (DAT_0043452c != 0)) {
    DAT_0043452c = DAT_0043452c + -1;
  }
  return;
}


