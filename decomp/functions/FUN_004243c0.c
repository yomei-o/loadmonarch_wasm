/* 004243c0 */

void __cdecl
FUN_004243c0(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 *param_5,int param_6
            )

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (0 < (int)param_2) {
    uVar1 = param_2;
    puVar3 = (undefined4 *)(param_6 + param_2 * param_2 * param_1);
    do {
      puVar4 = puVar3;
      puVar5 = param_5;
      for (uVar2 = param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      for (uVar2 = param_2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
      param_5 = (undefined4 *)((int)param_5 + param_3);
      uVar1 = uVar1 - 1;
      puVar3 = (undefined4 *)((int)puVar3 + param_2);
    } while (uVar1 != 0);
  }
  return;
}


