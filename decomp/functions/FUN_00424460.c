/* 00424460 */

void __cdecl
FUN_00424460(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (0 < param_2) {
    iVar2 = param_2 * param_2 * param_1 + param_6;
    iVar1 = param_2;
    do {
      iVar3 = 0;
      if (0 < param_2) {
        do {
          if (*(char *)(iVar3 + iVar2) != 'p') {
            *(char *)(iVar3 + param_5) = *(char *)(iVar3 + iVar2);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < param_2);
      }
      param_5 = param_5 + param_3;
      iVar2 = iVar2 + param_2;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


