/* 00424410 */

void __cdecl
FUN_00424410(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6,
            char param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (0 < param_2) {
    iVar2 = param_6 + param_2 * param_2 * param_1;
    iVar1 = param_2;
    do {
      iVar3 = 0;
      if (0 < param_2) {
        do {
          iVar4 = iVar3 + 1;
          *(char *)(iVar3 + param_5) = *(char *)(iVar3 + iVar2) + param_7;
          iVar3 = iVar4;
        } while (iVar4 < param_2);
      }
      iVar2 = iVar2 + param_2;
      param_5 = param_5 + param_3;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


