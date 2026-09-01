/* 00420a40 */

undefined4 FUN_00420a40(void)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  pbVar2 = (byte *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18);
  uVar3 = (uint)*pbVar2;
  iVar1 = uVar3 - 0xc;
  if ((((iVar1 < 4) && (-1 < iVar1)) && (uVar3 = uVar3 - 0xc, DAT_00437580 != uVar3)) &&
     (*(byte *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) != uVar3)) {
    *pbVar2 = 0;
    return 1;
  }
  return 0;
}


