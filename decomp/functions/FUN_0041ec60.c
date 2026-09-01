/* 0041ec60 */

undefined4 __cdecl FUN_0041ec60(uint param_1)

{
  byte *pbVar1;
  
  if (*(uint *)(DAT_00434534 + 0x18 + DAT_00437580 * 0x38) < param_1) {
    if (DAT_004365cd == DAT_00437580) {
      DAT_0043451c = 0xffffffff;
      pbVar1 = (byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224);
      *pbVar1 = *pbVar1 | 1;
    }
    return 0;
  }
  return 1;
}


