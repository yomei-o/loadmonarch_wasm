/* 0041cc30 */

bool __cdecl FUN_0041cc30(undefined1 *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int local_4;
  
  iVar2 = 0;
  local_4 = 0;
  *(undefined4 *)(param_1 + 4) = 0x1f0;
  do {
    iVar3 = DAT_0043453c + iVar2;
    if (*(uint *)(iVar3 + 8) < *(uint *)(param_1 + 4)) {
      bVar1 = *(byte *)(iVar3 + 0x10);
      if ((((7 < bVar1) && (bVar1 < 0xc)) && ((uint)bVar1 - DAT_00437580 != 8)) &&
         ((uint)*(byte *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) - (uint)bVar1 != -8)) {
        *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar3 + 8);
        *param_1 = (char)(local_4 / 0x30);
        param_1[1] = (char)(local_4 % 0x30);
      }
    }
    iVar2 = iVar2 + 0x18;
    local_4 = local_4 + 1;
  } while (iVar2 < 0xd800);
  return *(uint *)(param_1 + 4) < 0x1f0;
}


