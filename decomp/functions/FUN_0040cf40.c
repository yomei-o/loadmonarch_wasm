/* 0040cf40 */

void __thiscall FUN_0040cf40(void *this,int param_1,LPCSTR param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040cd60(this,param_1);
  if (iVar1 != -1) {
    wsprintfA((LPSTR)(iVar1 * 0x220 + *(int *)this + 0x114),param_2);
  }
  return;
}


