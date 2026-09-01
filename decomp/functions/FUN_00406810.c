/* 00406810 */

void __cdecl FUN_00406810(byte *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  char *pcVar14;
  byte *local_424;
  byte *local_420;
  int local_408;
  uint local_404;
  byte local_400 [512];
  byte abStack_200 [16];
  byte abStack_1f0 [496];
  
  pcVar1 = param_2;
  local_420 = param_1 + 0x7ca0;
  if (param_3 == 8) {
    local_408 = 0x80;
    local_424 = param_1;
    do {
      uVar11 = 0;
      pbVar5 = local_424;
      do {
        uVar12 = 0;
        bVar2 = *pbVar5;
        bVar7 = pbVar5[0x20];
        bVar3 = pbVar5[0x40];
        bVar4 = pbVar5[0x60];
        do {
          uVar9 = 0x80 >> ((byte)uVar12 & 0x1f);
          pbVar6 = local_400 + uVar11 + uVar12;
          bVar8 = 1 - ((uVar9 & bVar2) == 0);
          *pbVar6 = bVar8;
          bVar8 = ((uVar9 & bVar7) == 0) - 1U & 2 | bVar8;
          *pbVar6 = bVar8;
          bVar8 = ((uVar9 & bVar3) == 0) - 1U & 4 | bVar8;
          *pbVar6 = bVar8;
          uVar12 = uVar12 + 1;
          *pbVar6 = ((uVar9 & bVar4) == 0) - 1U & 8 | bVar8;
        } while (uVar12 < 8);
        pbVar5 = pbVar5 + 2;
        uVar11 = uVar11 + 8;
      } while (uVar11 < 0x40);
      pbVar5 = local_400;
      pcVar14 = param_2;
      for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(undefined4 *)pcVar14 = *(undefined4 *)pbVar5;
        pbVar5 = pbVar5 + 4;
        pcVar14 = pcVar14 + 4;
      }
      param_2 = param_2 + 0x40;
      local_424 = local_424 + 0x80;
      local_408 = local_408 + -1;
    } while (local_408 != 0);
  }
  else if (param_3 == 0x10) {
    uVar11 = 0;
    do {
      uVar12 = 0;
      do {
        pbVar5 = local_400 + uVar12;
        pbVar6 = param_1 + uVar11 + (uVar12 >> 3);
        uVar9 = 0x80 >> ((byte)uVar12 & 7);
        bVar7 = 1 - ((*pbVar6 & uVar9) == 0);
        bVar2 = pbVar6[0x20];
        *pbVar5 = bVar7;
        bVar7 = ((bVar2 & uVar9) == 0) - 1U & 2 | bVar7;
        bVar2 = pbVar6[0x40];
        *pbVar5 = bVar7;
        bVar7 = ((bVar2 & uVar9) == 0) - 1U & 4 | bVar7;
        bVar2 = pbVar6[0x60];
        *pbVar5 = bVar7;
        uVar12 = uVar12 + 1;
        *pbVar5 = ((bVar2 & uVar9) == 0) - 1U & 8 | bVar7;
      } while (uVar12 < 0x100);
      uVar11 = uVar11 + 0x80;
      pbVar5 = local_400;
      pcVar14 = param_2;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(undefined4 *)pcVar14 = *(undefined4 *)pbVar5;
        pbVar5 = pbVar5 + 4;
        pcVar14 = pcVar14 + 4;
      }
      param_2 = param_2 + 0x100;
    } while (uVar11 < 0x4000);
  }
  else if (param_3 == 0x20) {
    local_408 = 0x80;
    do {
      bVar2 = *local_420;
      bVar7 = local_420[2];
      bVar3 = local_420[1];
      bVar4 = local_420[3];
      local_424 = (byte *)0x0;
      local_404 = 0;
      do {
        uVar11 = 0;
        do {
          iVar10 = local_404 + uVar11;
          iVar13 = (int)local_424 + (uVar11 >> 3);
          pbVar5 = param_1 + iVar13 + (uint)bVar2 * 0x80;
          uVar12 = 0x80 >> ((byte)uVar11 & 7);
          bVar8 = 1 - ((*pbVar5 & uVar12) == 0);
          local_400[iVar10] = bVar8;
          bVar8 = ((pbVar5[0x20] & uVar12) == 0) - 1U & 2 | bVar8;
          local_400[iVar10] = bVar8;
          bVar8 = ((pbVar5[0x40] & uVar12) == 0) - 1U & 4 | bVar8;
          local_400[iVar10] = bVar8;
          local_400[iVar10] = ((pbVar5[0x60] & uVar12) == 0) - 1U & 8 | bVar8;
          pbVar5 = param_1 + iVar13 + (uint)bVar7 * 0x80;
          bVar8 = 1 - ((*pbVar5 & uVar12) == 0);
          local_400[iVar10 + 0x10] = bVar8;
          bVar8 = ((pbVar5[0x20] & uVar12) == 0) - 1U & 2 | bVar8;
          local_400[iVar10 + 0x10] = bVar8;
          bVar8 = ((pbVar5[0x40] & uVar12) == 0) - 1U & 4 | bVar8;
          local_400[iVar10 + 0x10] = bVar8;
          local_400[iVar10 + 0x10] = ((pbVar5[0x60] & uVar12) == 0) - 1U & 8 | bVar8;
          pbVar6 = param_1 + iVar13 + (uint)bVar3 * 0x80;
          bVar8 = 1 - ((*pbVar6 & uVar12) == 0);
          abStack_200[iVar10] = bVar8;
          bVar8 = ((pbVar6[0x20] & uVar12) == 0) - 1U & 2 | bVar8;
          abStack_200[iVar10] = bVar8;
          bVar8 = ((pbVar6[0x40] & uVar12) == 0) - 1U & 4 | bVar8;
          abStack_200[iVar10] = bVar8;
          pbVar5 = abStack_1f0 + iVar10;
          abStack_200[iVar10] = ((pbVar6[0x60] & uVar12) == 0) - 1U & 8 | bVar8;
          pbVar6 = param_1 + iVar13 + (uint)bVar4 * 0x80;
          bVar8 = 1 - ((*pbVar6 & uVar12) == 0);
          *pbVar5 = bVar8;
          bVar8 = ((pbVar6[0x20] & uVar12) == 0) - 1U & 2 | bVar8;
          *pbVar5 = bVar8;
          bVar8 = ((pbVar6[0x40] & uVar12) == 0) - 1U & 4 | bVar8;
          *pbVar5 = bVar8;
          uVar11 = uVar11 + 1;
          *pbVar5 = ((pbVar6[0x60] & uVar12) == 0) - 1U & 8 | bVar8;
        } while (uVar11 < 0x10);
        local_424 = (byte *)((int)local_424 + 2);
        local_404 = local_404 + 0x20;
      } while (local_404 < 0x200);
      pbVar5 = local_400;
      pcVar14 = param_2;
      for (iVar10 = 0x100; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(undefined4 *)pcVar14 = *(undefined4 *)pbVar5;
        pbVar5 = pbVar5 + 4;
        pcVar14 = pcVar14 + 4;
      }
      param_2 = param_2 + 0x400;
      local_420 = local_420 + 4;
      local_408 = local_408 + -1;
    } while (local_408 != 0);
  }
  for (; pcVar1 < param_2; pcVar1 = pcVar1 + 1) {
    *pcVar1 = *pcVar1 + '\x10';
  }
  return;
}


