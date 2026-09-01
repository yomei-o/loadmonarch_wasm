/* 0041d460 */

void __fastcall FUN_0041d460(int *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint local_10;
  int local_8;
  int local_4;
  
  iVar5 = param_1[9];
  iVar6 = param_1[8];
  puVar7 = (undefined4 *)param_1[0x97];
  for (uVar2 = (uint)(iVar5 * iVar6) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar7 = 0x70707070;
    puVar7 = puVar7 + 1;
  }
  for (uVar2 = iVar5 * iVar6 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar7 = 0x70;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  local_10 = 0;
  do {
    iVar5 = local_10 + 0xe0 + param_1[0xe5] * 8;
    if (local_10 == 1) {
      bVar1 = *(byte *)(DAT_00434534 + 0x1e + param_1[0xe5] * 0x38);
      if (bVar1 != 0x80) {
        iVar5 = (uint)bVar1 * 8 + 0xe1;
        goto LAB_0041d4d2;
      }
    }
    else {
LAB_0041d4d2:
      iVar5 = iVar5 << 10;
      iVar6 = 0;
      uVar2 = (int)local_10 >> 0x1f;
      do {
        iVar4 = ((int)local_10 / 2) * 0x28 + iVar6;
        puVar7 = (undefined4 *)(DAT_00436440 + iVar5);
        iVar5 = iVar5 + 0x20;
        iVar6 = iVar6 + 1;
        puVar8 = (undefined4 *)
                 ((iVar4 + 0x10) * param_1[8] + param_1[0x97] + 0x10 +
                 (((local_10 ^ uVar2) - uVar2 & 1 ^ uVar2) - uVar2) * 0x20);
        for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
      } while (iVar6 < 0x20);
    }
    local_10 = local_10 + 1;
    if (7 < (int)local_10) {
      SelectObject((HDC)param_1[0x95],*(HGDIOBJ *)(DAT_004344e4 + 0x3a4));
      wsprintfA((LPSTR)(param_1 + 0xe8),&DAT_00432100,&DAT_00435b31 + param_1[0xe5] * 0x11);
      local_8 = param_1[8];
      local_4 = param_1[9];
      FUN_0040a870(4,2,0,1,(LPCSTR)(param_1 + 0xe8),(HDC)param_1[0x95],1,&local_8);
      SelectObject((HDC)param_1[0x95],*(HGDIOBJ *)(DAT_004344e4 + 0x3a4));
      (**(code **)(*param_1 + 0x18))();
      return;
    }
  } while( true );
}


