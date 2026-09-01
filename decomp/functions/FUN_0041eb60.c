/* 0041eb60 */

undefined4 __cdecl FUN_0041eb60(int param_1)

{
  byte *pbVar1;
  
  if (DAT_0043781c != 0) {
    DAT_0043781c = DAT_0043781c + -1;
    pbVar1 = (byte *)(DAT_00434538 + 0x10 + param_1 * 0x224);
    *pbVar1 = *pbVar1 & 0xf6;
    return 1;
  }
  pbVar1 = (byte *)(DAT_00434538 + 0x10 + param_1 * 0x224);
  *pbVar1 = *pbVar1 | 9;
  return 0;
}


