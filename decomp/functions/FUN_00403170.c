/* 00403170 */

void FUN_00403170(void)

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  bool bVar4;
  byte bVar5;
  int iVar6;
  undefined3 extraout_var;
  int iVar7;
  uint uVar8;
  int iVar9;
  char local_6;
  char local_5;
  undefined4 local_4;
  
  iVar6 = FUN_0041a920();
  if (iVar6 != 0) {
    FUN_00420a40();
    if (*(int *)(DAT_00434538 + 0x18 + DAT_0043756c * 0x224) == 0x1f0) {
      iVar6 = FUN_0041ef80(DAT_0043756c,DAT_0043644c,DAT_00436450);
      if (iVar6 != 1) {
        iVar6 = DAT_0043756c * 0x224 + DAT_00434538;
        switch(*(byte *)(iVar6 + 0xd) & 0xf) {
        case 0:
          *(undefined1 *)(iVar6 + 0xc) = 6;
          return;
        case 1:
        case 3:
          iVar6 = FUN_0040b330();
          if ((iVar6 != 1) && (iVar6 != 6)) {
            *(undefined1 *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) = 6;
            if ((*(byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224) & 8) == 0) {
              iVar6 = FUN_004219b0();
              if ((iVar6 == 0) && (iVar6 = FUN_0041eb60(DAT_0043756c), iVar6 != 0)) {
                FUN_00421ae0();
                return;
              }
            }
            else {
              iVar6 = FUN_0041eb60(DAT_0043756c);
              if (iVar6 != 0) {
                FUN_00421ae0();
                return;
              }
            }
          }
          break;
        case 2:
          *(undefined1 *)(iVar6 + 0xc) = 6;
          FUN_0040b330();
          return;
        case 4:
          iVar9 = FUN_00421910();
          iVar6 = DAT_0043756c;
          if (iVar9 != 1) {
            pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
            iVar9 = DAT_0043756c * 0x224;
            if ((*pbVar1 & 0x80) == 0) {
              if ((*pbVar1 & 0x40) == 0) {
                *pbVar1 = 1;
                iVar7 = FUN_0041e560((char *)&local_4);
                if (iVar7 == 1) {
                  FUN_00405250(iVar6,(int)(char)local_4,(int)local_4._1_1_);
                }
                else {
                  *(undefined1 *)(DAT_00434538 + 0xc + iVar9) = 6;
                }
              }
              else {
                *pbVar1 = 0x10;
              }
              bVar4 = false;
            }
            else {
              bVar4 = true;
            }
            if (bVar4) {
              if (((*(byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224) & 8) == 0) &&
                 (iVar6 = FUN_0041e0a0(&local_6), iVar6 == 1)) {
                FUN_00405250(DAT_0043756c,(int)local_6,(int)local_5);
                return;
              }
              iVar6 = FUN_0041eb60(DAT_0043756c);
              if (iVar6 == 1) {
                iVar9 = FUN_00422290();
                iVar6 = DAT_0043756c;
                if (iVar9 == 0) {
                  iVar9 = DAT_0043756c * 0x224;
                  *(undefined1 *)(DAT_00434538 + 0xd + iVar9) = 1;
                  local_4._0_2_ = local_4._1_2_;
                  iVar7 = FUN_0041e560((char *)&local_4);
                  if (iVar7 == 1) {
                    FUN_00405250(iVar6,(int)(char)local_4,(int)local_4._1_1_);
                    return;
                  }
                  *(undefined1 *)(DAT_00434538 + 0xc + iVar9) = 6;
                  return;
                }
              }
            }
          }
          break;
        case 5:
          iVar6 = FUN_0040b330();
          if (iVar6 == 2) {
            iVar9 = FUN_0041e560(&local_6);
            iVar6 = DAT_0043756c;
            if (iVar9 == 1) {
              FUN_00405250(DAT_0043756c,(int)local_6,(int)local_5);
              return;
            }
            if (*(char *)(DAT_00434534 + 0x1c + DAT_00437580 * 0x38) == '\0') {
              iVar9 = DAT_0043756c * 0x224;
              *(undefined1 *)(DAT_00434538 + 0xd + iVar9) = 1;
              iVar7 = FUN_0041e560((char *)&local_4);
              if (iVar7 == 1) {
                FUN_00405250(iVar6,(int)(char)local_4,(int)local_4._1_1_);
              }
              else {
                *(undefined1 *)(DAT_00434538 + 0xc + iVar9) = 6;
              }
            }
          }
          else if (iVar6 == 6) {
            return;
          }
          iVar9 = DAT_0043756c;
          iVar6 = DAT_0043756c * 0x224;
          pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
          if ((*pbVar1 & 0x80) == 0) {
            if ((*pbVar1 & 0x40) == 0) {
              *pbVar1 = 1;
              iVar7 = FUN_0041e560((char *)&local_4);
              if (iVar7 == 1) {
                FUN_00405250(iVar9,(int)(char)local_4,(int)local_4._1_1_);
              }
              else {
                *(undefined1 *)(DAT_00434538 + 0xc + iVar6) = 6;
              }
            }
            else {
              *pbVar1 = 0x10;
            }
            bVar4 = false;
          }
          else {
            bVar4 = true;
          }
          if (bVar4) {
            iVar6 = FUN_0041ec60(100);
            if (iVar6 == 0) {
              iVar9 = FUN_0041e560(&local_6);
              iVar6 = DAT_0043756c;
              if (iVar9 == 1) {
                FUN_00405250(DAT_0043756c,(int)local_6,(int)local_5);
                return;
              }
              if (*(char *)(DAT_00434534 + 0x1c + DAT_00437580 * 0x38) == '\0') {
                iVar9 = DAT_0043756c * 0x224;
                *(undefined1 *)(DAT_00434538 + 0xd + iVar9) = 1;
                local_4._0_2_ = local_4._1_2_;
                iVar7 = FUN_0041e560((char *)&local_4);
                if (iVar7 == 1) {
                  FUN_00405250(iVar6,(int)(char)local_4,(int)local_4._1_1_);
                  return;
                }
                *(undefined1 *)(DAT_00434538 + 0xc + iVar9) = 6;
                return;
              }
            }
            else {
              if (((*(byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224) & 8) == 0) &&
                 (iVar6 = FUN_0041e1d0(&local_6), iVar6 == 1)) {
                FUN_00405250(DAT_0043756c,(int)local_6,(int)local_5);
                return;
              }
              iVar6 = FUN_0041eb60(DAT_0043756c);
              if (iVar6 != 0) {
                iVar9 = FUN_00421050();
                iVar6 = DAT_0043756c;
                if (iVar9 != 1) {
                  iVar9 = DAT_0043756c * 0x224;
                  *(undefined1 *)(DAT_00434538 + 0xd + iVar9) = 1;
                  local_4._0_2_ = local_4._1_2_;
                  iVar7 = FUN_0041e560((char *)&local_4);
                  if (iVar7 == 1) {
                    FUN_00405250(iVar6,(int)(char)local_4,(int)local_4._1_1_);
                    return;
                  }
                  *(undefined1 *)(DAT_00434538 + 0xc + iVar9) = 6;
                  return;
                }
              }
            }
          }
          break;
        case 6:
          iVar6 = FUN_0040b440();
          if (iVar6 != 2) {
            if (iVar6 == 3) {
              iVar6 = DAT_0043756c * 0x224 + DAT_00434538;
              iVar6 = FUN_004208b0((uint)*(byte *)(iVar6 + 2),(uint)*(byte *)(iVar6 + 3));
              if (iVar6 == 1) {
                return;
              }
            }
            else if (iVar6 == 4) {
              return;
            }
            iVar9 = DAT_0043756c;
            iVar6 = DAT_0043756c * 0x224;
            pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
            if ((*pbVar1 & 0x80) == 0) {
              if ((*pbVar1 & 0x40) != 0) {
                *pbVar1 = 0x10;
                return;
              }
              *pbVar1 = 1;
              local_4._0_2_ = local_4._1_2_;
              iVar7 = FUN_0041e560((char *)&local_4);
              if (iVar7 == 1) {
                FUN_00405250(iVar9,(int)(char)local_4,(int)local_4._1_1_);
                return;
              }
              *(undefined1 *)(DAT_00434538 + 0xc + iVar6) = 6;
              return;
            }
          }
          break;
        case 7:
          iVar9 = FUN_0040b680();
          iVar6 = DAT_0043756c;
          if (iVar9 == 1) {
            pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
            iVar9 = DAT_0043756c * 0x224;
            if ((*pbVar1 & 0x80) == 0) {
              if ((*pbVar1 & 0x40) != 0) {
                *pbVar1 = 0x10;
                return;
              }
              *pbVar1 = 1;
              local_4._0_2_ = local_4._1_2_;
              iVar7 = FUN_0041e560((char *)&local_4);
              if (iVar7 == 1) {
                FUN_00405250(iVar6,(int)(char)local_4,(int)local_4._1_1_);
                return;
              }
              *(undefined1 *)(DAT_00434538 + 0xc + iVar9) = 6;
              return;
            }
          }
          else if ((iVar9 != 2) && (iVar9 != 4)) {
            pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
            iVar9 = DAT_0043756c * 0x224;
            if ((*pbVar1 & 0x80) == 0) {
              if ((*pbVar1 & 0x40) == 0) {
                *pbVar1 = 1;
                iVar7 = FUN_0041e560((char *)&local_4);
                if (iVar7 == 1) {
                  FUN_00405250(iVar6,(int)(char)local_4,(int)local_4._1_1_);
                }
                else {
                  *(undefined1 *)(DAT_00434538 + 0xc + iVar9) = 6;
                }
              }
              else {
                *pbVar1 = 0x10;
              }
              bVar4 = false;
            }
            else {
              bVar4 = true;
            }
            iVar6 = DAT_0043756c;
            if (bVar4) {
              iVar9 = DAT_0043756c * 0x224;
              *(undefined1 *)(DAT_00434538 + 0xd + iVar9) = 1;
              local_4._0_2_ = local_4._1_2_;
              iVar7 = FUN_0041e560((char *)&local_4);
              if (iVar7 == 1) {
                FUN_00405250(iVar6,(int)(char)local_4,(int)local_4._1_1_);
                return;
              }
              *(undefined1 *)(DAT_00434538 + 0xc + iVar9) = 6;
              return;
            }
          }
          break;
        case 8:
          iVar9 = FUN_0040bc20();
          iVar6 = DAT_0043756c;
          if (iVar9 != 4) {
            pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
            iVar9 = DAT_0043756c * 0x224;
            if ((*pbVar1 & 0x80) == 0) {
              if ((*pbVar1 & 0x40) == 0) {
                *pbVar1 = 1;
                iVar7 = FUN_0041e560((char *)&local_4);
                if (iVar7 == 1) {
                  FUN_00405250(iVar6,(int)(char)local_4,(int)local_4._1_1_);
                }
                else {
                  *(undefined1 *)(DAT_00434538 + 0xc + iVar9) = 6;
                }
              }
              else {
                *pbVar1 = 0x10;
              }
              bVar4 = false;
            }
            else {
              bVar4 = true;
            }
            if (bVar4) {
              if (((*(byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224) & 8) == 0) &&
                 (iVar6 = FUN_0041e360(&local_6), iVar6 == 1)) {
                FUN_00405250(DAT_0043756c,(int)local_6,(int)local_5);
                return;
              }
              iVar6 = FUN_0041eb60(DAT_0043756c);
              if (iVar6 == 1) {
                iVar9 = FUN_00422370();
                iVar6 = DAT_0043756c;
                if (iVar9 == 0) {
                  iVar9 = DAT_0043756c * 0x224;
                  *(undefined1 *)(DAT_00434538 + 0xd + iVar9) = 1;
                  local_4._0_2_ = local_4._1_2_;
                  iVar7 = FUN_0041e560((char *)&local_4);
                  if (iVar7 == 1) {
                    FUN_00405250(iVar6,(int)(char)local_4,(int)local_4._1_1_);
                    return;
                  }
                  *(undefined1 *)(DAT_00434538 + 0xc + iVar9) = 6;
                  return;
                }
              }
            }
          }
          break;
        case 9:
          iVar9 = FUN_0040b840();
          iVar6 = DAT_0043756c;
          if (iVar9 != 4) {
            pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
            iVar9 = DAT_0043756c * 0x224;
            if ((*pbVar1 & 0x80) == 0) {
              if ((*pbVar1 & 0x40) == 0) {
                *pbVar1 = 1;
                iVar7 = FUN_0041e560((char *)&local_4);
                if (iVar7 == 1) {
                  FUN_00405250(iVar6,(int)(char)local_4,(int)local_4._1_1_);
                }
                else {
                  *(undefined1 *)(DAT_00434538 + 0xc + iVar9) = 6;
                }
              }
              else {
                *pbVar1 = 0x10;
              }
              bVar4 = false;
            }
            else {
              bVar4 = true;
            }
            if (bVar4) {
              if (((*(byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224) & 8) == 0) &&
                 (iVar6 = FUN_0041e480(&local_6), iVar6 == 1)) {
                FUN_00405250(DAT_0043756c,(int)local_6,(int)local_5);
                FUN_004051b0(DAT_0043756c);
                return;
              }
              iVar6 = FUN_0041eb60(DAT_0043756c);
              if (iVar6 == 1) {
                iVar9 = FUN_00422460();
                iVar6 = DAT_0043756c;
                if (iVar9 == 0) {
                  iVar9 = DAT_0043756c * 0x224;
                  *(undefined1 *)(DAT_00434538 + 0xd + iVar9) = 1;
                  local_4._0_2_ = local_4._1_2_;
                  iVar7 = FUN_0041e560((char *)&local_4);
                  if (iVar7 == 1) {
                    FUN_00405250(iVar6,(int)(char)local_4,(int)local_4._1_1_);
                    return;
                  }
                  *(undefined1 *)(DAT_00434538 + 0xc + iVar9) = 6;
                  return;
                }
              }
            }
          }
          break;
        case 10:
          iVar9 = FUN_0040b960();
          iVar6 = DAT_0043756c;
          if (iVar9 == 1) {
            pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
            iVar9 = DAT_0043756c * 0x224;
            if ((*pbVar1 & 0x80) == 0) {
              if ((*pbVar1 & 0x40) != 0) {
                *pbVar1 = 0x10;
                return;
              }
              *pbVar1 = 1;
              local_4._0_2_ = local_4._1_2_;
              iVar7 = FUN_0041e560((char *)&local_4);
              if (iVar7 == 1) {
                FUN_00405250(iVar6,(int)(char)local_4,(int)local_4._1_1_);
                return;
              }
              *(undefined1 *)(DAT_00434538 + 0xc + iVar9) = 6;
              return;
            }
          }
          else if (iVar9 != 4) {
            pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
            iVar9 = DAT_0043756c * 0x224;
            if ((*pbVar1 & 0x80) == 0) {
              if ((*pbVar1 & 0x40) == 0) {
                *pbVar1 = 1;
                iVar7 = FUN_0041e560((char *)&local_4);
                if (iVar7 == 1) {
                  FUN_00405250(iVar6,(int)(char)local_4,(int)local_4._1_1_);
                }
                else {
                  *(undefined1 *)(DAT_00434538 + 0xc + iVar9) = 6;
                }
              }
              else {
                *pbVar1 = 0x10;
              }
              bVar4 = false;
            }
            else {
              bVar4 = true;
            }
            iVar6 = DAT_0043756c;
            if (bVar4) {
              iVar9 = DAT_0043756c * 0x224;
              *(undefined1 *)(DAT_00434538 + 0xd + iVar9) = 1;
              local_4._0_2_ = local_4._1_2_;
              iVar7 = FUN_0041e560((char *)&local_4);
              if (iVar7 == 1) {
                FUN_00405250(iVar6,(int)(char)local_4,(int)local_4._1_1_);
                return;
              }
              *(undefined1 *)(DAT_00434538 + 0xc + iVar9) = 6;
              return;
            }
          }
          break;
        case 0xb:
          iVar9 = FUN_0040bb10();
          iVar6 = DAT_0043756c;
          if (iVar9 != 4) {
            pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
            iVar9 = DAT_0043756c * 0x224;
            if ((*pbVar1 & 0x80) == 0) {
              if ((*pbVar1 & 0x40) == 0) {
                *pbVar1 = 1;
                iVar7 = FUN_0041e560((char *)&local_4);
                if (iVar7 == 1) {
                  FUN_00405250(iVar6,(int)(char)local_4,(int)local_4._1_1_);
                }
                else {
                  *(undefined1 *)(DAT_00434538 + 0xc + iVar9) = 6;
                }
              }
              else {
                *pbVar1 = 0x10;
              }
              bVar4 = false;
            }
            else {
              bVar4 = true;
            }
            if (bVar4) {
              if (((*(byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224) & 8) == 0) &&
                 (iVar6 = FUN_0041dfb0(&local_6), iVar6 == 1)) {
                FUN_00405250(DAT_0043756c,(int)local_6,(int)local_5);
                FUN_004051b0(DAT_0043756c);
                return;
              }
              iVar6 = FUN_0041eb60(DAT_0043756c);
              if (iVar6 == 1) {
                iVar9 = FUN_00422530();
                iVar6 = DAT_0043756c;
                if (iVar9 == 0) {
                  iVar9 = DAT_0043756c * 0x224;
                  *(undefined1 *)(DAT_00434538 + 0xd + iVar9) = 1;
                  local_4._0_2_ = local_4._1_2_;
                  iVar7 = FUN_0041e560((char *)&local_4);
                  if (iVar7 == 1) {
                    FUN_00405250(iVar6,(int)(char)local_4,(int)local_4._1_1_);
                    return;
                  }
                  *(undefined1 *)(DAT_00434538 + 0xc + iVar9) = 6;
                  return;
                }
              }
            }
          }
          break;
        case 0xc:
          cVar3 = *(char *)(DAT_00434534 + 0x1f + DAT_00437580 * 0x38);
          if (cVar3 == '\x04') {
            FUN_00420aa0(DAT_0043756c,4);
            return;
          }
          *(char *)(iVar6 + 4) = cVar3;
          *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
          break;
        default:
          *(undefined1 *)(iVar6 + 0xc) = 6;
          return;
        }
      }
    }
    else {
      bVar5 = FUN_0041d690(DAT_0043756c);
      pbVar1 = (byte *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224);
      uVar8 = (uint)*pbVar1;
      if (CONCAT31(extraout_var,bVar5) != uVar8) {
        *pbVar1 = bVar5;
        iVar6 = DAT_0043756c * 0x224 + DAT_00434538;
        *(undefined1 *)(iVar6 + 0xe) = *(undefined1 *)(iVar6 + 0xc);
        return;
      }
      FUN_0041d6d0(uVar8,&local_6);
      iVar6 = FUN_0041ec30(DAT_0043644c,DAT_00436450,(int)local_6,(int)local_5);
      if (iVar6 == 0) {
        *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
        *(undefined4 *)(DAT_00434538 + 0x18 + DAT_0043756c * 0x224) = 0x1f0;
        return;
      }
      local_4 = local_6 + DAT_0043644c;
      iVar9 = local_5 + DAT_00436450;
      iVar6 = (local_4 * 0x30 + iVar9) * 0x18;
      if (*(byte *)(DAT_0043453c + 0x10 + iVar6) < 0x30) {
        iVar7 = FUN_00420c60(local_4,iVar9);
        if ((iVar7 != 1) && (iVar7 = FUN_00420610(local_4,iVar9), iVar7 != 1)) {
          if (*(byte *)(DAT_0043453c + iVar6) < 0x40) {
            pcVar2 = (char *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224);
            *pcVar2 = *pcVar2 + -1;
            pcVar2 = (char *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224);
            if (*pcVar2 == '\0') {
              *pcVar2 = '\x01';
              iVar6 = FUN_0041eb60(DAT_0043756c);
              if ((iVar6 != 0) &&
                 (iVar6 = FUN_0041a800(DAT_0043756c,DAT_0043644c,DAT_00436450), iVar6 == 0)) {
                *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
                *(undefined4 *)(DAT_00434538 + 0x18 + DAT_0043756c * 0x224) = 0x1f0;
                return;
              }
            }
          }
          else {
            iVar7 = FUN_004208b0(local_4,iVar9);
            if (iVar7 != 1) {
              *(undefined1 *)(DAT_0043453c + DAT_00437690 * 0x18) = 0x40;
              *(undefined1 *)(DAT_0043453c + iVar6) = (undefined1)DAT_0043756c;
              *(char *)(DAT_00434538 + DAT_0043756c * 0x224) = (char)local_4;
              *(char *)(DAT_00434538 + 1 + DAT_0043756c * 0x224) = (char)iVar9;
              FUN_00405200(DAT_0043756c);
              return;
            }
          }
        }
      }
      else {
        pcVar2 = (char *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224);
        *pcVar2 = *pcVar2 + -1;
        pcVar2 = (char *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224);
        if (*pcVar2 == '\0') {
          *pcVar2 = '\x01';
          iVar6 = FUN_0041eb60(DAT_0043756c);
          if ((iVar6 != 0) &&
             (iVar6 = FUN_0041a800(DAT_0043756c,DAT_0043644c,DAT_00436450), iVar6 == 0)) {
            *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
            *(undefined4 *)(DAT_00434538 + 0x18 + DAT_0043756c * 0x224) = 0x1f0;
            return;
          }
        }
      }
    }
  }
  return;
}


