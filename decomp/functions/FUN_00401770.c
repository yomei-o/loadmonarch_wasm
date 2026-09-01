/* 00401770 */

void FUN_00401770(void)

{
  byte bVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar7;
  int iVar8;
  uint uVar9;
  char local_8;
  char local_7;
  undefined2 local_6;
  int local_4;
  
  iVar6 = FUN_0041a920();
  if (iVar6 != 0) {
    iVar6 = DAT_0043756c * 0x224 + DAT_00434538;
    if ((*(byte *)(iVar6 + 0xd) & 0xf) == 0xc) {
      cVar5 = *(char *)(DAT_00434534 + 0x1f + DAT_00437580 * 0x38);
      if (cVar5 == '\x04') {
        FUN_00420aa0(DAT_0043756c,4);
        return;
      }
      *(char *)(iVar6 + 4) = cVar5;
      *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
      iVar6 = DAT_0043756c * 0x224 + DAT_00434538;
      if (*(byte *)(iVar6 + 4) == DAT_004365cd) {
        *(undefined1 *)(iVar6 + 0xd) = 0;
        return;
      }
    }
    else {
      FUN_00420a40();
      if (((DAT_004365cd == DAT_00437580) ||
          (iVar6 = FUN_0041e700(DAT_0043756c,DAT_0043644c,DAT_00436450), iVar6 != 1)) ||
         (iVar6 = FUN_0041e920(DAT_0043756c,DAT_0043644c,DAT_00436450), iVar6 != 1)) {
        uVar9 = *(byte *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) - 0x14;
        if ((uVar9 < 4) && (DAT_00437580 != uVar9)) {
          *(undefined4 *)(DAT_00434538 + 0x18 + DAT_0043756c * 0x224) = 0x1f0;
          *(undefined1 *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) = 6;
          *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 2;
          FUN_0041ef80(DAT_0043756c,DAT_0043644c,DAT_00436450);
          return;
        }
        if (*(int *)(DAT_00434538 + 0x18 + DAT_0043756c * 0x224) == 0x1f0) {
          iVar6 = FUN_0041ef80(DAT_0043756c,DAT_0043644c,DAT_00436450);
          if (iVar6 != 1) {
            iVar6 = DAT_0043756c * 0x224 + DAT_00434538;
            switch(*(byte *)(iVar6 + 0xd) & 0xf) {
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
              iVar6 = FUN_0040b330();
              if ((iVar6 != 1) && (iVar6 != 6)) {
                uVar9 = *(byte *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) - 0x14;
                if (((int)uVar9 < 0) || (3 < (int)uVar9)) {
                  if (DAT_004365cd != DAT_00437580) {
                    iVar6 = (DAT_0043644c * 0x30 + DAT_00436450) * 0x18 + DAT_0043453c;
                    uVar9 = *(byte *)(iVar6 + -0x20) - 0x14;
                    if (((-1 < (int)uVar9) && ((int)uVar9 < 4)) && (DAT_00437580 != uVar9)) {
                      uVar9 = (uint)*(byte *)(iVar6 + -0x30);
                      if (0x3f < uVar9) {
                        return;
                      }
                      if (*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) <=
                          (uint)(*(int *)(DAT_00434538 + 8 + uVar9 * 0x224) * 3)) {
                        return;
                      }
                      FUN_004215a0(uVar9);
                      return;
                    }
                  }
                }
                else if (DAT_00437580 != uVar9) {
                  return;
                }
                if ((((*(byte *)(DAT_00434538 + 0x10 + DAT_0043756c * 0x224) & 8) != 0) ||
                    (iVar6 = FUN_004219b0(), iVar6 != 1)) &&
                   (iVar6 = FUN_0041eb60(DAT_0043756c), iVar6 == 1)) {
                  FUN_00421ae0();
                  return;
                }
              }
              break;
            case 4:
              iVar6 = FUN_0041e0a0((char *)&local_6);
              if (iVar6 == 0) {
                *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
                iVar6 = FUN_0041e560((char *)&local_6);
                if (iVar6 == 0) {
                  *(undefined1 *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) = 6;
                  return;
                }
              }
              FUN_00405250(DAT_0043756c,(int)(char)local_6,(int)local_6._1_1_);
              return;
            case 5:
              iVar6 = FUN_0040b330();
              if (iVar6 == 1) {
                iVar6 = FUN_0041e1d0((char *)&local_6);
                if (iVar6 == 0) {
                  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
                  iVar6 = FUN_0041e560((char *)&local_6);
                  if (iVar6 == 0) {
                    *(undefined1 *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) = 6;
                    return;
                  }
                }
              }
              else if (iVar6 == 2) {
                *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
                iVar6 = FUN_0041e560((char *)&local_6);
                if (iVar6 == 0) {
                  *(undefined1 *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) = 6;
                  return;
                }
              }
              else if (iVar6 != 6) {
                iVar6 = FUN_0041e560((char *)&local_6);
                if ((iVar6 == 0) && (iVar6 = FUN_0041e1d0((char *)&local_6), iVar6 == 0)) {
                  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
                  iVar6 = FUN_0041e560((char *)&local_6);
                  if (iVar6 == 0) {
                    *(undefined1 *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) = 6;
                    return;
                  }
                }
                FUN_00405250(DAT_0043756c,(int)(char)local_6,(int)local_6._1_1_);
                return;
              }
              break;
            case 6:
              iVar6 = FUN_0040b440();
              if (0 < iVar6) {
                if (iVar6 < 3) {
                  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
                  iVar6 = FUN_0041e560((char *)&local_6);
                  if (iVar6 != 0) {
                    FUN_00405250(DAT_0043756c,(int)(char)local_6,(int)local_6._1_1_);
                    return;
                  }
                  *(undefined1 *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) = 6;
                }
                else if (iVar6 == 4) {
                  return;
                }
              }
              iVar6 = DAT_0043756c * 0x224 + DAT_00434538;
              iVar6 = FUN_004208b0((uint)*(byte *)(iVar6 + 2),(uint)*(byte *)(iVar6 + 3));
              if (iVar6 != 1) {
                *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
                iVar6 = FUN_0041e560((char *)&local_6);
                if (iVar6 == 0) {
                  *(undefined1 *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) = 6;
                  return;
                }
                FUN_00405250(DAT_0043756c,(int)(char)local_6,(int)local_6._1_1_);
                return;
              }
              break;
            case 7:
              iVar6 = FUN_0040b680();
              if (iVar6 != 4) {
                *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
                iVar6 = FUN_0041e560((char *)&local_6);
                if (iVar6 == 0) {
                  *(undefined1 *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) = 6;
                  return;
                }
                FUN_00405250(DAT_0043756c,(int)(char)local_6,(int)local_6._1_1_);
                return;
              }
              break;
            case 8:
              iVar6 = FUN_0040bc20();
              if (iVar6 != 4) {
                bVar1 = *(byte *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18);
                if ((bVar1 != 0) && (4 < (int)(bVar1 - 0xc))) {
                  iVar6 = FUN_0041e360((char *)&local_6);
                  if (iVar6 == 0) {
                    *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
                    iVar6 = FUN_0041e560((char *)&local_6);
                    if (iVar6 == 0) {
                      *(undefined1 *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) = 6;
                      return;
                    }
                  }
                  FUN_00405250(DAT_0043756c,(int)(char)local_6,(int)local_6._1_1_);
                  return;
                }
                iVar6 = FUN_0041e670(DAT_0043644c,DAT_00436450);
                if (iVar6 == 1) {
                  iVar6 = FUN_0041e560((char *)&local_4);
                  uVar2 = local_6;
                  if (iVar6 == 1) {
                    local_6 = (undefined2)local_4;
                    uVar2 = local_6;
                    cVar5 = (char)(undefined2)local_4;
                    local_6._1_1_ = (char)((ushort)(undefined2)local_4 >> 8);
                    local_6 = uVar2;
                    if ((cVar5 == '\x03') || (local_6._1_1_ == '\x03')) {
                      *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
                      iVar6 = (int)local_6._1_1_;
                      FUN_00405250(DAT_0043756c,(int)cVar5,iVar6);
                      return;
                    }
                    if ((int)local_6._1_1_ + (int)cVar5 != 0) {
                      iVar6 = (int)local_6._1_1_;
                      FUN_00405250(DAT_0043756c,(int)cVar5,iVar6);
                      return;
                    }
                  }
                  local_6 = uVar2;
                  iVar6 = FUN_0040b330();
                  if (iVar6 == 1) {
                    return;
                  }
                  if (iVar6 == 6) {
                    return;
                  }
                }
                iVar6 = FUN_0041e360((char *)&local_6);
                if (iVar6 == 0) {
                  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
                  iVar6 = FUN_0041e560((char *)&local_6);
                  if (iVar6 == 0) {
                    *(undefined1 *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) = 6;
                    return;
                  }
                }
                FUN_00405250(DAT_0043756c,(int)(char)local_6,(int)local_6._1_1_);
                return;
              }
              break;
            case 9:
              iVar6 = FUN_0040b840();
              if (iVar6 != 4) {
                *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
                iVar6 = FUN_0041e560((char *)&local_6);
                if (iVar6 == 0) {
                  *(undefined1 *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) = 6;
                  return;
                }
                FUN_00405250(DAT_0043756c,(int)(char)local_6,(int)local_6._1_1_);
                return;
              }
              break;
            case 10:
              iVar6 = FUN_0040b960();
              if (iVar6 == 1) {
                iVar6 = DAT_0043756c * 0x224 + DAT_00434538;
                if (*(int *)(DAT_0043453c + 0xc +
                            ((uint)*(byte *)(iVar6 + 2) * 0x30 + (uint)*(byte *)(iVar6 + 3)) * 0x18)
                    == 0xff) {
                  *(undefined1 *)(iVar6 + 0xd) = 1;
                  iVar6 = FUN_0041e560((char *)&local_6);
                  if (iVar6 == 0) {
                    *(undefined1 *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) = 6;
                    return;
                  }
                  FUN_00405250(DAT_0043756c,(int)(char)local_6,(int)local_6._1_1_);
                  return;
                }
              }
              else if (iVar6 != 4) {
                *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
                iVar6 = FUN_0041e560((char *)&local_6);
                if (iVar6 == 0) {
                  *(undefined1 *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) = 6;
                  return;
                }
                FUN_00405250(DAT_0043756c,(int)(char)local_6,(int)local_6._1_1_);
                return;
              }
              break;
            case 0xb:
              iVar6 = FUN_0040bb10();
              if (iVar6 != 4) {
                *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
                iVar6 = FUN_0041e560((char *)&local_6);
                if (iVar6 == 0) {
                  *(undefined1 *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) = 6;
                  return;
                }
                FUN_00405250(DAT_0043756c,(int)(char)local_6,(int)local_6._1_1_);
                return;
              }
              break;
            case 0xc:
              cVar5 = *(char *)(DAT_00434534 + 0x1f + DAT_00437580 * 0x38);
              if (cVar5 == '\x04') {
                FUN_00420aa0(DAT_0043756c,4);
                return;
              }
              *(char *)(iVar6 + 4) = cVar5;
              *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
              iVar6 = DAT_0043756c * 0x224 + DAT_00434538;
              if (*(byte *)(iVar6 + 4) == DAT_004365cd) {
                *(undefined1 *)(iVar6 + 0xd) = 0;
              }
              break;
            default:
              *(undefined1 *)(iVar6 + 0xc) = 6;
              return;
            }
          }
        }
        else {
          uVar3 = FUN_0041d690(DAT_0043756c);
          iVar6 = DAT_0043756c * 0x224 + DAT_00434538;
          uVar9 = (uint)*(byte *)(iVar6 + 0xc);
          if (CONCAT31(extraout_var,uVar3) == uVar9) {
            FUN_0041d6d0(uVar9,&local_8);
            iVar6 = FUN_0041ec30(DAT_0043644c,DAT_00436450,(int)local_8,(int)local_7);
            if (iVar6 == 0) {
              *(undefined4 *)(DAT_00434538 + 0x18 + DAT_0043756c * 0x224) = 0x1f0;
              *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
              return;
            }
            local_4 = (int)local_8 + DAT_0043644c;
            iVar6 = (int)local_7 + DAT_00436450;
            bVar4 = FUN_0041ebf0(local_4,iVar6);
            if (CONCAT31(extraout_var_00,bVar4) == 0) {
              if (DAT_004365cd != DAT_00437580) {
                cVar5 = *(char *)(DAT_0043453c + 0x10 + (local_4 * 0x30 + iVar6) * 0x18);
                if (cVar5 == 'z') {
                  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 7;
                }
                else {
                  if (cVar5 != '{') {
                    *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
                    goto LAB_00401b21;
                  }
                  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 9;
                }
                *(undefined1 *)(DAT_00434538 + 2 + DAT_0043756c * 0x224) = (undefined1)local_4;
                *(char *)(DAT_00434538 + 3 + DAT_0043756c * 0x224) = (char)iVar6;
              }
LAB_00401b21:
              *(undefined4 *)(DAT_00434538 + 0x18 + DAT_0043756c * 0x224) = 0x1f0;
              return;
            }
            iVar7 = FUN_0041ecc0(DAT_0043756c,DAT_0043644c,DAT_00436450);
            if ((((iVar7 != 1) ||
                 (iVar7 = FUN_0041e920(DAT_0043756c,DAT_0043644c,DAT_00436450), iVar7 != 1)) &&
                (iVar7 = FUN_00420c60(local_4,iVar6), iVar7 != 1)) &&
               (iVar7 = FUN_00420610(local_4,iVar6), iVar7 != 1)) {
              iVar7 = (local_4 * 0x30 + iVar6) * 0x18;
              if (*(byte *)(DAT_0043453c + iVar7) < 0x40) {
                *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
                *(undefined4 *)(DAT_00434538 + 0x18 + DAT_0043756c * 0x224) = 0x1f0;
                return;
              }
              iVar8 = FUN_004208b0(local_4,iVar6);
              if (iVar8 != 1) {
                *(undefined1 *)(DAT_0043453c + (DAT_0043644c * 0x30 + DAT_00436450) * 0x18) = 0x40;
                *(undefined1 *)(DAT_0043453c + iVar7) = (undefined1)DAT_0043756c;
                *(undefined1 *)(DAT_00434538 + DAT_0043756c * 0x224) = (undefined1)local_4;
                *(char *)(DAT_00434538 + 1 + DAT_0043756c * 0x224) = (char)iVar6;
                FUN_00405200(DAT_0043756c);
                return;
              }
            }
          }
          else {
            *(undefined1 *)(iVar6 + 0xe) = uVar3;
            iVar6 = DAT_0043756c * 0x224 + DAT_00434538;
            *(undefined1 *)(iVar6 + 0xc) = *(undefined1 *)(iVar6 + 0xe);
            iVar6 = FUN_0041ecc0(DAT_0043756c,DAT_0043644c,DAT_00436450);
            if (iVar6 == 1) {
              FUN_0041e920(DAT_0043756c,DAT_0043644c,DAT_00436450);
              return;
            }
          }
        }
      }
    }
  }
  return;
}


