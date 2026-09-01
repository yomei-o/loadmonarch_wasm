/* 004198c0 */

int __fastcall FUN_004198c0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0x23194);
  do {
    if (*piVar2 == -1) {
      return iVar1;
    }
    piVar2 = piVar2 + 2;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x100);
  return -1;
}


