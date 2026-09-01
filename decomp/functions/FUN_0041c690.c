/* 0041c690 */

bool __cdecl FUN_0041c690(undefined1 *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int local_8;
  undefined1 local_4;
  
  iVar2 = FUN_0041ec60(100);
  if (iVar2 == 0) {
    return false;
  }
  iVar2 = 0;
  local_8 = 0;
  *(undefined4 *)(param_1 + 4) = 0x1f0;
  do {
    bVar1 = *(byte *)(DAT_0043453c + iVar2 + 0x10);
    if (((((uint)bVar1 - DAT_00437580 != 8) &&
         ((uint)*(byte *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) - (uint)bVar1 != -8)) &&
        (*(uint *)(DAT_0043453c + iVar2 + 8) < *(uint *)(param_1 + 4))) && (bVar1 == 0)) {
      iVar3 = FUN_0041e670(local_8 / 0x30,local_8 % 0x30);
      if (iVar3 == 0) {
        local_4 = (undefined1)(local_8 % 0x30);
        *param_1 = (char)(local_8 / 0x30);
        param_1[1] = local_4;
        *(undefined4 *)(param_1 + 4) = *(undefined4 *)(DAT_0043453c + 8 + iVar2);
      }
    }
    iVar2 = iVar2 + 0x18;
    local_8 = local_8 + 1;
  } while (iVar2 < 0xd800);
  return *(uint *)(param_1 + 4) < 0x1f0;
}


