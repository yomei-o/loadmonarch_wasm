/* 004208b0 */

undefined4 __cdecl FUN_004208b0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint *puVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  
  iVar6 = param_2 + param_1 * 0x30;
  iVar1 = iVar6 * 0x18;
  bVar7 = *(char *)(DAT_0043453c + 0x10 + iVar6 * 0x18) - 8;
  if (3 < bVar7) {
    return 0;
  }
  iVar8 = DAT_0043756c * 0x224 + DAT_00434538;
  bVar4 = *(byte *)(iVar8 + 4);
  if ((bVar7 != bVar4) && (*(byte *)(DAT_00434534 + 0x1e + (uint)bVar4 * 0x38) != bVar7)) {
    uVar9 = *(uint *)(iVar8 + 8);
    FUN_004209a0(iVar6);
    uVar5 = *(uint *)(DAT_0043453c + 0xc + iVar1);
    if (uVar5 < uVar9) {
      uVar9 = uVar5;
    }
    piVar2 = (int *)(DAT_00434534 + 0x14 + (uint)bVar7 * 0x38);
    iVar6 = *piVar2;
    *piVar2 = -1;
    *piVar2 = iVar6 + uVar9;
    puVar3 = (uint *)(DAT_0043453c + 0xc + iVar1);
    if (uVar9 < *puVar3) {
      *puVar3 = *puVar3 - uVar9;
      return 1;
    }
    *puVar3 = 100;
    *(undefined1 *)(DAT_0043453c + 0x10 + iVar1) = 0;
    return 1;
  }
  return 0;
}


