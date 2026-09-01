/* 0040ffe0 */

void __fastcall FUN_0040ffe0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar2 = 0;
  do {
    puVar4 = (undefined4 *)(*(int *)(param_1 + 0x22c) + iVar2);
    puVar3 = (undefined4 *)(DAT_00435fd4 + 0x20000 + iVar2);
    iVar2 = iVar2 + 0x100;
    for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  } while (iVar2 < 0x4000);
  return;
}


