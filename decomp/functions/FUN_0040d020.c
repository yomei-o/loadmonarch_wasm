/* 0040d020 */

void __thiscall FUN_0040d020(void *this,int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040cd60(this,param_1);
  if (iVar1 != -1) {
    *(undefined4 *)(iVar1 * 0x220 + 0x108 + *(int *)this) = param_2;
  }
  return;
}


