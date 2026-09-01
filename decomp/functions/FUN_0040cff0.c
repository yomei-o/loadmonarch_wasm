/* 0040cff0 */

void __thiscall FUN_0040cff0(void *this,int param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040cd60(this,param_1);
  if (iVar1 != -1) {
    *(undefined1 *)(iVar1 * 0x220 + 0x214 + *(int *)this) = param_2;
  }
  return;
}


