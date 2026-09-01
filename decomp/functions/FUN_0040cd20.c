/* 0040cd20 */

undefined4 __thiscall FUN_0040cd20(void *this,int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0040cd60(this,param_1);
  if (iVar1 == -1) {
    return 0;
  }
  uVar2 = (*(code *)**(undefined4 **)(&DAT_004358d8)[*(int *)(iVar1 * 0x220 + 0x108 + *(int *)this)]
          )(iVar1,param_2);
  return uVar2;
}


