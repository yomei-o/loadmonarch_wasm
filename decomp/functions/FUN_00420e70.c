/* 00420e70 */

void __cdecl FUN_00420e70(int param_1,int param_2,uint param_3)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = DAT_00434538 + param_2 * 0x224;
  uVar4 = *(uint *)(iVar5 + 8);
  if (param_3 <= uVar4) {
    uVar4 = param_3;
  }
  piVar1 = (int *)(DAT_00434534 + 0x14 + (uint)*(byte *)(iVar5 + 4) * 0x38);
  *piVar1 = *piVar1 + uVar4;
  puVar2 = (uint *)(DAT_00434538 + 8 + param_2 * 0x224);
  uVar3 = *puVar2;
  if (uVar3 <= uVar4) {
    FUN_00420aa0(param_2,*(undefined1 *)(DAT_00434538 + 4 + param_1 * 0x224));
    return;
  }
  *puVar2 = uVar3 - uVar4;
  return;
}


