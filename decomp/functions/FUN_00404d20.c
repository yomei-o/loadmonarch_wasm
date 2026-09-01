/* 00404d20 */

void __fastcall FUN_00404d20(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x524) != 0) {
    iVar2 = 0x10;
    iVar3 = 0;
    iVar4 = param_1 + 0x528;
    do {
      iVar1 = iVar2 + 0x10;
      FUN_00427a10(*(void **)(param_1 + 0x524),iVar3 + 60000,iVar4,iVar2,0,iVar1,0x40);
      iVar2 = iVar1;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x100;
    } while (iVar1 < 0x90);
    iVar2 = param_1 + 0xd28;
    iVar3 = 0;
    iVar4 = 0x10;
    do {
      iVar1 = iVar4 + 0x10;
      FUN_00427a10(*(void **)(param_1 + 0x524),iVar3 + 0xea68,iVar2,iVar4,0x40,iVar1,0xb0);
      iVar2 = iVar2 + 0x100;
      iVar3 = iVar3 + 1;
      iVar4 = iVar1;
    } while (iVar1 < 0x90);
    FUN_00427a10(*(void **)(param_1 + 0x524),0xea70,param_1 + 0x1528,0x90,0x40,0xa0,0xb0);
  }
  return;
}


