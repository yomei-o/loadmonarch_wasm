/* 0042a070 */

int __cdecl FUN_0042a070(SIZE_T param_1,int param_2)

{
  int iVar1;
  
  if (0xffffffe0 < param_1) {
    return 0;
  }
  if (param_1 == 0) {
    param_1 = 1;
  }
  while( true ) {
    iVar1 = FUN_0042a0b0(param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (param_2 == 0) break;
    iVar1 = FUN_0042c740(param_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 0;
}


