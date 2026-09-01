/* 00402bc0 */

void FUN_00402bc0(void)

{
  byte *pbVar1;
  char cVar2;
  int iVar3;
  char local_2;
  char local_1;
  
  iVar3 = FUN_0041a920();
  if (iVar3 != 0) {
    FUN_00420a40();
    iVar3 = FUN_0041ef80(DAT_0043756c,DAT_0043644c,DAT_00436450);
    if (iVar3 != 1) {
      iVar3 = DAT_0043756c * 0x224 + DAT_00434538;
      switch(*(byte *)(iVar3 + 0xd) & 0xf) {
      case 0:
        *(undefined1 *)(iVar3 + 0xc) = 6;
        pbVar1 = (byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224);
        *pbVar1 = *pbVar1 & 0xfb;
        return;
      default:
        FUN_00403100(DAT_0043756c);
        return;
      case 4:
        if (((*(byte *)(iVar3 + 0x10) & 8) == 0) && (iVar3 = FUN_0041e0a0(&local_2), iVar3 == 1)) {
          FUN_00405250(DAT_0043756c,(int)local_2,(int)local_1);
          pbVar1 = (byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224);
          *pbVar1 = *pbVar1 & 0xfb;
          return;
        }
        iVar3 = FUN_0041eb60(DAT_0043756c);
        if ((iVar3 == 1) && (iVar3 = FUN_00422290(), iVar3 == 1)) {
          pbVar1 = (byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224);
          *pbVar1 = *pbVar1 & 0xfb;
          return;
        }
        FUN_00403100(DAT_0043756c);
        return;
      case 5:
        iVar3 = FUN_0040b330();
        if (iVar3 != 1) {
          if (iVar3 == 2) {
            if (*(char *)(DAT_00434534 + 0x1c + DAT_00437580 * 0x38) == '\0') {
              FUN_00403100(DAT_0043756c);
              return;
            }
          }
          else if (iVar3 != 6) {
            if (((*(byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224) & 8) == 0) &&
               (iVar3 = FUN_0041e1d0(&local_2), iVar3 == 1)) {
              FUN_00405250(DAT_0043756c,(int)local_2,(int)local_1);
              pbVar1 = (byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224);
              *pbVar1 = *pbVar1 & 0xfb;
              return;
            }
            iVar3 = FUN_0041eb60(DAT_0043756c);
            if ((iVar3 == 1) && (iVar3 = FUN_00421050(), iVar3 == 1)) {
              pbVar1 = (byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224);
              *pbVar1 = *pbVar1 & 0xfb;
              return;
            }
            FUN_00403100(DAT_0043756c);
            return;
          }
        }
        break;
      case 8:
        iVar3 = FUN_0040bc20();
        if (iVar3 != 4) {
          if (((*(byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224) & 8) == 0) &&
             (iVar3 = FUN_0041e360(&local_2), iVar3 == 1)) {
            FUN_00405250(DAT_0043756c,(int)local_2,(int)local_1);
            pbVar1 = (byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224);
            *pbVar1 = *pbVar1 & 0xfb;
            return;
          }
          iVar3 = FUN_0041eb60(DAT_0043756c);
          if ((iVar3 == 1) && (iVar3 = FUN_00422370(), iVar3 == 1)) {
            pbVar1 = (byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224);
            *pbVar1 = *pbVar1 & 0xfb;
            return;
          }
          FUN_00403100(DAT_0043756c);
          return;
        }
        break;
      case 9:
        if (((*(byte *)(iVar3 + 0x10) & 8) == 0) && (iVar3 = FUN_0041e480(&local_2), iVar3 == 1)) {
          FUN_00405250(DAT_0043756c,(int)local_2,(int)local_1);
          pbVar1 = (byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224);
          *pbVar1 = *pbVar1 & 0xfb;
          return;
        }
        iVar3 = FUN_0041eb60(DAT_0043756c);
        if ((iVar3 == 1) && (iVar3 = FUN_00422460(), iVar3 == 1)) {
          pbVar1 = (byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224);
          *pbVar1 = *pbVar1 & 0xfb;
          return;
        }
        FUN_00403100(DAT_0043756c);
        return;
      case 0xb:
        if (((*(byte *)(iVar3 + 0x10) & 8) == 0) && (iVar3 = FUN_0041dfb0(&local_2), iVar3 == 1)) {
          FUN_00405250(DAT_0043756c,(int)local_2,(int)local_1);
          pbVar1 = (byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224);
          *pbVar1 = *pbVar1 & 0xfb;
          return;
        }
        iVar3 = FUN_0041eb60(DAT_0043756c);
        if ((iVar3 == 1) && (iVar3 = FUN_00422530(), iVar3 == 1)) {
          pbVar1 = (byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224);
          *pbVar1 = *pbVar1 & 0xfb;
          return;
        }
        FUN_00403100(DAT_0043756c);
        return;
      case 0xc:
        cVar2 = *(char *)(DAT_00434534 + 0x1f + DAT_00437580 * 0x38);
        if (cVar2 == '\x04') {
          FUN_00420aa0(DAT_0043756c,4);
          return;
        }
        *(char *)(iVar3 + 4) = cVar2;
        *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
        *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 0;
        pbVar1 = (byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224);
        *pbVar1 = *pbVar1 & 0xfb;
      }
    }
  }
  return;
}


