/* 00405000 */

undefined4 __cdecl FUN_00405000(int param_1,uint param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  byte *pbVar3;
  undefined3 extraout_var;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint local_c;
  
  if ((0x2e < (int)param_2) || (0x2e < (int)param_3)) {
    return 0;
  }
  local_c = *(uint *)(DAT_0043453c + 8 + (param_2 * 0x30 + param_3) * 0x18);
  if (0x1ef < local_c) {
    return 0;
  }
  iVar4 = param_1 * 0x224;
  *(undefined4 *)(DAT_00434538 + 0x18 + iVar4) = 0x1f0;
  pbVar3 = (byte *)(DAT_00434538 + iVar4);
  if ((*pbVar3 == param_2) && (pbVar3[1] == param_3)) {
    return 10;
  }
  uVar5 = 0;
  pbVar3[0x18] = 0;
  pbVar3[0x19] = 0;
  pbVar3[0x1a] = 0;
  pbVar3[0x1b] = 0;
  *(uint *)(DAT_00434538 + 0x14 + iVar4) = local_c;
  do {
    iVar6 = 0;
    bVar1 = false;
    do {
      uVar7 = param_2 + (int)(char)(&DAT_00434401)[uVar5];
      uVar8 = param_3 + (int)(char)(&DAT_00434411)[uVar5];
      bVar2 = FUN_0041ebb0(uVar7,uVar8);
      if ((CONCAT31(extraout_var,bVar2) == 1) &&
         (*(uint *)(DAT_0043453c + 8 + (uVar7 * 0x30 + uVar8) * 0x18) < local_c)) {
        local_c = *(uint *)(DAT_0043453c + 8 + (uVar7 * 0x30 + uVar8) * 0x18);
        bVar1 = true;
        *(byte *)(DAT_00434538 + local_c + 0x1c + iVar4) =
             *(char *)((char)(&DAT_00434411)[uVar5] * 3 + 0x434434 +
                      (int)(char)(&DAT_00434401)[uVar5]) + 4U & 7;
        param_2 = uVar7;
        param_3 = uVar8;
        break;
      }
      iVar6 = iVar6 + 1;
      uVar5 = uVar5 + 1 & 3;
    } while (iVar6 < 4);
    if (local_c == 0) {
      return 1;
    }
    if (!bVar1) {
      if (local_c == 0) {
        return 1;
      }
      *(undefined4 *)(DAT_00434538 + 0x18 + iVar4) = 0x1f0;
      return 0;
    }
  } while( true );
}


