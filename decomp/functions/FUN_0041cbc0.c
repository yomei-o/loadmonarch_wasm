/* 0041cbc0 */

bool __cdecl FUN_0041cbc0(byte *param_1)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  
  bVar2 = 0;
  param_1[4] = 0xf0;
  param_1[5] = 1;
  param_1[6] = 0;
  param_1[7] = 0;
  do {
    bVar3 = 0;
    do {
      iVar4 = ((uint)bVar3 + (uint)bVar2 * 0x30) * 0x18 + DAT_0043453c;
      if (((uint)*(byte *)(iVar4 + 0x10) - DAT_00437580 == 8) &&
         (uVar1 = *(uint *)(iVar4 + 8), uVar1 < *(uint *)(param_1 + 4))) {
        *(uint *)(param_1 + 4) = uVar1;
        *param_1 = bVar2;
        param_1[1] = bVar3;
      }
      bVar3 = bVar3 + 1;
    } while (bVar3 < 0x30);
    bVar2 = bVar2 + 1;
  } while (bVar2 < 0x30);
  return *(uint *)(param_1 + 4) < 0x1f0;
}


