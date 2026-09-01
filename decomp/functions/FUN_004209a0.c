/* 004209a0 */

void __cdecl FUN_004209a0(int param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(DAT_0043453c + 0xc + param_1 * 0x18);
  uVar3 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
  if (uVar3 < uVar5) {
    uVar5 = uVar3;
  }
  piVar1 = (int *)(DAT_00434534 + 0x14 + DAT_00437580 * 0x38);
  iVar4 = *piVar1;
  *piVar1 = -1;
  if (iVar4 + uVar5 != -1) {
    *piVar1 = iVar4 + uVar5;
  }
  puVar2 = (uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
  uVar3 = *puVar2;
  if (uVar3 <= uVar5) {
    FUN_00420aa0(DAT_0043756c,*(char *)(DAT_0043453c + 0x10 + param_1 * 0x18) + -8);
    return;
  }
  *puVar2 = uVar3 - uVar5;
  return;
}


