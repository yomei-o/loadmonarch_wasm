/* 004204f0 */

void FUN_004204f0(void)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0x3f;
  DAT_0043756c = DAT_004377fc;
  DAT_0043451c = 0;
  do {
    uVar1 = DAT_0043756c;
    DAT_0043756c = DAT_0043756c + 1;
    if (0x3f < DAT_0043756c) {
      DAT_0043756c = uVar1 - 0x3f;
    }
    pbVar2 = (byte *)(DAT_0043756c * 0x224 + DAT_00434538);
    if ((pbVar2[0x10] & 0x80) == 0) {
      DAT_00437580 = (uint)pbVar2[4];
      DAT_0043644c = (uint)*pbVar2;
      DAT_00436450 = (uint)pbVar2[1];
      DAT_00437690 = DAT_0043644c * 0x30 + DAT_00436450;
      pbVar2[0x10] = pbVar2[0x10] & 0xfe;
      iVar3 = DAT_0043756c * 0x224 + DAT_00434538;
      if ((*(byte *)(iVar3 + 0x10) & 2) == 0) {
        if (*(char *)(iVar3 + 4) == '\x04') {
          FUN_00402700();
        }
        else if ((*(byte *)(iVar3 + 0xd) & 0x20) == 0) {
          if ((*(byte *)(iVar3 + 0xd) & 0x10) == 0) {
            FUN_00401770();
          }
          else if ((*(byte *)(iVar3 + 0x10) & 4) == 0) {
            FUN_00403170();
          }
          else {
            FUN_00402bc0();
          }
        }
        else {
          FUN_00401000();
        }
      }
      else {
        FUN_00420af0(DAT_0043756c,DAT_0043644c,DAT_00436450);
      }
    }
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  DAT_004377fc = DAT_0043756c;
  return;
}


