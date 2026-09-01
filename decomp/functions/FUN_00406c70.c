/* 00406c70 */

void __cdecl FUN_00406c70(int param_1,undefined4 *param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint local_408;
  uint local_404;
  byte local_400 [512];
  byte local_200 [16];
  byte local_1f0 [496];
  
  if (param_3 == 8) {
    uVar8 = 0;
    do {
      uVar10 = 0;
      do {
        pbVar2 = local_400 + uVar10;
        pbVar7 = (byte *)((uVar10 >> 3) + param_1 + uVar8);
        uVar9 = 0x80 >> ((byte)uVar10 & 7);
        bVar5 = 1 - ((*pbVar7 & uVar9) == 0);
        bVar1 = pbVar7[0x20];
        *pbVar2 = bVar5;
        bVar5 = ((bVar1 & uVar9) == 0) - 1U & 2 | bVar5;
        bVar1 = pbVar7[0x40];
        *pbVar2 = bVar5;
        bVar5 = ((bVar1 & uVar9) == 0) - 1U & 4 | bVar5;
        bVar1 = pbVar7[0x60];
        *pbVar2 = bVar5;
        bVar5 = ((bVar1 & uVar9) == 0) - 1U & 8 | bVar5;
        *pbVar2 = bVar5;
        if (bVar5 == 0xf) {
          *pbVar2 = 0x70;
          if (uVar8 < 0x1980) {
            *pbVar2 = 0x76;
          }
        }
        else {
          *pbVar2 = bVar5 + 0x30;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < 0x100);
      pbVar7 = local_400;
      do {
        iVar4 = 2;
        pbVar2 = pbVar7;
        do {
          iVar3 = 8;
          pbVar6 = pbVar2;
          do {
            puVar11 = param_2 + 2;
            pbVar2 = pbVar6 + 0x10;
            *param_2 = *(undefined4 *)pbVar6;
            iVar3 = iVar3 + -1;
            param_2[1] = *(undefined4 *)(pbVar6 + 4);
            pbVar6 = pbVar2;
            param_2 = puVar11;
          } while (iVar3 != 0);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        pbVar7 = pbVar7 + 8;
      } while (pbVar7 < local_400 + 0x10);
      uVar8 = uVar8 + 0x80;
    } while (uVar8 < 0x2000);
    return;
  }
  if (param_3 != 0x10) {
    if (param_3 != 0x20) {
      return;
    }
    local_408 = 0;
    do {
      uVar8 = 0;
      local_404 = local_408;
      do {
        uVar10 = 0;
        do {
          pbVar7 = local_400 + uVar8 + uVar10;
          pbVar2 = (byte *)(local_404 + (uVar10 >> 3) + param_1);
          uVar9 = 0x80 >> ((byte)uVar10 & 7);
          bVar5 = 1 - ((*pbVar2 & uVar9) == 0);
          bVar1 = pbVar2[0x20];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 2 | bVar5;
          bVar1 = pbVar2[0x40];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 4 | bVar5;
          bVar1 = pbVar2[0x60];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 8 | bVar5;
          *pbVar7 = bVar5;
          if (bVar5 == 0xf) {
            local_400[uVar8 + uVar10] = 0x70;
          }
          else {
            local_400[uVar8 + uVar10] = local_400[uVar8 + uVar10] + 0x30;
          }
          pbVar7 = local_400 + uVar8 + uVar10 + 0x10;
          bVar5 = 1 - ((pbVar2[0x80] & uVar9) == 0);
          bVar1 = pbVar2[0xa0];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 2 | bVar5;
          bVar1 = pbVar2[0xc0];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 4 | bVar5;
          bVar1 = pbVar2[0xe0];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 8 | bVar5;
          *pbVar7 = bVar5;
          if (bVar5 == 0xf) {
            local_400[uVar8 + uVar10 + 0x10] = 0x70;
          }
          else {
            local_400[uVar8 + uVar10 + 0x10] = local_400[uVar8 + uVar10 + 0x10] + 0x30;
          }
          pbVar7 = local_200 + uVar8 + uVar10;
          bVar5 = 1 - ((pbVar2[0x100] & uVar9) == 0);
          bVar1 = pbVar2[0x120];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 2 | bVar5;
          bVar1 = pbVar2[0x140];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 4 | bVar5;
          bVar1 = pbVar2[0x160];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 8 | bVar5;
          *pbVar7 = bVar5;
          if (bVar5 == 0xf) {
            local_200[uVar8 + uVar10] = 0x70;
          }
          else {
            local_200[uVar8 + uVar10] = local_200[uVar8 + uVar10] + 0x30;
          }
          pbVar7 = local_1f0 + uVar8 + uVar10;
          bVar5 = 1 - ((pbVar2[0x180] & uVar9) == 0);
          bVar1 = pbVar2[0x1a0];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 2 | bVar5;
          bVar1 = pbVar2[0x1c0];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 4 | bVar5;
          bVar1 = pbVar2[0x1e0];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 8 | bVar5;
          *pbVar7 = bVar5;
          if (bVar5 == 0xf) {
            local_1f0[uVar8 + uVar10] = 0x70;
          }
          else {
            local_1f0[uVar8 + uVar10] = local_1f0[uVar8 + uVar10] + 0x30;
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < 0x10);
        local_404 = local_404 + 2;
        uVar8 = uVar8 + 0x20;
      } while (uVar8 < 0x200);
      pbVar7 = local_400;
      puVar11 = param_2;
      for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar11 = *(undefined4 *)pbVar7;
        pbVar7 = pbVar7 + 4;
        puVar11 = puVar11 + 1;
      }
      param_2 = param_2 + 0x100;
      local_408 = local_408 + 0x200;
    } while (local_408 < 0x8000);
    return;
  }
  uVar8 = 0;
  do {
    uVar10 = 0;
    do {
      pbVar2 = local_400 + uVar10;
      pbVar7 = (byte *)((uVar10 >> 3) + param_1 + uVar8);
      uVar9 = 0x80 >> ((byte)uVar10 & 7);
      bVar5 = 1 - ((*pbVar7 & uVar9) == 0);
      bVar1 = pbVar7[0x20];
      *pbVar2 = bVar5;
      bVar5 = ((bVar1 & uVar9) == 0) - 1U & 2 | bVar5;
      bVar1 = pbVar7[0x40];
      *pbVar2 = bVar5;
      bVar5 = ((bVar1 & uVar9) == 0) - 1U & 4 | bVar5;
      bVar1 = pbVar7[0x60];
      *pbVar2 = bVar5;
      bVar5 = ((bVar1 & uVar9) == 0) - 1U & 8 | bVar5;
      *pbVar2 = bVar5;
      if (bVar5 == 0xf) {
        *pbVar2 = 0x70;
      }
      else {
        *pbVar2 = bVar5 + 0x30;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < 0x100);
    uVar8 = uVar8 + 0x80;
    pbVar7 = local_400;
    puVar11 = param_2;
    for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar11 = *(undefined4 *)pbVar7;
      pbVar7 = pbVar7 + 4;
      puVar11 = puVar11 + 1;
    }
    param_2 = param_2 + 0x40;
  } while (uVar8 < 0x6800);
  return;
}


