/* 0041a8d0 */

undefined4 __cdecl FUN_0041a8d0(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)(DAT_00434534 + 0x18 + DAT_00437580 * 0x38);
  uVar2 = *puVar1;
  if (uVar2 < param_1) {
    if (DAT_004365cd == DAT_00437580) {
      DAT_0043451c = 0xffffffff;
    }
    return 0;
  }
  *puVar1 = uVar2 - param_1;
  return 1;
}


