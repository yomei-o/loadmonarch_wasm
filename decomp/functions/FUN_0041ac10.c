/* 0041ac10 */

int __cdecl FUN_0041ac10(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_3 < param_1) {
    iVar1 = param_1 - param_3;
  }
  else {
    iVar1 = param_3 - param_1;
  }
  if (param_4 < param_2) {
    return (param_2 - param_4) + iVar1;
  }
  return (param_4 - param_2) + iVar1;
}


