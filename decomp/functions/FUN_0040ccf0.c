/* 0040ccf0 */

void FUN_0040ccf0(int param_1)

{
  int iVar1;
  
  if ((&DAT_004358d8)[param_1] != 0) {
    iVar1 = FUN_0040cdc0(param_1);
    if (iVar1 != -1) {
      (**(code **)(*(int *)(&DAT_004358d8)[param_1] + 4))();
    }
  }
  return;
}


