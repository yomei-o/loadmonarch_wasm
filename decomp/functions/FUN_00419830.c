/* 00419830 */

void __fastcall FUN_00419830(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int local_8;
  
  iVar2 = 0;
  if (0 < DAT_00435dc8) {
    local_8 = 0;
    piVar3 = (int *)(param_1 + 0x584);
    do {
      iVar2 = iVar2 + 1;
      FUN_0040ce60(&DAT_00435db0,*piVar3,piVar3[0x43]);
      piVar4 = piVar3;
      piVar5 = (int *)(DAT_00435db0 + local_8);
      for (iVar1 = 0x88; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        piVar5 = piVar5 + 1;
      }
      local_8 = local_8 + 0x220;
      piVar3 = piVar3 + 0x88;
    } while (iVar2 < DAT_00435dc8);
  }
  FUN_0040eb70(param_1);
  return;
}


