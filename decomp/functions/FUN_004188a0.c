/* 004188a0 */

void __fastcall FUN_004188a0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  iVar2 = 0;
  iVar1 = FUN_0040cdc0(0);
  if ((iVar1 != -1) && (0 < DAT_00435dc8)) {
    iVar5 = 0;
    piVar3 = (int *)(param_1 + 0x444);
    do {
      if ((*(int *)(DAT_00435db0 + iVar5) == iVar1) &&
         (((int *)(DAT_00435db0 + iVar5))[0x43] != *piVar3)) {
        FUN_0040ccf0(0);
      }
      piVar3 = piVar3 + 0x88;
      iVar5 = iVar5 + 0x220;
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_00435dc8);
  }
  iVar1 = 0;
  iVar2 = 0;
  if (0 < DAT_00435dc8) {
    puVar4 = (undefined4 *)(param_1 + 0x338);
    do {
      puVar6 = puVar4;
      puVar7 = (undefined4 *)(DAT_00435db0 + iVar1);
      for (iVar5 = 0x88; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar4 = puVar4 + 0x88;
      iVar1 = iVar1 + 0x220;
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_00435dc8);
  }
  if ((DAT_0043769e != '\0') && (*(int *)(param_1 + 0x22338) != -1)) {
    FUN_0040cd20(&DAT_00435db0,*(int *)(param_1 + 0x22338),0);
  }
  FUN_0040eb70(param_1);
  return;
}


