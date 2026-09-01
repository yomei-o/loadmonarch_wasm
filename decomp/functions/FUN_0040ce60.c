/* 0040ce60 */

void __thiscall FUN_0040ce60(void *this,int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char local_40c [1036];
  
  iVar1 = FUN_0040cd60(this,param_1);
  if (iVar1 != -1) {
    if (param_2 == 2) {
      DAT_004376b4 = 0;
      (**(code **)(*DAT_004358d0 + 0x10))(local_40c);
      if ((local_40c[0] == '\0') || (DAT_00436598 == 5)) {
        DAT_004376b4 = 1;
        param_2 = 0;
      }
    }
    iVar1 = iVar1 * 0x220;
    if ((((*(int *)(*(int *)this + iVar1) != -1) &&
         (iVar2 = FUN_0040cdc0(((int *)(*(int *)this + iVar1))[0x42]), iVar2 != -1)) &&
        (iVar2 == param_1)) && (*(int *)(*(int *)this + iVar1 + 0x10c) != param_2)) {
      FUN_0040ccf0(*(int *)(*(int *)this + iVar1 + 0x108));
      *(int *)(*(int *)this + 0x10c + iVar1) = param_2;
      FUN_0040cd20(this,param_1,1);
      return;
    }
    *(int *)(*(int *)this + 0x10c + iVar1) = param_2;
  }
  return;
}


