/* 0040ce10 */

undefined4 __thiscall FUN_0040ce10(void *this,int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040cd60(this,param_1);
  if (iVar1 == -1) {
    iVar1 = FUN_0040cd90(this);
    if (iVar1 == -1) {
      return 0;
    }
  }
  *(int *)(*(int *)this + iVar1 * 0x220) = param_1;
  *(undefined4 *)(*(int *)this + 0x108 + iVar1 * 0x220) = param_2;
  return 1;
}


