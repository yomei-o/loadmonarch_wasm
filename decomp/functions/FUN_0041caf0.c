/* 0041caf0 */

bool __cdecl FUN_0041caf0(undefined2 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 0;
  *(undefined4 *)(param_1 + 2) = 0x1f0;
  do {
    iVar2 = DAT_00434538 + iVar3;
    if (((((*(byte *)(iVar2 + 0x10) & 0x80) == 0) && (iVar4 != DAT_0043756c)) &&
        (*(byte *)(iVar2 + 4) == DAT_00437580)) && ((*(byte *)(iVar2 + 0xd) & 0xf) == 2)) {
      uVar1 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
      if ((uVar1 < *(uint *)(iVar2 + 8)) && (*(uint *)(iVar2 + 8) + uVar1 < 100000)) {
        uVar1 = *(uint *)(DAT_0043453c + 8 +
                         ((uint)*(byte *)(iVar2 + 2) * 0x30 + (uint)*(byte *)(iVar2 + 3)) * 0x18);
        if (uVar1 < *(uint *)(param_1 + 2)) {
          *(uint *)(param_1 + 2) = uVar1;
          *param_1 = *(undefined2 *)(DAT_00434538 + 2 + iVar3);
        }
      }
    }
    iVar3 = iVar3 + 0x224;
    iVar4 = iVar4 + 1;
  } while (iVar3 < 0x8900);
  return *(uint *)(param_1 + 2) < 0x1f0;
}


