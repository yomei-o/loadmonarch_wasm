/* 004267e0 */

void __fastcall FUN_004267e0(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  
  *(undefined4 *)(param_1 + 0x39c) = 0;
  *(undefined4 *)(param_1 + 0x3a0) = 0;
  *(undefined4 *)(param_1 + 0x394) = 0x40;
  iVar7 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    do {
      uVar3 = *(uint *)(param_1 + 0x20);
      iVar5 = iVar7 + 1;
      puVar6 = (undefined4 *)(iVar7 * 0x100 + 0x7000 + DAT_00435fd4);
      puVar8 = (undefined4 *)(iVar7 * uVar3 + *(int *)(param_1 + 0x25c));
      for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      iVar7 = iVar5;
    } while (iVar5 < *(int *)(param_1 + 0x24));
  }
  iVar7 = 0;
  SelectObject(*(HDC *)(param_1 + 0x254),*(HGDIOBJ *)(DAT_004344e4 + 0x3a4));
  do {
    iVar5 = iVar7;
    iVar10 = 0;
    do {
      iVar1 = DAT_00435fd4 + iVar5;
      iVar4 = iVar10 + 1;
      iVar9 = (iVar10 + 0x10) * *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x25c) + iVar7;
      *(undefined4 *)(iVar9 + 0x48) = *(undefined4 *)(iVar1 + 0x3000);
      *(undefined4 *)(iVar9 + 0x4c) = *(undefined4 *)(iVar1 + 0x3004);
      iVar1 = DAT_00435fd4 + iVar5;
      iVar5 = iVar5 + 0x100;
      iVar10 = (iVar10 + 0x60) * *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x25c) + iVar7;
      *(undefined4 *)(iVar10 + 0x48) = *(undefined4 *)(iVar1 + 0x3000);
      *(undefined4 *)(iVar10 + 0x4c) = *(undefined4 *)(iVar1 + 0x3004);
      iVar10 = iVar4;
    } while (iVar4 < 0x10);
    iVar7 = iVar7 + 8;
  } while (iVar7 < 0x50);
  return;
}


