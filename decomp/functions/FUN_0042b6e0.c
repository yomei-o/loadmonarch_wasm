/* 0042b6e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0042b6e0(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  UINT CodePage;
  UINT *pUVar3;
  BOOL BVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  BYTE *pBVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  int local_18;
  _cpinfo local_14;
  
  CodePage = getSystemCP(param_1);
  if (DAT_004349a4 == CodePage) {
    return 0;
  }
  if (CodePage == 0) {
    setSBCS();
    return 0;
  }
  local_18 = 0;
  pUVar3 = &DAT_004349c8;
  do {
    if (*pUVar3 == CodePage) {
      uVar5 = 0;
      puVar10 = &DAT_004348a0;
      for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined1 *)puVar10 = 0;
      do {
        pbVar9 = &DAT_004349d8 + (uVar5 + local_18 * 6) * 8;
        bVar2 = *pbVar9;
        while ((bVar2 != 0 && (pbVar9[1] != 0))) {
          uVar7 = (uint)*pbVar9;
          if (uVar7 <= pbVar9[1]) {
            bVar2 = (&DAT_004349c0)[uVar5];
            do {
              pbVar1 = (byte *)((int)&DAT_004348a0 + uVar7 + 1);
              *pbVar1 = *pbVar1 | bVar2;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= pbVar9[1]);
          }
          pbVar9 = pbVar9 + 2;
          bVar2 = *pbVar9;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < 4);
      DAT_004349a4 = CodePage;
      _DAT_004349a8 = _CPtoLCID(CodePage);
      DAT_004349b0 = *(undefined4 *)(&DAT_004349cc + local_18 * 0x30);
      DAT_004349b4 = *(undefined4 *)(&DAT_004349d0 + local_18 * 0x30);
      DAT_004349b8 = *(undefined4 *)(local_18 * 0x30 + 0x4349d4);
      return 0;
    }
    pUVar3 = pUVar3 + 0xc;
    local_18 = local_18 + 1;
  } while (pUVar3 < &DAT_00434ab8);
  BVar4 = GetCPInfo(CodePage,&local_14);
  if (BVar4 == 1) {
    puVar10 = &DAT_004348a0;
    for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined1 *)puVar10 = 0;
    if (local_14.MaxCharSize < 2) {
      _DAT_004349a8 = 0;
      DAT_004349a4 = 0;
    }
    else {
      pBVar8 = local_14.LeadByte;
      while ((local_14.LeadByte[0] != 0 && (pBVar8[1] != 0))) {
        uVar5 = (uint)*pBVar8;
        if (uVar5 <= pBVar8[1]) {
          do {
            pbVar9 = (byte *)((int)&DAT_004348a0 + uVar5 + 1);
            *pbVar9 = *pbVar9 | 4;
            uVar5 = uVar5 + 1;
          } while (uVar5 <= pBVar8[1]);
        }
        pBVar8 = pBVar8 + 2;
        local_14.LeadByte[0] = *pBVar8;
      }
      uVar5 = 1;
      do {
        pbVar9 = (byte *)((int)&DAT_004348a0 + uVar5 + 1);
        *pbVar9 = *pbVar9 | 8;
        uVar5 = uVar5 + 1;
      } while (uVar5 < 0xff);
      DAT_004349a4 = CodePage;
      _DAT_004349a8 = _CPtoLCID(CodePage);
    }
    DAT_004349b0 = 0;
    DAT_004349b4 = 0;
    DAT_004349b8 = 0;
    return 0;
  }
  if (DAT_004349bc == 0) {
    return 0xffffffff;
  }
  setSBCS();
  return 0;
}


