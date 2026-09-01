/* 0041e670 */

undefined4 __cdecl FUN_0041e670(int param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  
  iVar3 = -1;
  pbVar1 = (byte *)(DAT_0043453c + -0x488 + (param_1 * 0x30 + param_2) * 0x18);
  do {
    iVar2 = -1;
    pbVar4 = pbVar1;
    do {
      if (((uint)*pbVar4 == *(byte *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) + 8) ||
         (DAT_00437580 + 8U == (uint)*pbVar4)) {
        return 1;
      }
      pbVar4 = pbVar4 + 0x480;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 2);
    pbVar1 = pbVar1 + 0x18;
    iVar3 = iVar3 + 1;
    if (1 < iVar3) {
      return 0;
    }
  } while( true );
}


