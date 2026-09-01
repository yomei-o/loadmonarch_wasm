/* 0040d410 */

void __fastcall FUN_0040d410(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_1[6]) {
    iVar2 = 0;
    do {
      iVar1 = *(int *)(*param_1 + iVar2);
      if ((iVar1 != -1) && (((int *)(*param_1 + iVar2))[0x42] == 0)) {
        FUN_0040ce60(param_1,iVar1,0);
      }
      iVar2 = iVar2 + 0x220;
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[6]);
  }
  return;
}


