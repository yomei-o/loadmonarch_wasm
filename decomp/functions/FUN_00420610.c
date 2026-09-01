/* 00420610 */

undefined4 __cdecl FUN_00420610(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  uVar9 = (uint)*(byte *)(DAT_0043453c + (param_1 * 0x30 + param_2) * 0x18);
  if (uVar9 == 0x40) {
    return 0;
  }
  iVar2 = uVar9 * 0x224;
  iVar7 = DAT_00434538 + iVar2;
  if (*(byte *)(iVar7 + 4) != DAT_00437580) {
    return 0;
  }
  if ((*(byte *)(iVar7 + 0x10) & 2) != 0) {
    return 0;
  }
  iVar8 = DAT_0043756c * 0x224 + DAT_00434538;
  puVar1 = (uint *)(iVar8 + 8);
  uVar6 = *puVar1;
  if (100000 < *(uint *)(iVar7 + 8) + uVar6) {
    return 0;
  }
  bVar4 = *(byte *)(iVar8 + 0xd);
  if ((bVar4 & 0x20) != 0) {
    *puVar1 = *(int *)(DAT_00434538 + 8 + iVar2) + uVar6;
    FUN_00420b30(uVar9,param_1,param_2);
    return 0;
  }
  bVar5 = *(byte *)(iVar7 + 0xd);
  if ((bVar5 & 0x20) != 0) {
    piVar3 = (int *)(DAT_00434538 + 8 + iVar2);
    *piVar3 = *piVar3 + uVar6;
    FUN_00420b30(DAT_0043756c,DAT_0043644c,DAT_00436450);
    return 1;
  }
  if (((bVar4 & 0x10) == 0x10) || ((bVar5 & 0x10) != 0)) {
    if ((bVar5 & 0x10) == 0) {
      *puVar1 = *(int *)(DAT_00434538 + 8 + iVar2) + uVar6;
      FUN_00420b30(uVar9,param_1,param_2);
      return 0;
    }
    if ((bVar4 & 0x10) == 0) {
      piVar3 = (int *)(DAT_00434538 + 8 + iVar2);
      *piVar3 = *piVar3 + uVar6;
      FUN_00420b30(DAT_0043756c,DAT_0043644c,DAT_00436450);
      return 1;
    }
  }
  if ((bVar4 & 0xf) != 3) {
    if ((bVar5 & 0xf) == 3) {
      if ((bVar4 & 0xf) == 3) goto LAB_004207b5;
      if ((bVar5 & 0xf) == 3) {
        *puVar1 = *(int *)(DAT_00434538 + 8 + iVar2) + uVar6;
        FUN_00420b30(uVar9,param_1,param_2);
        return 0;
      }
      if ((bVar5 & 0xf) == 1) {
        *puVar1 = *(int *)(DAT_00434538 + 8 + iVar2) + uVar6;
        FUN_00420b30(uVar9,param_1,param_2);
        return 0;
      }
    }
    if (*(uint *)(iVar7 + 8) <= uVar6) {
      *puVar1 = *(int *)(DAT_00434538 + 8 + iVar2) + uVar6;
      FUN_00420b30(uVar9,param_1,param_2);
      return 0;
    }
    piVar3 = (int *)(DAT_00434538 + 8 + iVar2);
    *piVar3 = *piVar3 + uVar6;
    FUN_00420b30(DAT_0043756c,DAT_0043644c,DAT_00436450);
    return 1;
  }
LAB_004207b5:
  piVar3 = (int *)(DAT_00434538 + 8 + iVar2);
  *piVar3 = *piVar3 + uVar6;
  FUN_00420b30(DAT_0043756c,DAT_0043644c,DAT_00436450);
  return 1;
}


