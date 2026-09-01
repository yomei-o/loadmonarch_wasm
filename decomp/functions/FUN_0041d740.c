/* 0041d740 */

void FUN_0041d740(void)

{
  byte *pbVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  
  DAT_00437690 = DAT_004369fc;
  iVar6 = 0x8f;
  do {
    uVar3 = DAT_00437690;
    DAT_00437690 = DAT_00437690 + 1;
    if (0x8ff < DAT_00437690) {
      DAT_00437690 = uVar3 - 0x8ff;
    }
    pbVar5 = (byte *)(DAT_00437690 * 0x18 + DAT_0043453c);
    pbVar1 = pbVar5 + 0x10;
    DAT_0043756c = (uint)*pbVar5;
    DAT_0043644c = DAT_00437690 / 0x30;
    DAT_00436450 = DAT_00437690 % 0x30;
    uVar3 = (uint)*pbVar1;
    switch(uVar3) {
    case 5:
      DAT_00437580 = 4;
      FUN_0041dec0();
      break;
    case 8:
    case 9:
    case 10:
    case 0xb:
      DAT_00437580 = uVar3 - 8;
      FUN_0041d870();
      break;
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
      DAT_00437580 = uVar3 - 0xc;
      iVar4 = DAT_00437580 * 0x38 + DAT_00434534;
      if ((*(byte *)(iVar4 + 4) & 0x40) != 0) {
        cVar2 = *(char *)(iVar4 + 0x1f);
        if (cVar2 == '\x04') {
          *pbVar1 = 0;
        }
        else {
          *pbVar1 = cVar2 + 0xc;
        }
      }
      break;
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
      DAT_00437580 = uVar3 - 0x14;
      FUN_0041dc60();
    }
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  DAT_004369fc = DAT_00437690;
  return;
}


