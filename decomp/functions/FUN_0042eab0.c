/* 0042eab0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042eab0(uint param_1)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = 0;
  puVar2 = &DAT_00435470;
  _DAT_00434858 = param_1;
  do {
    if (*puVar2 == param_1) {
      _DAT_00434854 = *(undefined4 *)(iVar1 * 8 + 0x435474);
      return;
    }
    puVar2 = puVar2 + 2;
    iVar1 = iVar1 + 1;
  } while (puVar2 < &DAT_004355d8);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    _DAT_00434854 = 0xd;
    return;
  }
  if ((0xbb < param_1) && (param_1 < 0xcb)) {
    _DAT_00434854 = 8;
    return;
  }
  _DAT_00434854 = 0x16;
  return;
}


