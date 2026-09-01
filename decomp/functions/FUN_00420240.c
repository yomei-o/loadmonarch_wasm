/* 00420240 */

void __fastcall FUN_00420240(void *param_1)

{
  undefined1 uVar1;
  byte *pbVar2;
  ushort uVar3;
  short sVar4;
  uint uVar5;
  int *piVar6;
  undefined1 *puVar7;
  ushort uVar8;
  int iVar9;
  
  *(undefined2 *)((int)param_1 + 0x218) = 4;
  piVar6 = (int *)(*(int *)((int)param_1 + 0x214) + 4);
  *(ushort *)((int)param_1 + 0x21a) =
       (ushort)*(byte *)(*(int *)(*(int *)((int)param_1 + 0x214) + 4) + 1);
  *(undefined1 *)((int)param_1 + 0x21c) = 8;
  *piVar6 = *piVar6 + 2;
  do {
    while( true ) {
      while (uVar5 = FUN_00420460((int)param_1), (short)uVar5 == 0) {
        *(undefined1 *)**(undefined4 **)((int)param_1 + 0x214) =
             *(undefined1 *)(*(undefined4 **)((int)param_1 + 0x214))[1];
        piVar6 = (int *)(*(int *)((int)param_1 + 0x214) + 4);
        *piVar6 = *piVar6 + 1;
        **(int **)((int)param_1 + 0x214) = **(int **)((int)param_1 + 0x214) + 1;
        piVar6 = (int *)(*(int *)((int)param_1 + 0x214) + 8);
        *piVar6 = *piVar6 + 1;
        *(short *)((int)param_1 + 0x218) = *(short *)((int)param_1 + 0x218) + 1;
      }
      uVar5 = FUN_00420460((int)param_1);
      if ((short)uVar5 != 0) break;
      pbVar2 = *(byte **)(*(int *)((int)param_1 + 0x214) + 4);
      uVar8 = (ushort)*pbVar2;
      *(byte **)(*(int *)((int)param_1 + 0x214) + 4) = pbVar2 + 1;
      *(short *)((int)param_1 + 0x218) = *(short *)((int)param_1 + 0x218) + 1;
LAB_004202d5:
      uVar5 = FUN_00420460((int)param_1);
      if ((short)uVar5 == 0) {
        uVar5 = FUN_00420460((int)param_1);
        if ((short)uVar5 == 0) {
          uVar5 = FUN_00420460((int)param_1);
          if ((short)uVar5 == 0) {
            uVar5 = FUN_00420460((int)param_1);
            if ((short)uVar5 == 0) {
              uVar5 = FUN_00420460((int)param_1);
              if ((short)uVar5 == 0) {
                pbVar2 = *(byte **)(*(int *)((int)param_1 + 0x214) + 4);
                uVar3 = *pbVar2 + 0xe;
                *(byte **)(*(int *)((int)param_1 + 0x214) + 4) = pbVar2 + 1;
                *(short *)((int)param_1 + 0x218) = *(short *)((int)param_1 + 0x218) + 1;
              }
              else {
                sVar4 = FUN_004204c0(param_1,3);
                uVar3 = sVar4 + 6;
              }
            }
            else {
              uVar3 = 5;
            }
          }
          else {
            uVar3 = 4;
          }
        }
        else {
          uVar3 = 3;
        }
      }
      else {
        uVar3 = 2;
      }
      puVar7 = (undefined1 *)(**(int **)((int)param_1 + 0x214) - (uint)uVar8);
      if (uVar3 != 0) {
        uVar5 = (uint)uVar3;
        do {
          uVar1 = *puVar7;
          puVar7 = puVar7 + 1;
          *(undefined1 *)**(undefined4 **)((int)param_1 + 0x214) = uVar1;
          **(int **)((int)param_1 + 0x214) = **(int **)((int)param_1 + 0x214) + 1;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
      piVar6 = (int *)(*(int *)((int)param_1 + 0x214) + 8);
      *piVar6 = *piVar6 + (uint)uVar3;
    }
    sVar4 = FUN_004204c0(param_1,5);
    pbVar2 = *(byte **)(*(int *)((int)param_1 + 0x214) + 4);
    uVar8 = (ushort)*pbVar2 + sVar4 * 0x100;
    *(byte **)(*(int *)((int)param_1 + 0x214) + 4) = pbVar2 + 1;
    if (uVar8 == 0) {
      return;
    }
    if (uVar8 != 1) goto LAB_004202d5;
    uVar5 = FUN_00420460((int)param_1);
    if ((short)uVar5 == 0) {
      uVar8 = FUN_004204c0(param_1,4);
      sVar4 = uVar8 + 0xf;
    }
    else {
      sVar4 = FUN_004204c0(param_1,4);
      pbVar2 = *(byte **)(*(int *)((int)param_1 + 0x214) + 4);
      uVar8 = (ushort)*pbVar2 + sVar4 * 0x100;
      *(byte **)(*(int *)((int)param_1 + 0x214) + 4) = pbVar2 + 1;
      sVar4 = uVar8 + 0x10;
    }
    *(short *)((int)param_1 + 0x218) = *(short *)((int)param_1 + 0x218) + sVar4;
    puVar7 = *(undefined1 **)(*(int *)((int)param_1 + 0x214) + 4);
    uVar1 = *puVar7;
    *(undefined1 **)(*(int *)((int)param_1 + 0x214) + 4) = puVar7 + 1;
    for (iVar9 = uVar8 + 0xe; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)**(undefined4 **)((int)param_1 + 0x214) = uVar1;
      **(int **)((int)param_1 + 0x214) = **(int **)((int)param_1 + 0x214) + 1;
    }
    piVar6 = (int *)(*(int *)((int)param_1 + 0x214) + 8);
    *piVar6 = *piVar6 + uVar8 + 0xe;
  } while( true );
}


