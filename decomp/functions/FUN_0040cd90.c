/* 0040cd90 */

int __fastcall FUN_0040cd90(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < (int)param_1[6]) {
    piVar2 = (int *)*param_1;
    do {
      if (*piVar2 == -1) {
        return iVar1;
      }
      piVar2 = piVar2 + 0x88;
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)param_1[6]);
  }
  return -1;
}


