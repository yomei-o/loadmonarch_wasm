/* 0041fef0 */

void __fastcall FUN_0041fef0(int param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  byte *pbVar4;
  short sVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  uint uVar9;
  ushort uVar10;
  int iVar11;
  
  *(undefined2 *)(param_1 + 0x218) = 2;
  if (*(short *)(*(int *)(param_1 + 0x214) + 0x10) != 2) {
    do {
      piVar6 = (int *)(*(int *)(param_1 + 0x214) + 4);
      bVar1 = **(byte **)(*(int *)(param_1 + 0x214) + 4);
      *piVar6 = *piVar6 + 1;
      sVar5 = *(short *)(param_1 + 0x218) + 1;
      *(short *)(param_1 + 0x218) = sVar5;
      if ((bVar1 & 0x80) == 0) {
        if ((bVar1 & 0x40) == 0) {
          if ((bVar1 & 0x20) == 0) {
            *(ushort *)(param_1 + 0x218) = sVar5 + (bVar1 & 0x1f);
            piVar6 = (int *)(*(int *)(param_1 + 0x214) + 8);
            *piVar6 = *piVar6 + (uint)(bVar1 & 0x1f);
            iVar11 = 0;
            if ((bVar1 & 0x1f) != 0) {
              do {
                iVar11 = iVar11 + 1;
                *(undefined1 *)**(undefined4 **)(param_1 + 0x214) =
                     *(undefined1 *)(*(undefined4 **)(param_1 + 0x214))[1];
                piVar6 = (int *)(*(int *)(param_1 + 0x214) + 4);
                *piVar6 = *piVar6 + 1;
                **(int **)(param_1 + 0x214) = **(int **)(param_1 + 0x214) + 1;
              } while (iVar11 < (int)(uint)(bVar1 & 0x1f));
            }
          }
          else {
            puVar7 = (undefined4 *)(*(int *)(param_1 + 0x214) + 4);
            pbVar4 = (byte *)*puVar7;
            uVar10 = (ushort)*pbVar4 + (bVar1 & 0x1f) * 0x100;
            *puVar7 = pbVar4 + 1;
            *(short *)(param_1 + 0x218) = *(short *)(param_1 + 0x218) + uVar10 + 1;
            uVar9 = (uint)uVar10;
            piVar6 = (int *)(*(int *)(param_1 + 0x214) + 8);
            *piVar6 = *piVar6 + uVar9;
            if (uVar10 != 0) {
              do {
                *(undefined1 *)**(undefined4 **)(param_1 + 0x214) =
                     *(undefined1 *)(*(undefined4 **)(param_1 + 0x214))[1];
                piVar6 = (int *)(*(int *)(param_1 + 0x214) + 4);
                *piVar6 = *piVar6 + 1;
                **(int **)(param_1 + 0x214) = **(int **)(param_1 + 0x214) + 1;
                uVar9 = uVar9 - 1;
              } while (uVar9 != 0);
            }
          }
        }
        else if ((bVar1 & 0x10) == 0) {
          puVar8 = *(undefined1 **)(*(int *)(param_1 + 0x214) + 4);
          uVar3 = *puVar8;
          *(undefined1 **)(*(int *)(param_1 + 0x214) + 4) = puVar8 + 1;
          *(short *)(param_1 + 0x218) = *(short *)(param_1 + 0x218) + 1;
          piVar6 = (int *)(*(int *)(param_1 + 0x214) + 8);
          *piVar6 = *piVar6 + (bVar1 & 0xf) + 4;
          iVar11 = 0;
          if ((bVar1 & 0xf) != 0xfffffffc) {
            do {
              iVar11 = iVar11 + 1;
              *(undefined1 *)**(undefined4 **)(param_1 + 0x214) = uVar3;
              **(int **)(param_1 + 0x214) = **(int **)(param_1 + 0x214) + 1;
            } while (iVar11 < (int)((bVar1 & 0xf) + 4));
          }
        }
        else {
          puVar7 = (undefined4 *)(*(int *)(param_1 + 0x214) + 4);
          pbVar4 = (byte *)*puVar7;
          bVar2 = *pbVar4;
          *puVar7 = pbVar4 + 1;
          puVar8 = *(undefined1 **)(*(int *)(param_1 + 0x214) + 4);
          uVar3 = *puVar8;
          *(undefined1 **)(*(int *)(param_1 + 0x214) + 4) = puVar8 + 1;
          uVar9 = (uint)(ushort)((bVar1 & 0xf) * 0x100 + (ushort)bVar2);
          *(short *)(param_1 + 0x218) = *(short *)(param_1 + 0x218) + 2;
          piVar6 = (int *)(*(int *)(param_1 + 0x214) + 8);
          *piVar6 = *piVar6 + uVar9 + 4;
          for (iVar11 = uVar9 + 4; iVar11 != 0; iVar11 = iVar11 + -1) {
            *(undefined1 *)**(undefined4 **)(param_1 + 0x214) = uVar3;
            **(int **)(param_1 + 0x214) = **(int **)(param_1 + 0x214) + 1;
          }
        }
      }
      else {
        puVar7 = (undefined4 *)(*(int *)(param_1 + 0x214) + 4);
        pbVar4 = (byte *)*puVar7;
        bVar2 = *pbVar4;
        *puVar7 = pbVar4 + 1;
        iVar11 = **(int **)(param_1 + 0x214);
        *(short *)(param_1 + 0x218) = *(short *)(param_1 + 0x218) + 1;
        puVar8 = (undefined1 *)(iVar11 - (uint)(ushort)((ushort)bVar2 + (bVar1 & 0x1f) * 0x100));
        piVar6 = *(int **)(param_1 + 0x214) + 2;
        *piVar6 = *piVar6 + ((bVar1 & 0xffffff60) >> 5) + 4;
        iVar11 = 0;
        if ((bVar1 & 0x60) >> 5 != 0xfffffffc) {
          do {
            uVar3 = *puVar8;
            puVar8 = puVar8 + 1;
            iVar11 = iVar11 + 1;
            *(undefined1 *)**(undefined4 **)(param_1 + 0x214) = uVar3;
            **(int **)(param_1 + 0x214) = **(int **)(param_1 + 0x214) + 1;
          } while (iVar11 < (int)(((bVar1 & 0x60) >> 5) + 4));
        }
        if (*(short *)(*(int *)(param_1 + 0x214) + 0x10) == *(short *)(param_1 + 0x218)) {
          return;
        }
        bVar1 = **(byte **)(*(int *)(param_1 + 0x214) + 4);
        while ((bVar1 & 0xe0) == 0x60) {
          iVar11 = 0;
          if ((bVar1 & 0x1f) != 0) {
            do {
              uVar3 = *puVar8;
              puVar8 = puVar8 + 1;
              iVar11 = iVar11 + 1;
              *(undefined1 *)**(undefined4 **)(param_1 + 0x214) = uVar3;
              **(int **)(param_1 + 0x214) = **(int **)(param_1 + 0x214) + 1;
            } while (iVar11 < (int)(uint)(bVar1 & 0x1f));
          }
          piVar6 = (int *)(*(int *)(param_1 + 0x214) + 4);
          *piVar6 = *piVar6 + 1;
          piVar6 = (int *)(*(int *)(param_1 + 0x214) + 8);
          *piVar6 = *piVar6 + (uint)(bVar1 & 0x1f);
          *(short *)(param_1 + 0x218) = *(short *)(param_1 + 0x218) + 1;
          bVar1 = **(byte **)(*(int *)(param_1 + 0x214) + 4);
        }
      }
    } while (*(short *)(*(int *)(param_1 + 0x214) + 0x10) != *(short *)(param_1 + 0x218));
  }
  return;
}


