/* Ghidra decompilation of DS7E_WIN.EXE - machine output, not the original source. */

/* 00401000  FUN_00401000  1429 bytes, 1 callers */

void FUN_00401000(void)

{
  uint *puVar1;
  byte bVar2;
  int iVar3;
  undefined3 extraout_var;
  int iVar4;
  byte *pbVar5;
  undefined2 *puVar6;
  int iVar7;
  char local_8;
  char local_7;
  char local_6;
  char local_5;
  int local_4;
  
  if ((*(byte *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) - DAT_00437580 != 0x14) &&
     (iVar3 = FUN_0041a920(), iVar3 == 0)) {
    return;
  }
  FUN_004015a0();
  FUN_00420a40();
  if (((DAT_004365cd != DAT_00437580) &&
      (iVar3 = FUN_0041e700(DAT_0043756c,DAT_0043644c,DAT_00436450), iVar3 == 1)) &&
     (iVar3 = FUN_0041e920(DAT_0043756c,DAT_0043644c,DAT_00436450), iVar3 == 1)) {
    return;
  }
  puVar6 = (undefined2 *)(DAT_0043756c * 0x224 + DAT_00434538);
  if (*(int *)(puVar6 + 0xc) == 0x1f0) {
    iVar3 = FUN_0041ef80(DAT_0043756c,DAT_0043644c,DAT_00436450);
    if ((iVar3 != 1) &&
       (*(undefined1 *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) = 6, DAT_004365cd != DAT_00437580
       )) {
      iVar3 = *(byte *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) - DAT_00437580;
      if (iVar3 == 0x14) {
        iVar3 = (DAT_0043644c * 0x30 + DAT_00436450) * 0x18 + DAT_0043453c;
        if ((((0x3f < *(byte *)(iVar3 + 0x18)) && (*(byte *)(iVar3 + 0x28) < 0x30)) &&
            ((iVar3 = FUN_0041eea0(DAT_0043756c,DAT_0043644c,DAT_00436450 + 1), iVar3 != 9 &&
             ((iVar3 = (DAT_0043644c * 0x30 + DAT_00436450) * 0x18 + DAT_0043453c,
              0x3f < *(byte *)(iVar3 + 0x30) && (*(byte *)(iVar3 + 0x40) < 0x30)))))) &&
           ((iVar3 = FUN_0041eea0(DAT_0043756c,DAT_0043644c,DAT_00436450 + 2), iVar3 < 8 ||
            (9 < iVar3)))) {
          FUN_0041d6d0(6,&local_6);
          iVar3 = FUN_0041ec30(DAT_0043644c,DAT_00436450,(int)local_6,(int)local_5);
          if (iVar3 != 0) {
            iVar4 = (int)local_6 + DAT_0043644c;
            iVar7 = (int)local_5 + DAT_00436450;
            iVar3 = (iVar4 * 0x30 + iVar7) * 0x18;
            pbVar5 = (byte *)(DAT_0043453c + iVar3);
            if ((pbVar5[0x10] < 0x30) && (0x3f < *pbVar5)) {
              *(undefined1 *)(DAT_0043453c + DAT_00437690 * 0x18) = 0x40;
              *(undefined1 *)(DAT_0043453c + iVar3) = (undefined1)DAT_0043756c;
              *(char *)(DAT_00434538 + DAT_0043756c * 0x224) = (char)iVar4;
              *(char *)(DAT_00434538 + 1 + DAT_0043756c * 0x224) = (char)iVar7;
              FUN_00405250(DAT_0043756c,-3,-3);
            }
          }
        }
      }
      else {
        if ((iVar3 == 8) && (iVar3 = FUN_0041eb60(DAT_0043756c), iVar3 == 0)) {
          return;
        }
        puVar1 = (uint *)(DAT_00434534 + 4 + DAT_00437580 * 0x38);
        *puVar1 = *puVar1 & 0xffffffdf;
        iVar3 = FUN_00421660();
        if (iVar3 != 1) {
          puVar1 = (uint *)(DAT_00434534 + 4 + DAT_00437580 * 0x38);
          *puVar1 = *puVar1 | 0x20;
          FUN_00422110();
          return;
        }
      }
    }
  }
  else {
    bVar2 = *(byte *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18);
    if (((0x1f < bVar2) && (bVar2 < 0x30)) &&
       (iVar3 = DAT_00437580 * 0x38 + DAT_00434534, (*(byte *)(iVar3 + 4) & 2) != 0)) {
      *(undefined2 *)(iVar3 + 0x20) = *puVar6;
      puVar1 = (uint *)(DAT_00434534 + 4 + DAT_00437580 * 0x38);
      *puVar1 = *puVar1 | 4;
    }
    bVar2 = FUN_0041d690(DAT_0043756c);
    pbVar5 = (byte *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224);
    if ((uint)*pbVar5 != CONCAT31(extraout_var,bVar2)) {
      *pbVar5 = bVar2;
      iVar3 = DAT_0043756c * 0x224 + DAT_00434538;
      *(undefined1 *)(iVar3 + 0xe) = *(undefined1 *)(iVar3 + 0xc);
      return;
    }
    FUN_0041d6d0(CONCAT31(extraout_var,bVar2),&local_8);
    iVar3 = FUN_0041ec30(DAT_0043644c,DAT_00436450,(int)local_8,(int)local_7);
    if (iVar3 == 0) {
      if (DAT_004365cd != DAT_00437580) {
        *(undefined4 *)(DAT_00434538 + 0x18 + DAT_0043756c * 0x224) = 0x1f0;
        return;
      }
    }
    else {
      local_4 = (int)local_8 + DAT_0043644c;
      iVar7 = (int)local_7 + DAT_00436450;
      iVar3 = (local_4 * 0x30 + iVar7) * 0x18;
      if (*(byte *)(DAT_0043453c + 0x10 + iVar3) < 0x30) {
        iVar4 = FUN_00420c60(local_4,iVar7);
        if ((iVar4 != 1) && (iVar4 = FUN_00420610(local_4,iVar7), iVar4 != 1)) {
          if (*(byte *)(DAT_0043453c + iVar3) < 0x40) {
            if (DAT_004365cd != DAT_00437580) {
              *(undefined4 *)(DAT_00434538 + 0x18 + DAT_0043756c * 0x224) = 0x1f0;
              return;
            }
          }
          else {
            iVar4 = FUN_004208b0(local_4,iVar7);
            if (iVar4 != 1) {
              *(undefined1 *)(DAT_0043453c + DAT_00437690 * 0x18) = 0x40;
              *(undefined1 *)(DAT_0043453c + iVar3) = (undefined1)DAT_0043756c;
              *(undefined1 *)(DAT_00434538 + DAT_0043756c * 0x224) = (undefined1)local_4;
              *(char *)(DAT_00434538 + 1 + DAT_0043756c * 0x224) = (char)iVar7;
              FUN_00405200(DAT_0043756c);
              return;
            }
          }
        }
      }
      else if (DAT_004365cd != DAT_00437580) {
        *(undefined4 *)(DAT_00434538 + 0x18 + DAT_0043756c * 0x224) = 0x1f0;
        return;
      }
    }
  }
  return;
}



/* 004015a0  FUN_004015a0  461 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004015a0(void)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  if (*(byte *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) - DAT_00437580 == 0x14) {
    puVar2 = (uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
    uVar6 = *puVar2;
    uVar5 = *(uint *)(DAT_00434534 + 0x10 + DAT_00437580 * 0x38);
    if (uVar5 < uVar6 >> 1) {
      if (0x3f < *(byte *)(DAT_0043453c + 0x18 + (DAT_0043644c * 0x30 + DAT_00436450) * 0x18)) {
        iVar7 = FUN_0041cdc0();
        if ((iVar7 != 0x40) &&
           (uVar6 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 2, uVar6 != 0)) {
          *(uint *)(DAT_00434538 + 8 + iVar7 * 0x224) = uVar6;
          iVar1 = iVar7 * 0x224;
          piVar3 = (int *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
          *piVar3 = *piVar3 - uVar6;
          *(undefined1 *)(DAT_00434538 + 4 + iVar1) = (undefined1)DAT_00437580;
          *(undefined1 *)(DAT_00434538 + iVar1) = (undefined1)DAT_0043644c;
          *(char *)(DAT_00434538 + 1 + iVar1) = (char)DAT_00436450 + '\x01';
          ((undefined2 *)(DAT_00434538 + iVar1))[1] = *(undefined2 *)(DAT_00434538 + iVar1);
          *(undefined1 *)(DAT_00434538 + 0x220 + iVar1) = 0xff;
          *(char *)(DAT_0043453c + 0x18 + (DAT_0043644c * 0x30 + DAT_00436450) * 0x18) = (char)iVar7
          ;
          *(undefined1 *)(DAT_00434538 + 0x10 + iVar1) = 0;
          if ((DAT_004365cd == DAT_00437580) && (_DAT_004365e0 != 1)) {
            pbVar4 = (byte *)(DAT_00434538 + 0x10 + iVar1);
            *pbVar4 = *pbVar4 | 4;
            *(undefined1 *)(DAT_00434538 + 0xd + iVar1) = DAT_004365e0;
            return;
          }
          *(undefined1 *)(DAT_00434538 + 0xd + iVar1) = 1;
        }
      }
    }
    else if (uVar6 < uVar5) {
      uVar6 = (uVar5 - uVar6 >> 3) + uVar6;
      if (99999 < uVar6) {
        *puVar2 = 100000;
        return;
      }
      *puVar2 = uVar6;
      return;
    }
  }
  return;
}



/* 00401770  FUN_00401770  3931 bytes, 1 callers */

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



/* 00402700  FUN_00402700  1216 bytes, 1 callers */

undefined4 FUN_00402700(void)

{
  char *pcVar1;
  byte *pbVar2;
  int *piVar3;
  byte bVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  undefined3 extraout_var;
  char cVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  char local_6;
  char local_5;
  int local_4;
  
  pcVar1 = (char *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224);
  *pcVar1 = *pcVar1 + -1;
  pbVar2 = (byte *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224);
  bVar4 = *pbVar2;
  if ((bVar4 & 0x80) != 0) {
    if ((bVar4 & 0x7f) == 0) {
      iVar6 = FUN_0041abd0(0x14);
      *pbVar2 = (char)iVar6 * '\x02' + 0x14;
      return 0;
    }
    return 0;
  }
  if (bVar4 == 0) {
    iVar6 = FUN_0041abd0(0x14);
    if (iVar6 < 0xb) {
      *(byte *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = (byte)iVar6 | 0x80;
      return 0;
    }
    iVar6 = FUN_0041abd0(0x14);
    *(char *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = (char)iVar6 * '\x02' + '\x14';
    return 0;
  }
  if ((bVar4 & 1) != 0) {
    return 0;
  }
  FUN_00420a40();
  FUN_0041d6d0((uint)*(byte *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224),&local_6);
  local_4 = DAT_0043644c + local_6;
  iVar9 = DAT_00436450 + local_5;
  iVar6 = FUN_0041ec30(DAT_0043644c,DAT_00436450,(int)local_6,(int)local_5);
  if (iVar6 != 0) {
    iVar6 = local_4 * 0x30 + iVar9;
    bVar4 = *(byte *)(DAT_0043453c + 0x10 + iVar6 * 0x18);
    iVar6 = iVar6 * 0x18;
    if ((bVar4 < 0x30) && (bVar4 != 0x1d)) {
      iVar7 = FUN_00420c60(local_4,iVar9);
      if (iVar7 == 1) {
        return 1;
      }
      iVar7 = FUN_00420610(local_4,iVar9);
      if (iVar7 == 1) {
        return 1;
      }
      if (*(byte *)(DAT_0043453c + iVar6) < 0x40) {
        pbVar2 = (byte *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224);
        iVar6 = FUN_0041abd0(100);
        *pbVar2 = (-((uint)(iVar6 < 0x32) + (uint)*pbVar2 == 0) & 0xfcU) + 2 & 7;
        return 1;
      }
      iVar7 = FUN_004208b0(local_4,iVar9);
      if (iVar7 == 1) {
        return 1;
      }
      pcVar1 = (char *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224);
      *pcVar1 = *pcVar1 + -1;
      if (*(char *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) != '\0') {
        *(undefined1 *)(DAT_0043453c + iVar6) = (undefined1)DAT_0043756c;
        *(undefined1 *)(DAT_0043453c + DAT_00437690 * 0x18) = 0x40;
        *(undefined1 *)(DAT_00434538 + DAT_0043756c * 0x224) = (undefined1)local_4;
        *(char *)(DAT_00434538 + 1 + DAT_0043756c * 0x224) = (char)iVar9;
        return 1;
      }
    }
  }
  iVar6 = FUN_0041abd0(10);
  uVar11 = 0;
  *(char *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = (char)iVar6 + '\x01';
  iVar6 = 4;
  uVar10 = *(byte *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) - 4;
  do {
    uVar11 = uVar11 * 2;
    FUN_0041d6d0(uVar10 & 6,&local_6);
    bVar5 = FUN_0041f020(DAT_0043756c,DAT_0043644c,DAT_00436450,&local_6);
    if (CONCAT31(extraout_var,bVar5) == 1) {
      uVar11 = uVar11 | 1;
    }
    uVar10 = uVar10 + 2 & 6;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if (uVar11 == 0) {
    iVar6 = 0;
    cVar8 = '\0';
    do {
      FUN_0041d6d0((uint)*(byte *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) + iVar6 & 7,&local_6);
      iVar9 = FUN_0041ec30(DAT_0043644c,DAT_00436450,(int)local_6,(int)local_5);
      if (iVar9 != 0) {
        if (*(char *)(DAT_0043453c + 0x10 +
                     ((local_6 + DAT_0043644c) * 0x30 + local_5 + DAT_00436450) * 0x18) == '{') {
          pbVar2 = (byte *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224);
          iVar6 = ((local_6 + DAT_0043644c) * 0x30 + local_5 + DAT_00436450) * 0x18;
          *pbVar2 = cVar8 * '\x02' + *pbVar2 & 7;
          piVar3 = (int *)(DAT_0043453c + 0xc + iVar6);
          *piVar3 = *piVar3 + -1;
          piVar3 = (int *)(DAT_0043453c + 0xc + iVar6);
          if (*piVar3 != 0) {
            return 1;
          }
          *piVar3 = 100;
          *(undefined1 *)(DAT_0043453c + 0x10 + iVar6) = 0;
          FUN_0041ad90();
          return 1;
        }
      }
      iVar6 = iVar6 + 2;
      cVar8 = cVar8 + '\x01';
    } while (iVar6 < 8);
    return 1;
  }
  if (uVar11 == 1) {
    cVar8 = '\x02';
  }
  else if (uVar11 == 2) {
    cVar8 = '\0';
  }
  else if (uVar11 == 4) {
    cVar8 = -2;
  }
  else {
    iVar6 = FUN_0041abd0(100);
    cVar8 = '\x02';
    if (0x31 < iVar6) {
      cVar8 = -2;
    }
  }
  pbVar2 = (byte *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224);
  *pbVar2 = *pbVar2 + cVar8 & 6;
  return 1;
}



/* 00402bc0  FUN_00402bc0  1296 bytes, 1 callers */

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



/* 00403100  FUN_00403100  107 bytes, 1 callers */

void __cdecl FUN_00403100(int param_1)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  char local_2;
  char local_1;
  
  iVar1 = param_1 * 0x224;
  pbVar2 = (byte *)(DAT_00434538 + 0x10 + iVar1);
  *pbVar2 = *pbVar2 & 0xfb;
  *(undefined1 *)(DAT_00434538 + 0xd + iVar1) = 1;
  iVar3 = FUN_0041e560(&local_2);
  if (iVar3 == 1) {
    FUN_00405250(param_1,(int)local_2,(int)local_1);
    return;
  }
  *(undefined1 *)(DAT_00434538 + 0xc + iVar1) = 6;
  return;
}



/* 00403170  FUN_00403170  4350 bytes, 1 callers */

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



/* 004042b0  FUN_004042b0  241 bytes, 1 callers */

undefined4 * __fastcall FUN_004042b0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_004043a1;
  *unaff_FS_OFFSET = &local_10;
  FUN_00427770(param_1);
  local_8 = 0;
  *param_1 = &PTR_FUN_00430000;
  wsprintfA((LPSTR)(param_1 + 0x53),s_Code3_00432080);
  wsprintfA((LPSTR)(param_1 + 0x12),s_Graph_Window_00432070);
  param_1[8] = 0xb0;
  param_1[9] = 0xb0;
  iVar1 = GetSystemMetrics(8);
  param_1[7] = param_1[7] + iVar1 * 2;
  iVar1 = GetSystemMetrics(7);
  param_1[6] = param_1[6] + iVar1 * 2;
  wsprintfA((LPSTR)(param_1 + 0x12),s_Graph_Window_00432070);
  iVar1 = param_1[8] + param_1[6];
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = iVar1;
  param_1[0x11] = param_1[9] + param_1[7];
  param_1[10] = param_1[6] * 2 + 0x160;
  param_1[0xb] = 0;
  param_1[0xc] = iVar1;
  param_1[0xd] = param_1[9] + param_1[7];
  param_1[0x9f] = 0;
  param_1[0x9e] = 0x54400000;
  param_1[0x149] = 0;
  DAT_004344ec = param_1;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}



/* 004043c0  FUN_004043c0  30 bytes, 0 callers */

undefined4 * __thiscall FUN_004043c0(void *this,byte param_1)

{
  FUN_004043e0(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 004043e0  FUN_004043e0  116 bytes, 1 callers */

void __fastcall FUN_004043e0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00404454;
  *param_1 = &PTR_FUN_00430000;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0;
  DAT_004344ec = 0;
  puVar1 = (undefined4 *)param_1[0x149];
  if (puVar1 != (undefined4 *)0x0) {
    FUN_004279a0(puVar1);
    FUN_00427f80(puVar1);
    param_1[0x149] = 0;
  }
  local_8 = 0xffffffff;
  FUN_0040445e();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 0040445e  FUN_0040445e  8 bytes, 1 callers */

void FUN_0040445e(void)

{
  int unaff_EBP;
  
  FUN_00427820(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 0040463b  FUN_0040463b  8 bytes, 0 callers */

void FUN_0040463b(void)

{
  int unaff_EBP;
  
  thunk_FUN_0040e460((undefined4 *)(unaff_EBP + -0x10));
  return;
}



/* 00404890  FUN_00404890  206 bytes, 0 callers */

void __thiscall FUN_00404890(void *this,int param_1,int param_2,int param_3,int param_4)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar6 = param_3 + param_2 * 4;
  iVar3 = *(int *)((int)this + iVar6 * 0x14 + 0x3a0);
  iVar6 = *(int *)((int)this + iVar6 * 0x14 + 0x3a4);
  if (param_4 == 0) {
    puVar5 = (undefined4 *)
             ((iVar6 - param_1) * *(int *)((int)this + 0x20) + *(int *)((int)this + 0x25c) + iVar3);
    *puVar5 = 0x70707070;
    puVar5[1] = 0x70707070;
    puVar5[2] = 0x70707070;
    puVar5[3] = 0x70707070;
    return;
  }
  iVar6 = iVar6 - param_1;
  puVar5 = (undefined4 *)(*(int *)((int)this + 0x20) * iVar6 + *(int *)((int)this + 0x25c) + iVar3);
  *puVar5 = 0x70707070;
  puVar5[1] = 0x70707070;
  puVar5[2] = 0x70707070;
  puVar5[3] = 0x70707070;
  if (param_2 == 4) {
    iVar3 = *(int *)((int)this + 0x20) * iVar6 + *(int *)((int)this + 0x25c) + iVar3;
    *(undefined4 *)(iVar3 + 1) = 0x76767676;
    *(undefined4 *)(iVar3 + 5) = 0x76767676;
    *(undefined4 *)(iVar3 + 9) = 0x76767676;
    *(undefined2 *)(iVar3 + 0xd) = 0x7676;
    return;
  }
  cVar2 = (char)param_2 + 'q';
  uVar1 = (undefined2)CONCAT31(CONCAT21(0x7070,cVar2),cVar2);
  uVar4 = CONCAT22(uVar1,uVar1);
  iVar3 = *(int *)((int)this + 0x20) * iVar6 + *(int *)((int)this + 0x25c) + iVar3;
  *(undefined4 *)(iVar3 + 1) = uVar4;
  *(undefined4 *)(iVar3 + 5) = uVar4;
  *(undefined4 *)(iVar3 + 9) = uVar4;
  *(undefined2 *)(iVar3 + 0xd) = uVar1;
  return;
}



/* 00404960  FUN_00404960  719 bytes, 0 callers */

void __thiscall FUN_00404960(void *this,int param_1,int param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  iVar6 = param_3 + param_2 * 4;
  iVar3 = *(int *)((int)this + iVar6 * 0x14 + 0x3a0);
  iVar4 = *(int *)((int)this + iVar6 * 0x14 + 0x3a4);
  uVar8 = (uint)*(byte *)((int)this + iVar6 * 0x14 + 0x39c);
  uVar5 = (DAT_00435b1c & 2) >> 1;
  if (uVar8 == 0xf0) {
    if ((*(byte *)((int)this + iVar6 * 0x14 + 0x39d) & 2) == 0) {
      bVar2 = *(byte *)((int)this + iVar6 * 0x14 + 0x39e);
      if (bVar2 == 0) {
        if (param_1 < 0x15) {
          if (10 < param_1) {
            uVar5 = uVar5 + 2;
          }
        }
        else {
          uVar5 = uVar5 + 4;
        }
      }
      else {
        uVar5 = bVar2 + 5;
        *(byte *)((int)this + iVar6 * 0x14 + 0x39e) = bVar2 - 1;
      }
    }
    else {
      cVar1 = *(char *)((int)this + iVar6 * 0x14 + 0x39e);
      if (cVar1 != '\x04') {
        *(char *)((int)this + iVar6 * 0x14 + 0x39e) = cVar1 + '\x01';
      }
      uVar5 = *(byte *)((int)this + iVar6 * 0x14 + 0x39e) + 5;
    }
    iVar6 = uVar5 << 4;
    iVar9 = 0;
    do {
      iVar10 = DAT_00435fd4 + iVar6;
      iVar6 = iVar6 + 0x100;
      puVar7 = (undefined4 *)
               (((iVar4 - param_1) + iVar9 + -0x10) * *(int *)((int)this + 0x20) +
                *(int *)((int)this + 0x25c) + iVar3);
      iVar9 = iVar9 + 1;
      *puVar7 = *(undefined4 *)(iVar10 + 0x1d000);
      puVar7[1] = *(undefined4 *)(iVar10 + 0x1d004);
      puVar7[2] = *(undefined4 *)(iVar10 + 0x1d008);
      puVar7[3] = *(undefined4 *)(iVar10 + 0x1d00c);
    } while (iVar9 < 0x10);
  }
  else if (uVar8 == 0xf1) {
    if ((*(byte *)((int)this + iVar6 * 0x14 + 0x39d) & 2) == 0) {
      bVar2 = *(byte *)((int)this + iVar6 * 0x14 + 0x39e);
      if (bVar2 == 0) {
        if (param_1 < 0x15) {
          if (10 < param_1) {
            uVar5 = uVar5 + 2;
          }
        }
        else {
          uVar5 = uVar5 + 4;
        }
      }
      else {
        uVar5 = bVar2 + 5;
        *(byte *)((int)this + iVar6 * 0x14 + 0x39e) = bVar2 - 1;
      }
    }
    else {
      cVar1 = *(char *)((int)this + iVar6 * 0x14 + 0x39e);
      if (cVar1 != '\x04') {
        *(char *)((int)this + iVar6 * 0x14 + 0x39e) = cVar1 + '\x01';
      }
      uVar5 = *(byte *)((int)this + iVar6 * 0x14 + 0x39e) + 5;
    }
    iVar6 = uVar5 << 4;
    iVar9 = 0;
    do {
      iVar10 = DAT_00435fd4 + iVar6;
      iVar6 = iVar6 + 0x100;
      puVar7 = (undefined4 *)
               (((iVar4 - param_1) + iVar9 + -0x10) * *(int *)((int)this + 0x20) +
                *(int *)((int)this + 0x25c) + iVar3);
      iVar9 = iVar9 + 1;
      *puVar7 = *(undefined4 *)(iVar10 + 0x1e000);
      puVar7[1] = *(undefined4 *)(iVar10 + 0x1e004);
      puVar7[2] = *(undefined4 *)(iVar10 + 0x1e008);
      puVar7[3] = *(undefined4 *)(iVar10 + 0x1e00c);
    } while (iVar9 < 0x10);
  }
  else if (uVar8 != 0xff) {
    uVar5 = uVar5 + uVar8;
    if ((*(byte *)((int)this + iVar6 * 0x14 + 0x39d) & 2) == 0) {
      bVar2 = *(byte *)((int)this + iVar6 * 0x14 + 0x39e);
      if (bVar2 == 0) {
        if ((param_2 != 4) && (param_3 == 1)) {
          if (param_1 < 0x51) {
            if (0x14 < param_1) {
              uVar5 = uVar5 | 0x20;
            }
          }
          else {
            uVar5 = uVar5 | 0x40;
          }
        }
      }
      else {
        if (param_2 == 4) {
          iVar9 = 0xa8;
        }
        else {
          iVar9 = (-(uint)(param_3 == 0) & 4) + 0xa0;
        }
        *(byte *)((int)this + iVar6 * 0x14 + 0x39e) = bVar2 - 1;
        uVar5 = (uint)bVar2 + param_2 * 8 + -1 + iVar9;
      }
    }
    else {
      iVar9 = 0xa8;
      if (param_2 != 4) {
        iVar9 = (-(uint)(param_3 == 0) & 4) + 0xa0;
      }
      cVar1 = *(char *)((int)this + iVar6 * 0x14 + 0x39e);
      if (cVar1 != '\x04') {
        *(char *)((int)this + iVar6 * 0x14 + 0x39e) = cVar1 + '\x01';
      }
      uVar5 = (uint)*(byte *)((int)this + iVar6 * 0x14 + 0x39e) + param_2 * 8 + -1 + iVar9;
    }
    FUN_004243c0(uVar5,0x10,*(int *)((int)this + 0x20),*(undefined4 *)((int)this + 0x24),
                 (undefined4 *)
                 (((iVar4 - param_1) + -0x10) * *(int *)((int)this + 0x20) +
                  *(int *)((int)this + 0x25c) + iVar3),DAT_00436444);
  }
  puVar7 = (undefined4 *)
           (((iVar4 - param_1) + -0x11) * *(int *)((int)this + 0x20) + *(int *)((int)this + 0x25c) +
           iVar3);
  *puVar7 = 0x70707070;
  puVar7[1] = 0x70707070;
  puVar7[2] = 0x70707070;
  puVar7[3] = 0x70707070;
  return;
}



/* 00404d20  FUN_00404d20  288 bytes, 0 callers */

void __fastcall FUN_00404d20(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x524) != 0) {
    iVar2 = 0x10;
    iVar3 = 0;
    iVar4 = param_1 + 0x528;
    do {
      iVar1 = iVar2 + 0x10;
      FUN_00427a10(*(void **)(param_1 + 0x524),iVar3 + 60000,iVar4,iVar2,0,iVar1,0x40);
      iVar2 = iVar1;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x100;
    } while (iVar1 < 0x90);
    iVar2 = param_1 + 0xd28;
    iVar3 = 0;
    iVar4 = 0x10;
    do {
      iVar1 = iVar4 + 0x10;
      FUN_00427a10(*(void **)(param_1 + 0x524),iVar3 + 0xea68,iVar2,iVar4,0x40,iVar1,0xb0);
      iVar2 = iVar2 + 0x100;
      iVar3 = iVar3 + 1;
      iVar4 = iVar1;
    } while (iVar1 < 0x90);
    FUN_00427a10(*(void **)(param_1 + 0x524),0xea70,param_1 + 0x1528,0x90,0x40,0xa0,0xb0);
  }
  return;
}



/* 00404e40  FUN_00404e40  447 bytes, 0 callers */

void __fastcall FUN_00404e40(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  LPSTR pCVar5;
  char *pcVar6;
  undefined8 uVar7;
  
  if (*(int *)(param_1 + 0x524) != 0) {
    uVar4 = 0;
    pCVar5 = (LPSTR)(param_1 + 0x528);
    do {
      uVar2 = (int)uVar4 >> 0x1f;
      iVar1 = (int)uVar4 / 2;
      if (((uVar4 ^ uVar2) - uVar2 & 1 ^ uVar2) == uVar2) {
        _sprintf(pCVar5,s__s_Area_Occupied__3_2f_004320dc,&DAT_00435b31 + iVar1 * 0x11,
                 (double)*(float *)(DAT_00434534 + 0x34 + iVar1 * 0x38));
      }
      else {
        wsprintfA(pCVar5,s__s_Funds__d_004320f4,&DAT_00435b31 + iVar1 * 0x11);
      }
      pCVar5 = pCVar5 + 0x100;
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 8);
    uVar4 = 0;
    pCVar5 = (LPSTR)(param_1 + 0xd28);
    do {
      uVar2 = (int)uVar4 >> 0x1f;
      iVar1 = (int)uVar4 / 2;
      iVar3 = iVar1 * 0x38 + DAT_00434534;
      if ((*(byte *)(iVar3 + 4) & 0x40) == 0) {
        if (((uVar4 ^ uVar2) - uVar2 & 1 ^ uVar2) == uVar2) {
          uVar7 = CONCAT44(*(undefined4 *)(DAT_00434538 + 8 + *(int *)(iVar3 + 0xc) * 0x224),
                           &DAT_00435b31 + iVar1 * 0x11);
          pcVar6 = s__s_Leader_Strength__d_004320b8;
        }
        else {
          uVar7 = CONCAT44(*(undefined4 *)(iVar3 + 0x10),&DAT_00435b31 + iVar1 * 0x11);
          pcVar6 = s__s_Unit_Totals__d_004320a4;
        }
        wsprintfA(pCVar5,pcVar6,uVar7);
      }
      else {
        wsprintfA(pCVar5,s__s_Defeated_004320d0);
      }
      pCVar5 = pCVar5 + 0x100;
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 8);
    if (*(int *)(DAT_00434534 + 0xf0) == 0) {
      wsprintfA((LPSTR)(param_1 + 0x1528),s__s_Defeated_004320d0);
    }
    else {
      wsprintfA((LPSTR)(param_1 + 0x1528),s__s_Unit_and_Base_Totals__d_00432088,&DAT_00435b75);
    }
    InvalidateRect((HWND)**(undefined4 **)(param_1 + 0x524),(RECT *)0x0,0);
    UpdateWindow((HWND)**(undefined4 **)(param_1 + 0x524));
  }
  return;
}



/* 00405000  FUN_00405000  432 bytes, 18 callers */

undefined4 __cdecl FUN_00405000(int param_1,uint param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  byte *pbVar3;
  undefined3 extraout_var;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint local_c;
  
  if ((0x2e < (int)param_2) || (0x2e < (int)param_3)) {
    return 0;
  }
  local_c = *(uint *)(DAT_0043453c + 8 + (param_2 * 0x30 + param_3) * 0x18);
  if (0x1ef < local_c) {
    return 0;
  }
  iVar4 = param_1 * 0x224;
  *(undefined4 *)(DAT_00434538 + 0x18 + iVar4) = 0x1f0;
  pbVar3 = (byte *)(DAT_00434538 + iVar4);
  if ((*pbVar3 == param_2) && (pbVar3[1] == param_3)) {
    return 10;
  }
  uVar5 = 0;
  pbVar3[0x18] = 0;
  pbVar3[0x19] = 0;
  pbVar3[0x1a] = 0;
  pbVar3[0x1b] = 0;
  *(uint *)(DAT_00434538 + 0x14 + iVar4) = local_c;
  do {
    iVar6 = 0;
    bVar1 = false;
    do {
      uVar7 = param_2 + (int)(char)(&DAT_00434401)[uVar5];
      uVar8 = param_3 + (int)(char)(&DAT_00434411)[uVar5];
      bVar2 = FUN_0041ebb0(uVar7,uVar8);
      if ((CONCAT31(extraout_var,bVar2) == 1) &&
         (*(uint *)(DAT_0043453c + 8 + (uVar7 * 0x30 + uVar8) * 0x18) < local_c)) {
        local_c = *(uint *)(DAT_0043453c + 8 + (uVar7 * 0x30 + uVar8) * 0x18);
        bVar1 = true;
        *(byte *)(DAT_00434538 + local_c + 0x1c + iVar4) =
             *(char *)((char)(&DAT_00434411)[uVar5] * 3 + 0x434434 +
                      (int)(char)(&DAT_00434401)[uVar5]) + 4U & 7;
        param_2 = uVar7;
        param_3 = uVar8;
        break;
      }
      iVar6 = iVar6 + 1;
      uVar5 = uVar5 + 1 & 3;
    } while (iVar6 < 4);
    if (local_c == 0) {
      return 1;
    }
    if (!bVar1) {
      if (local_c == 0) {
        return 1;
      }
      *(undefined4 *)(DAT_00434538 + 0x18 + iVar4) = 0x1f0;
      return 0;
    }
  } while( true );
}



/* 004051b0  FUN_004051b0  65 bytes, 8 callers */

undefined4 __cdecl FUN_004051b0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = DAT_00434538 + param_1 * 0x224;
  if (*(int *)(iVar2 + 0x18) == 0x1f0) {
    return 0;
  }
  piVar1 = (int *)(iVar2 + 0x14);
  *piVar1 = *piVar1 + -1;
  iVar2 = DAT_00434538 + param_1 * 0x224;
  if (*(int *)(iVar2 + 0x14) < 1) {
    *(undefined4 *)(iVar2 + 0x18) = 0x1f0;
    return 0;
  }
  return 1;
}



/* 00405200  FUN_00405200  76 bytes, 3 callers */

undefined4 __cdecl FUN_00405200(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(DAT_00434538 + 0x18 + param_1 * 0x224);
  iVar2 = *piVar1;
  if (iVar2 == 0x1f0) {
    return 0;
  }
  *piVar1 = iVar2 + 1;
  iVar2 = DAT_00434538 + param_1 * 0x224;
  if (*(uint *)(iVar2 + 0x14) <= *(uint *)(iVar2 + 0x18)) {
    *(undefined4 *)(iVar2 + 0x18) = 0x1f0;
    return 0;
  }
  return 1;
}



/* 00405250  FUN_00405250  219 bytes, 6 callers */

void __cdecl FUN_00405250(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int local_10 [4];
  
  local_10[1] = 1;
  local_10[0] = 0;
  local_10[2] = 2;
  local_10[3] = 3;
  *(undefined4 *)(DAT_00434538 + 0x18 + param_1 * 0x224) = 0;
  iVar1 = param_1 * 0x224;
  *(int *)(DAT_00434538 + 0x14 + iVar1) = local_10[param_3] + local_10[param_2];
  iVar2 = (char)(&DAT_00434130)[param_2 + param_3 * 7] * 3;
  *(undefined *)(DAT_00434538 + 0x1c + iVar1) =
       (&DAT_00434150)[(char)(&DAT_00434130)[param_2 + param_3 * 7] * 3];
  *(undefined *)(DAT_00434538 + 0x1d + iVar1) = (&DAT_00434151)[iVar2];
  *(undefined *)(DAT_00434538 + 0x1e + iVar1) = (&DAT_00434152)[iVar2];
  *(char *)(DAT_00434538 + 2 + iVar1) = (char)DAT_0043644c + (char)param_2;
  *(char *)(DAT_00434538 + 3 + iVar1) = (char)DAT_00436450 + (char)param_3;
  return;
}



/* 00405330  FUN_00405330  48 bytes, 7 callers */

void FUN_00405330(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = DAT_0043453c + iVar2;
    *(undefined1 *)(iVar1 + 5) = 1;
    if (*(byte *)(iVar1 + 0x10) < 0x30) {
      *(undefined1 *)(iVar1 + 5) = 0;
    }
    iVar2 = iVar2 + 0x18;
  } while (iVar2 < 0xd800);
  return;
}



/* 00405360  FUN_00405360  43 bytes, 7 callers */

void FUN_00405360(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = DAT_0043453c + iVar2;
    iVar2 = iVar2 + 0x18;
    *(undefined1 *)(iVar1 + 4) = *(undefined1 *)(iVar1 + 5);
    *(undefined4 *)(DAT_0043453c + -0x10 + iVar2) = 0x1f0;
  } while (iVar2 < 0xd800);
  return;
}



/* 00405390  FUN_00405390  154 bytes, 1 callers */

void __cdecl FUN_00405390(byte param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  do {
    uVar3 = (uint)*(byte *)(DAT_0043453c + iVar2 + 0x10);
    switch(uVar3) {
    case 8:
    case 9:
    case 10:
    case 0xb:
      if (uVar3 - param_1 != 8) {
        iVar1 = *(byte *)(DAT_00434534 + 0x1e + (uint)param_1 * 0x38) - uVar3;
joined_r0x00405410:
        if (iVar1 != -8) {
          *(undefined1 *)(DAT_0043453c + iVar2 + 4) = 1;
        }
      }
      break;
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
      if (uVar3 - param_1 != 0xc) {
        iVar1 = *(byte *)(DAT_00434534 + 0x1e + (uint)param_1 * 0x38) - uVar3;
        goto joined_r0x00405410;
      }
    }
    iVar2 = iVar2 + 0x18;
    if (0xd7ff < iVar2) {
      return;
    }
  } while( true );
}



/* 00405440  FUN_00405440  206 bytes, 1 callers */

void __cdecl FUN_00405440(int param_1)

{
  bool bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int local_8;
  
  iVar2 = 0;
  local_8 = 0;
  do {
    if (((local_8 != param_1) &&
        (pbVar3 = (byte *)(DAT_00434538 + iVar2), (pbVar3[0x10] & 0x80) == 0)) &&
       (*(int *)(pbVar3 + 0x18) == 0x1f0)) {
      bVar1 = false;
      iVar4 = param_1 * 0x224 + DAT_00434538;
      if ((*(byte *)(DAT_00434534 + 0x1e + (uint)*(byte *)(iVar4 + 4) * 0x38) == pbVar3[4]) ||
         ((pbVar3[4] == *(byte *)(iVar4 + 4) &&
          (100000 < (uint)(*(int *)(pbVar3 + 8) + *(int *)(iVar4 + 8)))))) {
        bVar1 = true;
      }
      if (bVar1) {
        *(undefined1 *)(DAT_0043453c + 4 + ((uint)*pbVar3 * 0x30 + (uint)pbVar3[1]) * 0x18) = 1;
      }
    }
    iVar2 = iVar2 + 0x224;
    local_8 = local_8 + 1;
  } while (iVar2 < 0x8900);
  return;
}



/* 00405510  FUN_00405510  478 bytes, 3 callers */

void __cdecl FUN_00405510(int param_1)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8;
  
  iVar6 = 0;
  local_8 = 0;
  do {
    if (((local_8 != param_1) &&
        (pbVar2 = (byte *)(DAT_00434538 + iVar6), (pbVar2[0x10] & 0x80) == 0)) &&
       (*(int *)(pbVar2 + 0x18) == 0x1f0)) {
      iVar3 = 0;
      iVar5 = param_1 * 0x224 + DAT_00434538;
      if (*(byte *)(DAT_00434534 + 0x1e + (uint)*(byte *)(iVar5 + 4) * 0x38) == pbVar2[4]) {
        iVar3 = 1;
      }
      else if (pbVar2[4] == *(byte *)(iVar5 + 4)) {
        if (100000 < (uint)(*(int *)(pbVar2 + 8) + *(int *)(iVar5 + 8))) {
          iVar3 = 1;
        }
      }
      else if ((uint)*(byte *)(DAT_0043453c + 0x10 + ((uint)*pbVar2 * 0x30 + (uint)pbVar2[1]) * 0x18
                              ) - (uint)pbVar2[4] == 0x14) {
        iVar4 = 2;
        if ((pbVar2[0xd] & 0x20) != 0) {
          iVar4 = 4;
        }
        if ((99999 < (uint)(*(int *)(pbVar2 + 8) * iVar4)) ||
           (*(uint *)(iVar5 + 8) < (uint)(*(int *)(pbVar2 + 8) * iVar4))) {
LAB_00405608:
          iVar3 = 4;
        }
      }
      else {
        uVar1 = *(uint *)(pbVar2 + 8);
        if ((0xcccc < uVar1) || (*(uint *)(iVar5 + 8) < (uVar1 >> 2) + uVar1)) goto LAB_00405608;
      }
      if (iVar3 != 0) {
        if (iVar3 == 1) {
          *(undefined1 *)(DAT_0043453c + 4 + ((uint)*pbVar2 * 0x30 + (uint)pbVar2[1]) * 0x18) = 1;
        }
        else {
          *(undefined1 *)(DAT_0043453c + -0x14 + ((uint)*pbVar2 * 0x30 + (uint)pbVar2[1]) * 0x18) =
               1;
          *(undefined1 *)
           (DAT_0043453c + 0x1c +
           ((uint)*(byte *)(DAT_00434538 + iVar6) * 0x30 + (uint)((byte *)(DAT_00434538 + iVar6))[1]
           ) * 0x18) = 1;
          *(undefined1 *)
           (DAT_0043453c + -0x47c +
           ((uint)*(byte *)(DAT_00434538 + iVar6) * 0x30 + (uint)((byte *)(DAT_00434538 + iVar6))[1]
           ) * 0x18) = 1;
          *(undefined1 *)
           (DAT_0043453c + 0x484 +
           ((uint)*(byte *)(DAT_00434538 + iVar6) * 0x30 + (uint)((byte *)(DAT_00434538 + iVar6))[1]
           ) * 0x18) = 1;
        }
      }
    }
    iVar6 = iVar6 + 0x224;
    local_8 = local_8 + 1;
    if (0x88ff < iVar6) {
      return;
    }
  } while( true );
}



/* 004056f0  FUN_004056f0  71 bytes, 4 callers */

void __cdecl FUN_004056f0(byte *param_1)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = ((uint)*param_1 * 0x30 + (uint)param_1[1]) * 0x18 + DAT_0043453c;
  bVar1 = *(byte *)(iVar2 + 0x10);
  if (bVar1 == 0x7a) {
    *(undefined1 *)(iVar2 + 4) = 0;
    return;
  }
  if (bVar1 == 0x7b) {
    *(undefined1 *)(iVar2 + 4) = 0;
    return;
  }
  if (bVar1 - 0x30 < 0x30) {
    *(undefined1 *)(iVar2 + 4) = 0;
  }
  return;
}



/* 00405740  FUN_00405740  72 bytes, 3 callers */

void __cdecl FUN_00405740(int param_1,int param_2,undefined1 *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  do {
    cVar1 = *(char *)(param_1 + iVar2);
    if ((cVar1 == '.') || (cVar1 == '\0')) break;
    *(char *)(param_2 + iVar2) = cVar1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xff);
  *(undefined1 *)(param_2 + iVar2) = 0x2e;
  iVar3 = iVar2 + 3;
  *(undefined1 *)(param_2 + -2 + iVar3) = *param_3;
  *(undefined1 *)(param_2 + -1 + iVar3) = param_3[1];
  *(undefined1 *)(param_2 + iVar3) = param_3[2];
  *(undefined1 *)(iVar2 + 4 + param_2) = 0;
  return;
}



/* 00405790  FUN_00405790  25 bytes, 3 callers */

void __cdecl FUN_00405790(undefined4 param_1,LPSTR param_2)

{
  wsprintfA(param_2,&DAT_00432100,param_1);
  return;
}



/* 004057b0  FUN_004057b0  26 bytes, 1 callers */

void FUN_004057b0(void)

{
  FUN_00425080(DAT_00436460,s_Cnfig_00432104,(LPBYTE)&DAT_00437698,0x20,3);
  return;
}



/* 004057d0  FUN_004057d0  26 bytes, 1 callers */

void FUN_004057d0(void)

{
  FUN_00425050(DAT_00436460,s_Cnfig_00432104,(BYTE *)&DAT_00437698,0x20,3);
  return;
}



/* 004057f0  FUN_004057f0  111 bytes, 2 callers */

undefined4 FUN_004057f0(void)

{
  int iVar1;
  CHAR local_208 [260];
  CHAR local_104 [260];
  
  FUN_00405790(s_Score_v11_0043210c,local_208);
  iVar1 = FUN_0040bda0(&DAT_00436468,local_104,local_208);
  if (iVar1 != 0) {
    iVar1 = FUN_0040c0d0(local_104,&DAT_00436a00,0xb68);
    if (iVar1 != 0) {
      DAT_004376b5 = 1;
      return 1;
    }
  }
  return 0;
}



/* 00405860  FUN_00405860  146 bytes, 2 callers */

undefined4 FUN_00405860(void)

{
  int iVar1;
  undefined4 *puVar2;
  CHAR local_208 [260];
  CHAR local_104 [260];
  
  FUN_00405790(s_Score_v11_0043210c,local_208);
  iVar1 = FUN_0040bda0(&DAT_00436468,local_104,local_208);
  if (iVar1 == 0) {
    puVar2 = &DAT_00436a00;
    for (iVar1 = 0x2da; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    return 0;
  }
  iVar1 = FUN_0040c010(local_104,&DAT_00436a00,0xb68);
  if (iVar1 == 0) {
    puVar2 = &DAT_00436a00;
    for (iVar1 = 0x2da; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    return 0;
  }
  FUN_0041b240();
  return 1;
}



/* 00405900  FUN_00405900  624 bytes, 2 callers */

undefined4 __cdecl FUN_00405900(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_494 [544];
  undefined1 local_274 [260];
  CHAR local_170 [260];
  undefined4 local_6c [19];
  undefined4 local_20 [3];
  undefined4 local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00405b78;
  *unaff_FS_OFFSET = &local_10;
  iVar1 = FUN_00405860();
  if (iVar1 != 0) {
    FUN_0041f8b0((int)local_494);
    local_8 = 0;
    FUN_00405740(param_1,(int)local_274,&DAT_0043211c);
    FUN_0040bda0(&DAT_00436468,local_170,local_274);
    iVar1 = FUN_0040c010(local_170,local_6c,0x4c);
    if (iVar1 == 0) {
      local_8 = 0xffffffff;
      FUN_00405b82();
    }
    else {
      puVar3 = local_6c;
      puVar4 = &DAT_004365a0;
      for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      DAT_004365d4 = 0;
      DAT_004365dc = 0;
      DAT_004321c8 = 0;
      if (DAT_004365d0 == 0) {
        DAT_00434510 = 0xffffffff;
        local_14 = FUN_00405de0(DAT_004365a0);
        local_8 = 0xffffffff;
        FUN_00405b82();
        goto LAB_0040592c;
      }
      uVar2 = 3000;
      if (((int)DAT_004365a0 <= DAT_00436a00) && (DAT_004365a0 != 0)) {
        uVar2 = *(int *)(&DAT_004369d4 + DAT_004365a0 * 0x38) + 3000;
      }
      if (uVar2 < DAT_004365c8) {
        DAT_004365c4 = 0;
      }
      else {
        DAT_004365c4 = uVar2 - DAT_004365c8;
      }
      FUN_00425bd0(local_20);
      local_8._0_1_ = 1;
      puVar3 = (undefined4 *)FUN_00425c00(local_20,0x16218);
      if (puVar3 == (undefined4 *)0x0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00405b41();
        local_8 = 0xffffffff;
        FUN_00405b82();
      }
      else {
        FUN_00405740(param_1,(int)local_274,&DAT_00432118);
        FUN_0040bda0(&DAT_00436468,local_170,local_274);
        iVar1 = FUN_0040c010(local_170,puVar3,0x16218);
        if (iVar1 != 0) {
          puVar4 = puVar3;
          puVar5 = DAT_00434534;
          for (iVar1 = 0x46; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
          puVar4 = puVar3 + 0x46;
          puVar5 = DAT_0043453c;
          for (iVar1 = 0x3600; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
          puVar3 = puVar3 + 0x3646;
          puVar4 = DAT_00434538;
          for (iVar1 = 0x2240; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar4 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar4 = puVar4 + 1;
          }
          DAT_0043450c = DAT_004365a0;
          DAT_00434514 = 0xffffffff;
          FUN_00405fc0(DAT_004365a4);
          FUN_00427210();
          FUN_004084e0(DAT_004344e4);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00405b41();
          local_8 = 0xffffffff;
          FUN_00405b82();
          local_14 = 1;
          goto LAB_0040592c;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00405b41();
        local_8 = 0xffffffff;
        FUN_00405b82();
      }
    }
  }
  local_14 = 0;
LAB_0040592c:
  *unaff_FS_OFFSET = local_10;
  return local_14;
}



/* 00405b41  FUN_00405b41  8 bytes, 1 callers */

void FUN_00405b41(void)

{
  int unaff_EBP;
  
  FUN_00425be0((int *)(unaff_EBP + -0x1c));
  return;
}



/* 00405b82  FUN_00405b82  11 bytes, 1 callers */

void FUN_00405b82(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x490));
  return;
}



/* 00405b90  FUN_00405b90  558 bytes, 2 callers */

undefined4 __cdecl FUN_00405b90(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_448 [544];
  undefined1 local_228 [260];
  CHAR local_124 [260];
  undefined4 local_20 [3];
  undefined4 *local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00405dc6;
  *unaff_FS_OFFSET = &local_10;
  iVar1 = FUN_004057f0();
  if (iVar1 != 0) {
    FUN_0041f8b0((int)local_448);
    local_8 = 0;
    FUN_00405740(param_1,(int)local_228,&DAT_0043211c);
    FUN_0040bda0(&DAT_00436468,local_124,local_228);
    DAT_004365a0 = DAT_0043450c;
    GetLocalTime((LPSYSTEMTIME)&DAT_004365ac);
    iVar1 = FUN_0040c0d0(local_124,&DAT_004365a0,0x4c);
    if (iVar1 == 0) {
      local_8 = 0xffffffff;
      FUN_00405dd0();
    }
    else {
      if ((DAT_004365d0 != -1) || (DAT_004365d4 != 0)) {
        local_8 = 0xffffffff;
        FUN_00405dd0();
        uVar2 = 1;
        goto LAB_00405bbc;
      }
      FUN_00425bd0(local_20);
      local_8._0_1_ = 1;
      local_14 = (undefined4 *)FUN_00425c00(local_20,0x16218);
      if (local_14 == (undefined4 *)0x0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00405da8();
        local_8 = 0xffffffff;
        FUN_00405dd0();
      }
      else {
        puVar3 = DAT_00434534;
        puVar4 = local_14;
        for (iVar1 = 0x46; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
        puVar3 = DAT_0043453c;
        puVar4 = local_14 + 0x46;
        for (iVar1 = 0x3600; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
        puVar3 = DAT_00434538;
        puVar4 = local_14 + 0x3646;
        for (iVar1 = 0x2240; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
        FUN_00405740(param_1,(int)local_228,&DAT_00432118);
        FUN_0040bda0(&DAT_00436468,local_124,local_228);
        iVar1 = FUN_0040c0d0(local_124,local_14,0x16218);
        if (iVar1 != 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00405da8();
          local_8 = 0xffffffff;
          FUN_00405dd0();
          uVar2 = 1;
          goto LAB_00405bbc;
        }
        if (DAT_00434530 == 0x70) {
          FUN_00405740(param_1,(int)local_228,&DAT_0043211c);
          FUN_0040bda0(&DAT_00436468,local_124,local_228);
          FUN_0040c3d0(local_124);
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00405da8();
        local_8 = 0xffffffff;
        FUN_00405dd0();
      }
    }
  }
  uVar2 = 0;
LAB_00405bbc:
  *unaff_FS_OFFSET = local_10;
  return uVar2;
}



/* 00405da8  FUN_00405da8  8 bytes, 1 callers */

void FUN_00405da8(void)

{
  int unaff_EBP;
  
  FUN_00425be0((int *)(unaff_EBP + -0x1c));
  return;
}



/* 00405dd0  FUN_00405dd0  11 bytes, 1 callers */

void FUN_00405dd0(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x444));
  return;
}



/* 00405de0  FUN_00405de0  449 bytes, 6 callers */

undefined4 __cdecl FUN_00405de0(uint param_1)

{
  undefined1 *puVar1;
  bool bVar2;
  LPVOID pvVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined3 extraout_var;
  int iVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  bool bVar8;
  CHAR local_340 [260];
  undefined2 local_23c [272];
  int local_1c [3];
  undefined4 local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00405fa9;
  *unaff_FS_OFFSET = &local_10;
  if (((int)param_1 < 0) || (DAT_004376cc < param_1)) {
    param_1 = DAT_004376cc;
  }
  if (DAT_004376cc == param_1) {
    param_1 = DAT_004376cc - 1;
  }
  DAT_004321c8 = 0;
  DAT_0043450c = param_1;
  DAT_004365a0 = param_1;
  FUN_0041f8b0((int)local_23c);
  local_8 = 0;
  FUN_00425bd0(local_1c);
  local_8._0_1_ = 1;
  pvVar3 = (LPVOID)FUN_00425c00(local_1c,0x902);
  if (pvVar3 == (LPVOID)0x0) {
    local_8 = (uint)local_8._1_3_ << 8;
  }
  else {
    pcVar5 = FUN_0041a620(&DAT_004376c8,DAT_0043450c);
    bVar8 = false;
    FUN_00409490(local_340,&DAT_00432120,pcVar5);
    bVar2 = FUN_0041f9f0(local_23c,local_340);
    if (CONCAT31(extraout_var,bVar2) != 0) {
      iVar6 = FUN_0041fa80(local_23c,pvVar3,0x902,0);
      bVar8 = iVar6 != 0;
      FUN_0041fa40(local_23c);
    }
    if (bVar8) {
      iVar6 = 0;
      iVar7 = 0;
      do {
        puVar1 = (undefined1 *)(iVar6 + (int)pvVar3);
        iVar7 = iVar7 + 0x18;
        iVar6 = iVar6 + 1;
        *(undefined1 *)(DAT_0043453c + -8 + iVar7) = *puVar1;
        *(undefined4 *)(DAT_0043453c + -0xc + iVar7) = 100;
        *(undefined1 *)(DAT_0043453c + -0x18 + iVar7) = 0x40;
      } while (iVar7 < 0xd800);
      DAT_004365a4 = (uint)*(byte *)((int)pvVar3 + 0x900);
      FUN_00425c80(local_1c);
      FUN_00425c20(local_1c);
      iVar6 = FUN_00405fc0(DAT_004365a4);
      if (iVar6 != 0) {
        DAT_00434510 = param_1;
        FUN_004271e0();
        FUN_004084e0(DAT_004344e4);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00405fa1();
        local_8 = 0xffffffff;
        FUN_00405fb3();
        uVar4 = 1;
        goto LAB_00405e7c;
      }
      local_8 = (uint)local_8._1_3_ << 8;
    }
    else {
      local_8 = (uint)local_8._1_3_ << 8;
    }
  }
  FUN_00405fa1();
  local_8 = 0xffffffff;
  FUN_00405fb3();
  uVar4 = 0;
LAB_00405e7c:
  *unaff_FS_OFFSET = local_10;
  return uVar4;
}



/* 00405fa1  FUN_00405fa1  8 bytes, 1 callers */

void FUN_00405fa1(void)

{
  int unaff_EBP;
  
  FUN_00425be0((int *)(unaff_EBP + -0x18));
  return;
}



/* 00405fb3  FUN_00405fb3  11 bytes, 1 callers */

void FUN_00405fb3(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x238));
  return;
}



/* 00405fc0  FUN_00405fc0  1540 bytes, 2 callers */

undefined4 __cdecl FUN_00405fc0(int param_1)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  char *pcVar6;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  char *pcVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *unaff_FS_OFFSET;
  CHAR local_268 [256];
  CHAR local_168 [260];
  char local_64 [24];
  undefined4 local_4c;
  char acStack_25 [9];
  int local_1c [3];
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_004065c4;
  *unaff_FS_OFFSET = &local_10;
  SendMessageA(DAT_004344d4,0x111,0x9c5e,0);
  if (DAT_004365a4 != -1) {
    iVar4 = FUN_0040cdc0(0);
    if (iVar4 - param_1 != 2) {
      FUN_0040cd20(&DAT_00435db0,param_1 + 2,0);
    }
    if (param_1 != DAT_00434514) {
      DAT_00434510 = DAT_0043450c;
      DAT_00434514 = param_1;
      DAT_004365a4 = param_1;
      FUN_00425bd0(local_1c);
      local_8 = 0;
      pbVar5 = (byte *)FUN_00425c00(local_1c,0x8030);
      if (pbVar5 == (byte *)0x0) {
        local_8 = 0xffffffff;
        FUN_004065ce();
        uVar3 = 0;
        goto LAB_00406007;
      }
      wsprintfA(local_268,s_B__03ds_bz_0043218c,param_1);
      FUN_00409490(local_168,&DAT_00432188,local_268);
      bVar2 = FUN_00406640(pbVar5,DAT_0043645c,local_168,8);
      if (CONCAT31(extraout_var,bVar2) == 0) {
        wsprintfA(local_168,s__s___No_Files_found__00432170,local_268);
        FUN_00409370(local_168,0);
        local_8 = 0xffffffff;
        FUN_004065ce();
        uVar3 = 0;
        goto LAB_00406007;
      }
      wsprintfA(local_268,s_B__03dm_bz_00432164,param_1);
      FUN_00409490(local_168,&DAT_00432188,local_268);
      bVar2 = FUN_00406640(pbVar5,DAT_00436458,local_168,0x10);
      if (CONCAT31(extraout_var_00,bVar2) == 0) {
        wsprintfA(local_168,s__s___No_Files_found__00432170,local_268);
        FUN_00409370(local_168,0);
        local_8 = 0xffffffff;
        FUN_004065ce();
        uVar3 = 0;
        goto LAB_00406007;
      }
      wsprintfA(local_268,s_B__03dl_bz_00432158,param_1);
      FUN_00409490(local_168,&DAT_00432188,local_268);
      bVar2 = FUN_00406640(pbVar5,DAT_00436454,local_168,0x20);
      if (CONCAT31(extraout_var_01,bVar2) == 0) {
        wsprintfA(local_168,s__s___No_Files_found__00432170,local_268);
        FUN_00409370(local_168,0);
        local_8 = 0xffffffff;
        FUN_004065ce();
        uVar3 = 0;
        goto LAB_00406007;
      }
      FUN_004065e0(0x10,0x10,(int)pbVar5);
      iVar4 = 0x10;
      pbVar8 = pbVar5 + 0x8000;
      do {
        *pbVar8 = (byte)(((uint)*pbVar8 * 0x55) / 100);
        pbVar8[1] = (byte)(((uint)pbVar8[1] * 0x55) / 100);
        iVar4 = iVar4 + -1;
        pbVar8[2] = (byte)(((uint)pbVar8[2] * 0x55) / 100);
        pbVar8 = pbVar8 + 3;
      } while (iVar4 != 0);
      FUN_004065e0(0x20,0x10,(int)pbVar5);
      pbVar8 = pbVar5 + 0x7ea0;
      puVar9 = &DAT_00435b20;
      do {
        puVar11 = (undefined4 *)((int)puVar9 + 0x11);
        *puVar9 = *(undefined4 *)pbVar8;
        puVar9[1] = *(undefined4 *)(pbVar8 + 4);
        puVar9[2] = *(undefined4 *)(pbVar8 + 8);
        puVar9[3] = *(undefined4 *)(pbVar8 + 0xc);
        *(undefined1 *)(puVar9 + 4) = 0;
        pbVar8 = pbVar8 + 0x10;
        puVar9 = puVar11;
      } while (puVar11 < &DAT_00435c96);
      pcVar7 = &DAT_00435b31;
      iVar4 = 1;
      do {
        cVar1 = *pcVar7;
        pcVar6 = pcVar7 + 0x11;
        *pcVar7 = ' ';
        acStack_25[iVar4] = cVar1 + '\x10';
        pcVar7[0xd] = '\0';
        pcVar7[0xe] = '\0';
        pcVar7[0xf] = '\0';
        pcVar7 = pcVar6;
        iVar4 = iVar4 + 1;
      } while (pcVar6 < &DAT_00435b86);
      wsprintfA(local_268,s_C__03ds_bz_0043214c,param_1);
      FUN_00409490(local_168,&DAT_00432144,local_268);
      bVar2 = FUN_00406700(pbVar5,DAT_00436448,local_168,8);
      if (CONCAT31(extraout_var_02,bVar2) == 0) {
        wsprintfA(local_168,s__s___No_Files_found__00432170,local_268);
        FUN_00409370(local_168,0);
        local_8 = 0xffffffff;
        FUN_004065ce();
        uVar3 = 0;
        goto LAB_00406007;
      }
      wsprintfA(local_268,s_C__03dm_bz_00432138,param_1);
      FUN_00409490(local_168,&DAT_00432144,local_268);
      bVar2 = FUN_00406700(pbVar5,DAT_00436444,local_168,0x10);
      if (CONCAT31(extraout_var_03,bVar2) == 0) {
        wsprintfA(local_168,s__s___No_Files_found__00432170,local_268);
        FUN_00409370(local_168,0);
        local_8 = 0xffffffff;
        FUN_004065ce();
        uVar3 = 0;
        goto LAB_00406007;
      }
      iVar4 = 0;
      puVar9 = DAT_00436440;
      do {
        wsprintfA(local_268,s_C__03dl_c_bz_00432128,param_1,iVar4 + 0x31);
        FUN_00409490(local_168,&DAT_00432144,local_268);
        bVar2 = FUN_00406700(pbVar5,puVar9,local_168,0x20);
        if (CONCAT31(extraout_var_04,bVar2) == 0) {
          wsprintfA(local_168,s__s___No_Files_found__00432170,local_268);
          FUN_00409370(local_168,0);
          local_8 = 0xffffffff;
          FUN_004065ce();
          uVar3 = 0;
          goto LAB_00406007;
        }
        puVar9 = puVar9 + 0x4000;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
      FUN_004065e0(0x30,0x10,(int)pbVar5);
      FUN_00425c80(local_1c);
      FUN_00425c20(local_1c);
      local_64[0] = '\0';
      local_64[1] = 0;
      local_64[2] = 0x96;
      iVar4 = 0;
      do {
        iVar10 = iVar4 + 1;
        FUN_0040e5d0(&DAT_004365f0,((byte)acStack_25[iVar4 + 1] & 0xf) + 0x30,
                     local_64 + iVar4 * 4 + 4);
        iVar4 = iVar10;
      } while (iVar10 < 5);
      FUN_0040e5d0(&DAT_004365f0,0x1f,&DAT_00437568);
      FUN_0040e5d0(&DAT_004365f0,0x3f,(undefined1 *)&DAT_0043768c);
      local_4c = DAT_0043768c;
      FUN_0040e560(&DAT_004365f0,local_64,0x70,7);
      pcVar7 = local_64 + 2;
      do {
        *pcVar7 = -1;
        pcVar6 = pcVar7 + 4;
        pcVar7[-2] = -1;
        pcVar7[-1] = -1;
        pcVar7 = pcVar6;
      } while (pcVar6 < acStack_25 + 3);
      FUN_0040e560(&DAT_004365f0,local_64,0x50,0x10);
      FUN_0040e600(0x4365f0);
      FUN_00409e10();
      local_8 = 0xffffffff;
      FUN_004065ce();
    }
  }
  uVar3 = 1;
LAB_00406007:
  *unaff_FS_OFFSET = local_10;
  return uVar3;
}



/* 004065ce  FUN_004065ce  8 bytes, 1 callers */

void FUN_004065ce(void)

{
  int unaff_EBP;
  
  FUN_00425be0((int *)(unaff_EBP + -0x18));
  return;
}



/* 004065e0  FUN_004065e0  95 bytes, 1 callers */

void __cdecl FUN_004065e0(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  char local_40 [64];
  
  if (0 < (int)param_2) {
    uVar1 = param_2;
    pcVar2 = (char *)(param_3 + 0x8000);
    pcVar3 = local_40 + 2;
    do {
      *pcVar3 = *pcVar2 << 4;
      pcVar3[-2] = pcVar2[1] << 4;
      uVar1 = uVar1 - 1;
      pcVar3[-1] = pcVar2[2] << 4;
      pcVar3[1] = '\x01';
      pcVar2 = pcVar2 + 3;
      pcVar3 = pcVar3 + 4;
    } while (uVar1 != 0);
  }
  FUN_0040e560(&DAT_004365f0,local_40,param_1,param_2);
  return;
}



/* 00406640  FUN_00406640  157 bytes, 1 callers */

bool __cdecl FUN_00406640(byte *param_1,char *param_2,LPCSTR param_3,byte param_4)

{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined2 local_230 [272];
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_004066dd;
  *unaff_FS_OFFSET = &local_10;
  FUN_0041f8b0((int)local_230);
  local_8 = 0;
  iVar1 = FUN_0041f930(local_230,param_3,param_1,0x8030,1);
  if (iVar1 == 0) {
    local_8 = 0xffffffff;
    FUN_004066e7();
  }
  else {
    FUN_00406810(param_1,param_2,(uint)param_4);
    FUN_0041fa40(local_230);
    local_8 = 0xffffffff;
    FUN_004066e7();
  }
  *unaff_FS_OFFSET = local_10;
  return iVar1 != 0;
}



/* 004066e7  FUN_004066e7  11 bytes, 1 callers */

void FUN_004066e7(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x22c));
  return;
}



/* 00406700  FUN_00406700  157 bytes, 1 callers */

bool __cdecl FUN_00406700(LPVOID param_1,undefined4 *param_2,LPCSTR param_3,byte param_4)

{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined2 local_230 [272];
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040679d;
  *unaff_FS_OFFSET = &local_10;
  FUN_0041f8b0((int)local_230);
  local_8 = 0;
  iVar1 = FUN_0041f930(local_230,param_3,param_1,0x8030,1);
  if (iVar1 == 0) {
    local_8 = 0xffffffff;
    FUN_004067a7();
  }
  else {
    FUN_00406c70((int)param_1,param_2,(uint)param_4);
    FUN_0041fa40(local_230);
    local_8 = 0xffffffff;
    FUN_004067a7();
  }
  *unaff_FS_OFFSET = local_10;
  return iVar1 != 0;
}



/* 004067a7  FUN_004067a7  11 bytes, 1 callers */

void FUN_004067a7(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x22c));
  return;
}



/* 004067c0  FUN_004067c0  79 bytes, 1 callers */

undefined4 FUN_004067c0(void)

{
  int iVar1;
  
  DAT_004365d4 = 0;
  DAT_0043451c = 0;
  DAT_004365cc = 1;
  DAT_00434510 = 0xffffffff;
  iVar1 = FUN_00405de0(DAT_00436a00);
  if (iVar1 == 0) {
    FUN_00409370(s_Failed_in_loading_map__00432198,0);
    return 0;
  }
  return 1;
}



/* 00406810  FUN_00406810  1115 bytes, 1 callers */

void __cdecl FUN_00406810(byte *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  char *pcVar14;
  byte *local_424;
  byte *local_420;
  int local_408;
  uint local_404;
  byte local_400 [512];
  byte abStack_200 [16];
  byte abStack_1f0 [496];
  
  pcVar1 = param_2;
  local_420 = param_1 + 0x7ca0;
  if (param_3 == 8) {
    local_408 = 0x80;
    local_424 = param_1;
    do {
      uVar11 = 0;
      pbVar5 = local_424;
      do {
        uVar12 = 0;
        bVar2 = *pbVar5;
        bVar7 = pbVar5[0x20];
        bVar3 = pbVar5[0x40];
        bVar4 = pbVar5[0x60];
        do {
          uVar9 = 0x80 >> ((byte)uVar12 & 0x1f);
          pbVar6 = local_400 + uVar11 + uVar12;
          bVar8 = 1 - ((uVar9 & bVar2) == 0);
          *pbVar6 = bVar8;
          bVar8 = ((uVar9 & bVar7) == 0) - 1U & 2 | bVar8;
          *pbVar6 = bVar8;
          bVar8 = ((uVar9 & bVar3) == 0) - 1U & 4 | bVar8;
          *pbVar6 = bVar8;
          uVar12 = uVar12 + 1;
          *pbVar6 = ((uVar9 & bVar4) == 0) - 1U & 8 | bVar8;
        } while (uVar12 < 8);
        pbVar5 = pbVar5 + 2;
        uVar11 = uVar11 + 8;
      } while (uVar11 < 0x40);
      pbVar5 = local_400;
      pcVar14 = param_2;
      for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(undefined4 *)pcVar14 = *(undefined4 *)pbVar5;
        pbVar5 = pbVar5 + 4;
        pcVar14 = pcVar14 + 4;
      }
      param_2 = param_2 + 0x40;
      local_424 = local_424 + 0x80;
      local_408 = local_408 + -1;
    } while (local_408 != 0);
  }
  else if (param_3 == 0x10) {
    uVar11 = 0;
    do {
      uVar12 = 0;
      do {
        pbVar5 = local_400 + uVar12;
        pbVar6 = param_1 + uVar11 + (uVar12 >> 3);
        uVar9 = 0x80 >> ((byte)uVar12 & 7);
        bVar7 = 1 - ((*pbVar6 & uVar9) == 0);
        bVar2 = pbVar6[0x20];
        *pbVar5 = bVar7;
        bVar7 = ((bVar2 & uVar9) == 0) - 1U & 2 | bVar7;
        bVar2 = pbVar6[0x40];
        *pbVar5 = bVar7;
        bVar7 = ((bVar2 & uVar9) == 0) - 1U & 4 | bVar7;
        bVar2 = pbVar6[0x60];
        *pbVar5 = bVar7;
        uVar12 = uVar12 + 1;
        *pbVar5 = ((bVar2 & uVar9) == 0) - 1U & 8 | bVar7;
      } while (uVar12 < 0x100);
      uVar11 = uVar11 + 0x80;
      pbVar5 = local_400;
      pcVar14 = param_2;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(undefined4 *)pcVar14 = *(undefined4 *)pbVar5;
        pbVar5 = pbVar5 + 4;
        pcVar14 = pcVar14 + 4;
      }
      param_2 = param_2 + 0x100;
    } while (uVar11 < 0x4000);
  }
  else if (param_3 == 0x20) {
    local_408 = 0x80;
    do {
      bVar2 = *local_420;
      bVar7 = local_420[2];
      bVar3 = local_420[1];
      bVar4 = local_420[3];
      local_424 = (byte *)0x0;
      local_404 = 0;
      do {
        uVar11 = 0;
        do {
          iVar10 = local_404 + uVar11;
          iVar13 = (int)local_424 + (uVar11 >> 3);
          pbVar5 = param_1 + iVar13 + (uint)bVar2 * 0x80;
          uVar12 = 0x80 >> ((byte)uVar11 & 7);
          bVar8 = 1 - ((*pbVar5 & uVar12) == 0);
          local_400[iVar10] = bVar8;
          bVar8 = ((pbVar5[0x20] & uVar12) == 0) - 1U & 2 | bVar8;
          local_400[iVar10] = bVar8;
          bVar8 = ((pbVar5[0x40] & uVar12) == 0) - 1U & 4 | bVar8;
          local_400[iVar10] = bVar8;
          local_400[iVar10] = ((pbVar5[0x60] & uVar12) == 0) - 1U & 8 | bVar8;
          pbVar5 = param_1 + iVar13 + (uint)bVar7 * 0x80;
          bVar8 = 1 - ((*pbVar5 & uVar12) == 0);
          local_400[iVar10 + 0x10] = bVar8;
          bVar8 = ((pbVar5[0x20] & uVar12) == 0) - 1U & 2 | bVar8;
          local_400[iVar10 + 0x10] = bVar8;
          bVar8 = ((pbVar5[0x40] & uVar12) == 0) - 1U & 4 | bVar8;
          local_400[iVar10 + 0x10] = bVar8;
          local_400[iVar10 + 0x10] = ((pbVar5[0x60] & uVar12) == 0) - 1U & 8 | bVar8;
          pbVar6 = param_1 + iVar13 + (uint)bVar3 * 0x80;
          bVar8 = 1 - ((*pbVar6 & uVar12) == 0);
          abStack_200[iVar10] = bVar8;
          bVar8 = ((pbVar6[0x20] & uVar12) == 0) - 1U & 2 | bVar8;
          abStack_200[iVar10] = bVar8;
          bVar8 = ((pbVar6[0x40] & uVar12) == 0) - 1U & 4 | bVar8;
          abStack_200[iVar10] = bVar8;
          pbVar5 = abStack_1f0 + iVar10;
          abStack_200[iVar10] = ((pbVar6[0x60] & uVar12) == 0) - 1U & 8 | bVar8;
          pbVar6 = param_1 + iVar13 + (uint)bVar4 * 0x80;
          bVar8 = 1 - ((*pbVar6 & uVar12) == 0);
          *pbVar5 = bVar8;
          bVar8 = ((pbVar6[0x20] & uVar12) == 0) - 1U & 2 | bVar8;
          *pbVar5 = bVar8;
          bVar8 = ((pbVar6[0x40] & uVar12) == 0) - 1U & 4 | bVar8;
          *pbVar5 = bVar8;
          uVar11 = uVar11 + 1;
          *pbVar5 = ((pbVar6[0x60] & uVar12) == 0) - 1U & 8 | bVar8;
        } while (uVar11 < 0x10);
        local_424 = (byte *)((int)local_424 + 2);
        local_404 = local_404 + 0x20;
      } while (local_404 < 0x200);
      pbVar5 = local_400;
      pcVar14 = param_2;
      for (iVar10 = 0x100; iVar10 != 0; iVar10 = iVar10 + -1) {
        *(undefined4 *)pcVar14 = *(undefined4 *)pbVar5;
        pbVar5 = pbVar5 + 4;
        pcVar14 = pcVar14 + 4;
      }
      param_2 = param_2 + 0x400;
      local_420 = local_420 + 4;
      local_408 = local_408 + -1;
    } while (local_408 != 0);
  }
  for (; pcVar1 < param_2; pcVar1 = pcVar1 + 1) {
    *pcVar1 = *pcVar1 + '\x10';
  }
  return;
}



/* 00406c70  FUN_00406c70  1125 bytes, 1 callers */

void __cdecl FUN_00406c70(int param_1,undefined4 *param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint local_408;
  uint local_404;
  byte local_400 [512];
  byte local_200 [16];
  byte local_1f0 [496];
  
  if (param_3 == 8) {
    uVar8 = 0;
    do {
      uVar10 = 0;
      do {
        pbVar2 = local_400 + uVar10;
        pbVar7 = (byte *)((uVar10 >> 3) + param_1 + uVar8);
        uVar9 = 0x80 >> ((byte)uVar10 & 7);
        bVar5 = 1 - ((*pbVar7 & uVar9) == 0);
        bVar1 = pbVar7[0x20];
        *pbVar2 = bVar5;
        bVar5 = ((bVar1 & uVar9) == 0) - 1U & 2 | bVar5;
        bVar1 = pbVar7[0x40];
        *pbVar2 = bVar5;
        bVar5 = ((bVar1 & uVar9) == 0) - 1U & 4 | bVar5;
        bVar1 = pbVar7[0x60];
        *pbVar2 = bVar5;
        bVar5 = ((bVar1 & uVar9) == 0) - 1U & 8 | bVar5;
        *pbVar2 = bVar5;
        if (bVar5 == 0xf) {
          *pbVar2 = 0x70;
          if (uVar8 < 0x1980) {
            *pbVar2 = 0x76;
          }
        }
        else {
          *pbVar2 = bVar5 + 0x30;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < 0x100);
      pbVar7 = local_400;
      do {
        iVar4 = 2;
        pbVar2 = pbVar7;
        do {
          iVar3 = 8;
          pbVar6 = pbVar2;
          do {
            puVar11 = param_2 + 2;
            pbVar2 = pbVar6 + 0x10;
            *param_2 = *(undefined4 *)pbVar6;
            iVar3 = iVar3 + -1;
            param_2[1] = *(undefined4 *)(pbVar6 + 4);
            pbVar6 = pbVar2;
            param_2 = puVar11;
          } while (iVar3 != 0);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        pbVar7 = pbVar7 + 8;
      } while (pbVar7 < local_400 + 0x10);
      uVar8 = uVar8 + 0x80;
    } while (uVar8 < 0x2000);
    return;
  }
  if (param_3 != 0x10) {
    if (param_3 != 0x20) {
      return;
    }
    local_408 = 0;
    do {
      uVar8 = 0;
      local_404 = local_408;
      do {
        uVar10 = 0;
        do {
          pbVar7 = local_400 + uVar8 + uVar10;
          pbVar2 = (byte *)(local_404 + (uVar10 >> 3) + param_1);
          uVar9 = 0x80 >> ((byte)uVar10 & 7);
          bVar5 = 1 - ((*pbVar2 & uVar9) == 0);
          bVar1 = pbVar2[0x20];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 2 | bVar5;
          bVar1 = pbVar2[0x40];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 4 | bVar5;
          bVar1 = pbVar2[0x60];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 8 | bVar5;
          *pbVar7 = bVar5;
          if (bVar5 == 0xf) {
            local_400[uVar8 + uVar10] = 0x70;
          }
          else {
            local_400[uVar8 + uVar10] = local_400[uVar8 + uVar10] + 0x30;
          }
          pbVar7 = local_400 + uVar8 + uVar10 + 0x10;
          bVar5 = 1 - ((pbVar2[0x80] & uVar9) == 0);
          bVar1 = pbVar2[0xa0];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 2 | bVar5;
          bVar1 = pbVar2[0xc0];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 4 | bVar5;
          bVar1 = pbVar2[0xe0];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 8 | bVar5;
          *pbVar7 = bVar5;
          if (bVar5 == 0xf) {
            local_400[uVar8 + uVar10 + 0x10] = 0x70;
          }
          else {
            local_400[uVar8 + uVar10 + 0x10] = local_400[uVar8 + uVar10 + 0x10] + 0x30;
          }
          pbVar7 = local_200 + uVar8 + uVar10;
          bVar5 = 1 - ((pbVar2[0x100] & uVar9) == 0);
          bVar1 = pbVar2[0x120];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 2 | bVar5;
          bVar1 = pbVar2[0x140];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 4 | bVar5;
          bVar1 = pbVar2[0x160];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 8 | bVar5;
          *pbVar7 = bVar5;
          if (bVar5 == 0xf) {
            local_200[uVar8 + uVar10] = 0x70;
          }
          else {
            local_200[uVar8 + uVar10] = local_200[uVar8 + uVar10] + 0x30;
          }
          pbVar7 = local_1f0 + uVar8 + uVar10;
          bVar5 = 1 - ((pbVar2[0x180] & uVar9) == 0);
          bVar1 = pbVar2[0x1a0];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 2 | bVar5;
          bVar1 = pbVar2[0x1c0];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 4 | bVar5;
          bVar1 = pbVar2[0x1e0];
          *pbVar7 = bVar5;
          bVar5 = ((bVar1 & uVar9) == 0) - 1U & 8 | bVar5;
          *pbVar7 = bVar5;
          if (bVar5 == 0xf) {
            local_1f0[uVar8 + uVar10] = 0x70;
          }
          else {
            local_1f0[uVar8 + uVar10] = local_1f0[uVar8 + uVar10] + 0x30;
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < 0x10);
        local_404 = local_404 + 2;
        uVar8 = uVar8 + 0x20;
      } while (uVar8 < 0x200);
      pbVar7 = local_400;
      puVar11 = param_2;
      for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar11 = *(undefined4 *)pbVar7;
        pbVar7 = pbVar7 + 4;
        puVar11 = puVar11 + 1;
      }
      param_2 = param_2 + 0x100;
      local_408 = local_408 + 0x200;
    } while (local_408 < 0x8000);
    return;
  }
  uVar8 = 0;
  do {
    uVar10 = 0;
    do {
      pbVar2 = local_400 + uVar10;
      pbVar7 = (byte *)((uVar10 >> 3) + param_1 + uVar8);
      uVar9 = 0x80 >> ((byte)uVar10 & 7);
      bVar5 = 1 - ((*pbVar7 & uVar9) == 0);
      bVar1 = pbVar7[0x20];
      *pbVar2 = bVar5;
      bVar5 = ((bVar1 & uVar9) == 0) - 1U & 2 | bVar5;
      bVar1 = pbVar7[0x40];
      *pbVar2 = bVar5;
      bVar5 = ((bVar1 & uVar9) == 0) - 1U & 4 | bVar5;
      bVar1 = pbVar7[0x60];
      *pbVar2 = bVar5;
      bVar5 = ((bVar1 & uVar9) == 0) - 1U & 8 | bVar5;
      *pbVar2 = bVar5;
      if (bVar5 == 0xf) {
        *pbVar2 = 0x70;
      }
      else {
        *pbVar2 = bVar5 + 0x30;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < 0x100);
    uVar8 = uVar8 + 0x80;
    pbVar7 = local_400;
    puVar11 = param_2;
    for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar11 = *(undefined4 *)pbVar7;
      pbVar7 = pbVar7 + 4;
      puVar11 = puVar11 + 1;
    }
    param_2 = param_2 + 0x40;
  } while (uVar8 < 0x6800);
  return;
}



/* 004070e0  FUN_004070e0  299 bytes, 1 callers */

undefined4 * __fastcall FUN_004070e0(undefined4 *param_1)

{
  int iVar1;
  HFONT pHVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040720b;
  *unaff_FS_OFFSET = &local_10;
  FUN_00427770(param_1);
  local_8 = 0;
  *param_1 = &PTR_FUN_00430078;
  wsprintfA((LPSTR)(param_1 + 0x53),s_Code7_00432210);
  wsprintfA((LPSTR)(param_1 + 0x12),s_Frame_Window_00432200);
  wsprintfA((LPSTR)(param_1 + 0xa0),s_DS795_FRAME_004321f4);
  param_1[0x9f] = 0x100;
  param_1[0x9e] = 0xcf0000;
  iVar1 = GetSystemMetrics(0x20);
  param_1[6] = iVar1 * 2;
  iVar1 = GetSystemMetrics(0x21);
  param_1[7] = iVar1 * 2;
  iVar1 = GetSystemMetrics(4);
  param_1[7] = param_1[7] + iVar1;
  param_1[10] = 0;
  param_1[0xb] = 0;
  iVar1 = GetSystemMetrics(0);
  param_1[0xc] = iVar1;
  iVar1 = GetSystemMetrics(1);
  param_1[0xd] = iVar1;
  param_1[0xe6] = 0;
  param_1[0xe7] = 0;
  param_1[0xe5] = 0;
  pHVar2 = CreateFontA(10,0,0,0,400,0,0,0,0x80,3,0,2,0x11,s_MS_Sans_Serif_004321e4);
  param_1[0xe8] = pHVar2;
  pHVar2 = CreateFontA(0xf,0,0,0,600,0,0,0,0xff,0,0,0,1,s_MS_Sans_Serif_004321e4);
  param_1[0xe9] = pHVar2;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}



/* 00407220  FUN_00407220  30 bytes, 0 callers */

undefined4 * __thiscall FUN_00407220(void *this,byte param_1)

{
  FUN_00407240(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 00407240  FUN_00407240  198 bytes, 1 callers */

void __fastcall FUN_00407240(undefined4 *param_1)

{
  LPVOID pvVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00407306;
  *param_1 = &PTR_FUN_00430078;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0;
  if ((HGDIOBJ)param_1[0xe8] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)param_1[0xe8]);
    param_1[0xe8] = 0;
  }
  if ((HGDIOBJ)param_1[0xe9] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)param_1[0xe9]);
    param_1[0xe9] = 0;
  }
  pvVar1 = DAT_00436460;
  if (DAT_00436460 != (LPVOID)0x0) {
    FUN_00424f50();
    FUN_00427f80(pvVar1);
    DAT_00436460 = (LPVOID)0x0;
  }
  DAT_004344e4 = 0;
  PostQuitMessage(0);
  local_8 = 0xffffffff;
  FUN_00407310();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 00407310  FUN_00407310  8 bytes, 1 callers */

void FUN_00407310(void)

{
  int unaff_EBP;
  
  FUN_00427820(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 00407320  FUN_00407320  242 bytes, 0 callers */

undefined4 FUN_00407320(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00437698;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_00436a00;
  for (iVar1 = 0x2da; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_004365a0;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  DAT_004365a0 = 0;
  DAT_004365a4 = 0xffffffff;
  DAT_00434510 = 0xffffffff;
  DAT_00434514 = 0xffffffff;
  DAT_0043781c = 0;
  DAT_004369fc = 0;
  DAT_004377fc = 0;
  DAT_004365bc = 3000;
  DAT_004365c4 = 3000;
  DAT_0043769c = 1;
  DAT_0043769d = 0;
  DAT_004376a3 = 0;
  DAT_004376a2 = 1;
  DAT_004376a4 = 1;
  DAT_004376a5 = 1;
  DAT_004376a6 = 1;
  DAT_004376ab = 1;
  DAT_004376ad = 0;
  DAT_0043769e = 1;
  DAT_0043769f = 1;
  DAT_004376a0 = 1;
  DAT_004376a1 = 1;
  DAT_004376b0 = 1;
  DAT_004376b4 = 0;
  DAT_004376b6 = 0;
  DAT_004376b7 = 0;
  DAT_00437698 = 0x19;
  DAT_004376ae = 0x10;
  DAT_004376ac = 7;
  FUN_004057b0();
  return 1;
}



/* 00407420  FUN_00407420  287 bytes, 0 callers */

int FUN_00407420(void)

{
  int iVar1;
  
  iVar1 = 0;
  DAT_0043645c = FUN_00425c00(&DAT_00435b10,0x2000);
  if (DAT_0043645c != 0) {
    DAT_00436458 = FUN_00425c00(&DAT_00435b00,0x8000);
    if (DAT_00436458 != 0) {
      DAT_00436454 = FUN_00425c00(&DAT_00435af0,0x20000);
      if (DAT_00436454 != 0) {
        DAT_00436448 = FUN_00425c00(&DAT_00437810,0x3400);
        if (DAT_00436448 != 0) {
          DAT_00436444 = FUN_00425c00(&DAT_00437800,0xd000);
          if (DAT_00436444 != 0) {
            DAT_00436440 = FUN_00425c00(&DAT_004377f0,0x40000);
            if (DAT_00436440 != 0) {
              DAT_00435fd4 = FUN_00425c00(&DAT_00435c98,0x40000);
              if (DAT_00435fd4 != 0) {
                DAT_0043453c = FUN_00425c00(&DAT_00437820,0xd800);
                if (DAT_0043453c != 0) {
                  DAT_00434538 = FUN_00425c00(&DAT_004376b8,0x8900);
                  if (DAT_00434538 != 0) {
                    DAT_00434534 = FUN_00425c00(&DAT_004377e0,0x118);
                    if (DAT_00434534 != 0) {
                      iVar1 = 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (iVar1 == 0) {
    FUN_00409370(s_Not_enough_memory__00432218,0);
  }
  return iVar1;
}



/* 00407540  FUN_00407540  20 bytes, 0 callers */

undefined4 __fastcall FUN_00407540(int param_1)

{
  FUN_0040c9e0(&DAT_00435db0,*(HWND *)(param_1 + 8));
  return 1;
}



/* 00407560  FUN_00407560  453 bytes, 0 callers */

undefined4 FUN_00407560(void)

{
  bool bVar1;
  undefined3 extraout_var;
  LPVOID pvVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_410 [192];
  undefined2 local_350 [272];
  CHAR local_130 [260];
  int local_2c [3];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040772d;
  *unaff_FS_OFFSET = &local_10;
  FUN_0041f8b0((int)local_350);
  local_8 = 0;
  FUN_00409490(local_130,s_DATA__004321b0,s_data1_rgb_00432238);
  bVar1 = FUN_0041f9f0(local_350,local_130);
  if (CONCAT31(extraout_var,bVar1) == 1) {
    FUN_0041fa80(local_350,local_410,0xc0,0);
    FUN_0041fa40(local_350);
    FUN_0040e560(&DAT_004365f0,local_410,0x80,0x30);
  }
  FUN_00425bd0(local_2c);
  local_8._0_1_ = 1;
  pvVar2 = (LPVOID)FUN_00425c00(local_2c,0x40000);
  if (pvVar2 != (LPVOID)0x0) {
    FUN_00409490(local_130,s_DATA__004321b0,s_data1_bz_0043222c);
    iVar4 = FUN_0041f930(local_350,local_130,pvVar2,0x40000,1);
    if (iVar4 != 0) {
      iVar4 = 0;
      local_14 = 0;
      do {
        local_1c = 0x10;
        local_18 = local_14;
        do {
          local_20 = 0x10;
          iVar5 = local_18;
          do {
            iVar6 = 0;
            do {
              if (*(char *)((int)pvVar2 + iVar4 + iVar6) == '\x1f') {
                *(undefined1 *)((int)pvVar2 + iVar4 + iVar6) = 0x70;
                *(undefined1 *)(DAT_00435fd4 + iVar6 + iVar5) = 0x70;
              }
              else {
                *(char *)(DAT_00435fd4 + iVar6 + iVar5) =
                     *(char *)((int)pvVar2 + iVar4 + iVar6) + 'p';
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 < 0x10);
            iVar4 = iVar4 + 0x10;
            iVar5 = iVar5 + 0x100;
            local_20 = local_20 + -1;
          } while (local_20 != 0);
          local_18 = local_18 + 0x10;
          local_1c = local_1c + -1;
        } while (local_1c != 0);
        local_14 = local_14 + 0x1000;
      } while (local_14 < 0x40000);
      FUN_00425c80(local_2c);
      FUN_00425c20(local_2c);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00407725();
      local_8 = 0xffffffff;
      FUN_00407737();
      uVar3 = 1;
      goto LAB_00407635;
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00407725();
  local_8 = 0xffffffff;
  FUN_00407737();
  uVar3 = 0;
LAB_00407635:
  *unaff_FS_OFFSET = local_10;
  return uVar3;
}



/* 00407725  FUN_00407725  8 bytes, 1 callers */

void FUN_00407725(void)

{
  int unaff_EBP;
  
  FUN_00425be0((int *)(unaff_EBP + -0x28));
  return;
}



/* 00407737  FUN_00407737  11 bytes, 1 callers */

void FUN_00407737(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x34c));
  return;
}



/* 00407750  FUN_00407750  57 bytes, 0 callers */

bool FUN_00407750(void)

{
  int iVar1;
  CHAR local_104 [260];
  
  FUN_00409490(local_104,&DAT_00432120,s_name_txt_00432244);
  iVar1 = FUN_0041a510(&DAT_004376c8,local_104);
  return (bool)('\x01' - (iVar1 == 0));
}



/* 00407790  FUN_00407790  105 bytes, 0 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00407790(void)

{
  int iVar1;
  _SYSTEMTIME local_10;
  
  GetLocalTime(&local_10);
  iVar1 = 5;
  DAT_004365e8 = local_10.wMilliseconds;
  DAT_004365cc = 1;
  FUN_004280b0((uint)local_10.wMilliseconds);
  do {
    FUN_0041abf0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_004273b0();
  FUN_00405330();
  FUN_004272b0();
  FUN_00427210();
  FUN_0041b370();
  _DAT_00434540 = 3;
  return 1;
}



/* 00407800  FUN_00407800  130 bytes, 0 callers */

undefined4 FUN_00407800(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (DAT_004376b5 != '\0') {
    iVar1 = FUN_00405860();
    if (iVar1 == 1) {
      uVar2 = DAT_00436a00;
    }
    if (DAT_004376b5 != '\0') {
      iVar1 = FUN_00405900(0x432268);
      if (iVar1 != 0) {
        FUN_00409510();
        return 1;
      }
      iVar1 = FUN_00405de0(uVar2);
      if (iVar1 != 0) {
        return 1;
      }
      FUN_00409370(s_Could_not_load_mapfile__00432250,0);
      return 0;
    }
  }
  iVar1 = FUN_00405de0(uVar2);
  if (iVar1 != 0) {
    return 1;
  }
  FUN_00409370(s_Could_not_load_mapfile__00432250,0);
  return 0;
}



/* 00407890  FUN_00407890  37 bytes, 0 callers */

undefined4 __fastcall FUN_00407890(int param_1)

{
  if (DAT_004376ab == '\0') {
    SendMessageA(*(HWND *)(param_1 + 8),0x111,0x9cac,0);
  }
  return 1;
}



/* 00407b40  FUN_00407b40  1613 bytes, 0 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00407b40(int *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  int *piVar4;
  int iVar5;
  byte *pbVar6;
  void *this;
  LONG LVar7;
  uint uVar8;
  
  uVar3 = DAT_004376b6;
  uVar8 = param_1[4];
  if (uVar8 < 0x9c56) {
    if ((uVar8 < 0x9c54) && (uVar8 != 0x9c4c)) {
      FUN_00408e40();
      return;
    }
  }
  else if (uVar8 < 0x9c62) {
    if (uVar8 != 0x9c61) {
      if (uVar8 == 0x9c5e) {
        FUN_00408db0();
        FUN_00408e40();
        return;
      }
      FUN_00408e40();
      return;
    }
  }
  else if (uVar8 < 0x9c6d) {
    if (uVar8 == 0x9c6c) {
      (**(code **)(*param_1 + 0x3c))();
      FUN_00408e40();
      return;
    }
    if (uVar8 < 0x9c65) goto switchD_00407c3c_caseD_9c7f;
    if (0x9c66 < uVar8) {
      if (uVar8 == 0x9c67) {
        FUN_004093b0();
        FUN_00408e40();
        return;
      }
      FUN_00408e40();
      return;
    }
  }
  else {
    if (uVar8 < 0x9c73) {
      if (uVar8 < 0x9c70) {
        if (uVar8 == 0x9c6d) {
          FUN_00408d80();
          FUN_00408e40();
          return;
        }
        FUN_00408e40();
        return;
      }
      if (uVar8 == 0x9c70) {
        DAT_004376ae = 8;
      }
      else if (uVar8 == 0x9c71) {
        DAT_004376ae = 0x10;
      }
      else {
        if (uVar8 != 0x9c72) {
          return;
        }
        DAT_004376ae = 0x20;
      }
      piVar4 = (int *)FUN_0040a0c0(60000);
      if (piVar4 != (int *)0x0) {
        if ((uint)DAT_004376ae == piVar4[0xe6]) {
          return;
        }
        (**(code **)(*piVar4 + 0x3c))();
      }
      FUN_00408590(param_1,60000);
      FUN_00408e40();
      return;
    }
    if (0x9c77 < uVar8) {
      if (uVar8 < 0x9c94) {
        if (uVar8 < 0x9c90) {
          switch(uVar8) {
          case 0x9c7d:
            if ((DAT_004365dc != 1) && (DAT_004365dc != 5)) {
              iVar5 = FUN_00409e90();
              if (iVar5 == 0) {
                DAT_004365dc = 0;
                FUN_00408e40();
                FUN_00408e40();
                return;
              }
              FUN_00409d50(0x9c7d,1);
              FUN_0040a1c0(90000);
              DAT_004365dc = 1;
              DAT_004321c8 = DAT_004321c8 | 1;
              FUN_00408e40();
              FUN_00408e40();
              return;
            }
            FUN_00409f90();
            return;
          case 0x9c7e:
            if ((DAT_004365dc != 1) && (DAT_004365dc != 5)) {
              iVar5 = FUN_00409f10();
              if (iVar5 == 0) {
                DAT_004365dc = 0;
                FUN_00408e40();
                FUN_00408e40();
                return;
              }
              FUN_00409d50(0x9c7e,1);
              FUN_0040a1c0(90000);
              DAT_004365dc = 1;
              DAT_004321c8 = DAT_004321c8 | 2;
              FUN_00408e40();
              FUN_00408e40();
              return;
            }
            FUN_00409f90();
            return;
          case 0x9c82:
            DAT_004376b6 = 0;
            FUN_00409570();
            DAT_004376b6 = uVar3;
            FUN_00408e40();
            return;
          case 0x9c83:
            FUN_004095d0(0x69,0,(HWND)param_1[2]);
            FUN_00408e40();
            return;
          case 0x9c84:
            FUN_004095d0(0x69,1,(HWND)param_1[2]);
            FUN_00408e40();
            return;
          case 0x9c85:
            FUN_004095d0(0x69,2,(HWND)param_1[2]);
            FUN_00408e40();
            return;
          case 0x9c86:
            FUN_004095d0(0x69,3,(HWND)param_1[2]);
            FUN_00408e40();
            return;
          case 0x9c87:
            FUN_004095d0(0x72,0,(HWND)param_1[2]);
            FUN_00408e40();
            return;
          }
        }
        else {
          iVar5 = *(int *)(DAT_00434534 + -0x223f74 + uVar8 * 0x38);
          if (iVar5 != 0x40) {
            if (DAT_004321c4 != 0x40) {
              *(undefined1 *)(DAT_00434538 + 0x220 + DAT_004321c4 * 0x224) = 0xff;
              DAT_004321c4 = 0x40;
              FUN_00408de0(0);
            }
            pbVar6 = (byte *)(iVar5 * 0x224 + DAT_00434538);
            bVar1 = *pbVar6;
            bVar2 = pbVar6[1];
            pbVar6[0x220] = 0xc;
            DAT_004321b8 = 0;
            DAT_004321c0 = 1;
            DAT_004321c4 = iVar5;
            FUN_00408de0(1);
            this = (void *)FUN_0040a0c0(60000);
            if (this != (void *)0x0) {
              FUN_00423f90(this,(uint)bVar1,(uint)bVar2,(undefined4 *)0x0,0);
              FUN_00408e40();
              return;
            }
          }
        }
      }
      else {
        if (uVar8 < 0xc351) {
          if (uVar8 != 50000) {
            switch(uVar8) {
            case 0x9cac:
              FUN_00408940((int)param_1);
              FUN_00408e40();
              return;
            case 0x9cad:
              piVar4 = (int *)FUN_0040a0c0(0xea65);
              if (piVar4 != (int *)0x0) {
                DAT_004376a3 = DAT_004376a3 + 1 & 1;
                (**(code **)(*piVar4 + 0x3c))();
                FUN_00408590(param_1,0xea65);
                FUN_00408e40();
                return;
              }
              break;
            case 0x9cae:
              FUN_00408d50();
              FUN_00408e40();
              return;
            case 0x9caf:
              FUN_0040a4b0();
              FUN_00408e40();
              return;
            case 0x9cb1:
              LVar7 = FUN_0040a0c0(60000);
              if (LVar7 != 0) {
                FUN_004247b0();
                FUN_00408e40();
                return;
              }
              break;
            case 0x9cb2:
              FUN_00408b80();
              FUN_00408e40();
              return;
            case 0x9cb4:
            case 0x9cb5:
              goto switchD_00407c5e_caseD_9cb4;
            case 0x9cb7:
              FUN_0040a2f0();
              FUN_00408e40();
              return;
            case 0x9cb8:
              FUN_0040b0a0();
              FUN_00408e40();
              return;
            }
            goto switchD_00407c3c_caseD_9c7f;
          }
        }
        else {
          if (0xea63 < uVar8) {
            if (uVar8 < 0xee4c) {
              if (uVar8 < 61000) {
                if (0xea64 < uVar8) {
                  if (0xea69 < uVar8) {
                    FUN_00408e40();
                    return;
                  }
                  goto LAB_00408161;
                }
                goto switchD_00407c3c_caseD_9c7f;
              }
            }
            else {
              if (uVar8 < 0xee4d) goto switchD_00407c3c_caseD_9c7f;
              if (0xee51 < uVar8) {
                FUN_00408e40();
                return;
              }
            }
            FUN_00408b30(uVar8 - 1000);
            goto switchD_00407c3c_caseD_9c7f;
          }
          if (59999 < uVar8) {
LAB_00408161:
            FUN_00408590(param_1,uVar8);
            FUN_00408e40();
            return;
          }
          if (uVar8 < 0xc353) goto switchD_00407c3c_caseD_9c7f;
          if (0xc362 < uVar8) {
            FUN_00408e40();
            return;
          }
        }
        DAT_004365e4 = uVar8 - 50000;
        _DAT_004365e0 = (uint)(char)(&DAT_00434444)[(param_1[4] - 50000U) / 3];
        uVar8 = (param_1[4] - 50000U) % 3;
        if (uVar8 == 1) {
          _DAT_004365e0 = _DAT_004365e0 | 0x50;
        }
        if (uVar8 == 2) {
          _DAT_004365e0 = _DAT_004365e0 | 0x90;
          FUN_00408e40();
          return;
        }
      }
switchD_00407c3c_caseD_9c7f:
      FUN_00408e40();
      return;
    }
    if ((uVar8 != 0x9c77) && (uVar8 != 0x9c73)) {
      FUN_00408e40();
      return;
    }
  }
switchD_00407c5e_caseD_9cb4:
  FUN_004095d0(uVar8,0,(HWND)param_1[2]);
  FUN_00408e40();
  return;
}



/* 00408200  FUN_00408200  63 bytes, 0 callers */

void __fastcall FUN_00408200(int param_1)

{
  int iVar1;
  LONG LVar2;
  
  iVar1 = FUN_004094c0();
  if (iVar1 != 0) {
    FUN_00408290(param_1);
    LVar2 = FUN_0040a0c0(0xea65);
    DAT_004376a2 = '\x01' - (LVar2 == 0);
    FUN_004093b0();
    FUN_004057d0();
    FUN_00425af0(param_1);
  }
  return;
}



/* 00408240  FUN_00408240  73 bytes, 0 callers */

undefined4 __fastcall FUN_00408240(int param_1)

{
  bool bVar1;
  MMRESULT MVar2;
  undefined3 extraout_var;
  
  MVar2 = timeSetEvent(0x10,0x10,&LAB_0040a5c0,0,1);
  *(MMRESULT *)(param_1 + 0x398) = MVar2;
  if (MVar2 == 0) {
    return 0;
  }
  bVar1 = FUN_004087e0(param_1);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    return 0;
  }
  DAT_004344e0 = 0;
  return 1;
}



/* 00408290  FUN_00408290  85 bytes, 1 callers */

void __fastcall FUN_00408290(int param_1)

{
  DAT_004344e0 = 0xffffffff;
  if (*(UINT *)(param_1 + 0x398) != 0) {
    timeKillEvent(*(UINT *)(param_1 + 0x398));
    DAT_004344e0 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x398) = 0;
  }
  if (*(UINT_PTR *)(param_1 + 0x39c) != 0) {
    KillTimer(*(HWND *)(param_1 + 8),*(UINT_PTR *)(param_1 + 0x39c));
    *(undefined4 *)(param_1 + 0x39c) = 0;
  }
  return;
}



/* 004084e0  FUN_004084e0  164 bytes, 2 callers */

void __fastcall FUN_004084e0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  DAT_00435b1c = 1;
  piVar1 = (int *)FUN_0040a0c0(60000);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea61);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea63);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea62);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))();
  }
  iVar2 = 0;
  do {
    piVar1 = (int *)FUN_0040a0c0(iVar2 + 0xea66);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x14))();
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  FUN_00408aa0(param_1);
  FUN_0040a210();
  FUN_00408e40();
  return;
}



/* 00408590  FUN_00408590  459 bytes, 1 callers */

undefined4 __thiscall FUN_00408590(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040879c;
  *unaff_FS_OFFSET = &local_10;
  piVar2 = (int *)FUN_0040a0c0(param_1);
  if (piVar2 == (int *)0x0) {
    switch(param_1) {
    case 60000:
      puVar4 = (undefined4 *)FUN_00427f90(0x17f8);
      local_8 = 0;
      piVar2 = (int *)0x0;
      if (puVar4 != (undefined4 *)0x0) {
        piVar2 = FUN_00422610(puVar4);
      }
      break;
    case 0xea61:
      puVar4 = (undefined4 *)FUN_00427f90(0x4ac);
      local_8 = 1;
      piVar2 = (int *)0x0;
      if (puVar4 != (undefined4 *)0x0) {
        piVar2 = FUN_00426630(puVar4);
      }
      break;
    case 0xea62:
      puVar4 = (undefined4 *)FUN_00427f90(0x4ac);
      local_8 = 2;
      piVar2 = (int *)0x0;
      if (puVar4 != (undefined4 *)0x0) {
        piVar2 = FUN_004198e0(puVar4);
      }
      break;
    case 0xea63:
      puVar4 = (undefined4 *)FUN_00427f90(0x1628);
      piVar2 = (int *)0x0;
      local_8 = 3;
      if (puVar4 != (undefined4 *)0x0) {
        piVar2 = FUN_004042b0(puVar4);
      }
      break;
    default:
      goto switchD_004085e8_caseD_ea64;
    case 0xea65:
      puVar4 = (undefined4 *)FUN_00427f90(0x3a0);
      piVar2 = (int *)0x0;
      local_8 = 4;
      if (puVar4 != (undefined4 *)0x0) {
        piVar2 = FUN_0041b700(puVar4);
      }
      break;
    case 0xea66:
    case 0xea67:
    case 0xea68:
    case 0xea69:
      puVar4 = (undefined4 *)FUN_00427f90(0x4a8);
      piVar2 = (int *)0x0;
      local_8 = 5;
      if (puVar4 != (undefined4 *)0x0) {
        piVar2 = FUN_0041cee0(puVar4);
      }
    }
    local_8 = 0xffffffff;
    FUN_00408de0(1);
    if (piVar2 != (int *)0x0) {
      iVar1 = *piVar2;
      iVar5 = (**(code **)(iVar1 + 4))(*(undefined4 *)((int)this + 8),param_1);
      if (iVar5 == 0) {
        (**(code **)(iVar1 + 0x3c))();
      }
    }
    FUN_00408e40();
    FUN_00408de0(0);
    uVar3 = 1;
  }
  else {
    (**(code **)(*piVar2 + 0x3c))();
switchD_004085e8_caseD_ea64:
    uVar3 = 0;
  }
  *unaff_FS_OFFSET = local_10;
  return uVar3;
}



/* 004087e0  FUN_004087e0  66 bytes, 1 callers */

bool __fastcall FUN_004087e0(int param_1)

{
  UINT_PTR UVar1;
  
  if (*(UINT_PTR *)(param_1 + 0x39c) != 0) {
    KillTimer(*(HWND *)(param_1 + 8),*(UINT_PTR *)(param_1 + 0x39c));
    *(undefined4 *)(param_1 + 0x39c) = 0;
  }
  UVar1 = SetTimer(*(HWND *)(param_1 + 8),0x15,100,(TIMERPROC)0x0);
  *(UINT_PTR *)(param_1 + 0x39c) = UVar1;
  return (bool)('\x01' - (UVar1 == 0));
}



/* 00408830  FUN_00408830  53 bytes, 0 callers */

void __fastcall FUN_00408830(int param_1)

{
  tagRECT local_10;
  
  GetWindowRect(*(HWND *)(param_1 + 8),&local_10);
  *(LONG *)(param_1 + 0x270) = local_10.left;
  *(LONG *)(param_1 + 0x274) = local_10.top;
  GetCursorPos((LPPOINT)(param_1 + 0x268));
  return;
}



/* 00408870  FUN_00408870  157 bytes, 0 callers */

void FUN_00408870(void)

{
  int *piVar1;
  tagPOINT local_8;
  
  switch(DAT_004365dc) {
  case 0:
    GetCursorPos(&local_8);
    DAT_004365dc = 3;
    GetCursorPos(&local_8);
    FUN_0040a980(&local_8.x);
    return;
  case 1:
    FUN_00409f90();
    return;
  case 3:
    DAT_004365dc = 1;
    piVar1 = (int *)FUN_0040a0c0(60000);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 100))();
      return;
    }
    break;
  case 4:
    FUN_00409f90();
    DAT_004365dc = 1;
    return;
  case 5:
    DAT_004365dc = 1;
  }
  return;
}



/* 00408940  FUN_00408940  339 bytes, 1 callers */

void __fastcall FUN_00408940(int param_1)

{
  HMENU pHVar1;
  UINT UVar2;
  uint uVar3;
  int iVar4;
  
  pHVar1 = GetMenu(*(HWND *)(param_1 + 8));
  UVar2 = GetMenuState(pHVar1,0x9c73,0);
  if (UVar2 == 0xffffffff) {
    pHVar1 = LoadMenuA(DAT_004344d0,(LPCSTR)0x65);
    if (pHVar1 != (HMENU)0x0) {
      uVar3 = GetWindowLongA(DAT_004344d4,-0x10);
      SetWindowLongA(DAT_004344d4,-0x10,uVar3 | 0xc00000);
      SetMenu(*(HWND *)(param_1 + 8),pHVar1);
      DAT_004376ab = 1;
      FUN_0040a210();
      FUN_00408aa0(param_1);
      DrawMenuBar(*(HWND *)(param_1 + 8));
      InvalidateRect(*(HWND *)(param_1 + 8),(RECT *)0x0,0);
      UpdateWindow(*(HWND *)(param_1 + 8));
      FUN_00408e40();
      iVar4 = GetSystemMetrics(0x20);
      *(int *)(param_1 + 0x18) = iVar4 * 2;
      iVar4 = GetSystemMetrics(0x21);
      *(int *)(param_1 + 0x1c) = iVar4 * 2;
      iVar4 = GetSystemMetrics(4);
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + iVar4;
      return;
    }
  }
  else {
    uVar3 = GetWindowLongA(DAT_004344d4,-0x10);
    SetWindowLongA(DAT_004344d4,-0x10,uVar3 & 0xff3fffff);
    pHVar1 = GetMenu(*(HWND *)(param_1 + 8));
    UVar2 = GetMenuState(pHVar1,0xea61,0);
    if (UVar2 != 0xffffffff) {
      DAT_004376ab = 0;
      DestroyMenu(pHVar1);
      DrawMenuBar(*(HWND *)(param_1 + 8));
      iVar4 = GetSystemMetrics(8);
      *(int *)(param_1 + 0x1c) = iVar4 * 2;
      iVar4 = GetSystemMetrics(7);
      *(int *)(param_1 + 0x18) = iVar4 * 2;
      InvalidateRect(*(HWND *)(param_1 + 8),(RECT *)0x0,0);
      UpdateWindow(*(HWND *)(param_1 + 8));
    }
  }
  return;
}



/* 00408aa0  FUN_00408aa0  133 bytes, 2 callers */

void __fastcall FUN_00408aa0(int param_1)

{
  HMENU hMnu;
  LONG LVar1;
  UINT UVar2;
  LPCSTR lpNewItem;
  LPCSTR pCVar3;
  uint uVar4;
  int iVar5;
  
  hMnu = GetMenu(*(HWND *)(param_1 + 8));
  if (hMnu != (HMENU)0x0) {
    iVar5 = 0;
    lpNewItem = &DAT_00435b31;
    do {
      UVar2 = iVar5 + 0x9c90;
      pCVar3 = lpNewItem + 0x11;
      iVar5 = iVar5 + 1;
      ModifyMenuA(hMnu,UVar2,0,UVar2,lpNewItem);
      lpNewItem = pCVar3;
    } while (pCVar3 < &DAT_00435b75);
    uVar4 = 0;
    do {
      LVar1 = FUN_0040a0c0(uVar4 + 60000);
      if (LVar1 != 0) {
        UVar2 = GetMenuState(hMnu,uVar4 + 61000,0);
        if (UVar2 == 0xffffffff) {
          InsertMenuA(hMnu,0x9caf,0,uVar4 + 61000,(LPCSTR)(LVar1 + 0x48));
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 10);
  }
  return;
}



/* 00408b30  FUN_00408b30  30 bytes, 1 callers */

void FUN_00408b30(int param_1)

{
  LONG LVar1;
  
  LVar1 = FUN_0040a0c0(param_1);
  if (LVar1 != 0) {
    BringWindowToTop(*(HWND *)(LVar1 + 8));
  }
  return;
}



/* 00408b50  FUN_00408b50  39 bytes, 1 callers */

void FUN_00408b50(void)

{
  if ((DAT_004365d0 == -1) && (DAT_004365d4 != -1)) {
    return;
  }
  DAT_004365d0 = 0xffffffff;
  DAT_00434510 = 0xffffffff;
  FUN_00408e40();
  return;
}



/* 00408b80  FUN_00408b80  458 bytes, 1 callers */

void FUN_00408b80(void)

{
  int iVar1;
  HCURSOR pHVar2;
  HANDLE pvVar3;
  BOOL BVar4;
  code *pcVar5;
  undefined4 *puVar6;
  CHAR local_348 [260];
  _WIN32_FIND_DATAA local_244;
  CHAR local_104 [260];
  
  iVar1 = FUN_00409370(s_High_Scores_will_be_cleared_and_t_00432284,4);
  if (iVar1 == 6) {
    pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
    SetCursor(pHVar2);
    puVar6 = &DAT_00436a00;
    for (iVar1 = 0x2da; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    FUN_0040bda0(&DAT_00436468,local_348,s___ds7_0043227c);
    pvVar3 = FindFirstFileA(local_348,&local_244);
    pcVar5 = FindClose_exref;
    if (pvVar3 != (HANDLE)0xffffffff) {
      do {
        FUN_0040bda0(&DAT_00436468,local_348,local_244.cFileName);
        iVar1 = FUN_0040c3d0(local_348);
        if (iVar1 == 0) {
          FindClose(pvVar3);
          return;
        }
        BVar4 = FindNextFileA(pvVar3,&local_244);
        pcVar5 = FindClose_exref;
      } while (BVar4 != 0);
      FindClose(pvVar3);
    }
    FUN_0040bda0(&DAT_00436468,local_348,s___dat_00432274);
    pvVar3 = FindFirstFileA(local_348,&local_244);
    if (pvVar3 != (HANDLE)0xffffffff) {
      do {
        FUN_0040bda0(&DAT_00436468,local_348,local_244.cFileName);
        iVar1 = FUN_0040c3d0(local_348);
        if (iVar1 == 0) {
          (*pcVar5)(pvVar3);
          return;
        }
        BVar4 = FindNextFileA(pvVar3,&local_244);
      } while (BVar4 != 0);
      (*pcVar5)(pvVar3);
    }
    FUN_00405790(s_Score_v11_0043210c,local_104);
    FUN_0040bda0(&DAT_00436468,local_348,local_104);
    FUN_0040c3d0(local_348);
    DAT_004376b5 = 0;
    pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    SetCursor(pHVar2);
    DAT_00434510 = 0xffffffff;
    DAT_004365cc = 1;
    FUN_00405de0(0);
  }
  return;
}



/* 00408d50  FUN_00408d50  45 bytes, 1 callers */

void FUN_00408d50(void)

{
  int iVar1;
  
  iVar1 = FUN_00409370(s_Restart_Stage__004322d8,4);
  if (iVar1 == 6) {
    DAT_00434510 = 0xffffffff;
    FUN_00405de0(DAT_0043450c);
  }
  return;
}



/* 00408d80  FUN_00408d80  38 bytes, 1 callers */

void FUN_00408d80(void)

{
  FUN_0040cd20(&DAT_00435db0,DAT_00434514,0);
  DAT_00434524 = 0;
  FUN_00408b50();
  FUN_00408e40();
  return;
}



/* 00408db0  FUN_00408db0  41 bytes, 1 callers */

void FUN_00408db0(void)

{
  if (DAT_00434514 != -1) {
    FUN_0040cd20(&DAT_00435db0,DAT_00434514 + 2,0);
  }
  DAT_00434524 = 1;
  FUN_00408e40();
  return;
}



/* 00408de0  FUN_00408de0  36 bytes, 4 callers */

void __cdecl FUN_00408de0(int param_1)

{
  if (param_1 == 1) {
    DAT_0043452c = DAT_0043452c + 1;
    return;
  }
  if ((param_1 == 0) && (DAT_0043452c != 0)) {
    DAT_0043452c = DAT_0043452c + -1;
  }
  return;
}



/* 00408e10  FUN_00408e10  10 bytes, 2 callers */

void __cdecl FUN_00408e10(undefined4 param_1)

{
  DAT_00434528 = param_1;
  return;
}



/* 00408e20  FUN_00408e20  25 bytes, 1 callers */

void FUN_00408e20(void)

{
  PostMessageA(DAT_004344d4,0x111,0x9c5e,0);
  return;
}



/* 00408e40  FUN_00408e40  30 bytes, 12 callers */

void FUN_00408e40(void)

{
  if (DAT_004344e4 != 0) {
    FUN_00408e60();
    FUN_00408ea0();
    FUN_00408ed0();
    FUN_004090e0();
    return;
  }
  return;
}



/* 00408e60  FUN_00408e60  61 bytes, 1 callers */

void FUN_00408e60(void)

{
  bool bVar1;
  
  FUN_00409db0(0x9c54,1);
  bVar1 = DAT_0043450c != -1;
  FUN_00409db0(0x9c55,(uint)bVar1);
  FUN_00409db0(0x9c73,(uint)bVar1);
  return;
}



/* 00408ea0  FUN_00408ea0  47 bytes, 1 callers */

void FUN_00408ea0(void)

{
  bool bVar1;
  
  bVar1 = DAT_0043450c != -1;
  FUN_00409db0(0x9cb4,(uint)bVar1);
  FUN_00409db0(0x9c61,(uint)bVar1);
  return;
}



/* 00408ed0  FUN_00408ed0  514 bytes, 1 callers */

void FUN_00408ed0(void)

{
  LONG LVar1;
  uint uVar2;
  
  uVar2 = (uint)(DAT_0043450c != -1);
  FUN_00409db0(60000,uVar2);
  FUN_00409db0(0xea61,uVar2);
  FUN_00409db0(0xea62,uVar2);
  FUN_00409db0(0xea63,uVar2);
  FUN_00409db0(0xea65,uVar2);
  LVar1 = FUN_0040a0c0(60000);
  FUN_00409d50(60000,(uint)(LVar1 != 0));
  LVar1 = FUN_0040a0c0(0xea61);
  FUN_00409d50(0xea61,(uint)(LVar1 != 0));
  LVar1 = FUN_0040a0c0(0xea63);
  FUN_00409d50(0xea63,(uint)(LVar1 != 0));
  LVar1 = FUN_0040a0c0(0xea62);
  FUN_00409d50(0xea62,(uint)(LVar1 != 0));
  LVar1 = FUN_0040a0c0(0xea65);
  FUN_00409d50(0xea65,(uint)(LVar1 == 0));
  LVar1 = FUN_0040a0c0(0xea65);
  FUN_00409db0(0x9cad,(uint)(LVar1 != 0));
  FUN_00409d50(0x9cad,(uint)(DAT_004376a3 != '\0'));
  FUN_00409d50(0x9c70,(uint)(DAT_004376ae == '\b'));
  FUN_00409d50(0x9c71,(uint)(DAT_004376ae == '\x10'));
  FUN_00409d50(0x9c72,(uint)(DAT_004376ae == ' '));
  LVar1 = FUN_0040a0c0(60000);
  uVar2 = (uint)(LVar1 != 0);
  FUN_00409db0(0x9c70,uVar2);
  FUN_00409db0(0x9c71,uVar2);
  FUN_00409db0(0x9c72,uVar2);
  FUN_00409db0(0x9c90,uVar2);
  FUN_00409db0(0x9c91,uVar2);
  FUN_00409db0(0x9c92,uVar2);
  FUN_00409db0(0x9c93,uVar2);
  return;
}



/* 004090e0  FUN_004090e0  654 bytes, 1 callers */

void FUN_004090e0(void)

{
  WPARAM WVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = (uint)(DAT_0043450c != -1);
  if (DAT_004365d4 == -1) {
    uVar3 = 0;
  }
  FUN_00409db0(0x9c90,uVar3);
  FUN_00409db0(0x9c91,uVar3);
  FUN_00409db0(0x9c92,uVar3);
  FUN_00409db0(0x9c93,uVar3);
  FUN_00409db0(0x9c4c,uVar3);
  FUN_00409db0(0x9c7d,uVar3);
  FUN_00409db0(0x9c7e,uVar3);
  FUN_00409db0(0x9c6d,uVar3);
  FUN_00409db0(0x9c5e,uVar3);
  FUN_00409d50(0x9c6d,(uint)(DAT_00434524 == 0));
  FUN_00409d50(0x9c5e,DAT_00434524);
  if (DAT_004365dc == 0) {
    FUN_00409d50(0x9c7d,0);
    FUN_00409d50(0x9c7e,0);
  }
  FUN_00409db0(0x9cae,uVar3);
  if (DAT_004365d0 == -1) {
    FUN_00409db0(0x9c4c,0);
    FUN_00409db0(0x9cb1,1);
    if (DAT_004365d0 == -1) goto LAB_00409268;
  }
  FUN_00409db0(0x9c7d,0);
  FUN_00409db0(0x9c7e,0);
  FUN_00409db0(0x9cae,0);
  FUN_00409d50(0x9c7d,0);
  FUN_00409d50(0x9c7e,0);
  FUN_00409db0(0x9cb1,0);
LAB_00409268:
  if (DAT_004365d4 == -1) {
    FUN_00409db0(0x9cae,1);
    FUN_00409db0(0x9cb1,0);
  }
  FUN_00409db0(0x9cb1,(uint)(DAT_00434524 == 0));
  FUN_00409db0(0x9c7d,(uint)(DAT_00434524 == 0));
  iVar4 = 0;
  iVar5 = 0;
  FUN_00409db0(0x9c7e,(uint)(DAT_00434524 == 0));
  do {
    puVar2 = (uint *)(DAT_00434534 + 4 + iVar5);
    WVar1 = iVar4 + 0x9c90;
    iVar5 = iVar5 + 0x38;
    iVar4 = iVar4 + 1;
    FUN_00409db0(WVar1,(uint)((*puVar2 & 0x40) == 0));
  } while (iVar5 < 0xe0);
  if (DAT_004321c8 == 0) {
    FUN_00409d50(0x9c7d,0);
    FUN_00409d50(0x9c7e,0);
  }
  else {
    if ((DAT_004321c8 & 1) != 0) {
      FUN_00409d50(0x9c7d,1);
    }
    if ((DAT_004321c8 & 2) != 0) {
      FUN_00409d50(0x9c7e,1);
      return;
    }
  }
  return;
}



/* 00409370  FUN_00409370  55 bytes, 17 callers */

int __cdecl FUN_00409370(LPCSTR param_1,uint param_2)

{
  int iVar1;
  
  FUN_00408de0(1);
  iVar1 = MessageBoxA((HWND)0x0,param_1,&DAT_004376dc,param_2 | 0x2020);
  FUN_00408de0(0);
  return iVar1;
}



/* 004093b0  FUN_004093b0  217 bytes, 3 callers */

void FUN_004093b0(void)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_0040a0c0(0xea65);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))();
  }
  piVar1 = (int *)FUN_0040a0c0(60000);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea61);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea63);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea62);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea66);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea67);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea68);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))();
  }
  piVar1 = (int *)FUN_0040a0c0(0xea69);
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00409485. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0x3c))();
    return;
  }
  return;
}



/* 00409490  FUN_00409490  35 bytes, 9 callers */

void __cdecl FUN_00409490(LPSTR param_1,undefined4 param_2,undefined4 param_3)

{
  wsprintfA(param_1,s__s_s_s_004322e8,&DAT_00437588,param_2,param_3);
  return;
}



/* 004094c0  FUN_004094c0  80 bytes, 1 callers */

undefined4 FUN_004094c0(void)

{
  int iVar1;
  
  if (((DAT_004344dc == '\0') && (DAT_004365d0 == -1)) && (DAT_004365d4 == 0)) {
    iVar1 = FUN_00409370(s_End_Game__004322f0,4);
    if (iVar1 == 7) {
      return 0;
    }
    FUN_00405b90(0x432268);
    return 1;
  }
  FUN_00409510();
  return 1;
}



/* 00409510  FUN_00409510  91 bytes, 2 callers */

void FUN_00409510(void)

{
  int iVar1;
  CHAR local_104 [260];
  
  iVar1 = FUN_0040bda0(&DAT_00436468,local_104,s_Temp_ds7_00432268);
  if (iVar1 != 0) {
    FUN_0040c3d0(local_104);
    iVar1 = FUN_0040bda0(&DAT_00436468,local_104,s_Temp_dat_004322fc);
    if (iVar1 != 0) {
      FUN_0040c3d0(local_104);
    }
  }
  return;
}



/* 00409570  FUN_00409570  96 bytes, 2 callers */

void FUN_00409570(void)

{
  if (DAT_004376b6 == '\0') {
    FUN_004095d0(0x72,0,*(HWND *)(DAT_004344e4 + 8));
    FUN_004095d0(0x79,0,*(HWND *)(DAT_004344e4 + 8));
    FUN_00409370(s_Congratulations__you_have_comple_00432308,0);
    DAT_004376b6 = '\x01';
    FUN_0040cd20(&DAT_00435db0,DAT_00434514 + 2,1);
  }
  return;
}



/* 004095d0  FUN_004095d0  1311 bytes, 8 callers */

void __cdecl FUN_004095d0(uint param_1,uint param_2,HWND param_3)

{
  void *pvVar1;
  undefined4 *this;
  undefined4 *unaff_FS_OFFSET;
  uint local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00409bc2;
  *unaff_FS_OFFSET = &local_10;
  this = (undefined4 *)0x0;
  FUN_00408de0(1);
  if (param_1 < 0x71) {
    if (param_1 == 0x70) {
      pvVar1 = (void *)FUN_00427f90(0x23998);
      local_8 = 1;
      this = (undefined4 *)0x0;
      if (pvVar1 != (void *)0x0) {
        this = FUN_00418cd0(pvVar1,0x70);
      }
      local_8 = 0xffffffff;
      local_14 = 0x70;
      goto LAB_00409616;
    }
    if (param_1 == 0x69) {
      pvVar1 = (void *)FUN_00427f90(0x583c);
      local_8 = 0;
      this = (undefined4 *)0x0;
      if (pvVar1 != (void *)0x0) {
        this = FUN_0040fb80(pvVar1,0x69,param_2);
      }
      local_8 = 0xffffffff;
      local_14 = 0x69;
      goto LAB_00409616;
    }
  }
  else if (param_1 < 0x77) {
    if (param_1 == 0x76) {
      pvVar1 = (void *)FUN_00427f90(0x24c);
      local_8 = 3;
      this = (undefined4 *)0x0;
      if (pvVar1 != (void *)0x0) {
        this = FUN_00412ed0(pvVar1,0x76);
      }
      local_8 = 0xffffffff;
      local_14 = 0x76;
      goto LAB_00409616;
    }
    if (param_1 == 0x72) {
      pvVar1 = (void *)FUN_00427f90(0x234);
      local_8 = 2;
      this = (undefined4 *)0x0;
      if (pvVar1 != (void *)0x0) {
        this = FUN_00411fe0(pvVar1,0x72);
      }
      local_8 = 0xffffffff;
      local_14 = 0x72;
      goto LAB_00409616;
    }
  }
  else {
    if (0x9c4c < param_1) {
      switch(param_1) {
      case 0x9c54:
        this = (undefined4 *)FUN_00427f90(0x234);
        local_8 = 7;
        if (this == (undefined4 *)0x0) {
          this = (undefined4 *)0x0;
        }
        else {
          FUN_0040e6b0(this,param_1);
          *this = &PTR_LAB_00430128;
        }
        local_8 = 0xffffffff;
        local_14 = 0x68;
        break;
      case 0x9c55:
        pvVar1 = (void *)FUN_00427f90(0x460);
        this = (undefined4 *)0x0;
        local_8 = 9;
        if (pvVar1 != (void *)0x0) {
          this = FUN_0040f580(pvVar1,param_1);
        }
        local_8 = 0xffffffff;
        local_14 = 0x6a;
        break;
      default:
        goto switchD_004096be_caseD_9c56;
      case 0x9c61:
        pvVar1 = (void *)FUN_00427f90(0x238);
        this = (undefined4 *)0x0;
        local_8 = 10;
        if (pvVar1 != (void *)0x0) {
          this = FUN_0040ef20(pvVar1,param_1);
        }
        local_8 = 0xffffffff;
        local_14 = 0x73;
        break;
      case 0x9c65:
        pvVar1 = (void *)FUN_00427f90(0x9398);
        this = (undefined4 *)0x0;
        local_8 = 0xb;
        if (pvVar1 != (void *)0x0) {
          this = FUN_00413e50(pvVar1,param_1);
        }
        local_8 = 0xffffffff;
        local_14 = 0x7b;
        break;
      case 0x9c66:
        pvVar1 = (void *)FUN_00427f90(0x23c);
        this = (undefined4 *)0x0;
        local_8 = 0xc;
        if (pvVar1 != (void *)0x0) {
          this = FUN_00413ad0(pvVar1,param_1);
        }
        local_8 = 0xffffffff;
        local_14 = 0x7c;
        break;
      case 0x9c73:
        pvVar1 = (void *)FUN_00427f90(0x460);
        this = (undefined4 *)0x0;
        local_8 = 0xd;
        if (pvVar1 != (void *)0x0) {
          this = FUN_0040fa00(pvVar1,param_1);
        }
        local_8 = 0xffffffff;
        local_14 = 0x6b;
        break;
      case 0x9c77:
        pvVar1 = (void *)FUN_00427f90(0x234);
        this = (undefined4 *)0x0;
        local_8 = 0xe;
        if (pvVar1 != (void *)0x0) {
          this = FUN_0040ee10(pvVar1,param_1);
        }
        local_8 = 0xffffffff;
        local_14 = 0x78;
        break;
      case 0x9cb4:
        pvVar1 = (void *)FUN_00427f90(0x22748);
        this = (undefined4 *)0x0;
        local_8 = 0xf;
        if (pvVar1 != (void *)0x0) {
          this = FUN_00418460(pvVar1,param_1);
        }
        local_8 = 0xffffffff;
        local_14 = 0x7e;
        break;
      case 0x9cb5:
        this = (undefined4 *)FUN_00427f90(0x234);
        local_8 = 0x10;
        if (this == (undefined4 *)0x0) {
          this = (undefined4 *)0x0;
        }
        else {
          FUN_0040e6b0(this,param_1);
          *this = &PTR_LAB_004300e8;
        }
        local_8 = 0xffffffff;
        local_14 = 0x7f;
      }
      goto LAB_00409616;
    }
    if (param_1 == 0x9c4c) {
      pvVar1 = (void *)FUN_00427f90(0x238);
      local_8 = 6;
      this = (undefined4 *)0x0;
      if (pvVar1 != (void *)0x0) {
        this = FUN_004132b0(pvVar1,0x9c4c);
      }
      local_8 = 0xffffffff;
      local_14 = 0x77;
      goto LAB_00409616;
    }
    if (param_1 == 0x79) {
      pvVar1 = (void *)FUN_00427f90(0x234);
      local_8 = 4;
      this = (undefined4 *)0x0;
      if (pvVar1 != (void *)0x0) {
        this = FUN_00418980(pvVar1,0x79);
      }
      local_8 = 0xffffffff;
      local_14 = 0x79;
      goto LAB_00409616;
    }
    if (param_1 == 0x7a) {
      pvVar1 = (void *)FUN_00427f90(0x244);
      local_8 = 5;
      this = (undefined4 *)0x0;
      if (pvVar1 != (void *)0x0) {
        this = FUN_00411ab0(pvVar1,0x7a,param_2);
      }
      local_8 = 0xffffffff;
      local_14 = 0x7a;
      goto LAB_00409616;
    }
  }
switchD_004096be_caseD_9c56:
LAB_00409616:
  if (this != (undefined4 *)0x0) {
    DAT_004321bc = 1;
    DialogBoxParamA(DAT_004344d0,(LPCSTR)(local_14 & 0xffff),param_3,(DLGPROC)&LAB_00426440,
                    (LPARAM)this);
    if (this != (undefined4 *)0x0) {
      (**(code **)*this)(1);
    }
    DAT_004321bc = 0;
  }
  FUN_00408e40();
  FUN_00408de0(0);
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 00409cc9  FUN_00409cc9  8 bytes, 0 callers */

void FUN_00409cc9(void)

{
  int unaff_EBP;
  
  FUN_0040e720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 00409d39  FUN_00409d39  8 bytes, 0 callers */

void FUN_00409d39(void)

{
  int unaff_EBP;
  
  FUN_0040e720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 00409d50  FUN_00409d50  83 bytes, 6 callers */

void __cdecl FUN_00409d50(WPARAM param_1,int param_2)

{
  void *this;
  HMENU hMenu;
  
  this = (void *)FUN_0040a0c0(0xea65);
  if (this != (void *)0x0) {
    FUN_0041bef0(this,param_1,param_2);
  }
  hMenu = GetMenu(DAT_004344d4);
  if (hMenu != (HMENU)0x0) {
    CheckMenuItem(hMenu,param_1,-(uint)(param_2 == 1) & 8);
  }
  return;
}



/* 00409db0  FUN_00409db0  93 bytes, 4 callers */

void __cdecl FUN_00409db0(WPARAM param_1,int param_2)

{
  void *this;
  HMENU hMenu;
  
  this = (void *)FUN_0040a0c0(0xea65);
  if (this != (void *)0x0) {
    FUN_0041bf10(this,param_1,param_2);
  }
  if ((DAT_004344e4 != 0) && (hMenu = GetMenu(*(HWND *)(DAT_004344e4 + 8)), hMenu != (HMENU)0x0)) {
    EnableMenuItem(hMenu,param_1,(uint)(param_2 != 1));
  }
  return;
}



/* 00409e10  FUN_00409e10  114 bytes, 1 callers */

void FUN_00409e10(void)

{
  int *piVar1;
  
  if (DAT_004344e8 != (int *)0x0) {
    (**(code **)(*DAT_004344e8 + 0x10))();
  }
  if (DAT_004344f0 != (int *)0x0) {
    (**(code **)(*DAT_004344f0 + 0x10))();
  }
  if (DAT_004344ec != (int *)0x0) {
    (**(code **)(*DAT_004344ec + 0x10))();
  }
  if (DAT_004344f4 != (int *)0x0) {
    (**(code **)(*DAT_004344f4 + 0x10))();
  }
  piVar1 = &DAT_004344f8;
  do {
    if ((int *)*piVar1 != (int *)0x0) {
      (**(code **)(*(int *)*piVar1 + 0x10))();
    }
    piVar1 = piVar1 + 1;
  } while (piVar1 < &DAT_00434508);
  return;
}



/* 00409e90  FUN_00409e90  126 bytes, 1 callers */

int FUN_00409e90(void)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = 0;
  iVar5 = 0;
  iVar6 = 0;
  do {
    bVar1 = *(byte *)(DAT_0043453c + iVar6);
    if ((bVar1 < 0x40) && ((*(byte *)(DAT_00434538 + 0xd + (uint)bVar1 * 0x224) & 0x20) == 0)) {
      iVar2 = FUN_0040a020((uint)bVar1,iVar5 / 0x30,iVar5 % 0x30,1);
      if (iVar2 == 1) {
        iVar4 = iVar4 + 1;
      }
    }
    iVar6 = iVar6 + 0x18;
    iVar5 = iVar5 + 1;
  } while (iVar6 < 0xd800);
  piVar3 = (int *)FUN_0040a0c0(60000);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 100))();
  }
  return iVar4;
}



/* 00409f10  FUN_00409f10  126 bytes, 1 callers */

int FUN_00409f10(void)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = 0;
  iVar6 = 0;
  iVar5 = 0;
  do {
    bVar1 = *(byte *)(DAT_0043453c + iVar5);
    if ((bVar1 < 0x40) && ((*(byte *)(DAT_00434538 + 0xd + (uint)bVar1 * 0x224) & 0x20) == 0)) {
      iVar2 = FUN_0040a020((uint)bVar1,iVar6 / 0x30,iVar6 % 0x30,0);
      if (iVar2 == 1) {
        iVar4 = iVar4 + 1;
      }
    }
    iVar5 = iVar5 + 0x18;
    iVar6 = iVar6 + 1;
  } while (iVar5 < 0xd800);
  piVar3 = (int *)FUN_0040a0c0(60000);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 100))();
  }
  return iVar4;
}



/* 00409f90  FUN_00409f90  140 bytes, 4 callers */

void FUN_00409f90(void)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  FUN_0040a1c0(0x15f91);
  do {
    iVar3 = DAT_00434538 + iVar4;
    if ((*(byte *)(iVar3 + 0x21c) & 1) != 0) {
      *(undefined1 *)(iVar3 + 0xc) = *(undefined1 *)(iVar3 + 0xe);
      puVar1 = (uint *)(DAT_00434538 + 0x21c + iVar4);
      *puVar1 = *puVar1 & 0xfffffffe;
      *(undefined1 *)(DAT_00434538 + 0x220 + iVar4) = 0xff;
    }
    iVar4 = iVar4 + 0x224;
  } while (iVar4 < 0x8900);
  piVar2 = (int *)FUN_0040a0c0(60000);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 100))();
  }
  DAT_004365dc = 0;
  DAT_004321c8 = 0;
  FUN_00408e40();
  return;
}



/* 0040a020  FUN_0040a020  149 bytes, 3 callers */

undefined4 __cdecl FUN_0040a020(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  
  iVar1 = param_1 * 0x224;
  iVar3 = DAT_00434538 + iVar1;
  if ((*(char *)(iVar3 + 4) != DAT_004365cd) || ((*(byte *)(iVar3 + 0x10) & 2) != 0)) {
    return 0;
  }
  if ((param_4 == 0) && ((*(byte *)(iVar3 + 0xd) & 0x10) != 0)) {
    return 0;
  }
  FUN_00405360();
  FUN_0041a680(param_2,param_3);
  puVar2 = (uint *)(DAT_00434538 + 0x21c + iVar1);
  *puVar2 = *puVar2 | 1;
  *(undefined1 *)(DAT_00434538 + 0x220 + iVar1) = 0;
  *(undefined1 *)(DAT_00434538 + iVar1 + 0xe) = *(undefined1 *)(DAT_00434538 + iVar1 + 0xc);
  *(undefined1 *)(DAT_00434538 + 0xc + iVar1) = 6;
  return 1;
}



/* 0040a0c0  FUN_0040a0c0  71 bytes, 25 callers */

LONG __cdecl FUN_0040a0c0(int param_1)

{
  HWND hWnd;
  LONG LVar1;
  
  hWnd = GetWindow(*(HWND *)(DAT_004344e4 + 8),5);
  while( true ) {
    if (hWnd == (HWND)0x0) {
      return 0;
    }
    LVar1 = GetWindowLongA(hWnd,-0x15);
    if ((LVar1 != 0) && (*(int *)(LVar1 + 4) == param_1)) break;
    hWnd = GetWindow(hWnd,2);
  }
  return LVar1;
}



/* 0040a110  FUN_0040a110  170 bytes, 1 callers */

void FUN_0040a110(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  uVar1 = 0;
  uVar4 = 0;
  piVar3 = (int *)(DAT_00434534 + 0x10);
  do {
    if (uVar1 != DAT_004365cd) {
      uVar4 = uVar4 + *piVar3;
    }
    piVar3 = piVar3 + 0xe;
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 4);
  if (*(uint *)(DAT_00434534 + 0x10 + (uint)DAT_004365cd * 0x38) < uVar4) {
    iVar2 = FUN_0040cdc0(0);
    if (iVar2 != DAT_00434514) {
      FUN_0040cd20(&DAT_00435db0,DAT_00434514,0);
    }
  }
  if (uVar4 < *(uint *)(DAT_00434534 + 0x10 + (uint)DAT_004365cd * 0x38) >> 3) {
    iVar2 = FUN_0040cdc0(0);
    if (iVar2 - DAT_00434514 != 1) {
      FUN_0040cd20(&DAT_00435db0,DAT_00434514 + 1,0);
    }
  }
  return;
}



/* 0040a1c0  FUN_0040a1c0  67 bytes, 9 callers */

void __cdecl FUN_0040a1c0(int param_1)

{
  if (((89999 < param_1) && (param_1 < 0x15f94)) && (DAT_004376a0 != '\0')) {
    param_1 = param_1 + -90000 + DAT_00434514 * 100;
  }
  FUN_0040cd20(&DAT_00435db0,param_1,0);
  return;
}



/* 0040a210  FUN_0040a210  223 bytes, 3 callers */

void FUN_0040a210(void)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  CHAR local_104 [260];
  
  pcVar4 = SetWindowTextA_exref;
  if (DAT_004376ab != '\0') {
    pcVar1 = s_Quest_004323fc;
    if (DAT_004365cc == '\0') {
      pcVar1 = s_Single_004323f4;
    }
    iVar2 = DAT_0043450c + 1;
    pcVar3 = FUN_0041a650(&DAT_004376c8,DAT_0043450c);
    wsprintfA(local_104,s__s__s__d___s_004323e4,&DAT_004376dc,pcVar3,iVar2,pcVar1);
    pcVar4 = SetWindowTextA_exref;
    SetWindowTextA(*(HWND *)(DAT_004344e4 + 8),local_104);
  }
  if (DAT_004344e8 != 0) {
    pcVar1 = s_Quest_004323fc;
    if (DAT_004365cc == '\0') {
      pcVar1 = s_Single_004323f4;
    }
    iVar2 = DAT_0043450c + 1;
    pcVar3 = FUN_0041a650(&DAT_004376c8,DAT_0043450c);
    wsprintfA(local_104,s__s__s__d___s_004323e4,s_Map_Window_004323d8,pcVar3,iVar2,pcVar1);
    (*pcVar4)(*(undefined4 *)(DAT_004344e8 + 8),local_104);
  }
  return;
}



/* 0040a2f0  FUN_0040a2f0  202 bytes, 1 callers */

void FUN_0040a2f0(void)

{
  WPARAM wParam;
  undefined4 *unaff_FS_OFFSET;
  tagPOINT local_1c;
  HMENU local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040a3ba;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e2f0(&local_14);
  local_8 = 0;
  FUN_0040b180(&local_14);
  FUN_0040e400(&local_14);
  FUN_0040e330(&local_14,0,0x9cc5,0);
  GetCursorPos(&local_1c);
  wParam = TrackPopupMenu(local_14,0x102,local_1c.x,local_1c.y,0,*(HWND *)(DAT_004344e4 + 8),
                          (RECT *)0x0);
  if (wParam == 0) {
    local_8 = 0xffffffff;
    FUN_0040a3c4();
    *unaff_FS_OFFSET = local_10;
    return;
  }
  SendMessageA(*(HWND *)(DAT_004344e4 + 8),0x111,wParam,0);
  local_8 = 0xffffffff;
  FUN_0040a3c4();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 0040a3c4  FUN_0040a3c4  8 bytes, 1 callers */

void FUN_0040a3c4(void)

{
  int unaff_EBP;
  
  thunk_FUN_0040e460((undefined4 *)(unaff_EBP + -0x10));
  return;
}



/* 0040a3d0  FUN_0040a3d0  217 bytes, 1 callers */

void FUN_0040a3d0(void)

{
  HWND hWnd;
  LONG LVar1;
  int iVar2;
  
  hWnd = *(HWND *)(DAT_004344e4 + 8);
  if (DAT_004376a2 != '\0') {
    SendMessageA(hWnd,0x111,0xea65,0);
  }
  SendMessageA(hWnd,0x111,60000,0);
  if (DAT_004376a4 != '\0') {
    SendMessageA(hWnd,0x111,0xea61,0);
  }
  if (DAT_004376a5 != '\0') {
    SendMessageA(hWnd,0x111,0xea63,0);
  }
  if (DAT_004376a6 != '\0') {
    SendMessageA(hWnd,0x111,0xea62,0);
  }
  iVar2 = 0;
  do {
    if ((&DAT_004376a7)[iVar2] != '\0') {
      SendMessageA(hWnd,0x111,iVar2 + 0xea66,0);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  if ((DAT_004376a2 != '\0') && (LVar1 = FUN_0040a0c0(0xea65), LVar1 != 0)) {
    BringWindowToTop(*(HWND *)(LVar1 + 8));
  }
  FUN_0040a210();
  return;
}



/* 0040a4b0  FUN_0040a4b0  264 bytes, 1 callers */

void FUN_0040a4b0(void)

{
  LONG LVar1;
  
  LVar1 = FUN_0040a0c0(0xea65);
  DAT_004376a2 = '\x01' - (LVar1 == 0);
  FUN_004093b0();
  FUN_00424f80(DAT_00436460,s_Code0_00432468);
  FUN_00424f80(DAT_00436460,s_Code1_00432460);
  FUN_00424f80(DAT_00436460,s_Code2_00432458);
  FUN_00424f80(DAT_00436460,s_Code3_00432080);
  FUN_00424f80(DAT_00436460,s_Code4_00432450);
  FUN_00424f80(DAT_00436460,s_Code5_00432448);
  FUN_00424f80(DAT_00436460,&DAT_00432440);
  FUN_00424f80(DAT_00436460,&DAT_00432438);
  FUN_00424f80(DAT_00436460,&DAT_00432430);
  FUN_00424f80(DAT_00436460,&DAT_00432428);
  FUN_00424f80(DAT_00436460,s_MapInfol_0043241c);
  FUN_00424f80(DAT_00436460,s_MapInfom_00432410);
  FUN_00424f80(DAT_00436460,s_MapInfos_00432404);
  DAT_004376a5 = 1;
  DAT_004376a6 = 1;
  DAT_004376a4 = 1;
  FUN_0040a3d0();
  return;
}



/* 0040a5e0  FUN_0040a5e0  264 bytes, 1 callers */

void FUN_0040a5e0(void)

{
  POINT Point;
  BOOL BVar1;
  HWND pHVar2;
  LONG LVar3;
  int iVar4;
  tagPOINT local_8;
  
  if (((((DAT_00434524 == 0) && (DAT_00434528 == 0)) && (DAT_0043452c == 0)) &&
      ((DAT_004365d0 != 0 && (DAT_004365d4 != -1)))) && (DAT_004365dc == 0)) {
    if (((DAT_004376ad != '\0') && (BVar1 = GetCursorPos(&local_8), BVar1 != 0)) &&
       ((Point.y = local_8.y, Point.x = local_8.x, pHVar2 = WindowFromPoint(Point),
        pHVar2 != (HWND)0x0 && (LVar3 = FUN_0040a0c0(60000), *(HWND *)(LVar3 + 8) == pHVar2)))) {
      return;
    }
    DAT_0043781c = 4;
    DAT_00435b1c = DAT_00435b1c + 1;
    FUN_0041d740();
    FUN_004204f0();
    FUN_0040b270();
    FUN_0041b370();
    FUN_0041b4f0();
    if (DAT_004344e8 != (int *)0x0) {
      (**(code **)(*DAT_004344e8 + 100))();
    }
    FUN_0040a110();
    FUN_0041f790();
    FUN_0041f090();
    iVar4 = FUN_0041f4c0();
    if (iVar4 == 1) {
      FUN_0040cd20(&DAT_00435db0,DAT_00434514 + 2,0);
    }
    FUN_0040a6f0();
  }
  return;
}



/* 0040a6f0  FUN_0040a6f0  259 bytes, 1 callers */

void FUN_0040a6f0(void)

{
  int iVar1;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  iVar1 = (int)(char)(&DAT_004321d0)[DAT_00435b1c & 0xf];
  local_2 = (undefined1)((int)((uint)DAT_0043756a * iVar1) / 100);
  local_4 = (undefined1)((int)((uint)DAT_00437568 * iVar1) / 100);
  local_1 = 1;
  local_3 = (undefined1)((int)((uint)DAT_00437569 * iVar1) / 100);
  FUN_0040e560(&DAT_004365f0,&local_4,0x1f,1);
  local_2 = (undefined1)((int)((uint)DAT_0043768c._2_1_ * iVar1) / 100);
  local_4 = (undefined1)((int)((uint)(byte)DAT_0043768c * iVar1) / 100);
  local_1 = 1;
  local_3 = (undefined1)((int)((uint)DAT_0043768c._1_1_ * iVar1) / 100);
  FUN_0040e560(&DAT_004365f0,&local_4,0x76,1);
  FUN_0040e600(0x4365f0);
  if (DAT_004344e8 != (int *)0x0) {
    (**(code **)(*DAT_004344e8 + 0x10))();
  }
  if (DAT_004344f0 != (int *)0x0) {
    (**(code **)(*DAT_004344f0 + 0x10))();
  }
  if (DAT_004344ec != (int *)0x0) {
    (**(code **)(*DAT_004344ec + 0x10))();
  }
  return;
}



/* 0040a800  FUN_0040a800  101 bytes, 2 callers */

void FUN_0040a800(void)

{
  if (DAT_004344e8 != (int *)0x0) {
    (**(code **)(*DAT_004344e8 + 100))();
  }
  if (DAT_004344f0 != (int *)0x0) {
    (**(code **)(*DAT_004344f0 + 100))();
  }
  if (DAT_004344f4 != (int *)0x0) {
    (**(code **)(*DAT_004344f4 + 100))();
  }
  if (DAT_004344ec != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0040a861. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_004344ec + 100))();
    return;
  }
  return;
}



/* 0040a870  FUN_0040a870  266 bytes, 23 callers */

void __cdecl
FUN_0040a870(int param_1,int param_2,int param_3,int param_4,LPCSTR param_5,HDC param_6,int param_7,
            int *param_8)

{
  int iVar1;
  BOOL BVar2;
  tagSIZE *psizl;
  COLORREF local_38 [12];
  tagSIZE local_8;
  
  if (param_8 != (int *)0x0) {
    DAT_004321e0 = param_8;
  }
  local_38[0] = 0xffffff;
  local_38[1] = 0;
  local_38[2] = 0xffffff;
  local_38[3] = 0;
  local_38[5] = 0x505050;
  local_38[6] = 0x505050;
  local_38[7] = 0xffffff;
  local_38[8] = 0xffffff;
  local_38[10] = 0;
  local_38[0xb] = 0xffffff;
  local_38[4] = 0xf5;
  local_38[9] = 0xc80000;
  if (param_7 != 0) {
    psizl = &local_8;
    iVar1 = lstrlenA(param_5);
    BVar2 = GetTextExtentPoint32A(param_6,param_5,iVar1,psizl);
    if ((BVar2 != 0) && (DAT_004321e0 != (int *)0x0)) {
      param_1 = (*DAT_004321e0 - local_8.cx) / 2;
    }
  }
  SetTextColor(param_6,local_38[param_4]);
  iVar1 = lstrlenA(param_5);
  TextOutA(param_6,param_1 + 1,param_2 + 1,param_5,iVar1);
  SetTextColor(param_6,local_38[param_3]);
  iVar1 = lstrlenA(param_5);
  TextOutA(param_6,param_1,param_2,param_5,iVar1);
  return;
}



/* 0040a980  FUN_0040a980  1711 bytes, 5 callers */

undefined4 __cdecl FUN_0040a980(int *param_1)

{
  LONG LVar1;
  WPARAM wParam;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined1 *this;
  undefined1 *puVar5;
  undefined4 *unaff_FS_OFFSET;
  UINT_PTR UVar6;
  UINT UVar7;
  CHAR local_150 [256];
  UINT_PTR UStack_50;
  undefined1 local_4c [20];
  undefined1 local_38 [12];
  UINT_PTR local_2c;
  UINT_PTR local_28;
  UINT_PTR local_24;
  UINT_PTR local_20;
  UINT_PTR local_1c;
  UINT_PTR local_18;
  HMENU local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040b072;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e2f0(&local_28);
  local_8 = 0;
  FUN_0040e2f0(&local_24);
  local_8._0_1_ = 1;
  FUN_0040e2f0(&local_14);
  local_8._0_1_ = 2;
  FUN_0040e2f0(&local_20);
  local_8._0_1_ = 3;
  FUN_0040e2f0(&local_2c);
  local_8._0_1_ = 4;
  FUN_0040e2f0(&local_1c);
  local_8._0_1_ = 5;
  FUN_0040e2f0(&local_18);
  local_8._0_1_ = 6;
  FUN_00428220(local_4c,4,8,FUN_0040e2f0,thunk_FUN_0040e460);
  local_8 = CONCAT31(local_8._1_3_,7);
  if (DAT_004365d4 == 0) {
    if (DAT_00434524 == 1) {
      if (DAT_004365d0 == -1) {
        UVar7 = 0x9c6e;
        UVar6 = 0x9c6d;
      }
      else {
        UVar7 = 0x9c6d;
        UVar6 = 0x9c6d;
      }
    }
    else {
      UVar7 = 0x9c5e;
      UVar6 = 0x9c5e;
    }
  }
  else {
    UVar7 = 0x9cae;
    UVar6 = 0x9cae;
  }
  FUN_0040e330(&local_14,UVar6,UVar7,0);
  FUN_0040e400(&local_14);
  if (DAT_004365d4 == 0) {
    UVar6 = 0xc353;
    iVar4 = 0;
    this = local_4c;
    do {
      FUN_0040e310(this,UVar6,&DAT_00435b97,0);
      FUN_0040e310(this,UVar6 + 1,&DAT_00435b86,0);
      wsprintfA(local_150,s__s_continue_00432470,&DAT_00435b86 + (char)(&DAT_00434445)[iVar4] * 0x11
               );
      puVar5 = this + 4;
      FUN_0040e310(this,UVar6 + 2,local_150,0);
      UVar6 = UVar6 + 3;
      iVar4 = iVar4 + 1;
      this = puVar5;
    } while (puVar5 < local_38);
    uVar3 = 0;
    do {
      wsprintfA(local_150,&DAT_00432100,&DAT_00435b86 + (char)(&DAT_00434444)[uVar3] * 0x11);
      switch(uVar3) {
      case 0:
        UVar6 = 50000;
        goto LAB_0040ab69;
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
        FUN_0040e390(&local_20,*(UINT_PTR *)(local_4c + uVar3 * 4 + -4),local_150);
        break;
      case 6:
        UVar6 = 0xc362;
LAB_0040ab69:
        FUN_0040e310(&local_20,UVar6,local_150,0);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 7);
    FUN_0040e420(&local_20,DAT_004365e4 + 50000);
    FUN_0040b180(&local_2c);
    if (DAT_00434524 == 0) {
      FUN_0040e330(&local_14,0x9c7e,0x9c7e,0);
      FUN_0040e330(&local_14,0x9c7d,0x9c7d,0);
    }
    FUN_0040e3b0(&local_14,local_20,0x9caa);
    FUN_0040e400(&local_14);
    if (DAT_00434524 == 0) {
      FUN_0040e330(&local_14,0x9cb1,0x9cb1,0);
    }
    FUN_0040e3b0(&local_14,local_2c,0x9cb7);
    FUN_0040e400(&local_14);
  }
  LVar1 = FUN_0040a0c0(60000);
  if (LVar1 != 0) {
    iVar4 = *(int *)(LVar1 + 0x398);
    FUN_0040e330(&local_24,0x9c70,0x9c70,-(uint)(iVar4 == 8) & 8);
    FUN_0040e330(&local_24,0x9c71,0x9c71,-(uint)(iVar4 == 0x10) & 8);
    FUN_0040e330(&local_24,0x9c72,0x9c72,-(uint)(iVar4 == 0x20) & 8);
    FUN_0040e3b0(&local_14,local_24,0x9cab);
  }
  FUN_0040e330(&local_18,0x9cac,0x9cac,-(uint)(DAT_004376ab == '\0') & 8);
  LVar1 = FUN_0040a0c0(0xea65);
  FUN_0040e330(&local_18,0xea65,0xea65,-(uint)(LVar1 == 0) & 8);
  FUN_0040e400(&local_18);
  FUN_0040e330(&local_18,0x9cad,0x9cad,(DAT_004376a3 == '\0') - 1 & 8);
  LVar1 = FUN_0040a0c0(0xea65);
  if (LVar1 == 0) {
    FUN_0040e440(&local_18,0x9cad,1);
  }
  FUN_0040e400(&local_18);
  LVar1 = FUN_0040a0c0(0xea61);
  FUN_0040e330(&local_18,0xea61,0xea61,(LVar1 == 0) - 1 & 8);
  LVar1 = FUN_0040a0c0(0xea63);
  FUN_0040e330(&local_18,0xea63,0xea63,(LVar1 == 0) - 1 & 8);
  LVar1 = FUN_0040a0c0(0xea62);
  iVar4 = 0;
  FUN_0040e330(&local_18,0xea62,0xea62,(LVar1 == 0) - 1 & 8);
  FUN_0040e400(&local_18);
  do {
    LVar1 = FUN_0040a0c0(iVar4 + 60000);
    if (LVar1 != 0) {
      FUN_0040e310(&local_18,iVar4 + 61000,(LPCSTR)(LVar1 + 0x48),0);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 10);
  FUN_0040e330(&local_18,0x9caf,0x9caf,0);
  FUN_0040e400(&local_14);
  FUN_0040e3b0(&local_14,local_18,0x9cc4);
  FUN_0040e330(&local_28,0x9c54,0x9c54,0);
  FUN_0040e330(&local_28,0x9cb5,0x9cb5,0);
  FUN_0040e330(&local_1c,0x9c73,0x9c73,0);
  FUN_0040e330(&local_1c,0x9c55,0x9c55,0);
  FUN_0040e3b0(&local_1c,local_28,0x9c74);
  FUN_0040e400(&local_1c);
  FUN_0040e330(&local_1c,0x9cae,0x9cae,0);
  FUN_0040e400(&local_1c);
  FUN_0040e330(&local_1c,0x9cb2,0x9cb2,0);
  FUN_0040e400(&local_1c);
  FUN_0040e330(&local_1c,0x9c6c,0x9c6c,0);
  FUN_0040e400(&local_14);
  FUN_0040e3b0(&local_14,local_1c,0x9cc2);
  FUN_0040e400(&local_14);
  FUN_0040e330(&local_14,0,0x9cc5,0);
  DAT_004365dc = 4;
  wParam = TrackPopupMenu(local_14,0x102,*param_1,param_1[1],0,DAT_004344d4,(RECT *)0x0);
  if (wParam == 0) {
    DAT_004365dc = 0;
    local_8._0_1_ = 6;
    FUN_0040b02f();
    local_8._0_1_ = 5;
    FUN_0040b042();
    local_8._0_1_ = 4;
    FUN_0040b04a();
    local_8._0_1_ = 3;
    FUN_0040b052();
    local_8._0_1_ = 2;
    FUN_0040b05a();
    local_8._0_1_ = 1;
    FUN_0040b062();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0040b06a();
    local_8 = 0xffffffff;
    FUN_0040b07c();
    uVar2 = 0;
  }
  else {
    PostMessageA(*(HWND *)(DAT_004344e4 + 8),0x111,wParam,0);
    if ((wParam != 0x9c7e) && (wParam != 0x9c7d)) {
      DAT_004365dc = 0;
    }
    local_8._0_1_ = 6;
    FUN_0040b02f();
    local_8._0_1_ = 5;
    FUN_0040b042();
    local_8._0_1_ = 4;
    FUN_0040b04a();
    local_8._0_1_ = 3;
    FUN_0040b052();
    local_8._0_1_ = 2;
    FUN_0040b05a();
    local_8._0_1_ = 1;
    FUN_0040b062();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0040b06a();
    local_8 = 0xffffffff;
    FUN_0040b07c();
    uVar2 = 1;
  }
  *unaff_FS_OFFSET = local_10;
  return uVar2;
}



/* 0040b02f  FUN_0040b02f  19 bytes, 1 callers */

void FUN_0040b02f(void)

{
  int unaff_EBP;
  
  FUN_004280f0(unaff_EBP + -0x48,4,8,thunk_FUN_0040e460);
  return;
}



/* 0040b042  FUN_0040b042  8 bytes, 1 callers */

void FUN_0040b042(void)

{
  int unaff_EBP;
  
  thunk_FUN_0040e460((undefined4 *)(unaff_EBP + -0x14));
  return;
}



/* 0040b04a  FUN_0040b04a  8 bytes, 1 callers */

void FUN_0040b04a(void)

{
  int unaff_EBP;
  
  thunk_FUN_0040e460((undefined4 *)(unaff_EBP + -0x18));
  return;
}



/* 0040b052  FUN_0040b052  8 bytes, 1 callers */

void FUN_0040b052(void)

{
  int unaff_EBP;
  
  thunk_FUN_0040e460((undefined4 *)(unaff_EBP + -0x28));
  return;
}



/* 0040b05a  FUN_0040b05a  8 bytes, 1 callers */

void FUN_0040b05a(void)

{
  int unaff_EBP;
  
  thunk_FUN_0040e460((undefined4 *)(unaff_EBP + -0x1c));
  return;
}



/* 0040b062  FUN_0040b062  8 bytes, 1 callers */

void FUN_0040b062(void)

{
  int unaff_EBP;
  
  thunk_FUN_0040e460((undefined4 *)(unaff_EBP + -0x10));
  return;
}



/* 0040b06a  FUN_0040b06a  8 bytes, 1 callers */

void FUN_0040b06a(void)

{
  int unaff_EBP;
  
  thunk_FUN_0040e460((undefined4 *)(unaff_EBP + -0x20));
  return;
}



/* 0040b07c  FUN_0040b07c  8 bytes, 1 callers */

void FUN_0040b07c(void)

{
  int unaff_EBP;
  
  thunk_FUN_0040e460((undefined4 *)(unaff_EBP + -0x24));
  return;
}



/* 0040b0a0  FUN_0040b0a0  202 bytes, 1 callers */

void FUN_0040b0a0(void)

{
  WPARAM wParam;
  undefined4 *unaff_FS_OFFSET;
  tagPOINT local_1c;
  HMENU local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040b16a;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e2f0(&local_14);
  local_8 = 0;
  FUN_0040b1d0(&local_14);
  FUN_0040e400(&local_14);
  FUN_0040e330(&local_14,0,0x9cc5,0);
  GetCursorPos(&local_1c);
  wParam = TrackPopupMenu(local_14,0x102,local_1c.x,local_1c.y,0,*(HWND *)(DAT_004344e4 + 8),
                          (RECT *)0x0);
  if (wParam == 0) {
    local_8 = 0xffffffff;
    FUN_0040b174();
    *unaff_FS_OFFSET = local_10;
    return;
  }
  PostMessageA(*(HWND *)(DAT_004344e4 + 8),0x111,wParam,0);
  local_8 = 0xffffffff;
  FUN_0040b174();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 0040b174  FUN_0040b174  8 bytes, 1 callers */

void FUN_0040b174(void)

{
  int unaff_EBP;
  
  thunk_FUN_0040e460((undefined4 *)(unaff_EBP + -0x10));
  return;
}



/* 0040b180  FUN_0040b180  76 bytes, 2 callers */

void __cdecl FUN_0040b180(void *param_1)

{
  LPCSTR pCVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  pCVar1 = &DAT_00435b31;
  iVar2 = 0;
  do {
    FUN_0040e310(param_1,iVar3 + 0x9c90U,pCVar1,0);
    if ((*(byte *)(DAT_00434534 + 4 + iVar2) & 0x40) != 0) {
      FUN_0040e440(param_1,iVar3 + 0x9c90U,1);
    }
    iVar2 = iVar2 + 0x38;
    pCVar1 = pCVar1 + 0x11;
    iVar3 = iVar3 + 1;
  } while (pCVar1 < &DAT_00435b75);
  return;
}



/* 0040b1d0  FUN_0040b1d0  156 bytes, 1 callers */

void __cdecl FUN_0040b1d0(void *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int *piVar4;
  CHAR local_104 [260];
  
  iVar1 = 0;
  piVar4 = &DAT_004344f8;
  iVar2 = 0;
  puVar3 = &DAT_00435b31;
  do {
    wsprintfA(local_104,&DAT_00432100,puVar3);
    FUN_0040e310(param_1,iVar2 + 0xea66,local_104,0);
    if (*piVar4 != 0) {
      FUN_0040e420(param_1,iVar2 + 0xea66);
    }
    if ((*(byte *)(DAT_00434534 + 4 + iVar1) & 0x40) != 0) {
      FUN_0040e440(param_1,iVar2 + 0xea66,1);
    }
    iVar1 = iVar1 + 0x38;
    piVar4 = piVar4 + 1;
    puVar3 = puVar3 + 0x11;
    iVar2 = iVar2 + 1;
  } while (puVar3 < &DAT_00435b75);
  return;
}



/* 0040b270  FUN_0040b270  183 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040b270(void)

{
  int iVar1;
  int iVar2;
  char local_a;
  char local_9;
  
  if (DAT_00437570 != 0) {
    *(undefined4 *)(DAT_0043453c + 0x14 + (DAT_00437574 * 0x30 + _DAT_00437578) * 0x18) = 0;
    FUN_0041d6d0((int)DAT_0043757d,&local_a);
    iVar2 = (int)local_a * (int)DAT_0043757c + DAT_00437574;
    iVar1 = (int)local_9 * (int)DAT_0043757c + _DAT_00437578;
    if ((((-1 < iVar2) && (-1 < iVar1)) && (iVar2 < 0x30)) && (iVar1 < 0x30)) {
      DAT_00437574 = iVar2;
      _DAT_00437578 = iVar1;
      *(int *)(DAT_0043453c + 0x14 + (iVar2 * 0x30 + iVar1) * 0x18) = DAT_00437570;
      return;
    }
    DAT_00437570 = 0;
  }
  return;
}



/* 0040b330  FUN_0040b330  264 bytes, 3 callers */

undefined4 FUN_0040b330(void)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  bVar2 = *(byte *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18);
  if ((bVar2 != 0) && ((bVar2 < 0xc || (0x10 < bVar2)))) {
    return 3;
  }
  iVar4 = FUN_0041e670(DAT_0043644c,DAT_00436450);
  if (iVar4 != 0) {
    return 3;
  }
  iVar4 = FUN_0041a8d0(100);
  if (iVar4 == 0) {
    return 2;
  }
  uVar5 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
  if (199 < uVar5) {
    uVar5 = 200;
  }
  *(char *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) = (char)DAT_00437580 + '\b';
  *(uint *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18) = (uVar5 >> 1) + 1;
  puVar1 = (uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
  uVar3 = *puVar1;
  if (uVar3 <= uVar5) {
    FUN_00420b30(DAT_0043756c,DAT_0043644c,DAT_00436450);
    return 6;
  }
  *puVar1 = uVar3 - uVar5;
  return 1;
}



/* 0040b440  FUN_0040b440  575 bytes, 2 callers */

undefined4 FUN_0040b440(void)

{
  uint *puVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  iVar5 = DAT_0043756c * 0x224 + DAT_00434538;
  uVar7 = (uint)*(byte *)(iVar5 + 2);
  uVar6 = (uint)*(byte *)(iVar5 + 3);
  iVar5 = FUN_0041ac10(DAT_0043644c,DAT_00436450,uVar7,uVar6);
  if (iVar5 == 0) {
    FUN_00421750();
    return 3;
  }
  if (iVar5 != 1) {
    return 3;
  }
  iVar5 = (uVar7 * 0x30 + uVar6) * 0x18;
  pbVar3 = (byte *)(DAT_0043453c + iVar5);
  if (*pbVar3 < 0x40) {
    FUN_0041ac40();
    return 2;
  }
  bVar2 = pbVar3[0x10];
  if (bVar2 == 0x7b) {
    uVar6 = ~(*(int *)(pbVar3 + 0xc) - 0xffU) + 1;
    uVar7 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 4;
    if ((int)uVar6 < (int)uVar7) {
      uVar7 = uVar6;
    }
    iVar4 = FUN_0041a8d0((int)(uVar7 + ((int)uVar7 >> 0x1f & 3U)) >> 2);
    if (iVar4 == 0) {
      FUN_0041ac40();
      return 2;
    }
    puVar1 = (uint *)(DAT_0043453c + 0xc + iVar5);
    if (*puVar1 < 0xff) {
      *puVar1 = *puVar1 + uVar7;
    }
    else {
      *puVar1 = 0xff;
    }
    FUN_0041ac40();
    return 1;
  }
  if ((bVar2 == 0) || ((byte)(bVar2 - 0xc) < 5)) {
    uVar7 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 4;
    if ((int)(*(int *)(pbVar3 + 0xc) + 0xffU) < (int)uVar7) {
      uVar7 = *(int *)(pbVar3 + 0xc) + 0xffU;
    }
    iVar4 = FUN_0041a8d0((int)(uVar7 + ((int)uVar7 >> 0x1f & 3U)) >> 2);
    if (iVar4 == 0) {
      FUN_0041ac40();
      return 2;
    }
    puVar1 = (uint *)(DAT_0043453c + 0xc + iVar5);
    uVar6 = *puVar1;
    if (uVar6 < uVar7) {
      *puVar1 = ~(uVar6 - uVar7);
      *(undefined1 *)(DAT_0043453c + 0x10 + iVar5) = 0x7b;
      FUN_00405330();
      FUN_0040cd20(&DAT_00435db0,DAT_00434514 * 100 + 6,1);
      return 1;
    }
    *puVar1 = uVar6 - uVar7;
    FUN_0041ac40();
    return 4;
  }
  iVar5 = FUN_004208b0(uVar7,uVar6);
  if (iVar5 == 1) {
    FUN_0041ac40();
    return 2;
  }
  iVar5 = FUN_00421910();
  if (iVar5 == 1) {
    FUN_0041ac40();
    return 2;
  }
  return 3;
}



/* 0040b680  FUN_0040b680  439 bytes, 2 callers */

undefined4 FUN_0040b680(void)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar5 = DAT_0043756c * 0x224 + DAT_00434538;
  uVar3 = (uint)*(byte *)(iVar5 + 2);
  bVar2 = *(byte *)(iVar5 + 3);
  uVar8 = (uint)bVar2;
  iVar5 = FUN_0041ac10(DAT_0043644c,DAT_00436450,uVar3,uVar8);
  if (iVar5 == 0) {
    FUN_00421750();
    return 3;
  }
  if (iVar5 != 1) {
    return 3;
  }
  if ((((uVar3 == 0) || (uVar8 == 0)) || (0x2e < uVar3)) || (0x2e < bVar2)) {
    return 3;
  }
  iVar5 = (uVar3 * 0x30 + uVar8) * 0x18;
  iVar4 = DAT_0043453c + iVar5;
  bVar2 = *(byte *)(iVar4 + 0x10);
  if (bVar2 == 0x7a) {
    iVar6 = 2;
    uVar7 = *(int *)(iVar4 + 0xc) + 0xff;
  }
  else {
    if ((bVar2 < 0x30) || (0x5f < bVar2)) {
      return 3;
    }
    iVar6 = 0x1e;
    uVar7 = *(int *)(iVar4 + 0xc) + 1;
  }
  uVar9 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 4;
  if (uVar7 < uVar9) {
    uVar9 = uVar7;
  }
  iVar4 = FUN_0041a8d0(uVar9 * iVar6);
  if (iVar4 == 0) {
    FUN_0041ac40();
    return 2;
  }
  puVar1 = (uint *)(DAT_0043453c + 0xc + iVar5);
  uVar7 = *puVar1;
  if (uVar9 < uVar7) {
    *puVar1 = uVar7 - uVar9;
    FUN_0041ac40();
    return 4;
  }
  *puVar1 = ~(uVar7 - uVar9) + 1;
  *(undefined1 *)(DAT_0043453c + 0x10 + iVar5) = 0x20;
  FUN_0041acc0(uVar3,uVar8);
  FUN_0041ad90();
  FUN_0041ac40();
  FUN_0040cd20(&DAT_00435db0,DAT_00434514 * 100 + 7,1);
  return 1;
}



/* 0040b840  FUN_0040b840  277 bytes, 2 callers */

undefined4 FUN_0040b840(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  
  iVar2 = DAT_0043756c * 0x224 + DAT_00434538;
  uVar3 = (uint)*(byte *)(iVar2 + 2);
  uVar1 = (uint)*(byte *)(iVar2 + 3);
  iVar2 = FUN_0041ac10(DAT_0043644c,DAT_00436450,uVar3,uVar1);
  if (iVar2 == 0) {
    FUN_00421750();
    return 4;
  }
  if (iVar2 != 1) {
    return 3;
  }
  iVar2 = (uVar3 * 0x30 + uVar1) * 0x18;
  iVar4 = DAT_0043453c + iVar2;
  if (*(char *)(iVar4 + 0x10) != '{') {
    return 3;
  }
  puVar5 = (uint *)(iVar4 + 0xc);
  uVar1 = *puVar5;
  uVar3 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 5;
  if (uVar1 != 0) {
    if (uVar3 < uVar1) {
      *puVar5 = uVar1 - uVar3;
      FUN_0041ac40();
      return 4;
    }
    *puVar5 = 0;
  }
  *(undefined1 *)(DAT_0043453c + 0x10 + iVar2) = 0;
  FUN_0041ad90();
  FUN_0041ac40();
  FUN_0040cd20(&DAT_00435db0,DAT_00434514 * 100 + 4,1);
  return 1;
}



/* 0040b960  FUN_0040b960  417 bytes, 2 callers */

undefined4 FUN_0040b960(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = DAT_0043756c * 0x224 + DAT_00434538;
  uVar5 = (uint)*(byte *)(iVar3 + 2);
  uVar2 = (uint)*(byte *)(iVar3 + 3);
  iVar3 = FUN_0041ac10(DAT_0043644c,DAT_00436450,uVar5,uVar2);
  if (iVar3 == 0) {
    FUN_00421750();
    return 4;
  }
  if (iVar3 != 1) {
    return 3;
  }
  iVar3 = (uVar5 * 0x30 + uVar2) * 0x18;
  iVar4 = DAT_0043453c + iVar3;
  if (*(char *)(iVar4 + 0x10) == 'z') {
    *(int *)(iVar4 + 0xc) =
         *(int *)(iVar4 + 0xc) + (*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 5);
    puVar1 = (uint *)(DAT_0043453c + 0xc + iVar3);
    if (0xff < *puVar1) {
      *puVar1 = 0xff;
    }
    FUN_0041ac40();
    return 1;
  }
  if (0xf < (byte)(*(char *)(iVar4 + 0x10) - 0x20U)) {
    return 3;
  }
  uVar5 = *(int *)(iVar4 + 0xc) + 0xff;
  uVar2 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 5;
  if ((int)uVar5 <= (int)uVar2) {
    uVar2 = uVar5;
  }
  iVar6 = *(int *)(iVar4 + 0xc) - uVar2;
  if (0 < iVar6) {
    *(int *)(iVar4 + 0xc) = iVar6;
    FUN_0041ac40();
    return 4;
  }
  *(int *)(iVar4 + 0xc) = 0;
  *(undefined1 *)(DAT_0043453c + 0x10 + iVar3) = 0x7a;
  FUN_00405330();
  if (*(byte *)(DAT_0043453c + iVar3) < 0x40) {
    FUN_00420aa0((uint)*(byte *)(DAT_0043453c + iVar3),(char)DAT_00437580);
  }
  FUN_0041ac40();
  FUN_0040cd20(&DAT_00435db0,DAT_00434514 * 100 + 5,1);
  return 1;
}



/* 0040bb10  FUN_0040bb10  260 bytes, 2 callers */

undefined4 FUN_0040bb10(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  
  iVar2 = DAT_0043756c * 0x224 + DAT_00434538;
  uVar3 = (uint)*(byte *)(iVar2 + 2);
  uVar1 = (uint)*(byte *)(iVar2 + 3);
  iVar2 = FUN_0041ac10(DAT_0043644c,DAT_00436450,uVar3,uVar1);
  if (iVar2 == 0) {
    FUN_00421750();
    return 4;
  }
  if (iVar2 != 1) {
    return 3;
  }
  pbVar4 = (byte *)((uVar3 * 0x30 + uVar1) * 0x18 + DAT_0043453c);
  if (pbVar4[0x10] != 5) {
    return 3;
  }
  if (*pbVar4 < 0x40) {
    FUN_0041ac40();
    return 4;
  }
  iVar2 = *(int *)(pbVar4 + 0xc) - (*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 3);
  if (-1 < iVar2) {
    *(int *)(pbVar4 + 0xc) = iVar2;
    FUN_0041ac40();
    return 4;
  }
  pbVar4[0x10] = 0x60;
  FUN_0041acc0(DAT_0043644c,DAT_00436450);
  FUN_0041ad90();
  return 1;
}



/* 0040bc20  FUN_0040bc20  142 bytes, 3 callers */

undefined4 FUN_0040bc20(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00437690 * 0x18 + DAT_0043453c;
  if (3 < (byte)(*(char *)(iVar2 + 0x10) - 1U)) {
    return 3;
  }
  iVar1 = *(int *)(iVar2 + 0xc) - (*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 1);
  if (iVar1 < 1) {
    *(undefined1 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18) = 100;
    FUN_0041acc0(DAT_0043644c,DAT_00436450);
    return 1;
  }
  *(int *)(iVar2 + 0xc) = iVar1;
  return 4;
}



/* 0040bcb0  FUN_0040bcb0  51 bytes, 0 callers */

undefined1 * __fastcall FUN_0040bcb0(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = 0x19;
  *(undefined4 *)(param_1 + 0x134) = 0;
  puVar1 = param_1;
  do {
    puVar1[0xc] = 0;
    iVar2 = iVar2 + -1;
    *(undefined4 *)(puVar1 + 4) = 0xffffffff;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
    puVar1 = puVar1 + 0xc;
  } while (iVar2 != 0);
  return param_1;
}



/* 0040bcf0  FUN_0040bcf0  52 bytes, 1 callers */

void __thiscall FUN_0040bcf0(void *this,undefined2 *param_1)

{
  UINT UVar1;
  
  *(undefined2 *)this = *param_1;
  *(undefined1 *)((int)this + 2) = *(undefined1 *)(param_1 + 1);
  *(undefined1 *)((int)this + 3) = 0;
  UVar1 = GetDriveTypeA(this);
  *(UINT *)((int)this + 0x130) = UVar1;
  if (UVar1 == 5) {
    FUN_0040bd30((int)this);
  }
  return;
}



/* 0040bd30  FUN_0040bd30  103 bytes, 1 callers */

undefined4 __fastcall FUN_0040bd30(int param_1)

{
  UINT UVar1;
  int *piVar2;
  int iVar3;
  char local_4 [4];
  
  local_4[1] = 0x3a;
  local_4[2] = 0x5c;
  local_4[3] = 0;
  piVar2 = (int *)(param_1 + 4);
  iVar3 = 0;
  do {
    local_4[0] = (char)iVar3 + 'A';
    UVar1 = GetDriveTypeA(local_4);
    if (UVar1 == 2) {
      *piVar2 = iVar3;
      *(char *)(piVar2 + 1) = (char)iVar3 + 'A';
      *(undefined1 *)((int)piVar2 + 5) = 0x3a;
      *(undefined1 *)((int)piVar2 + 6) = 0x5c;
      *(undefined1 *)((int)piVar2 + 7) = 0;
      *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + 1;
    }
    piVar2 = piVar2 + 3;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x19);
  return *(undefined4 *)(param_1 + 0x134);
}



/* 0040bda0  FUN_0040bda0  601 bytes, 11 callers */

undefined4 __thiscall FUN_0040bda0(void *this,LPSTR param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 uVar2;
  HANDLE pvVar3;
  int iVar4;
  byte *pbVar5;
  int *piVar6;
  byte bVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  char *lpString2;
  _WIN32_FIND_DATAA local_584;
  undefined1 local_444 [544];
  CHAR local_224 [260];
  CHAR local_120 [260];
  int local_1c;
  byte *local_18;
  void *local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040bff9;
  *unaff_FS_OFFSET = &local_10;
  if (*(int *)((int)this + 0x130) != 0) {
    local_14 = this;
    if (*(int *)((int)this + 0x130) != 5) {
      wsprintfA(param_1,s__sSAVE__s_004324f8,&DAT_00437588,param_2);
      uVar2 = 1;
      goto LAB_0040bdd0;
    }
    if (*(int *)((int)this + 0x134) != 0) {
      FUN_0041f8b0((int)local_444);
      local_8 = 0;
      local_18 = (byte *)((int)local_14 + 0xc);
      do {
        iVar8 = 0x19;
        pbVar5 = local_18;
        do {
          *pbVar5 = 0;
          if (*(int *)(pbVar5 + -8) != -1) {
            wsprintfA(local_120,s__s____004324f0,pbVar5 + -4);
            pvVar3 = FindFirstFileA(local_120,&local_584);
            if (pvVar3 == (HANDLE)0xffffffff) {
              DAT_00434530 = GetLastError();
              if (DAT_00434530 == 0x15) {
                *pbVar5 = 0;
              }
              else {
                iVar4 = FUN_0040c3b0();
                if (iVar4 != 0) goto LAB_0040bec4;
                wsprintfA(local_224,s__s_Disk_unusable__004324dc,pbVar5 + -4);
                FUN_00409370(local_224,0);
              }
            }
            else {
LAB_0040bec4:
              *pbVar5 = 1;
            }
          }
          pbVar5 = pbVar5 + 0xc;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        bVar7 = 0;
        iVar8 = 0x19;
        pbVar5 = local_18;
        do {
          bVar1 = *pbVar5;
          pbVar5 = pbVar5 + 0xc;
          bVar7 = bVar7 | bVar1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        if (bVar7 != 0) {
          iVar8 = 0;
          piVar6 = (int *)((int)local_14 + 4);
          goto LAB_0040bf9c;
        }
        iVar8 = 0;
        wsprintfA(local_120,&DAT_004324d8);
        local_1c = 0x19;
        piVar6 = (int *)((int)local_14 + 4);
        do {
          if (*piVar6 != -1) {
            iVar8 = iVar8 + 1;
            lstrcatA(local_120,s_Drive_004324d0);
            lstrcatA(local_120,(LPCSTR)(piVar6 + 1));
            lstrcatA(local_120,&DAT_004324cc);
          }
          piVar6 = piVar6 + 3;
          local_1c = local_1c + -1;
        } while (local_1c != 0);
        if (iVar8 < 2) {
          lpString2 = s_Please_insert_save_disk__0043247c;
        }
        else {
          lpString2 = s_Please_insert_disk_into_one_of_t_00432498;
        }
        lstrcatA(local_120,lpString2);
        iVar8 = FUN_00409370(local_120,5);
      } while (iVar8 == 4);
      local_8 = 0xffffffff;
      FUN_0040c003();
    }
  }
  goto LAB_0040bdce;
  while( true ) {
    piVar6 = piVar6 + 3;
    iVar8 = iVar8 + 1;
    if (0x18 < iVar8) break;
LAB_0040bf9c:
    if ((*piVar6 != -1) && ((char)piVar6[2] == '\x01')) {
      wsprintfA(param_1,s__sSAVE__s_004324f8,(int)local_14 + iVar8 * 0xc + 8,param_2);
      local_8 = 0xffffffff;
      FUN_0040c003();
      uVar2 = 1;
      goto LAB_0040bdd0;
    }
  }
  local_8 = 0xffffffff;
  FUN_0040c003();
LAB_0040bdce:
  uVar2 = 0;
LAB_0040bdd0:
  *unaff_FS_OFFSET = local_10;
  return uVar2;
}



/* 0040c003  FUN_0040c003  11 bytes, 1 callers */

void FUN_0040c003(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x440));
  return;
}



/* 0040c010  FUN_0040c010  167 bytes, 3 callers */

undefined4 FUN_0040c010(LPCSTR param_1,LPVOID param_2,DWORD param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined3 extraout_var_00;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined2 local_230 [272];
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040c0b7;
  *unaff_FS_OFFSET = &local_10;
  FUN_0041f8b0((int)local_230);
  local_8 = 0;
  do {
    bVar1 = FUN_0041f9f0(local_230,param_1);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      iVar2 = FUN_0041fa80(local_230,param_2,param_3,0);
      if (iVar2 != 0) {
        local_8 = 0xffffffff;
        FUN_0040c0c1();
        uVar3 = 1;
        goto LAB_0040c091;
      }
      FUN_0041fa40(local_230);
    }
    bVar1 = FUN_0040c2e0();
  } while (CONCAT31(extraout_var_00,bVar1) != 0);
  local_8 = 0xffffffff;
  FUN_0040c0c1();
  uVar3 = 0;
LAB_0040c091:
  *unaff_FS_OFFSET = local_10;
  return uVar3;
}



/* 0040c0c1  FUN_0040c0c1  11 bytes, 1 callers */

void FUN_0040c0c1(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x22c));
  return;
}



/* 0040c0d0  FUN_0040c0d0  213 bytes, 2 callers */

undefined4 FUN_0040c0d0(LPCSTR param_1,LPCVOID param_2,DWORD param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  BOOL BVar3;
  undefined3 extraout_var_01;
  undefined4 uVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined2 local_234 [272];
  void *local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040c1a5;
  *unaff_FS_OFFSET = &local_10;
  FUN_0041f8b0((int)local_234);
  local_8 = 0;
  do {
    iVar2 = FUN_0040c1c0(local_14);
    if (iVar2 != 0) break;
    bVar1 = FUN_0040c2e0();
  } while (CONCAT31(extraout_var,bVar1) != 0);
  do {
    bVar1 = FUN_0041f9a0(local_234,param_1);
    if (CONCAT31(extraout_var_00,bVar1) != 0) {
      BVar3 = FUN_0041fc10(local_234,param_2,param_3);
      if (BVar3 != 0) {
        local_8 = 0xffffffff;
        FUN_0040c1af();
        uVar4 = 1;
        goto LAB_0040c17f;
      }
      FUN_0041fa40(local_234);
    }
    if (DAT_00434530 == 0x70) {
      FUN_0040c3d0(param_1);
    }
    bVar1 = FUN_0040c2e0();
  } while (CONCAT31(extraout_var_01,bVar1) != 0);
  local_8 = 0xffffffff;
  FUN_0040c1af();
  uVar4 = 0;
LAB_0040c17f:
  *unaff_FS_OFFSET = local_10;
  return uVar4;
}



/* 0040c1af  FUN_0040c1af  11 bytes, 1 callers */

void FUN_0040c1af(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x230));
  return;
}



/* 0040c1c0  FUN_0040c1c0  282 bytes, 2 callers */

undefined4 __fastcall FUN_0040c1c0(void *param_1)

{
  bool bVar1;
  int iVar2;
  HANDLE hFindFile;
  BOOL BVar3;
  undefined3 extraout_var;
  _SECURITY_ATTRIBUTES local_354;
  undefined2 local_348;
  undefined1 local_346;
  undefined1 local_345;
  undefined2 local_244;
  undefined1 local_242;
  _WIN32_FIND_DATAA local_140;
  
  iVar2 = FUN_0040bda0(param_1,(LPSTR)&local_244,&DAT_0043250c);
  if (iVar2 == 0) {
    return 0;
  }
  if (*(int *)((int)param_1 + 0x130) == 5) {
    local_348 = local_244;
    local_346 = local_242;
    local_345 = 0;
  }
  else {
    lstrcpyA((LPSTR)&local_348,&DAT_00437588);
  }
  lstrcatA((LPSTR)&local_348,&DAT_00432504);
  hFindFile = FindFirstFileA((LPCSTR)&local_348,&local_140);
  if (hFindFile == (HANDLE)0xffffffff) {
    local_354.nLength = 0;
    do {
      BVar3 = CreateDirectoryA((LPCSTR)&local_348,&local_354);
      if (BVar3 != 0) {
        return 1;
      }
      DAT_00434530 = GetLastError();
      bVar1 = FUN_0040c2e0();
    } while (CONCAT31(extraout_var,bVar1) != 0);
    return 0;
  }
  FindClose(hFindFile);
  if (local_140.dwFileAttributes != 0x10) {
    DeleteFileA((LPCSTR)&local_244);
    DAT_00434530 = GetLastError();
    return 0;
  }
  return 1;
}



/* 0040c2e0  FUN_0040c2e0  57 bytes, 6 callers */

bool FUN_0040c2e0(void)

{
  int iVar1;
  
  switch(DAT_00434530) {
  case 5:
  case 0xb:
  case 0xe:
  case 0x13:
  case 0x15:
  case 0x70:
    iVar1 = FUN_00409370(&DAT_00435ed0,5);
    return iVar1 == 4;
  default:
    return false;
  }
}



/* 0040c3b0  FUN_0040c3b0  23 bytes, 1 callers */

undefined4 FUN_0040c3b0(void)

{
  if ((-1 < DAT_00434530) && (DAT_00434530 < 4)) {
    return 1;
  }
  return 0;
}



/* 0040c3d0  FUN_0040c3d0  85 bytes, 4 callers */

undefined4 FUN_0040c3d0(LPCSTR param_1)

{
  bool bVar1;
  BOOL BVar2;
  undefined3 extraout_var;
  
  do {
    BVar2 = DeleteFileA(param_1);
    if (BVar2 != 0) {
      return 1;
    }
    wsprintfA(&DAT_00435ed0,&DAT_00432510);
    DAT_00434530 = GetLastError();
    bVar1 = FUN_0040c2e0();
  } while (CONCAT31(extraout_var,bVar1) != 0);
  return 0;
}



/* 0040c430  FUN_0040c430  173 bytes, 0 callers */

undefined4 * __fastcall FUN_0040c430(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040c4dd;
  *unaff_FS_OFFSET = &local_10;
  FUN_004250d0(param_1);
  local_8 = 0;
  *param_1 = &PTR_FUN_00430168;
  wsprintfA((LPSTR)(param_1 + 0xa0),s_DS795_WND_0043255c);
  wsprintfA((LPSTR)(param_1 + 0x53),s_Title_00432554);
  wsprintfA((LPSTR)(param_1 + 0x12),s_Falcom_Co__00432548);
  param_1[0x9f] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0x9e] = 0x14000000;
  param_1[8] = 0x100;
  param_1[9] = 0xc0;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}



/* 0040c4f0  FUN_0040c4f0  30 bytes, 0 callers */

undefined4 * __thiscall FUN_0040c4f0(void *this,byte param_1)

{
  FUN_0040c510(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 0040c510  FUN_0040c510  61 bytes, 1 callers */

void __fastcall FUN_0040c510(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_0040c54d;
  *param_1 = &PTR_FUN_00430168;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_0040c557();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 0040c557  FUN_0040c557  8 bytes, 1 callers */

void FUN_0040c557(void)

{
  int unaff_EBP;
  
  FUN_00425180(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 0040c77a  FUN_0040c77a  11 bytes, 0 callers */

void FUN_0040c77a(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x234));
  return;
}



/* 0040c860  FUN_0040c860  136 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_0040c860(int param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040c8e8;
  *unaff_FS_OFFSET = &local_10;
  FUN_00425bd0((undefined4 *)(param_1 + 4));
  DAT_004358d8 = 0;
  DAT_004358dc = 0;
  DAT_004358e0 = 0;
  DAT_004358c8 = 0;
  DAT_004358cc = 0;
  DAT_004358d0 = 0;
  _DAT_004358a8 = 0xffffffff;
  _DAT_004358ac = 0xffffffff;
  _DAT_004358b0 = 0xffffffff;
  _DAT_004358b4 = 0xffffffff;
  _DAT_004358b8 = 0xffffffff;
  _DAT_004358bc = 0xffffffff;
  _DAT_004358c0 = 0xffffffff;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}



/* 0040c9c9  FUN_0040c9c9  11 bytes, 0 callers */

void FUN_0040c9c9(void)

{
  int unaff_EBP;
  
  FUN_00425be0((int *)(*(int *)(unaff_EBP + -0x10) + 4));
  return;
}



/* 0040c9e0  FUN_0040c9e0  468 bytes, 1 callers */

int __thiscall FUN_0040c9e0(void *this,HWND param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040cbf8;
  *unaff_FS_OFFSET = &local_10;
  if (param_1 == (HWND)0x0) {
    iVar1 = 0;
  }
  else {
    DAT_00432588 = GetWindowLongA(param_1,-4);
    DAT_00432588 = SetWindowLongA(param_1,-4,0x40e210);
    *(undefined4 *)((int)this + 0x14) = 0;
    puVar2 = (undefined4 *)FUN_00427f90(0x14);
    local_8 = 0;
    puVar3 = (undefined4 *)0x0;
    if (puVar2 != (undefined4 *)0x0) {
      FUN_0040d940(puVar2);
      *puVar2 = &PTR_LAB_004301d8;
      puVar3 = puVar2;
    }
    local_8 = 0xffffffff;
    DAT_004358d8 = puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      puVar3 = (undefined4 *)FUN_00427f90(0x18);
      local_8 = 1;
      puVar2 = (undefined4 *)0x0;
      if (puVar3 != (undefined4 *)0x0) {
        puVar2 = FUN_0040da60(puVar3);
      }
      local_8 = 0xffffffff;
      DAT_004358dc = puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        piVar4 = (int *)FUN_00427f90(0x45c);
        local_8 = 2;
        piVar5 = (int *)0x0;
        if (piVar4 != (int *)0x0) {
          piVar5 = FUN_0040dd20(piVar4);
        }
        local_8 = 0xffffffff;
        DAT_004358d0 = piVar5;
        if (piVar5 != (int *)0x0) {
          puVar3 = (undefined4 *)FUN_00427f90(0x50);
          local_8 = 3;
          if (puVar3 == (undefined4 *)0x0) {
            puVar3 = (undefined4 *)0x0;
          }
          else {
            FUN_0040db50(puVar3);
            *puVar3 = &PTR_LAB_004301e0;
          }
          local_8 = 0xffffffff;
          DAT_004358c8 = puVar3;
          if (puVar3 != (undefined4 *)0x0) {
            puVar3 = (undefined4 *)FUN_00427f90(0x50);
            local_8 = 5;
            if (puVar3 == (undefined4 *)0x0) {
              puVar3 = (undefined4 *)0x0;
            }
            else {
              FUN_0040db50(puVar3);
              *puVar3 = &PTR_LAB_004301f8;
            }
            DAT_004358cc = puVar3;
            if (puVar3 != (undefined4 *)0x0) {
              *(undefined4 *)((int)this + 0x14) = 1;
            }
          }
        }
      }
    }
    local_8 = 0xffffffff;
    FUN_0040d050(this,3);
    if (DAT_00436598 == 5) {
      DAT_004376b4 = 1;
      FUN_0040d410(this);
    }
    iVar1 = *(int *)((int)this + 0x14);
  }
  *unaff_FS_OFFSET = local_10;
  return iVar1;
}



/* 0040cc69  FUN_0040cc69  8 bytes, 0 callers */

void FUN_0040cc69(void)

{
  int unaff_EBP;
  
  FUN_0040dba0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 0040ccd9  FUN_0040ccd9  8 bytes, 0 callers */

void FUN_0040ccd9(void)

{
  int unaff_EBP;
  
  FUN_0040dba0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 0040ccf0  FUN_0040ccf0  39 bytes, 4 callers */

void FUN_0040ccf0(int param_1)

{
  int iVar1;
  
  if ((&DAT_004358d8)[param_1] != 0) {
    iVar1 = FUN_0040cdc0(param_1);
    if (iVar1 != -1) {
      (**(code **)(*(int *)(&DAT_004358d8)[param_1] + 4))();
    }
  }
  return;
}



/* 0040cd20  FUN_0040cd20  64 bytes, 15 callers */

undefined4 __thiscall FUN_0040cd20(void *this,int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0040cd60(this,param_1);
  if (iVar1 == -1) {
    return 0;
  }
  uVar2 = (*(code *)**(undefined4 **)(&DAT_004358d8)[*(int *)(iVar1 * 0x220 + 0x108 + *(int *)this)]
          )(iVar1,param_2);
  return uVar2;
}



/* 0040cd60  FUN_0040cd60  40 bytes, 8 callers */

int __thiscall FUN_0040cd60(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)((int)this + 0x18)) {
    piVar2 = *(int **)this;
    do {
      if (*piVar2 == param_1) {
        return iVar1;
      }
      piVar2 = piVar2 + 0x88;
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)((int)this + 0x18));
  }
  return -1;
}



/* 0040cd90  FUN_0040cd90  33 bytes, 1 callers */

int __fastcall FUN_0040cd90(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < (int)param_1[6]) {
    piVar2 = (int *)*param_1;
    do {
      if (*piVar2 == -1) {
        return iVar1;
      }
      piVar2 = piVar2 + 0x88;
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)param_1[6]);
  }
  return -1;
}



/* 0040cdc0  FUN_0040cdc0  48 bytes, 5 callers */

undefined4 FUN_0040cdc0(int param_1)

{
  if (*(int *)((&DAT_004358d8)[param_1] + 4) != -1) {
    return *(undefined4 *)(*(int *)((&DAT_004358d8)[param_1] + 4) * 0x220 + DAT_00435db0);
  }
  return 0xffffffff;
}



/* 0040cdf0  FUN_0040cdf0  19 bytes, 0 callers */

void FUN_0040cdf0(undefined4 param_1)

{
  (**(code **)(*DAT_004358d0 + 0x10))(param_1);
  return;
}



/* 0040ce10  FUN_0040ce10  76 bytes, 1 callers */

undefined4 __thiscall FUN_0040ce10(void *this,int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040cd60(this,param_1);
  if (iVar1 == -1) {
    iVar1 = FUN_0040cd90(this);
    if (iVar1 == -1) {
      return 0;
    }
  }
  *(int *)(*(int *)this + iVar1 * 0x220) = param_1;
  *(undefined4 *)(*(int *)this + 0x108 + iVar1 * 0x220) = param_2;
  return 1;
}



/* 0040ce60  FUN_0040ce60  216 bytes, 4 callers */

void __thiscall FUN_0040ce60(void *this,int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char local_40c [1036];
  
  iVar1 = FUN_0040cd60(this,param_1);
  if (iVar1 != -1) {
    if (param_2 == 2) {
      DAT_004376b4 = 0;
      (**(code **)(*DAT_004358d0 + 0x10))(local_40c);
      if ((local_40c[0] == '\0') || (DAT_00436598 == 5)) {
        DAT_004376b4 = 1;
        param_2 = 0;
      }
    }
    iVar1 = iVar1 * 0x220;
    if ((((*(int *)(*(int *)this + iVar1) != -1) &&
         (iVar2 = FUN_0040cdc0(((int *)(*(int *)this + iVar1))[0x42]), iVar2 != -1)) &&
        (iVar2 == param_1)) && (*(int *)(*(int *)this + iVar1 + 0x10c) != param_2)) {
      FUN_0040ccf0(*(int *)(*(int *)this + iVar1 + 0x108));
      *(int *)(*(int *)this + 0x10c + iVar1) = param_2;
      FUN_0040cd20(this,param_1,1);
      return;
    }
    *(int *)(*(int *)this + 0x10c + iVar1) = param_2;
  }
  return;
}



/* 0040cf40  FUN_0040cf40  55 bytes, 1 callers */

void __thiscall FUN_0040cf40(void *this,int param_1,LPCSTR param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040cd60(this,param_1);
  if (iVar1 != -1) {
    wsprintfA((LPSTR)(iVar1 * 0x220 + *(int *)this + 0x114),param_2);
  }
  return;
}



/* 0040cf80  FUN_0040cf80  52 bytes, 1 callers */

void __thiscall FUN_0040cf80(void *this,int param_1,LPCSTR param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040cd60(this,param_1);
  if (iVar1 != -1) {
    wsprintfA((LPSTR)(iVar1 * 0x220 + *(int *)this + 4),param_2);
  }
  return;
}



/* 0040cfc0  FUN_0040cfc0  45 bytes, 1 callers */

void __thiscall FUN_0040cfc0(void *this,int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040cd60(this,param_1);
  if (iVar1 != -1) {
    *(undefined4 *)(iVar1 * 0x220 + 0x110 + *(int *)this) = param_2;
  }
  return;
}



/* 0040cff0  FUN_0040cff0  45 bytes, 1 callers */

void __thiscall FUN_0040cff0(void *this,int param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040cd60(this,param_1);
  if (iVar1 != -1) {
    *(undefined1 *)(iVar1 * 0x220 + 0x214 + *(int *)this) = param_2;
  }
  return;
}



/* 0040d020  FUN_0040d020  45 bytes, 1 callers */

void __thiscall FUN_0040d020(void *this,int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040cd60(this,param_1);
  if (iVar1 != -1) {
    *(undefined4 *)(iVar1 * 0x220 + 0x108 + *(int *)this) = param_2;
  }
  return;
}



/* 0040d050  FUN_0040d050  140 bytes, 2 callers */

undefined4 __thiscall FUN_0040d050(void *this,undefined4 param_1)

{
  int iVar1;
  CHAR local_208 [260];
  CHAR local_104 [260];
  
  wsprintfA(local_104,s_USnd_02d_cfg_004325a8,param_1);
  FUN_00409490(local_208,s_SAVE__004325a0,local_104);
  iVar1 = FUN_0040d0e0(this,local_208);
  if (iVar1 == 0) {
    FUN_00409490(local_208,s_Sound__0043258c,s_Sound_cfg_00432594);
    FUN_0040d0e0(this,local_208);
    return 0;
  }
  return 1;
}



/* 0040d0e0  FUN_0040d0e0  786 bytes, 1 callers */

undefined4 __thiscall FUN_0040d0e0(void *this,LPCSTR param_1)

{
  int *this_00;
  int iVar1;
  undefined4 uVar2;
  UINT UVar3;
  int iVar4;
  UINT UVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_544 [544];
  CHAR local_324 [260];
  CHAR local_220 [260];
  char local_11c;
  undefined1 local_11b [259];
  UINT local_18;
  int local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040d3f2;
  *unaff_FS_OFFSET = &local_10;
  FUN_0041f8b0((int)local_544);
  local_8 = 0;
  iVar1 = FUN_0041fc60(local_544,param_1);
  if (iVar1 != 0) {
    GetPrivateProfileStringA
              (s_entry_00432618,&DAT_00432620,s_no_name_00432628,(LPSTR)((int)this + 0x1c),0x104,
               param_1);
    UVar3 = GetPrivateProfileIntA(s_entry_00432618,&DAT_00432614,0,param_1);
    if (UVar3 != 0) {
      this_00 = (int *)((int)this + 4);
      *(UINT *)((int)this + 0x18) = UVar3;
      FUN_00425c80(this_00);
      FUN_00425c20(this_00);
      iVar1 = FUN_00425c00(this_00,*(int *)((int)this + 0x18) * 0x220);
      *(int *)this = iVar1;
      if (iVar1 != 0) {
        local_14 = 0;
        if (0 < *(int *)((int)this + 0x18)) {
          iVar1 = 0;
          do {
            *(undefined4 *)(*(int *)this + iVar1) = 0xffffffff;
            iVar4 = *(int *)this + iVar1;
            iVar1 = iVar1 + 0x220;
            wsprintfA((LPSTR)(iVar4 + 4),&DAT_0043260c);
            local_14 = local_14 + 1;
            *(undefined4 *)(*(int *)this + -0x118 + iVar1) = 0;
            *(undefined4 *)(*(int *)this + -0x114 + iVar1) = 0;
            *(undefined4 *)(*(int *)this + -0x110 + iVar1) = 0;
            *(undefined1 *)(*(int *)this + -0xc + iVar1) = 0;
            *(undefined4 *)(*(int *)this + -8 + iVar1) = 0;
            *(undefined4 *)(*(int *)this + -4 + iVar1) = 0;
          } while (local_14 < *(int *)((int)this + 0x18));
        }
        local_14 = 0;
        if (0 < *(int *)((int)this + 0x18)) {
          do {
            wsprintfA(local_220,&DAT_00432608,local_14);
            UVar3 = GetPrivateProfileIntA(local_220,s_ENTRY_00432600,-1,param_1);
            if (UVar3 != 0xffffffff) {
              FUN_0040ce10(this,UVar3,0);
              GetPrivateProfileStringA
                        (local_220,&DAT_00432620,s_no_name_00432628,&local_11c,0x104,param_1);
              FUN_0040cf80(this,UVar3,&local_11c);
              UVar5 = GetPrivateProfileIntA(local_220,&DAT_004325fc,0,param_1);
              FUN_0040cfc0(this,UVar3,UVar5);
              UVar5 = GetPrivateProfileIntA(local_220,s_DEVICE_004325f4,0,param_1);
              if (UVar5 < 3) {
                FUN_0040ce60(this,UVar3,UVar5);
              }
              local_18 = GetPrivateProfileIntA(local_220,&DAT_004325ec,0,param_1);
              FUN_0040d020(this,UVar3,local_18);
              if (local_18 == 0) {
                GetPrivateProfileStringA
                          (local_220,&DAT_004325d8,s__Lm000_mid_004325e0,&local_11c,0x104,param_1);
              }
              else {
                GetPrivateProfileStringA
                          (local_220,&DAT_004325c0,s__Lm90000_wav_004325c8,&local_11c,0x104,param_1)
                ;
              }
              if (local_11c == '*') {
                FUN_00409490(local_324,s_Sound__0043258c,local_11b);
                lstrcpyA(&local_11c,local_324);
              }
              FUN_0040cf40(this,UVar3,&local_11c);
              UVar5 = GetPrivateProfileIntA(local_220,&DAT_004325b8,0,param_1);
              FUN_0040cff0(this,UVar3,(char)UVar5);
            }
            local_14 = local_14 + 1;
          } while (local_14 < *(int *)((int)this + 0x18));
        }
        local_8 = 0xffffffff;
        FUN_0040d3fc();
        uVar2 = 1;
        goto LAB_0040d136;
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_0040d3fc();
  uVar2 = 0;
LAB_0040d136:
  *unaff_FS_OFFSET = local_10;
  return uVar2;
}



/* 0040d3fc  FUN_0040d3fc  11 bytes, 1 callers */

void FUN_0040d3fc(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x540));
  return;
}



/* 0040d410  FUN_0040d410  62 bytes, 1 callers */

void __fastcall FUN_0040d410(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_1[6]) {
    iVar2 = 0;
    do {
      iVar1 = *(int *)(*param_1 + iVar2);
      if ((iVar1 != -1) && (((int *)(*param_1 + iVar2))[0x42] == 0)) {
        FUN_0040ce60(param_1,iVar1,0);
      }
      iVar2 = iVar2 + 0x220;
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[6]);
  }
  return;
}



/* 0040d450  FUN_0040d450  63 bytes, 0 callers */

void __fastcall FUN_0040d450(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_1[6]) {
    iVar2 = 0;
    do {
      iVar1 = *(int *)(*param_1 + iVar2);
      if ((iVar1 != -1) && (((int *)(*param_1 + iVar2))[0x42] == 0)) {
        FUN_0040ce60(param_1,iVar1,2);
      }
      iVar2 = iVar2 + 0x220;
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[6]);
  }
  return;
}



/* 0040d490  FUN_0040d490  1146 bytes, 2 callers */

int __thiscall FUN_0040d490(void *this,undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  DWORD DVar3;
  BOOL BVar4;
  undefined3 extraout_var_00;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar5;
  CHAR local_440 [260];
  undefined2 local_33c [272];
  CHAR local_11c [260];
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040d90a;
  *unaff_FS_OFFSET = &local_10;
  FUN_0041f8b0((int)local_33c);
  local_8 = 0;
  local_14 = 1;
  iVar2 = FUN_0040c1c0(&DAT_00436468);
  if (iVar2 != 0) {
    wsprintfA(local_440,s_USnd_02d_cfg_004325a8,param_1);
    iVar2 = FUN_0040bda0(&DAT_00436468,local_11c,local_440);
    if (iVar2 != 0) {
      do {
        local_14 = 1;
        bVar1 = FUN_0041f9a0(local_33c,local_11c);
        if (CONCAT31(extraout_var,bVar1) == 0) {
          local_14 = 0;
        }
        else {
          wsprintfA(local_11c,s__entry__004326bc);
          DVar3 = lstrlenA(local_11c);
          BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
          if (BVar4 == 0) {
            local_14 = 0;
          }
          wsprintfA(local_11c,s_NAME__s_004326b0,param_2);
          DVar3 = lstrlenA(local_11c);
          BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
          if (BVar4 == 0) {
            local_14 = 0;
          }
          wsprintfA(local_11c,s_MAX__d_004326a8,*(undefined4 *)((int)this + 0x18));
          DVar3 = lstrlenA(local_11c);
          BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
          if (BVar4 == 0) {
            local_14 = 0;
          }
          local_18 = 0;
          if (0 < *(int *)((int)this + 0x18)) {
            iVar2 = 0;
            do {
              if (*(int *)(*(int *)this + iVar2) != -1) {
                wsprintfA(local_11c,s___d__004326a0,local_18);
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
                wsprintfA(local_11c,s_ENTRY__d_00432694,*(undefined4 *)(*(int *)this + iVar2));
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
                wsprintfA(local_11c,s_MODE__d_00432688,*(undefined4 *)(*(int *)this + 0x108 + iVar2)
                         );
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
                wsprintfA(local_11c,s_DEVICE__d_0043267c,
                          *(undefined4 *)(*(int *)this + 0x10c + iVar2));
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
                wsprintfA(local_11c,s_NAME__s_004326b0,*(int *)this + iVar2 + 4);
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
                if (*(int *)(*(int *)this + iVar2 + 0x108) == 0) {
                  pcVar5 = s_MIDI__s_00432670;
                }
                else {
                  pcVar5 = s_WAVE__s_00432664;
                }
                wsprintfA(local_11c,pcVar5,*(int *)this + iVar2 + 0x114);
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
                wsprintfA(local_11c,s_CD__d_0043265c,*(undefined4 *)(*(int *)this + 0x110 + iVar2));
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
                wsprintfA(local_11c,s_LOOP__d_00432650,(uint)*(byte *)(*(int *)this + 0x214 + iVar2)
                         );
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
                wsprintfA(local_11c,&DAT_004324cc);
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
              }
              iVar2 = iVar2 + 0x220;
              local_18 = local_18 + 1;
            } while (local_18 < *(int *)((int)this + 0x18));
          }
          FUN_0041fa40(local_33c);
        }
        if (local_14 != 0) goto LAB_0040d8f9;
        bVar1 = FUN_0040c2e0();
      } while (CONCAT31(extraout_var_00,bVar1) != 0);
      FUN_00409370(s_Failed_in_saving_environment__00432630,0);
      local_8 = 0xffffffff;
      FUN_0040d914();
      local_14 = 0;
      goto LAB_0040d8e6;
    }
  }
LAB_0040d8f9:
  local_8 = 0xffffffff;
  FUN_0040d914();
LAB_0040d8e6:
  *unaff_FS_OFFSET = local_10;
  return local_14;
}



/* 0040d914  FUN_0040d914  11 bytes, 1 callers */

void FUN_0040d914(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x338));
  return;
}



/* 0040d940  FUN_0040d940  20 bytes, 2 callers */

undefined4 * __fastcall FUN_0040d940(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_00430210;
  param_1[4] = 0xffffffff;
  param_1[1] = 0xffffffff;
  return param_1;
}



/* 0040da60  FUN_0040da60  25 bytes, 1 callers */

undefined4 * __fastcall FUN_0040da60(undefined4 *param_1)

{
  FUN_0040d940(param_1);
  *param_1 = &PTR_LAB_00430218;
  param_1[5] = 0;
  return param_1;
}



/* 0040db50  FUN_0040db50  43 bytes, 2 callers */

undefined4 * __fastcall FUN_0040db50(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00430220;
  param_1[7] = DAT_004344d4;
  param_1[10] = DAT_004344d4;
  param_1[0x10] = DAT_004344d4;
  *(undefined2 *)((int)param_1 + 6) = 0;
  *(undefined2 *)(param_1 + 1) = 0;
  return param_1;
}



/* 0040db80  FUN_0040db80  30 bytes, 0 callers */

undefined4 * __thiscall FUN_0040db80(void *this,byte param_1)

{
  FUN_0040dba0(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 0040dba0  FUN_0040dba0  7 bytes, 4 callers */

void __fastcall FUN_0040dba0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00430220;
  return;
}



/* 0040dbf0  FUN_0040dbf0  96 bytes, 0 callers */

undefined4 __fastcall FUN_0040dbf0(int *param_1)

{
  MCIERROR MVar1;
  
  if (*(short *)((int)param_1 + 6) != 0) {
    (**(code **)(*param_1 + 0xc))();
  }
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[4] = (int)s_sequencer_004326c8;
  param_1[2] = 0;
  MVar1 = mciSendCommandA(0,0x803,0x2202,(DWORD_PTR)(param_1 + 2));
  param_1[0x13] = MVar1;
  if (MVar1 != 0) {
    (**(code **)(*param_1 + 0xc))();
    return 0;
  }
  *(short *)((int)param_1 + 6) = (short)param_1[3];
  return 1;
}



/* 0040dc50  FUN_0040dc50  122 bytes, 0 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __thiscall FUN_0040dc50(void *this,int param_1)

{
  int iVar1;
  MCIERROR MVar2;
  
  *(int *)((int)this + 0x14) = param_1 * 0x220 + DAT_00435db0 + 0x114;
  iVar1 = (**(code **)(*(int *)this + 4))();
  if (iVar1 == 0) {
    return false;
  }
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  _DAT_004358c4 = 0;
  MVar2 = mciSendCommandA((uint)*(ushort *)((int)this + 6),0x806,1,(int)this + 0x1c);
  *(MCIERROR *)((int)this + 0x4c) = MVar2;
  if (*(ushort *)((int)this + 6) < 7) {
    *(int *)(&DAT_004358a8 + (uint)*(ushort *)((int)this + 6) * 4) = param_1;
  }
  return *(int *)((int)this + 0x4c) == 0;
}



/* 0040dd20  FUN_0040dd20  126 bytes, 1 callers */

int * __fastcall FUN_0040dd20(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040dd9e;
  *unaff_FS_OFFSET = &local_10;
  piVar1 = param_1 + 0x14;
  FUN_0040db50(param_1);
  local_8 = 0;
  *param_1 = (int)&PTR_FUN_00430238;
  piVar3 = piVar1;
  for (iVar2 = 0x103; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  iVar2 = FUN_0040de60(param_1);
  if (iVar2 == 0) {
    *(undefined1 *)piVar1 = 0;
    DAT_004376b4 = 1;
  }
  else {
    *(undefined1 *)piVar1 = 1;
    FUN_0040df80((int)param_1);
  }
  *unaff_FS_OFFSET = local_10;
  return param_1;
}



/* 0040ddb0  FUN_0040ddb0  30 bytes, 0 callers */

undefined4 * __thiscall FUN_0040ddb0(void *this,byte param_1)

{
  FUN_0040ddd0(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 0040ddd0  FUN_0040ddd0  114 bytes, 1 callers */

void __fastcall FUN_0040ddd0(undefined4 *param_1)

{
  MCIERROR MVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_0040de42;
  *param_1 = &PTR_FUN_00430238;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0;
  if (*(ushort *)((int)param_1 + 6) != 0) {
    MVar1 = mciSendCommandA((uint)*(ushort *)((int)param_1 + 6),0x804,2,0);
    *(undefined2 *)((int)param_1 + 6) = 0;
    *(undefined1 *)(param_1 + 0x14) = 0;
    param_1[0x13] = MVar1;
  }
  local_8 = 0xffffffff;
  FUN_0040de4c();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 0040de4c  FUN_0040de4c  8 bytes, 1 callers */

void FUN_0040de4c(void)

{
  int unaff_EBP;
  
  FUN_0040dba0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 0040de60  FUN_0040de60  75 bytes, 1 callers */

undefined4 __fastcall FUN_0040de60(int *param_1)

{
  MCIERROR MVar1;
  undefined4 uVar2;
  
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[2] = 0;
  param_1[4] = (int)s_cdaudio_004326d4;
  MVar1 = mciSendCommandA(0,0x803,0x2002,(DWORD_PTR)(param_1 + 2));
  param_1[0x13] = MVar1;
  if (MVar1 != 0) {
    *(undefined2 *)((int)param_1 + 6) = 0;
    return 0;
  }
  *(short *)((int)param_1 + 6) = (short)param_1[3];
  uVar2 = FUN_0040dfb0(param_1);
  return uVar2;
}



/* 0040deb0  FUN_0040deb0  195 bytes, 0 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0040deb0(void *this,int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(DAT_00435db0 + 0x110 + param_1 * 0x220) == 0) {
    return 0;
  }
  if (*(short *)((int)this + 6) == 0) {
    iVar2 = (**(code **)(*(int *)this + 4))();
    if (iVar2 == 0) {
      return 0;
    }
  }
  uVar1 = *(uint *)(DAT_00435db0 + 0x110 + param_1 * 0x220);
  uVar3 = uVar1 & 0xff;
  *(uint *)((int)this + 0x20) = uVar3;
  *(uint *)((int)this + 0x2c) = uVar3;
  uVar1 = *(uint *)((int)this + uVar1 * 4 + 0x5c);
  *(uint *)((int)this + 0x24) =
       ((uVar1 >> 0x10 & 0xff) << 0x10 | uVar1 & 0xff) << 8 | ((uVar1 & 0xffff) >> 8) << 0x10 |
       uVar3;
  _DAT_004358c4 = 0;
  mciSendCommandA((uint)*(ushort *)((int)this + 6),0x806,0xd,(int)this + 0x1c);
  if (*(ushort *)((int)this + 6) < 7) {
    *(int *)(&DAT_004358a8 + (uint)*(ushort *)((int)this + 6) * 4) = param_1;
  }
  return 1;
}



/* 0040df80  FUN_0040df80  36 bytes, 1 callers */

void __fastcall FUN_0040df80(int param_1)

{
  MCIERROR MVar1;
  
  if (*(ushort *)(param_1 + 6) != 0) {
    MVar1 = mciSendCommandA((uint)*(ushort *)(param_1 + 6),0x808,2,0);
    *(MCIERROR *)(param_1 + 0x4c) = MVar1;
  }
  return;
}



/* 0040dfb0  FUN_0040dfb0  229 bytes, 1 callers */

undefined4 __fastcall FUN_0040dfb0(int *param_1)

{
  int iVar1;
  MCIERROR MVar2;
  int iVar3;
  
  param_1[0x11] = 10;
  MVar2 = mciSendCommandA((uint)*(ushort *)((int)param_1 + 6),0x80d,0x402,
                          (DWORD_PTR)(param_1 + 0x10));
  param_1[0x13] = MVar2;
  if (MVar2 != 0) {
    (**(code **)(*param_1 + 0xc))();
    return 0;
  }
  param_1[0xe] = 3;
  MVar2 = mciSendCommandA((uint)*(ushort *)((int)param_1 + 6),0x814,0x112,(DWORD_PTR)(param_1 + 0xc)
                         );
  param_1[0x13] = MVar2;
  param_1[0x16] = param_1[0xd];
  if (param_1[0x13] != 0) {
    (**(code **)(*param_1 + 0xc))();
    return 0;
  }
  param_1[0x15] = 0;
  param_1[0xe] = 1;
  iVar3 = 1;
  if (0 < param_1[0xd]) {
    do {
      if (0xff < iVar3) break;
      param_1[0xf] = iVar3;
      MVar2 = mciSendCommandA((uint)*(ushort *)((int)param_1 + 6),0x814,0x112,
                              (DWORD_PTR)(param_1 + 0xc));
      param_1[0x13] = MVar2;
      iVar1 = param_1[0xd];
      param_1[iVar3 + 0x17] = iVar1;
      if (param_1[0x13] != 0) {
        (**(code **)(*param_1 + 0xc))();
        return 0;
      }
      iVar3 = iVar3 + 1;
      param_1[0x15] = param_1[0x15] + iVar1;
    } while (iVar3 <= param_1[0x16]);
  }
  *(undefined1 *)(param_1 + 0x14) = 1;
  return 1;
}



/* 0040e0c0  FUN_0040e0c0  95 bytes, 0 callers */

undefined4 __fastcall FUN_0040e0c0(int *param_1)

{
  MCIERROR MVar1;
  
  if (*(short *)((int)param_1 + 6) != 0) {
    (**(code **)(*param_1 + 0xc))();
  }
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[4] = (int)s_waveaudio_004326dc;
  param_1[2] = 0;
  MVar1 = mciSendCommandA(0,0x803,0x2202,(DWORD_PTR)(param_1 + 2));
  param_1[0x13] = MVar1;
  if (MVar1 != 0) {
    *(undefined2 *)((int)param_1 + 6) = 0;
    return 0;
  }
  *(short *)((int)param_1 + 6) = (short)param_1[3];
  return 1;
}



/* 0040e120  FUN_0040e120  146 bytes, 0 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0040e120(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  MCIERROR MVar3;
  
  iVar1 = *(int *)this;
  *(int *)((int)this + 0x14) = param_1 * 0x220 + DAT_00435db0 + 0x114;
  iVar2 = (**(code **)(iVar1 + 4))();
  if (iVar2 == 0) {
    return 0;
  }
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  _DAT_004358c4 = 0;
  MVar3 = mciSendCommandA((uint)*(ushort *)((int)this + 6),0x806,1,(int)this + 0x1c);
  *(MCIERROR *)((int)this + 0x4c) = MVar3;
  if (MVar3 != 0) {
    (**(code **)(iVar1 + 0xc))();
    return 0;
  }
  if (*(ushort *)((int)this + 6) < 7) {
    *(int *)(&DAT_004358a8 + (uint)*(ushort *)((int)this + 6) * 4) = param_1;
  }
  return 1;
}



/* 0040e2f0  FUN_0040e2f0  15 bytes, 4 callers */

undefined4 * __fastcall FUN_0040e2f0(undefined4 *param_1)

{
  HMENU pHVar1;
  
  pHVar1 = CreatePopupMenu();
  *param_1 = pHVar1;
  return param_1;
}



/* 0040e300  thunk_FUN_0040e460  5 bytes, 11 callers */

void __fastcall thunk_FUN_0040e460(undefined4 *param_1)

{
  if ((HMENU)*param_1 != (HMENU)0x0) {
    DestroyMenu((HMENU)*param_1);
    *param_1 = 0;
  }
  return;
}



/* 0040e310  FUN_0040e310  31 bytes, 4 callers */

void __thiscall FUN_0040e310(void *this,UINT_PTR param_1,LPCSTR param_2,UINT param_3)

{
  if (*(HMENU *)this != (HMENU)0x0) {
    AppendMenuA(*(HMENU *)this,param_3,param_1,param_2);
  }
  return;
}



/* 0040e330  FUN_0040e330  85 bytes, 4 callers */

void __thiscall FUN_0040e330(void *this,UINT_PTR param_1,UINT param_2,UINT param_3)

{
  CHAR local_104 [260];
  
  if (*(int *)this != 0) {
    LoadStringA(DAT_004344d0,param_2,local_104,0x103);
    AppendMenuA(*(HMENU *)this,param_3,param_1,local_104);
  }
  return;
}



/* 0040e390  FUN_0040e390  28 bytes, 2 callers */

void __thiscall FUN_0040e390(void *this,UINT_PTR param_1,LPCSTR param_2)

{
  if (*(HMENU *)this != (HMENU)0x0) {
    AppendMenuA(*(HMENU *)this,0x10,param_1,param_2);
  }
  return;
}



/* 0040e3b0  FUN_0040e3b0  79 bytes, 1 callers */

void __thiscall FUN_0040e3b0(void *this,UINT_PTR param_1,UINT param_2)

{
  CHAR local_104 [260];
  
  if (*(int *)this != 0) {
    LoadStringA(DAT_004344d0,param_2,local_104,0x103);
    AppendMenuA(*(HMENU *)this,0x10,param_1,local_104);
  }
  return;
}



/* 0040e400  FUN_0040e400  23 bytes, 4 callers */

void __fastcall FUN_0040e400(undefined4 *param_1)

{
  if ((HMENU)*param_1 != (HMENU)0x0) {
    AppendMenuA((HMENU)*param_1,0x800,0,(LPCSTR)0x0);
  }
  return;
}



/* 0040e420  FUN_0040e420  23 bytes, 2 callers */

void __thiscall FUN_0040e420(void *this,UINT param_1)

{
  if (*(HMENU *)this != (HMENU)0x0) {
    CheckMenuItem(*(HMENU *)this,param_1,8);
  }
  return;
}



/* 0040e440  FUN_0040e440  26 bytes, 3 callers */

void __thiscall FUN_0040e440(void *this,UINT param_1,UINT param_2)

{
  if (*(HMENU *)this != (HMENU)0x0) {
    EnableMenuItem(*(HMENU *)this,param_1,param_2);
  }
  return;
}



/* 0040e460  FUN_0040e460  24 bytes, 0 callers */

void __fastcall FUN_0040e460(undefined4 *param_1)

{
  if ((HMENU)*param_1 != (HMENU)0x0) {
    DestroyMenu((HMENU)*param_1);
    *param_1 = 0;
  }
  return;
}



/* 0040e480  FUN_0040e480  10 bytes, 1 callers */

int __fastcall FUN_0040e480(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  return param_1;
}



/* 0040e4a0  FUN_0040e4a0  133 bytes, 1 callers */

bool __thiscall FUN_0040e4a0(void *this,undefined4 param_1)

{
  bool bVar1;
  HDC hdc;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  *(undefined4 *)this = param_1;
  hdc = CreateDCA(s_DISPLAY_004326e8,(LPCSTR)0x0,(LPCSTR)0x0,(DEVMODEA *)0x0);
  if (hdc != (HDC)0x0) {
    GetSystemPaletteEntries(hdc,0,0x100,(LPPALETTEENTRY)((int)this + 0xc));
    puVar2 = (undefined1 *)((int)this + 0xe);
    puVar3 = &DAT_00436000;
    do {
      puVar4 = puVar3 + 4;
      *puVar3 = *puVar2;
      puVar3[1] = puVar2[-1];
      puVar3[2] = puVar2[-2];
      puVar3[3] = 0;
      puVar2 = puVar2 + 4;
      puVar3 = puVar4;
    } while (puVar4 < &DAT_00436400);
    DeleteDC(hdc);
  }
  if (*(int *)((int)this + 4) == 0) {
    bVar1 = FUN_0040e530((int)this);
    return bVar1;
  }
  return true;
}



/* 0040e530  FUN_0040e530  35 bytes, 2 callers */

bool __fastcall FUN_0040e530(int param_1)

{
  HPALETTE pHVar1;
  
  ((LOGPALETTE *)(param_1 + 8))->palVersion = 0x300;
  *(undefined2 *)(param_1 + 10) = 0x100;
  pHVar1 = CreatePalette((LOGPALETTE *)(param_1 + 8));
  *(HPALETTE *)(param_1 + 4) = pHVar1;
  return (bool)('\x01' - (pHVar1 == (HPALETTE)0x0));
}



/* 0040e560  FUN_0040e560  110 bytes, 4 callers */

void __thiscall FUN_0040e560(void *this,undefined1 *param_1,int param_2,uint param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_3 != 0) {
    puVar2 = &DAT_00436000 + param_2 * 4;
    puVar1 = (undefined1 *)((int)this + param_2 * 4 + 0xc);
    do {
      if ((9 < uVar3 + param_2) && (uVar3 + param_2 < 0xf6)) {
        *puVar1 = *param_1;
        puVar1[1] = param_1[1];
        puVar1[2] = param_1[2];
        puVar1[3] = 1;
        *puVar2 = param_1[2];
        puVar2[1] = param_1[1];
        puVar2[2] = *param_1;
        puVar2[3] = 0;
      }
      puVar2 = puVar2 + 4;
      puVar1 = puVar1 + 4;
      param_1 = param_1 + 4;
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_3);
  }
  return;
}



/* 0040e5d0  FUN_0040e5d0  38 bytes, 1 callers */

void __thiscall FUN_0040e5d0(void *this,int param_1,undefined1 *param_2)

{
  *param_2 = *(undefined1 *)((int)this + param_1 * 4 + 0xc);
  param_2[1] = *(undefined1 *)((int)this + param_1 * 4 + 0xd);
  param_2[2] = *(undefined1 *)((int)this + param_1 * 4 + 0xe);
  param_2[3] = *(undefined1 *)((int)this + param_1 * 4 + 0xf);
  return;
}



/* 0040e600  FUN_0040e600  50 bytes, 2 callers */

undefined4 __fastcall FUN_0040e600(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  if (*(int *)(param_1 + 4) == 0) {
    bVar1 = FUN_0040e530(param_1);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      return 0;
    }
  }
  SetPaletteEntries(*(HPALETTE *)(param_1 + 4),0,0x100,(PALETTEENTRY *)(param_1 + 0xc));
  return 1;
}



/* 0040e640  FUN_0040e640  69 bytes, 1 callers */

void __fastcall FUN_0040e640(int param_1)

{
  HDC hdc;
  HPALETTE hPal;
  
  hdc = CreateDCA(s_DISPLAY_004326e8,(LPCSTR)0x0,(LPCSTR)0x0,(DEVMODEA *)0x0);
  if (hdc != (HDC)0x0) {
    hPal = SelectPalette(hdc,*(HPALETTE *)(param_1 + 4),0);
    RealizePalette(hdc);
    SelectPalette(hdc,hPal,1);
    DeleteDC(hdc);
  }
  return;
}



/* 0040e6b0  FUN_0040e6b0  74 bytes, 14 callers */

undefined4 * __thiscall FUN_0040e6b0(void *this,WPARAM param_1)

{
  *(undefined ***)this = &PTR_FUN_00430250;
  *(WPARAM *)((int)this + 0x14) = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x228) = 0;
  *(undefined4 *)((int)this + 0x224) = 0;
  *(undefined4 *)((int)this + 0x230) = 0;
  FUN_00409d50(param_1,1);
  ClipCursor((RECT *)0x0);
  return this;
}



/* 0040e700  FUN_0040e700  30 bytes, 0 callers */

undefined4 * __thiscall FUN_0040e700(void *this,byte param_1)

{
  FUN_0040e720(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 0040e720  FUN_0040e720  76 bytes, 17 callers */

void __fastcall FUN_0040e720(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00430250;
  if (param_1[0x8c] != 0) {
    KillTimer((HWND)param_1[1],param_1[0x8c]);
    param_1[0x8c] = 0;
  }
  if ((HDC)param_1[0x89] != (HDC)0x0) {
    DeleteDC((HDC)param_1[0x89]);
  }
  if ((HGDIOBJ)param_1[0x8a] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)param_1[0x8a]);
  }
  return;
}



/* 0040e770  FUN_0040e770  31 bytes, 0 callers */

void __thiscall
FUN_0040e770(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 0xc) = param_3;
  *(undefined4 *)((int)this + 0x10) = param_4;
  return;
}



/* 0040e9b0  FUN_0040e9b0  136 bytes, 0 callers */

undefined4 __fastcall FUN_0040e9b0(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  wsprintfA((LPSTR)(param_1 + 0x1c),s_Pos_d_00433518,*(undefined4 *)(param_1 + 0x14));
  bVar1 = FUN_00424fa0(DAT_00436460,(LPSTR)(param_1 + 0x1c));
  if (CONCAT31(extraout_var,bVar1) == 1) {
    iVar2 = GetSystemMetrics(0);
    if ((iVar2 <= *(int *)((int)DAT_00436460 + 0x34)) ||
       (iVar2 = GetSystemMetrics(1), iVar2 <= *(int *)((int)DAT_00436460 + 0x38))) {
      *(undefined4 *)((int)DAT_00436460 + 0x34) = 0;
      *(undefined4 *)((int)DAT_00436460 + 0x38) = 0;
    }
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0x0,*(int *)((int)DAT_00436460 + 0x34),
                 *(int *)((int)DAT_00436460 + 0x38),0,0,5);
    return 1;
  }
  return 1;
}



/* 0040eb00  FUN_0040eb00  110 bytes, 0 callers */

void __fastcall FUN_0040eb00(int *param_1)

{
  HDC hdc;
  HPALETTE hPal;
  tagPAINTSTRUCT local_40;
  
  hdc = BeginPaint((HWND)param_1[1],&local_40);
  if (hdc != (HDC)0x0) {
    hPal = SelectPalette(hdc,DAT_004365f4,0);
    SelectPalette((HDC)param_1[0x89],DAT_004365f4,0);
    RealizePalette(hdc);
    (**(code **)(*param_1 + 0x1c))(hdc);
    SelectPalette(hdc,hPal,1);
    EndPaint((HWND)param_1[1],(PAINTSTRUCT *)&stack0xffffffbc);
  }
  return;
}



/* 0040eb70  FUN_0040eb70  71 bytes, 5 callers */

void __fastcall FUN_0040eb70(int param_1)

{
  wsprintfA((LPSTR)(param_1 + 0x1c),s_Pos_d_00433518,*(undefined4 *)(param_1 + 0x14));
  FUN_00425010(DAT_00436460,(LPSTR)(param_1 + 0x1c),*(HWND *)(param_1 + 4));
  FUN_00409d50(*(WPARAM *)(param_1 + 0x14),0);
  EndDialog(*(HWND *)(param_1 + 4),0);
  return;
}



/* 0040ebc0  FUN_0040ebc0  71 bytes, 0 callers */

void __thiscall FUN_0040ebc0(void *this,HDC param_1)

{
  tagRECT local_10;
  
  GetClientRect(*(HWND *)((int)this + 4),&local_10);
  StretchBlt(param_1,0,0,local_10.right,local_10.bottom,*(HDC *)((int)this + 0x224),0,0,
             local_10.right,local_10.bottom,0xcc0020);
  return;
}



/* 0040ec30  FUN_0040ec30  27 bytes, 4 callers */

void __thiscall FUN_0040ec30(void *this,int param_1)

{
  SendDlgItemMessageA(*(HWND *)((int)this + 4),param_1,0x188,0,0);
  return;
}



/* 0040ec50  FUN_0040ec50  30 bytes, 1 callers */

void __thiscall FUN_0040ec50(void *this,int param_1,LPARAM param_2)

{
  SendDlgItemMessageA(*(HWND *)((int)this + 4),param_1,0x180,0,param_2);
  return;
}



/* 0040ec70  FUN_0040ec70  33 bytes, 1 callers */

void __thiscall FUN_0040ec70(void *this,int param_1,WPARAM param_2,LPARAM param_3)

{
  SendDlgItemMessageA(*(HWND *)((int)this + 4),param_1,0x189,param_2,param_3);
  return;
}



/* 0040eca0  FUN_0040eca0  27 bytes, 3 callers */

void __thiscall FUN_0040eca0(void *this,int param_1,LPARAM param_2)

{
  SendDlgItemMessageA(*(HWND *)((int)this + 4),param_1,0xc,0,param_2);
  return;
}



/* 0040ecc0  FUN_0040ecc0  30 bytes, 2 callers */

void __thiscall FUN_0040ecc0(void *this,int param_1,LPARAM param_2)

{
  SendDlgItemMessageA(*(HWND *)((int)this + 4),param_1,0xd,0x104,param_2);
  return;
}



/* 0040ece0  FUN_0040ece0  30 bytes, 0 callers */

void __thiscall FUN_0040ece0(void *this,int param_1,WPARAM param_2)

{
  SendDlgItemMessageA(*(HWND *)((int)this + 4),param_1,0xf1,param_2,0);
  return;
}



/* 0040ed00  FUN_0040ed00  27 bytes, 2 callers */

void __thiscall FUN_0040ed00(void *this,int param_1)

{
  SendDlgItemMessageA(*(HWND *)((int)this + 4),param_1,0xf0,0,0);
  return;
}



/* 0040ed20  FUN_0040ed20  30 bytes, 2 callers */

void __thiscall FUN_0040ed20(void *this,int param_1,LPCSTR param_2)

{
  HWND hWnd;
  
  hWnd = GetDlgItem(*(HWND *)((int)this + 4),param_1);
  SetWindowTextA(hWnd,param_2);
  return;
}



/* 0040ed80  FUN_0040ed80  34 bytes, 11 callers */

void __thiscall FUN_0040ed80(void *this,int param_1,BOOL param_2)

{
  HWND hWnd;
  
  hWnd = GetDlgItem(*(HWND *)((int)this + 4),param_1);
  if (hWnd != (HWND)0x0) {
    EnableWindow(hWnd,param_2);
  }
  return;
}



/* 0040edb0  FUN_0040edb0  30 bytes, 1 callers */

void __thiscall FUN_0040edb0(void *this,int param_1,LPARAM param_2)

{
  SendDlgItemMessageA(*(HWND *)((int)this + 4),param_1,0x143,0,param_2);
  return;
}



/* 0040edd0  FUN_0040edd0  27 bytes, 2 callers */

void __thiscall FUN_0040edd0(void *this,int param_1)

{
  SendDlgItemMessageA(*(HWND *)((int)this + 4),param_1,0x147,0,0);
  return;
}



/* 0040edf0  FUN_0040edf0  30 bytes, 1 callers */

void __thiscall FUN_0040edf0(void *this,int param_1,WPARAM param_2)

{
  SendDlgItemMessageA(*(HWND *)((int)this + 4),param_1,0x14e,param_2,0);
  return;
}



/* 0040ee10  FUN_0040ee10  87 bytes, 1 callers */

undefined4 * __thiscall FUN_0040ee10(void *this,WPARAM param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040ee67;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  *(undefined ***)this = &PTR_LAB_00430290;
  *unaff_FS_OFFSET = local_10;
  return this;
}



/* 0040eed9  FUN_0040eed9  8 bytes, 0 callers */

void FUN_0040eed9(void)

{
  int unaff_EBP;
  
  FUN_0040e720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 0040ef20  FUN_0040ef20  91 bytes, 1 callers */

undefined4 * __thiscall FUN_0040ef20(void *this,WPARAM param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040ef7b;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  *(undefined ***)this = &PTR_FUN_004302d0;
  *(undefined4 *)((int)this + 0x234) = 0;
  *unaff_FS_OFFSET = local_10;
  return this;
}



/* 0040ef90  FUN_0040ef90  30 bytes, 0 callers */

undefined4 * __thiscall FUN_0040ef90(void *this,byte param_1)

{
  FUN_0040efb0(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 0040efb0  FUN_0040efb0  61 bytes, 1 callers */

void __fastcall FUN_0040efb0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_0040efed;
  *param_1 = &PTR_FUN_004302d0;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_0040eff7();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 0040eff7  FUN_0040eff7  8 bytes, 1 callers */

void FUN_0040eff7(void)

{
  int unaff_EBP;
  
  FUN_0040e720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 0040f1b0  FUN_0040f1b0  130 bytes, 0 callers */

void __fastcall FUN_0040f1b0(void *param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  DAT_004376a4 = FUN_0040ed00(param_1,0x42c);
  DAT_004376a5 = FUN_0040ed00(param_1,0x42e);
  DAT_004376a6 = FUN_0040ed00(param_1,0x42b);
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 1;
    uVar1 = FUN_0040ed00(param_1,iVar2 + 0x42f);
    (&DAT_004376a7)[iVar2] = uVar1;
    iVar2 = iVar3;
  } while (iVar3 < 4);
  DAT_004376ad = FUN_0040ed00(param_1,0x459);
  DAT_004376a1 = FUN_0040ed00(param_1,0x45a);
  FUN_0040a800();
  FUN_0040eb70((int)param_1);
  return;
}



/* 0040f260  FUN_0040f260  102 bytes, 2 callers */

undefined4 * __thiscall FUN_0040f260(void *this,WPARAM param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040f2d4;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  local_8 = 0;
  FUN_0041f8b0((int)this + 0x238);
  *(undefined ***)this = &PTR_LAB_00430310;
  *unaff_FS_OFFSET = local_10;
  return this;
}



/* 0040f34c  FUN_0040f34c  14 bytes, 0 callers */

void FUN_0040f34c(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(*(int *)(unaff_EBP + -0x10) + 0x238));
  return;
}



/* 0040f364  FUN_0040f364  8 bytes, 0 callers */

void FUN_0040f364(void)

{
  int unaff_EBP;
  
  FUN_0040e720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 0040f370  FUN_0040f370  402 bytes, 1 callers */

void __thiscall FUN_0040f370(void *this,int param_1)

{
  LPSTR lpFileName;
  bool bVar1;
  HANDLE hFindFile;
  DWORD DVar2;
  undefined3 extraout_var;
  int iVar3;
  BOOL BVar4;
  int aiStack_18c [3];
  undefined4 uStack_180;
  ushort uStack_17a;
  undefined4 uStack_168;
  int iStack_15c;
  _WIN32_FIND_DATAA local_140;
  
  lpFileName = (LPSTR)((int)this + 0x1c);
  SendDlgItemMessageA(*(HWND *)((int)this + 4),param_1,0x184,0,0);
  *(undefined4 *)((int)this + 0x234) = 0;
  FUN_0040bda0(&DAT_00436468,lpFileName,s___ds7_0043227c);
  do {
    hFindFile = FindFirstFileA(lpFileName,&local_140);
    if ((hFindFile != (HANDLE)0xffffffff) || ((DVar2 = GetLastError(), 1 < DVar2 && (DVar2 < 4))))
    goto LAB_0040f3ef;
    bVar1 = FUN_0040c2e0();
  } while (CONCAT31(extraout_var,bVar1) != 0);
  (**(code **)(*(int *)this + 0x38))();
LAB_0040f3ef:
  do {
    FUN_0040bda0(&DAT_00436468,lpFileName,local_140.cFileName);
    iVar3 = FUN_0040c010(lpFileName,aiStack_18c,0x4c);
    if ((iVar3 != 0) && (aiStack_18c[0] != -1)) {
      if (iStack_15c == -1) {
        wsprintfA(lpFileName,s__s___Map_d__dLeft____4d__2d__2d_0043352c,local_140.cFileName,
                  aiStack_18c[0] + 1,uStack_168,uStack_180 & 0xffff,(uint)uStack_180._2_2_,
                  (uint)uStack_17a);
      }
      else {
        wsprintfA(lpFileName,s__s___Map_d_Beginning____4d__2d___0043354c,local_140.cFileName,
                  aiStack_18c[0] + 1,uStack_180 & 0xffff,(uint)uStack_180._2_2_,(uint)uStack_17a);
      }
      *(int *)((int)this + 0x234) = *(int *)((int)this + 0x234) + 1;
      SendDlgItemMessageA(*(HWND *)((int)this + 4),param_1,0x180,0,(LPARAM)lpFileName);
    }
    BVar4 = FindNextFileA(hFindFile,&local_140);
  } while (BVar4 != 0);
  if (hFindFile != (HANDLE)0xffffffff) {
    FindClose(hFindFile);
  }
  if (*(int *)((int)this + 0x234) != 0) {
    FUN_0040ed80(this,param_1,1);
  }
  return;
}



/* 0040f510  FUN_0040f510  98 bytes, 3 callers */

void __fastcall FUN_0040f510(void *param_1)

{
  char cVar1;
  WPARAM WVar2;
  int iVar3;
  
  iVar3 = (int)param_1 + 0x120;
  WVar2 = FUN_0040ec30(param_1,0x3f7);
  FUN_0040ec70(param_1,0x3f7,WVar2,iVar3);
  iVar3 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + iVar3 + 0x120);
    if ((cVar1 == '.') || (cVar1 == '\0')) break;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xff);
  *(undefined1 *)((int)param_1 + iVar3 + 0x120) = 0x2e;
  *(undefined1 *)((int)param_1 + iVar3 + 0x121) = 100;
  *(undefined1 *)((int)param_1 + iVar3 + 0x122) = 0x73;
  *(undefined1 *)((int)param_1 + iVar3 + 0x123) = 0x37;
  *(undefined1 *)((int)param_1 + iVar3 + 0x124) = 0;
  return;
}



/* 0040f580  FUN_0040f580  87 bytes, 1 callers */

undefined4 * __thiscall FUN_0040f580(void *this,WPARAM param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040f5d7;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040f260(this,param_1);
  *(undefined ***)this = &PTR_LAB_00430350;
  *unaff_FS_OFFSET = local_10;
  return this;
}



/* 0040f5f0  FUN_0040f5f0  68 bytes, 2 callers */

void FUN_0040f5f0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_0040f642;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0;
  FUN_0040f634();
  local_8 = 0xffffffff;
  FUN_0040f64c();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 0040f634  FUN_0040f634  14 bytes, 1 callers */

void FUN_0040f634(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(*(int *)(unaff_EBP + -0x10) + 0x238));
  return;
}



/* 0040f64c  FUN_0040f64c  8 bytes, 1 callers */

void FUN_0040f64c(void)

{
  int unaff_EBP;
  
  FUN_0040e720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 0040f6b9  FUN_0040f6b9  8 bytes, 0 callers */

void FUN_0040f6b9(void)

{
  FUN_0040f5f0();
  return;
}



/* 0040f7b9  FUN_0040f7b9  11 bytes, 0 callers */

void FUN_0040f7b9(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x234));
  return;
}



/* 0040f810  FUN_0040f810  38 bytes, 0 callers */

void __fastcall FUN_0040f810(void *param_1)

{
  FUN_0040f510(param_1);
  FUN_0040ed80(param_1,0x3fb,1);
  FUN_0040ed80(param_1,0x3fc,1);
  return;
}



/* 0040f840  FUN_0040f840  46 bytes, 0 callers */

void __fastcall FUN_0040f840(int *param_1)

{
  int *piVar1;
  
  piVar1 = param_1 + 0x48;
  FUN_0040ecc0(param_1,0x455,(LPARAM)piVar1);
  FUN_00405740((int)piVar1,(int)piVar1,&DAT_0043211c);
  FUN_0040f870(param_1);
  return;
}



/* 0040f870  FUN_0040f870  216 bytes, 1 callers */

void __fastcall FUN_0040f870(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined2 local_230 [272];
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040f948;
  *unaff_FS_OFFSET = &local_10;
  FUN_0041f8b0((int)local_230);
  local_8 = 0;
  FUN_0040bda0(&DAT_00436468,(LPSTR)(param_1 + 7),param_1 + 0x48);
  bVar1 = FUN_0041f9f0(local_230,(LPCSTR)(param_1 + 7));
  FUN_0041fa40(local_230);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iVar2 = FUN_00409370(s_Overwrite_saved_game__0043359c,4);
    if (iVar2 == 7) goto LAB_0040f8eb;
  }
  FUN_0040ed80(param_1,0x3fc,0);
  FUN_0040ed80(param_1,0x3fb,0);
  iVar2 = FUN_00405b90((int)(param_1 + 0x48));
  if (iVar2 == 0) {
    FUN_00409370(s_Failed_in_writting_file__00433580,0);
  }
  (**(code **)(*param_1 + 0x38))();
LAB_0040f8eb:
  local_8 = 0xffffffff;
  FUN_0040f952();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 0040f952  FUN_0040f952  11 bytes, 1 callers */

void FUN_0040f952(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x22c));
  return;
}



/* 0040f960  FUN_0040f960  145 bytes, 0 callers */

void __fastcall FUN_0040f960(void *param_1)

{
  LPSTR lpFileName;
  int iVar1;
  int iVar2;
  BOOL BVar3;
  
  iVar1 = (int)param_1 + 0x120;
  lpFileName = (LPSTR)((int)param_1 + 0x1c);
  FUN_0040f510(param_1);
  wsprintfA(lpFileName,s_Delete___s__004335dc,iVar1);
  iVar2 = FUN_00409370(lpFileName,4);
  if (iVar2 == 6) {
    FUN_0040bda0(&DAT_00436468,lpFileName,iVar1);
    BVar3 = DeleteFileA(lpFileName);
    if (BVar3 == 0) {
      wsprintfA(lpFileName,s_Failed_in_deleating_filename_the_004335b4,iVar1);
      FUN_00409370(lpFileName,0);
    }
    FUN_0040ed80(param_1,0x3fc,0);
    FUN_0040ed80(param_1,0x3fb,0);
    FUN_0040f370(param_1,0x3f7);
  }
  return;
}



/* 0040fa00  FUN_0040fa00  87 bytes, 1 callers */

undefined4 * __thiscall FUN_0040fa00(void *this,WPARAM param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040fa57;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040f260(this,param_1);
  *(undefined ***)this = &PTR_LAB_00430390;
  *unaff_FS_OFFSET = local_10;
  return this;
}



/* 0040fac9  FUN_0040fac9  8 bytes, 0 callers */

void FUN_0040fac9(void)

{
  FUN_0040f5f0();
  return;
}



/* 0040fb10  FUN_0040fb10  13 bytes, 0 callers */

void __fastcall FUN_0040fb10(void *param_1)

{
  FUN_0040ed80(param_1,0x456,1);
  return;
}



/* 0040fb20  FUN_0040fb20  85 bytes, 0 callers */

void __fastcall FUN_0040fb20(int *param_1)

{
  int iVar1;
  
  FUN_00408e20();
  FUN_0040f510(param_1);
  iVar1 = FUN_00405900((int)(param_1 + 0x48));
  if (iVar1 == 0) {
    FUN_00409370(s_Failed_in_reading_file__004335e8,0);
    return;
  }
  DAT_0043451c = 0;
  FUN_00405330();
  FUN_00427210();
  FUN_0041b370();
  (**(code **)(*param_1 + 0x38))();
  return;
}



/* 0040fb80  FUN_0040fb80  133 bytes, 1 callers */

undefined4 * __thiscall FUN_0040fb80(void *this,WPARAM param_1,undefined4 param_2)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040fc05;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  *(undefined ***)this = &PTR_FUN_004303d0;
  *(undefined4 *)((int)this + 0x23c) = param_2;
  *(undefined4 *)((int)this + 0x238) = 0;
  *(undefined4 *)((int)this + 0x5838) = 0;
  *(undefined4 *)((int)this + 0x244) = 0;
  *(undefined4 *)((int)this + 0x248) = 0;
  *(undefined4 *)((int)this + 0x24c) = 0;
  *(undefined4 *)((int)this + 0x250) = 0;
  *(undefined4 *)((int)this + 0x254) = 0;
  *unaff_FS_OFFSET = local_10;
  return this;
}



/* 0040fc20  FUN_0040fc20  30 bytes, 0 callers */

undefined4 * __thiscall FUN_0040fc20(void *this,byte param_1)

{
  FUN_0040fc40(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 0040fc40  FUN_0040fc40  61 bytes, 1 callers */

void __fastcall FUN_0040fc40(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_0040fc7d;
  *param_1 = &PTR_FUN_004303d0;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_0040fc87();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 0040fc87  FUN_0040fc87  8 bytes, 1 callers */

void FUN_0040fc87(void)

{
  int unaff_EBP;
  
  FUN_0040e720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 0040ffe0  FUN_0040ffe0  52 bytes, 4 callers */

void __fastcall FUN_0040ffe0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar2 = 0;
  do {
    puVar4 = (undefined4 *)(*(int *)(param_1 + 0x22c) + iVar2);
    puVar3 = (undefined4 *)(DAT_00435fd4 + 0x20000 + iVar2);
    iVar2 = iVar2 + 0x100;
    for (iVar1 = 0x34; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  } while (iVar2 < 0x4000);
  return;
}



/* 00410020  FUN_00410020  451 bytes, 0 callers */

void __fastcall FUN_00410020(void *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  switch(*(undefined4 *)((int)param_1 + 0x23c)) {
  case 0:
    FUN_00410680(param_1);
    break;
  case 1:
    FUN_00410910(param_1);
    break;
  case 2:
    FUN_00410be0(param_1);
    break;
  case 3:
    FUN_00410d00(param_1);
    break;
  case 4:
    FUN_00411050(param_1);
  }
  puVar4 = (undefined4 *)((int)param_1 + 0x1838);
  puVar5 = (undefined4 *)(*(int *)((int)param_1 + 0x22c) + 0xc000);
  for (iVar3 = 0x1000; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  iVar3 = 0;
  piVar6 = (int *)((int)param_1 + 0x25c);
  do {
    if ((char)piVar6[-1] != '\0') {
      if (*(int *)((int)param_1 + 0x5838) == 0) {
        iVar2 = *piVar6;
        *piVar6 = iVar2 + -1;
        if (iVar2 + -1 == 0) {
          FUN_00410200(param_1,iVar3);
        }
      }
      else {
        *(int *)((int)param_1 + 0x5838) = *(int *)((int)param_1 + 0x5838) + -1;
      }
      FUN_004104d0(param_1,iVar3);
    }
    piVar6 = piVar6 + 0x46;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x14);
  *(undefined4 *)((int)param_1 + 0x248) = 0;
  do {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      iVar3 = *(int *)((int)param_1 + 0x248) * 0x100;
      cVar1 = *(char *)(DAT_00435fd4 + iVar3 + 0x2c000 + *(int *)((int)param_1 + 0x244));
      if (cVar1 != 'p') {
        *(char *)(*(int *)((int)param_1 + 0x22c) + iVar3 + 0xc000 + *(int *)((int)param_1 + 0x244))
             = cVar1;
      }
      iVar3 = *(int *)((int)param_1 + 0x248) * 0x100;
      cVar1 = *(char *)(DAT_00435fd4 + iVar3 + 0x2c0e0 + *(int *)((int)param_1 + 0x244));
      if (cVar1 != 'p') {
        *(char *)(*(int *)((int)param_1 + 0x22c) + iVar3 + 0xc0e0 + *(int *)((int)param_1 + 0x244))
             = cVar1;
      }
      iVar3 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar3;
    } while (iVar3 < 0x20);
    iVar3 = *(int *)((int)param_1 + 0x248) + 1;
    *(int *)((int)param_1 + 0x248) = iVar3;
  } while (iVar3 < 0x40);
  if (*(int *)((int)param_1 + 0x238) == 400) {
    FUN_0040ffe0((int)param_1);
    FUN_0040a870(0xe,0x14,6,7,s_Click_here_00433614,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    FUN_0040a870(0xe,0x28,6,7,s_to_go_on__00433600,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
  }
  InvalidateRect(*(HWND *)((int)param_1 + 4),(RECT *)0x0,0);
  UpdateWindow(*(HWND *)((int)param_1 + 4));
  if (*(int *)((int)param_1 + 0x238) < 1000) {
    *(int *)((int)param_1 + 0x238) = *(int *)((int)param_1 + 0x238) + 1;
  }
  return;
}



/* 00410200  FUN_00410200  407 bytes, 1 callers */

void __thiscall FUN_00410200(void *this,int param_1)

{
  char *pcVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x8c + (int)*(char *)((int)this + param_1 * 0x118 + 0x368);
  *(undefined4 *)((int)this + param_1 * 0x118 + 0x25c) = 1;
  *(undefined1 *)((int)this + param_1 * 0x118 + 0x268) =
       *(undefined1 *)((int)this + iVar3 * 2 + 0x26a);
  uVar2 = *(ushort *)((int)this + iVar3 * 2 + 0x26a);
  if (uVar2 < 0xe) {
    if (9 < uVar2) {
      *(uint *)((int)this + param_1 * 0x118 + 0x25c) =
           (uint)*(ushort *)((int)this + iVar3 * 2 + 0x26c) << 4;
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x02';
      return;
    }
    switch(uVar2) {
    case 0:
    case 2:
    case 4:
    case 6:
      *(char *)((int)this + param_1 * 0x118 + 0x36b) = (char)uVar2;
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x01';
      return;
    }
  }
  else {
    switch(uVar2) {
    case 0xf:
      *(uint *)((int)this + param_1 * 0x118 + 0x25c) =
           (uint)*(ushort *)((int)this + iVar3 * 2 + 0x26c);
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x02';
      return;
    case 0x10:
      *(uint *)((int)this + param_1 * 0x118 + 0x25c) =
           (uint)*(ushort *)((int)this + iVar3 * 2 + 0x26c);
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x02';
      return;
    case 0x12:
      *(byte *)((int)this + param_1 * 0x118 + 0x36a) =
           *(char *)((int)this + param_1 * 0x118 + 0x36c) * '\b' +
           *(char *)((int)this + iVar3 * 2 + 0x26c) | 0xa4;
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x02';
      return;
    case 0x13:
      *(byte *)((int)this + param_1 * 0x118 + 0x36a) =
           *(char *)((int)this + param_1 * 0x118 + 0x36c) * '\b' +
           *(char *)((int)this + iVar3 * 2 + 0x26c) | 0xa0;
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x02';
      return;
    case 0x14:
      *(byte *)((int)this + param_1 * 0x118 + 0x36a) =
           (byte)*(undefined2 *)((int)this + iVar3 * 2 + 0x26c) | 200;
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x02';
      return;
    case 0x15:
      *(undefined4 *)((int)this + param_1 * 0x118 + 0x25c) = 0xffffffff;
      return;
    case 0x16:
      *(uint *)((int)this + 0x5838) = (uint)*(ushort *)((int)this + iVar3 * 2 + 0x26c);
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x02';
      return;
    case 0xff:
      *(undefined1 *)((int)this + param_1 * 0x118 + 600) = 0;
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x01';
    }
  }
  return;
}



/* 004104d0  FUN_004104d0  349 bytes, 1 callers */

void __thiscall FUN_004104d0(void *this,int param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  
  bVar2 = false;
  if (*(int *)((int)this + 0x5838) == 0) {
    switch(*(undefined1 *)((int)this + param_1 * 0x118 + 0x268)) {
    case 0:
    case 2:
    case 4:
    case 6:
    case 0x11:
      bVar2 = true;
      break;
    case 10:
      iVar3 = *(int *)((int)this + param_1 * 0x118 + 0x260);
      if ((iVar3 != 0) &&
         (iVar3 = iVar3 - *(char *)((int)this + param_1 * 0x118 + 0x369),
         *(int *)((int)this + param_1 * 0x118 + 0x260) = iVar3, iVar3 < 0)) {
        *(undefined4 *)((int)this + param_1 * 0x118 + 0x260) = 0;
      }
      bVar2 = true;
      break;
    case 0xb:
      iVar3 = *(int *)((int)this + param_1 * 0x118 + 0x260);
      if ((iVar3 < 0x100) &&
         (iVar3 = iVar3 + *(char *)((int)this + param_1 * 0x118 + 0x369),
         *(int *)((int)this + param_1 * 0x118 + 0x260) = iVar3, 0xff < iVar3)) {
        *(undefined4 *)((int)this + param_1 * 0x118 + 0x260) = 0x100;
      }
      bVar2 = true;
      break;
    case 0xc:
      iVar3 = *(int *)((int)this + param_1 * 0x118 + 0x264);
      if (iVar3 < 0x100) {
        *(int *)((int)this + param_1 * 0x118 + 0x264) =
             *(char *)((int)this + param_1 * 0x118 + 0x369) + iVar3;
      }
      bVar2 = true;
      break;
    case 0xd:
      iVar3 = *(int *)((int)this + param_1 * 0x118 + 0x264);
      if (iVar3 != 0) {
        *(int *)((int)this + param_1 * 0x118 + 0x264) =
             *(char *)((int)this + param_1 * 0x118 + 0x369) + iVar3;
      }
      bVar2 = true;
      break;
    case 0xf:
      goto switchD_0041050f_caseD_f;
    }
  }
  iVar3 = *(int *)((int)this + param_1 * 0x118 + 0x264);
  iVar1 = *(int *)((int)this + param_1 * 0x118 + 0x260);
  uVar4 = (int)*(char *)((int)this + param_1 * 0x118 + 0x36b) |
          (uint)*(byte *)((int)this + param_1 * 0x118 + 0x36a);
  *(uint *)((int)this + 0x254) = uVar4;
  if ((bVar2) && ((*(byte *)((int)this + 0x238) & 2) != 0)) {
    *(uint *)((int)this + 0x254) = uVar4 + 1;
  }
  FUN_00424460(*(int *)((int)this + 0x254),0x20,0x100,0x100,
               *(int *)((int)this + 0x22c) + iVar3 * 0x100 + iVar1,DAT_00436440);
switchD_0041050f_caseD_f:
  return;
}



/* 00410680  FUN_00410680  656 bytes, 1 callers */

void __fastcall FUN_00410680(void *param_1)

{
  LPSTR _Dest;
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  byte *pbVar5;
  
  pcVar4 = wsprintfA_exref;
  if (*(int *)((int)param_1 + 0x238) == 0) {
    FUN_0040ffe0((int)param_1);
    FUN_0040a870(0x16,0x14,6,7,s_Bravo__you_win__004336dc,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    FUN_0040a870(0x16,0x23,6,7,s_Go_to_the_next_stage_004336c4,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    _Dest = (LPSTR)((int)param_1 + 0x1c);
    FUN_0040a870(0x16,0x32,6,7,s__004336b0,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    FUN_0041a650(&DAT_004376c8,DAT_0043450c);
    pcVar4 = wsprintfA_exref;
    wsprintfA(_Dest,s_Map_d__s_004336a4,DAT_0043450c + 1);
    FUN_0040a870(0x16,0x49,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    _sprintf(_Dest,s_Area__3_2f_Per__00433688,(double)DAT_0043641c);
    FUN_0040a870(0x16,0x5f,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    wsprintfA(_Dest,s_Remaining__6d_days_00433670);
    FUN_0040a870(0x16,0x6e,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    wsprintfA(_Dest,s_Bonus__6d_days_00433658);
    FUN_0040a870(0x16,0x7d,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    wsprintfA(_Dest,s_Penalty__6d_days_00433640);
    FUN_0040a870(0x16,0x8c,4,5,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
  }
  if (*(int *)((int)param_1 + 0x238) == 0x14) {
    (*pcVar4)((LPCSTR)((int)param_1 + 0x1c),s_Total_bonus__6d_days_00433628);
    FUN_0040a870(0x16,0xaa,2,3,(LPCSTR)((int)param_1 + 0x1c),*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
  }
  if (*(int *)((int)param_1 + 0x238) == 0) {
    *(undefined4 *)((int)param_1 + 0x260) = 0xe0;
    *(undefined4 *)((int)param_1 + 0x264) = 0xd0;
    iVar3 = 1;
    *(byte *)((int)param_1 + 0x36a) = (DAT_004365cd | 0xc) << 3;
    iVar2 = 0x20;
    pbVar5 = (byte *)((int)param_1 + 0x482);
    *(byte *)((int)param_1 + 0x36c) = DAT_004365cd;
    *(undefined1 *)((int)param_1 + 0x369) = 2;
    FUN_00411340(param_1,0,0,1);
    do {
      pbVar5[-0xffffffff0000010a] = 0xe0;
      pbVar5[-0xffffffff00000109] = 0;
      pbVar5[-0xffffffff00000108] = 0;
      pbVar5[-0xffffffff00000107] = 0;
      pbVar5[-0xffffffff00000106] = 0xd0;
      pbVar5[-0xffffffff00000105] = 0;
      pbVar5[-0xffffffff00000104] = 0;
      pbVar5[-0xffffffff00000103] = 0;
      *pbVar5 = DAT_004365cd << 3;
      pbVar5[2] = DAT_004365cd;
      pbVar5[-1] = 2;
      FUN_00411340(param_1,iVar3,0,(short)iVar2);
      iVar1 = FUN_0041abd0(100);
      if (iVar1 < 0x1e) {
        *pbVar5 = *pbVar5 | 0x40;
      }
      else if (iVar1 < 0x3c) {
        *pbVar5 = *pbVar5 | 0x20;
      }
      iVar2 = iVar2 + 0x10;
      pbVar5 = pbVar5 + 0x118;
      iVar3 = iVar3 + 1;
    } while (iVar2 < 0x110);
  }
  return;
}



/* 00410910  FUN_00410910  717 bytes, 1 callers */

void __fastcall FUN_00410910(void *param_1)

{
  LPSTR _Dest;
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_8 [2];
  
  if (*(int *)((int)param_1 + 0x238) == 0) {
    FUN_0040ffe0((int)param_1);
    FUN_0040a870(0x16,0xf,6,7,s_Bravo__you_win__004336dc,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0
                );
    FUN_0040a870(0x16,0x1d,6,7,s_But_day_s_over_00433740,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0
                );
    _Dest = (LPSTR)((int)param_1 + 0x1c);
    FUN_0040a870(0x16,0x2b,6,7,s_Please_try_again___0043372c,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    local_8[0] = 0x100;
    local_8[1] = 0x100;
    FUN_0041a650(&DAT_004376c8,DAT_0043450c);
    wsprintfA(_Dest,s_Map_d__s_004336a4,DAT_0043450c + 1);
    FUN_0040a870(0x16,0x49,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,local_8);
    _sprintf(_Dest,s_Area__3_2f_Per__00433688,(double)DAT_0043641c);
    FUN_0040a870(0x16,0x5f,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,local_8);
    wsprintfA(_Dest,s_Remaining__6d_days_00433670);
    FUN_0040a870(0x16,0x6e,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,local_8);
    FUN_0040a870(0x16,0x7d,2,3,s_Bonus_no_count_00433710,*(HDC *)((int)param_1 + 0x224),0,local_8);
    FUN_0040a870(0x16,0x8c,4,5,s_Penalty_no_count_004336f4,*(HDC *)((int)param_1 + 0x224),0,local_8)
    ;
    if (*(int *)((int)param_1 + 0x238) == 0) {
      *(undefined4 *)((int)param_1 + 0x260) = 0xe0;
      *(undefined4 *)((int)param_1 + 0x264) = 0xd0;
      *(byte *)((int)param_1 + 0x36a) = (DAT_004365cd | 0xc) << 3;
      bVar1 = DAT_004365cd;
      *(undefined1 *)((int)param_1 + 0x369) = 2;
      *(byte *)((int)param_1 + 0x36c) = bVar1;
      FUN_00411340(param_1,0,1,1);
      *(undefined4 *)((int)param_1 + 0x13e0) = 0;
      *(undefined4 *)((int)param_1 + 0x13e4) = 0xd0;
      iVar5 = 0x20;
      *(undefined1 *)((int)param_1 + 0x14ea) = 0xc0;
      *(undefined1 *)((int)param_1 + 0x14ec) = 4;
      *(undefined1 *)((int)param_1 + 0x14e9) = 1;
      pbVar3 = (byte *)((int)param_1 + 0x482);
      FUN_00411340(param_1,0x10,2,0x16);
      local_8[0] = 1;
      do {
        pbVar3[-0xffffffff0000010a] = 0xe0;
        pbVar3[-0xffffffff00000109] = 0;
        pbVar3[-0xffffffff00000108] = 0;
        pbVar3[-0xffffffff00000107] = 0;
        pbVar3[-0xffffffff00000106] = 0xd0;
        pbVar3[-0xffffffff00000105] = 0;
        pbVar3[-0xffffffff00000104] = 0;
        pbVar3[-0xffffffff00000103] = 0;
        *pbVar3 = DAT_004365cd << 3;
        pbVar3[-1] = 2;
        FUN_00411340(param_1,local_8[0],0xc,(short)iVar5);
        iVar2 = FUN_0041abd0(100);
        if (iVar2 < 0x1e) {
          *pbVar3 = *pbVar3 | 0x40;
        }
        else if (iVar2 < 0x3c) {
          *pbVar3 = *pbVar3 | 0x20;
        }
        iVar5 = iVar5 + 0x10;
        pbVar3 = pbVar3 + 0x118;
        local_8[0] = local_8[0] + 1;
      } while (iVar5 < 0x110);
    }
  }
  if (0x39 < *(int *)((int)param_1 + 0x238)) {
    *(undefined4 *)((int)param_1 + 0x248) = 0;
    do {
      iVar5 = *(int *)((int)param_1 + 0x248) * 0x100;
      puVar4 = (undefined4 *)(DAT_00435fd4 + 0x38030 + iVar5);
      puVar6 = (undefined4 *)(iVar5 + 0x3868 + (int)param_1);
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      iVar5 = *(int *)((int)param_1 + 0x248) + 1;
      *(int *)((int)param_1 + 0x248) = iVar5;
    } while (iVar5 < 0x20);
  }
  return;
}



/* 00410be0  FUN_00410be0  285 bytes, 1 callers */

void __fastcall FUN_00410be0(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)((int)param_1 + 0x238) == 0) {
    FUN_0040a870(0x16,0x14,6,7,s_You_have_be_defeated_00433760,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    FUN_0040a870(0x16,0x23,6,7,s_Please_try_again___0043372c,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    FUN_0040a870(0x52,0x6e,2,3,s_Game_Over_00433754,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    if (*(int *)((int)param_1 + 0x238) == 0) {
      *(undefined4 *)((int)param_1 + 0x260) = 0xe0;
      *(undefined4 *)((int)param_1 + 0x264) = 0xd0;
      *(byte *)((int)param_1 + 0x36a) = (DAT_004365cd | 0xc) << 3;
      *(byte *)((int)param_1 + 0x36c) = DAT_004365cd;
      *(undefined1 *)((int)param_1 + 0x369) = 2;
      FUN_00411340(param_1,0,3,1);
      iVar1 = 1;
      puVar2 = (undefined4 *)((int)param_1 + 0x378);
      iVar3 = 0x20;
      do {
        *puVar2 = 0xe0;
        iVar4 = iVar3 + 0x10;
        puVar2[1] = 0xd0;
        *(byte *)((int)puVar2 + 0x10a) = DAT_004365cd << 3;
        *(byte *)(puVar2 + 0x43) = DAT_004365cd;
        *(undefined1 *)((int)puVar2 + 0x109) = 2;
        FUN_00411340(param_1,iVar1,iVar1 + 4,(short)iVar3);
        iVar1 = iVar1 + 1;
        puVar2 = puVar2 + 0x46;
        iVar3 = iVar4;
      } while (iVar4 < 0x70);
    }
  }
  return;
}



/* 00410d00  FUN_00410d00  839 bytes, 1 callers */

void __fastcall FUN_00410d00(void *param_1)

{
  LPSTR _Dest;
  int iVar1;
  code *pcVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  HDC pHVar6;
  
  pcVar2 = wsprintfA_exref;
  if (*(int *)((int)param_1 + 0x238) == 0) {
    FUN_0040ffe0((int)param_1);
    FUN_0040a870(0x16,0x14,6,7,s_Bravo__you_win__004336dc,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    FUN_0040a870(0x16,0x23,6,7,s_Go_to_the_next_stage_004336c4,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    _Dest = (LPSTR)((int)param_1 + 0x1c);
    FUN_0040a870(0x16,0x32,6,7,s__004336b0,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    FUN_0041a650(&DAT_004376c8,DAT_0043450c);
    pcVar2 = wsprintfA_exref;
    wsprintfA(_Dest,s_Map_d__s_004336a4,DAT_0043450c + 1);
    FUN_0040a870(0x16,0x49,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    _sprintf(_Dest,s_Area__3_2f_Per__00433688,(double)DAT_0043641c);
    FUN_0040a870(0x16,0x5f,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    wsprintfA(_Dest,s_Remaining__6d_days_00433670);
    FUN_0040a870(0x16,0x6e,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    wsprintfA(_Dest,s_Bonus__6d_days_00433658);
    FUN_0040a870(0x16,0x7d,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    wsprintfA(_Dest,s_Penalty__6d_days_00433640);
    FUN_0040a870(0x16,0x8c,4,5,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
  }
  if (*(int *)((int)param_1 + 0x238) == 0x14) {
    (*pcVar2)((LPCSTR)((int)param_1 + 0x1c),s_Total_bonus__6d_days_00433628);
    FUN_0040a870(0x16,0xaa,2,3,(LPCSTR)((int)param_1 + 0x1c),*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
  }
  if ((*(int *)((int)param_1 + 0x238) < 0x14) || (0x50 < *(int *)((int)param_1 + 0x238)))
  goto LAB_00410f7d;
  if (DAT_00436438 == 0) {
    FUN_0040ffe0((int)param_1);
    (*pcVar2)((int)param_1 + 0x1c);
    pHVar6 = *(HDC *)((int)param_1 + 0x224);
    iVar5 = 7;
    iVar4 = 6;
  }
  else {
    if (DAT_00436438 < 1) {
      FUN_0040ffe0((int)param_1);
      (*pcVar2)((int)param_1 + 0x1c,s_You_lose__d_days__00433778);
      pHVar6 = *(HDC *)((int)param_1 + 0x224);
    }
    else {
      FUN_0040ffe0((int)param_1);
      (*pcVar2)((int)param_1 + 0x1c,s_You_gain__d_days__0043378c);
      pHVar6 = *(HDC *)((int)param_1 + 0x224);
      if ((*(byte *)((int)param_1 + 0x238) & 1) != 0) {
        iVar5 = 7;
        iVar4 = 6;
        goto LAB_00410f71;
      }
    }
    iVar5 = 5;
    iVar4 = 4;
  }
LAB_00410f71:
  FUN_0040a870(0x16,0x1e,iVar4,iVar5,(LPCSTR)((int)param_1 + 0x1c),pHVar6,0,(int *)0x0);
LAB_00410f7d:
  if (*(int *)((int)param_1 + 0x238) == 0) {
    *(undefined4 *)((int)param_1 + 0x260) = 0;
    *(undefined4 *)((int)param_1 + 0x264) = 0xd0;
    iVar4 = 1;
    *(byte *)((int)param_1 + 0x36a) = (DAT_004365cd | 0xc) << 3;
    iVar5 = 0x20;
    pbVar3 = (byte *)((int)param_1 + 0x482);
    *(byte *)((int)param_1 + 0x36c) = DAT_004365cd;
    *(undefined1 *)((int)param_1 + 0x369) = 2;
    FUN_00411340(param_1,0,4,1);
    do {
      pbVar3[-0xffffffff0000010a] = 0;
      pbVar3[-0xffffffff00000109] = 0;
      pbVar3[-0xffffffff00000108] = 0;
      pbVar3[-0xffffffff00000107] = 0;
      pbVar3[-0xffffffff00000106] = 0xd0;
      pbVar3[-0xffffffff00000105] = 0;
      pbVar3[-0xffffffff00000104] = 0;
      pbVar3[-0xffffffff00000103] = 0;
      *pbVar3 = DAT_004365cd << 3;
      pbVar3[2] = DAT_004365cd;
      pbVar3[-1] = 2;
      FUN_00411340(param_1,iVar4,4,(short)iVar5);
      iVar1 = FUN_0041abd0(100);
      if (iVar1 < 0x1e) {
        *pbVar3 = *pbVar3 | 0x40;
      }
      else if (iVar1 < 0x3c) {
        *pbVar3 = *pbVar3 | 0x20;
      }
      iVar5 = iVar5 + 0x10;
      pbVar3 = pbVar3 + 0x118;
      iVar4 = iVar4 + 1;
    } while (iVar5 < 0x110);
  }
  return;
}



/* 00411050  FUN_00411050  741 bytes, 1 callers */

void __fastcall FUN_00411050(void *param_1)

{
  LPSTR _Dest;
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int local_8 [2];
  
  if (*(int *)((int)param_1 + 0x238) == 0) {
    local_8[0] = 0x100;
    local_8[1] = 0x100;
    FUN_0040a870(0x16,0x14,6,7,s_Single_map_mode_00433800,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    _Dest = (LPSTR)((int)param_1 + 0x1c);
    FUN_0040a870(0x16,0x23,6,7,s_Please_try_again___0043372c,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    FUN_0041a650(&DAT_004376c8,DAT_0043450c);
    wsprintfA(_Dest,s_Map_d__s_004336a4,DAT_0043450c + 1);
    FUN_0040a870(0x16,0x49,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),1,local_8);
    wsprintfA(_Dest,s_Area_P_E___6d__6d_004337e8,DAT_00436414);
    FUN_0040a870(0x16,0x5f,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    _sprintf(_Dest,s_Area__3_2f_Per__00433688,(double)DAT_0043641c);
    FUN_0040a870(0x16,0x6e,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    if (DAT_00436410 == 0) {
      wsprintfA(_Dest,s_Penalty_no_count_004336f4);
    }
    else {
      wsprintfA(_Dest,s_Penalty__6d_days_00433640);
    }
    FUN_0040a870(0x16,0x7d,4,5,_Dest,*(HDC *)((int)param_1 + 0x224),0,local_8);
    wsprintfA(_Dest,s_Losses__6d__6d_004337d0,DAT_00436424);
    FUN_0040a870(0x16,0x8f,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,local_8);
    _sprintf(_Dest,s_Battle_effic__3_2f_Per_004337b4,(double)DAT_0043642c);
    FUN_0040a870(0x16,0x9e,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,local_8);
    wsprintfA(_Dest,s_Bonus__6d_days_00433658);
    FUN_0040a870(0x16,0xad,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,local_8);
    if (*(int *)((int)param_1 + 0x238) == 0) {
      *(undefined4 *)((int)param_1 + 0x260) = 0xe0;
      *(undefined4 *)((int)param_1 + 0x264) = 0xd0;
      iVar2 = 1;
      *(byte *)((int)param_1 + 0x36a) = (DAT_004365cd | 0xc) << 3;
      iVar4 = 0x20;
      pbVar3 = (byte *)((int)param_1 + 0x482);
      *(byte *)((int)param_1 + 0x36c) = DAT_004365cd;
      *(undefined1 *)((int)param_1 + 0x369) = 2;
      FUN_00411340(param_1,0,0xd,1);
      do {
        pbVar3[-0xffffffff0000010a] = 0xe0;
        pbVar3[-0xffffffff00000109] = 0;
        pbVar3[-0xffffffff00000108] = 0;
        pbVar3[-0xffffffff00000107] = 0;
        pbVar3[-0xffffffff00000106] = 0xd0;
        pbVar3[-0xffffffff00000105] = 0;
        pbVar3[-0xffffffff00000104] = 0;
        pbVar3[-0xffffffff00000103] = 0;
        *pbVar3 = DAT_004365cd << 3;
        pbVar3[2] = DAT_004365cd;
        iVar1 = FUN_0041abd0(3);
        pbVar3[-1] = (char)iVar1 + 1;
        FUN_00411340(param_1,iVar2,0xd,(short)iVar4);
        iVar1 = FUN_0041abd0(100);
        if (iVar1 < 0x1e) {
          *pbVar3 = *pbVar3 | 0x40;
        }
        else if (iVar1 < 0x3c) {
          *pbVar3 = *pbVar3 | 0x20;
        }
        iVar4 = iVar4 + 0x10;
        pbVar3 = pbVar3 + 0x118;
        iVar2 = iVar2 + 1;
      } while (iVar4 < 0x110);
    }
  }
  return;
}



/* 00411340  FUN_00411340  1890 bytes, 5 callers */

void __thiscall FUN_00411340(void *this,int param_1,int param_2,undefined2 param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  undefined1 local_32c [20];
  undefined1 local_318 [24];
  undefined1 local_300 [44];
  undefined1 local_2d4 [48];
  undefined1 local_2a4 [48];
  undefined1 local_274 [48];
  undefined1 local_244 [56];
  undefined1 *local_20c [4];
  undefined1 *local_1fc;
  undefined4 *local_1f8;
  undefined4 *local_1f4;
  undefined4 *local_1f0;
  undefined4 *local_1ec;
  undefined4 *local_1e8;
  undefined4 *local_1e4;
  undefined1 *local_1e0;
  undefined1 *local_1dc;
  undefined4 *local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_1d4 = 0xf;
  local_1cc = 10;
  local_1d0 = 1;
  local_1bc = 0x13;
  local_1b8 = 0;
  local_1b4 = 0x13;
  local_1b0 = 1;
  local_1c8 = 5;
  local_1ac = 0x13;
  local_1a4 = 0x13;
  local_1c4 = 0x10;
  local_1c0 = 2;
  local_198 = 0xff;
  local_194 = 0xf;
  local_1a8 = 2;
  local_190 = 1;
  local_188 = 4;
  local_1a0 = 3;
  local_19c = 0x15;
  local_17c = 0x13;
  local_178 = 0;
  local_174 = 0x13;
  local_170 = 1;
  local_18c = 10;
  local_16c = 0x13;
  local_164 = 0x13;
  local_184 = 0x10;
  local_180 = 3;
  local_158 = 0xff;
  local_154 = 0xf;
  local_168 = 2;
  local_160 = 3;
  local_15c = 0x15;
  local_150 = 1;
  local_140 = 4;
  local_13c = 0x13;
  local_138 = 0;
  local_134 = 0x13;
  local_130 = 1;
  local_14c = 10;
  local_12c = 0x13;
  local_124 = 0x13;
  local_148 = 3;
  local_144 = 0x10;
  local_118 = 0xff;
  local_114 = 0xf;
  local_128 = 2;
  local_120 = 3;
  local_11c = 0x15;
  local_10c = 10;
  local_108 = 2;
  local_104 = 0x10;
  local_110 = 1;
  local_100 = 5;
  local_fc = 0x13;
  local_f8 = 0;
  local_f4 = 0x13;
  local_f0 = 1;
  local_ec = 0x13;
  local_e4 = 0x13;
  local_d8 = 0xff;
  local_d4 = 0xf;
  local_e8 = 2;
  local_d0 = 1;
  local_c8 = 1;
  local_e0 = 3;
  local_dc = 0x15;
  local_bc = 0x13;
  local_b8 = 0;
  local_b4 = 0x13;
  local_b0 = 1;
  local_cc = 10;
  local_ac = 0x13;
  local_a4 = 0x13;
  local_c4 = 0x10;
  local_c0 = 6;
  local_98 = 0xff;
  local_94 = 0xf;
  local_a8 = 2;
  local_90 = 1;
  local_88 = 0;
  local_a0 = 3;
  local_9c = 0x15;
  local_7c = 0x13;
  local_78 = 0;
  local_74 = 0x13;
  local_70 = 1;
  local_8c = 10;
  local_6c = 0x13;
  local_64 = 0x13;
  local_84 = 0x10;
  local_80 = 7;
  local_58 = 0xff;
  local_68 = 2;
  local_60 = 3;
  local_5c = 0x15;
  local_54 = 0xf;
  local_50 = 1;
  local_4c = 10;
  local_40 = 4;
  local_38 = 0;
  local_48 = 5;
  local_44 = 6;
  local_30 = 4;
  local_28 = 0;
  local_3c = 2;
  local_34 = 6;
  local_20 = 4;
  local_18 = 0;
  local_2c = 2;
  local_24 = 6;
  local_1c = 2;
  local_10 = 4;
  local_4 = 0xff;
  local_20c[0] = local_318;
  local_20c[1] = local_2d4;
  local_20c[2] = local_300;
  local_20c[3] = local_244;
  local_1fc = local_2a4;
  local_1f8 = &local_1d4;
  local_1f4 = &local_194;
  local_1f0 = &local_154;
  local_1ec = &local_114;
  local_1e8 = &local_d4;
  local_1e4 = &local_94;
  local_1e0 = local_32c;
  local_1dc = local_274;
  local_1d8 = &local_54;
  local_14 = 6;
  local_c = 0xb;
  local_8 = 5;
  puVar2 = (undefined4 *)local_20c[param_2];
  puVar4 = (undefined2 *)((int)this + param_1 * 0x118 + 0x26a);
  iVar3 = 0;
  puVar5 = puVar2;
  do {
    *puVar4 = (short)*puVar5;
    puVar5 = puVar5 + 1;
    puVar4 = puVar4 + 1;
    piVar1 = puVar2 + iVar3;
    iVar3 = iVar3 + 1;
  } while (*piVar1 != 0xff);
  *(undefined2 *)((int)this + param_1 * 0x118 + 0x26c) = param_3;
  *(undefined4 *)((int)this + param_1 * 0x118 + 0x25c) = 1;
  *(undefined1 *)((int)this + param_1 * 0x118 + 600) = 1;
  return;
}



/* 00411ab0  FUN_00411ab0  114 bytes, 1 callers */

undefined4 * __thiscall FUN_00411ab0(void *this,WPARAM param_1,uint param_2)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00411b22;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  *(undefined ***)this = &PTR_FUN_00430410;
  *(undefined4 *)((int)this + 0x23c) = 0;
  *unaff_FS_OFFSET = local_10;
  *(uint *)((int)this + 0x234) = param_2 >> 0x10;
  *(uint *)((int)this + 0x238) = param_2 & 0xffff;
  return this;
}



/* 00411b40  FUN_00411b40  30 bytes, 0 callers */

undefined4 * __thiscall FUN_00411b40(void *this,byte param_1)

{
  FUN_00411b60(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 00411b60  FUN_00411b60  61 bytes, 1 callers */

void __fastcall FUN_00411b60(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00411b9d;
  *param_1 = &PTR_FUN_00430410;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_00411ba7();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 00411ba7  FUN_00411ba7  8 bytes, 1 callers */

void FUN_00411ba7(void)

{
  int unaff_EBP;
  
  FUN_0040e720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 00411d70  FUN_00411d70  309 bytes, 0 callers */

void __fastcall FUN_00411d70(int param_1)

{
  int iVar1;
  int local_8 [2];
  
  if (*(int *)(param_1 + 0x23c) == 0) {
    FUN_004243c0((uint)*(byte *)(DAT_00434534 + *(int *)(param_1 + 0x234) * 0x38) << 3 | 0x66,0x20,
                 0x100,0x40,(undefined4 *)(*(int *)(param_1 + 0x22c) + 0x1010),DAT_00436440);
    FUN_0040a1c0(DAT_00434514 * 100 + 8);
  }
  iVar1 = *(int *)(param_1 + 0x23c);
  if ((0 < iVar1) && (iVar1 < 5)) {
    FUN_004243c0((iVar1 + (uint)*(byte *)(DAT_00434534 + *(int *)(param_1 + 0x234) * 0x38) * 8) - 1
                 | 0xa4,0x20,0x100,0x40,(undefined4 *)(*(int *)(param_1 + 0x22c) + 0x1010),
                 DAT_00436440);
  }
  local_8[0] = 0x100;
  local_8[1] = 0x40;
  if (*(int *)(param_1 + 0x23c) == 6) {
    wsprintfA((LPSTR)(param_1 + 0x1c),s__s_has_Fallen_00433814,
              &DAT_00435b31 +
              (uint)*(byte *)(DAT_00434534 + *(int *)(param_1 + 0x234) * 0x38) * 0x11);
    FUN_0040a870(0x30,0x18,0,1,(LPSTR)(param_1 + 0x1c),*(HDC *)(param_1 + 0x224),1,local_8);
  }
  return;
}



/* 00411eb0  FUN_00411eb0  304 bytes, 0 callers */

void __fastcall FUN_00411eb0(int param_1)

{
  int local_8 [2];
  
  if (*(int *)(param_1 + 0x23c) == 0) {
    FUN_00424460((uint)*(byte *)(DAT_00434534 + *(int *)(param_1 + 0x234) * 0x38) << 3 | 100,0x20,
                 0x100,0x40,*(int *)(param_1 + 0x22c) + 0x1010,DAT_00436440);
    FUN_00424460((uint)(*(byte *)(DAT_00434534 + 0x1e + *(int *)(param_1 + 0x234) * 0x38) | 0xc) <<
                 3,0x20,0x100,0x40,*(int *)(param_1 + 0x22c) + 0x10d0,DAT_00436440);
    *(undefined1 *)
     (DAT_00434534 + 0x1e +
     (uint)*(byte *)(DAT_00434534 + 0x1e + *(int *)(param_1 + 0x234) * 0x38) * 0x38) = 0x80;
    *(undefined1 *)(DAT_00434534 + 0x1e + *(int *)(param_1 + 0x234) * 0x38) = 0x80;
    local_8[0] = 0x100;
    local_8[1] = 0x40;
    wsprintfA((LPSTR)(param_1 + 0x1c),s_Break_alliance_00433824);
    FUN_0040a870(0x40,0x18,0,1,(LPSTR)(param_1 + 0x1c),*(HDC *)(param_1 + 0x224),1,local_8);
    FUN_0040a1c0(0x15f97);
  }
  return;
}



/* 00411fe0  FUN_00411fe0  87 bytes, 1 callers */

undefined4 * __thiscall FUN_00411fe0(void *this,WPARAM param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00412037;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  *(undefined ***)this = &PTR_LAB_00430450;
  *unaff_FS_OFFSET = local_10;
  return this;
}



/* 004120a9  FUN_004120a9  8 bytes, 0 callers */

void FUN_004120a9(void)

{
  int unaff_EBP;
  
  FUN_0040e720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 00412721  FUN_00412721  11 bytes, 0 callers */

void FUN_00412721(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x4fc));
  return;
}



/* 00412780  FUN_00412780  186 bytes, 0 callers */

void __fastcall FUN_00412780(void *param_1)

{
  LPSTR _Dest;
  int iVar1;
  char *pcVar2;
  WPARAM wParam;
  int iVar3;
  
  SendDlgItemMessageA(*(HWND *)((int)param_1 + 4),0x3ea,0x184,0,0);
  if (-1 < DAT_00436a00) {
    _Dest = (LPSTR)((int)param_1 + 0x1c);
    iVar3 = 0;
    do {
      iVar1 = iVar3 + 1;
      pcVar2 = FUN_0041a620(&DAT_004376c8,iVar3);
      FUN_00409490(_Dest,&DAT_00432120,pcVar2);
      pcVar2 = FUN_0041a650(&DAT_004376c8,iVar3);
      _sprintf(_Dest,s_Map_3d____s_00433980,iVar1,pcVar2);
      SendDlgItemMessageA(*(HWND *)((int)param_1 + 4),0x3ea,0x180,0,(LPARAM)_Dest);
      iVar3 = iVar1;
    } while (iVar1 <= DAT_00436a00);
  }
  wParam = 0;
  if (DAT_00434510 != 0xffffffff) {
    wParam = DAT_00434510;
  }
  SendDlgItemMessageA(*(HWND *)((int)param_1 + 4),0x3ea,0x186,wParam,0);
  FUN_004128f0(param_1);
  return;
}



/* 004128f0  FUN_004128f0  772 bytes, 1 callers */

void __fastcall FUN_004128f0(void *param_1)

{
  LPSTR _Dest;
  int iVar1;
  HWND hWnd;
  char *lpString;
  
  iVar1 = FUN_0040ec30(param_1,0x3ea);
  if (iVar1 != -1) {
    hWnd = GetDlgItem(*(HWND *)((int)param_1 + 4),0x40f);
    lpString = FUN_0041a650(&DAT_004376c8,iVar1);
    _Dest = (LPSTR)((int)param_1 + 0x1c);
    SetWindowTextA(hWnd,lpString);
    wsprintfA(_Dest,&DAT_00432100);
    FUN_0040ed20(param_1,0x45d,_Dest);
    if (DAT_004376cc - DAT_00436a00 == 1) {
      wsprintfA(_Dest,s_Overall_004339d4);
    }
    else {
      wsprintfA(_Dest,s__d_Map_s__004339c8);
    }
    FUN_0040ed20(param_1,0x41b,_Dest);
    if ((DAT_004376cc - DAT_00436a00 != 1) && (DAT_00436a00 == iVar1)) {
      FUN_0040ed20(param_1,0x45e,&DAT_004339c0);
      FUN_0040ed20(param_1,0x45b,&DAT_004339c0);
      FUN_0040ed20(param_1,0x45c,&DAT_004339bc);
      FUN_0040ed20(param_1,0x49c,&DAT_004339bc);
      FUN_0040ed20(param_1,0x49d,&DAT_004339bc);
      FUN_0040ed20(param_1,0x49e,&DAT_004339bc);
      FUN_0040ed20(param_1,0x4a2,&DAT_004339bc);
      FUN_0040ed20(param_1,0x4a0,&DAT_004339bc);
      FUN_0040ed20(param_1,0x49f,&DAT_004339bc);
      FUN_0040ed20(param_1,0x4a1,&DAT_004339bc);
      FUN_0040ed20(param_1,0x4a3,&DAT_004339bc);
      return;
    }
    wsprintfA(_Dest,s__d_days_004339b4);
    FUN_0040ed20(param_1,0x45b,_Dest);
    wsprintfA(_Dest,s__d_days_004339b4);
    FUN_0040ed20(param_1,0x45e,_Dest);
    wsprintfA(_Dest,s__d_days_004339b4);
    FUN_0040ed20(param_1,0x45c,_Dest);
    wsprintfA(_Dest,&DAT_00432608);
    FUN_0040ed20(param_1,0x49c,_Dest);
    wsprintfA(_Dest,&DAT_00432608);
    FUN_0040ed20(param_1,0x49d,_Dest);
    _sprintf(_Dest,s__3_2f_004339ac,(double)(float)(&DAT_00436a10)[iVar1 * 0xe]);
    FUN_0040ed20(param_1,0x49e,_Dest);
    wsprintfA(_Dest,s____d_days_004339a0);
    FUN_0040ed20(param_1,0x4a2,_Dest);
    wsprintfA(_Dest,s__d_p__00433998);
    FUN_0040ed20(param_1,0x4a0,_Dest);
    wsprintfA(_Dest,s__d_p__00433998);
    FUN_0040ed20(param_1,0x49f,_Dest);
    _sprintf(_Dest,s__3_2f_004339ac,(double)*(float *)(&DAT_00436a14 + iVar1 * 0x38));
    FUN_0040ed20(param_1,0x4a1,_Dest);
    wsprintfA(_Dest,s____d_days_0043398c);
    FUN_0040ed20(param_1,0x4a3,_Dest);
  }
  return;
}



/* 00412cea  FUN_00412cea  11 bytes, 0 callers */

void FUN_00412cea(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x22c));
  return;
}



/* 00412d10  FUN_00412d10  180 bytes, 0 callers */

void __fastcall FUN_00412d10(int param_1)

{
  LPSTR lParam;
  int iVar1;
  char *pcVar2;
  WPARAM wParam;
  int iVar3;
  
  SendDlgItemMessageA(*(HWND *)(param_1 + 4),0x3ea,0x184,0,0);
  if (0 < DAT_004376cc) {
    lParam = (LPSTR)(param_1 + 0x1c);
    iVar3 = 0;
    do {
      iVar1 = iVar3 + 1;
      pcVar2 = FUN_0041a620(&DAT_004376c8,iVar3);
      FUN_00409490(lParam,&DAT_00432120,pcVar2);
      pcVar2 = FUN_0041a650(&DAT_004376c8,iVar3);
      wsprintfA(lParam,s_Map__3d___s_004339f0,iVar1,pcVar2);
      SendDlgItemMessageA(*(HWND *)(param_1 + 4),0x3ea,0x180,0,(LPARAM)lParam);
      iVar3 = iVar1;
    } while (iVar1 < DAT_004376cc);
  }
  wParam = 0;
  if (DAT_0043450c != 0xffffffff) {
    wParam = DAT_0043450c;
  }
  SendDlgItemMessageA(*(HWND *)(param_1 + 4),0x3ea,0x186,wParam,0);
  return;
}



/* 00412ebf  FUN_00412ebf  11 bytes, 0 callers */

void FUN_00412ebf(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x22c));
  return;
}



/* 00412ed0  FUN_00412ed0  104 bytes, 1 callers */

undefined4 * __thiscall FUN_00412ed0(void *this,WPARAM param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00412f38;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  *(undefined ***)this = &PTR_FUN_00430490;
  *(undefined4 *)((int)this + 0x240) = 0;
  *(undefined4 *)((int)this + 0x244) = 0xffffffff;
  *(undefined4 *)((int)this + 0x248) = 0xffffffff;
  *unaff_FS_OFFSET = local_10;
  return this;
}



/* 00412f50  FUN_00412f50  30 bytes, 0 callers */

undefined4 * __thiscall FUN_00412f50(void *this,byte param_1)

{
  FUN_00412f70(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 00412f70  FUN_00412f70  100 bytes, 1 callers */

void __fastcall FUN_00412f70(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00412fd4;
  *param_1 = &PTR_FUN_00430490;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0;
  if ((param_1[0x91] != -1) && (DAT_004344e8 != (void *)0x0)) {
    FUN_00424620(DAT_004344e8,(ushort *)(param_1 + 0x91));
  }
  local_8 = 0xffffffff;
  FUN_00412fde();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 00412fde  FUN_00412fde  8 bytes, 1 callers */

void FUN_00412fde(void)

{
  int unaff_EBP;
  
  FUN_0040e720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 00412ff0  FUN_00412ff0  354 bytes, 0 callers */

undefined4 __fastcall FUN_00412ff0(void *param_1)

{
  byte bVar1;
  int iVar2;
  void *this;
  int *this_00;
  UINT_PTR UVar3;
  byte *pbVar4;
  char *pcVar5;
  
  FUN_0040a1c0(0x15f96);
  if (DAT_00434544 == 0) {
    pcVar5 = s_Passage_blocked_by_friendly_unit_00433a1c;
  }
  else {
    if (DAT_00434544 != 1) goto LAB_0041302a;
    pcVar5 = s_Powerful_enemies_in_path__00433a00;
  }
  wsprintfA((LPSTR)((int)param_1 + 0x1c),pcVar5);
LAB_0041302a:
  iVar2 = DAT_0043454c;
  *(int *)((int)param_1 + 0x23c) = DAT_0043454c;
  bVar1 = *(byte *)(DAT_00434538 + 0x220 + iVar2 * 0x224);
  iVar2 = 0;
  *(undefined4 *)((int)param_1 + 0x234) = 0;
  *(uint *)((int)param_1 + 0x238) = (uint)bVar1;
  do {
    if ((*(byte *)(DAT_00434538 + 0x21c + iVar2) & 1) != 0) {
      *(int *)((int)param_1 + 0x234) = *(int *)((int)param_1 + 0x234) + 1;
    }
    iVar2 = iVar2 + 0x224;
  } while (iVar2 < 0x8900);
  if (1 < *(int *)((int)param_1 + 0x234)) {
    FUN_0040ed80(param_1,3,1);
    FUN_0040ed80(param_1,4,1);
  }
  FUN_0040ed20(param_1,0x42b,(LPCSTR)((int)param_1 + 0x1c));
  this = (void *)FUN_0040a0c0(60000);
  if (this != (void *)0x0) {
    pbVar4 = (byte *)(*(int *)((int)param_1 + 0x23c) * 0x224 + DAT_00434538);
    FUN_00423f90(this,(uint)*pbVar4,(uint)pbVar4[1],(undefined4 *)((int)param_1 + 0x244),1);
  }
  this_00 = (int *)FUN_0040a0c0(0xea61);
  if (this_00 != (int *)0x0) {
    FUN_004271b0(this_00,(byte *)(*(int *)((int)param_1 + 0x23c) * 0x224 + DAT_00434538));
    (**(code **)(*this_00 + 100))();
  }
  UVar3 = SetTimer(*(HWND *)((int)param_1 + 4),0x16,100,(TIMERPROC)0x0);
  *(UINT_PTR *)((int)param_1 + 0x230) = UVar3;
  return 1;
}



/* 00413220  FUN_00413220  135 bytes, 0 callers */

void __fastcall FUN_00413220(int param_1)

{
  if ((*(byte *)(param_1 + 0x240) & 1) == 0) {
    *(undefined1 *)(DAT_00434538 + 0x220 + *(int *)(param_1 + 0x23c) * 0x224) = 1;
  }
  else {
    *(undefined1 *)(DAT_00434538 + 0x220 + *(int *)(param_1 + 0x23c) * 0x224) =
         *(undefined1 *)(param_1 + 0x238);
  }
  if (DAT_004344e8 != (int *)0x0) {
    (**(code **)(*DAT_004344e8 + 100))();
  }
  if (DAT_004344f0 != (int *)0x0) {
    (**(code **)(*DAT_004344f0 + 100))();
  }
  *(int *)(param_1 + 0x240) = *(int *)(param_1 + 0x240) + 1;
  return;
}



/* 004132b0  FUN_004132b0  87 bytes, 1 callers */

undefined4 * __thiscall FUN_004132b0(void *this,WPARAM param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00413307;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  *(undefined ***)this = &PTR_LAB_004304d0;
  *unaff_FS_OFFSET = local_10;
  return this;
}



/* 00413379  FUN_00413379  8 bytes, 0 callers */

void FUN_00413379(void)

{
  int unaff_EBP;
  
  FUN_0040e720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 00413390  FUN_00413390  231 bytes, 0 callers */

undefined4 __fastcall FUN_00413390(void *param_1)

{
  uint uVar1;
  HWND hWnd;
  int iVar2;
  int *piVar3;
  int local_14;
  int local_10;
  int local_c [3];
  
  local_c[0] = 0x447;
  local_c[1] = 0x448;
  uVar1 = 0;
  local_14 = 0;
  local_c[2] = 0x449;
  do {
    if (DAT_004365cd == uVar1) {
      local_14 = *(int *)(DAT_00434534 + 0x2c + uVar1 * 0x38);
      break;
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 4);
  iVar2 = 0;
  uVar1 = 0;
  local_10 = 1;
  piVar3 = local_c;
  do {
    if (DAT_004365cd == uVar1) {
      if (*(char *)(DAT_00434534 + 0x1e + iVar2) != -0x80) {
        FUN_0040ed80(param_1,0x432,1);
      }
      *(char *)((int)param_1 + 0x234) = (char)uVar1;
    }
    else {
      if (local_14 < *(int *)(DAT_00434534 + 0x2c + iVar2)) {
        hWnd = GetDlgItem(*(HWND *)((int)param_1 + 4),*piVar3);
        EnableWindow(hWnd,0);
      }
      piVar3 = piVar3 + 1;
      *(undefined1 *)(local_10 + 0x234 + (int)param_1) = *(undefined1 *)(DAT_00434534 + iVar2);
      local_10 = local_10 + 1;
    }
    iVar2 = iVar2 + 0x38;
    uVar1 = uVar1 + 1;
  } while (iVar2 < 0xe0);
  return 1;
}



/* 00413ad0  FUN_00413ad0  122 bytes, 1 callers */

undefined4 * __thiscall FUN_00413ad0(void *this,WPARAM param_1)

{
  uint uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00413b4a;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  *(undefined ***)this = &PTR_LAB_00430510;
  *(uint *)((int)this + 0x234) = DAT_004365e4 / 3;
  uVar1 = DAT_004365e4 % 3;
  *unaff_FS_OFFSET = local_10;
  *(uint *)((int)this + 0x238) = uVar1;
  return this;
}



/* 00413bb9  FUN_00413bb9  8 bytes, 0 callers */

void FUN_00413bb9(void)

{
  int unaff_EBP;
  
  FUN_0040e720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 00413cf0  FUN_00413cf0  247 bytes, 0 callers */

void __fastcall FUN_00413cf0(void *param_1)

{
  int iVar1;
  HWND hWnd;
  
  iVar1 = FUN_0040edd0(param_1,0x465);
  if (iVar1 != -1) {
    *(int *)((int)param_1 + 0x234) = iVar1;
  }
  iVar1 = FUN_0040edd0(param_1,0x466);
  if (iVar1 != -1) {
    *(int *)((int)param_1 + 0x238) = iVar1;
  }
  hWnd = GetDlgItem(*(HWND *)((int)param_1 + 4),0x466);
  SendMessageA(hWnd,0x14b,0,0);
  if ((*(int *)((int)param_1 + 0x234) != 0) && (*(int *)((int)param_1 + 0x234) != 6)) {
    FUN_0040ed80(param_1,0x466,1);
    FUN_0040edb0(param_1,0x466,0x435b97);
    FUN_0040edb0(param_1,0x466,0x435b86);
    wsprintfA((LPSTR)((int)param_1 + 0x1c),s__s_continue_00432470,
              &DAT_00435b86 + (char)(&DAT_00434444)[*(int *)((int)param_1 + 0x234)] * 0x11);
    FUN_0040edb0(param_1,0x466,(LPARAM)((int)param_1 + 0x1c));
    FUN_0040edf0(param_1,0x466,*(WPARAM *)((int)param_1 + 0x238));
    return;
  }
  FUN_0040ed80(param_1,0x466,0);
  return;
}



/* 00413e50  FUN_00413e50  146 bytes, 1 callers */

undefined4 * __thiscall FUN_00413e50(void *this,WPARAM param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00413ee2;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  *(undefined ***)this = &PTR_FUN_00430550;
  *(undefined1 *)((int)this + 0x9388) = DAT_004365cd;
  *(undefined4 *)((int)this + 0x23c) = 0;
  *(undefined4 *)((int)this + 0x238) = 0;
  *(undefined4 *)((int)this + 0x254) = 0;
  *(undefined4 *)((int)this + 600) = 0;
  *(undefined4 *)((int)this + 0x25c) = 0;
  *(undefined1 *)((int)this + 0x9394) = DAT_004376a1;
  *unaff_FS_OFFSET = local_10;
  DAT_004376a1 = 1;
  return this;
}



/* 00413f00  FUN_00413f00  30 bytes, 0 callers */

undefined4 * __thiscall FUN_00413f00(void *this,byte param_1)

{
  FUN_00413f20(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 00413f20  FUN_00413f20  79 bytes, 1 callers */

void __fastcall FUN_00413f20(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00413f6f;
  *param_1 = &PTR_FUN_00430550;
  *unaff_FS_OFFSET = &local_10;
  DAT_004376a1 = *(undefined1 *)(param_1 + 0x24e5);
  local_8 = 0xffffffff;
  FUN_00413f79();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 00413f79  FUN_00413f79  8 bytes, 1 callers */

void FUN_00413f79(void)

{
  int unaff_EBP;
  
  FUN_0040e720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 004145c0  FUN_004145c0  179 bytes, 0 callers */

void __fastcall FUN_004145c0(int param_1)

{
  HWND hWnd;
  HDC hdc;
  HGDIOBJ h;
  int mode;
  COLORREF color;
  tagRECT local_10;
  
  hWnd = GetDlgItem(*(HWND *)(param_1 + 4),0x463);
  if (hWnd != (HWND)0x0) {
    hdc = GetDC(hWnd);
    if (hdc != (HDC)0x0) {
      GetClientRect(hWnd,&local_10);
      h = SelectObject(hdc,*(HGDIOBJ *)(DAT_004344e4 + 0x3a4));
      mode = SetBkMode(hdc,1);
      color = SetTextColor(hdc,0x10000);
      SetWindowTextA(hWnd,(&PTR_s_Lord_Monarch_is_a_game_where_you_004334d0)
                          [*(int *)(param_1 + 0x23c)]);
      SetTextColor(hdc,color);
      SetBkMode(hdc,mode);
      SelectObject(hdc,h);
      ReleaseDC(hWnd,hdc);
    }
  }
  return;
}



/* 004146f0  FUN_004146f0  338 bytes, 13 callers */

void __fastcall FUN_004146f0(void *param_1)

{
  int iVar1;
  HWND pHVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  
  *(undefined4 *)((int)param_1 + 0x238) = 0;
  *(undefined4 *)((int)param_1 + 0x254) = 0;
  iVar1 = 0x19;
  puVar3 = (undefined1 *)((int)param_1 + 0x9130);
  do {
    *puVar3 = 0x14;
    iVar1 = iVar1 + -1;
    puVar3[0x10] = 0;
    puVar3 = puVar3 + 0x18;
  } while (iVar1 != 0);
  iVar1 = 0x14;
  puVar4 = (undefined4 *)((int)param_1 + 0x6678);
  do {
    *puVar4 = 0x1e;
    iVar1 = iVar1 + -1;
    puVar4[-4] = 1000;
    *(undefined1 *)(puVar4 + -3) = 6;
    *(undefined1 *)(puVar4 + 0x82) = 0xff;
    *(undefined1 *)(puVar4 + -2) = 0;
    puVar4 = puVar4 + 0x89;
  } while (iVar1 != 0);
  SendDlgItemMessageA(*(HWND *)((int)param_1 + 4),0x462,0x14e,*(WPARAM *)((int)param_1 + 0x23c),0);
  puVar4 = *(undefined4 **)((int)param_1 + 0x22c);
  for (iVar1 = 0x1900; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = 0x70707070;
    puVar4 = puVar4 + 1;
  }
  if (*(int *)((int)param_1 + 0x23c) == 0) {
    FUN_0040ed80(param_1,0x461,1);
    FUN_0040ed80(param_1,0x460,0);
    pHVar2 = GetDlgItem(*(HWND *)((int)param_1 + 4),0x461);
    if (pHVar2 != (HWND)0x0) {
      SetFocus(pHVar2);
    }
  }
  else if (*(int *)((int)param_1 + 0x23c) == 0x11) {
    FUN_0040ed80(param_1,0x461,0);
    FUN_0040ed80(param_1,0x460,1);
    pHVar2 = GetDlgItem(*(HWND *)((int)param_1 + 4),0x460);
    if (pHVar2 != (HWND)0x0) {
      SetFocus(pHVar2);
    }
  }
  else {
    FUN_0040ed80(param_1,0x461,1);
    FUN_0040ed80(param_1,0x460,1);
  }
  InvalidateRect(*(HWND *)((int)param_1 + 4),(RECT *)0x0,0);
  UpdateWindow(*(HWND *)((int)param_1 + 4));
  return;
}



/* 00414850  FUN_00414850  330 bytes, 0 callers */

uint __thiscall FUN_00414850(void *this,int param_1)

{
  byte bVar1;
  uint uVar2;
  
  if (*(char *)((int)this + param_1 * 0x224 + 0x6664) == '\x04') {
    if ((*(byte *)((int)this + param_1 * 0x224 + 0x6670) & 2) != 0) {
      return (uint)(*(byte *)((int)this + param_1 * 0x224 + 0x666e) | 200);
    }
    return (uint)(*(byte *)((int)this + param_1 * 0x224 + 0x666c) & 6) |
           (*(uint *)((int)this + 0x238) & 2) >> 1 | 0xc0;
  }
  bVar1 = *(byte *)((int)this + param_1 * 0x224 + 0x6670);
  if ((bVar1 & 2) != 0) {
    return (-(uint)((*(byte *)((int)this + param_1 * 0x224 + 0x666d) & 0x20) == 0) & 0xfffffffc) +
           0xa4 | (uint)*(byte *)((int)this + param_1 * 0x224 + 0x666e) |
                  (uint)*(byte *)((int)this + param_1 * 0x224 + 0x6664) << 3;
  }
  if ((bVar1 & 1) != 0) {
    if ((*(byte *)((int)this + param_1 * 0x224 + 0x666d) & 0x20) == 0) {
      uVar2 = *(uint *)((int)this + param_1 * 0x224 + 0x6668);
      if (uVar2 < 1000) {
        uVar2 = 0x80;
      }
      else {
        uVar2 = (-(uint)(uVar2 < 10000) & 0xfffffffe) + 0x84;
      }
    }
    else {
      uVar2 = 0x86;
    }
    return uVar2 | (*(uint *)((int)this + 0x238) & 2) >> 1 |
                   (uint)*(byte *)((int)this + param_1 * 0x224 + 0x6664) << 3;
  }
  if ((*(byte *)((int)this + param_1 * 0x224 + 0x666d) & 0x20) == 0) {
    uVar2 = *(uint *)((int)this + param_1 * 0x224 + 0x6668);
    if (uVar2 < 1000) {
      uVar2 = 0;
    }
    else {
      uVar2 = (-(uint)(uVar2 < 10000) & 0xffffffe0) + 0x40;
    }
  }
  else {
    uVar2 = 0x60;
  }
  return uVar2 | (uint)(*(byte *)((int)this + param_1 * 0x224 + 0x666c) & 6) |
                 (*(uint *)((int)this + 0x238) & 2) >> 1 |
                 (uint)*(byte *)((int)this + param_1 * 0x224 + 0x6664) << 3;
}



/* 004149a0  FUN_004149a0  200 bytes, 0 callers */

void __fastcall FUN_004149a0(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (*(int *)(param_1 + 0x238) == 0) {
    puVar2 = (undefined1 *)(param_1 + 0x9140);
    iVar1 = 0x19;
    do {
      *puVar2 = 0;
      puVar2 = puVar2 + 0x18;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    *(undefined1 *)(param_1 + 0x91d0) = 0x70;
    *(undefined1 *)(param_1 + 0x9248) = 0x74;
    *(undefined1 *)(param_1 + 0x92c0) = 0x71;
    *(undefined1 *)(param_1 + 0x91e8) = 0x72;
    *(undefined1 *)(param_1 + 0x9260) = 0x14;
    *(undefined1 *)(param_1 + 0x92d8) = 0x73;
    *(undefined1 *)(param_1 + 0x9200) = 0x78;
    *(undefined1 *)(param_1 + 0x9278) = 0x1d;
    *(undefined1 *)(param_1 + 0x92f0) = 0x79;
    *(undefined1 *)(param_1 + 0x6880) = 0xff;
    *(undefined1 *)(param_1 + 0x6670) = 0;
    *(undefined1 *)(param_1 + 0x666c) = 6;
    *(undefined4 *)(param_1 + 0x6668) = 100;
    *(undefined1 *)(param_1 + 0x666d) = 0x20;
    *(undefined1 *)(param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)(param_1 + 0x9388) * 0x38);
    *(undefined1 *)(param_1 + 0x9250) = 0;
    *(undefined4 *)(param_1 + 0x6678) = 0x1e;
    *(undefined1 *)(param_1 + 0x6660) = 2;
    *(undefined1 *)(param_1 + 0x6661) = 2;
  }
  return;
}



/* 00414a70  FUN_00414a70  772 bytes, 0 callers */

void __fastcall FUN_00414a70(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((*(int *)(param_1 + 0x238) == 0) || (*(int *)(param_1 + 0x238) == 0x32)) {
    iVar1 = 0;
    *(undefined4 *)(param_1 + 0x238) = 0;
    *(undefined1 *)(param_1 + 0x9140) = 0x60;
    *(undefined1 *)(param_1 + 0x91b8) = 0x68;
    *(undefined1 *)(param_1 + 0x9230) = 0x68;
    *(undefined1 *)(param_1 + 0x92a8) = 0x68;
    *(undefined1 *)(param_1 + 0x9320) = 0x60;
    *(undefined1 *)(param_1 + 0x9338) = 0x61;
    *(undefined1 *)(param_1 + 0x9350) = 0x61;
    *(undefined1 *)(param_1 + 0x9368) = 0x61;
    *(undefined1 *)(param_1 + 0x9380) = 0x60;
    *(undefined1 *)(param_1 + 0x91a0) = 0x60;
    *(undefined1 *)(param_1 + 0x9308) = 0x62;
    *(undefined1 *)(param_1 + 0x9290) = 0x62;
    *(undefined1 *)(param_1 + 0x9218) = 0x62;
    *(undefined1 *)(param_1 + 0x9188) = 100;
    *(undefined1 *)(param_1 + 0x9170) = 100;
    *(undefined1 *)(param_1 + 0x9158) = 100;
    puVar2 = (undefined1 *)(param_1 + 0x6880);
    do {
      *puVar2 = 0xff;
      puVar2[-0x214] = 6;
      puVar2[-0x213] = 0x20;
      *(undefined4 *)(puVar2 + -0x218) = 1000;
      puVar2[-0x212] = 0;
      puVar2[-0x210] = 0;
      puVar2[-0x21c] = (char)iVar1;
      iVar1 = iVar1 + 1;
      *(undefined4 *)(puVar2 + -0x208) = 0x1e;
      puVar2 = puVar2 + 0x224;
    } while (iVar1 < 4);
    *(undefined1 *)(param_1 + 0x91c0) = 0;
    *(undefined1 *)(param_1 + 0x92b0) = 1;
    *(undefined1 *)(param_1 + 0x91f0) = 2;
    *(undefined1 *)(param_1 + 0x92e0) = 3;
  }
  iVar1 = *(int *)(param_1 + 0x238);
  if (iVar1 == 10) {
    *(undefined1 *)(param_1 + 0x6880) = 0xff;
    *(undefined1 *)(param_1 + 0x6660) = 1;
    *(undefined1 *)(param_1 + 0x6661) = 1;
    *(undefined1 *)(param_1 + 0x667c) = 4;
    *(undefined1 *)(param_1 + 0x667d) = 5;
    *(undefined4 *)(param_1 + 0x6678) = 0;
    *(undefined1 *)(param_1 + 0x667e) = 5;
    *(undefined1 *)(param_1 + 0x667f) = 5;
    *(undefined1 *)(param_1 + 0x6680) = 5;
    *(undefined1 *)(param_1 + 0x6681) = 4;
    *(undefined1 *)(param_1 + 0x6683) = 5;
    *(undefined1 *)(param_1 + 0x6684) = 5;
    *(undefined1 *)(param_1 + 0x6682) = 6;
    *(undefined1 *)(param_1 + 0x6685) = 5;
    *(undefined1 *)(param_1 + 0x6686) = 5;
    *(undefined1 *)(param_1 + 0x6687) = 6;
    *(undefined1 *)(param_1 + 0x6688) = 0;
    *(undefined1 *)(param_1 + 0x6689) = 5;
    *(undefined1 *)(param_1 + 0x668a) = 5;
    *(undefined1 *)(param_1 + 0x668b) = 5;
    *(undefined1 *)(param_1 + 0x668c) = 5;
    *(undefined1 *)(param_1 + 0x668d) = 0;
    *(undefined4 *)(param_1 + 0x6674) = 0x14;
    *(undefined1 *)(param_1 + 0x668e) = 2;
    *(undefined1 *)(param_1 + 0x668f) = 2;
  }
  if (iVar1 == 0xb) {
    *(undefined1 *)(param_1 + 0x6894) = 2;
  }
  if (iVar1 == 0x12) {
    *(undefined1 *)(param_1 + 0x6cdc) = 2;
  }
  if (iVar1 == 0x1a) {
    *(undefined1 *)(param_1 + 0x6ab8) = 2;
  }
  if (iVar1 == 0x24) {
    *(undefined1 *)(param_1 + 0x666c) = 6;
  }
  if (iVar1 < 0x28) {
    *(undefined4 *)(param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)(param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)(*(int *)(param_1 + 0x244) * 0xa0 + *(int *)(param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar1 = *(int *)(param_1 + 0x244) + 1;
      *(int *)(param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
  }
  iVar1 = *(int *)(param_1 + 0x238);
  if (iVar1 < 10) {
    FUN_0040a870(0x10,8,8,9,s_The_rules_are____00433b08,*(HDC *)(param_1 + 0x224),1,
                 (int *)(param_1 + 0x938c));
    return;
  }
  if (iVar1 < 0x14) {
    FUN_0040a870(0x10,8,8,9,s_easy_and_simple___00433af4,*(HDC *)(param_1 + 0x224),1,
                 (int *)(param_1 + 0x938c));
    return;
  }
  if (iVar1 < 0x1e) {
    FUN_0040a870(0x10,8,8,9,s_defeat_everyone__00433ae0,*(HDC *)(param_1 + 0x224),1,
                 (int *)(param_1 + 0x938c));
    return;
  }
  if (iVar1 < 0x28) {
    FUN_0040a870(0x10,8,8,9,s_That_s_all_to_it__00433acc,*(HDC *)(param_1 + 0x224),1,
                 (int *)(param_1 + 0x938c));
  }
  return;
}



/* 00414d80  FUN_00414d80  806 bytes, 0 callers */

void __fastcall FUN_00414d80(void *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char local_10 [8];
  char local_8 [8];
  
  if (*(int *)((int)param_1 + 0x238) == 0) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x9140) = 8;
    *(undefined4 *)((int)param_1 + 0x250) = 0;
    iVar1 = 0;
    *(undefined1 *)((int)param_1 + 0x9170) = 9;
    *(undefined1 *)((int)param_1 + 0x9188) = 10;
    *(undefined1 *)((int)param_1 + 0x91a0) = 0xb;
    puVar2 = (undefined1 *)((int)param_1 + 0x6880);
    do {
      *puVar2 = 0xff;
      iVar1 = iVar1 + 0x38;
      puVar2[-0x214] = 6;
      puVar2[-0x213] = 0x20;
      puVar2[-0x210] = 0;
      puVar2[-0x21c] = *(undefined1 *)(DAT_00434534 + -0x38 + iVar1);
      *(undefined4 *)(puVar2 + -0x208) = 0x1e;
      puVar2[0x224] = 0xff;
      puVar2[0x10] = 6;
      puVar2[0x11] = 1;
      *(undefined4 *)(puVar2 + 0xc) = 100;
      puVar2[0x14] = 0;
      puVar2[8] = *(undefined1 *)(DAT_00434534 + -0x38 + iVar1);
      *(undefined4 *)(puVar2 + 0x1c) = 0x1e;
      puVar2[0x448] = 0xff;
      puVar2[0x234] = 6;
      puVar2[0x235] = 1;
      *(undefined4 *)(puVar2 + 0x230) = 1000;
      puVar2[0x238] = 0;
      puVar2[0x22c] = *(undefined1 *)(DAT_00434534 + -0x38 + iVar1);
      *(undefined4 *)(puVar2 + 0x240) = 0x1e;
      puVar2[0x66c] = 0xff;
      puVar2[0x458] = 6;
      puVar2[0x459] = 1;
      *(undefined4 *)(puVar2 + 0x454) = 10000;
      puVar2[0x45c] = 0;
      puVar2[0x450] = *(undefined1 *)(DAT_00434534 + -0x38 + iVar1);
      *(undefined4 *)(puVar2 + 0x464) = 0x1e;
      puVar2 = puVar2 + 0x890;
    } while (iVar1 < 0xe0);
    *(undefined1 *)((int)param_1 + 0x91a8) = 0;
    *(undefined1 *)((int)param_1 + 0x9220) = 1;
    *(undefined1 *)((int)param_1 + 0x91d8) = 4;
    *(undefined1 *)((int)param_1 + 0x9298) = 2;
    *(undefined1 *)((int)param_1 + 0x9310) = 3;
    *(undefined1 *)((int)param_1 + 0x9250) = 5;
    *(undefined1 *)((int)param_1 + 0x92c8) = 6;
    *(undefined1 *)((int)param_1 + 0x9340) = 7;
    *(undefined1 *)((int)param_1 + 0x91f0) = 8;
    *(undefined1 *)((int)param_1 + 0x9268) = 9;
    *(undefined1 *)((int)param_1 + 0x92e0) = 10;
    *(undefined1 *)((int)param_1 + 0x9358) = 0xb;
    *(undefined1 *)((int)param_1 + 0x9208) = 0xc;
    *(undefined1 *)((int)param_1 + 0x9280) = 0xd;
    *(undefined1 *)((int)param_1 + 0x88a0) = 4;
    *(undefined1 *)((int)param_1 + 0x88a1) = 1;
    *(undefined1 *)((int)param_1 + 0x92f8) = 0xe;
    *(undefined1 *)((int)param_1 + 0x9370) = 0xf;
    *(undefined1 *)((int)param_1 + 0x9238) = 0x10;
    *(undefined1 *)((int)param_1 + 0x88ad) = 1;
    *(undefined1 *)((int)param_1 + 0x88b0) = 0;
    *(undefined1 *)((int)param_1 + 0x8ac0) = 0xff;
    *(undefined1 *)((int)param_1 + 0x88ac) = 6;
    *(undefined4 *)((int)param_1 + 0x88a8) = 1000;
    *(undefined4 *)((int)param_1 + 35000) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x88a4) = 4;
  }
  if ((*(byte *)((int)param_1 + 0x238) & 4) != 0) {
    local_10[1] = 5;
    local_10[2] = 9;
    local_10[3] = 0xd;
    local_10[4] = 0x11;
    local_8[0] = '\0';
    local_8[1] = 4;
    local_8[3] = 2;
    local_8[4] = 3;
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    local_10[0] = '\x01';
    local_8[2] = 1;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               ((*(int *)((int)param_1 + 0x244) + local_10[*(int *)((int)param_1 + 0x250)] * 8) *
                0xa0 + -0x500 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar1 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
    wsprintfA((LPSTR)((int)param_1 + 0x1c),&DAT_00432100,
              &DAT_00435b31 + local_8[*(int *)((int)param_1 + 0x250)] * 0x11);
    FUN_0040a870(0x20,(int)local_10[*(int *)((int)param_1 + 0x250)] << 3,8,9,
                 (LPSTR)((int)param_1 + 0x1c),*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    if ((((byte)*(undefined4 *)((int)param_1 + 0x238) & 7) == 7) &&
       (iVar1 = *(int *)((int)param_1 + 0x250) + 1, *(int *)((int)param_1 + 0x250) = iVar1,
       4 < iVar1)) {
      *(undefined4 *)((int)param_1 + 0x250) = 0;
    }
  }
  return;
}



/* 004150b0  FUN_004150b0  1269 bytes, 0 callers */

void __fastcall FUN_004150b0(void *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((*(int *)((int)param_1 + 0x238) == 0) || (*(int *)((int)param_1 + 0x238) == 0x3c)) {
    FUN_004146f0(param_1);
    *(undefined4 *)((int)param_1 + 0x254) = 1;
    *(undefined4 *)((int)param_1 + 0x25c) = 1;
    *(undefined4 *)((int)param_1 + 600) = 0;
    *(undefined1 *)((int)param_1 + 0x91a0) = 4;
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    cVar1 = *(char *)((int)param_1 + 0x9388) + '\f';
    *(char *)((int)param_1 + 0x9260) = *(char *)((int)param_1 + 0x9388) + '\b';
    *(char *)((int)param_1 + 0x91e8) = cVar1;
    *(char *)((int)param_1 + 0x9248) = cVar1;
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    *(undefined4 *)((int)param_1 + 0x6668) = 100;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x6664) = *DAT_00434534;
    *(undefined1 *)((int)param_1 + 0x6660) = 2;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x9250) = 0;
    *(undefined1 *)((int)param_1 + 0x6661) = 2;
  }
  iVar2 = *(int *)((int)param_1 + 0x238);
  if (iVar2 == 4) {
    *(undefined4 *)((int)param_1 + 600) = 1;
    *(undefined4 *)((int)param_1 + 0x25c) = 1;
  }
  if (iVar2 == 6) {
    *(undefined4 *)((int)param_1 + 600) = 2;
    *(undefined4 *)((int)param_1 + 0x25c) = 1;
  }
  if (iVar2 == 8) {
    *(undefined4 *)((int)param_1 + 600) = 2;
    *(undefined4 *)((int)param_1 + 0x25c) = 2;
  }
  if (iVar2 == 0xd) {
    *(undefined1 *)((int)param_1 + 0x6880) = 0;
  }
  if (iVar2 == 0x10) {
    *(undefined4 *)((int)param_1 + 600) = 2;
    *(undefined4 *)((int)param_1 + 0x25c) = 3;
  }
  if (iVar2 == 0x12) {
    *(undefined4 *)((int)param_1 + 600) = 2;
    *(undefined4 *)((int)param_1 + 0x25c) = 4;
  }
  if (iVar2 == 0x14) {
    *(undefined4 *)((int)param_1 + 600) = 1;
    *(undefined4 *)((int)param_1 + 0x25c) = 4;
  }
  if (iVar2 == 0x16) {
    *(undefined4 *)((int)param_1 + 600) = 0;
    *(undefined4 *)((int)param_1 + 0x25c) = 4;
  }
  if (iVar2 == 0x19) {
    *(undefined1 *)((int)param_1 + 0x6880) = 2;
  }
  if ((0x18 < iVar2) && (iVar2 < 0x27)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x300c0 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0xa00 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x80);
  }
  if ((0x1a < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x21)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x380c0 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               ((*(int *)((int)param_1 + 0x238) * 0x10 + *(int *)((int)param_1 + 0x244)) * 0xa0 +
                -0x10400 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x10);
  }
  if ((0x20 < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x27)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x30090 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c38 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x30);
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x33090 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c38 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x10);
  }
  iVar2 = *(int *)((int)param_1 + 0x238);
  if (iVar2 == 0x2d) {
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 6;
    *(undefined1 *)((int)param_1 + 0x667d) = 6;
    *(undefined1 *)((int)param_1 + 0x667e) = 0;
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined4 *)((int)param_1 + 0x6674) = 4;
    *(undefined1 *)((int)param_1 + 0x667f) = 0;
  }
  if (iVar2 == 0x32) {
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    *(undefined1 *)((int)param_1 + 0x91a0) = 0;
  }
  if (iVar2 == 0x35) {
    *(undefined4 *)((int)param_1 + 0x6674) = 4;
    *(undefined1 *)((int)param_1 + 0x667c) = 2;
    *(undefined1 *)((int)param_1 + 0x667d) = 2;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667f) = 4;
  }
  if (iVar2 == 0x3b) {
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
  }
  if (iVar2 < 0x29) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
  }
  iVar2 = *(int *)((int)param_1 + 0x238);
  if (iVar2 < 10) {
    FUN_0040a870(0,8,8,9,s_1_Choose_character_00433b50,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    return;
  }
  if (iVar2 < 0xf) {
    FUN_0040a870(0,8,4,5,s_Left_button_00433b44,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    return;
  }
  if (iVar2 < 0x19) {
    FUN_0040a870(0,8,8,9,s_2_Choose_destination_00433b2c,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    return;
  }
  if (iVar2 < 0x1b) {
    FUN_0040a870(0,8,4,5,s_Left_button_00433b44,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    return;
  }
  if (iVar2 < 0x24) {
    FUN_0040a870(0,8,8,9,s_3_Choose_order_00433b1c,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    return;
  }
  if (iVar2 < 0x29) {
    FUN_0040a870(0,8,4,5,s_Left_button_00433b44,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  return;
}



/* 004155b0  FUN_004155b0  259 bytes, 0 callers */

void __fastcall FUN_004155b0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_20;
  char **local_1c;
  int local_18;
  char *local_14;
  char *local_10;
  char *local_c;
  char *local_8;
  char *local_4;
  
  local_14 = s_Selected__00433bb4;
  local_10 = s_Can_t_go__00433ba0;
  local_c = s_Can_go__00433b8c;
  local_8 = s_Powerful_enemy_00433b78;
  local_4 = s_Unit_in_way_00433b64;
  iVar2 = 0;
  local_1c = &local_14;
  local_18 = 0;
  local_20 = 0;
  do {
    *(undefined4 *)(param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)(param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               ((*(int *)(param_1 + 0x244) + iVar2) * 0xa0 + *(int *)(param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar1 = *(int *)(param_1 + 0x244) + 1;
      *(int *)(param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
    FUN_004244b0(local_18,0x20,0xa0,0xa0,*(int *)(param_1 + 0x22c) + local_20);
    iVar1 = iVar2 + 8;
    iVar2 = iVar2 + 0x20;
    FUN_0040a870(0x30,iVar1,8,9,*local_1c,*(HDC *)(param_1 + 0x224),1,(int *)(param_1 + 0x938c));
    local_1c = local_1c + 1;
    local_20 = local_20 + 0x1400;
    local_18 = local_18 + 1;
  } while (local_20 < 0x6400);
  return;
}



/* 004156c0  FUN_004156c0  317 bytes, 0 callers */

void __fastcall FUN_004156c0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char local_20 [4];
  int local_1c;
  char **local_18;
  int local_14;
  char *local_10;
  char *local_c;
  char *local_8;
  char *local_4;
  
  local_10 = s_Help__00433bf8;
  local_c = s_No_cash_00433be8;
  local_8 = s_Under_orders_00433bd8;
  local_4 = s_Leader_00433bc8;
  builtin_strncpy(local_20,"\x06\b\n\f",4);
  iVar3 = 0;
  local_14 = 0;
  local_18 = &local_10;
  local_1c = 0;
  do {
    *(undefined4 *)(param_1 + 0x244) = 0;
    do {
      puVar4 = (undefined4 *)(*(int *)(param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar5 = (undefined4 *)
               ((*(int *)(param_1 + 0x244) + iVar3) * 0xa0 + 0xa00 + *(int *)(param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      iVar1 = *(int *)(param_1 + 0x244) + 1;
      *(int *)(param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
    uVar2 = *(uint *)(param_1 + 0x238) & 1;
    if (local_1c == 0x3c00) {
      uVar2 = *(uint *)(param_1 + 0x238) & 3;
    }
    FUN_004244b0(uVar2 + (int)local_20[local_14],0x20,0xa0,0xa0,
                 *(int *)(param_1 + 0x22c) + local_1c + 0xa00);
    iVar1 = iVar3 + 0x18;
    iVar3 = iVar3 + 0x20;
    FUN_0040a870(0x30,iVar1,8,9,*local_18,*(HDC *)(param_1 + 0x224),1,(int *)(param_1 + 0x938c));
    local_18 = local_18 + 1;
    local_1c = local_1c + 0x1400;
    local_14 = local_14 + 1;
  } while (local_1c < 0x5000);
  return;
}



/* 00415800  FUN_00415800  209 bytes, 0 callers */

void __fastcall FUN_00415800(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 0x238) == 0) {
    *(undefined1 *)(param_1 + 0x6880) = 0xff;
    *(undefined1 *)(param_1 + 0x6670) = 0;
    *(undefined1 *)(param_1 + 0x666c) = 6;
    *(undefined4 *)(param_1 + 0x6668) = 100;
    *(undefined1 *)(param_1 + 0x666d) = 1;
    *(undefined1 *)(param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)(param_1 + 0x9388) * 0x38);
    *(undefined1 *)(param_1 + 0x9250) = 0;
    *(undefined4 *)(param_1 + 0x6678) = 0x1e;
  }
  *(undefined4 *)(param_1 + 0x244) = 0;
  do {
    puVar2 = (undefined4 *)(*(int *)(param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x244) * 0xa0 + *(int *)(param_1 + 0x22c));
    for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    iVar1 = *(int *)(param_1 + 0x244) + 1;
    *(int *)(param_1 + 0x244) = iVar1;
  } while (iVar1 < 0x20);
  FUN_0040a870(8,8,8,9,s_Hanging_around_00433c08,*(HDC *)(param_1 + 0x224),1,
               (int *)(param_1 + 0x938c));
  return;
}



/* 004158e0  FUN_004158e0  1196 bytes, 0 callers */

void __fastcall FUN_004158e0(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((*(int *)((int)param_1 + 0x238) == 0) || (*(int *)((int)param_1 + 0x238) == 0x50)) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    *(undefined4 *)((int)param_1 + 0x6668) = 100;
    *(undefined1 *)((int)param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38);
    *(undefined1 *)((int)param_1 + 0x9250) = 0;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x6660) = 2;
    *(undefined1 *)((int)param_1 + 0x6661) = 2;
    *(undefined1 *)((int)param_1 + 0x9230) = 0x7b;
    *(undefined1 *)((int)param_1 + 0x9350) = 0x7b;
    *(undefined1 *)((int)param_1 + 0x9140) = 4;
    *(undefined1 *)((int)param_1 + 0x9320) = 4;
    *(undefined1 *)((int)param_1 + 0x9380) = 4;
    *(undefined1 *)((int)param_1 + 0x91a0) = 4;
  }
  switch(*(int *)((int)param_1 + 0x238)) {
  case 5:
    *(char *)((int)param_1 + 0x9260) = *(char *)((int)param_1 + 0x9388) + '\b';
    break;
  case 10:
    *(undefined4 *)((int)param_1 + 0x6674) = 2;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 0;
    *(undefined1 *)((int)param_1 + 0x667d) = 0;
    break;
  case 0x12:
    *(char *)((int)param_1 + 0x9170) = *(char *)((int)param_1 + 0x9388) + '\b';
    break;
  case 0x14:
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined4 *)((int)param_1 + 0x6674) = 2;
    *(undefined1 *)((int)param_1 + 0x667c) = 2;
    *(undefined1 *)((int)param_1 + 0x667d) = 2;
    break;
  case 0x1d:
    *(char *)((int)param_1 + 0x9140) = *(char *)((int)param_1 + 0x9388) + '\b';
    break;
  case 0x1e:
    *(undefined4 *)((int)param_1 + 0x6674) = 6;
    *(undefined1 *)((int)param_1 + 0x667c) = 4;
    *(undefined1 *)((int)param_1 + 0x667d) = 6;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    *(undefined1 *)((int)param_1 + 0x667f) = 4;
    *(undefined1 *)((int)param_1 + 0x6681) = 4;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x6680) = 2;
    break;
  case 0x28:
    *(char *)((int)param_1 + 0x9320) = *(char *)((int)param_1 + 0x9388) + '\b';
    break;
  case 0x2c:
    *(undefined4 *)((int)param_1 + 0x6674) = 6;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 6;
    *(undefined1 *)((int)param_1 + 0x667d) = 0;
    *(undefined1 *)((int)param_1 + 0x667e) = 6;
    *(undefined1 *)((int)param_1 + 0x667f) = 6;
    *(undefined1 *)((int)param_1 + 0x6680) = 4;
    *(undefined1 *)((int)param_1 + 0x6681) = 6;
    break;
  case 0x37:
    *(char *)((int)param_1 + 0x9380) = *(char *)((int)param_1 + 0x9388) + '\b';
    break;
  case 0x38:
    *(undefined4 *)((int)param_1 + 0x6674) = 2;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 0;
    *(undefined1 *)((int)param_1 + 0x667d) = 0;
    break;
  case 0x3c:
    *(char *)((int)param_1 + 0x9290) = *(char *)((int)param_1 + 0x9388) + '\b';
    break;
  case 0x41:
    *(undefined4 *)((int)param_1 + 0x6674) = 2;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 0;
    *(undefined1 *)((int)param_1 + 0x667d) = 0;
    break;
  case 0x46:
    *(char *)((int)param_1 + 0x91a0) = *(char *)((int)param_1 + 0x9388) + '\b';
    break;
  case 0x4a:
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
  }
  if (*(int *)((int)param_1 + 0x238) < 0x14) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x1400 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
    FUN_0040a870(4,8,8,9,s_Unit_will_think_and_00433c68,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(4,0x28,8,9,s_act_on_it_s_own__00433c54,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  if ((0x27 < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x3d)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x1400 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x2800 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c00 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x5000 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
    piVar1 = (int *)((int)param_1 + 0x938c);
    FUN_0040a870(4,0x28,8,9,s_But_they_00433c48,*(HDC *)((int)param_1 + 0x224),1,piVar1);
    FUN_0040a870(4,0x48,8,9,s_won_t_remove_00433c38,*(HDC *)((int)param_1 + 0x224),1,piVar1);
    FUN_0040a870(4,0x68,8,9,s_any_barriers_00433c28,*(HDC *)((int)param_1 + 0x224),1,piVar1);
    FUN_0040a870(4,0x88,8,9,s_without_orders__00433c18,*(HDC *)((int)param_1 + 0x224),1,piVar1);
  }
  return;
}



/* 00415e10  FUN_00415e10  1539 bytes, 0 callers */

void __fastcall FUN_00415e10(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((*(int *)((int)param_1 + 0x238) == 0x4b) || (*(int *)((int)param_1 + 0x238) == 0)) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    *(undefined4 *)((int)param_1 + 0x6668) = 100;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    *(undefined1 *)((int)param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38);
    *(undefined1 *)((int)param_1 + 0x9250) = 0;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x91b8) = 0x39;
    *(undefined1 *)((int)param_1 + 0x9320) = 0x48;
    *(undefined1 *)((int)param_1 + 0x6660) = 2;
    *(undefined1 *)((int)param_1 + 0x6661) = 2;
    *(undefined1 *)((int)param_1 + 0x9230) = 0x38;
    *(undefined1 *)((int)param_1 + 0x92a8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9380) = 0x41;
    *(undefined1 *)((int)param_1 + 0x9338) = 0x31;
    *(undefined1 *)((int)param_1 + 0x9350) = 0x31;
    *(undefined1 *)((int)param_1 + 0x9368) = 0x31;
    *(undefined1 *)((int)param_1 + 0x9308) = 0x32;
    *(undefined1 *)((int)param_1 + 0x9290) = 0x32;
    *(undefined1 *)((int)param_1 + 0x9218) = 0x32;
    *(undefined1 *)((int)param_1 + 0x91a0) = 0x32;
  }
  switch(*(int *)((int)param_1 + 0x238)) {
  case 2:
    *(char *)((int)param_1 + 0x9260) = *(char *)((int)param_1 + 0x9388) + '\b';
    break;
  case 10:
    *(char *)((int)param_1 + 0x91e8) = *(char *)((int)param_1 + 0x9388) + '\f';
    break;
  case 0xc:
    *(char *)((int)param_1 + 0x92d8) = *(char *)((int)param_1 + 0x9388) + '\f';
    break;
  case 0xe:
    *(char *)((int)param_1 + 0x9248) = *(char *)((int)param_1 + 0x9388) + '\f';
    break;
  case 0x10:
    *(char *)((int)param_1 + 0x9278) = *(char *)((int)param_1 + 0x9388) + '\f';
    break;
  case 0x12:
    *(char *)((int)param_1 + 0x91d0) = *(char *)((int)param_1 + 0x9388) + '\f';
    break;
  case 0x14:
    *(char *)((int)param_1 + 0x92c0) = *(char *)((int)param_1 + 0x9388) + '\f';
    break;
  case 0x16:
    *(char *)((int)param_1 + 0x9200) = *(char *)((int)param_1 + 0x9388) + '\f';
    break;
  case 0x18:
    *(char *)((int)param_1 + 0x92f0) = *(char *)((int)param_1 + 0x9388) + '\f';
    break;
  case 0x1e:
  case 0x28:
  case 0x32:
  case 0x3c:
    *(undefined1 *)((int)param_1 + 0x6890) = 4;
    *(undefined1 *)((int)param_1 + 0x6894) = 0;
    *(undefined1 *)((int)param_1 + 0x6aa4) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6891) = 1;
    *(undefined4 *)((int)param_1 + 0x688c) = 100;
    *(undefined1 *)((int)param_1 + 0x6888) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38);
    *(undefined1 *)((int)param_1 + 0x6884) = 0;
    *(undefined1 *)((int)param_1 + 0x6885) = 0;
    *(undefined4 *)((int)param_1 + 0x6898) = 4;
    *(undefined1 *)((int)param_1 + 0x68a2) = 4;
    *(undefined1 *)((int)param_1 + 0x68a3) = 4;
    *(undefined4 *)((int)param_1 + 0x689c) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x9130) = 1;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 6;
    *(undefined1 *)((int)param_1 + 0x68a1) = 6;
    break;
  case 0x2d:
    *(undefined4 *)((int)param_1 + 0x6668) = 1000;
    break;
  case 0x41:
    *(undefined4 *)((int)param_1 + 0x6668) = 10000;
  }
  if (*(int *)((int)param_1 + 0x238) < 0x14) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x1400 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
    FUN_0040a870(4,8,8,9,s_Sets_up_a_base_00433ce4,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(4,0x28,8,9,s_and_stays_there__00433cd0,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  if ((0x1d < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x2d)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x1400 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c00 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
    piVar1 = (int *)((int)param_1 + 0x938c);
    FUN_0040a870(4,8,8,9,s_Later__00433cc8,*(HDC *)((int)param_1 + 0x224),1,piVar1);
    FUN_0040a870(4,0x28,8,9,s_more_units_will_00433cb8,*(HDC *)((int)param_1 + 0x224),1,piVar1);
    FUN_0040a870(4,0x68,8,9,s_gather_there__00433ca8,*(HDC *)((int)param_1 + 0x224),1,piVar1);
  }
  if ((0x2c < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x37)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c00 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x5000 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
    FUN_0040a870(0x10,0x68,8,9,s_Population_00433c9c,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0x10,0x88,8,9,s_1_000_or_more_00433c8c,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  if ((0x40 < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x4b)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c00 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x5000 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
    FUN_0040a870(0x10,0x68,8,9,s_Population_00433c9c,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0x10,0x88,8,9,s_10_000_or_more_00433c7c,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  return;
}



/* 004164a0  FUN_004164a0  694 bytes, 0 callers */

void __fastcall FUN_004164a0(void *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((*(int *)((int)param_1 + 0x238) == 0x14) || (*(int *)((int)param_1 + 0x238) == 0)) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x666c) = 2;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined4 *)((int)param_1 + 0x6668) = 1000;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    iVar2 = (uint)*(byte *)((int)param_1 + 0x9388) * 0x38;
    *(undefined1 *)((int)param_1 + 0x6664) = *(undefined1 *)(DAT_00434534 + iVar2);
    *(undefined1 *)((int)param_1 + 0x6660) = 2;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x6aa4) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6661) = 2;
    *(undefined1 *)((int)param_1 + 0x6894) = 0;
    *(undefined1 *)((int)param_1 + 0x6890) = 6;
    *(undefined4 *)((int)param_1 + 0x688c) = 1000;
    *(undefined1 *)((int)param_1 + 0x6891) = 1;
    cVar1 = *(char *)(DAT_00434534 + iVar2);
    *(undefined1 *)((int)param_1 + 0x6884) = 2;
    *(undefined1 *)((int)param_1 + 0x6885) = 0;
    *(undefined4 *)((int)param_1 + 0x689c) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x6cc8) = 0xff;
    *(byte *)((int)param_1 + 0x6888) = cVar1 + 1U & 3;
    *(undefined1 *)((int)param_1 + 0x6ab8) = 0;
    *(undefined1 *)((int)param_1 + 0x6ab4) = 6;
    *(undefined1 *)((int)param_1 + 0x6ab5) = 1;
    *(undefined4 *)((int)param_1 + 0x6ab0) = 1000;
    *(undefined1 *)((int)param_1 + 0x6aac) = *(undefined1 *)(DAT_00434534 + iVar2);
    *(undefined1 *)((int)param_1 + 0x6aa8) = 0;
    *(undefined1 *)((int)param_1 + 0x9250) = 0;
    *(undefined1 *)((int)param_1 + 0x9190) = 2;
    *(undefined4 *)((int)param_1 + 0x6ac0) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x6aa9) = 4;
    *(undefined1 *)((int)param_1 + 0x9230) = 0;
    *(undefined1 *)((int)param_1 + 0x9220) = 1;
    *(undefined1 *)((int)param_1 + 0x9140) = 0x30;
    *(undefined1 *)((int)param_1 + 0x9320) = 0x30;
    *(undefined1 *)((int)param_1 + 0x9248) = 0x7a;
    *(undefined1 *)((int)param_1 + 0x91b8) = 0x34;
    *(undefined1 *)((int)param_1 + 0x92a8) = 0x31;
    *(undefined1 *)((int)param_1 + 0x91d0) = 0x5a;
    *(undefined1 *)((int)param_1 + 0x92c0) = 0x59;
    *(undefined1 *)((int)param_1 + 0x9158) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9338) = 0x38;
  }
  iVar2 = *(int *)((int)param_1 + 0x238);
  if (iVar2 == 5) {
    *(undefined4 *)((int)param_1 + 0x6668) = 100;
  }
  else if (iVar2 == 10) {
    *(undefined4 *)((int)param_1 + 0x6ac0) = 0;
    *(undefined4 *)((int)param_1 + 0x6abc) = 4;
    *(undefined1 *)((int)param_1 + 0x6ac4) = 4;
    *(undefined1 *)((int)param_1 + 0x6ac5) = 4;
    *(undefined1 *)((int)param_1 + 0x6ac6) = 2;
    *(undefined1 *)((int)param_1 + 0x6ac7) = 2;
  }
  else if (iVar2 == 0xf) {
    *(undefined4 *)((int)param_1 + 0x6668) = 1000;
  }
  if ((9 < iVar2) && (iVar2 < 0x1e)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x1400 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
    FUN_0040a870(0x10,8,8,9,s_Useful_for_00433d08,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0x10,0x28,8,9,s_reinforcing_units_00433cf4,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  return;
}



/* 00416760  FUN_00416760  494 bytes, 0 callers */

void __fastcall FUN_00416760(void *param_1)

{
  int iVar1;
  
  if ((*(int *)((int)param_1 + 0x238) == 0) || (*(int *)((int)param_1 + 0x238) == 0x14)) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    *(undefined4 *)((int)param_1 + 0x6668) = 1000;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    iVar1 = (uint)*(byte *)((int)param_1 + 0x9388) * 0x38;
    *(undefined1 *)((int)param_1 + 0x6664) = *(undefined1 *)(DAT_00434534 + iVar1);
    *(undefined1 *)((int)param_1 + 0x9250) = 0;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x9140) = 0x44;
    *(undefined1 *)((int)param_1 + 0x6660) = 2;
    *(undefined1 *)((int)param_1 + 0x6661) = 2;
    *(undefined1 *)((int)param_1 + 0x9320) = 0x48;
    *(undefined1 *)((int)param_1 + 0x91b8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9230) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9380) = 0x41;
    *(undefined1 *)((int)param_1 + 0x92a8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9338) = 0x31;
    *(undefined1 *)((int)param_1 + 0x9350) = 0x31;
    *(undefined1 *)((int)param_1 + 0x91a0) = 0x42;
    *(undefined1 *)((int)param_1 + 0x9368) = 0x31;
    *(undefined1 *)((int)param_1 + 0x9308) = 0x32;
    *(undefined1 *)((int)param_1 + 0x9290) = 0x32;
    *(undefined1 *)((int)param_1 + 0x9218) = 0x32;
    *(undefined1 *)((int)param_1 + 0x9188) = 0x34;
    *(undefined1 *)((int)param_1 + 0x9170) = 0x34;
    *(undefined1 *)((int)param_1 + 0x9158) = 0x34;
    *(byte *)((int)param_1 + 0x91d0) = (*(char *)(DAT_00434534 + iVar1) + 1U & 3) + 8;
    *(byte *)((int)param_1 + 0x92c0) = (*(char *)(DAT_00434534 + iVar1) + 1U & 3) + 8;
    *(byte *)((int)param_1 + 0x92f0) = (*(char *)(DAT_00434534 + iVar1) + 1U & 3) + 8;
    *(byte *)((int)param_1 + 0x9200) = (*(char *)(DAT_00434534 + iVar1) + 1U & 3) + 8;
  }
  switch(*(undefined4 *)((int)param_1 + 0x238)) {
  case 2:
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 0;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    *(undefined1 *)((int)param_1 + 0x667f) = 4;
    *(undefined1 *)((int)param_1 + 0x6682) = 0;
    *(undefined1 *)((int)param_1 + 0x6680) = 6;
    *(undefined1 *)((int)param_1 + 0x6681) = 6;
    *(undefined4 *)((int)param_1 + 0x6674) = 8;
    *(undefined1 *)((int)param_1 + 0x667d) = 2;
    *(undefined1 *)((int)param_1 + 0x6683) = 0;
    return;
  case 6:
    *(undefined1 *)((int)param_1 + 0x91d0) = 0;
    return;
  case 9:
    *(undefined1 *)((int)param_1 + 0x92c0) = 0;
    return;
  case 0xc:
    *(undefined1 *)((int)param_1 + 0x92f0) = 0;
    return;
  case 0xf:
    *(undefined1 *)((int)param_1 + 0x9200) = 0;
    return;
  case 0x10:
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
  }
  return;
}



/* 00416980  FUN_00416980  503 bytes, 0 callers */

void __fastcall FUN_00416980(void *param_1)

{
  if ((*(int *)((int)param_1 + 0x238) == 0) || (*(int *)((int)param_1 + 0x238) == 0x14)) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    *(undefined4 *)((int)param_1 + 0x6668) = 1000;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    *(undefined1 *)((int)param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38);
    *(undefined1 *)((int)param_1 + 0x9250) = 0;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x9140) = 0x44;
    *(undefined1 *)((int)param_1 + 0x6660) = 2;
    *(undefined1 *)((int)param_1 + 0x6661) = 2;
    *(undefined1 *)((int)param_1 + 0x9320) = 0x48;
    *(undefined1 *)((int)param_1 + 0x91b8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9230) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9380) = 0x41;
    *(undefined1 *)((int)param_1 + 0x92a8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9338) = 0x31;
    *(undefined1 *)((int)param_1 + 0x9350) = 0x31;
    *(undefined1 *)((int)param_1 + 0x91a0) = 0x42;
    *(undefined1 *)((int)param_1 + 0x9368) = 0x31;
    *(undefined1 *)((int)param_1 + 0x9308) = 0x32;
    *(undefined1 *)((int)param_1 + 0x9290) = 0x32;
    *(undefined1 *)((int)param_1 + 0x9218) = 0x32;
    *(undefined1 *)((int)param_1 + 0x9188) = 0x34;
    *(undefined1 *)((int)param_1 + 0x9170) = 0x34;
    *(undefined1 *)((int)param_1 + 0x9158) = 0x34;
  }
  switch(*(undefined4 *)((int)param_1 + 0x238)) {
  case 2:
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 0;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    *(undefined1 *)((int)param_1 + 0x667f) = 4;
    *(undefined1 *)((int)param_1 + 0x6682) = 0;
    *(undefined1 *)((int)param_1 + 0x6680) = 6;
    *(undefined1 *)((int)param_1 + 0x6681) = 6;
    *(undefined4 *)((int)param_1 + 0x6674) = 8;
    *(undefined1 *)((int)param_1 + 0x667d) = 2;
    *(undefined1 *)((int)param_1 + 0x6683) = 0;
    return;
  case 6:
    *(char *)((int)param_1 + 0x91d0) =
         *(char *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38) + '\b';
    return;
  case 9:
    *(char *)((int)param_1 + 0x92c0) =
         *(char *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38) + '\b';
    return;
  case 0xc:
    *(char *)((int)param_1 + 0x92f0) =
         *(char *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38) + '\b';
    return;
  case 0xf:
    *(char *)((int)param_1 + 0x9200) =
         *(char *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38) + '\b';
    return;
  case 0x10:
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
  }
  return;
}



/* 00416bb0  FUN_00416bb0  1388 bytes, 0 callers */

void __fastcall FUN_00416bb0(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((*(int *)((int)param_1 + 0x238) == 0) || (*(int *)((int)param_1 + 0x238) == 0x3c)) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    *(undefined4 *)((int)param_1 + 0x6668) = 1000;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    *(undefined1 *)((int)param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38);
    *(undefined1 *)((int)param_1 + 0x6660) = 0;
    *(undefined1 *)((int)param_1 + 0x9190) = 0;
    *(undefined1 *)((int)param_1 + 0x9140) = 0x30;
    *(undefined1 *)((int)param_1 + 0x9230) = 0x38;
    *(undefined1 *)((int)param_1 + 0x92a8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9320) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9158) = 0x30;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x6661) = 4;
    *(undefined1 *)((int)param_1 + 0x9170) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9260) = 0;
    *(undefined1 *)((int)param_1 + 0x91b8) = 0x44;
    *(undefined1 *)((int)param_1 + 0x91d0) = 0x34;
    *(undefined1 *)((int)param_1 + 0x91e8) = 0x3c;
    *(undefined1 *)((int)param_1 + 0x92d8) = 0x3b;
    *(undefined1 *)((int)param_1 + 0x9350) = 0x3a;
  }
  iVar1 = *(int *)((int)param_1 + 0x238);
  switch(iVar1) {
  case 2:
    *(undefined1 *)((int)param_1 + 0x6890) = 6;
    *(undefined1 *)((int)param_1 + 0x6891) = 1;
    *(undefined1 *)((int)param_1 + 0x6894) = 0;
    *(undefined1 *)((int)param_1 + 0x6aa4) = 0xff;
    *(undefined4 *)((int)param_1 + 0x688c) = 1000;
    *(undefined1 *)((int)param_1 + 0x6885) = 1;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 0;
    *(undefined1 *)((int)param_1 + 0x68a1) = 0;
    *(undefined1 *)((int)param_1 + 0x68a2) = 6;
    *(undefined1 *)((int)param_1 + 0x68a3) = 6;
    *(undefined1 *)((int)param_1 + 0x68a4) = 6;
    *(undefined1 *)((int)param_1 + 0x9328) = 1;
    *(undefined1 *)((int)param_1 + 0x6888) = 4;
    *(undefined1 *)((int)param_1 + 0x6884) = 4;
    *(undefined4 *)((int)param_1 + 0x6898) = 5;
    break;
  case 9:
  case 0x2b:
    *(undefined1 *)((int)param_1 + 0x9280) = 0x14;
    break;
  case 0xc:
    *(undefined4 *)((int)param_1 + 0x6674) = 3;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 2;
    *(undefined1 *)((int)param_1 + 0x667d) = 4;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    break;
  case 0x11:
    *(undefined1 *)((int)param_1 + 0x666c) = 2;
    break;
  case 0x14:
    *(undefined1 *)((int)param_1 + 0x9260) = 0x7b;
    break;
  case 0x16:
    *(undefined1 *)((int)param_1 + 0x6891) = 1;
    *(undefined1 *)((int)param_1 + 0x6894) = 0;
    *(undefined1 *)((int)param_1 + 0x6885) = 1;
    *(undefined1 *)((int)param_1 + 0x6888) = 4;
    *(undefined1 *)((int)param_1 + 0x6884) = 4;
    *(undefined1 *)((int)param_1 + 0x6aa4) = 0xff;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 0;
    *(undefined1 *)((int)param_1 + 0x68a1) = 0;
    *(undefined1 *)((int)param_1 + 0x9328) = 1;
    *(undefined1 *)((int)param_1 + 0x6890) = 6;
    *(undefined4 *)((int)param_1 + 0x688c) = 1000;
    *(undefined4 *)((int)param_1 + 0x6898) = 2;
    break;
  case 0x19:
    *(undefined1 *)((int)param_1 + 0x6890) = 6;
    break;
  case 0x1a:
    *(undefined4 *)((int)param_1 + 0x6898) = 2;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 4;
    *(undefined1 *)((int)param_1 + 0x68a1) = 4;
    break;
  case 0x1d:
    *(undefined1 *)((int)param_1 + 0x9328) = 0x14;
    break;
  case 0x1e:
    *(undefined4 *)((int)param_1 + 0x6674) = 2;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 4;
    *(undefined1 *)((int)param_1 + 0x667d) = 4;
    break;
  case 0x20:
    *(undefined1 *)((int)param_1 + 0x6891) = 1;
    *(undefined1 *)((int)param_1 + 0x6894) = 0;
    *(undefined1 *)((int)param_1 + 0x6aa4) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6885) = 1;
    *(undefined1 *)((int)param_1 + 0x6888) = 2;
    *(undefined4 *)((int)param_1 + 0x6898) = 2;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 0;
    *(undefined1 *)((int)param_1 + 0x68a1) = 0;
    *(undefined1 *)((int)param_1 + 0x9328) = 1;
    *(undefined1 *)((int)param_1 + 0x6890) = 6;
    *(undefined4 *)((int)param_1 + 0x688c) = 100;
    *(undefined1 *)((int)param_1 + 0x6884) = 4;
    break;
  case 0x21:
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    break;
  case 0x23:
    *(undefined1 *)((int)param_1 + 0x6890) = 6;
    break;
  case 0x26:
    *(undefined1 *)((int)param_1 + 0x9260) = 0;
    break;
  case 0x28:
    *(undefined4 *)((int)param_1 + 0x6898) = 2;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 6;
    *(undefined1 *)((int)param_1 + 0x68a1) = 6;
  }
  if ((0x11 < iVar1) && (iVar1 < 0x1d)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar2 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar3 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c00 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar2 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar3 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x5000 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      iVar1 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
    FUN_0040a870(0x10,0x68,8,9,s_Keeps_out_00433d50,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0x10,0x88,8,9,s_unwanted_units__00433d40,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  if ((0x1f < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x23)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar2 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar3 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      iVar1 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
    FUN_0040a870(0x10,8,8,9,s_but____00433d38,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  if ((0x25 < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x3a)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar2 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar3 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar2 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar3 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x1400 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      iVar1 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
    FUN_0040a870(0x10,8,8,9,s_can_be_destroyed_00433d24,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0x10,0x28,8,9,s_by_enemy_units_00433d14,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  return;
}



/* 00417190  FUN_00417190  1250 bytes, 0 callers */

void __fastcall FUN_00417190(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((*(int *)((int)param_1 + 0x238) == 0) || (*(int *)((int)param_1 + 0x238) == 0x3e)) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    *(undefined4 *)((int)param_1 + 0x6668) = 1000;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    *(undefined1 *)((int)param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38);
    *(undefined1 *)((int)param_1 + 0x6660) = 0;
    *(undefined1 *)((int)param_1 + 0x9190) = 0;
    *(undefined1 *)((int)param_1 + 0x91b8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9230) = 0x38;
    *(undefined1 *)((int)param_1 + 0x92a8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9320) = 0x38;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x6661) = 4;
    *(undefined1 *)((int)param_1 + 0x9140) = 0x44;
    *(undefined1 *)((int)param_1 + 0x9158) = 0x34;
    *(undefined1 *)((int)param_1 + 0x9170) = 0x5a;
    *(undefined1 *)((int)param_1 + 0x91e8) = 0x7a;
    *(undefined1 *)((int)param_1 + 0x9260) = 0x3a;
    *(undefined1 *)((int)param_1 + 0x92d8) = 0x3a;
    *(undefined1 *)((int)param_1 + 0x9350) = 0x3a;
  }
  iVar2 = *(int *)((int)param_1 + 0x238);
  switch(iVar2) {
  case 2:
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667d) = 4;
    *(undefined4 *)((int)param_1 + 0x6674) = 2;
    *(undefined1 *)((int)param_1 + 0x667c) = 2;
    break;
  case 7:
    *(undefined1 *)((int)param_1 + 0x666c) = 2;
    break;
  case 10:
    *(undefined1 *)((int)param_1 + 0x91e8) = 0x25;
    break;
  case 0xf:
    *(undefined4 *)((int)param_1 + 0x6674) = 4;
    *(undefined1 *)((int)param_1 + 0x667c) = 2;
    *(undefined1 *)((int)param_1 + 0x667d) = 2;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    *(undefined1 *)((int)param_1 + 0x6660) = 1;
    *(undefined1 *)((int)param_1 + 0x6661) = 3;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667f) = 4;
    break;
  case 0x14:
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    break;
  case 0x28:
    *(undefined1 *)((int)param_1 + 0x92d8) = 0x25;
  }
  if ((7 < iVar2) && (iVar2 < 0x12)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x1400 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
    FUN_0040a870(0x10,8,8,9,s_Repairing_paths_00433dd8,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0x10,0x28,8,9,s_will_let_you_pass_00433dc4,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  if ((0x13 < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x1e)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c00 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x5000 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
    FUN_0040a870(0x10,0x68,8,9,s_and_you_can_also_00433db0,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0x10,0x88,8,9,s_build_new_ones_00433da0,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  if ((0x1d < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x28)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x2800 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c00 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x5000 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
    piVar1 = (int *)((int)param_1 + 0x938c);
    FUN_0040a870(0x10,0x48,8,9,s_but_doing_so_00433d90,*(HDC *)((int)param_1 + 0x224),1,piVar1);
    FUN_0040a870(0x10,0x68,8,9,s_will_cost_you_3_000_00433d7c,*(HDC *)((int)param_1 + 0x224),1,
                 piVar1);
    FUN_0040a870(0x10,0x88,8,9,s_cash_points_so_00433d6c,*(HDC *)((int)param_1 + 0x224),1,piVar1);
  }
  if ((0x28 < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x33)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c00 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
    FUN_0040a870(0x10,0x68,8,9,s_plan_carefully__00433d5c,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  return;
}



/* 004176c0  FUN_004176c0  436 bytes, 0 callers */

void __fastcall FUN_004176c0(void *param_1)

{
  if ((*(int *)((int)param_1 + 0x238) == 0) || (*(int *)((int)param_1 + 0x238) == 0x14)) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    *(undefined4 *)((int)param_1 + 0x6668) = 1000;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    *(undefined1 *)((int)param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38);
    *(undefined1 *)((int)param_1 + 0x9250) = 0;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x9140) = 0x44;
    *(undefined1 *)((int)param_1 + 0x6660) = 2;
    *(undefined1 *)((int)param_1 + 0x6661) = 2;
    *(undefined1 *)((int)param_1 + 0x9320) = 0x48;
    *(undefined1 *)((int)param_1 + 0x91b8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9230) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9380) = 0x41;
    *(undefined1 *)((int)param_1 + 0x92a8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9338) = 0x31;
    *(undefined1 *)((int)param_1 + 0x9350) = 0x31;
    *(undefined1 *)((int)param_1 + 0x91a0) = 0x42;
    *(undefined1 *)((int)param_1 + 0x9368) = 0x31;
    *(undefined1 *)((int)param_1 + 0x9308) = 0x32;
    *(undefined1 *)((int)param_1 + 0x9290) = 0x32;
    *(undefined1 *)((int)param_1 + 0x9218) = 0x32;
    *(undefined1 *)((int)param_1 + 0x9188) = 0x34;
    *(undefined1 *)((int)param_1 + 0x9170) = 0x34;
    *(undefined1 *)((int)param_1 + 0x9158) = 0x34;
    *(undefined1 *)((int)param_1 + 0x91d0) = 4;
    *(undefined1 *)((int)param_1 + 0x92c0) = 4;
    *(undefined1 *)((int)param_1 + 0x92f0) = 4;
    *(undefined1 *)((int)param_1 + 0x9200) = 4;
  }
  switch(*(undefined4 *)((int)param_1 + 0x238)) {
  case 2:
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 0;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    *(undefined1 *)((int)param_1 + 0x667f) = 4;
    *(undefined1 *)((int)param_1 + 0x6682) = 0;
    *(undefined1 *)((int)param_1 + 0x6680) = 6;
    *(undefined1 *)((int)param_1 + 0x6681) = 6;
    *(undefined4 *)((int)param_1 + 0x6674) = 8;
    *(undefined1 *)((int)param_1 + 0x667d) = 2;
    *(undefined1 *)((int)param_1 + 0x6683) = 0;
    return;
  case 6:
    *(undefined1 *)((int)param_1 + 0x91d0) = 0;
    return;
  case 9:
    *(undefined1 *)((int)param_1 + 0x92c0) = 0;
    return;
  case 0xc:
    *(undefined1 *)((int)param_1 + 0x92f0) = 0;
    return;
  case 0xf:
    *(undefined1 *)((int)param_1 + 0x9200) = 0;
    return;
  case 0x10:
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
  }
  return;
}



/* 004178a0  FUN_004178a0  596 bytes, 0 callers */

void __fastcall FUN_004178a0(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((*(int *)((int)param_1 + 0x238) == 0) || (*(int *)((int)param_1 + 0x238) == 0x19)) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    *(undefined4 *)((int)param_1 + 0x6668) = 1000;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    *(undefined1 *)((int)param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38);
    *(undefined1 *)((int)param_1 + 0x6660) = 0;
    *(undefined1 *)((int)param_1 + 0x9190) = 0;
    *(undefined1 *)((int)param_1 + 0x9140) = 0x30;
    *(undefined1 *)((int)param_1 + 0x9230) = 0x38;
    *(undefined1 *)((int)param_1 + 0x92a8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9320) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9158) = 0x30;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x6661) = 4;
    *(undefined1 *)((int)param_1 + 0x91b8) = 0x44;
    *(undefined1 *)((int)param_1 + 0x91d0) = 0x34;
    *(undefined1 *)((int)param_1 + 0x91e8) = 0x3c;
    *(undefined1 *)((int)param_1 + 0x9260) = 0x7b;
    *(undefined1 *)((int)param_1 + 0x92d8) = 0x3b;
    *(undefined1 *)((int)param_1 + 0x9350) = 0x3a;
    *(undefined1 *)((int)param_1 + 0x9170) = 0x38;
  }
  iVar1 = *(int *)((int)param_1 + 0x238);
  switch(iVar1) {
  case 2:
    *(undefined4 *)((int)param_1 + 0x6674) = 3;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 2;
    *(undefined1 *)((int)param_1 + 0x667d) = 4;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    break;
  case 7:
    *(undefined1 *)((int)param_1 + 0x666c) = 2;
    break;
  case 10:
    *(undefined1 *)((int)param_1 + 0x9260) = 0;
    break;
  case 0xf:
    *(undefined1 *)((int)param_1 + 0x6660) = 2;
    *(undefined4 *)((int)param_1 + 0x6674) = 4;
    *(undefined1 *)((int)param_1 + 0x667c) = 2;
    *(undefined1 *)((int)param_1 + 0x667d) = 2;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    *(undefined1 *)((int)param_1 + 0x667f) = 4;
    *(undefined1 *)((int)param_1 + 0x6661) = 3;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    break;
  case 0x14:
    *(undefined1 *)((int)param_1 + 0x9328) = 0x14;
  }
  if ((5 < iVar1) && (iVar1 < 0x12)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar2 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar3 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar2 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar3 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x1400 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      iVar1 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
    FUN_0040a870(0x10,8,8,9,s_Destroying_barriers_00433dfc,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0x10,0x28,8,9,s_will_allow_passage_00433de8,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  return;
}



/* 00417b20  FUN_00417b20  1392 bytes, 0 callers */

void __fastcall FUN_00417b20(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((*(int *)((int)param_1 + 0x238) == 0) || (*(int *)((int)param_1 + 0x238) == 0x3c)) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    *(undefined4 *)((int)param_1 + 0x6668) = 1000;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    *(undefined1 *)((int)param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38);
    *(undefined1 *)((int)param_1 + 0x6660) = 0;
    *(undefined1 *)((int)param_1 + 0x9190) = 0;
    *(undefined1 *)((int)param_1 + 0x9140) = 0x30;
    *(undefined1 *)((int)param_1 + 0x9230) = 0x38;
    *(undefined1 *)((int)param_1 + 0x92a8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9320) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9158) = 0x30;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x6661) = 4;
    *(undefined1 *)((int)param_1 + 0x91b8) = 0x44;
    *(undefined1 *)((int)param_1 + 0x9170) = 0x38;
    *(undefined1 *)((int)param_1 + 0x92d8) = 0x3a;
    *(undefined1 *)((int)param_1 + 0x9350) = 0x3a;
    *(undefined1 *)((int)param_1 + 0x91d0) = 0x34;
    *(undefined1 *)((int)param_1 + 0x91e8) = 0x5a;
    *(undefined1 *)((int)param_1 + 0x9260) = 0x25;
  }
  iVar1 = *(int *)((int)param_1 + 0x238);
  switch(iVar1) {
  case 2:
    *(undefined1 *)((int)param_1 + 0x6890) = 6;
    *(undefined1 *)((int)param_1 + 0x6891) = 1;
    *(undefined1 *)((int)param_1 + 0x6894) = 0;
    *(undefined1 *)((int)param_1 + 0x6aa4) = 0xff;
    *(undefined4 *)((int)param_1 + 0x688c) = 1000;
    *(undefined1 *)((int)param_1 + 0x6885) = 1;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 0;
    *(undefined1 *)((int)param_1 + 0x68a1) = 0;
    *(undefined1 *)((int)param_1 + 0x68a2) = 6;
    *(undefined1 *)((int)param_1 + 0x68a3) = 6;
    *(undefined1 *)((int)param_1 + 0x68a4) = 6;
    *(undefined1 *)((int)param_1 + 0x9328) = 1;
    *(undefined1 *)((int)param_1 + 0x6888) = 4;
    *(undefined1 *)((int)param_1 + 0x6884) = 4;
    *(undefined4 *)((int)param_1 + 0x6898) = 5;
    break;
  case 9:
  case 0x2b:
    *(undefined1 *)((int)param_1 + 0x9280) = 0x14;
    break;
  case 0xc:
    *(undefined4 *)((int)param_1 + 0x6674) = 3;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 2;
    *(undefined1 *)((int)param_1 + 0x667d) = 4;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    break;
  case 0x11:
    *(undefined1 *)((int)param_1 + 0x666c) = 2;
    break;
  case 0x14:
    *(undefined1 *)((int)param_1 + 0x9260) = 0x7a;
    break;
  case 0x16:
    *(undefined1 *)((int)param_1 + 0x6891) = 1;
    *(undefined1 *)((int)param_1 + 0x6894) = 0;
    *(undefined1 *)((int)param_1 + 0x6885) = 1;
    *(undefined1 *)((int)param_1 + 0x6888) = 4;
    *(undefined1 *)((int)param_1 + 0x6884) = 4;
    *(undefined1 *)((int)param_1 + 0x6aa4) = 0xff;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 0;
    *(undefined1 *)((int)param_1 + 0x68a1) = 0;
    *(undefined1 *)((int)param_1 + 0x9328) = 1;
    *(undefined1 *)((int)param_1 + 0x6890) = 6;
    *(undefined4 *)((int)param_1 + 0x688c) = 1000;
    *(undefined4 *)((int)param_1 + 0x6898) = 2;
    break;
  case 0x19:
    *(undefined1 *)((int)param_1 + 0x6890) = 6;
    break;
  case 0x1a:
    *(undefined4 *)((int)param_1 + 0x6898) = 2;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 4;
    *(undefined1 *)((int)param_1 + 0x68a1) = 4;
    break;
  case 0x1d:
    *(undefined1 *)((int)param_1 + 0x9328) = 0x14;
    break;
  case 0x1e:
    *(undefined4 *)((int)param_1 + 0x6674) = 2;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 4;
    *(undefined1 *)((int)param_1 + 0x667d) = 4;
    break;
  case 0x20:
    *(undefined1 *)((int)param_1 + 0x6891) = 1;
    *(undefined1 *)((int)param_1 + 0x6894) = 0;
    *(undefined1 *)((int)param_1 + 0x6aa4) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6885) = 1;
    *(undefined1 *)((int)param_1 + 0x6888) = 2;
    *(undefined4 *)((int)param_1 + 0x6898) = 2;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 0;
    *(undefined1 *)((int)param_1 + 0x68a1) = 0;
    *(undefined1 *)((int)param_1 + 0x9328) = 1;
    *(undefined1 *)((int)param_1 + 0x6890) = 6;
    *(undefined4 *)((int)param_1 + 0x688c) = 100;
    *(undefined1 *)((int)param_1 + 0x6884) = 4;
    break;
  case 0x21:
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    break;
  case 0x23:
    *(undefined1 *)((int)param_1 + 0x6890) = 6;
    break;
  case 0x26:
    *(undefined1 *)((int)param_1 + 0x9260) = 0x25;
    break;
  case 0x28:
    *(undefined4 *)((int)param_1 + 0x6898) = 2;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 6;
    *(undefined1 *)((int)param_1 + 0x68a1) = 6;
  }
  if ((0x11 < iVar1) && (iVar1 < 0x1d)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar2 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar3 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c00 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar2 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar3 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x5000 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      iVar1 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
    FUN_0040a870(0x10,0x68,8,9,s_Blocks_out_00433e44,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0x10,0x88,8,9,s_unwanted_units_00433e34,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  if ((0x1f < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x23)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar2 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar3 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      iVar1 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
    FUN_0040a870(0x10,8,8,9,s_but____00433d38,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  if ((0x25 < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x3a)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar2 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar3 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar2 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar3 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x1400 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      iVar1 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
    FUN_0040a870(0,8,8,9,s_Enemy_units_can_00433e24,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0,0x28,8,9,s_still_pass_through__00433e10,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  return;
}



/* 00418100  FUN_00418100  785 bytes, 0 callers */

void __fastcall FUN_00418100(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((*(int *)((int)param_1 + 0x238) == 0) || (*(int *)((int)param_1 + 0x238) == 0x28)) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x666c) = 4;
    *(undefined4 *)((int)param_1 + 0x6668) = 1000;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    *(undefined1 *)((int)param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38);
    *(undefined1 *)((int)param_1 + 0x6660) = 0;
    *(undefined1 *)((int)param_1 + 0x9160) = 0;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x91b8) = 0x62;
    *(undefined1 *)((int)param_1 + 0x92a8) = 0x62;
    *(undefined1 *)((int)param_1 + 0x6661) = 2;
    *(undefined1 *)((int)param_1 + 0x9140) = 99;
    *(undefined1 *)((int)param_1 + 0x9230) = 5;
    *(undefined1 *)((int)param_1 + 0x9320) = 0x66;
    *(undefined1 *)((int)param_1 + 0x9158) = 0x6d;
    *(undefined1 *)((int)param_1 + 0x9380) = 0x6c;
    *(undefined1 *)((int)param_1 + 0x9308) = 0x6b;
    *(undefined1 *)((int)param_1 + 0x9218) = 0x6e;
    *(undefined1 *)((int)param_1 + 0x91a0) = 0x69;
    *(undefined1 *)((int)param_1 + 0x9188) = 0x67;
    *(undefined1 *)((int)param_1 + 0x9158) = 0x6d;
    *(undefined1 *)((int)param_1 + 0x9338) = 0x65;
    *(undefined1 *)((int)param_1 + 0x9350) = 0x65;
    *(undefined1 *)((int)param_1 + 0x9368) = 0x65;
  }
  iVar2 = *(int *)((int)param_1 + 0x238);
  switch(iVar2) {
  case 0:
  case 6:
    *(undefined1 *)((int)param_1 + 0x6890) = 4;
    *(undefined1 *)((int)param_1 + 0x6891) = 1;
    *(undefined1 *)((int)param_1 + 0x6894) = 0;
    *(undefined1 *)((int)param_1 + 0x6aa4) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6888) = 4;
    *(undefined1 *)((int)param_1 + 0x6885) = 0;
    *(undefined1 *)((int)param_1 + 0x9220) = 1;
    *(undefined4 *)((int)param_1 + 0x6898) = 4;
    *(undefined4 *)((int)param_1 + 0x688c) = 1000;
    *(undefined4 *)((int)param_1 + 0x689c) = 0x1e;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 6;
    *(undefined1 *)((int)param_1 + 0x68a1) = 6;
    *(undefined1 *)((int)param_1 + 0x68a2) = 6;
    *(undefined1 *)((int)param_1 + 0x68a3) = 6;
    *(undefined1 *)((int)param_1 + 0x6884) = 2;
    *(undefined1 *)((int)param_1 + 0x666c) = 4;
    break;
  case 3:
  case 9:
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    break;
  case 5:
  case 0xb:
    *(undefined1 *)((int)param_1 + 0x9280) = 0x14;
    break;
  case 0xc:
    *(undefined4 *)((int)param_1 + 0x6674) = 3;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667d) = 2;
    *(undefined1 *)((int)param_1 + 0x667c) = 4;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    break;
  case 0x12:
    *(undefined1 *)((int)param_1 + 0x666c) = 2;
    break;
  case 0x14:
    *(undefined1 *)((int)param_1 + 0x9230) = 0x6a;
  }
  if ((9 < iVar2) && (iVar2 < 0x23)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x2800 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c00 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x5000 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
    piVar1 = (int *)((int)param_1 + 0x938c);
    FUN_0040a870(0x10,0x48,8,9,s_None_appear_00433e68,*(HDC *)((int)param_1 + 0x224),1,piVar1);
    FUN_0040a870(0x10,0x68,8,9,s_if_exit_is_00433e5c,*(HDC *)((int)param_1 + 0x224),1,piVar1);
    FUN_0040a870(0x10,0x88,8,9,s_destroyed__00433e50,*(HDC *)((int)param_1 + 0x224),1,piVar1);
  }
  return;
}



/* 00418460  FUN_00418460  87 bytes, 1 callers */

undefined4 * __thiscall FUN_00418460(void *this,WPARAM param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_004184b7;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  *(undefined ***)this = &PTR_FUN_00430590;
  *unaff_FS_OFFSET = local_10;
  return this;
}



/* 004184d0  FUN_004184d0  30 bytes, 0 callers */

undefined4 * __thiscall FUN_004184d0(void *this,byte param_1)

{
  FUN_004184f0(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 004184f0  FUN_004184f0  61 bytes, 1 callers */

void __fastcall FUN_004184f0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_0041852d;
  *param_1 = &PTR_FUN_00430590;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_00418537();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 00418537  FUN_00418537  8 bytes, 1 callers */

void FUN_00418537(void)

{
  int unaff_EBP;
  
  FUN_0040e720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 004187f0  FUN_004187f0  169 bytes, 0 callers */

void __fastcall FUN_004187f0(void *param_1)

{
  undefined1 extraout_AL;
  UINT UVar1;
  
  DAT_0043769e = FUN_0040ed00(param_1,0x441);
  DAT_0043769f = FUN_0040ed00(param_1,0x442);
  UVar1 = IsDlgButtonChecked(*(HWND *)((int)param_1 + 4),0x497);
  DAT_004376a0 = (char)UVar1;
  UVar1 = IsDlgButtonChecked(*(HWND *)((int)param_1 + 4),0x4a6);
  extraout_AL = (undefined1)UVar1;
  DAT_004376b4 = extraout_AL;
  if (DAT_0043769e == '\0') {
    FUN_0040ccf0(0);
  }
  else if (*(int *)((int)param_1 + 0x22338) != -1) {
    FUN_0040cd20(&DAT_00435db0,*(int *)((int)param_1 + 0x22338),0);
  }
  if (DAT_0043769f == '\0') {
    FUN_0040ccf0(1);
  }
  FUN_0040d490(&DAT_00435db0,3,&DAT_00435dcc);
  FUN_0040eb70((int)param_1);
  return;
}



/* 004188a0  FUN_004188a0  220 bytes, 0 callers */

void __fastcall FUN_004188a0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  iVar2 = 0;
  iVar1 = FUN_0040cdc0(0);
  if ((iVar1 != -1) && (0 < DAT_00435dc8)) {
    iVar5 = 0;
    piVar3 = (int *)(param_1 + 0x444);
    do {
      if ((*(int *)(DAT_00435db0 + iVar5) == iVar1) &&
         (((int *)(DAT_00435db0 + iVar5))[0x43] != *piVar3)) {
        FUN_0040ccf0(0);
      }
      piVar3 = piVar3 + 0x88;
      iVar5 = iVar5 + 0x220;
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_00435dc8);
  }
  iVar1 = 0;
  iVar2 = 0;
  if (0 < DAT_00435dc8) {
    puVar4 = (undefined4 *)(param_1 + 0x338);
    do {
      puVar6 = puVar4;
      puVar7 = (undefined4 *)(DAT_00435db0 + iVar1);
      for (iVar5 = 0x88; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar4 = puVar4 + 0x88;
      iVar1 = iVar1 + 0x220;
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_00435dc8);
  }
  if ((DAT_0043769e != '\0') && (*(int *)(param_1 + 0x22338) != -1)) {
    FUN_0040cd20(&DAT_00435db0,*(int *)(param_1 + 0x22338),0);
  }
  FUN_0040eb70(param_1);
  return;
}



/* 00418980  FUN_00418980  87 bytes, 1 callers */

undefined4 * __thiscall FUN_00418980(void *this,WPARAM param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_004189d7;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  *(undefined ***)this = &PTR_FUN_004305d0;
  *unaff_FS_OFFSET = local_10;
  return this;
}



/* 004189f0  FUN_004189f0  30 bytes, 0 callers */

undefined4 * __thiscall FUN_004189f0(void *this,byte param_1)

{
  FUN_00418a10(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 00418a10  FUN_00418a10  61 bytes, 1 callers */

void __fastcall FUN_00418a10(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00418a4d;
  *param_1 = &PTR_FUN_004305d0;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_00418a57();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 00418a57  FUN_00418a57  8 bytes, 1 callers */

void FUN_00418a57(void)

{
  int unaff_EBP;
  
  FUN_0040e720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 00418cb8  FUN_00418cb8  11 bytes, 0 callers */

void FUN_00418cb8(void)

{
  int unaff_EBP;
  
  FUN_0041f900((undefined2 *)(unaff_EBP + -0x234));
  return;
}



/* 00418cd0  FUN_00418cd0  115 bytes, 1 callers */

undefined4 * __thiscall FUN_00418cd0(void *this,WPARAM param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00418d43;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e6b0(this,param_1);
  iVar1 = 0;
  *(undefined ***)this = &PTR_FUN_00430610;
  puVar2 = (undefined4 *)((int)this + 0x22994);
  do {
    *puVar2 = 0xffffffff;
    iVar1 = iVar1 + 1;
    puVar2[0x200] = 0xffffffff;
    puVar2 = puVar2 + 2;
  } while (iVar1 < 0x100);
  *unaff_FS_OFFSET = local_10;
  return this;
}



/* 00418d60  FUN_00418d60  30 bytes, 0 callers */

undefined4 * __thiscall FUN_00418d60(void *this,byte param_1)

{
  FUN_00418d80(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 00418d80  FUN_00418d80  154 bytes, 1 callers */

void __fastcall FUN_00418d80(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00418e1a;
  *param_1 = &PTR_FUN_00430610;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0;
  DAT_0043769f = *(char *)((int)param_1 + 0x23995);
  DAT_0043769e = *(char *)(param_1 + 0x8e65);
  if (DAT_0043769e == '\0') {
    FUN_0040ccf0(0);
  }
  else if (param_1[0x8961] != -1) {
    FUN_0040cd20(&DAT_00435db0,param_1[0x8961],0);
  }
  if (DAT_0043769f == '\0') {
    FUN_0040ccf0(1);
  }
  local_8 = 0xffffffff;
  FUN_00418e24();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 00418e24  FUN_00418e24  8 bytes, 1 callers */

void FUN_00418e24(void)

{
  int unaff_EBP;
  
  FUN_0040e720(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 00419010  FUN_00419010  250 bytes, 0 callers */

void __fastcall FUN_00419010(void *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar1 = 0x100;
  puVar3 = (undefined4 *)((int)param_1 + 0x22994);
  do {
    *puVar3 = 0xffffffff;
    iVar1 = iVar1 + -1;
    puVar3[0x200] = 0xffffffff;
    puVar3 = puVar3 + 2;
  } while (iVar1 != 0);
  iVar1 = 0;
  if (0 < DAT_00435dc8) {
    iVar4 = 0;
    do {
      if (*(int *)(DAT_00435db0 + iVar4) != -1) {
        iVar2 = ((int *)(DAT_00435db0 + iVar4))[0x42];
        if (iVar2 == 0) {
          iVar2 = FUN_004198a0((int)param_1);
          if (iVar2 != -1) {
            FUN_0040ec50(param_1,0x3fb,DAT_00435db0 + iVar4 + 4);
            *(undefined4 *)((int)param_1 + iVar2 * 8 + 0x22994) =
                 *(undefined4 *)(DAT_00435db0 + iVar4);
            *(int *)((int)param_1 + iVar2 * 8 + 0x22998) = iVar1;
          }
        }
        else if ((iVar2 == 1) && (iVar2 = FUN_004198c0((int)param_1), iVar2 != -1)) {
          FUN_0040ec50(param_1,0x3fc,DAT_00435db0 + iVar4 + 4);
          *(undefined4 *)((int)param_1 + iVar2 * 8 + 0x23194) =
               *(undefined4 *)(DAT_00435db0 + iVar4);
          *(int *)((int)param_1 + iVar2 * 8 + 0x23198) = iVar1;
        }
      }
      iVar4 = iVar4 + 0x220;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_00435dc8);
  }
  FUN_0040eca0(param_1,0x4aa,0x435dcc);
  return;
}



/* 00419110  FUN_00419110  371 bytes, 1 callers */

void __thiscall FUN_00419110(void *this,WPARAM param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int nIDButton;
  
  SendDlgItemMessageA(*(HWND *)((int)this + 4),0x3fb,0x186,param_1,0);
  if (*(int *)((int)this + param_1 * 8 + 0x22994) != -1) {
    FUN_0040eca0(this,0x46b,0x43250c);
    iVar4 = *(int *)((int)this + param_1 * 8 + 0x22998);
    if (*(char *)((int)this + 0x22588) != '\0') {
      iVar3 = iVar4 * 0x220;
      piVar1 = (int *)(DAT_00435db0 + 0x110 + iVar3);
      if (*(int *)((int)this + 0x22590) < *piVar1) {
        *piVar1 = *(int *)((int)this + 0x22590);
      }
      uVar2 = *(uint *)((int)this + *(int *)(DAT_00435db0 + 0x110 + iVar3) * 4 + 0x22594);
      wsprintfA((LPSTR)((int)this + 0x1c),s__02dmin_02dsec_00433ec8,uVar2 & 0xff,uVar2 >> 8 & 0xff);
      FUN_0040eca0(this,0x471,(LPARAM)((int)this + 0x1c));
    }
    iVar4 = iVar4 * 0x220;
    nIDButton = 0;
    SetDlgItemInt(*(HWND *)((int)this + 4),0x46d,*(UINT *)(DAT_00435db0 + 0x110 + iVar4),0);
    iVar3 = *(int *)(DAT_00435db0 + 0x10c + iVar4);
    if (iVar3 == 0) {
      nIDButton = 0x468;
      CheckDlgButton(*(HWND *)((int)this + 4),0x46a,0);
      FUN_0040eca0(this,0x46b,DAT_00435db0 + iVar4 + 0x114);
    }
    else if (iVar3 == 2) {
      nIDButton = 0x46a;
      CheckDlgButton(*(HWND *)((int)this + 4),0x468,0);
    }
    FUN_0040ed80(this,0x46d,(uint)(*(int *)(DAT_00435db0 + 0x110 + iVar4) != 0));
    CheckDlgButton(*(HWND *)((int)this + 4),nIDButton,1);
  }
  return;
}



/* 00419290  FUN_00419290  117 bytes, 1 callers */

void __thiscall FUN_00419290(void *this,WPARAM param_1)

{
  SendDlgItemMessageA(*(HWND *)((int)this + 4),0x3fc,0x186,param_1,0);
  if (*(int *)((int)this + param_1 * 8 + 0x23194) != -1) {
    FUN_0040ed80(this,0x442,1);
    FUN_0040ed80(this,0x443,1);
    FUN_0040eca0(this,0x46c,
                 *(int *)((int)this + param_1 * 8 + 0x23198) * 0x220 + DAT_00435db0 + 0x114);
  }
  return;
}



/* 00419570  FUN_00419570  153 bytes, 0 callers */

void __fastcall FUN_00419570(void *param_1)

{
  int iVar1;
  WPARAM WVar2;
  
  wsprintfA((LPSTR)((int)param_1 + 900),s___mid___smf_00433f14);
  *(undefined4 *)((int)param_1 + 0x248) = 0;
  *(char **)((int)param_1 + 0x244) = s_MIDI_FILE_00433ef8;
  *(char **)((int)param_1 + 0x268) = s_Choose_a_MIDI_file__00433ee4;
  *(undefined4 *)((int)param_1 + 0x274) = 0;
  iVar1 = FUN_004196b0((int)param_1);
  if (iVar1 == 1) {
    WVar2 = FUN_0040ec30(param_1,0x3fb);
    if ((WVar2 != 0xffffffff) && (*(int *)((int)param_1 + WVar2 * 8 + 0x22994) != -1)) {
      wsprintfA((LPSTR)(*(int *)((int)param_1 + WVar2 * 8 + 0x22998) * 0x220 + DAT_00435db0 + 0x114)
                ,(LPSTR)((int)param_1 + 900));
      FUN_00419110(param_1,WVar2);
    }
  }
  return;
}



/* 00419610  FUN_00419610  159 bytes, 0 callers */

void __fastcall FUN_00419610(void *param_1)

{
  int iVar1;
  WPARAM WVar2;
  
  wsprintfA((LPSTR)((int)param_1 + 900),s___wav_00433f4c);
  *(char **)((int)param_1 + 0x244) = s_WAVE_FILE_00433f38;
  *(undefined4 *)((int)param_1 + 0x248) = 0;
  *(char **)((int)param_1 + 0x268) = s_Choose_a_WAVE_file__00433f24;
  *(undefined **)((int)param_1 + 0x274) = &DAT_00433f20;
  iVar1 = FUN_004196b0((int)param_1);
  if (iVar1 == 1) {
    WVar2 = FUN_0040ec30(param_1,0x3fc);
    if ((WVar2 != 0xffffffff) && (*(int *)((int)param_1 + WVar2 * 8 + 0x23194) != -1)) {
      wsprintfA((LPSTR)(*(int *)((int)param_1 + WVar2 * 8 + 0x23198) * 0x220 + DAT_00435db0 + 0x114)
                ,(LPSTR)((int)param_1 + 900));
      FUN_00419290(param_1,WVar2);
    }
  }
  return;
}



/* 004196b0  FUN_004196b0  142 bytes, 2 callers */

void __fastcall FUN_004196b0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  ((LPOPENFILENAMEA)(param_1 + 0x238))->lStructSize = 0x4c;
  *(undefined4 *)(param_1 + 0x240) = DAT_004344d0;
  *(undefined4 *)(param_1 + 0x23c) = uVar1;
  *(undefined4 *)(param_1 + 0x24c) = 0x100;
  *(int *)(param_1 + 0x254) = param_1 + 900;
  *(undefined4 *)(param_1 + 600) = 0x100;
  *(int *)(param_1 + 0x25c) = param_1 + 0x484;
  *(undefined4 *)(param_1 + 0x260) = 0x100;
  *(undefined4 *)(param_1 + 0x250) = 1;
  *(undefined4 *)(param_1 + 0x26c) = 0x1004;
  FUN_00409490((LPSTR)(param_1 + 0x1c),s_Sound__0043258c,&DAT_0043250c);
  *(LPSTR *)(param_1 + 0x264) = (LPSTR)(param_1 + 0x1c);
  GetOpenFileNameA((LPOPENFILENAMEA)(param_1 + 0x238));
  return;
}



/* 004197d0  FUN_004197d0  92 bytes, 0 callers */

void __fastcall FUN_004197d0(void *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_104 [260];
  
  uVar1 = FUN_0040edd0(param_1,0x4a8);
  FUN_0040ecc0(param_1,0x4aa,(LPARAM)local_104);
  iVar2 = FUN_0040d490(&DAT_00435db0,uVar1,local_104);
  if (iVar2 != 0) {
    DAT_004376b7 = (undefined1)uVar1;
    FUN_0040d050(&DAT_00435db0,uVar1);
  }
  FUN_0040eb70((int)param_1);
  return;
}



/* 00419830  FUN_00419830  111 bytes, 0 callers */

void __fastcall FUN_00419830(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int local_8;
  
  iVar2 = 0;
  if (0 < DAT_00435dc8) {
    local_8 = 0;
    piVar3 = (int *)(param_1 + 0x584);
    do {
      iVar2 = iVar2 + 1;
      FUN_0040ce60(&DAT_00435db0,*piVar3,piVar3[0x43]);
      piVar4 = piVar3;
      piVar5 = (int *)(DAT_00435db0 + local_8);
      for (iVar1 = 0x88; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        piVar5 = piVar5 + 1;
      }
      local_8 = local_8 + 0x220;
      piVar3 = piVar3 + 0x88;
    } while (iVar2 < DAT_00435dc8);
  }
  FUN_0040eb70(param_1);
  return;
}



/* 004198a0  FUN_004198a0  30 bytes, 1 callers */

int __fastcall FUN_004198a0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0x22994);
  do {
    if (*piVar2 == -1) {
      return iVar1;
    }
    piVar2 = piVar2 + 2;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x100);
  return -1;
}



/* 004198c0  FUN_004198c0  30 bytes, 1 callers */

int __fastcall FUN_004198c0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0x23194);
  do {
    if (*piVar2 == -1) {
      return iVar1;
    }
    piVar2 = piVar2 + 2;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x100);
  return -1;
}



/* 004198e0  FUN_004198e0  226 bytes, 1 callers */

undefined4 * __fastcall FUN_004198e0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_004199c2;
  *unaff_FS_OFFSET = &local_10;
  FUN_00427770(param_1);
  local_8 = 0;
  *param_1 = &PTR_FUN_00430650;
  wsprintfA((LPSTR)(param_1 + 0x53),s_Code1_00432460);
  wsprintfA((LPSTR)(param_1 + 0x12),s_Progress_Window_00433f54);
  param_1[0x9f] = 0;
  param_1[0x9e] = 0x54400000;
  param_1[8] = 0xb0;
  param_1[9] = 0xb0;
  iVar1 = GetSystemMetrics(8);
  param_1[7] = param_1[7] + iVar1 * 2;
  iVar1 = GetSystemMetrics(7);
  param_1[6] = param_1[6] + iVar1 * 2;
  wsprintfA((LPSTR)(param_1 + 0x12),s_Progress_Window_00433f54);
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = param_1[6] + param_1[8];
  param_1[0x11] = param_1[9] + param_1[7];
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = param_1[6] + param_1[8];
  param_1[0xd] = param_1[9] + param_1[7];
  DAT_004344f4 = param_1;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}



/* 004199e0  FUN_004199e0  30 bytes, 0 callers */

undefined4 * __thiscall FUN_004199e0(void *this,byte param_1)

{
  FUN_00419a00(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 00419a00  FUN_00419a00  71 bytes, 1 callers */

void __fastcall FUN_00419a00(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00419a47;
  *param_1 = &PTR_FUN_00430650;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  DAT_004344f4 = 0;
  FUN_00419a51();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 00419a51  FUN_00419a51  8 bytes, 1 callers */

void FUN_00419a51(void)

{
  int unaff_EBP;
  
  FUN_00427820(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 0041a160  FUN_0041a160  29 bytes, 0 callers */

void __fastcall FUN_0041a160(int *param_1)

{
  if ((char)param_1[0xe1] == '\0') {
    ClipCursor((RECT *)0x0);
    FUN_0041a3d0(param_1);
  }
  return;
}



/* 0041a180  FUN_0041a180  40 bytes, 0 callers */

void __fastcall FUN_0041a180(int param_1)

{
  tagPOINT local_8;
  
  if (*(char *)(param_1 + 900) == '\0') {
    GetCursorPos(&local_8);
    FUN_0040a980(&local_8.x);
  }
  return;
}



/* 0041a1b0  FUN_0041a1b0  536 bytes, 0 callers */

void __fastcall FUN_0041a1b0(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  tagRECT local_10;
  
  uVar3 = param_1[5] & 0xffff;
  uVar1 = (uint)param_1[5] >> 0x10;
  iVar2 = GetSystemMetrics(7);
  if (uVar3 < 0x18) {
LAB_0041a365:
    if (((0x60 < uVar3) && (uVar3 < 0x70)) && ((0x28 < uVar1 && (uVar1 < 0x38)))) {
      GetWindowRect((HWND)param_1[2],&local_10);
      local_10.right = local_10.left + 0x70;
      local_10.bottom = local_10.top + 0x38;
      local_10.left = local_10.left + 0x66;
      local_10.top = local_10.top + 0x2e;
      ClipCursor(&local_10);
      return;
    }
    FUN_00425970((int)param_1);
    return;
  }
  if (((iVar2 + 0x90 < (int)uVar3) || (uVar1 < 0x10)) || (0x20 < uVar1)) {
    if (((uVar3 < 0x18) || (iVar2 + 0x90 < (int)uVar3)) || ((uVar1 < 0x90 || (0xa0 < uVar1))))
    goto LAB_0041a365;
    GetWindowRect((HWND)param_1[2],&local_10);
    local_10.left = local_10.left + 0x1c;
    local_10.right = local_10.right + -0x20;
    local_10.bottom = local_10.top + 0xa0;
    local_10.top = local_10.top + 0x98;
    ClipCursor(&local_10);
    if (uVar3 < 0x18) {
      uVar3 = 0x18;
    }
    if (0xdc < uVar3) {
      uVar3 = 0xdc;
    }
    iVar2 = uVar3 - 0x18;
    if (0x7c < iVar2) {
      iVar2 = 0x7c;
    }
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    DAT_00437698 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
    if (0x1e < DAT_00437698) {
      DAT_00437698 = 0x1e;
    }
  }
  else {
    GetWindowRect((HWND)param_1[2],&local_10);
    local_10.left = local_10.left + 0x1c;
    local_10.right = local_10.right + -0x20;
    local_10.bottom = local_10.top + 0x20;
    local_10.top = local_10.top + 0x18;
    ClipCursor(&local_10);
    if (uVar3 < 0x18) {
      uVar3 = 0x18;
    }
    if (0xdc < uVar3) {
      uVar3 = 0xdc;
    }
    iVar2 = uVar3 - 0x18;
    if (0x7c < iVar2) {
      iVar2 = 0x7c;
    }
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    iVar2 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
    if (0x1e < iVar2) {
      iVar2 = 0x1e;
    }
    *(char *)(DAT_00434534 + 0x1c + (uint)DAT_004365cd * 0x38) = (char)iVar2;
    DAT_0043769c = 0;
    *(undefined1 *)(param_1 + 0xe9) = 1;
  }
  (**(code **)(*param_1 + 0x18))();
  InvalidateRect((HWND)param_1[2],(RECT *)0x0,0);
  UpdateWindow((HWND)param_1[2]);
  return;
}



/* 0041a3d0  FUN_0041a3d0  72 bytes, 1 callers */

void __fastcall FUN_0041a3d0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1[5] & 0xffff;
  uVar1 = (uint)param_1[5] >> 0x10;
  if ((((0x60 < uVar2) && (uVar2 < 0x70)) && (0x28 < uVar1)) && (uVar1 < 0x38)) {
    DAT_0043769c = DAT_0043769c + 1 & 1;
  }
  InvalidateRect((HWND)param_1[2],(RECT *)0x0,0);
  (**(code **)(*param_1 + 0x18))();
  return;
}



/* 0041a420  FUN_0041a420  93 bytes, 1 callers */

undefined4 * __fastcall FUN_0041a420(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041a47d;
  *unaff_FS_OFFSET = &local_10;
  FUN_00425bd0(param_1 + 2);
  local_8 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  wsprintfA((LPSTR)(param_1 + 5),&DAT_00433f6c);
  *unaff_FS_OFFSET = local_10;
  return param_1;
}



/* 0041a4fb  FUN_0041a4fb  11 bytes, 0 callers */

void FUN_0041a4fb(void)

{
  int unaff_EBP;
  
  FUN_00425be0((int *)(*(int *)(unaff_EBP + -0x10) + 8));
  return;
}



/* 0041a510  FUN_0041a510  268 bytes, 1 callers */

undefined4 __thiscall FUN_0041a510(void *this,LPCSTR param_1)

{
  int *this_00;
  UINT UVar1;
  int iVar2;
  LPSTR lpReturnedString;
  uint uVar3;
  uint uVar4;
  CHAR local_104 [260];
  
  UVar1 = GetPrivateProfileIntA(s_entry_00432618,&DAT_00433f98,0,param_1);
  if ((UVar1 != 0) && (UVar1 < 0x35)) {
    this_00 = (int *)((int)this + 8);
    *(UINT *)((int)this + 4) = UVar1;
    FUN_00425c80(this_00);
    FUN_00425c20(this_00);
    iVar2 = FUN_00425c00(this_00,UVar1 * 0x208);
    *(int *)this = iVar2;
    if (iVar2 != 0) {
      GetPrivateProfileStringA
                (s_entry_00432618,s_QESTNAME_00433f84,s_no_qest_00433f90,(LPSTR)((int)this + 0x14),
                 0x104,param_1);
      if (*(int *)((int)this + 4) != 0) {
        iVar2 = 0;
        uVar3 = 0;
        do {
          uVar4 = uVar3 + 1;
          wsprintfA(local_104,&DAT_00432608,uVar3);
          GetPrivateProfileStringA
                    (local_104,&DAT_00433f7c,&DAT_00433f7c,(LPSTR)(*(int *)this + iVar2 + 0x104),
                     0x104,param_1);
          lpReturnedString = (LPSTR)(*(int *)this + iVar2);
          iVar2 = iVar2 + 0x208;
          GetPrivateProfileStringA
                    (local_104,&DAT_00432620,s_no_name_00432628,lpReturnedString,0x104,param_1);
          uVar3 = uVar4;
        } while (uVar4 < *(uint *)((int)this + 4));
      }
      return 1;
    }
  }
  return 0;
}



/* 0041a620  FUN_0041a620  43 bytes, 3 callers */

char * __thiscall FUN_0041a620(void *this,int param_1)

{
  if ((*(int *)this != 0) && (param_1 < *(int *)((int)this + 4))) {
    return (char *)(*(int *)this + 0x104 + param_1 * 0x208);
  }
  return s_Error_00433f9c;
}



/* 0041a650  FUN_0041a650  39 bytes, 9 callers */

char * __thiscall FUN_0041a650(void *this,int param_1)

{
  if ((*(int *)this != 0) && (param_1 < *(int *)((int)this + 4))) {
    return (char *)(*(int *)this + param_1 * 0x208);
  }
  return s_Error_00433f9c;
}



/* 0041a680  FUN_0041a680  373 bytes, 7 callers */

void __cdecl FUN_0041a680(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  undefined3 extraout_var;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte local_e;
  byte local_d;
  undefined1 local_8;
  
  local_d = 0;
  if ((((param_1 < 0x2f) && (param_2 < 0x2f)) && (0 < param_1)) && (0 < param_2)) {
    DAT_004358e0._0_1_ = (undefined1)param_1;
    DAT_004359e0 = (undefined1)param_2;
    local_e = 1;
    *(undefined4 *)(DAT_0043453c + 8 + (param_1 * 0x30 + param_2) * 0x18) = 0;
    do {
      uVar5 = (uint)local_d;
      iVar9 = 0;
      local_d = local_d + 1;
      uVar4 = (uint)*(byte *)((int)&DAT_004358e0 + uVar5);
      bVar2 = (&DAT_004359e0)[uVar5];
      do {
        iVar6 = (int)(char)(&DAT_00434401)[iVar9] + uVar4;
        iVar7 = (uint)bVar2 + (int)(char)(&DAT_00434411)[iVar9];
        bVar3 = FUN_0041ebb0(iVar6,iVar7);
        if (CONCAT31(extraout_var,bVar3) != 0) {
          iVar1 = (iVar6 * 0x30 + iVar7) * 0x18;
          iVar8 = DAT_0043453c + iVar1;
          if (0x1ef < *(uint *)(iVar8 + 8)) {
            local_8 = (undefined1)iVar6;
            uVar5 = (uint)local_e;
            local_e = local_e + 1;
            *(undefined1 *)((int)&DAT_004358e0 + uVar5) = local_8;
            iVar6 = DAT_0043453c;
            (&DAT_004359e0)[uVar5] = (char)iVar7;
            iVar6 = *(int *)(iVar6 + 8 + (uVar4 * 0x30 + (uint)bVar2) * 0x18) + 1;
            if (0x1ef < iVar6) {
              *(undefined1 *)(iVar8 + 4) = 1;
              iVar6 = 0x1f0;
            }
            *(int *)(DAT_0043453c + 8 + iVar1) = iVar6;
          }
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < 4);
    } while (local_e != local_d);
  }
  return;
}



/* 0041a800  FUN_0041a800  177 bytes, 1 callers */

undefined4 __cdecl FUN_0041a800(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  FUN_00405360();
  iVar1 = param_1 * 0x224;
  FUN_004056f0((byte *)(DAT_00434538 + iVar1 + 2));
  FUN_00405510(param_1);
  FUN_0041a680(param_2,param_3);
  iVar2 = FUN_00405000(param_1,(uint)*(byte *)(DAT_00434538 + iVar1 + 2),
                       (uint)*(byte *)(DAT_00434538 + iVar1 + 3));
  if (iVar2 == 0) {
    return 0;
  }
  switch(*(byte *)(DAT_00434538 + 0xd + iVar1) & 0xf) {
  case 6:
  case 7:
  case 9:
  case 10:
  case 0xb:
    FUN_004051b0(param_1);
  }
  *(undefined1 *)(DAT_00434538 + 0xf + iVar1) = 4;
  return 1;
}



/* 0041a8d0  FUN_0041a8d0  70 bytes, 4 callers */

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



/* 0041a920  FUN_0041a920  205 bytes, 4 callers */

undefined4 FUN_0041a920(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (uint)*(byte *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18);
  iVar2 = uVar3 - 0x14;
  if ((iVar2 < 4) && (-1 < iVar2)) {
    iVar2 = FUN_0041a8d0(*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 0xb);
    if (iVar2 == 1) {
      return 1;
    }
  }
  else if (uVar3 - DAT_00437580 == 8) {
    iVar2 = FUN_0041a8d0(*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 0xb);
    if (iVar2 == 1) {
      return 1;
    }
  }
  puVar1 = (uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
  uVar3 = *puVar1;
  uVar4 = (uVar3 >> 8) + 1;
  if (uVar3 <= uVar4) {
    FUN_00420aa0(DAT_0043756c,4);
    return 0;
  }
  *puVar1 = uVar3 - uVar4;
  return 1;
}



/* 0041a9f0  FUN_0041a9f0  63 bytes, 15 callers */

void __cdecl FUN_0041a9f0(int param_1,int param_2,int param_3)

{
  *(undefined4 *)(DAT_00434538 + 0x18 + param_1 * 0x224) = 0x1f0;
  FUN_00405360();
  FUN_00405510(param_1);
  FUN_0041a680(param_2,param_3);
  return;
}



/* 0041aa30  FUN_0041aa30  184 bytes, 1 callers */

void FUN_0041aa30(void)

{
  longlong lVar1;
  ulonglong uVar2;
  
  DAT_00436418 = FUN_0041cdf0();
  DAT_00436414 = FUN_0041ceb0((uint)DAT_00436400);
  if (DAT_004345f4 != 0) {
    FUN_004283c7();
  }
  lVar1 = __ftol();
  DAT_0043641c = (float)(int)lVar1 * 0.01;
  uVar2 = __ftol();
  DAT_00436420 = (int)((uVar2 & 0xffffffff) / 100);
  return;
}



/* 0041aaf0  FUN_0041aaf0  224 bytes, 1 callers */

undefined4 FUN_0041aaf0(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  bool bVar5;
  float10 fVar6;
  longlong lVar7;
  
  iVar4 = 0;
  DAT_00436428 = 0;
  puVar3 = (uint *)(DAT_00434534 + 0x14);
  DAT_00436424 = 0;
  do {
    uVar1 = *puVar3;
    if (((char)iVar4 != DAT_00436400) &&
       (DAT_00436428 = *puVar3 + DAT_00436428, uVar1 = DAT_00436424, DAT_00436428 == 0xffffffff)) {
      DAT_00436428 = 0xffffffff;
    }
    DAT_00436424 = uVar1;
    puVar3 = puVar3 + 0xe;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  DAT_00436430 = 0;
  bVar5 = DAT_00436410 != 0;
  if (DAT_004345f4 == 0) {
    fVar6 = (float10)DAT_00436428 / (float10)DAT_00436424;
  }
  else {
    fVar6 = FUN_004283c7();
  }
  uVar2 = 0;
  DAT_0043642c = (float)(fVar6 * (float10)100.0);
  if ((bVar5) && (0x42c80000 < (int)DAT_0043642c)) {
    lVar7 = __ftol();
    DAT_00436430 = (uint)lVar7;
    uVar2 = 500;
    if (500 < DAT_00436430) {
      DAT_00436430 = 500;
    }
  }
  return uVar2;
}



/* 0041abd0  FUN_0041abd0  25 bytes, 7 callers */

int __cdecl FUN_0041abd0(int param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    uVar1 = FUN_0041abf0();
    return (int)uVar1 % param_1;
  }
  return 0;
}



/* 0041abf0  FUN_0041abf0  22 bytes, 3 callers */

uint FUN_0041abf0(void)

{
  int iVar1;
  
  iVar1 = _rand();
  return iVar1 + (uint)DAT_004365e8 & 0xffff;
}



/* 0041ac10  FUN_0041ac10  44 bytes, 5 callers */

int __cdecl FUN_0041ac10(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_3 < param_1) {
    iVar1 = param_1 - param_3;
  }
  else {
    iVar1 = param_3 - param_1;
  }
  if (param_4 < param_2) {
    return (param_2 - param_4) + iVar1;
  }
  return (param_4 - param_2) + iVar1;
}



/* 0041ac40  FUN_0041ac40  65 bytes, 5 callers */

void FUN_0041ac40(void)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = DAT_0043756c * 0x224 + DAT_00434538;
  uVar1 = FUN_0041ac90(DAT_0043644c,DAT_00436450,(uint)*(byte *)(iVar2 + 2),
                       (uint)*(byte *)(iVar2 + 3));
  *(undefined1 *)(iVar2 + 0xc) = uVar1;
  return;
}



/* 0041ac90  FUN_0041ac90  41 bytes, 1 callers */

undefined1 __cdecl FUN_0041ac90(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  
  if (param_4 == param_2) {
    if (param_3 == param_1) {
      uVar1 = 6;
    }
    else {
      uVar1 = 0;
      if (param_1 < param_3) {
        return 4;
      }
    }
  }
  else {
    uVar1 = 2;
    if (param_2 < param_4) {
      return 6;
    }
  }
  return uVar1;
}



/* 0041acc0  FUN_0041acc0  200 bytes, 3 callers */

void __cdecl FUN_0041acc0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_8;
  
  local_8 = -1;
  do {
    iVar4 = -1;
    iVar3 = local_8 + param_2;
    do {
      iVar1 = iVar4 + param_1;
      if ((((0 < param_1) || (param_1 < 0x2f)) || (0 < param_2)) || (param_2 < 0x2f)) {
        uVar2 = (uint)*(byte *)(DAT_0043453c + 0x10 + (iVar1 * 0x30 + iVar3) * 0x18);
        if (((int)(uVar2 - 0x30) < 0) || (0x2f < (int)(uVar2 - 0x30))) {
          if (((int)(uVar2 - 0x20) < 0) || (0xf < (int)(uVar2 - 0x20))) {
            if (((int)(uVar2 - 1) < 0) || (3 < (int)(uVar2 - 1))) {
              if ((-1 < (int)(uVar2 - 0x60)) && ((int)(uVar2 - 0x60) < 0x10)) {
                FUN_0041b050(iVar1,iVar3);
              }
            }
            else {
              FUN_0041afa0(iVar1,iVar3);
            }
          }
          else {
            FUN_0041af10(iVar1,iVar3);
          }
        }
        else {
          FUN_0041adf0(iVar1,iVar3);
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    local_8 = local_8 + 1;
  } while (local_8 < 2);
  return;
}



/* 0041ad90  FUN_0041ad90  86 bytes, 4 callers */

void FUN_0041ad90(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  FUN_00405330();
  do {
    iVar2 = DAT_00434538 + iVar3;
    if (((*(byte *)(iVar2 + 0x10) & 0x80) == 0) && (*(int *)(iVar2 + 0x18) == 0x1f0)) {
      cVar1 = *(char *)(iVar2 + 0xd);
      if ((cVar1 == '\0') || ((*(char *)(iVar2 + 4) != DAT_004365cd && (cVar1 == '\x02')))) {
        *(char *)(iVar2 + 0xd) = '\x01';
      }
    }
    iVar3 = iVar3 + 0x224;
  } while (iVar3 < 0x8900);
  return;
}



/* 0041adf0  FUN_0041adf0  285 bytes, 1 callers */

void __cdecl FUN_0041adf0(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  bVar1 = FUN_0041f3f0(param_1 + -1,param_2);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    iVar2 = 0x80;
  }
  uVar3 = iVar2 >> 1;
  iVar2 = param_2 + -1;
  bVar1 = FUN_0041f3f0(param_1 + -1,iVar2);
  if (CONCAT31(extraout_var_00,bVar1) == 0) {
    uVar3 = uVar3 | 0x80;
  }
  uVar3 = (int)uVar3 >> 1;
  bVar1 = FUN_0041f3f0(param_1,iVar2);
  if (CONCAT31(extraout_var_01,bVar1) == 0) {
    uVar3 = uVar3 | 0x80;
  }
  uVar3 = (int)uVar3 >> 1;
  bVar1 = FUN_0041f3f0(param_1 + 1,iVar2);
  if (CONCAT31(extraout_var_02,bVar1) == 0) {
    uVar3 = uVar3 | 0x80;
  }
  uVar3 = (int)uVar3 >> 1;
  bVar1 = FUN_0041f3f0(param_1 + 1,param_2);
  if (CONCAT31(extraout_var_03,bVar1) == 0) {
    uVar3 = uVar3 | 0x80;
  }
  uVar3 = (int)uVar3 >> 1;
  iVar2 = param_2 + 1;
  bVar1 = FUN_0041f3f0(param_1 + 1,iVar2);
  if (CONCAT31(extraout_var_04,bVar1) == 0) {
    uVar3 = uVar3 | 0x80;
  }
  uVar3 = (int)uVar3 >> 1;
  bVar1 = FUN_0041f3f0(param_1,iVar2);
  if (CONCAT31(extraout_var_05,bVar1) == 0) {
    uVar3 = uVar3 | 0x80;
  }
  uVar3 = (int)uVar3 >> 1;
  bVar1 = FUN_0041f3f0(param_1 + -1,iVar2);
  if (CONCAT31(extraout_var_06,bVar1) == 0) {
    uVar3 = uVar3 | 0x80;
  }
  if (param_1 == 0) {
    uVar3 = uVar3 & 0x7c;
  }
  if (param_1 == 0x2f) {
    uVar3 = uVar3 & 199;
  }
  if (param_2 == 0) {
    uVar3 = uVar3 & 0xf1;
  }
  if (param_2 == 0x2f) {
    uVar3 = uVar3 & 0x1f;
  }
  *(undefined1 *)(DAT_0043453c + 0x10 + (param_1 * 0x30 + param_2) * 0x18) = (&DAT_00434300)[uVar3];
  return;
}



/* 0041af10  FUN_0041af10  137 bytes, 1 callers */

void __cdecl FUN_0041af10(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = 0;
  if (param_1 != 0) {
    iVar1 = FUN_0041f460(param_1 + -1,param_2);
    if (iVar1 == 0) {
      bVar2 = 1;
    }
  }
  if (param_2 != 0) {
    iVar1 = FUN_0041f460(param_1,param_2 + -1);
    if (iVar1 == 0) {
      bVar2 = bVar2 | 2;
    }
  }
  if (param_1 < 0x2f) {
    iVar1 = FUN_0041f460(param_1 + 1,param_2);
    if (iVar1 == 0) {
      bVar2 = bVar2 | 4;
    }
  }
  if (param_2 < 0x2f) {
    iVar1 = FUN_0041f460(param_1,param_2 + 1);
    if (iVar1 == 0) {
      bVar2 = bVar2 | 8;
    }
  }
  *(byte *)(DAT_0043453c + 0x10 + (param_1 * 0x30 + param_2) * 0x18) = bVar2 + 0x20;
  return;
}



/* 0041afa0  FUN_0041afa0  165 bytes, 1 callers */

void __cdecl FUN_0041afa0(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  
  bVar4 = 0;
  if ((param_2 != 0) &&
     ((bVar2 = *(byte *)(DAT_0043453c + -8 + (param_1 * 0x30 + param_2) * 0x18), bVar2 == 0 ||
      (4 < bVar2)))) {
    bVar4 = 1;
  }
  if ((param_2 != 0x2f) &&
     ((bVar2 = *(byte *)(DAT_0043453c + 0x28 + (param_1 * 0x30 + param_2) * 0x18), bVar2 == 0 ||
      (4 < bVar2)))) {
    bVar4 = bVar4 | 2;
  }
  iVar1 = (param_1 * 0x30 + param_2) * 0x18;
  iVar3 = DAT_0043453c + iVar1;
  bVar2 = *(byte *)(iVar3 + 0x10);
  if ((bVar2 != 0) && (bVar2 < 5)) {
    *(undefined4 *)(iVar3 + 0xc) = 100;
  }
  *(byte *)(DAT_0043453c + 0x10 + iVar1) = bVar4 + 1;
  return;
}



/* 0041b050  FUN_0041b050  137 bytes, 1 callers */

void __cdecl FUN_0041b050(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = 0;
  if (param_1 != 0) {
    iVar1 = FUN_0041f380(param_1 + -1,param_2);
    if (iVar1 == 0) {
      bVar2 = 1;
    }
  }
  if (param_2 != 0) {
    iVar1 = FUN_0041f380(param_1,param_2 + -1);
    if (iVar1 == 0) {
      bVar2 = bVar2 | 2;
    }
  }
  if (param_1 != 0x2f) {
    iVar1 = FUN_0041f380(param_1 + 1,param_2);
    if (iVar1 == 0) {
      bVar2 = bVar2 | 4;
    }
  }
  if (param_2 != 0x2f) {
    iVar1 = FUN_0041f380(param_1,param_2 + 1);
    if (iVar1 == 0) {
      bVar2 = bVar2 | 8;
    }
  }
  *(byte *)(DAT_0043453c + 0x10 + (param_1 * 0x30 + param_2) * 0x18) = bVar2 + 0x60;
  return;
}



/* 0041b0e0  FUN_0041b0e0  82 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041b0e0(void)

{
  _DAT_00436434 = DAT_00436404;
  if (DAT_004365a0 != 0) {
    _DAT_00436434 = DAT_00436404 - *(int *)(&DAT_004369d4 + DAT_004365a0 * 0x38);
  }
  if ((&DAT_00436a0c)[DAT_004365a0 * 0xe] != 0) {
    DAT_00436438 = DAT_00436404 - (&DAT_00436a0c)[DAT_004365a0 * 0xe];
  }
  return;
}



/* 0041b140  FUN_0041b140  244 bytes, 1 callers */

undefined4 FUN_0041b140(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = DAT_004365a0;
  uVar2 = DAT_00436430;
  uVar5 = 0;
  DAT_0043643c = 0;
  DAT_0043643d = 0;
  if (DAT_00436404 != 0) {
    iVar1 = DAT_004365a0 * 0x38;
    DAT_0043643d = (&DAT_00436a0c)[DAT_004365a0 * 0xe] != 0;
    if (DAT_00436404 <= (uint)(&DAT_00436a0c)[DAT_004365a0 * 0xe]) {
      return 0;
    }
    DAT_0043643c = 1;
    if ((!(bool)DAT_0043643d) && (DAT_00436a00 <= DAT_004365a0)) {
      DAT_00436a00 = DAT_00436a00 + 1;
    }
    (&DAT_00436a08)[DAT_004365a0 * 0xe] = DAT_004365c8;
    uVar3 = DAT_0043641c;
    (&DAT_00436a18)[iVar4 * 0xe] = uVar2;
    uVar5 = DAT_00436418;
    (&DAT_00436a10)[iVar4 * 0xe] = uVar3;
    uVar2 = DAT_00436414;
    *(undefined4 *)(&DAT_00436a34 + iVar1) = uVar5;
    uVar5 = DAT_00436428;
    *(undefined4 *)(&DAT_00436a30 + iVar1) = uVar2;
    uVar2 = DAT_00436424;
    *(undefined4 *)(&DAT_00436a3c + iVar1) = uVar5;
    uVar5 = DAT_00436420;
    *(undefined4 *)(&DAT_00436a38 + iVar1) = uVar2;
    uVar2 = DAT_00436408;
    (&DAT_00436a28)[iVar4 * 0xe] = uVar5;
    uVar5 = DAT_00436410;
    *(undefined4 *)(&DAT_00436a2c + iVar1) = uVar2;
    uVar2 = DAT_0043642c;
    (&DAT_00436a20)[iVar4 * 0xe] = uVar5;
    *(undefined4 *)(&DAT_00436a14 + iVar1) = uVar2;
    FUN_0041b240();
    uVar5 = 1;
  }
  return uVar5;
}



/* 0041b240  FUN_0041b240  304 bytes, 2 callers */

void FUN_0041b240(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  ulonglong uVar5;
  
  if (DAT_00436a00 != 0) {
    iVar3 = 0;
    iVar4 = 0;
    if (0 < DAT_00436a00) {
      piVar2 = &DAT_00436a0c;
      do {
        iVar4 = iVar4 + 1;
        piVar2[5] = (iVar3 + 3000) - piVar2[-1];
        uVar5 = __ftol();
        piVar2[7] = (int)((uVar5 & 0xffffffff) / 100);
        *piVar2 = 0;
        *piVar2 = piVar2[5];
        iVar1 = piVar2[5] + piVar2[3];
        *piVar2 = iVar1;
        iVar1 = iVar1 - piVar2[7];
        *piVar2 = iVar1;
        piVar2[6] = iVar1 - iVar3;
        iVar3 = *piVar2;
        piVar2 = piVar2 + 0xe;
      } while (iVar4 < DAT_00436a00);
    }
    if (DAT_004376cc - iVar4 == 1) {
      if ((&DAT_00436a08)[iVar4 * 0xe] != 0) {
        (&DAT_00436a20)[iVar4 * 0xe] = (iVar3 + 3000) - (&DAT_00436a08)[iVar4 * 0xe];
        uVar5 = __ftol();
        (&DAT_00436a28)[iVar4 * 0xe] = (int)((uVar5 & 0xffffffff) / 100);
        (&DAT_00436a0c)[iVar4 * 0xe] = 0;
        (&DAT_00436a0c)[iVar4 * 0xe] = (&DAT_00436a20)[iVar4 * 0xe];
        iVar1 = (&DAT_00436a20)[iVar4 * 0xe] + (&DAT_00436a18)[iVar4 * 0xe];
        (&DAT_00436a0c)[iVar4 * 0xe] = iVar1;
        iVar1 = iVar1 - (&DAT_00436a28)[iVar4 * 0xe];
        (&DAT_00436a0c)[iVar4 * 0xe] = iVar1;
        (&DAT_00436a24)[iVar4 * 0xe] = iVar1 - iVar3;
      }
    }
  }
  return;
}



/* 0041b370  FUN_0041b370  381 bytes, 4 callers */

void FUN_0041b370(void)

{
  uint *puVar1;
  int *piVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  do {
    iVar5 = iVar5 + 0x38;
    *(undefined4 *)(DAT_00434534 + -8 + iVar5) = 0;
    *(undefined4 *)(DAT_00434534 + -0x14 + iVar5) = 0;
    *(undefined4 *)(DAT_00434534 + -0x10 + iVar5) = 0;
    *(undefined4 *)(DAT_00434534 + -0xc + iVar5) = 0;
  } while (iVar5 < 0x118);
  iVar5 = 0;
  do {
    bVar3 = *(byte *)(DAT_0043453c + 0x10 + iVar5);
    if (bVar3 == 5) {
      *(int *)(DAT_00434534 + 0xf0) =
           *(int *)(DAT_00434534 + 0xf0) + *(int *)(DAT_0043453c + iVar5 + 0xc);
    }
    else {
      iVar6 = bVar3 - 8;
      if ((iVar6 < 4) && (-1 < iVar6)) {
        puVar1 = (uint *)(DAT_00434534 + 0x30 + iVar6 * 0x38);
        uVar4 = *(int *)(DAT_0043453c + iVar5 + 0xc) + *puVar1;
        *puVar1 = uVar4;
        if (99999 < uVar4) {
          *puVar1 = 100000;
        }
        piVar2 = (int *)(DAT_00434534 + 0x2c + iVar6 * 0x38);
        *piVar2 = *piVar2 + 1;
      }
    }
    iVar5 = iVar5 + 0x18;
  } while (iVar5 < 0xd800);
  iVar5 = 0;
  do {
    iVar6 = DAT_00434538 + iVar5;
    if (((*(byte *)(iVar6 + 0x10) & 0x80) == 0) && ((*(byte *)(iVar6 + 0xd) & 0x20) == 0)) {
      puVar1 = (uint *)(DAT_00434534 + 0x28 + (uint)*(byte *)(iVar6 + 4) * 0x38);
      uVar4 = *(int *)(iVar6 + 8) + *puVar1;
      *puVar1 = uVar4;
      if (99999 < uVar4) {
        *puVar1 = 100000;
      }
      piVar2 = (int *)(DAT_00434534 + 0x24 + (uint)*(byte *)(DAT_00434538 + 4 + iVar5) * 0x38);
      *piVar2 = *piVar2 + 1;
    }
    iVar5 = iVar5 + 0x224;
  } while (iVar5 < 0x8900);
  iVar5 = 0;
  do {
    iVar6 = DAT_00434534 + iVar5;
    uVar4 = *(int *)(iVar6 + 0x28) + *(int *)(iVar6 + 0x30);
    *(undefined4 *)(iVar6 + 0x10) = 100000;
    if (uVar4 < 0x186a1) {
      *(uint *)(iVar6 + 0x10) = uVar4;
    }
    iVar5 = iVar5 + 0x38;
  } while (iVar5 < 0x118);
  iVar5 = 0;
  do {
    if (*(int *)(DAT_00434534 + iVar5 + 0x10) == 0) {
      *(undefined1 *)(DAT_00434534 + iVar5 + 0x1f) = 4;
      puVar1 = (uint *)(DAT_00434534 + 4 + iVar5);
      *puVar1 = *puVar1 | 0x10;
    }
    iVar5 = iVar5 + 0x38;
  } while (iVar5 < 0xe0);
  return;
}



/* 0041b4f0  FUN_0041b4f0  43 bytes, 1 callers */

void FUN_0041b4f0(void)

{
  if (((byte)DAT_00435b1c & 1) == 0) {
    if (DAT_004365c8 < 999999) {
      DAT_004365c8 = DAT_004365c8 + 1;
    }
    if (DAT_004365c4 != 0) {
      DAT_004365c4 = DAT_004365c4 + -1;
    }
  }
  return;
}



/* 0041b520  FUN_0041b520  275 bytes, 3 callers */

uint __cdecl FUN_0041b520(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x224 + DAT_00434538;
  bVar1 = *(byte *)(iVar3 + 4);
  if (bVar1 == 4) {
    if ((*(byte *)(iVar3 + 0x10) & 2) != 0) {
      return (uint)(*(byte *)(iVar3 + 0xe) | 200);
    }
    return (uint)(*(byte *)(iVar3 + 0xc) & 6) | (DAT_00435b1c & 2 | 0x180) >> 1;
  }
  if ((*(byte *)(iVar3 + 0x10) & 2) != 0) {
    return (-(uint)((*(byte *)(iVar3 + 0xd) & 0x20) == 0) & 0xfffffffc) + 0xa4 |
           (uint)*(byte *)(iVar3 + 0xe) | (uint)bVar1 << 3;
  }
  if ((*(byte *)(iVar3 + 0x10) & 1) != 0) {
    if ((*(byte *)(iVar3 + 0xd) & 0x20) == 0) {
      if (*(uint *)(iVar3 + 8) < 1000) {
        uVar2 = 0x80;
      }
      else {
        uVar2 = (-(uint)(*(uint *)(iVar3 + 8) < 10000) & 0xfffffffe) + 0x84;
      }
    }
    else {
      uVar2 = 0x86;
    }
    return uVar2 | (uint)bVar1 << 3 | (DAT_00435b1c & 2) >> 1;
  }
  if ((*(byte *)(iVar3 + 0xd) & 0x20) == 0) {
    if (*(uint *)(iVar3 + 8) < 1000) {
      uVar2 = 0;
    }
    else {
      uVar2 = (-(uint)(*(uint *)(iVar3 + 8) < 10000) & 0xffffffe0) + 0x40;
    }
  }
  else {
    uVar2 = 0x60;
  }
  return uVar2 | *(byte *)(iVar3 + 0xc) & 6 | (uint)bVar1 << 3 | (DAT_00435b1c & 2) >> 1;
}



/* 0041b640  FUN_0041b640  191 bytes, 2 callers */

void FUN_0041b640(void)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  
  uVar2 = FUN_0041cdf0();
  *(undefined4 *)(DAT_00434534 + 0x34) = 0;
  *(undefined4 *)(DAT_00434534 + 0x6c) = 0;
  *(undefined4 *)(DAT_00434534 + 0xa4) = 0;
  *(undefined4 *)(DAT_00434534 + 0xdc) = 0;
  if (ABS((float)uVar2) != 0.0) {
    iVar4 = 0;
    iVar3 = 0;
    while( true ) {
      iVar4 = iVar4 + 0x38;
      FUN_0041ceb0(iVar3);
      if (DAT_004345f4 != 0) {
        __adj_fdiv_m32((uint)(float)uVar2);
      }
      lVar5 = __ftol();
      fVar1 = (float)(int)lVar5 * 0.01;
      if (0xdf < iVar4) break;
      *(float *)(DAT_00434534 + -4 + iVar4) = fVar1;
      iVar3 = iVar3 + 1;
    }
    *(float *)(DAT_00434534 + -4 + iVar4) = fVar1;
  }
  return;
}



/* 0041b700  FUN_0041b700  362 bytes, 1 callers */

undefined4 * __fastcall FUN_0041b700(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar3;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041b86a;
  *unaff_FS_OFFSET = &local_10;
  FUN_00427770(param_1);
  local_8 = 0;
  *param_1 = &PTR_FUN_004306e0;
  param_1[0xe6] = (uint)DAT_004376a3;
  param_1[0xe7] = DAT_004376b0;
  wsprintfA((LPSTR)(param_1 + 0x12),s_Tool_Bar_00433fa8);
  param_1[0xe5] = 0;
  if (param_1[0xe6] == 0) {
    param_1[7] = 2;
    iVar1 = GetSystemMetrics(0x20);
    iVar2 = GetSystemMetrics(0);
    param_1[6] = iVar1 * 2 + iVar2;
    iVar1 = GetSystemMetrics(0);
    param_1[8] = iVar1;
    iVar1 = GetSystemMetrics(1);
    param_1[9] = iVar1;
    param_1[10] = 0;
    param_1[0xb] = 0;
    iVar1 = GetSystemMetrics(0);
    pcVar3 = s_Code5_00432448;
    param_1[0xc] = iVar1;
    param_1[0xd] = 0x1c;
    param_1[0x9e] = 0x54000000;
    param_1[0x9f] = 0;
  }
  else {
    iVar1 = GetSystemMetrics(0x21);
    iVar2 = GetSystemMetrics(0x33);
    param_1[7] = iVar1 * 2 + iVar2;
    iVar1 = GetSystemMetrics(0x20);
    param_1[6] = iVar1 * 2;
    iVar1 = GetSystemMetrics(0);
    param_1[8] = iVar1;
    iVar1 = GetSystemMetrics(1);
    param_1[9] = iVar1;
    param_1[10] = 0;
    param_1[0xb] = 0;
    iVar1 = GetSystemMetrics(0);
    pcVar3 = s_Code4_00432450;
    param_1[0xc] = iVar1;
    param_1[0x9e] = 0x54c40000;
    param_1[0x9f] = 0x80;
    param_1[0xd] = param_1[7] + 0x1c;
  }
  wsprintfA((LPSTR)(param_1 + 0x53),pcVar3);
  *unaff_FS_OFFSET = local_10;
  return param_1;
}



/* 0041b880  FUN_0041b880  30 bytes, 0 callers */

undefined4 * __thiscall FUN_0041b880(void *this,byte param_1)

{
  FUN_0041b8a0(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 0041b8a0  FUN_0041b8a0  152 bytes, 1 callers */

void __fastcall FUN_0041b8a0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  tagRECT local_24;
  undefined4 *local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_0041b938;
  *param_1 = &PTR_FUN_004306e0;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0;
  local_14 = param_1;
  FUN_0041bf30((int)param_1);
  if (DAT_004344e4 != 0) {
    GetClientRect(*(HWND *)(DAT_004344e4 + 8),&local_24);
  }
  InvalidateRect(*(HWND *)(DAT_004344e4 + 8),(RECT *)0x0,0);
  UpdateWindow(*(HWND *)(DAT_004344e4 + 8));
  local_8 = 0xffffffff;
  DAT_004376b0 = local_14[0xe7];
  FUN_0041b942();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 0041b942  FUN_0041b942  8 bytes, 1 callers */

void FUN_0041b942(void)

{
  int unaff_EBP;
  
  FUN_00427820(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 0041bab0  FUN_0041bab0  187 bytes, 0 callers */

undefined4 __fastcall FUN_0041bab0(int param_1)

{
  uint uVar1;
  undefined1 local_10 [16];
  
  uVar1 = *(uint *)(param_1 + 0xc);
  if (uVar1 < 0x112) {
    if (uVar1 == 0x111) {
      SendMessageA(*(HWND *)(DAT_004344e4 + 8),0x111,*(WPARAM *)(param_1 + 0x10),
                   *(LPARAM *)(param_1 + 0x14));
      return 1;
    }
    if (uVar1 == 0x4e) {
      if (*(int *)(*(int *)(param_1 + 0x14) + 8) != -0x208) {
        return 1;
      }
      FUN_0041c300(*(int *)(param_1 + 0x14));
      return 1;
    }
    return 0;
  }
  if (0x113 < uVar1) {
    if (uVar1 < 0x116) {
      return 1;
    }
    if (uVar1 == 0x232) {
      if (*(int *)(param_1 + 0x394) == 0) {
        return 1;
      }
      SendMessageA(*(HWND *)(*(int *)(param_1 + 0x394) + 0x28),0x427,
                   *(ushort *)(param_1 + 0x39c) | 0x10000,(LPARAM)local_10);
      return 1;
    }
  }
  return 0;
}



/* 0041bb70  FUN_0041bb70  706 bytes, 0 callers */

void __fastcall FUN_0041bb70(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar1 = *(int *)(param_1 + 0x10);
  piVar2 = *(int **)(param_1 + 0x14);
  iVar10 = piVar2[3];
  iVar8 = piVar2[2];
  iVar9 = piVar2[1];
  iVar11 = *piVar2;
  iVar4 = GetSystemMetrics(0x20);
  iVar3 = iVar4 * 2;
  iVar5 = GetSystemMetrics(0x21);
  iVar6 = GetSystemMetrics(0x33);
  iVar6 = iVar6 + iVar5 * 2;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(iVar1) {
  case 3:
    break;
  case 5:
    *piVar2 = (piVar2[2] -
              *(int *)(*(int *)(*(int *)(param_1 + 0x394) + 0x1c) + 8 +
                      *(int *)(param_1 + 0x39c) * 0x10)) + iVar4 * -2;
    piVar2[1] = (piVar2[3] -
                *(int *)(*(int *)(*(int *)(param_1 + 0x394) + 0x1c) + 0xc +
                        *(int *)(param_1 + 0x39c) * 0x10)) - iVar6;
    return;
  case 7:
    iVar8 = *(int *)(param_1 + 0x394);
    iVar11 = 1;
    *(undefined4 *)(param_1 + 0x39c) = 1;
    iVar10 = (iVar10 - iVar9) - (*(int *)(iVar8 + 0x14) + iVar6);
    if (1 < *(int *)(iVar8 + 0x24)) {
      iVar9 = 0x10;
      do {
        iVar4 = *(int *)(*(int *)(iVar8 + 0x1c) + 0xc + iVar9);
        if (iVar10 == iVar4) {
          *(int *)(param_1 + 0x39c) = iVar11;
          break;
        }
        if (iVar10 < iVar4) break;
        iVar9 = iVar9 + 0x10;
        iVar11 = iVar11 + 1;
        *(int *)(param_1 + 0x39c) = *(int *)(param_1 + 0x39c) + 1;
      } while (iVar11 < *(int *)(iVar8 + 0x24));
    }
    if (iVar1 == 3) {
      piVar2[1] = (piVar2[3] -
                  *(int *)(*(int *)(param_1 + 0x39c) * 0x10 + 0xc + *(int *)(iVar8 + 0x1c))) - iVar6
      ;
      piVar2[2] = *(int *)(*(int *)(*(int *)(param_1 + 0x394) + 0x1c) + 8 +
                          *(int *)(param_1 + 0x39c) * 0x10) + *piVar2 + iVar3;
      return;
    }
    if (iVar1 == 6) {
      piVar2[3] = *(int *)(*(int *)(param_1 + 0x39c) * 0x10 + 0xc + *(int *)(iVar8 + 0x1c)) +
                  piVar2[1] + iVar6;
      piVar2[2] = *(int *)(*(int *)(*(int *)(param_1 + 0x394) + 0x1c) + 8 +
                          *(int *)(param_1 + 0x39c) * 0x10) + *piVar2 + iVar3;
      return;
    }
    return;
  case 9:
                    /* WARNING: This code block may not be properly labeled as switch case */
    piVar2[2] = *(int *)(*(int *)(*(int *)(param_1 + 0x394) + 0x1c) + 8 +
                        *(int *)(param_1 + 0x39c) * 0x10) + *piVar2 + iVar3;
    piVar2[3] = *(int *)(*(int *)(*(int *)(param_1 + 0x394) + 0x1c) + 0xc +
                        *(int *)(param_1 + 0x39c) * 0x10) + piVar2[1] + iVar6;
  default:
    return;
  }
  iVar10 = *(int *)(*(int *)(param_1 + 0x394) + 0x24);
  iVar9 = iVar10;
  if (0 < iVar10) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x394) + 0x1c);
    piVar7 = (int *)(iVar10 * 0x10 + 8 + iVar5);
    do {
      if ((iVar8 - iVar11) + iVar4 * -2 <= *piVar7) {
        iVar8 = iVar10 + -1;
        if (0 < iVar8) {
          piVar7 = (int *)(iVar8 * 0x10 + 8 + iVar5);
          goto LAB_0041bc1c;
        }
        break;
      }
      iVar9 = iVar9 + -1;
      piVar7 = piVar7 + -4;
      iVar10 = iVar10 + -1;
    } while (0 < iVar10);
  }
  goto LAB_0041bc2a;
  while( true ) {
    iVar9 = iVar9 + -1;
    piVar7 = piVar7 + -4;
    iVar8 = iVar8 + -1;
    if (iVar8 < 1) break;
LAB_0041bc1c:
    if (*piVar7 != *(int *)(iVar10 * 0x10 + 8 + iVar5)) break;
  }
LAB_0041bc2a:
  if (iVar9 == 0) {
    iVar9 = 1;
  }
  iVar10 = *(int *)(*(int *)(param_1 + 0x394) + 0x1c);
  iVar8 = (piVar2[3] - *(int *)(iVar9 * 0x10 + 0xc + iVar10)) - iVar6;
  if (iVar8 < 0) {
    piVar2[1] = (piVar2[3] - *(int *)(*(int *)(param_1 + 0x39c) * 0x10 + 0xc + iVar10)) - iVar6;
  }
  else {
    piVar2[1] = iVar8;
    *(int *)(param_1 + 0x39c) = iVar9;
  }
  if (iVar1 != 1) {
    piVar2[2] = *(int *)(*(int *)(*(int *)(param_1 + 0x394) + 0x1c) + 8 +
                        *(int *)(param_1 + 0x39c) * 0x10) + *piVar2 + iVar3;
    return;
  }
  *piVar2 = (piVar2[2] -
            *(int *)(*(int *)(*(int *)(param_1 + 0x394) + 0x1c) + 8 +
                    *(int *)(param_1 + 0x39c) * 0x10)) + iVar4 * -2;
  return;
}



/* 0041bef0  FUN_0041bef0  28 bytes, 1 callers */

void __thiscall FUN_0041bef0(void *this,WPARAM param_1,LPARAM param_2)

{
  if (*(void **)((int)this + 0x394) != (void *)0x0) {
    FUN_0041c2e0(*(void **)((int)this + 0x394),param_1,param_2);
  }
  return;
}



/* 0041bf10  FUN_0041bf10  28 bytes, 1 callers */

void __thiscall FUN_0041bf10(void *this,WPARAM param_1,LPARAM param_2)

{
  if (*(void **)((int)this + 0x394) != (void *)0x0) {
    FUN_0041c2c0(*(void **)((int)this + 0x394),param_1,param_2);
  }
  return;
}



/* 0041bf30  FUN_0041bf30  43 bytes, 1 callers */

void __fastcall FUN_0041bf30(int param_1)

{
  LPVOID pvVar1;
  
  pvVar1 = *(LPVOID *)(param_1 + 0x394);
  if (pvVar1 != (LPVOID)0x0) {
    FUN_0041c0c0((int)pvVar1);
    FUN_00427f80(pvVar1);
    *(undefined4 *)(param_1 + 0x394) = 0;
  }
  return;
}



/* 0041bf60  FUN_0041bf60  14 bytes, 0 callers */

int __fastcall FUN_0041bf60(int param_1)

{
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return param_1;
}



/* 0041bf70  FUN_0041bf70  331 bytes, 1 callers */

undefined4 __thiscall FUN_0041bf70(void *this,uint param_1)

{
  int iVar1;
  HRSRC hResInfo;
  HGLOBAL hResData;
  short *psVar2;
  undefined4 *puVar3;
  ushort uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  InitCommonControls();
  *(undefined4 *)((int)this + 0x18) = 0;
  *(LPCSTR *)((int)this + 0x2c) = (LPCSTR)(param_1 & 0xffff);
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  hResInfo = FindResourceA(DAT_004344d0,(LPCSTR)(param_1 & 0xffff),(LPCSTR)0xf1);
  if (hResInfo != (HRSRC)0x0) {
    hResData = LoadResource(DAT_004344d0,hResInfo);
    if (hResData != (HGLOBAL)0x0) {
      psVar2 = LockResource(hResData);
      if ((psVar2 != (short *)0x0) && (*psVar2 == 1)) {
        *(uint *)this = (uint)(ushort)psVar2[1];
        *(uint *)((int)this + 4) = (uint)(ushort)psVar2[2];
        *(uint *)((int)this + 8) = (ushort)psVar2[1] + 7;
        *(uint *)((int)this + 0xc) = (ushort)psVar2[2] + 7;
        *(uint *)((int)this + 0x24) = (uint)(ushort)psVar2[3];
        uVar6 = FUN_00427f90((uint)(ushort)psVar2[3] * 0x14);
        *(undefined4 *)((int)this + 0x18) = uVar6;
        puVar3 = *(undefined4 **)((int)this + 0x18);
        for (uVar5 = (uint)(ushort)psVar2[3] * 0x14 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
        uVar4 = 0;
        while (uVar4 < (ushort)psVar2[3]) {
          iVar1 = (uint)uVar4 * 0x14;
          *(uint *)(*(int *)((int)this + 0x18) + 4 + iVar1) = (uint)(ushort)psVar2[uVar4 + 4];
          *(undefined1 *)(*(int *)((int)this + 0x18) + 8 + iVar1) = 4;
          puVar3 = (undefined4 *)(*(int *)((int)this + 0x18) + iVar1);
          if (puVar3[1] == 0) {
            *(undefined1 *)((int)puVar3 + 9) = 1;
            uVar4 = uVar4 + 1;
          }
          else {
            uVar4 = uVar4 + 1;
            *puVar3 = *(undefined4 *)((int)this + 0x20);
            *(int *)((int)this + 0x20) = *(int *)((int)this + 0x20) + 1;
            *(undefined1 *)(*(int *)((int)this + 0x18) + 9 + iVar1) = 0;
          }
        }
        uVar6 = 1;
      }
      FreeResource(hResData);
    }
  }
  return uVar6;
}



/* 0041c0c0  FUN_0041c0c0  68 bytes, 1 callers */

void __fastcall FUN_0041c0c0(int param_1)

{
  BOOL BVar1;
  
  BVar1 = IsWindow(*(HWND *)(param_1 + 0x28));
  if (BVar1 != 0) {
    DestroyWindow(*(HWND *)(param_1 + 0x28));
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  if (*(LPVOID *)(param_1 + 0x18) != (LPVOID)0x0) {
    FUN_00427f80(*(LPVOID *)(param_1 + 0x18));
  }
  if (*(LPVOID *)(param_1 + 0x1c) != (LPVOID)0x0) {
    FUN_00427f80(*(LPVOID *)(param_1 + 0x1c));
  }
  return;
}



/* 0041c110  FUN_0041c110  312 bytes, 0 callers */

undefined4 __thiscall FUN_0041c110(void *this,HWND param_1,uint param_2)

{
  int iVar1;
  HWND pHVar2;
  byte *pbVar3;
  WPARAM WVar4;
  uint uVar5;
  int local_10 [2];
  int local_8;
  
  iVar1 = FUN_0041bf70(this,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  pHVar2 = CreateToolbarEx(param_1,0x102,0x9c68,*(int *)((int)this + 0x20),DAT_004344d0,0x66,
                           *(LPCTBBUTTON *)((int)this + 0x18),*(int *)((int)this + 0x24),
                           *(int *)this,*(int *)((int)this + 4),*(int *)((int)this + 8),
                           *(int *)((int)this + 0xc),0x14);
  *(HWND *)((int)this + 0x28) = pHVar2;
  if (pHVar2 == (HWND)0x0) {
    return 0;
  }
  iVar1 = FUN_00427f90((*(int *)((int)this + 0x24) + 1) * 0x10);
  *(int *)((int)this + 0x1c) = iVar1;
  if (iVar1 == 0) {
    return 0;
  }
  uVar5 = 0;
  if (*(int *)((int)this + 0x24) != -1 && -1 < *(int *)((int)this + 0x24) + 1) {
    do {
      FUN_0041c290(this,uVar5,0);
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < *(int *)((int)this + 0x24) + 1);
  }
  FUN_0041c290(this,1,1);
  WVar4 = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  if (0 < *(int *)((int)this + 0x24)) {
    pbVar3 = (byte *)(*(int *)((int)this + 0x18) + 9);
    do {
      if ((*pbVar3 & 1) != 0) {
        FUN_0041c250(this,0x41d,WVar4,(LPARAM)local_10);
        *(int *)((int)this + 0x10) = local_8 - local_10[0];
        iVar1 = FUN_0041c270((int)this);
        *(int *)((int)this + 0x14) = iVar1 - *(int *)((int)this + 0xc);
        break;
      }
      pbVar3 = pbVar3 + 0x14;
      WVar4 = WVar4 + 1;
    } while ((int)WVar4 < *(int *)((int)this + 0x24));
  }
  DAT_00433fa4 = SetWindowLongA(*(HWND *)((int)this + 0x28),-4,0x41c380);
  ShowWindow(*(HWND *)((int)this + 0x28),5);
  return 1;
}



/* 0041c250  FUN_0041c250  28 bytes, 4 callers */

void __thiscall FUN_0041c250(void *this,UINT param_1,WPARAM param_2,LPARAM param_3)

{
  SendMessageA(*(HWND *)((int)this + 0x28),param_1,param_2,param_3);
  return;
}



/* 0041c270  FUN_0041c270  30 bytes, 1 callers */

int __fastcall FUN_0041c270(int param_1)

{
  tagRECT local_10;
  
  GetWindowRect(*(HWND *)(param_1 + 0x28),&local_10);
  return local_10.bottom - local_10.top;
}



/* 0041c290  FUN_0041c290  48 bytes, 1 callers */

void __thiscall FUN_0041c290(void *this,uint param_1,int param_2)

{
  FUN_0041c250(this,0x427,param_2 << 0x10 | param_1 & 0xffff,
               *(int *)((int)this + 0x1c) + param_1 * 0x10);
  return;
}



/* 0041c2c0  FUN_0041c2c0  23 bytes, 1 callers */

void __thiscall FUN_0041c2c0(void *this,WPARAM param_1,LPARAM param_2)

{
  FUN_0041c250(this,0x401,param_1,param_2);
  return;
}



/* 0041c2e0  FUN_0041c2e0  23 bytes, 1 callers */

void __thiscall FUN_0041c2e0(void *this,WPARAM param_1,LPARAM param_2)

{
  FUN_0041c250(this,0x402,param_1,param_2);
  return;
}



/* 0041c300  FUN_0041c300  121 bytes, 1 callers */

void FUN_0041c300(int param_1)

{
  uint uVar1;
  int iVar2;
  CHAR local_100 [256];
  
  if (*(int *)(param_1 + 8) == -0x208) {
    iVar2 = LoadStringA(DAT_004344d0,*(UINT *)(param_1 + 4),local_100,0x100);
    if (0 < iVar2) {
      uVar1 = *(uint *)(param_1 + 4);
      if ((0x9c8f < uVar1) && (uVar1 < 0x9c94)) {
        wsprintfA(local_100,&DAT_00433fb4,uVar1 * 0x11 + 0x38f5a1);
      }
      *(CHAR **)(param_1 + 0xc) = local_100;
    }
  }
  return;
}



/* 0041c380  FUN_0041c380  89 bytes, 0 callers */

void FUN_0041c380(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  LONG LVar1;
  
  if (param_2 == 0x201) {
    LVar1 = FUN_0040a0c0(0xea65);
    if (LVar1 != 0) {
      BringWindowToTop(*(HWND *)(LVar1 + 8));
    }
  }
  else if (param_2 == 0x203) {
    FUN_0041c3e0();
  }
  CallWindowProcA(DAT_00433fa4,param_1,param_2,param_3,param_4);
  return;
}



/* 0041c3e0  FUN_0041c3e0  45 bytes, 1 callers */

void FUN_0041c3e0(void)

{
  LONG LVar1;
  
  LVar1 = FUN_0040a0c0(0xea65);
  if (LVar1 != 0) {
    PostMessageA(*(HWND *)(DAT_004344e4 + 8),0x111,0x9cad,0);
  }
  return;
}



/* 0041c410  FUN_0041c410  329 bytes, 2 callers */

undefined4 __cdecl FUN_0041c410(undefined1 *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_14;
  int local_10;
  int local_c;
  
  iVar3 = FUN_0041ec60(100);
  if (iVar3 == 0) {
    uVar4 = FUN_0041c580(param_1);
    return uVar4;
  }
  iVar8 = 0x1f9;
  uVar5 = DAT_00437580 + 8;
  iVar3 = 0;
  local_c = 0;
  bVar1 = *(byte *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38);
  do {
    iVar9 = *(int *)(DAT_0043453c + iVar3 + 8);
    if (iVar9 < 0x1f0) {
      bVar2 = *(byte *)(DAT_0043453c + iVar3 + 0x10);
      uVar6 = (uint)bVar2;
      if (uVar6 == 5) {
joined_r0x0041c4fc:
        if (iVar9 < iVar8) goto switchD_0041c4d9_caseD_1;
      }
      else {
        iVar9 = iVar9 + 8;
        if (((iVar9 < iVar8) && (uVar6 != uVar5)) && (uVar6 != bVar1 + 8)) {
          if ((uVar6 == 0) || ((0xb < bVar2 && (bVar2 < 0x10)))) {
            iVar7 = FUN_0041e670(local_c / 0x30,local_c % 0x30);
            if (iVar7 == 0) goto switchD_0041c4d9_caseD_1;
          }
          else {
            switch(uVar6) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 8:
            case 9:
            case 10:
            case 0xb:
switchD_0041c4d9_caseD_1:
              iVar8 = iVar9;
              local_14 = local_c / 0x30;
              local_10 = local_c % 0x30;
              break;
            case 5:
              goto joined_r0x0041c4fc;
            }
          }
        }
      }
    }
    iVar3 = iVar3 + 0x18;
    local_c = local_c + 1;
    if (0xd7ff < iVar3) {
      iVar8 = iVar8 + -8;
      if (iVar8 < 0) {
        iVar8 = 0;
      }
      else if (0x1ef < iVar8) {
        return 0;
      }
      *(int *)(param_1 + 4) = iVar8;
      *param_1 = (undefined1)local_14;
      param_1[1] = (undefined1)local_10;
      return 1;
    }
  } while( true );
}



/* 0041c580  FUN_0041c580  239 bytes, 1 callers */

undefined4 __cdecl FUN_0041c580(undefined1 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_10;
  int local_c;
  
  iVar3 = 0x1f9;
  piVar5 = (int *)(DAT_0043453c + 8);
  iVar4 = 0;
  do {
    iVar2 = *piVar5;
    if (iVar2 < 0x1f0) {
      uVar1 = (uint)*(byte *)(piVar5 + 2);
      if (uVar1 == 5) {
joined_r0x0041c619:
        if (iVar2 < iVar3) {
switchD_0041c60a_caseD_1:
          iVar3 = iVar2;
          local_10 = iVar4 / 0x30;
          local_c = iVar4 % 0x30;
        }
      }
      else {
        iVar2 = iVar2 + 8;
        if (((iVar2 < iVar3) && (DAT_00437580 + 8U != uVar1)) &&
           (*(byte *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) + 8 != uVar1)) {
          switch(uVar1) {
          case 1:
          case 2:
          case 3:
          case 4:
          case 8:
          case 9:
          case 10:
          case 0xb:
            goto switchD_0041c60a_caseD_1;
          case 5:
            goto joined_r0x0041c619;
          }
        }
      }
    }
    piVar5 = piVar5 + 6;
    iVar4 = iVar4 + 1;
    if (0x8ff < iVar4) {
      iVar3 = iVar3 + -8;
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      else if (0x1ef < iVar3) {
        return 0;
      }
      *(int *)(param_1 + 4) = iVar3;
      *param_1 = (undefined1)local_10;
      param_1[1] = (undefined1)local_c;
      return 1;
    }
  } while( true );
}



/* 0041c690  FUN_0041c690  225 bytes, 1 callers */

bool __cdecl FUN_0041c690(undefined1 *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int local_8;
  undefined1 local_4;
  
  iVar2 = FUN_0041ec60(100);
  if (iVar2 == 0) {
    return false;
  }
  iVar2 = 0;
  local_8 = 0;
  *(undefined4 *)(param_1 + 4) = 0x1f0;
  do {
    bVar1 = *(byte *)(DAT_0043453c + iVar2 + 0x10);
    if (((((uint)bVar1 - DAT_00437580 != 8) &&
         ((uint)*(byte *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) - (uint)bVar1 != -8)) &&
        (*(uint *)(DAT_0043453c + iVar2 + 8) < *(uint *)(param_1 + 4))) && (bVar1 == 0)) {
      iVar3 = FUN_0041e670(local_8 / 0x30,local_8 % 0x30);
      if (iVar3 == 0) {
        local_4 = (undefined1)(local_8 % 0x30);
        *param_1 = (char)(local_8 / 0x30);
        param_1[1] = local_4;
        *(undefined4 *)(param_1 + 4) = *(undefined4 *)(DAT_0043453c + 8 + iVar2);
      }
    }
    iVar2 = iVar2 + 0x18;
    local_8 = local_8 + 1;
  } while (iVar2 < 0xd800);
  return *(uint *)(param_1 + 4) < 0x1f0;
}



/* 0041c780  FUN_0041c780  123 bytes, 1 callers */

undefined4 __cdecl FUN_0041c780(char *param_1)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    bVar1 = *(byte *)(DAT_0043453c + 0x10 +
                     (((char)(&DAT_00434420)[iVar2] + DAT_0043644c) * 0x30 +
                      (int)(char)(&DAT_00434428)[iVar2] + DAT_00436450) * 0x18);
    if (((0xb < bVar1) && (bVar1 < 0x10)) && (DAT_00437580 - (uint)bVar1 != -0xc)) break;
    iVar2 = iVar2 + 1;
    if (7 < iVar2) {
      return 0;
    }
  }
  *param_1 = (&DAT_00434420)[iVar2] + (char)DAT_0043644c;
  param_1[1] = (&DAT_00434428)[iVar2] + (char)DAT_00436450;
  return 1;
}



/* 0041c800  FUN_0041c800  211 bytes, 2 callers */

bool __cdecl FUN_0041c800(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar2 = 0;
  local_4 = 0;
  param_1[4] = -0x10;
  param_1[5] = '\x01';
  param_1[6] = '\0';
  param_1[7] = '\0';
  do {
    iVar3 = 0;
    do {
      if (*(char *)(DAT_0043453c + 0x10 + local_4) == '{') {
        iVar4 = 0;
        do {
          if (*(uint *)(DAT_0043453c + 8 +
                       (((char)(&DAT_00434420)[iVar4] + iVar2) * 0x30 +
                        (int)(char)(&DAT_00434428)[iVar4] + iVar3) * 0x18) < *(uint *)(param_1 + 4))
          {
            param_1[2] = (&DAT_00434420)[iVar4] + (char)iVar2;
            cVar1 = (&DAT_00434428)[iVar4];
            *param_1 = (char)iVar2;
            param_1[3] = cVar1 + (char)iVar3;
            param_1[1] = (char)iVar3;
            *(undefined4 *)(param_1 + 4) =
                 *(undefined4 *)
                  (DAT_0043453c + 8 +
                  (((char)(&DAT_00434420)[iVar4] + iVar2) * 0x30 + (int)(char)(&DAT_00434428)[iVar4]
                  + iVar3) * 0x18);
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 4);
      }
      local_4 = local_4 + 0x18;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x30);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x30);
  return *(uint *)(param_1 + 4) < 0x1f0;
}



/* 0041c8e0  FUN_0041c8e0  518 bytes, 1 callers */

bool __cdecl FUN_0041c8e0(char *param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_c;
  int local_8;
  
  iVar5 = FUN_0041ec60(500);
  if (iVar5 == 0) {
    return false;
  }
  local_c = 0;
  local_8 = 0;
  *(undefined1 *)(DAT_0043453c + (DAT_0043644c * 0x30 + DAT_00436450) * 0x18) = 0x40;
  param_1[4] = -0x10;
  param_1[5] = '\x01';
  param_1[6] = '\0';
  param_1[7] = '\0';
  do {
    if (*(char *)(DAT_0043453c + 0x10 + local_8) == 'z') {
      iVar5 = local_c / 0x30;
      iVar6 = local_c % 0x30;
      iVar7 = (iVar5 * 0x30 + iVar6) * 0x18 + DAT_0043453c;
      if ((*(byte *)(iVar7 + -0x14) & *(byte *)(iVar7 + 0x484) & *(byte *)(iVar7 + 0x1c) &
           *(byte *)(iVar7 + -0x47c) & 1) == 0) {
        bVar4 = true;
        iVar7 = 0;
        do {
          bVar1 = *(byte *)(DAT_0043453c +
                           (((char)(&DAT_00434420)[iVar7] + iVar5) * 0x30 +
                            (int)(char)(&DAT_00434428)[iVar7] + iVar6) * 0x18);
          if ((bVar1 < 0x40) &&
             ((uVar3 = *(uint *)(DAT_00434538 + 8 + (uint)bVar1 * 0x224),
              *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 2 < uVar3 || (0x1000 < uVar3))))
          {
            bVar4 = false;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < 4);
        if (bVar4) {
          iVar7 = 0;
          do {
            if (*(uint *)(DAT_0043453c + 8 +
                         (((char)(&DAT_00434420)[iVar7] + iVar5) * 0x30 +
                          (int)(char)(&DAT_00434428)[iVar7] + iVar6) * 0x18) <
                *(uint *)(param_1 + 4)) {
              param_1[2] = (&DAT_00434420)[iVar7] + (char)iVar5;
              cVar2 = (&DAT_00434428)[iVar7];
              *param_1 = (char)iVar5;
              param_1[3] = cVar2 + (char)iVar6;
              param_1[1] = (char)iVar6;
              *(undefined4 *)(param_1 + 4) =
                   *(undefined4 *)
                    (DAT_0043453c + 8 +
                    (((char)(&DAT_00434420)[iVar7] + iVar5) * 0x30 +
                     (int)(char)(&DAT_00434428)[iVar7] + iVar6) * 0x18);
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < 4);
        }
      }
    }
    local_8 = local_8 + 0x18;
    local_c = local_c + 1;
  } while (local_8 < 0xd800);
  *(undefined1 *)(DAT_0043453c + (DAT_0043644c * 0x30 + DAT_00436450) * 0x18) =
       (undefined1)DAT_0043756c;
  return *(uint *)(param_1 + 4) < 0x1f0;
}



/* 0041caf0  FUN_0041caf0  202 bytes, 1 callers */

bool __cdecl FUN_0041caf0(undefined2 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 0;
  *(undefined4 *)(param_1 + 2) = 0x1f0;
  do {
    iVar2 = DAT_00434538 + iVar3;
    if (((((*(byte *)(iVar2 + 0x10) & 0x80) == 0) && (iVar4 != DAT_0043756c)) &&
        (*(byte *)(iVar2 + 4) == DAT_00437580)) && ((*(byte *)(iVar2 + 0xd) & 0xf) == 2)) {
      uVar1 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
      if ((uVar1 < *(uint *)(iVar2 + 8)) && (*(uint *)(iVar2 + 8) + uVar1 < 100000)) {
        uVar1 = *(uint *)(DAT_0043453c + 8 +
                         ((uint)*(byte *)(iVar2 + 2) * 0x30 + (uint)*(byte *)(iVar2 + 3)) * 0x18);
        if (uVar1 < *(uint *)(param_1 + 2)) {
          *(uint *)(param_1 + 2) = uVar1;
          *param_1 = *(undefined2 *)(DAT_00434538 + 2 + iVar3);
        }
      }
    }
    iVar3 = iVar3 + 0x224;
    iVar4 = iVar4 + 1;
  } while (iVar3 < 0x8900);
  return *(uint *)(param_1 + 2) < 0x1f0;
}



/* 0041cbc0  FUN_0041cbc0  111 bytes, 1 callers */

bool __cdecl FUN_0041cbc0(byte *param_1)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  
  bVar2 = 0;
  param_1[4] = 0xf0;
  param_1[5] = 1;
  param_1[6] = 0;
  param_1[7] = 0;
  do {
    bVar3 = 0;
    do {
      iVar4 = ((uint)bVar3 + (uint)bVar2 * 0x30) * 0x18 + DAT_0043453c;
      if (((uint)*(byte *)(iVar4 + 0x10) - DAT_00437580 == 8) &&
         (uVar1 = *(uint *)(iVar4 + 8), uVar1 < *(uint *)(param_1 + 4))) {
        *(uint *)(param_1 + 4) = uVar1;
        *param_1 = bVar2;
        param_1[1] = bVar3;
      }
      bVar3 = bVar3 + 1;
    } while (bVar3 < 0x30);
    bVar2 = bVar2 + 1;
  } while (bVar2 < 0x30);
  return *(uint *)(param_1 + 4) < 0x1f0;
}



/* 0041cc30  FUN_0041cc30  168 bytes, 1 callers */

bool __cdecl FUN_0041cc30(undefined1 *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int local_4;
  
  iVar2 = 0;
  local_4 = 0;
  *(undefined4 *)(param_1 + 4) = 0x1f0;
  do {
    iVar3 = DAT_0043453c + iVar2;
    if (*(uint *)(iVar3 + 8) < *(uint *)(param_1 + 4)) {
      bVar1 = *(byte *)(iVar3 + 0x10);
      if ((((7 < bVar1) && (bVar1 < 0xc)) && ((uint)bVar1 - DAT_00437580 != 8)) &&
         ((uint)*(byte *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) - (uint)bVar1 != -8)) {
        *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar3 + 8);
        *param_1 = (char)(local_4 / 0x30);
        param_1[1] = (char)(local_4 % 0x30);
      }
    }
    iVar2 = iVar2 + 0x18;
    local_4 = local_4 + 1;
  } while (iVar2 < 0xd800);
  return *(uint *)(param_1 + 4) < 0x1f0;
}



/* 0041cce0  FUN_0041cce0  103 bytes, 1 callers */

bool __cdecl FUN_0041cce0(undefined1 *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 0;
  *(undefined4 *)(param_1 + 4) = 0x1f0;
  do {
    uVar2 = *(uint *)(DAT_0043453c + iVar4 + 8);
    if (uVar2 < *(uint *)(param_1 + 4)) {
      bVar1 = *(byte *)(DAT_0043453c + iVar4 + 0x10);
      if ((bVar1 != 0) && (bVar1 < 5)) {
        *(uint *)(param_1 + 4) = uVar2;
        *param_1 = (char)(iVar3 / 0x30);
        param_1[1] = (char)(iVar3 % 0x30);
      }
    }
    iVar4 = iVar4 + 0x18;
    iVar3 = iVar3 + 1;
  } while (iVar4 < 0xd800);
  return *(uint *)(param_1 + 4) < 0x1f0;
}



/* 0041cd50  FUN_0041cd50  100 bytes, 1 callers */

bool __cdecl FUN_0041cd50(undefined1 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  *(undefined4 *)(param_1 + 4) = 0x1f0;
  do {
    uVar1 = *(uint *)(DAT_0043453c + iVar3 + 8);
    if ((uVar1 < *(uint *)(param_1 + 4)) && (*(char *)(DAT_0043453c + iVar3 + 0x10) == '\x05')) {
      *(uint *)(param_1 + 4) = uVar1;
      *param_1 = (char)(iVar2 / 0x30);
      param_1[1] = (char)(iVar2 % 0x30);
    }
    iVar3 = iVar3 + 0x18;
    iVar2 = iVar2 + 1;
  } while (iVar3 < 0xd800);
  return *(uint *)(param_1 + 4) < 0x1f0;
}



/* 0041cdc0  FUN_0041cdc0  34 bytes, 4 callers */

int FUN_0041cdc0(void)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = 0;
  pbVar2 = (byte *)(DAT_00434538 + 0x10);
  do {
    if ((*pbVar2 & 0x80) != 0) {
      return iVar1;
    }
    pbVar2 = pbVar2 + 0x224;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x40);
  return 0x40;
}



/* 0041cdf0  FUN_0041cdf0  52 bytes, 2 callers */

int FUN_0041cdf0(void)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar1 = 0;
  iVar2 = 0x900;
  puVar3 = (undefined1 *)(DAT_0043453c + 0x10);
  do {
    switch(*puVar3) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x7b:
      iVar1 = iVar1 + 1;
    }
    puVar3 = puVar3 + 0x18;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return iVar1;
}



/* 0041ceb0  FUN_0041ceb0  48 bytes, 2 callers */

int __cdecl FUN_0041ceb0(int param_1)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar1 = 0;
  pbVar3 = (byte *)(DAT_0043453c + 0x10);
  iVar2 = 0x900;
  do {
    if (((uint)*pbVar3 - param_1 == 8) || ((uint)*pbVar3 - param_1 == 0xc)) {
      iVar1 = iVar1 + 1;
    }
    pbVar3 = pbVar3 + 0x18;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return iVar1;
}



/* 0041cee0  FUN_0041cee0  167 bytes, 1 callers */

undefined4 * __fastcall FUN_0041cee0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041cf87;
  *unaff_FS_OFFSET = &local_10;
  FUN_00427770(param_1);
  local_8 = 0;
  param_1[8] = 0xb0;
  param_1[9] = 0xb0;
  *param_1 = &PTR_FUN_00430750;
  iVar1 = GetSystemMetrics(8);
  param_1[7] = param_1[7] + iVar1 * 2;
  iVar1 = GetSystemMetrics(7);
  param_1[6] = param_1[6] + iVar1 * 2;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = param_1[8] + param_1[6];
  param_1[0x11] = param_1[9] + param_1[7];
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = param_1[8] + param_1[6];
  param_1[0xd] = param_1[9] + param_1[7];
  param_1[0x9f] = 0;
  param_1[0x9e] = 0x54400000;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}



/* 0041cfa0  FUN_0041cfa0  30 bytes, 0 callers */

undefined4 * __thiscall FUN_0041cfa0(void *this,byte param_1)

{
  FUN_0041cfc0(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 0041cfc0  FUN_0041cfc0  123 bytes, 1 callers */

void __fastcall FUN_0041cfc0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_0041d03b;
  *param_1 = &PTR_FUN_00430750;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0;
  (&DAT_004344f8)[param_1[0xe5]] = 0;
  puVar1 = (undefined4 *)param_1[0x129];
  if (puVar1 != (undefined4 *)0x0) {
    FUN_004279a0(puVar1);
    FUN_00427f80(puVar1);
    param_1[0x129] = 0;
  }
  local_8 = 0xffffffff;
  FUN_0041d045();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 0041d045  FUN_0041d045  8 bytes, 1 callers */

void FUN_0041d045(void)

{
  int unaff_EBP;
  
  FUN_00427820(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 0041d050  FUN_0041d050  142 bytes, 0 callers */

void __thiscall FUN_0041d050(void *this,int param_1,int param_2)

{
  int iVar1;
  
  *(int *)((int)this + 0x394) = param_2 + -0xea66;
  wsprintfA((LPSTR)((int)this + 0x14c),s_Cnt_d_00433fdc,param_2 + -0xea66);
  wsprintfA((LPSTR)((int)this + 0x48),s__s__s_00433fc4,s_Status_Window_00433fcc,
            &DAT_00435b31 + *(int *)((int)this + 0x394) * 0x11);
  (&DAT_004344f8)[*(int *)((int)this + 0x394)] = this;
  iVar1 = *(int *)((int)this + 0x394) << 4;
  *(int *)((int)this + 0x28) = iVar1;
  *(int *)((int)this + 0x2c) = iVar1;
  *(undefined4 *)((int)this + 0x30) = *(undefined4 *)((int)this + 0x40);
  *(undefined4 *)((int)this + 0x34) = *(undefined4 *)((int)this + 0x44);
  FUN_00425210(this,param_1,param_2);
  return;
}



/* 0041d1f0  FUN_0041d1f0  40 bytes, 0 callers */

void __fastcall FUN_0041d1f0(int param_1)

{
  tagPOINT local_8;
  
  if (*(char *)(param_1 + 900) == '\0') {
    GetCursorPos(&local_8);
    FUN_0040a980(&local_8.x);
  }
  return;
}



/* 0041d460  FUN_0041d460  395 bytes, 0 callers */

void __fastcall FUN_0041d460(int *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint local_10;
  int local_8;
  int local_4;
  
  iVar5 = param_1[9];
  iVar6 = param_1[8];
  puVar7 = (undefined4 *)param_1[0x97];
  for (uVar2 = (uint)(iVar5 * iVar6) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar7 = 0x70707070;
    puVar7 = puVar7 + 1;
  }
  for (uVar2 = iVar5 * iVar6 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar7 = 0x70;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  local_10 = 0;
  do {
    iVar5 = local_10 + 0xe0 + param_1[0xe5] * 8;
    if (local_10 == 1) {
      bVar1 = *(byte *)(DAT_00434534 + 0x1e + param_1[0xe5] * 0x38);
      if (bVar1 != 0x80) {
        iVar5 = (uint)bVar1 * 8 + 0xe1;
        goto LAB_0041d4d2;
      }
    }
    else {
LAB_0041d4d2:
      iVar5 = iVar5 << 10;
      iVar6 = 0;
      uVar2 = (int)local_10 >> 0x1f;
      do {
        iVar4 = ((int)local_10 / 2) * 0x28 + iVar6;
        puVar7 = (undefined4 *)(DAT_00436440 + iVar5);
        iVar5 = iVar5 + 0x20;
        iVar6 = iVar6 + 1;
        puVar8 = (undefined4 *)
                 ((iVar4 + 0x10) * param_1[8] + param_1[0x97] + 0x10 +
                 (((local_10 ^ uVar2) - uVar2 & 1 ^ uVar2) - uVar2) * 0x20);
        for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
      } while (iVar6 < 0x20);
    }
    local_10 = local_10 + 1;
    if (7 < (int)local_10) {
      SelectObject((HDC)param_1[0x95],*(HGDIOBJ *)(DAT_004344e4 + 0x3a4));
      wsprintfA((LPSTR)(param_1 + 0xe8),&DAT_00432100,&DAT_00435b31 + param_1[0xe5] * 0x11);
      local_8 = param_1[8];
      local_4 = param_1[9];
      FUN_0040a870(4,2,0,1,(LPCSTR)(param_1 + 0xe8),(HDC)param_1[0x95],1,&local_8);
      SelectObject((HDC)param_1[0x95],*(HGDIOBJ *)(DAT_004344e4 + 0x3a4));
      (**(code **)(*param_1 + 0x18))();
      return;
    }
  } while( true );
}



/* 0041d5f0  FUN_0041d5f0  160 bytes, 0 callers */

void __fastcall FUN_0041d5f0(int param_1)

{
  int iVar1;
  int iVar2;
  char local_1c [12];
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x4a4) != 0) {
    local_1c[0] = '\0';
    local_1c[1] = 0x10;
    local_1c[2] = 0x10;
    local_1c[3] = 0x18;
    local_1c[4] = 0x10;
    local_1c[5] = 0x10;
    local_1c[6] = 0x18;
    local_1c[7] = 0x10;
    local_1c[8] = 0x18;
    local_1c[9] = 0x10;
    local_10 = 0x58;
    local_8 = 0xb0;
    local_c = 0;
    iVar1 = 0;
    do {
      iVar2 = iVar1 + 1;
      local_c = local_c + local_1c[iVar1];
      FUN_00427a90(*(void **)(param_1 + 0x4a4),iVar1 + 70000,iVar1 + 0x9cb9,local_10,local_c,local_8
                   ,local_c + 0x10);
      iVar1 = iVar2;
    } while (iVar2 < 9);
  }
  return;
}



/* 0041d690  FUN_0041d690  53 bytes, 3 callers */

undefined1 __cdecl FUN_0041d690(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00434538 + 0x18 + param_1 * 0x224);
  if (iVar1 != 0x1f0) {
    return *(undefined1 *)(DAT_00434538 + iVar1 + 0x1c + param_1 * 0x224);
  }
  return 5;
}



/* 0041d6d0  FUN_0041d6d0  109 bytes, 10 callers */

/* WARNING: Type propagation algorithm not settling */

void __cdecl FUN_0041d6d0(int param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_40 = 0xffffffff;
  local_3c = 0;
  local_38 = 0xffffffff;
  local_34 = 0xffffffff;
  local_30 = 0;
  local_2c = 0xffffffff;
  local_28 = 1;
  local_24 = 0xffffffff;
  local_20 = 1;
  local_1c = 0;
  local_18 = 1;
  local_14 = 1;
  local_10 = 0;
  local_c = 1;
  local_8 = 0xffffffff;
  local_4 = 1;
  if (param_1 < 8) {
    uVar1 = *(undefined1 *)((int)&local_3c + param_1 * 8);
    *param_2 = *(undefined1 *)(&local_40 + param_1 * 2);
    param_2[1] = uVar1;
  }
  return;
}



/* 0041d740  FUN_0041d740  256 bytes, 1 callers */

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



/* 0041d870  FUN_0041d870  1005 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041d870(void)

{
  byte *pbVar1;
  int *piVar2;
  uint *puVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte local_a;
  byte local_9;
  byte local_8;
  char local_7;
  byte local_5;
  byte local_4;
  
  iVar5 = DAT_00437580 * 0x38 + DAT_00434534;
  uVar6 = *(uint *)(iVar5 + 4);
  if ((uVar6 & 0x40) != 0) {
    cVar4 = *(char *)(iVar5 + 0x1f);
    if (cVar4 != '\x04') {
      *(char *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) = cVar4 + '\b';
      iVar5 = -1;
      do {
        iVar7 = -1;
        do {
          pbVar1 = (byte *)(DAT_0043453c + 0x10 +
                           ((DAT_0043644c + iVar5) * 0x30 + DAT_00436450 + iVar7) * 0x18);
          if (*pbVar1 - DAT_00437580 == 0xc) {
            *pbVar1 = *(char *)(DAT_00434534 + 0x1f + DAT_00437580 * 0x38) + 0xc;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < 2);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 2);
      return;
    }
    *(undefined1 *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) = 0;
    iVar5 = -1;
    do {
      iVar7 = -1;
      do {
        pbVar1 = (byte *)(DAT_0043453c + 0x10 +
                         ((DAT_0043644c + iVar5) * 0x30 + DAT_00436450 + iVar7) * 0x18);
        if (*pbVar1 - DAT_00437580 == 0xc) {
          *pbVar1 = 0;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < 2);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
    return;
  }
  if ((uVar6 & 1) == 0) {
    FUN_0041ee10(DAT_0043644c,DAT_00436450,(char *)&local_8);
    piVar2 = (int *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18);
    *piVar2 = *piVar2 + local_8 + 1;
    puVar3 = (uint *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18);
    uVar6 = *puVar3;
    if ((local_8 + 1) * 0x10 <= uVar6) {
      if (0xfe < uVar6) {
        uVar6 = 0xff;
      }
      *puVar3 = uVar6;
      if (local_7 == '\0') {
        iVar5 = FUN_0041c780((char *)&local_a);
        if (iVar5 == 1) {
          iVar5 = ((uint)local_a * 0x30 + (uint)local_9) * 0x18;
          *(undefined4 *)(DAT_0043453c + 0xc + iVar5) = 100;
          *(char *)(DAT_0043453c + 0x10 + iVar5) = (char)DAT_00437580 + '\f';
          if (*(uint *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18) < 200) {
            return;
          }
        }
      }
      else {
        iVar5 = ((uint)local_4 + (uint)local_5 * 0x30) * 0x18;
        *(undefined4 *)(DAT_0043453c + 0xc + iVar5) = 100;
        *(char *)(DAT_0043453c + 0x10 + iVar5) = (char)DAT_00437580 + '\f';
        if (*(uint *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18) < 200) {
          return;
        }
      }
      if (DAT_0043756c < 0x40) {
        iVar5 = DAT_0043756c * 0x224 + DAT_00434538;
        if (*(byte *)(iVar5 + 4) == DAT_00437580) {
          piVar2 = (int *)(iVar5 + 8);
          *piVar2 = *piVar2 + *(int *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18);
          *(undefined4 *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18) = 1;
          puVar3 = (uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
          if (100000 < *puVar3) {
            *puVar3 = 100000;
            return;
          }
        }
      }
      else {
        iVar5 = FUN_0041cdc0();
        if (iVar5 != 0x40) {
          iVar7 = iVar5 * 0x224;
          *(undefined1 *)(DAT_00434538 + 4 + iVar7) = (undefined1)DAT_00437580;
          *(int *)(DAT_00434538 + 8 + iVar7) =
               *(int *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18) + -1;
          *(undefined1 *)(DAT_00434538 + iVar7) = (undefined1)DAT_0043644c;
          *(undefined1 *)(DAT_00434538 + 1 + iVar7) = (undefined1)DAT_00436450;
          ((undefined2 *)(DAT_00434538 + iVar7))[1] = *(undefined2 *)(DAT_00434538 + iVar7);
          *(undefined1 *)(DAT_00434538 + 0x10 + iVar7) = 0;
          *(undefined1 *)(DAT_00434538 + 0x220 + iVar7) = 0xff;
          *(char *)(DAT_0043453c + DAT_00437690 * 0x18) = (char)iVar5;
          *(undefined4 *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18) = 1;
          if ((DAT_004365cd == DAT_00437580) && (_DAT_004365e0 != 1)) {
            pbVar1 = (byte *)(DAT_00434538 + 0x10 + iVar7);
            *pbVar1 = *pbVar1 | 4;
            *(byte *)(DAT_00434538 + 0xd + iVar7) = (byte)_DAT_004365e0 | 0x10;
            return;
          }
          *(undefined1 *)(DAT_00434538 + 0xd + iVar7) = 1;
        }
      }
    }
  }
  return;
}



/* 0041dc60  FUN_0041dc60  580 bytes, 1 callers */

void FUN_0041dc60(void)

{
  int *piVar1;
  byte *pbVar2;
  uint *puVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  bVar5 = 0;
  if (DAT_004365cd == DAT_00437580) {
    if (DAT_0043769c == '\x01') {
      *(undefined1 *)(DAT_00434534 + 0x1c + DAT_00437580 * 0x38) = 0;
      iVar4 = DAT_00437580 * 0x38 + DAT_00434534;
      uVar6 = *(uint *)(iVar4 + 0x18);
      if (uVar6 < 0xffff) {
        *(char *)(iVar4 + 0x1c) = (char)(uVar6 >> 8);
        pbVar2 = (byte *)(DAT_00434534 + 0x1c + DAT_00437580 * 0x38);
        if (*pbVar2 < 0x15) {
          *pbVar2 = 0x14 - *pbVar2;
        }
        else {
          *pbVar2 = 0;
        }
      }
    }
  }
  else {
    iVar4 = DAT_00437580 * 0x38 + DAT_00434534;
    uVar6 = *(uint *)(iVar4 + 0x18);
    if ((uVar6 < 100000) && ((uVar6 & 0xffffff00) < 0x701)) {
      bVar5 = ~((char)(uVar6 >> 8) << 2) & 0x1c;
    }
    *(byte *)(iVar4 + 0x1c) = bVar5;
  }
  if ((((DAT_0043756c < 0x40) &&
       (iVar4 = DAT_0043756c * 0x224 + DAT_00434538, *(byte *)(iVar4 + 4) == DAT_00437580)) &&
      ((*(byte *)(iVar4 + 0xd) & 0x20) != 0)) &&
     (uVar6 = (uint)*(byte *)(DAT_0043453c + 0x40 + (DAT_0043644c * 0x30 + DAT_00436450) * 0x18),
     uVar6 < 0x30)) {
    switch(uVar6) {
    case 8:
    case 9:
    case 10:
    case 0xb:
      if (uVar6 - DAT_00437580 != 8) {
        return;
      }
      break;
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
      if (uVar6 - DAT_00437580 != 0xc) {
        return;
      }
    }
    if (DAT_0043781c != 0) {
      DAT_0043781c = DAT_0043781c + -1;
    }
    FUN_00405360();
    FUN_00405390((byte)DAT_00437580);
    iVar4 = DAT_00437580 * 0x38 + DAT_00434534;
    FUN_0041a680((uint)*(byte *)(iVar4 + 8),(uint)*(byte *)(iVar4 + 9));
    iVar4 = 0;
    do {
      iVar7 = DAT_0043453c + iVar4;
      if ((*(byte *)(iVar7 + 0x10) - DAT_00437580 == 8) && (*(uint *)(iVar7 + 8) < 0x1f0)) {
        iVar8 = DAT_00437580 * 0x38 + DAT_00434534;
        uVar6 = (uint)*(byte *)(iVar8 + 0x1c) * *(int *)(iVar7 + 0xc) >> 8;
        piVar1 = (int *)(iVar8 + 0x18);
        *piVar1 = *piVar1 + uVar6;
        puVar3 = (uint *)(DAT_00434534 + 0x18 + DAT_00437580 * 0x38);
        if (100000 < *puVar3) {
          *puVar3 = 100000;
        }
        puVar3 = (uint *)(DAT_0043453c + 0xc + iVar4);
        if (*puVar3 < uVar6) {
          *puVar3 = 0;
        }
        else {
          *puVar3 = *puVar3 - uVar6;
        }
      }
      iVar4 = iVar4 + 0x18;
    } while (iVar4 < 0xd800);
  }
  return;
}



/* 0041dec0  FUN_0041dec0  238 bytes, 1 callers */

void FUN_0041dec0(void)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = (uint *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18);
  uVar3 = *puVar2;
  if (uVar3 < 0xf5) {
    *puVar2 = uVar3 + 10;
    return;
  }
  *puVar2 = uVar3 - 0xf5;
  if (0x3f < DAT_0043756c) {
    uVar3 = FUN_0041cdc0();
    if (uVar3 < 0x40) {
      iVar1 = uVar3 * 0x224;
      *(undefined1 *)(DAT_00434538 + iVar1) = (undefined1)DAT_0043644c;
      *(undefined1 *)(DAT_00434538 + 1 + iVar1) = (undefined1)DAT_00436450;
      ((undefined2 *)(DAT_00434538 + iVar1))[1] = *(undefined2 *)(DAT_00434538 + iVar1);
      *(undefined1 *)(DAT_00434538 + 0x10 + iVar1) = 0;
      *(undefined1 *)(DAT_00434538 + 0xc + iVar1) = 6;
      *(undefined1 *)(DAT_00434538 + 0xd + iVar1) = 0xe;
      *(undefined1 *)(DAT_00434538 + 4 + iVar1) = 4;
      *(undefined4 *)(DAT_00434538 + 8 + iVar1) = 200;
      *(undefined4 *)(DAT_00434538 + 0x18 + iVar1) = 0x1f0;
      *(undefined1 *)(DAT_00434538 + 0xf + iVar1) = 10;
      *(char *)(DAT_0043453c + DAT_00437690 * 0x18) = (char)uVar3;
    }
  }
  return;
}



/* 0041dfb0  FUN_0041dfb0  226 bytes, 3 callers */

undefined4 __cdecl FUN_0041dfb0(char *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  int iVar3;
  int iVar4;
  
  bVar1 = FUN_0041ebf0(DAT_0043644c,DAT_00436450);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    return 0;
  }
  DAT_00433ff0 = 0;
  iVar4 = 1;
  do {
    DAT_00433ff0 = (int)DAT_00433ff0 >> 1;
    iVar2 = (char)(&DAT_00434400)[iVar4] + DAT_0043644c;
    iVar3 = (char)(&DAT_00434410)[iVar4] + DAT_00436450;
    bVar1 = FUN_0041ebf0(iVar2,iVar3);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      DAT_00433ff0 = DAT_00433ff0 | 0x80;
    }
    else if ((*(char *)(DAT_0043453c + 0x10 + (iVar2 * 0x30 + iVar3) * 0x18) == '\x05') &&
            ((DAT_00433ff0 & 8) == 0)) {
      iVar2 = FUN_0041e700(DAT_0043756c,iVar2,iVar3);
      if (iVar2 == 0) {
        *param_1 = (&DAT_00434400)[iVar4];
        param_1[1] = (&DAT_00434410)[iVar4];
        return 1;
      }
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 9);
  return 0;
}



/* 0041e0a0  FUN_0041e0a0  303 bytes, 4 callers */

undefined4 __cdecl FUN_0041e0a0(char *param_1)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar4;
  int iVar5;
  int iVar6;
  
  bVar3 = FUN_0041ebf0(DAT_0043644c,DAT_00436450);
  if (CONCAT31(extraout_var,bVar3) == 0) {
    return 0;
  }
  DAT_00433ff0 = 0;
  iVar4 = 1;
  do {
    DAT_00433ff0 = (int)DAT_00433ff0 >> 1;
    iVar5 = (char)(&DAT_00434400)[iVar4] + DAT_0043644c;
    iVar6 = (char)(&DAT_00434410)[iVar4] + DAT_00436450;
    bVar3 = FUN_0041ebf0(iVar5,iVar6);
    if (CONCAT31(extraout_var_00,bVar3) == 1) {
      if ((((DAT_00433ff0 & 8) == 0) &&
          (bVar1 = *(byte *)(DAT_0043453c + 0x10 + (iVar5 * 0x30 + iVar6) * 0x18), 7 < bVar1)) &&
         (bVar1 < 0xc)) {
        bVar2 = *(byte *)(DAT_00434538 + 4 + DAT_0043756c * 0x224);
        if (((byte)(bVar1 - 8) != bVar2) &&
           (*(byte *)(DAT_00434534 + 0x1e + (uint)bVar2 * 0x38) != (byte)(bVar1 - 8))) {
          iVar5 = FUN_0041e700(DAT_0043756c,iVar5,iVar6);
          if (iVar5 == 0) {
            *param_1 = (&DAT_00434400)[iVar4];
            param_1[1] = (&DAT_00434410)[iVar4];
            return 1;
          }
        }
      }
    }
    else {
      DAT_00433ff0 = DAT_00433ff0 | 0x80;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 9);
  return 0;
}



/* 0041e1d0  FUN_0041e1d0  386 bytes, 4 callers */

undefined4 __cdecl FUN_0041e1d0(char *param_1)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  char cVar4;
  undefined3 extraout_var;
  int iVar5;
  undefined3 extraout_var_00;
  int iVar6;
  int iVar7;
  int iVar8;
  
  bVar3 = FUN_0041ebf0(DAT_0043644c,DAT_00436450);
  if (CONCAT31(extraout_var,bVar3) == 0) {
    return 0;
  }
  iVar5 = FUN_0041ec60(100);
  if (iVar5 == 0) {
    return 0;
  }
  cVar4 = (char)DAT_00437580;
  iVar5 = 1;
  cVar1 = *(char *)(DAT_00434534 + 0x1e +
                   (uint)*(byte *)(DAT_00434538 + 4 + DAT_0043756c * 0x224) * 0x38);
  DAT_00433ff0 = 0;
  do {
    DAT_00433ff0 = (int)DAT_00433ff0 >> 1;
    iVar8 = (char)(&DAT_00434400)[iVar5] + DAT_0043644c;
    iVar7 = (char)(&DAT_00434410)[iVar5] + DAT_00436450;
    bVar3 = FUN_0041ebf0(iVar8,iVar7);
    if (CONCAT31(extraout_var_00,bVar3) == 1) {
      if ((DAT_00433ff0 & 8) == 0) {
        bVar2 = *(byte *)(DAT_0043453c + 0x10 + (iVar8 * 0x30 + iVar7) * 0x18);
        bVar3 = bVar2 == 0;
        if ((0xb < bVar2) && (bVar2 < 0x10)) {
          bVar3 = true;
        }
        if ((((7 < bVar2) && (bVar2 < 0xc)) && (bVar2 != (byte)(cVar4 + 8U))) &&
           (bVar2 != (byte)(cVar1 + 8U))) {
          bVar3 = true;
        }
        if (((bVar3) && (iVar6 = FUN_0041e670(iVar8,iVar7), iVar6 == 0)) &&
           (iVar7 = FUN_0041e700(DAT_0043756c,iVar8,iVar7), iVar7 == 0)) {
          *param_1 = (&DAT_00434400)[iVar5];
          param_1[1] = (&DAT_00434410)[iVar5];
          return 1;
        }
      }
    }
    else {
      DAT_00433ff0 = DAT_00433ff0 | 0x80;
    }
    iVar5 = iVar5 + 1;
    if (8 < iVar5) {
      return 0;
    }
  } while( true );
}



/* 0041e360  FUN_0041e360  285 bytes, 4 callers */

undefined4 __cdecl FUN_0041e360(char *param_1)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar4;
  int iVar5;
  
  iVar3 = DAT_0043756c * 0x224 + DAT_00434538;
  if (((*(byte *)(iVar3 + 0xd) & 0x10) == 0) && (*(uint *)(iVar3 + 8) < 100)) {
    return 0;
  }
  bVar2 = FUN_0041ebf0(DAT_0043644c,DAT_00436450);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    return 0;
  }
  DAT_00433ff0 = 0;
  iVar3 = 1;
  do {
    DAT_00433ff0 = (int)DAT_00433ff0 >> 1;
    iVar5 = (char)(&DAT_00434400)[iVar3] + DAT_0043644c;
    iVar4 = (char)(&DAT_00434410)[iVar3] + DAT_00436450;
    bVar2 = FUN_0041ebf0(iVar5,iVar4);
    if (CONCAT31(extraout_var_00,bVar2) == 1) {
      if ((((DAT_00433ff0 & 8) == 0) &&
          (bVar1 = *(byte *)(DAT_0043453c + 0x10 + (iVar5 * 0x30 + iVar4) * 0x18), bVar1 != 0)) &&
         (bVar1 < 5)) {
        iVar4 = FUN_0041e700(DAT_0043756c,iVar5,iVar4);
        if (iVar4 == 0) {
          *param_1 = (&DAT_00434400)[iVar3];
          param_1[1] = (&DAT_00434410)[iVar3];
          return 1;
        }
      }
    }
    else {
      DAT_00433ff0 = DAT_00433ff0 | 0x80;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 9);
  return 0;
}



/* 0041e480  FUN_0041e480  218 bytes, 3 callers */

undefined4 __cdecl FUN_0041e480(char *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  int iVar3;
  int iVar4;
  
  bVar1 = FUN_0041ebf0(DAT_0043644c,DAT_00436450);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    return 0;
  }
  DAT_00433ff0 = 0;
  iVar4 = 1;
  do {
    DAT_00433ff0 = (int)DAT_00433ff0 >> 1;
    iVar2 = (char)(&DAT_00434400)[iVar4] + DAT_0043644c;
    iVar3 = (char)(&DAT_00434410)[iVar4] + DAT_00436450;
    bVar1 = FUN_0041ebf0(iVar2,iVar3);
    if (CONCAT31(extraout_var_00,bVar1) == 1) {
      if (*(char *)(DAT_0043453c + 0x10 + (iVar2 * 0x30 + iVar3) * 0x18) == '{') {
        iVar2 = FUN_0041e700(DAT_0043756c,iVar2,iVar3);
        if (iVar2 == 0) {
          *param_1 = (&DAT_00434400)[iVar4];
          param_1[1] = (&DAT_00434410)[iVar4];
          return 1;
        }
      }
    }
    else {
      DAT_00433ff0 = DAT_00433ff0 | 0x80;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 9);
  return 0;
}



/* 0041e560  FUN_0041e560  262 bytes, 4 callers */

undefined4 __cdecl FUN_0041e560(char *param_1)

{
  char cVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((uint)*(byte *)(DAT_0043453c + 0x10 + (DAT_0043644c * 0x30 + DAT_00436450) * 0x18) -
      DAT_00437580 == 8) {
    return 0;
  }
  iVar4 = 1;
  DAT_00433ff0 = 0;
  cVar1 = (char)DAT_00437580;
  do {
    DAT_00433ff0 = (int)DAT_00433ff0 >> 1;
    iVar5 = (char)(&DAT_00434400)[iVar4] + DAT_0043644c;
    iVar3 = (char)(&DAT_00434410)[iVar4] + DAT_00436450;
    bVar2 = FUN_0041ebf0(iVar5,iVar3);
    if (CONCAT31(extraout_var,bVar2) == 1) {
      if (((DAT_00433ff0 & 8) == 0) &&
         (*(char *)(DAT_0043453c + 0x10 + (iVar5 * 0x30 + iVar3) * 0x18) == (char)(cVar1 + '\b'))) {
        iVar3 = FUN_0041e700(DAT_0043756c,iVar5,iVar3);
        if (iVar3 == 0) {
          *param_1 = (&DAT_00434400)[iVar4];
          param_1[1] = (&DAT_00434410)[iVar4];
          return 1;
        }
      }
    }
    else {
      DAT_00433ff0 = DAT_00433ff0 | 0x80;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 9);
  return 0;
}



/* 0041e670  FUN_0041e670  131 bytes, 6 callers */

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



/* 0041e700  FUN_0041e700  536 bytes, 9 callers */

undefined4 __cdecl FUN_0041e700(uint param_1,int param_2,int param_3)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  bool bVar4;
  undefined3 extraout_var;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char local_2;
  char local_1;
  
  uVar6 = (uint)*(byte *)(DAT_0043453c + (param_2 * 0x30 + param_3) * 0x18);
  if ((uVar6 != 0x40) && (param_1 != uVar6)) {
    iVar5 = uVar6 * 0x224 + DAT_00434538;
    iVar8 = param_1 * 0x224 + DAT_00434538;
    if ((*(char *)(iVar8 + 4) == *(char *)(iVar5 + 4)) &&
       (100000 < (uint)(*(int *)(iVar5 + 8) + *(int *)(iVar8 + 8)))) {
      return 1;
    }
    if (*(char *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) == *(char *)(iVar5 + 4)) {
      return 1;
    }
    if (*(uint *)(iVar8 + 8) <= *(uint *)(iVar5 + 8)) {
      return 1;
    }
  }
  iVar5 = 1;
  do {
    cVar1 = (&DAT_00434400)[iVar5];
    cVar2 = (&DAT_00434410)[iVar5];
    bVar4 = FUN_0041ebb0(param_2 + cVar1,param_3 + cVar2);
    if ((CONCAT31(extraout_var,bVar4) == 1) &&
       (bVar3 = *(byte *)(DAT_0043453c + ((param_2 + cVar1) * 0x30 + param_3 + cVar2) * 0x18),
       bVar3 < 0x40)) {
      iVar8 = (uint)bVar3 * 0x224;
      iVar7 = DAT_00434538 + iVar8;
      if (*(byte *)(iVar7 + 4) != DAT_00437580) {
        if (*(byte *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) == *(byte *)(iVar7 + 4)) {
          if (*(int *)(DAT_00434538 + 0x18 + param_1 * 0x224) == 0x1f0) {
            return 1;
          }
        }
        else if (*(int *)(iVar7 + 0x18) == 0x1f0) {
          if (*(uint *)(DAT_00434538 + 8 + param_1 * 0x224) < *(uint *)(iVar7 + 8)) {
            return 1;
          }
        }
        else {
          FUN_0041d6d0(*(byte *)(iVar7 + 0xc) + 4 & 7,&local_2);
          if ((((&DAT_00434400)[iVar5] == local_2) && ((&DAT_00434410)[iVar5] == local_1)) &&
             (*(uint *)(DAT_00434538 + 8 + param_1 * 0x224) < *(uint *)(DAT_00434538 + 8 + iVar8)))
          {
            return 1;
          }
        }
      }
    }
    iVar5 = iVar5 + 1;
    if (4 < iVar5) {
      return 0;
    }
  } while( true );
}



/* 0041e920  FUN_0041e920  568 bytes, 2 callers */

undefined4 __cdecl FUN_0041e920(uint param_1,uint param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char local_e;
  char local_d;
  uint local_c;
  int local_8;
  int local_4;
  
  local_8 = param_1 * 0x224;
  if (((*(byte *)(DAT_00434538 + 0xd + local_8) & 0x20) != 0) &&
     (iVar5 = DAT_00437580 * 0x38 + DAT_00434534, *(byte *)(iVar5 + 8) == param_2)) {
    uVar4 = (uint)*(byte *)(iVar5 + 9);
    if (param_3 == uVar4) {
      return 0;
    }
    if ((int)(param_3 - uVar4) < 3) {
      cVar1 = '\x02';
      iVar5 = param_3 - 1;
      local_c = param_2;
LAB_0041ea4e:
      *(char *)(DAT_00434538 + 0xc + local_8) = cVar1;
      *(undefined4 *)(DAT_00434538 + 0x18 + local_8) = 0x1f0;
      iVar2 = FUN_00420c60(local_c,iVar5);
      if (iVar2 != 0) {
        return 1;
      }
      iVar2 = FUN_00420610(local_c,iVar5);
      if (iVar2 != 0) {
        return 1;
      }
      iVar2 = (local_c * 0x30 + iVar5) * 0x18;
      if (*(byte *)(DAT_0043453c + iVar2) < 0x40) {
        return 0;
      }
      iVar3 = FUN_004208b0(local_c,iVar5);
      if (iVar3 != 1) {
        *(undefined1 *)(DAT_0043453c + (param_2 * 0x30 + param_3) * 0x18) = 0x40;
        *(undefined1 *)(DAT_0043453c + iVar2) = (undefined1)DAT_0043756c;
        *(undefined1 *)(DAT_00434538 + DAT_0043756c * 0x224) = (undefined1)local_c;
        *(char *)(DAT_00434538 + 1 + DAT_0043756c * 0x224) = (char)iVar5;
        return 1;
      }
      return 1;
    }
  }
  iVar2 = 0;
  local_4 = 0;
  do {
    FUN_0041d6d0((uint)*(byte *)(DAT_00434538 + 0xc + local_8) + iVar2 & 6,&local_e);
    iVar5 = FUN_0041ec30(param_2,param_3,(int)local_e,(int)local_d);
    if (iVar5 == 1) {
      local_c = (int)local_e + param_2;
      iVar5 = (int)local_d + param_3;
      if ((*(byte *)(DAT_0043453c + 0x10 + (local_c * 0x30 + iVar5) * 0x18) < 0x30) &&
         (iVar3 = FUN_0041e700(param_1,local_c,iVar5), iVar3 == 0)) {
        cVar1 = ((byte)local_4 & 3) * '\x02';
        goto LAB_0041ea4e;
      }
    }
    iVar2 = iVar2 + 2;
    local_4 = local_4 + 1;
    if (7 < iVar2) {
      return 1;
    }
  } while( true );
}



/* 0041eb60  FUN_0041eb60  72 bytes, 4 callers */

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



/* 0041ebb0  FUN_0041ebb0  55 bytes, 4 callers */

bool __cdecl FUN_0041ebb0(int param_1,int param_2)

{
  if ((((param_1 < 0x2f) && (param_2 < 0x2f)) && (0 < param_1)) && (0 < param_2)) {
    return *(char *)(DAT_0043453c + 4 + (param_1 * 0x30 + param_2) * 0x18) == '\0';
  }
  return false;
}



/* 0041ebf0  FUN_0041ebf0  55 bytes, 7 callers */

bool __cdecl FUN_0041ebf0(int param_1,int param_2)

{
  if ((((param_2 < 0x2f) && (param_1 < 0x2f)) && (0 < param_1)) && (0 < param_2)) {
    return *(char *)(DAT_0043453c + 5 + (param_1 * 0x30 + param_2) * 0x18) == '\0';
  }
  return false;
}



/* 0041ec30  FUN_0041ec30  43 bytes, 8 callers */

undefined4 __cdecl FUN_0041ec30(int param_1,int param_2,int param_3,int param_4)

{
  if ((((0 < param_3 + param_1) && (param_3 + param_1 < 0x30)) && (0 < param_2 + param_4)) &&
     (param_2 + param_4 < 0x30)) {
    return 1;
  }
  return 0;
}



/* 0041ec60  FUN_0041ec60  89 bytes, 7 callers */

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



/* 0041ecc0  FUN_0041ecc0  331 bytes, 1 callers */

undefined4 __cdecl FUN_0041ecc0(int param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  bool bVar5;
  undefined3 extraout_var;
  int iVar6;
  int iVar7;
  char local_4;
  char local_3;
  char local_2;
  char local_1;
  
  iVar7 = 0;
  do {
    cVar2 = (&DAT_00434400)[iVar7];
    cVar3 = (&DAT_00434410)[iVar7];
    bVar5 = FUN_0041ebb0(param_2 + cVar2,param_3 + cVar3);
    if ((CONCAT31(extraout_var,bVar5) == 1) &&
       (bVar4 = *(byte *)(DAT_0043453c + ((param_2 + cVar2) * 0x30 + param_3 + cVar3) * 0x18),
       bVar4 < 0x40)) {
      iVar6 = DAT_00434538 + param_1 * 0x224;
      iVar1 = (uint)bVar4 * 0x224;
      if ((*(char *)(iVar6 + 4) != *(char *)(DAT_00434538 + 4 + iVar1)) &&
         (*(int *)(DAT_00434538 + iVar1 + 0x18) != 0x1f0)) {
        FUN_0041d6d0((uint)*(byte *)(iVar6 + 0xc),&local_4);
        FUN_0041d6d0(*(byte *)(DAT_00434538 + 0xc + iVar1) + 4 & 7,&local_2);
        if ((local_2 == local_4) && (local_1 == local_3)) {
          iVar6 = DAT_00434538 + param_1 * 0x224;
          if (*(char *)(DAT_00434534 + 0x1e + (uint)*(byte *)(iVar6 + 4) * 0x38) ==
              *(char *)(DAT_00434538 + iVar1 + 4)) {
            return 1;
          }
          if (*(uint *)(iVar6 + 8) < *(uint *)(DAT_00434538 + iVar1 + 8)) {
            return 1;
          }
        }
      }
    }
    iVar7 = iVar7 + 1;
    if (3 < iVar7) {
      return 0;
    }
  } while( true );
}



/* 0041ee10  FUN_0041ee10  137 bytes, 2 callers */

void __cdecl FUN_0041ee10(int param_1,int param_2,char *param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  param_3[1] = '\0';
  param_3[2] = '\0';
  *param_3 = '\0';
  do {
    cVar1 = (&DAT_00434420)[iVar5];
    cVar2 = (&DAT_00434428)[iVar5];
    uVar4 = (uint)*(byte *)(DAT_0043453c + 0x10 +
                           ((cVar1 + param_1) * 0x30 + param_2 + cVar2) * 0x18);
    if (DAT_00437580 - uVar4 == -0xc) {
      *param_3 = *param_3 + '\x01';
    }
    else if (uVar4 == 0) {
      cVar3 = param_3[1];
      param_3[1] = cVar3 + '\x01';
      if ((char)(cVar3 + '\x01') == '\x01') {
        param_3[3] = (char)(cVar1 + param_1);
        param_3[4] = (char)(param_2 + cVar2);
      }
    }
    else if ((uVar4 < 0xd) && (uVar4 < 0x10)) {
      param_3[2] = param_3[2] + '\x01';
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 8);
  return;
}



/* 0041eea0  FUN_0041eea0  211 bytes, 1 callers */

int __cdecl FUN_0041eea0(uint param_1,int param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  iVar3 = 1;
  do {
    bVar1 = *(byte *)(DAT_0043453c +
                     (((char)(&DAT_00434400)[iVar3] + param_2) * 0x30 +
                      (int)(char)(&DAT_00434410)[iVar3] + param_3) * 0x18);
    if ((((bVar1 < 0x40) && (bVar1 != param_1)) &&
        (iVar5 = (uint)bVar1 * 0x224 + DAT_00434538, *(byte *)(iVar5 + 4) != DAT_00437580)) &&
       (*(char *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) != *(char *)(iVar5 + 4))) {
      uVar2 = *(int *)(iVar5 + 8) + uVar4;
      uVar4 = 0xffffffff;
      if (uVar2 != 0xffffffff) {
        uVar4 = uVar2;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 5);
  if (uVar4 == 0) {
    return 8;
  }
  return (-(uint)(uVar4 < *(uint *)(DAT_00434538 + 8 + param_1 * 0x224)) & 0xfffffffe) + 9;
}



/* 0041ef80  FUN_0041ef80  157 bytes, 4 callers */

undefined4 __cdecl FUN_0041ef80(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char local_2;
  char local_1;
  
  iVar2 = 0;
  do {
    FUN_0041d6d0((uint)*(byte *)(DAT_00434538 + 0xc + param_1 * 0x224) + iVar2 & 6,&local_2);
    iVar1 = FUN_0041ec30(param_2,param_3,(int)local_2,(int)local_1);
    if (iVar1 == 1) {
      iVar1 = FUN_00420c60(local_2 + param_2,local_1 + param_3);
      if (iVar1 == 1) {
        return 1;
      }
    }
    iVar2 = iVar2 + 2;
  } while (iVar2 < 8);
  return 0;
}



/* 0041f020  FUN_0041f020  99 bytes, 1 callers */

bool __cdecl FUN_0041f020(undefined4 param_1,int param_2,int param_3,char *param_4)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = FUN_0041ec30(param_2,param_3,(int)*param_4,(int)param_4[1]);
  if (iVar1 == 0) {
    return false;
  }
  pbVar2 = (byte *)(((param_2 + *param_4) * 0x30 + param_4[1] + param_3) * 0x18 + DAT_0043453c);
  if (0x2f < pbVar2[0x10]) {
    return false;
  }
  return (bool)('\x01' - (*pbVar2 < 0x40));
}



/* 0041f090  FUN_0041f090  55 bytes, 1 callers */

void FUN_0041f090(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = 0;
  do {
    uVar1 = *(uint *)(DAT_00434534 + 4 + iVar3);
    if (((uVar1 & 0x40) == 0) && (((uVar1 >> 4 | uVar1) & 1) != 0)) {
      FUN_0041f0d0(uVar2);
    }
    iVar3 = iVar3 + 0x38;
    uVar2 = uVar2 + 1;
  } while (iVar3 < 0xe0);
  return;
}



/* 0041f0d0  FUN_0041f0d0  681 bytes, 1 callers */

void __cdecl FUN_0041f0d0(uint param_1)

{
  uint *puVar1;
  int iVar2;
  byte *pbVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = param_1 * 0x38;
  if ((*(byte *)(DAT_00434534 + iVar2 + 4) & 1) == 0) {
    FUN_00420aa0(*(int *)(DAT_00434534 + iVar2 + 0xc),4);
  }
  if (DAT_004344e8 != (void *)0x0) {
    FUN_00424520(DAT_004344e8,param_1);
  }
  *(undefined1 *)
   (DAT_0043453c + 0x10 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  *(undefined1 *)
   (DAT_0043453c + 0x28 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  *(undefined1 *)
   (DAT_0043453c + -0x458 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  *(undefined1 *)
   (DAT_0043453c + -0x470 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  *(undefined1 *)
   (DAT_0043453c + -0x488 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  *(undefined1 *)
   (DAT_0043453c + -8 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  *(undefined1 *)
   (DAT_0043453c + 0x478 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  *(undefined1 *)
   (DAT_0043453c + 0x490 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  *(undefined1 *)
   (DAT_0043453c + 0x4a8 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  piVar6 = (int *)(DAT_00434534 + 0x18 + (uint)*(byte *)(DAT_00434534 + iVar2 + 0x1f) * 0x38);
  *piVar6 = *piVar6 + *(int *)(DAT_00434534 + iVar2 + 0x18);
  puVar1 = (uint *)(DAT_00434534 + 0x18 + (uint)*(byte *)(DAT_00434534 + 0x1f + iVar2) * 0x38);
  if (100000 < *puVar1) {
    *puVar1 = 100000;
  }
  cVar4 = '\0';
  *(undefined4 *)(DAT_00434534 + 0x18 + iVar2) = 0;
  *(undefined1 *)(DAT_00434534 + 0x1c + iVar2) = 0;
  puVar1 = (uint *)(DAT_00434534 + 4 + iVar2);
  *puVar1 = *puVar1 | 0x40;
  FUN_00405330();
  iVar2 = 4;
  pbVar3 = (byte *)(DAT_00434534 + 4);
  do {
    if ((*pbVar3 & 0x40) != 0) {
      cVar4 = cVar4 + '\x01';
    }
    pbVar3 = pbVar3 + 0x38;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (cVar4 == '\x02') {
    iVar5 = 0;
    iVar2 = 0;
    piVar6 = &DAT_004344f8;
    do {
      if (((*(uint *)(DAT_00434534 + iVar5 + 4) & 0x40) == 0) &&
         (*(byte *)(DAT_00434534 + iVar5 + 0x1e) < 4)) {
        FUN_004095d0(0x7a,CONCAT31((int3)((uint)(iVar2 << 0x10) >> 8),1),*(HWND *)(DAT_004344e4 + 8)
                    );
        *(undefined1 *)(DAT_00434534 + 0x1e + iVar5) = 0x80;
      }
      if ((int *)*piVar6 != (int *)0x0) {
        (**(code **)(*(int *)*piVar6 + 0x1c))();
        (**(code **)(*(int *)*piVar6 + 100))();
      }
      piVar6 = piVar6 + 1;
      iVar5 = iVar5 + 0x38;
      iVar2 = iVar2 + 1;
    } while (iVar5 < 0xe0);
  }
  FUN_00408e40();
  return;
}



/* 0041f380  FUN_0041f380  97 bytes, 1 callers */

undefined4 __cdecl FUN_0041f380(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 < 0) || (0x2f < param_1)) {
    return 1;
  }
  if ((param_2 < 0) || (0x2f < param_2)) {
    return 1;
  }
  uVar1 = (uint)*(byte *)(DAT_0043453c + 0x10 + (param_1 * 0x30 + param_2) * 0x18);
  iVar2 = uVar1 - 0x60;
  if ((-1 < iVar2) && (iVar2 < 0x10)) {
    return 1;
  }
  iVar2 = uVar1 - 5;
  if ((-1 < iVar2) && (iVar2 < 1)) {
    return 1;
  }
  return 0;
}



/* 0041f3f0  FUN_0041f3f0  107 bytes, 1 callers */

bool __cdecl FUN_0041f3f0(int param_1,int param_2)

{
  uint uVar1;
  
  if ((param_1 < 0) || (0x2f < param_1)) {
    return true;
  }
  if ((param_2 < 0) || (0x2f < param_2)) {
    return true;
  }
  uVar1 = (uint)*(byte *)(DAT_0043453c + 0x10 + (param_1 * 0x30 + param_2) * 0x18);
  if ((-1 < (int)(uVar1 - 0x30)) && ((int)(uVar1 - 0x30) < 0x30)) {
    return true;
  }
  if ((-1 < (int)(uVar1 - 0x20)) && ((int)(uVar1 - 0x20) < 0x10)) {
    return true;
  }
  return uVar1 == 0x7a;
}



/* 0041f460  FUN_0041f460  94 bytes, 1 callers */

undefined4 __cdecl FUN_0041f460(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 < 0) || (0x2f < param_1)) {
    return 1;
  }
  if ((param_2 < 0) || (0x2f < param_2)) {
    return 1;
  }
  uVar1 = (uint)*(byte *)(DAT_0043453c + 0x10 + (param_1 * 0x30 + param_2) * 0x18);
  iVar2 = uVar1 - 0x30;
  if ((-1 < iVar2) && (iVar2 < 0x30)) {
    return 0;
  }
  iVar2 = uVar1 - 0x60;
  if ((-1 < iVar2) && (iVar2 < 0x10)) {
    return 0;
  }
  return 1;
}



/* 0041f4c0  FUN_0041f4c0  512 bytes, 1 callers */

undefined4 FUN_0041f4c0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = 0;
  if (((byte)DAT_00435b1c & 3) == 3) {
    FUN_0041b640();
  }
  iVar1 = 4;
  puVar5 = (uint *)(DAT_00434534 + 4);
  puVar4 = puVar5;
  do {
    uVar6 = *puVar4;
    if ((((uVar6 & 0x40) != 0) && ((uVar6 & 1) != 0)) && ((uVar6 & 0x10) != 0)) {
      iVar7 = iVar7 + 1;
    }
    puVar4 = puVar4 + 0xe;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((*(byte *)(DAT_00434534 + 4 + (uint)DAT_004365cd * 0x38) & 0x40) == 0) {
    if (iVar7 < 3) {
      return 0;
    }
    iVar7 = 0;
    piVar2 = (int *)(DAT_0043453c + 0x14);
    do {
      if (*piVar2 != 0) {
        return 0;
      }
      piVar2 = piVar2 + 6;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x900);
    iVar7 = 0;
    DAT_004365d0 = 0;
    do {
      if ((*puVar5 & 0x40) == 0) {
        DAT_00436400 = (byte)iVar7;
        break;
      }
      puVar5 = puVar5 + 0xe;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 4);
    DAT_00436408 = DAT_004365bc;
    DAT_00436410 = DAT_004365c4;
    FUN_0041aaf0();
    FUN_0041aa30();
    DAT_00436404 = DAT_00436410;
    if (DAT_00436410 != 0) {
      DAT_00436404 = (DAT_00436410 - DAT_00436420) + DAT_00436430;
    }
    if ((DAT_004365cc != '\0') && ((int)DAT_0043450c < DAT_004376cc)) {
      FUN_0041b0e0();
      FUN_0041b140();
    }
  }
  uVar6 = 0;
  DAT_004365d0 = 0;
  if (DAT_00436410 == 0) {
    uVar6 = 1;
  }
  else if (DAT_0043643d != '\0') {
    uVar6 = 3;
  }
  if (DAT_004365cc == '\0') {
    uVar6 = 4;
  }
  if ((*(byte *)(DAT_00434534 + 4 + (uint)DAT_004365cd * 0x38) & 0x40) != 0) {
    uVar6 = 2;
  }
  DAT_004365d4 = 0xffffffff;
  DAT_00434524 = 1;
  FUN_00408e40();
  FUN_0041b640();
  FUN_0040a800();
  FUN_004095d0(0x69,uVar6,*(HWND *)(DAT_004344e4 + 8));
  if ((uVar6 != 2) && (uVar6 != 1)) {
    if (uVar6 != 4) {
      if ((DAT_004365cd == DAT_00436400) && (FUN_0041f6c0(), DAT_0043643c != '\0')) {
        FUN_004057f0();
      }
      return 1;
    }
    return 1;
  }
  DAT_00434510 = 0xffffffff;
  uVar3 = FUN_00405de0(DAT_0043450c);
  return uVar3;
}



/* 0041f6c0  FUN_0041f6c0  194 bytes, 1 callers */

void FUN_0041f6c0(void)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  uVar1 = 0;
  DAT_004365d4 = 0xffffffff;
  if (-1 < DAT_00436a00) {
    puVar3 = &DAT_00436a0c;
    iVar2 = DAT_00436a00 + 1;
    do {
      if (uVar1 < *puVar3) {
        uVar1 = *puVar3;
      }
      puVar3 = puVar3 + 0xe;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if (uVar1 < 100000) {
    if (uVar1 < 10000) {
      uVar1 = uVar1 / 1000;
    }
    else {
      uVar1 = uVar1 / 10000 + 9;
    }
  }
  else {
    uVar1 = 0x13;
  }
  if (DAT_004376cc - DAT_0043450c == 1) {
    DAT_00436a00 = DAT_004376cc + -1;
    DAT_00436a04 = uVar1;
    FUN_00409570();
  }
  else {
    if (((int)DAT_00436a04 < (int)uVar1) && (uVar1 != 0)) {
      DAT_00436a04 = uVar1;
      FUN_004095d0(0x72,0,*(HWND *)(DAT_004344e4 + 8));
    }
    if (DAT_0043450c - DAT_00436a00 == -1) {
      FUN_004067c0();
      return;
    }
  }
  return;
}



/* 0041f790  FUN_0041f790  284 bytes, 1 callers */

void FUN_0041f790(void)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    *(undefined1 *)(DAT_00434538 + 0x220 + iVar3) = 0xff;
    iVar1 = DAT_00434538 + iVar3;
    if (((*(byte *)(iVar1 + 0x10) & 0x80) == 0) && (*(byte *)(iVar1 + 4) == DAT_004365cd)) {
      if ((*(byte *)(iVar1 + 0xd) & 0x20) == 0) {
        if (((*(byte *)(iVar1 + 0x10) & 4) != 0) || ((*(byte *)(iVar1 + 0xd) & 0x10) != 0)) {
          *(byte *)(iVar1 + 0x220) = ((byte)(DAT_00435b1c >> 1) & 1) + 10;
        }
        if (DAT_0043451c == -1) {
          bVar2 = *(byte *)(DAT_00434538 + iVar3 + 0xd) & 0xf;
          if ((4 < bVar2) && (bVar2 < 8)) {
            *(byte *)(DAT_00434538 + iVar3 + 0x220) = ((byte)(DAT_00435b1c >> 1) & 1) + 8;
          }
        }
        iVar1 = DAT_00434538 + iVar3;
        if ((*(uint *)(iVar1 + 8) < 100) && ((*(byte *)(iVar1 + 0xd) & 0xf) == 2)) {
          *(byte *)(iVar1 + 0x220) = ((byte)(DAT_00435b1c >> 1) & 1) + 6;
        }
      }
      else if ((*(int *)(iVar1 + 0x18) != 0x1f0) ||
              ((*(byte *)(DAT_00434534 + 4 + (uint)DAT_004365cd * 0x38) & 2) != 0)) {
        *(byte *)(iVar1 + 0x220) = ((byte)(DAT_00435b1c >> 1) & 3) + 0xc;
      }
    }
    iVar3 = iVar3 + 0x224;
  } while (iVar3 < 0x8900);
  return;
}



/* 0041f8b0  FUN_0041f8b0  80 bytes, 13 callers */

int __fastcall FUN_0041f8b0(int param_1)

{
  HCURSOR hCursor;
  
  hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
  SetCursor(hCursor);
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  wsprintfA((LPSTR)(param_1 + 0x110),&DAT_00433ff4);
  return param_1;
}



/* 0041f900  FUN_0041f900  41 bytes, 20 callers */

void __fastcall FUN_0041f900(undefined2 *param_1)

{
  HCURSOR hCursor;
  
  hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  SetCursor(hCursor);
  if (*(int *)(param_1 + 0x84) != 0) {
    FUN_0041fa40(param_1);
  }
  return;
}



/* 0041f930  FUN_0041f930  98 bytes, 3 callers */

undefined4 __thiscall
FUN_0041f930(void *this,LPCSTR param_1,LPVOID param_2,DWORD param_3,int param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  lstrcpyA(this,param_1);
  if (*(int *)((int)this + 0x108) != -1) {
    FUN_0041fa40(this);
  }
  bVar1 = FUN_0041f9f0(this,param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iVar2 = FUN_0041fa80(this,param_2,param_3,param_4);
    if (iVar2 != 0) {
      iVar2 = FUN_0041fa40(this);
      if (iVar2 != 0) {
        return 1;
      }
    }
  }
  return 0;
}



/* 0041f9a0  FUN_0041f9a0  74 bytes, 2 callers */

bool __thiscall FUN_0041f9a0(void *this,LPCSTR param_1)

{
  HANDLE pvVar1;
  
  lstrcpyA(this,param_1);
  pvVar1 = CreateFileA(param_1,0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,4,0,(HANDLE)0x0);
  *(HANDLE *)((int)this + 0x108) = pvVar1;
  if (pvVar1 == (HANDLE)0xffffffff) {
    FUN_0041fc90(this);
    return false;
  }
  return (bool)('\x01' - (pvVar1 == (HANDLE)0x0));
}



/* 0041f9f0  FUN_0041f9f0  78 bytes, 6 callers */

bool __thiscall FUN_0041f9f0(void *this,LPCSTR param_1)

{
  HANDLE pvVar1;
  
  lstrcpyA(this,param_1);
  pvVar1 = CreateFileA(param_1,0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  *(HANDLE *)((int)this + 0x108) = pvVar1;
  if (pvVar1 == (HANDLE)0xffffffff) {
    FUN_0041fc90(this);
    return false;
  }
  return (bool)('\x01' - (pvVar1 == (HANDLE)0xffffffff));
}



/* 0041fa40  FUN_0041fa40  60 bytes, 11 callers */

undefined4 __fastcall FUN_0041fa40(undefined2 *param_1)

{
  BOOL BVar1;
  
  if (*(HANDLE *)(param_1 + 0x84) == (HANDLE)0xffffffff) {
    return 1;
  }
  BVar1 = CloseHandle(*(HANDLE *)(param_1 + 0x84));
  if (BVar1 == 0) {
    FUN_0041fc90(param_1);
    return 0;
  }
  *(undefined4 *)(param_1 + 0x84) = 0xffffffff;
  return 1;
}



/* 0041fa80  FUN_0041fa80  321 bytes, 4 callers */

undefined4 __thiscall FUN_0041fa80(void *this,LPVOID param_1,DWORD param_2,int param_3)

{
  uint nNumberOfBytesToRead;
  undefined4 uVar1;
  BOOL BVar2;
  int iVar3;
  LPVOID *ppvVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_38 [3];
  LPVOID local_2c [2];
  DWORD local_24;
  uint local_20;
  LPVOID local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041fb8c;
  *unaff_FS_OFFSET = &local_10;
  if (param_3 == 0) {
    BVar2 = ReadFile(*(HANDLE *)((int)this + 0x108),param_1,param_2,(LPDWORD)((int)this + 0x10c),
                     (LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      FUN_0041fc90(this);
      uVar1 = 0;
      goto LAB_0041fb79;
    }
    if (*(LPDWORD)((int)this + 0x10c) != param_2) {
      uVar1 = 0;
      goto LAB_0041fb79;
    }
  }
  else {
    FUN_00425bd0(local_38);
    local_8 = 0;
    nNumberOfBytesToRead = FUN_0041fbe0((int)this);
    local_14 = (LPVOID)FUN_00425c00(local_38,nNumberOfBytesToRead);
    if (local_14 == (LPVOID)0x0) {
      local_8 = 0xffffffff;
      FUN_0041fb96();
      uVar1 = 0;
      goto LAB_0041fb79;
    }
    BVar2 = ReadFile(*(HANDLE *)((int)this + 0x108),local_14,nNumberOfBytesToRead,
                     (LPDWORD)((int)this + 0x10c),(LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      FUN_0041fc90(this);
      local_8 = 0xffffffff;
      FUN_0041fb96();
      uVar1 = 0;
      goto LAB_0041fb79;
    }
    if (*(LPDWORD)((int)this + 0x10c) != nNumberOfBytesToRead) {
      local_8 = 0xffffffff;
      FUN_0041fb96();
      uVar1 = 0;
      goto LAB_0041fb79;
    }
    ppvVar4 = local_2c;
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppvVar4 = (LPVOID)0x0;
      ppvVar4 = ppvVar4 + 1;
    }
    local_2c[0] = param_1;
    local_2c[1] = local_14;
    local_24 = param_2;
    local_20 = nNumberOfBytesToRead;
    iVar3 = FUN_0041fe40(this,local_2c);
    local_8 = 0xffffffff;
    if (iVar3 != 0) {
      FUN_0041fb96();
      uVar1 = 0;
      goto LAB_0041fb79;
    }
    FUN_0041fb96();
  }
  uVar1 = 1;
LAB_0041fb79:
  *unaff_FS_OFFSET = local_10;
  return uVar1;
}



/* 0041fb96  FUN_0041fb96  8 bytes, 1 callers */

void FUN_0041fb96(void)

{
  int unaff_EBP;
  
  FUN_00425be0((int *)(unaff_EBP + -0x34));
  return;
}



/* 0041fbe0  FUN_0041fbe0  41 bytes, 1 callers */

uint __fastcall FUN_0041fbe0(int param_1)

{
  DWORD DVar1;
  
  if (*(HANDLE *)(param_1 + 0x108) == (HANDLE)0x0) {
    return 0;
  }
  DVar1 = GetFileSize(*(HANDLE *)(param_1 + 0x108),(LPDWORD)0x0);
  return (DVar1 == 0xffffffff) - 1 & DVar1;
}



/* 0041fc10  FUN_0041fc10  68 bytes, 2 callers */

BOOL __thiscall FUN_0041fc10(void *this,LPCVOID param_1,DWORD param_2)

{
  BOOL BVar1;
  
  BVar1 = WriteFile(*(HANDLE *)((int)this + 0x108),param_1,param_2,(LPDWORD)((int)this + 0x10c),
                    (LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    FUN_0041fc90(this);
    return 0;
  }
  if (*(LPDWORD)((int)this + 0x10c) != param_2) {
    BVar1 = 0;
  }
  return BVar1;
}



/* 0041fc60  FUN_0041fc60  39 bytes, 1 callers */

undefined4 __thiscall FUN_0041fc60(void *this,LPCSTR param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_0041f9f0(this,param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    FUN_0041fa40(this);
    return 1;
  }
  return 0;
}



/* 0041fc90  FUN_0041fc90  273 bytes, 5 callers */

void __fastcall FUN_0041fc90(undefined2 *param_1)

{
  undefined2 local_108;
  undefined1 local_106;
  undefined1 local_105;
  CHAR local_104 [260];
  
  local_108 = *param_1;
  local_106 = *(undefined1 *)(param_1 + 1);
  local_105 = 0;
  wsprintfA(&DAT_00435ed0,s_Drive__s_0043410c,&local_108);
  DAT_00434530 = GetLastError();
  switch(DAT_00434530) {
  case 3:
  case 0x13:
    lstrcatA(&DAT_00435ed0,s_Please_check_the_write_protectio_004340b0);
    return;
  default:
    wsprintfA(local_104,s_Could_not_complete_file_operatio_00434008,DAT_00434530);
    lstrcatA(&DAT_00435ed0,local_104);
    return;
  case 5:
  case 0x15:
    lstrcatA(&DAT_00435ed0,s_Please_set_disk__004340d8);
    return;
  case 0xb:
    lstrcatA(&DAT_00435ed0,s_Please_format_disk_00434040);
    return;
  case 0xe:
    lstrcatA(&DAT_00435ed0,s_Not_enough_memory_to_continue__00434090);
    return;
  case 0x1a:
    lstrcatA(&DAT_00435ed0,s_Please_insert_disk_into_drive__004340ec);
    return;
  case 0x70:
    lstrcatA(&DAT_00435ed0,s_Disk_full_please_insert_another_f_00434054);
    return;
  }
}



/* 0041fe40  FUN_0041fe40  173 bytes, 1 callers */

undefined4 __thiscall FUN_0041fe40(void *this,undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  char *pcVar3;
  uint uVar4;
  
  *(undefined4 *)((int)this + 0x214) = param_1;
  uVar4 = 0;
  while( true ) {
    iVar1 = *(int *)((int)this + 0x214);
    if (*(uint *)(iVar1 + 0xc) <= uVar4) {
      return 1;
    }
    *(undefined2 *)(iVar1 + 0x10) = **(undefined2 **)(iVar1 + 4);
    iVar1 = *(int *)((int)this + 0x214);
    uVar4 = uVar4 + *(ushort *)(iVar1 + 0x10);
    if (*(uint *)(iVar1 + 0xc) <= uVar4) break;
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 2;
    if (**(char **)(*(int *)((int)this + 0x214) + 4) == '\0') {
      FUN_00420240(this);
    }
    else {
      FUN_0041fef0((int)this);
    }
    pcVar2 = *(code **)(*(int *)((int)this + 0x214) + 0x14);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(*(int *)((int)this + 0x214));
    }
    uVar4 = uVar4 + 1;
    iVar1 = *(int *)((int)this + 0x214);
    if (*(int *)(iVar1 + 0xc) + 1U <= uVar4) {
      return 1;
    }
    pcVar3 = *(char **)(iVar1 + 4);
    *(char **)(iVar1 + 4) = pcVar3 + 1;
    if (*pcVar3 == '\0') {
      return 0;
    }
  }
  return 1;
}



/* 0041fef0  FUN_0041fef0  838 bytes, 1 callers */

void __fastcall FUN_0041fef0(int param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  byte *pbVar4;
  short sVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  uint uVar9;
  ushort uVar10;
  int iVar11;
  
  *(undefined2 *)(param_1 + 0x218) = 2;
  if (*(short *)(*(int *)(param_1 + 0x214) + 0x10) != 2) {
    do {
      piVar6 = (int *)(*(int *)(param_1 + 0x214) + 4);
      bVar1 = **(byte **)(*(int *)(param_1 + 0x214) + 4);
      *piVar6 = *piVar6 + 1;
      sVar5 = *(short *)(param_1 + 0x218) + 1;
      *(short *)(param_1 + 0x218) = sVar5;
      if ((bVar1 & 0x80) == 0) {
        if ((bVar1 & 0x40) == 0) {
          if ((bVar1 & 0x20) == 0) {
            *(ushort *)(param_1 + 0x218) = sVar5 + (bVar1 & 0x1f);
            piVar6 = (int *)(*(int *)(param_1 + 0x214) + 8);
            *piVar6 = *piVar6 + (uint)(bVar1 & 0x1f);
            iVar11 = 0;
            if ((bVar1 & 0x1f) != 0) {
              do {
                iVar11 = iVar11 + 1;
                *(undefined1 *)**(undefined4 **)(param_1 + 0x214) =
                     *(undefined1 *)(*(undefined4 **)(param_1 + 0x214))[1];
                piVar6 = (int *)(*(int *)(param_1 + 0x214) + 4);
                *piVar6 = *piVar6 + 1;
                **(int **)(param_1 + 0x214) = **(int **)(param_1 + 0x214) + 1;
              } while (iVar11 < (int)(uint)(bVar1 & 0x1f));
            }
          }
          else {
            puVar7 = (undefined4 *)(*(int *)(param_1 + 0x214) + 4);
            pbVar4 = (byte *)*puVar7;
            uVar10 = (ushort)*pbVar4 + (bVar1 & 0x1f) * 0x100;
            *puVar7 = pbVar4 + 1;
            *(short *)(param_1 + 0x218) = *(short *)(param_1 + 0x218) + uVar10 + 1;
            uVar9 = (uint)uVar10;
            piVar6 = (int *)(*(int *)(param_1 + 0x214) + 8);
            *piVar6 = *piVar6 + uVar9;
            if (uVar10 != 0) {
              do {
                *(undefined1 *)**(undefined4 **)(param_1 + 0x214) =
                     *(undefined1 *)(*(undefined4 **)(param_1 + 0x214))[1];
                piVar6 = (int *)(*(int *)(param_1 + 0x214) + 4);
                *piVar6 = *piVar6 + 1;
                **(int **)(param_1 + 0x214) = **(int **)(param_1 + 0x214) + 1;
                uVar9 = uVar9 - 1;
              } while (uVar9 != 0);
            }
          }
        }
        else if ((bVar1 & 0x10) == 0) {
          puVar8 = *(undefined1 **)(*(int *)(param_1 + 0x214) + 4);
          uVar3 = *puVar8;
          *(undefined1 **)(*(int *)(param_1 + 0x214) + 4) = puVar8 + 1;
          *(short *)(param_1 + 0x218) = *(short *)(param_1 + 0x218) + 1;
          piVar6 = (int *)(*(int *)(param_1 + 0x214) + 8);
          *piVar6 = *piVar6 + (bVar1 & 0xf) + 4;
          iVar11 = 0;
          if ((bVar1 & 0xf) != 0xfffffffc) {
            do {
              iVar11 = iVar11 + 1;
              *(undefined1 *)**(undefined4 **)(param_1 + 0x214) = uVar3;
              **(int **)(param_1 + 0x214) = **(int **)(param_1 + 0x214) + 1;
            } while (iVar11 < (int)((bVar1 & 0xf) + 4));
          }
        }
        else {
          puVar7 = (undefined4 *)(*(int *)(param_1 + 0x214) + 4);
          pbVar4 = (byte *)*puVar7;
          bVar2 = *pbVar4;
          *puVar7 = pbVar4 + 1;
          puVar8 = *(undefined1 **)(*(int *)(param_1 + 0x214) + 4);
          uVar3 = *puVar8;
          *(undefined1 **)(*(int *)(param_1 + 0x214) + 4) = puVar8 + 1;
          uVar9 = (uint)(ushort)((bVar1 & 0xf) * 0x100 + (ushort)bVar2);
          *(short *)(param_1 + 0x218) = *(short *)(param_1 + 0x218) + 2;
          piVar6 = (int *)(*(int *)(param_1 + 0x214) + 8);
          *piVar6 = *piVar6 + uVar9 + 4;
          for (iVar11 = uVar9 + 4; iVar11 != 0; iVar11 = iVar11 + -1) {
            *(undefined1 *)**(undefined4 **)(param_1 + 0x214) = uVar3;
            **(int **)(param_1 + 0x214) = **(int **)(param_1 + 0x214) + 1;
          }
        }
      }
      else {
        puVar7 = (undefined4 *)(*(int *)(param_1 + 0x214) + 4);
        pbVar4 = (byte *)*puVar7;
        bVar2 = *pbVar4;
        *puVar7 = pbVar4 + 1;
        iVar11 = **(int **)(param_1 + 0x214);
        *(short *)(param_1 + 0x218) = *(short *)(param_1 + 0x218) + 1;
        puVar8 = (undefined1 *)(iVar11 - (uint)(ushort)((ushort)bVar2 + (bVar1 & 0x1f) * 0x100));
        piVar6 = *(int **)(param_1 + 0x214) + 2;
        *piVar6 = *piVar6 + ((bVar1 & 0xffffff60) >> 5) + 4;
        iVar11 = 0;
        if ((bVar1 & 0x60) >> 5 != 0xfffffffc) {
          do {
            uVar3 = *puVar8;
            puVar8 = puVar8 + 1;
            iVar11 = iVar11 + 1;
            *(undefined1 *)**(undefined4 **)(param_1 + 0x214) = uVar3;
            **(int **)(param_1 + 0x214) = **(int **)(param_1 + 0x214) + 1;
          } while (iVar11 < (int)(((bVar1 & 0x60) >> 5) + 4));
        }
        if (*(short *)(*(int *)(param_1 + 0x214) + 0x10) == *(short *)(param_1 + 0x218)) {
          return;
        }
        bVar1 = **(byte **)(*(int *)(param_1 + 0x214) + 4);
        while ((bVar1 & 0xe0) == 0x60) {
          iVar11 = 0;
          if ((bVar1 & 0x1f) != 0) {
            do {
              uVar3 = *puVar8;
              puVar8 = puVar8 + 1;
              iVar11 = iVar11 + 1;
              *(undefined1 *)**(undefined4 **)(param_1 + 0x214) = uVar3;
              **(int **)(param_1 + 0x214) = **(int **)(param_1 + 0x214) + 1;
            } while (iVar11 < (int)(uint)(bVar1 & 0x1f));
          }
          piVar6 = (int *)(*(int *)(param_1 + 0x214) + 4);
          *piVar6 = *piVar6 + 1;
          piVar6 = (int *)(*(int *)(param_1 + 0x214) + 8);
          *piVar6 = *piVar6 + (uint)(bVar1 & 0x1f);
          *(short *)(param_1 + 0x218) = *(short *)(param_1 + 0x218) + 1;
          bVar1 = **(byte **)(*(int *)(param_1 + 0x214) + 4);
        }
      }
    } while (*(short *)(*(int *)(param_1 + 0x214) + 0x10) != *(short *)(param_1 + 0x218));
  }
  return;
}



/* 00420240  FUN_00420240  539 bytes, 1 callers */

void __fastcall FUN_00420240(void *param_1)

{
  undefined1 uVar1;
  byte *pbVar2;
  ushort uVar3;
  short sVar4;
  uint uVar5;
  int *piVar6;
  undefined1 *puVar7;
  ushort uVar8;
  int iVar9;
  
  *(undefined2 *)((int)param_1 + 0x218) = 4;
  piVar6 = (int *)(*(int *)((int)param_1 + 0x214) + 4);
  *(ushort *)((int)param_1 + 0x21a) =
       (ushort)*(byte *)(*(int *)(*(int *)((int)param_1 + 0x214) + 4) + 1);
  *(undefined1 *)((int)param_1 + 0x21c) = 8;
  *piVar6 = *piVar6 + 2;
  do {
    while( true ) {
      while (uVar5 = FUN_00420460((int)param_1), (short)uVar5 == 0) {
        *(undefined1 *)**(undefined4 **)((int)param_1 + 0x214) =
             *(undefined1 *)(*(undefined4 **)((int)param_1 + 0x214))[1];
        piVar6 = (int *)(*(int *)((int)param_1 + 0x214) + 4);
        *piVar6 = *piVar6 + 1;
        **(int **)((int)param_1 + 0x214) = **(int **)((int)param_1 + 0x214) + 1;
        piVar6 = (int *)(*(int *)((int)param_1 + 0x214) + 8);
        *piVar6 = *piVar6 + 1;
        *(short *)((int)param_1 + 0x218) = *(short *)((int)param_1 + 0x218) + 1;
      }
      uVar5 = FUN_00420460((int)param_1);
      if ((short)uVar5 != 0) break;
      pbVar2 = *(byte **)(*(int *)((int)param_1 + 0x214) + 4);
      uVar8 = (ushort)*pbVar2;
      *(byte **)(*(int *)((int)param_1 + 0x214) + 4) = pbVar2 + 1;
      *(short *)((int)param_1 + 0x218) = *(short *)((int)param_1 + 0x218) + 1;
LAB_004202d5:
      uVar5 = FUN_00420460((int)param_1);
      if ((short)uVar5 == 0) {
        uVar5 = FUN_00420460((int)param_1);
        if ((short)uVar5 == 0) {
          uVar5 = FUN_00420460((int)param_1);
          if ((short)uVar5 == 0) {
            uVar5 = FUN_00420460((int)param_1);
            if ((short)uVar5 == 0) {
              uVar5 = FUN_00420460((int)param_1);
              if ((short)uVar5 == 0) {
                pbVar2 = *(byte **)(*(int *)((int)param_1 + 0x214) + 4);
                uVar3 = *pbVar2 + 0xe;
                *(byte **)(*(int *)((int)param_1 + 0x214) + 4) = pbVar2 + 1;
                *(short *)((int)param_1 + 0x218) = *(short *)((int)param_1 + 0x218) + 1;
              }
              else {
                sVar4 = FUN_004204c0(param_1,3);
                uVar3 = sVar4 + 6;
              }
            }
            else {
              uVar3 = 5;
            }
          }
          else {
            uVar3 = 4;
          }
        }
        else {
          uVar3 = 3;
        }
      }
      else {
        uVar3 = 2;
      }
      puVar7 = (undefined1 *)(**(int **)((int)param_1 + 0x214) - (uint)uVar8);
      if (uVar3 != 0) {
        uVar5 = (uint)uVar3;
        do {
          uVar1 = *puVar7;
          puVar7 = puVar7 + 1;
          *(undefined1 *)**(undefined4 **)((int)param_1 + 0x214) = uVar1;
          **(int **)((int)param_1 + 0x214) = **(int **)((int)param_1 + 0x214) + 1;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
      piVar6 = (int *)(*(int *)((int)param_1 + 0x214) + 8);
      *piVar6 = *piVar6 + (uint)uVar3;
    }
    sVar4 = FUN_004204c0(param_1,5);
    pbVar2 = *(byte **)(*(int *)((int)param_1 + 0x214) + 4);
    uVar8 = (ushort)*pbVar2 + sVar4 * 0x100;
    *(byte **)(*(int *)((int)param_1 + 0x214) + 4) = pbVar2 + 1;
    if (uVar8 == 0) {
      return;
    }
    if (uVar8 != 1) goto LAB_004202d5;
    uVar5 = FUN_00420460((int)param_1);
    if ((short)uVar5 == 0) {
      uVar8 = FUN_004204c0(param_1,4);
      sVar4 = uVar8 + 0xf;
    }
    else {
      sVar4 = FUN_004204c0(param_1,4);
      pbVar2 = *(byte **)(*(int *)((int)param_1 + 0x214) + 4);
      uVar8 = (ushort)*pbVar2 + sVar4 * 0x100;
      *(byte **)(*(int *)((int)param_1 + 0x214) + 4) = pbVar2 + 1;
      sVar4 = uVar8 + 0x10;
    }
    *(short *)((int)param_1 + 0x218) = *(short *)((int)param_1 + 0x218) + sVar4;
    puVar7 = *(undefined1 **)(*(int *)((int)param_1 + 0x214) + 4);
    uVar1 = *puVar7;
    *(undefined1 **)(*(int *)((int)param_1 + 0x214) + 4) = puVar7 + 1;
    for (iVar9 = uVar8 + 0xe; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(undefined1 *)**(undefined4 **)((int)param_1 + 0x214) = uVar1;
      **(int **)((int)param_1 + 0x214) = **(int **)((int)param_1 + 0x214) + 1;
    }
    piVar6 = (int *)(*(int *)((int)param_1 + 0x214) + 8);
    *piVar6 = *piVar6 + uVar8 + 0xe;
  } while( true );
}



/* 00420460  FUN_00420460  81 bytes, 2 callers */

uint __fastcall FUN_00420460(int param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  undefined2 *puVar3;
  undefined4 in_EAX;
  undefined2 uVar4;
  int *piVar5;
  
  uVar4 = (undefined2)((uint)in_EAX >> 0x10);
  if (*(char *)(param_1 + 0x21c) == '\0') {
    puVar3 = *(undefined2 **)(*(int *)(param_1 + 0x214) + 4);
    piVar5 = (int *)(*(int *)(param_1 + 0x214) + 4);
    uVar1 = *puVar3;
    uVar4 = (undefined2)((uint)puVar3 >> 0x10);
    *(undefined1 *)(param_1 + 0x21c) = 0x10;
    *(undefined2 *)(param_1 + 0x21a) = uVar1;
    *piVar5 = *piVar5 + 2;
    *(short *)(param_1 + 0x218) = *(short *)(param_1 + 0x218) + 2;
  }
  uVar2 = *(ushort *)(param_1 + 0x21a);
  *(char *)(param_1 + 0x21c) = *(char *)(param_1 + 0x21c) + -1;
  *(ushort *)(param_1 + 0x21a) = uVar2 >> 1;
  return CONCAT22(uVar4,uVar2) & 0xffff0001;
}



/* 004204c0  FUN_004204c0  38 bytes, 1 callers */

undefined2 __thiscall FUN_004204c0(void *this,int param_1)

{
  uint uVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  for (; param_1 != 0; param_1 = param_1 + -1) {
    uVar1 = FUN_00420460((int)this);
    iVar3 = uVar1 + iVar3 * 2;
    uVar2 = (undefined2)iVar3;
  }
  return uVar2;
}



/* 004204f0  FUN_004204f0  287 bytes, 1 callers */

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



/* 00420610  FUN_00420610  661 bytes, 6 callers */

undefined4 __cdecl FUN_00420610(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  uVar9 = (uint)*(byte *)(DAT_0043453c + (param_1 * 0x30 + param_2) * 0x18);
  if (uVar9 == 0x40) {
    return 0;
  }
  iVar2 = uVar9 * 0x224;
  iVar7 = DAT_00434538 + iVar2;
  if (*(byte *)(iVar7 + 4) != DAT_00437580) {
    return 0;
  }
  if ((*(byte *)(iVar7 + 0x10) & 2) != 0) {
    return 0;
  }
  iVar8 = DAT_0043756c * 0x224 + DAT_00434538;
  puVar1 = (uint *)(iVar8 + 8);
  uVar6 = *puVar1;
  if (100000 < *(uint *)(iVar7 + 8) + uVar6) {
    return 0;
  }
  bVar4 = *(byte *)(iVar8 + 0xd);
  if ((bVar4 & 0x20) != 0) {
    *puVar1 = *(int *)(DAT_00434538 + 8 + iVar2) + uVar6;
    FUN_00420b30(uVar9,param_1,param_2);
    return 0;
  }
  bVar5 = *(byte *)(iVar7 + 0xd);
  if ((bVar5 & 0x20) != 0) {
    piVar3 = (int *)(DAT_00434538 + 8 + iVar2);
    *piVar3 = *piVar3 + uVar6;
    FUN_00420b30(DAT_0043756c,DAT_0043644c,DAT_00436450);
    return 1;
  }
  if (((bVar4 & 0x10) == 0x10) || ((bVar5 & 0x10) != 0)) {
    if ((bVar5 & 0x10) == 0) {
      *puVar1 = *(int *)(DAT_00434538 + 8 + iVar2) + uVar6;
      FUN_00420b30(uVar9,param_1,param_2);
      return 0;
    }
    if ((bVar4 & 0x10) == 0) {
      piVar3 = (int *)(DAT_00434538 + 8 + iVar2);
      *piVar3 = *piVar3 + uVar6;
      FUN_00420b30(DAT_0043756c,DAT_0043644c,DAT_00436450);
      return 1;
    }
  }
  if ((bVar4 & 0xf) != 3) {
    if ((bVar5 & 0xf) == 3) {
      if ((bVar4 & 0xf) == 3) goto LAB_004207b5;
      if ((bVar5 & 0xf) == 3) {
        *puVar1 = *(int *)(DAT_00434538 + 8 + iVar2) + uVar6;
        FUN_00420b30(uVar9,param_1,param_2);
        return 0;
      }
      if ((bVar5 & 0xf) == 1) {
        *puVar1 = *(int *)(DAT_00434538 + 8 + iVar2) + uVar6;
        FUN_00420b30(uVar9,param_1,param_2);
        return 0;
      }
    }
    if (*(uint *)(iVar7 + 8) <= uVar6) {
      *puVar1 = *(int *)(DAT_00434538 + 8 + iVar2) + uVar6;
      FUN_00420b30(uVar9,param_1,param_2);
      return 0;
    }
    piVar3 = (int *)(DAT_00434538 + 8 + iVar2);
    *piVar3 = *piVar3 + uVar6;
    FUN_00420b30(DAT_0043756c,DAT_0043644c,DAT_00436450);
    return 1;
  }
LAB_004207b5:
  piVar3 = (int *)(DAT_00434538 + 8 + iVar2);
  *piVar3 = *piVar3 + uVar6;
  FUN_00420b30(DAT_0043756c,DAT_0043644c,DAT_00436450);
  return 1;
}



/* 004208b0  FUN_004208b0  238 bytes, 7 callers */

undefined4 __cdecl FUN_004208b0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint *puVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  
  iVar6 = param_2 + param_1 * 0x30;
  iVar1 = iVar6 * 0x18;
  bVar7 = *(char *)(DAT_0043453c + 0x10 + iVar6 * 0x18) - 8;
  if (3 < bVar7) {
    return 0;
  }
  iVar8 = DAT_0043756c * 0x224 + DAT_00434538;
  bVar4 = *(byte *)(iVar8 + 4);
  if ((bVar7 != bVar4) && (*(byte *)(DAT_00434534 + 0x1e + (uint)bVar4 * 0x38) != bVar7)) {
    uVar9 = *(uint *)(iVar8 + 8);
    FUN_004209a0(iVar6);
    uVar5 = *(uint *)(DAT_0043453c + 0xc + iVar1);
    if (uVar5 < uVar9) {
      uVar9 = uVar5;
    }
    piVar2 = (int *)(DAT_00434534 + 0x14 + (uint)bVar7 * 0x38);
    iVar6 = *piVar2;
    *piVar2 = -1;
    *piVar2 = iVar6 + uVar9;
    puVar3 = (uint *)(DAT_0043453c + 0xc + iVar1);
    if (uVar9 < *puVar3) {
      *puVar3 = *puVar3 - uVar9;
      return 1;
    }
    *puVar3 = 100;
    *(undefined1 *)(DAT_0043453c + 0x10 + iVar1) = 0;
    return 1;
  }
  return 0;
}



/* 004209a0  FUN_004209a0  160 bytes, 1 callers */

void __cdecl FUN_004209a0(int param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(DAT_0043453c + 0xc + param_1 * 0x18);
  uVar3 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
  if (uVar3 < uVar5) {
    uVar5 = uVar3;
  }
  piVar1 = (int *)(DAT_00434534 + 0x14 + DAT_00437580 * 0x38);
  iVar4 = *piVar1;
  *piVar1 = -1;
  if (iVar4 + uVar5 != -1) {
    *piVar1 = iVar4 + uVar5;
  }
  puVar2 = (uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
  uVar3 = *puVar2;
  if (uVar3 <= uVar5) {
    FUN_00420aa0(DAT_0043756c,*(char *)(DAT_0043453c + 0x10 + param_1 * 0x18) + -8);
    return;
  }
  *puVar2 = uVar3 - uVar5;
  return;
}



/* 00420a40  FUN_00420a40  91 bytes, 5 callers */

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



/* 00420aa0  FUN_00420aa0  80 bytes, 8 callers */

void __cdecl FUN_00420aa0(int param_1,undefined1 param_2)

{
  int iVar1;
  byte *pbVar2;
  byte bVar3;
  
  iVar1 = param_1 * 0x224;
  pbVar2 = (byte *)(DAT_00434538 + 0x10 + param_1 * 0x224);
  bVar3 = *pbVar2;
  if ((bVar3 & 2) == 0) {
    *pbVar2 = bVar3 | 2;
    *(undefined1 *)(DAT_00434538 + 0xf + iVar1) = param_2;
    *(undefined1 *)(DAT_00434538 + 0xe + iVar1) = 0;
  }
  *(undefined4 *)(DAT_00434538 + 8 + iVar1) = 0;
  return;
}



/* 00420af0  FUN_00420af0  62 bytes, 1 callers */

void __cdecl FUN_00420af0(int param_1,int param_2,int param_3)

{
  char *pcVar1;
  
  pcVar1 = (char *)(DAT_00434538 + 0xe + param_1 * 0x224);
  *pcVar1 = *pcVar1 + '\x01';
  if (3 < *(byte *)(DAT_00434538 + 0xe + param_1 * 0x224)) {
    FUN_00420b30(param_1,param_2,param_3);
  }
  return;
}



/* 00420b30  FUN_00420b30  296 bytes, 3 callers */

void __cdecl FUN_00420b30(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = param_1 * 0x224;
  iVar5 = 0;
  *(undefined1 *)(DAT_00434538 + 0x220 + iVar4) = 0xff;
  *(undefined4 *)(DAT_00434538 + 8 + iVar4) = 0;
  *(undefined4 *)(DAT_00434538 + 0x18 + iVar4) = 0x1f0;
  *(undefined1 *)(DAT_00434538 + 0xe + iVar4) = 3;
  if ((*(byte *)(DAT_00434538 + iVar4 + 0xd) & 0x20) != 0) {
    uVar3 = (uint)*(byte *)(DAT_00434538 + iVar4 + 4);
    iVar6 = uVar3 * 0x38;
    puVar1 = (uint *)(DAT_00434534 + 4 + iVar6);
    *puVar1 = *puVar1 | 1;
    *(undefined1 *)(DAT_00434534 + 0x1f + iVar6) = *(undefined1 *)(DAT_00434538 + 0xf + iVar4);
    *(undefined4 *)(DAT_00434534 + 0xc + iVar6) = 0x40;
    do {
      iVar6 = DAT_00434538 + iVar5;
      if (((*(byte *)(iVar6 + 0x10) & 0x80) == 0) && (*(byte *)(iVar6 + 4) == uVar3)) {
        *(byte *)(iVar6 + 0xd) = *(byte *)(iVar6 + 0xd) & 0x20 | 0xc;
        *(undefined1 *)(DAT_00434538 + 0xc + iVar5) = 6;
        pbVar2 = (byte *)(DAT_00434538 + 0x10 + iVar5);
        *pbVar2 = *pbVar2 | 1;
        *(undefined1 *)(DAT_00434538 + 0x220 + iVar5) = 0xff;
        *(undefined4 *)(DAT_00434538 + 0x18 + iVar5) = 0x1f0;
      }
      iVar5 = iVar5 + 0x224;
    } while (iVar5 < 0x8900);
  }
  *(undefined1 *)(DAT_0043453c + (param_2 * 0x30 + param_3) * 0x18) = 0x40;
  *(undefined1 *)(DAT_00434538 + 0x10 + iVar4) = 0x80;
  return;
}



/* 00420c60  FUN_00420c60  519 bytes, 7 callers */

undefined4 __cdecl FUN_00420c60(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar4 = (param_1 * 0x30 + param_2) * 0x18;
  bVar2 = *(byte *)(DAT_0043453c + iVar4);
  if (0x3f < bVar2) {
    return 0;
  }
  uVar5 = (uint)bVar2;
  iVar1 = uVar5 * 0x224;
  iVar6 = DAT_00434538 + iVar1;
  iVar3 = DAT_0043756c * 0x224 + DAT_00434538;
  if (*(char *)(iVar6 + 4) == *(char *)(iVar3 + 4)) {
    return 0;
  }
  if (*(char *)(DAT_00434534 + 0x1e + (uint)*(byte *)(iVar3 + 4) * 0x38) == *(char *)(iVar6 + 4)) {
    return 0;
  }
  if ((*(byte *)(iVar6 + 0xd) & 0xf) == 0xc) {
    return 0;
  }
  if ((0x1ef < *(uint *)(iVar6 + 0x18)) &&
     ((*(char *)(iVar3 + 0xc) + 4U & 6) != *(byte *)(iVar6 + 0xc))) {
    *(byte *)(iVar6 + 0xc) = *(char *)(iVar3 + 0xc) + 4U & 6;
  }
  iVar3 = *(byte *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) - 0x14;
  if ((iVar3 < 4) && (-1 < iVar3)) {
    FUN_00420e70(DAT_0043756c,uVar5,(*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 2) + 1);
    return 1;
  }
  iVar4 = *(byte *)(DAT_0043453c + 0x10 + iVar4) - 0x14;
  if ((iVar4 < 4) && (-1 < iVar4)) {
    FUN_00420e70(DAT_0043756c,uVar5,(*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 3) + 1);
    FUN_00420e70(uVar5,DAT_0043756c,(*(uint *)(DAT_00434538 + 8 + iVar1) >> 3) + 1);
    return 1;
  }
  FUN_00420e70(DAT_0043756c,uVar5,(*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 3) + 1);
  FUN_00420e70(uVar5,DAT_0043756c,(*(uint *)(DAT_00434538 + 8 + iVar1) >> 4) + 1);
  return 1;
}



/* 00420e70  FUN_00420e70  124 bytes, 1 callers */

void __cdecl FUN_00420e70(int param_1,int param_2,uint param_3)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = DAT_00434538 + param_2 * 0x224;
  uVar4 = *(uint *)(iVar5 + 8);
  if (param_3 <= uVar4) {
    uVar4 = param_3;
  }
  piVar1 = (int *)(DAT_00434534 + 0x14 + (uint)*(byte *)(iVar5 + 4) * 0x38);
  *piVar1 = *piVar1 + uVar4;
  puVar2 = (uint *)(DAT_00434538 + 8 + param_2 * 0x224);
  uVar3 = *puVar2;
  if (uVar3 <= uVar4) {
    FUN_00420aa0(param_2,*(undefined1 *)(DAT_00434538 + 4 + param_1 * 0x224));
    return;
  }
  *puVar2 = uVar3 - uVar4;
  return;
}



/* 00420ef0  FUN_00420ef0  341 bytes, 1 callers */

undefined4 FUN_00420ef0(void)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  
  bVar3 = 0;
  while ((((DAT_00437580 == bVar3 || (*(byte *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) == bVar3)
           ) || (uVar1 = *(uint *)(DAT_00434534 + 4 + (uint)bVar3 * 0x38), (uVar1 & 2) == 0)) ||
         ((uVar1 & 4) == 0))) {
    bVar3 = bVar3 + 1;
    if (3 < bVar3) {
      return 0;
    }
  }
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  iVar2 = (uint)bVar3 * 0x38 + DAT_00434534;
  uVar1 = *(uint *)(DAT_0043453c + 8 +
                   ((uint)*(byte *)(iVar2 + 0x21) + (uint)*(byte *)(iVar2 + 0x20) * 0x30) * 0x18);
  if (0x1ef < uVar1) {
    return 0;
  }
  iVar4 = DAT_0043756c * 0x224 + DAT_00434538;
  if (*(uint *)(iVar4 + 8) < uVar1 * 2) {
    return 0;
  }
  *(undefined2 *)(iVar4 + 2) = *(undefined2 *)(iVar2 + 0x20);
  iVar2 = DAT_0043756c * 0x224 + DAT_00434538;
  iVar2 = FUN_00405000(DAT_0043756c,(uint)*(byte *)(iVar2 + 2),(uint)*(byte *)(iVar2 + 3));
  if (iVar2 == 0) {
    return 0;
  }
  FUN_004051b0(DAT_0043756c);
  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 10;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  return 1;
}



/* 00421050  FUN_00421050  234 bytes, 2 callers */

undefined4 FUN_00421050(void)

{
  byte *pbVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined2 local_8;
  int local_4;
  
  iVar3 = FUN_0041ec60(100);
  if (iVar3 == 0) {
    return 0;
  }
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  bVar2 = FUN_0041c690((undefined1 *)&local_8);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    return 0;
  }
  iVar3 = DAT_0043756c * 0x224 + DAT_00434538;
  if (*(uint *)(iVar3 + 8) < (uint)(local_4 * 2)) {
    return 0;
  }
  *(undefined2 *)(iVar3 + 2) = local_8;
  iVar3 = FUN_00405000(DAT_0043756c,(uint)(byte)local_8,(uint)local_8._1_1_);
  if (iVar3 == 0) {
    return 0;
  }
  pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
  *pbVar1 = *pbVar1 & 0x95 | 5;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  return 1;
}



/* 00421140  FUN_00421140  295 bytes, 1 callers */

undefined4 FUN_00421140(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  
  iVar3 = DAT_00437580 * 0x38 + DAT_00434534;
  if ((*(byte *)(iVar3 + 4) & 0x20) == 0) {
    return 0;
  }
  iVar3 = *(int *)(iVar3 + 0xc);
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  pbVar4 = (byte *)(iVar3 * 0x224 + DAT_00434538);
  if (*(int *)(pbVar4 + 0x18) == 0x1f0) {
    bVar1 = *pbVar4;
    bVar2 = pbVar4[1];
  }
  else {
    bVar1 = pbVar4[2];
    bVar2 = pbVar4[3];
  }
  iVar3 = DAT_0043756c * 0x224 + DAT_00434538;
  if (*(uint *)(iVar3 + 8) < *(uint *)(DAT_0043453c + 8 + ((uint)bVar1 * 0x30 + (uint)bVar2) * 0x18)
     ) {
    return 0;
  }
  *(byte *)(iVar3 + 2) = bVar1;
  *(byte *)(DAT_00434538 + 3 + DAT_0043756c * 0x224) = bVar2;
  iVar3 = FUN_00405000(DAT_0043756c,(uint)bVar1,(uint)bVar2);
  if (iVar3 == 0) {
    return 0;
  }
  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 2;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  return 1;
}



/* 00421270  FUN_00421270  801 bytes, 1 callers */

undefined4 FUN_00421270(void)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint local_c;
  uint local_8;
  uint local_4;
  
  uVar6 = 0x1f0;
  bVar3 = 0;
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  do {
    pbVar4 = (byte *)((uint)bVar3 * 0x224 + DAT_00434538);
    if (((pbVar4[0x10] & 0x80) == 0) && ((pbVar4[0xd] & 0x20) != 0)) {
      if ((pbVar4[4] != DAT_00437580) &&
         (*(byte *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) != pbVar4[4])) {
        uVar1 = *(uint *)(DAT_0043453c + 8 + ((uint)*pbVar4 * 0x30 + (uint)pbVar4[1]) * 0x18);
        if ((uVar1 < 0x1f0) && (uVar1 < uVar6)) {
          uVar6 = uVar1;
          local_c = (uint)bVar3;
          local_8 = (uint)pbVar4[1];
          local_4 = (uint)*pbVar4;
        }
      }
    }
    bVar3 = bVar3 + 1;
  } while (bVar3 < 0x40);
  if (0x1ef < uVar6) {
    return 0;
  }
  iVar2 = DAT_0043756c * 0x224 + DAT_00434538;
  uVar1 = *(uint *)(iVar2 + 8);
  if (uVar1 < uVar6 * 2) {
    return 0;
  }
  iVar5 = local_c * 0x224 + DAT_00434538;
  if ((uint)*(byte *)(DAT_0043453c + 0x10 + (local_4 * 0x30 + local_8) * 0x18) -
      (uint)*(byte *)(iVar5 + 4) == 0x14) {
    uVar6 = *(int *)(iVar5 + 8) * 3;
    if (uVar1 < uVar6) {
      if (uVar1 <= uVar6 >> 2) {
        return 0;
      }
      *(undefined1 *)(iVar2 + 2) = (undefined1)local_4;
      *(char *)(DAT_00434538 + 3 + DAT_0043756c * 0x224) = (char)local_8 + '\x02';
      iVar2 = FUN_00405000(DAT_0043756c,local_4,local_8 + 2);
      if (iVar2 == 0) {
        return 0;
      }
      *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 2;
      *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
      return 1;
    }
  }
  else if (uVar1 < *(uint *)(iVar5 + 8)) {
    *(undefined2 *)(iVar2 + 2) =
         *(undefined2 *)(DAT_00434534 + 8 + (uint)*(byte *)(iVar5 + 4) * 0x38);
    iVar2 = DAT_0043756c * 0x224 + DAT_00434538;
    iVar2 = FUN_00405000(DAT_0043756c,(uint)*(byte *)(iVar2 + 2),(uint)*(byte *)(iVar2 + 3));
    if (iVar2 == 0) {
      return 0;
    }
    *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 2;
    *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
    return 1;
  }
  *(undefined2 *)(iVar2 + 2) = *(undefined2 *)(iVar5 + 2);
  iVar2 = DAT_0043756c * 0x224 + DAT_00434538;
  iVar2 = FUN_00405000(DAT_0043756c,(uint)*(byte *)(iVar2 + 2),(uint)*(byte *)(iVar2 + 3));
  if (iVar2 == 0) {
    return 0;
  }
  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  return 1;
}



/* 004215a0  FUN_004215a0  192 bytes, 1 callers */

undefined4 __cdecl FUN_004215a0(int param_1)

{
  int iVar1;
  
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  *(undefined2 *)(DAT_00434538 + 2 + DAT_0043756c * 0x224) =
       *(undefined2 *)(DAT_00434538 + param_1 * 0x224);
  iVar1 = DAT_0043756c * 0x224 + DAT_00434538;
  iVar1 = FUN_00405000(DAT_0043756c,(uint)*(byte *)(iVar1 + 2),(uint)*(byte *)(iVar1 + 3));
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 2;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  return 1;
}



/* 00421660  FUN_00421660  237 bytes, 1 callers */

undefined4 FUN_00421660(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  iVar5 = DAT_00437580 * 0x38 + DAT_00434534;
  uVar4 = (uint)*(byte *)(iVar5 + 8);
  uVar3 = (uint)*(byte *)(iVar5 + 9);
  uVar2 = *(uint *)(DAT_0043453c + 8 + (uVar4 * 0x30 + uVar3) * 0x18);
  if (0x1ef < uVar2) {
    return 0;
  }
  if (*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) < uVar2 * 2) {
    return 0;
  }
  iVar5 = FUN_00405000(DAT_0043756c,uVar4,uVar3);
  if (iVar5 == 0) {
    return 0;
  }
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  puVar1 = (uint *)(DAT_00434534 + 4 + DAT_00437580 * 0x38);
  *puVar1 = *puVar1 & 0xfffffffd;
  puVar1 = (uint *)(DAT_00434534 + 4 + DAT_00437580 * 0x38);
  *puVar1 = *puVar1 & 0xfffffffb;
  return 1;
}



/* 00421750  FUN_00421750  437 bytes, 5 callers */

undefined4 FUN_00421750(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char local_7;
  char local_6;
  char local_5;
  int local_4;
  
  local_7 = '\0';
  do {
    FUN_0041d6d0((uint)*(byte *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) + local_7 * 2 & 7,
                 &local_6);
    iVar2 = FUN_0041ec30(DAT_0043644c,DAT_00436450,(int)local_6,(int)local_5);
    if (iVar2 != 0) {
      local_4 = local_6 + DAT_0043644c;
      iVar2 = local_5 + DAT_00436450;
      if (*(byte *)(DAT_0043453c + 0x10 + (local_4 * 0x30 + iVar2) * 0x18) < 0x30) {
        pbVar1 = (byte *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224);
        *pbVar1 = local_7 * '\x02' + *pbVar1 & 7;
        iVar3 = FUN_00420c60(local_4,iVar2);
        if (iVar3 == 1) {
          return 1;
        }
        iVar3 = FUN_00420610(local_4,iVar2);
        if (iVar3 == 1) {
          return 1;
        }
        iVar3 = (local_4 * 0x30 + iVar2) * 0x18;
        if (*(byte *)(DAT_0043453c + iVar3) < 0x40) {
          return 0;
        }
        iVar4 = FUN_004208b0(local_4,iVar2);
        if (iVar4 == 1) {
          return 1;
        }
        *(undefined1 *)(DAT_0043453c + DAT_00437690 * 0x18) = 0x40;
        *(undefined1 *)(DAT_0043453c + iVar3) = (undefined1)DAT_0043756c;
        *(undefined1 *)(DAT_00434538 + DAT_0043756c * 0x224) = (undefined1)local_4;
        *(char *)(DAT_00434538 + 1 + DAT_0043756c * 0x224) = (char)iVar2;
        return 1;
      }
    }
    local_7 = local_7 + '\x01';
    if ('\x03' < local_7) {
      return 0;
    }
  } while( true );
}



/* 00421910  FUN_00421910  158 bytes, 2 callers */

undefined4 FUN_00421910(void)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  byte bVar4;
  
  iVar3 = DAT_00437690 * 0x18 + DAT_0043453c;
  bVar4 = *(char *)(iVar3 + 0x10) - 8;
  if ((bVar4 < 4) && (bVar4 == DAT_00437580)) {
    piVar1 = (int *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
    *piVar1 = *piVar1 + *(int *)(iVar3 + 0xc);
    puVar2 = (uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
    if (100000 < *puVar2) {
      *puVar2 = 100000;
    }
    *(undefined1 *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) = 0;
    *(undefined4 *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18) = 100;
    return 1;
  }
  return 0;
}



/* 004219b0  FUN_004219b0  291 bytes, 2 callers */

int FUN_004219b0(void)

{
  byte bVar1;
  int iVar2;
  undefined1 uVar3;
  char local_2;
  char local_1;
  
  uVar3 = 0xb;
  iVar2 = FUN_0041dfb0(&local_2);
  if (iVar2 == 0) {
    uVar3 = 4;
    iVar2 = FUN_0041e0a0(&local_2);
    if (iVar2 == 0) {
      uVar3 = 5;
      iVar2 = FUN_0041e1d0(&local_2);
      goto LAB_004219f9;
    }
LAB_00421a11:
    if (iVar2 == 0) {
      if (*(char *)(DAT_00434538 + 4 + DAT_0043756c * 0x224) != DAT_004365cd) {
        uVar3 = 9;
        iVar2 = FUN_0041e480(&local_2);
      }
      goto LAB_00421a4a;
    }
  }
  else {
LAB_004219f9:
    if (iVar2 == 0) {
      uVar3 = 8;
      iVar2 = FUN_0041e360(&local_2);
      goto LAB_00421a11;
    }
LAB_00421a4a:
    if (iVar2 != 0) goto LAB_00421a66;
    uVar3 = 1;
    iVar2 = FUN_0041e560(&local_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_00421a66:
  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = uVar3;
  FUN_00405250(DAT_0043756c,(int)local_2,(int)local_1);
  bVar1 = *(byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) & 0xf;
  if ((bVar1 == 0xb) || (bVar1 == 9)) {
    FUN_004051b0(DAT_0043756c);
  }
  return iVar2;
}



/* 00421ae0  FUN_00421ae0  184 bytes, 2 callers */

void FUN_00421ae0(void)

{
  int iVar1;
  
  if (DAT_004365cd != DAT_00437580) {
    iVar1 = FUN_00420ef0();
    if (iVar1 == 1) {
      return;
    }
    iVar1 = FUN_00421140();
    if (iVar1 == 1) {
      return;
    }
    if ((1000 < *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224)) &&
       (iVar1 = FUN_00421270(), iVar1 == 1)) {
      return;
    }
    iVar1 = FUN_0041abd0(100);
    if (0x59 < (byte)iVar1) {
      iVar1 = FUN_00421d30();
      if (iVar1 == 1) {
        return;
      }
      iVar1 = FUN_00422040();
      if (iVar1 == 1) {
        return;
      }
      FUN_00422110();
      return;
    }
    if ((0x50 < (byte)iVar1) && (iVar1 = FUN_00421f20(), iVar1 == 1)) {
      return;
    }
  }
  iVar1 = FUN_00421ba0(0x1f0);
  if ((iVar1 != 1) && (iVar1 = FUN_00422040(), iVar1 != 1)) {
    FUN_00422110();
    return;
  }
  return;
}



/* 00421ba0  FUN_00421ba0  346 bytes, 1 callers */

undefined4 __cdecl FUN_00421ba0(uint param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined2 local_8;
  uint local_4;
  
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  iVar1 = FUN_0041c410((undefined1 *)&local_8);
  if (iVar1 == 0) {
    return 0;
  }
  if (param_1 <= local_4) {
    return 0;
  }
  iVar1 = DAT_0043756c * 0x224 + DAT_00434538;
  if (*(uint *)(iVar1 + 8) < local_4 * 2) {
    return 0;
  }
  switch(*(undefined1 *)
          (DAT_0043453c + 0x10 + ((uint)(byte)local_8 * 0x30 + (uint)local_8._1_1_) * 0x18)) {
  case 0:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    uVar2 = 5;
    break;
  case 1:
  case 2:
  case 3:
  case 4:
    uVar2 = 8;
    break;
  case 5:
    uVar2 = 0xb;
    break;
  default:
    return 0;
  case 8:
  case 9:
  case 10:
  case 0xb:
    uVar2 = 4;
  }
  *(undefined2 *)(iVar1 + 2) = local_8;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = uVar2;
  iVar1 = FUN_00405000(DAT_0043756c,(uint)(byte)local_8,(uint)local_8._1_1_);
  if (iVar1 == 0) {
    return 0;
  }
  if ((*(byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) & 0xf) == 0xb) {
    FUN_004051b0(DAT_0043756c);
  }
  return 1;
}



/* 00421d30  FUN_00421d30  454 bytes, 1 callers */

undefined4 FUN_00421d30(void)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  char cVar3;
  undefined4 local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  local_c = 0x1f0;
  cVar3 = '\x01';
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  iVar2 = FUN_0041c410((undefined1 *)&local_10);
  if (iVar2 == 1) {
    switch(*(undefined1 *)
            (DAT_0043453c + 0x10 + ((local_10 & 0xff) * 0x30 + (local_10 >> 8 & 0xff)) * 0x18)) {
    case 0:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
      cVar3 = '\x05';
      break;
    default:
      cVar3 = '\b';
      break;
    case 5:
      cVar3 = '\v';
      break;
    case 8:
    case 9:
    case 10:
    case 0xb:
      cVar3 = '\x04';
    }
    local_10 = CONCAT22((undefined2)local_10,(undefined2)local_10);
  }
  else {
    bVar1 = FUN_0041c800((char *)&local_8);
    if ((CONCAT31(extraout_var,bVar1) == 1) && (local_4 < local_c)) {
      cVar3 = '\t';
      local_10 = local_8;
      local_c = local_4;
    }
    bVar1 = FUN_0041c8e0((char *)&local_8);
    if ((CONCAT31(extraout_var_00,bVar1) == 1) && (local_4 + 0x14 < local_c)) {
      cVar3 = '\a';
      local_10 = local_8;
      local_c = local_4;
    }
    if (0x1ef < local_c) {
      return 0;
    }
    if (*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) <= local_c * 2) {
      return 0;
    }
  }
  *(char *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = cVar3;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  *(undefined2 *)(DAT_00434538 + 2 + DAT_0043756c * 0x224) = (undefined2)local_10;
  iVar2 = FUN_00405000(DAT_0043756c,local_10 >> 0x10 & 0xff,local_10 >> 0x18);
  if (iVar2 == 0) {
    return 0;
  }
  if (cVar3 == '\v') {
    FUN_004051b0(DAT_0043756c);
  }
  return 1;
}



/* 00421f20  FUN_00421f20  273 bytes, 1 callers */

undefined4 FUN_00421f20(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = FUN_0041ec60(100);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = 0;
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  do {
    uVar3 = FUN_0041abf0();
    uVar5 = (uVar3 >> 8) * 0x30 >> 8;
    uVar3 = (uVar3 & 0xff) * 0x30 >> 8;
    iVar4 = (uVar5 * 0x30 + uVar3) * 0x18 + DAT_0043453c;
    if (((*(char *)(iVar4 + 0x10) == '\0') && (uVar1 = *(uint *)(iVar4 + 8), uVar1 < 0x1f0)) &&
       (uVar1 * 2 < *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224))) {
      iVar4 = FUN_0041e670(uVar5,uVar3);
      if (iVar4 == 0) {
        iVar4 = FUN_00405000(DAT_0043756c,uVar5,uVar3);
        if (iVar4 == 1) {
          *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 5;
          *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
          return 1;
        }
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  return 0;
}



/* 00422040  FUN_00422040  206 bytes, 1 callers */

undefined4 FUN_00422040(void)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined2 local_8;
  int local_4;
  
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  bVar1 = FUN_0041caf0(&local_8);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    return 0;
  }
  iVar2 = DAT_0043756c * 0x224 + DAT_00434538;
  if (*(uint *)(iVar2 + 8) < (uint)(local_4 * 2)) {
    return 0;
  }
  *(undefined2 *)(iVar2 + 2) = local_8;
  iVar2 = FUN_00405000(DAT_0043756c,(uint)(byte)local_8,(uint)local_8._1_1_);
  if (iVar2 == 1) {
    *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 3;
    *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
    return 1;
  }
  return 0;
}



/* 00422110  FUN_00422110  380 bytes, 2 callers */

undefined4 FUN_00422110(void)

{
  byte *pbVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined2 local_8;
  int local_4;
  
  if ((uint)*(byte *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) - DAT_00437580 == 8) {
    *(undefined4 *)(DAT_00434538 + 0x18 + DAT_0043756c * 0x224) = 0x1f0;
    *(undefined1 *)(DAT_00434538 + 2 + DAT_0043756c * 0x224) = (undefined1)DAT_0043644c;
    *(undefined1 *)(DAT_00434538 + 3 + DAT_0043756c * 0x224) = (undefined1)DAT_00436450;
    pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
    if ((*pbVar1 & 0x20) == 0) {
      *pbVar1 = 2;
    }
    return 1;
  }
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  bVar2 = FUN_0041cbc0((byte *)&local_8);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    return 0;
  }
  iVar3 = DAT_0043756c * 0x224 + DAT_00434538;
  if (*(uint *)(iVar3 + 8) < (uint)(local_4 * 2)) {
    return 0;
  }
  *(undefined2 *)(iVar3 + 2) = local_8;
  iVar3 = FUN_00405000(DAT_0043756c,(uint)(byte)local_8,(uint)local_8._1_1_);
  if (iVar3 == 0) {
    return 0;
  }
  pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
  if ((*pbVar1 & 0x20) == 0) {
    *pbVar1 = 2;
  }
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  return 1;
}



/* 00422290  FUN_00422290  214 bytes, 2 callers */

undefined4 FUN_00422290(void)

{
  byte *pbVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined2 local_8;
  int local_4;
  
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  bVar2 = FUN_0041cc30((undefined1 *)&local_8);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    return 0;
  }
  iVar3 = DAT_0043756c * 0x224 + DAT_00434538;
  if (*(uint *)(iVar3 + 8) < (uint)(local_4 * 2)) {
    return 0;
  }
  *(undefined2 *)(iVar3 + 2) = local_8;
  iVar3 = FUN_00405000(DAT_0043756c,(uint)(byte)local_8,(uint)local_8._1_1_);
  if (iVar3 == 0) {
    return 0;
  }
  pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
  *pbVar1 = *pbVar1 & 0xd4 | 4;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  return 1;
}



/* 00422370  FUN_00422370  238 bytes, 2 callers */

undefined4 FUN_00422370(void)

{
  byte *pbVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined2 local_8;
  int local_4;
  
  if (*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) < 0x14) {
    return 0;
  }
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  bVar2 = FUN_0041cce0((undefined1 *)&local_8);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    return 0;
  }
  iVar3 = DAT_0043756c * 0x224 + DAT_00434538;
  if (*(uint *)(iVar3 + 8) < (uint)(local_4 * 2)) {
    return 0;
  }
  *(undefined2 *)(iVar3 + 2) = local_8;
  FUN_00405000(DAT_0043756c,(uint)(byte)local_8,(uint)local_8._1_1_);
  pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
  *pbVar1 = *pbVar1 & 0xd8 | 8;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  return 1;
}



/* 00422460  FUN_00422460  204 bytes, 2 callers */

undefined4 FUN_00422460(void)

{
  byte *pbVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined2 local_8;
  byte local_6;
  byte local_5;
  int local_4;
  
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  bVar2 = FUN_0041c800((char *)&local_8);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    return 0;
  }
  iVar3 = DAT_0043756c * 0x224 + DAT_00434538;
  if (*(uint *)(iVar3 + 8) < (uint)(local_4 * 2)) {
    return 0;
  }
  *(undefined2 *)(iVar3 + 2) = local_8;
  FUN_00405000(DAT_0043756c,(uint)local_6,(uint)local_5);
  pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
  *pbVar1 = *pbVar1 & 0xd9 | 9;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  return 1;
}



/* 00422530  FUN_00422530  219 bytes, 2 callers */

undefined4 FUN_00422530(void)

{
  byte *pbVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined2 local_8;
  int local_4;
  
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  bVar2 = FUN_0041cd50((undefined1 *)&local_8);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    return 0;
  }
  iVar3 = DAT_0043756c * 0x224 + DAT_00434538;
  if (*(uint *)(iVar3 + 8) < (uint)(local_4 * 2)) {
    return 0;
  }
  *(undefined2 *)(iVar3 + 2) = local_8;
  FUN_00405000(DAT_0043756c,(uint)(byte)local_8,(uint)local_8._1_1_);
  FUN_004051b0(DAT_0043756c);
  pbVar1 = (byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224);
  *pbVar1 = *pbVar1 & 0xdb | 0xb;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  return 1;
}



/* 00422610  FUN_00422610  544 bytes, 1 callers */

undefined4 * __fastcall FUN_00422610(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 *unaff_FS_OFFSET;
  tagRECT local_24;
  undefined4 *local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00422830;
  *unaff_FS_OFFSET = &local_10;
  local_14 = param_1;
  FUN_00427770(param_1);
  local_8 = 0;
  *param_1 = &PTR_FUN_004307c0;
  uVar1 = (uint)DAT_004376ae;
  param_1[0x9e] = 0x54f40000;
  param_1[0x9f] = 0x80;
  param_1[0xe6] = uVar1;
  iVar2 = GetSystemMetrics(0x20);
  param_1[6] = iVar2 * 2;
  iVar2 = GetSystemMetrics(0x21);
  iVar3 = GetSystemMetrics(0x33);
  *(undefined1 *)(param_1 + 0xf0) = 1;
  *(undefined1 *)((int)param_1 + 0x3c1) = 1;
  param_1[7] = iVar2 * 2 + iVar3;
  *(undefined2 *)(param_1 + 0xf1) = *(undefined2 *)(param_1 + 0xf0);
  param_1[0xef] = 0;
  iVar2 = param_1[0xe6];
  param_1[0xeb] = iVar2;
  param_1[0xec] = iVar2;
  param_1[0xed] = iVar2;
  param_1[0xee] = param_1[0xec];
  wsprintfA((LPSTR)(param_1 + 0x53),s_MapInfo_c_00434458,
            (int)(char)(&DAT_0043444c)[(int)(iVar2 + (iVar2 >> 0x1f & 0xfU)) >> 4]);
  iVar2 = param_1[0xe6];
  param_1[8] = iVar2 * 0x30;
  param_1[9] = iVar2 * 0x30;
  if (iVar2 == 8) {
    param_1[0x572] = DAT_0043645c;
    uVar6 = DAT_00436448;
  }
  else if (iVar2 == 0x10) {
    param_1[0x572] = DAT_00436458;
    uVar6 = DAT_00436444;
  }
  else {
    if (iVar2 != 0x20) goto LAB_0042275b;
    param_1[0x572] = DAT_00436454;
    uVar6 = DAT_00436440;
  }
  param_1[0x573] = uVar6;
LAB_0042275b:
  param_1[10] = 0;
  iVar2 = GetSystemMetrics(0x20);
  param_1[0xb] = iVar2 * 2 + 0xb0;
  param_1[0xc] = param_1[6] + param_1[8];
  *(undefined1 *)(param_1 + 0x575) = 0;
  param_1[0xd] = param_1[9] + param_1[7];
  GetClientRect(*(HWND *)(DAT_004344e4 + 8),&local_24);
  if (local_24.right <= (int)(param_1[0xc] + param_1[10])) {
    param_1[0xc] = local_24.right - param_1[10];
  }
  if (local_24.bottom <= (int)(param_1[0xd] + param_1[0xb])) {
    param_1[0xd] = local_24.bottom - param_1[0xb];
  }
  pcVar4 = s_Quest_004323fc;
  if (DAT_004365cc == '\0') {
    pcVar4 = s_Single_004323f4;
  }
  iVar2 = DAT_0043450c + 1;
  DAT_004344e8 = param_1;
  pcVar5 = FUN_0041a650(&DAT_004376c8,DAT_0043450c);
  wsprintfA((LPSTR)(param_1 + 0x12),s__s__s__d___s_004323e4,s_Map_Window_004323d8,pcVar5,iVar2,
            pcVar4);
  param_1[0x5fa] = 0;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}



/* 00422850  FUN_00422850  30 bytes, 0 callers */

undefined4 * __thiscall FUN_00422850(void *this,byte param_1)

{
  FUN_00422870(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 00422870  FUN_00422870  71 bytes, 1 callers */

void __fastcall FUN_00422870(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_004228b7;
  *param_1 = &PTR_FUN_004307c0;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  DAT_004344e8 = 0;
  FUN_004228c1();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 004228c1  FUN_004228c1  8 bytes, 1 callers */

void FUN_004228c1(void)

{
  int unaff_EBP;
  
  FUN_00427820(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 004228d0  FUN_004228d0  284 bytes, 0 callers */

undefined4 __fastcall FUN_004228d0(void *param_1)

{
  uint uVar1;
  tagRECT local_10;
  
  uVar1 = *(uint *)((int)param_1 + 0xc);
  if (0x112 < uVar1) {
    if (uVar1 == 0x114) {
      if (DAT_004376ad == '\0') {
        FUN_00408e10(2);
      }
      FUN_00424b90(param_1,*(uint *)((int)param_1 + 0x10));
      return 0;
    }
    if (uVar1 != 0x115) {
      if (uVar1 != 0x203) {
        return 0;
      }
      return 1;
    }
    if (DAT_004376ad == '\0') {
      FUN_00408e10(2);
    }
    FUN_00424cc0(param_1,*(uint *)((int)param_1 + 0x10));
    return 0;
  }
  if (uVar1 == 0x112) {
    if (*(int *)((int)param_1 + 0x10) != 0xf030) {
      return 0;
    }
    GetClientRect(DAT_004344d8,&local_10);
    MoveWindow(*(HWND *)((int)param_1 + 8),0,0,local_10.right,local_10.bottom,1);
    return 1;
  }
  if ((uVar1 == 0x47) && (*(int *)((int)param_1 + 0x25c) != 0)) {
    FUN_00424b90(param_1,CONCAT31((int3)(((uint)*(ushort *)((int)param_1 + 0x260) << 0x10) >> 8),5))
    ;
    FUN_00424cc0(param_1,CONCAT31((int3)(((uint)*(ushort *)((int)param_1 + 0x264) << 0x10) >> 8),5))
    ;
    return 0;
  }
  return 0;
}



/* 00422a90  FUN_00422a90  265 bytes, 0 callers */

void __fastcall FUN_00422a90(int *param_1)

{
  int iVar1;
  tagPOINT local_8;
  
  if (DAT_00434524 != 0) {
    return;
  }
  if (DAT_004365dc == 1) {
    iVar1 = FUN_00423760(param_1,(uint)*(byte *)(param_1 + 0xf0),
                         (uint)*(byte *)((int)param_1 + 0x3c1));
    if (iVar1 == 1) {
      GetCursorPos(&local_8);
      FUN_00424770(param_1);
      if (DAT_00434440 < 0x40) {
        FUN_00423cc0(param_1,0,0);
      }
      else {
        iVar1 = FUN_00423940(param_1,&local_8.x);
        if ((iVar1 == 0) && (DAT_004365dc == 3)) {
          DAT_004365dc = 5;
        }
      }
    }
    else {
      DAT_004321c0 = 2;
      DAT_004321b8 = 0;
      FUN_0040a1c0(0x15f95);
      FUN_00424770(param_1);
    }
  }
  else {
    if (DAT_004365dc == 2) {
      iVar1 = FUN_004235a0((int)param_1);
      if (iVar1 != 1) {
        DAT_004365dc = 0;
        goto LAB_00422b8d;
      }
      FUN_0040a1c0(90000);
    }
    else if (DAT_004365dc != 5) goto LAB_00422b8d;
    DAT_004365dc = 1;
  }
LAB_00422b8d:
  FUN_00424770(param_1);
  return;
}



/* 00422ba0  FUN_00422ba0  124 bytes, 0 callers */

void __fastcall FUN_00422ba0(int param_1)

{
  tagRECT local_20;
  tagRECT local_10;
  
  GetWindowRect(*(HWND *)(param_1 + 8),&local_20);
  local_20.top = local_20.top + *(int *)(param_1 + 0x1c);
  local_20.left = local_20.left + *(int *)(param_1 + 0x18);
  GetClientRect(*(HWND *)(param_1 + 8),&local_10);
  local_20.right = local_10.right + local_20.left;
  local_20.bottom = local_10.bottom + local_20.top;
  ClipCursor(&local_20);
  *(undefined4 *)(param_1 + 0x17f4) = 6;
  *(uint *)(param_1 + 0x17ec) = *(uint *)(param_1 + 0x14) & 0xffff;
  *(uint *)(param_1 + 0x17f0) = *(uint *)(param_1 + 0x14) >> 0x10;
  return;
}



/* 00422c20  FUN_00422c20  217 bytes, 0 callers */

void __fastcall FUN_00422c20(int *param_1)

{
  tagPOINT local_24;
  tagMSG local_1c;
  
  ClipCursor((RECT *)0x0);
  if (param_1[0x5fa] != 0) {
    PeekMessageA(&local_1c,(HWND)param_1[2],0x200,0x209,1);
    param_1[0x5fa] = 0;
    return;
  }
  if (((DAT_004365dc == 1) || (DAT_00434524 == 0)) || (DAT_004365dc == 0)) {
    switch(DAT_004365dc) {
    case 0:
      DAT_004365dc = 3;
      GetCursorPos(&local_24);
      FUN_0040a980(&local_24.x);
      break;
    case 1:
      FUN_00409f90();
      break;
    case 2:
      FUN_00423480((int)param_1);
      DAT_004365dc = 0;
      break;
    case 3:
      DAT_004365dc = 1;
      (**(code **)(*param_1 + 100))();
      break;
    case 4:
      FUN_00409f90();
    case 5:
      DAT_004365dc = 1;
    }
    FUN_00424770(param_1);
  }
  return;
}



/* 00422d20  FUN_00422d20  677 bytes, 0 callers */

void __fastcall FUN_00422d20(void *param_1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *this;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 local_14;
  RECT local_10;
  
  uVar5 = (*(int *)((int)param_1 + 0x260) + *(int *)((int)param_1 + 0x3ac)) /
          *(int *)((int)param_1 + 0x398);
  uVar6 = (*(int *)((int)param_1 + 0x3b0) + *(int *)((int)param_1 + 0x264)) /
          *(int *)((int)param_1 + 0x398);
  if (((((int)uVar5 < 0x2f) && ((int)uVar6 < 0x2f)) && (0 < (int)uVar5)) &&
     ((0 < (int)uVar6 &&
      ((*(byte *)((int)param_1 + 0x3c0) != uVar5 || (*(byte *)((int)param_1 + 0x3c1) != uVar6))))))
  {
    if (DAT_004376ad == '\0') {
      FUN_00408e10((10 - (uint)DAT_004376ac) * 2);
    }
    local_14 = (undefined1)uVar5;
    local_10.bottom = *(int *)((int)param_1 + 0x398);
    *(undefined1 *)((int)param_1 + 0x3c0) = local_14;
    *(char *)((int)param_1 + 0x3c1) = (char)uVar6;
    local_10.left =
         ((uint)*(byte *)((int)param_1 + 0x3c4) - *(int *)((int)param_1 + 0x260) / local_10.bottom)
         * local_10.bottom - *(int *)((int)param_1 + 0x260) % local_10.bottom;
    local_10.top = ((uint)*(byte *)((int)param_1 + 0x3c5) -
                   *(int *)((int)param_1 + 0x264) / local_10.bottom) * local_10.bottom -
                   *(int *)((int)param_1 + 0x264) % local_10.bottom;
    local_10.right = local_10.left + local_10.bottom;
    local_10.bottom = local_10.bottom + local_10.top;
    iVar9 = 0;
    FUN_00422fd0(param_1,(uint)*(byte *)((int)param_1 + 0x3c4),(uint)*(byte *)((int)param_1 + 0x3c5)
                );
    InvalidateRect(*(HWND *)((int)param_1 + 8),&local_10,0);
    *(undefined2 *)((int)param_1 + 0x3c4) = *(undefined2 *)((int)param_1 + 0x3c0);
    *(undefined4 *)((int)param_1 + 0x3b4) = *(undefined4 *)((int)param_1 + 0x3ac);
    *(undefined4 *)((int)param_1 + 0x3b8) = *(undefined4 *)((int)param_1 + 0x3b0);
    local_10.bottom = *(int *)((int)param_1 + 0x398);
    local_10.left =
         ((uint)*(byte *)((int)param_1 + 0x3c0) - *(int *)((int)param_1 + 0x260) / local_10.bottom)
         * local_10.bottom - *(int *)((int)param_1 + 0x260) % local_10.bottom;
    local_10.top = ((uint)*(byte *)((int)param_1 + 0x3c1) -
                   *(int *)((int)param_1 + 0x264) / local_10.bottom) * local_10.bottom -
                   *(int *)((int)param_1 + 0x264) % local_10.bottom;
    local_10.right = local_10.left + local_10.bottom;
    local_10.bottom = local_10.bottom + local_10.top;
    InvalidateRect(*(HWND *)((int)param_1 + 8),&local_10,1);
    FUN_00422fd0(param_1,(uint)*(byte *)((int)param_1 + 0x3c0),(uint)*(byte *)((int)param_1 + 0x3c1)
                );
    if (DAT_004365dc != 2) {
      iVar4 = *(int *)((int)param_1 + 0x398);
      bVar1 = *(byte *)((int)param_1 + 0x3c1);
      bVar2 = *(byte *)((int)param_1 + 0x3c0);
      iVar7 = 0;
      if (0 < iVar4) {
        do {
          iVar8 = 0;
          if (0 < *(int *)((int)param_1 + 0x398)) {
            do {
              cVar3 = *(char *)(DAT_00435fd4 + iVar9 + iVar8 + iVar4 + 0x1078);
              if (cVar3 != 'p') {
                *(char *)(*(int *)((int)param_1 + 0x398) * iVar7 * 0x30 +
                          *(int *)((int)param_1 + 0x25c) +
                          ((uint)bVar1 * iVar4 * 0x30 + (uint)bVar2) * iVar4 + iVar8) = cVar3;
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < *(int *)((int)param_1 + 0x398));
          }
          iVar9 = iVar9 + 0x100;
          iVar7 = iVar7 + 1;
        } while (iVar7 < *(int *)((int)param_1 + 0x398));
      }
    }
    this = (int *)FUN_0040a0c0(0xea61);
    if (this != (int *)0x0) {
      FUN_004271b0(this,(byte *)((int)param_1 + 0x3c0));
      (**(code **)(*this + 100))();
    }
    UpdateWindow(*(HWND *)((int)param_1 + 8));
  }
  return;
}



/* 00422fd0  FUN_00422fd0  361 bytes, 2 callers */

void __thiscall FUN_00422fd0(void *this,int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  
  if ((param_1 < 0x2f) && (param_2 < 0x2f)) {
    uVar3 = *(uint *)((int)this + 0x398);
    iVar1 = (param_1 * 0x30 + param_2) * 0x18;
    iVar5 = (param_2 * uVar3 * 0x30 + param_1) * uVar3;
    FUN_004243c0((uint)*(byte *)(DAT_0043453c + 0x10 + iVar1),uVar3,*(int *)((int)this + 0x20),
                 *(undefined4 *)((int)this + 0x24),
                 (undefined4 *)(*(int *)((int)this + 0x25c) + iVar5),*(int *)((int)this + 0x15c8));
    if (*(byte *)(DAT_0043453c + iVar1) < 0x40) {
      iVar9 = *(int *)((int)this + 0x15cc);
      uVar8 = *(undefined4 *)((int)this + 0x24);
      iVar4 = *(int *)((int)this + 0x25c) + iVar5;
      iVar7 = *(int *)((int)this + 0x20);
      iVar6 = *(int *)((int)this + 0x398);
      uVar3 = FUN_0041b520((uint)*(byte *)(DAT_0043453c + iVar1));
      FUN_00424460(uVar3,iVar6,iVar7,uVar8,iVar4,iVar9);
      bVar2 = *(byte *)(DAT_00434538 + 0x220 + (uint)*(byte *)(DAT_0043453c + iVar1) * 0x224);
      if (bVar2 != 0xff) {
        iVar9 = *(int *)((int)this + 0x398);
        FUN_004244b0((uint)bVar2,iVar9,*(int *)((int)this + 0x20),*(undefined4 *)((int)this + 0x24),
                     iVar9 * iVar9 * -0x30 + *(int *)((int)this + 0x25c) + iVar5);
      }
    }
    bVar2 = *(byte *)(DAT_0043453c + 0x18 + iVar1);
    if ((bVar2 < 0x40) &&
       (bVar2 = *(byte *)(DAT_00434538 + 0x220 + (uint)bVar2 * 0x224), bVar2 != 0xff)) {
      FUN_004244b0((uint)bVar2,*(int *)((int)this + 0x398),*(int *)((int)this + 0x20),
                   *(undefined4 *)((int)this + 0x24),*(int *)((int)this + 0x25c) + iVar5);
    }
  }
  return;
}



/* 00423140  FUN_00423140  220 bytes, 0 callers */

void __fastcall FUN_00423140(int *param_1)

{
  int iVar1;
  int iVar2;
  tagPOINT local_18;
  tagRECT local_10;
  
  GetCursorPos(&local_18);
  ScreenToClient((HWND)param_1[2],&local_18);
  iVar2 = param_1[0xe6];
  param_1[0xe7] = ((local_18.x + param_1[0x98]) / iVar2) * iVar2 - param_1[0x98];
  param_1[0xe8] = ((local_18.y + param_1[0x99]) / iVar2) * iVar2 - param_1[0x99];
  param_1[0xe9] = -1;
  param_1[0xea] = -1;
  GetWindowRect((HWND)param_1[2],&local_10);
  iVar2 = param_1[7];
  local_10.top = local_10.top + iVar2;
  local_10.left = local_10.left + param_1[6];
  local_10.right = local_10.right - param_1[6];
  iVar1 = GetSystemMetrics(0x33);
  local_10.bottom = local_10.bottom + (iVar1 - iVar2);
  ClipCursor(&local_10);
  iVar2 = (uint)*(byte *)(param_1 + 0xf0) * 0x30 + (uint)*(byte *)((int)param_1 + 0x3c1);
  *(undefined1 *)((int)param_1 + iVar2 * 2 + 0x3c6) = 0xff;
  *(undefined1 *)((int)param_1 + iVar2 * 2 + 0x3c7) = 1;
  FUN_00424770(param_1);
  return;
}



/* 00423220  FUN_00423220  605 bytes, 0 callers */

void __fastcall FUN_00423220(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  HPEN h;
  HDC hdc;
  HGDIOBJ h_00;
  int local_38;
  int local_34;
  POINT local_28;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  HPALETTE local_4;
  
  piVar1 = (int *)(param_1 + 0x3a4);
  if (((*piVar1 == -1) ||
      (iVar3 = *(int *)(param_1 + 0x398),
      ((*(int *)(param_1 + 0x3ac) + *(int *)(param_1 + 0x260)) / iVar3) * iVar3 - *piVar1 !=
      *(int *)(param_1 + 0x260))) ||
     (((*(int *)(param_1 + 0x3b0) + *(int *)(param_1 + 0x264)) / iVar3) * iVar3 -
      *(int *)(param_1 + 0x3a8) != *(int *)(param_1 + 0x264))) {
    h = CreatePen(0,(int)(*(int *)(param_1 + 0x398) + (*(int *)(param_1 + 0x398) >> 0x1f & 7U)) >> 3
                  ,0x1000040);
    if (h != (HPEN)0x0) {
      hdc = GetDC(*(HWND *)(param_1 + 8));
      if (hdc == (HDC)0x0) {
        DeleteObject(h);
        return;
      }
      local_4 = SelectPalette(hdc,DAT_004365f4,0);
      piVar2 = (int *)(param_1 + 0x39c);
      h_00 = SelectObject(hdc,h);
      local_8 = SetROP2(hdc,7);
      MoveToEx(hdc,*piVar2,*(int *)(param_1 + 0x3a0),(LPPOINT)0x0);
      iVar3 = *piVar1;
      if (iVar3 != -1) {
        local_28.x = *piVar2;
        local_28.y = *(LONG *)(param_1 + 0x3a8);
        local_1c = *(undefined4 *)(param_1 + 0x3a8);
        local_10 = *piVar2;
        local_14 = *(undefined4 *)(param_1 + 0x3a0);
        local_c = *(undefined4 *)(param_1 + 0x3a0);
        local_20 = iVar3;
        local_18 = iVar3;
        PolylineTo(hdc,&local_28,4);
      }
      MoveToEx(hdc,*piVar2,*(int *)(param_1 + 0x3a0),(LPPOINT)0x0);
      iVar3 = *(int *)(param_1 + 0x398);
      local_38 = ((*(int *)(param_1 + 0x260) + *(int *)(param_1 + 0x3ac)) / iVar3) * iVar3 -
                 *(int *)(param_1 + 0x260);
      local_34 = ((*(int *)(param_1 + 0x264) + *(int *)(param_1 + 0x3b0)) / iVar3) * iVar3 -
                 *(int *)(param_1 + 0x264);
      local_28.x = *piVar2;
      if (local_38 == local_28.x) {
        local_38 = local_28.x + iVar3;
      }
      if (local_34 == *(int *)(param_1 + 0x3a0)) {
        local_34 = iVar3 + *(int *)(param_1 + 0x3a0);
      }
      local_14 = *(undefined4 *)(param_1 + 0x3a0);
      local_28.y = local_34;
      local_20 = local_38;
      local_1c = local_34;
      local_18 = local_38;
      local_10 = *piVar2;
      local_c = *(undefined4 *)(param_1 + 0x3a0);
      PolylineTo(hdc,&local_28,4);
      *piVar1 = local_38;
      *(int *)(param_1 + 0x3a8) = local_34;
      if (h_00 != (HGDIOBJ)0x0) {
        SelectObject(hdc,h_00);
      }
      SetROP2(hdc,local_8);
      SelectPalette(hdc,local_4,1);
      ReleaseDC(*(HWND *)(param_1 + 8),hdc);
      DeleteObject(h);
    }
  }
  return;
}



/* 00423480  FUN_00423480  283 bytes, 2 callers */

void __fastcall FUN_00423480(int param_1)

{
  HPEN h;
  HDC hdc;
  HGDIOBJ h_00;
  int rop2;
  POINT local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(param_1 + 0x394) = 0;
  h = CreatePen(0,(int)(*(int *)(param_1 + 0x398) + (*(int *)(param_1 + 0x398) >> 0x1f & 7U)) >> 3,
                0x1000040);
  if (h != (HPEN)0x0) {
    hdc = GetDC(*(HWND *)(param_1 + 8));
    if (hdc == (HDC)0x0) {
      DeleteObject(h);
      return;
    }
    h_00 = SelectObject(hdc,h);
    rop2 = SetROP2(hdc,7);
    MoveToEx(hdc,*(int *)(param_1 + 0x39c),*(int *)(param_1 + 0x3a0),(LPPOINT)0x0);
    local_20.x = *(LONG *)(param_1 + 0x39c);
    local_20.y = *(LONG *)(param_1 + 0x3a8);
    local_18 = *(undefined4 *)(param_1 + 0x3a4);
    local_14 = *(undefined4 *)(param_1 + 0x3a8);
    local_c = *(undefined4 *)(param_1 + 0x3a0);
    local_4 = *(undefined4 *)(param_1 + 0x3a0);
    local_8 = *(undefined4 *)(param_1 + 0x39c);
    local_10 = local_18;
    PolylineTo(hdc,&local_20,4);
    if (h_00 != (HGDIOBJ)0x0) {
      SelectObject(hdc,h_00);
    }
    SetROP2(hdc,rop2);
    ReleaseDC(*(HWND *)(param_1 + 8),hdc);
    DeleteObject(h);
    ClipCursor((RECT *)0x0);
  }
  return;
}



/* 004235a0  FUN_004235a0  435 bytes, 1 callers */

undefined4 __fastcall FUN_004235a0(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_00423480(param_1);
  local_10 = *(int *)(param_1 + 0x398);
  local_c = (*(int *)(param_1 + 0x39c) + *(int *)(param_1 + 0x260)) / local_10;
  iVar2 = (*(int *)(param_1 + 0x3a0) + *(int *)(param_1 + 0x264)) / local_10;
  iVar3 = (*(int *)(param_1 + 0x3ac) + *(int *)(param_1 + 0x260)) / local_10;
  local_10 = (*(int *)(param_1 + 0x3b0) + *(int *)(param_1 + 0x264)) / local_10;
  if (iVar3 == local_c) {
    iVar3 = iVar3 + 1;
  }
  if (local_10 == iVar2) {
    local_10 = local_10 + 1;
  }
  iVar6 = iVar3;
  if (iVar3 < local_c) {
    iVar6 = local_c;
    local_c = iVar3;
  }
  local_8 = iVar2;
  if (local_10 < iVar2) {
    local_8 = local_10;
    local_10 = iVar2;
  }
  iVar2 = 0;
  iVar3 = 0;
  DAT_00434440 = 0x40;
  do {
    iVar4 = iVar2 / 0x30;
    if ((local_c <= iVar4) && (iVar4 < iVar6)) {
      iVar5 = iVar2 % 0x30;
      if ((local_8 <= iVar5) && ((iVar5 < local_10 && (*(byte *)(DAT_0043453c + iVar3) < 0x40)))) {
        iVar4 = FUN_0040a020((uint)*(byte *)(DAT_0043453c + iVar3),iVar4,iVar5,1);
        if (iVar4 == 1) {
          if ((*(byte *)(DAT_00434538 + 0xd + (uint)*(byte *)(DAT_0043453c + iVar3) * 0x224) & 0x20)
              != 0) {
            DAT_00434440 = (uint)*(byte *)(DAT_0043453c + iVar3);
          }
          *(int *)(param_1 + 0x394) = *(int *)(param_1 + 0x394) + 1;
        }
      }
    }
    iVar3 = iVar3 + 0x18;
    iVar2 = iVar2 + 1;
  } while (iVar3 < 0xd800);
  if (*(int *)(param_1 + 0x394) == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x394) == 1) {
    return 1;
  }
  if (DAT_00434440 != 0x40) {
    puVar1 = (uint *)(DAT_00434538 + 0x21c + DAT_00434440 * 0x224);
    *puVar1 = *puVar1 & 0xfffffffe;
    *(undefined1 *)(DAT_00434538 + 0x220 + DAT_00434440 * 0x224) = 0xff;
    DAT_00434440 = 0x40;
  }
  return 1;
}



/* 00423760  FUN_00423760  115 bytes, 1 callers */

undefined4 __thiscall FUN_00423760(void *this,int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = 0;
  if ((param_1 < 0x30) && (param_2 < 0x30)) {
    iVar3 = 0;
    iVar4 = 0;
    *(char *)((int)this + 0x3c2) = (char)param_1;
    *(char *)((int)this + 0x3c3) = (char)param_2;
    do {
      if ((*(byte *)(DAT_00434538 + 0x21c + iVar4) & 1) != 0) {
        iVar1 = FUN_004237e0(iVar3,(byte *)((int)this + 0x3c2));
        if (iVar1 == 1) {
          uVar2 = 1;
        }
      }
      iVar4 = iVar4 + 0x224;
      iVar3 = iVar3 + 1;
    } while (iVar4 < 0x8900);
    return uVar2;
  }
  return 0;
}



/* 004237e0  FUN_004237e0  340 bytes, 2 callers */

undefined4 FUN_004237e0(int param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  
  FUN_00405360();
  FUN_00405510(param_1);
  bVar3 = *param_2;
  bVar4 = param_2[1];
  FUN_004056f0(param_2);
  iVar1 = param_1 * 0x224;
  FUN_0041a680((uint)*(byte *)(DAT_00434538 + iVar1),(uint)((byte *)(DAT_00434538 + iVar1))[1]);
  iVar2 = ((uint)bVar3 * 0x30 + (uint)bVar4) * 0x18;
  if (*(uint *)(DAT_0043453c + 8 + iVar2) < 0x1f0) {
    *(undefined1 *)(DAT_00434538 + 0x220 + iVar1) = 2;
    return 1;
  }
  FUN_00405360();
  FUN_00405440(param_1);
  FUN_004056f0(param_2);
  FUN_0041a680((uint)*(byte *)(DAT_00434538 + iVar1),(uint)((byte *)(DAT_00434538 + iVar1))[1]);
  if (0x1ef < *(uint *)(DAT_0043453c + 8 + iVar2)) {
    FUN_00405360();
    FUN_004056f0(param_2);
    FUN_0041a680((uint)*(byte *)(DAT_00434538 + iVar1),(uint)((byte *)(DAT_00434538 + iVar1))[1]);
    if (0x1ef < *(uint *)(DAT_0043453c + 8 + iVar2)) {
      *(undefined1 *)(DAT_00434538 + 0x220 + iVar1) = 1;
      return 0;
    }
    *(undefined1 *)(DAT_00434538 + 0x220 + iVar1) = 4;
    return 1;
  }
  *(undefined1 *)(DAT_00434538 + 0x220 + iVar1) = 3;
  return 1;
}



/* 00423940  FUN_00423940  844 bytes, 1 callers */

undefined4 __thiscall FUN_00423940(void *this,int *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  UINT_PTR UVar5;
  UINT_PTR *pUVar6;
  undefined *puVar7;
  LPCSTR pCVar8;
  undefined1 *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_40 [32];
  int *local_20;
  int *local_1c;
  HMENU local_18;
  int local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00423c94;
  *unaff_FS_OFFSET = &local_10;
  bVar1 = *(byte *)(DAT_0043453c + 0x10 +
                   ((uint)*(byte *)((int)this + 0x3c2) * 0x30 + (uint)*(byte *)((int)this + 0x3c3))
                   * 0x18);
  if (bVar1 == 0) {
    local_14 = 0;
  }
  else {
    uVar4 = (uint)bVar1;
    if (((int)(uVar4 - 8) < 4) && (-1 < (int)(uVar4 - 8))) {
      local_14 = 1;
    }
    else if (((int)(uVar4 - 0xc) < 4) && (-1 < (int)(uVar4 - 0xc))) {
      local_14 = 2;
    }
    else if (((int)(uVar4 - 1) < 4) && (-1 < (int)(uVar4 - 1))) {
      local_14 = 3;
    }
    else if (bVar1 == 0x7b) {
      local_14 = 4;
    }
    else if (((int)(uVar4 - 0x20) < 0x10) && (-1 < (int)(uVar4 - 0x20))) {
      local_14 = 5;
    }
    else if (bVar1 == 5) {
      local_14 = 6;
    }
    else if (bVar1 == 0x7a) {
      local_14 = 7;
    }
    else if (((int)(uVar4 - 0x30) < 0x30) && (-1 < (int)(uVar4 - 0x30))) {
      local_14 = 8;
    }
    else if (((int)(uVar4 - 0x14) < 4) && (-1 < (int)(uVar4 - 0x14))) {
      local_14 = 9;
    }
    else {
      local_14 = 10;
    }
  }
  UVar5 = 0x200;
  local_1c = this;
  FUN_00428220(local_40,4,8,FUN_0040e2f0,thunk_FUN_0040e460);
  this_00 = local_40;
  local_8 = 0;
  puVar7 = &DAT_00435bca;
  FUN_0040e2f0(&local_18);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_20 = local_1c + 0x5b9;
  do {
    wsprintfA((LPSTR)local_20,s__s_continue_00432470,puVar7);
    FUN_0040e310(this_00,UVar5,&DAT_00435b97,0);
    FUN_0040e310(this_00,UVar5 + 1,&DAT_00435b86,0);
    if (puVar7 != &DAT_00435bfd) {
      wsprintfA((LPSTR)local_20,s__s_continue_00432470,puVar7);
      FUN_0040e310(this_00,UVar5 + 2,(LPCSTR)local_20,0);
    }
    UVar5 = UVar5 + 3;
    this_00 = this_00 + 4;
    puVar7 = puVar7 + 0x11;
  } while (puVar7 < &DAT_00435c52);
  pUVar6 = (UINT_PTR *)&stack0xffffffb0;
  UVar5 = 500;
  pCVar8 = &DAT_00435b86;
  local_20 = (int *)0x0;
  local_14 = local_14 << 4;
  do {
    if (((&DAT_004341af)[local_14 - (int)local_20] == '\x01') ||
       ((&DAT_0043425f)[local_14 - (int)local_20] == '\x01')) {
      if (pCVar8 < (LPCSTR)0x435bca) {
        FUN_0040e310(&local_18,UVar5,pCVar8,0);
      }
      else {
        FUN_0040e390(&local_18,*pUVar6,pCVar8);
      }
    }
    else {
      FUN_0040e310(&local_18,UVar5,pCVar8,1);
    }
    pUVar6 = pUVar6 + 1;
    UVar5 = UVar5 + 3;
    pCVar8 = pCVar8 + 0x11;
    local_20 = (int *)((int)local_20 + 1);
  } while (pCVar8 < &DAT_00435c52);
  FUN_0040e400(&local_18);
  FUN_0040e330(&local_18,60000,0x9cc5,0);
  DAT_004365dc = 3;
  FUN_0040a1c0(0x15f93);
  iVar2 = TrackPopupMenu(local_18,0x102,*param_1,param_1[1],0,(HWND)local_1c[2],(RECT *)0x0);
  if (iVar2 == 60000) {
    DAT_004365dc = 1;
    iVar2 = 0;
  }
  if (iVar2 == 0) {
    iVar2 = 0;
    do {
      if ((*(byte *)(DAT_00434538 + iVar2 + 0x21c) & 1) != 0) {
        *(undefined1 *)(DAT_00434538 + iVar2 + 0x220) = 0;
      }
      iVar2 = iVar2 + 0x224;
    } while (iVar2 < 0x8900);
    (**(code **)(*local_1c + 100))();
    local_8 = local_8 & 0xffffff00;
    FUN_00423c8c();
    local_8 = 0xffffffff;
    FUN_00423c9e();
    uVar3 = 0;
  }
  else {
    DAT_004365d8 = (iVar2 + -500) / 3;
    FUN_00423cc0(local_1c,DAT_004365d8,(iVar2 + -500) % 3);
    local_8 = local_8 & 0xffffff00;
    FUN_00423c8c();
    local_8 = 0xffffffff;
    FUN_00423c9e();
    uVar3 = 1;
  }
  *unaff_FS_OFFSET = local_10;
  return uVar3;
}



/* 00423c8c  FUN_00423c8c  8 bytes, 1 callers */

void FUN_00423c8c(void)

{
  int unaff_EBP;
  
  thunk_FUN_0040e460((undefined4 *)(unaff_EBP + -0x14));
  return;
}



/* 00423c9e  FUN_00423c9e  19 bytes, 1 callers */

void FUN_00423c9e(void)

{
  int unaff_EBP;
  
  FUN_004280f0(unaff_EBP + -0x3c,4,8,thunk_FUN_0040e460);
  return;
}



/* 00423cc0  FUN_00423cc0  687 bytes, 2 callers */

void __thiscall FUN_00423cc0(void *this,undefined4 param_1,int param_2)

{
  byte *pbVar1;
  uint *puVar2;
  char cVar3;
  bool bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  
  bVar4 = false;
  iVar9 = 0;
  iVar10 = 0;
  do {
    if ((*(byte *)(DAT_00434538 + iVar9 + 0x21c) & 1) != 0) {
      if (DAT_00434548 == 0) {
        cVar3 = *(char *)(DAT_00434538 + iVar9 + 0x220);
        if (cVar3 == '\x03') {
          DAT_00434544 = 1;
        }
        else {
          if (cVar3 != '\x04') goto LAB_00423d3e;
          DAT_00434544 = 0;
        }
        DAT_0043454c = iVar10;
        FUN_004095d0(0x76,0,*(HWND *)(DAT_004344e4 + 8));
      }
LAB_00423d3e:
      if (DAT_00434548 == 2) {
LAB_00423eeb:
        *(undefined1 *)(DAT_00434538 + 0x220 + iVar9) = 0xff;
      }
      else {
        cVar3 = *(char *)(DAT_00434538 + 0x220 + iVar9);
        if (((cVar3 == '\x01') || (DAT_00434548 == 2)) || (cVar3 == -1)) goto LAB_00423eeb;
        bVar4 = true;
        bVar8 = (byte)DAT_004365d8;
        if (param_2 == 1) {
          bVar8 = (byte)DAT_004365d8 | 0x40;
        }
        if (param_2 == 2) {
          bVar8 = bVar8 | 0x80;
        }
        bVar5 = *(byte *)(DAT_00434538 + iVar9 + 0xd) & 0x20;
        if (bVar5 == 0) {
          bVar8 = bVar8 | 0x10;
        }
        else {
          bVar8 = bVar8 & 0xfd | 0xd;
        }
        *(byte *)(DAT_00434538 + iVar9 + 0xd) = bVar8 | bVar5;
        *(undefined1 *)(DAT_00434538 + 2 + iVar9) = *(undefined1 *)((int)this + 0x3c2);
        *(undefined1 *)(DAT_00434538 + 3 + iVar9) = *(undefined1 *)((int)this + 0x3c3);
        pbVar1 = (byte *)(DAT_00434538 + 0x10 + iVar9);
        *pbVar1 = *pbVar1 & 0xf3;
        FUN_00405360();
        FUN_004056f0((byte *)((int)this + 0x3c2));
        FUN_0041a680((uint)*(byte *)(DAT_00434538 + iVar9),(uint)((byte *)(DAT_00434538 + iVar9))[1]
                    );
        *(undefined4 *)(DAT_00434538 + 0x18 + iVar9) = 0x1f0;
        iVar6 = FUN_00405000(iVar10,(uint)*(byte *)((int)this + 0x3c2),
                             (uint)*(byte *)((int)this + 0x3c3));
        if (iVar6 == 1) {
          switch(bVar8 & 0xf) {
          case 6:
          case 7:
          case 9:
          case 10:
          case 0xb:
            FUN_004051b0(iVar10);
          }
switchD_00423e5f_caseD_8:
          iVar6 = DAT_00434538 + iVar9;
          if ((*(byte *)(iVar6 + 0xd) & 0x20) != 0) {
            uVar7 = (uint)*(byte *)(iVar6 + 4);
            if (*(byte *)(DAT_0043453c + 0x10 +
                         ((uint)*(byte *)(iVar6 + 2) * 0x30 + (uint)*(byte *)(iVar6 + 3)) * 0x18) -
                uVar7 == 0x14) {
              puVar2 = (uint *)(DAT_00434534 + 4 + uVar7 * 0x38);
              *puVar2 = *puVar2 & 0xfffffffd;
              puVar2 = (uint *)(DAT_00434534 + 4 + (uint)*(byte *)(DAT_00434538 + 4 + iVar9) * 0x38)
              ;
              *puVar2 = *puVar2 & 0xfffffffb;
            }
            else {
              puVar2 = (uint *)(DAT_00434534 + 4 + uVar7 * 0x38);
              *puVar2 = *puVar2 | 2;
            }
          }
        }
        else if (iVar6 == 10) goto switchD_00423e5f_caseD_8;
      }
      puVar2 = (uint *)(DAT_00434538 + 0x21c + iVar9);
      *puVar2 = *puVar2 & 0xfffffffe;
    }
    iVar9 = iVar9 + 0x224;
    iVar10 = iVar10 + 1;
    if (0x88ff < iVar9) {
      FUN_00409d50(0x9c7e,0);
      FUN_00409d50(0x9c7d,0);
      if (bVar4) {
        FUN_0040a1c0(0x15f92);
      }
      DAT_004321c8 = 0;
      DAT_00434548 = 0;
      DAT_004365dc = 0;
      DAT_00434440 = 0x40;
      return;
    }
  } while( true );
}



/* 00423f90  FUN_00423f90  289 bytes, 3 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00423f90(void *this,int param_1,int param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  LONG LVar2;
  int iVar3;
  int iVar4;
  tagRECT local_10;
  
  GetClientRect(*(HWND *)((int)this + 8),&local_10);
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)((int)this + 0x260);
    param_3[1] = *(undefined4 *)((int)this + 0x264);
  }
  if ((((0x2e < param_1) || (0x2e < param_2)) || (param_1 < 1)) || (param_2 < 1)) {
    _DAT_00434454 = _DAT_00434454 + 1;
  }
  if (param_4 != 0) {
    FUN_00422fd0(this,(uint)*(byte *)((int)this + 0x3c4),(uint)*(byte *)((int)this + 0x3c5));
    *(char *)((int)this + 0x3c0) = (char)param_1;
    *(undefined1 *)((int)this + 0x3c1) = (undefined1)param_2;
  }
  iVar3 = 0;
  iVar4 = 0;
  iVar1 = *(int *)((int)this + 0x398);
  if (local_10.right / 2 <= param_1 * iVar1) {
    iVar3 = ((param_1 * iVar1 - local_10.right / 2) / iVar1) * iVar1;
  }
  if (local_10.bottom / 2 <= param_2 * iVar1) {
    iVar4 = ((param_2 * iVar1 - local_10.bottom / 2) / iVar1) * iVar1;
  }
  FUN_00424b90(this,CONCAT31((int3)((uint)(iVar3 << 0x10) >> 8),4));
  FUN_00424cc0(this,CONCAT31((int3)((uint)(iVar4 << 0x10) >> 8),4));
  LVar2 = FUN_0040a0c0(0xea61);
  if (LVar2 != 0) {
    InvalidateRect(*(HWND *)(LVar2 + 8),(RECT *)0x0,0);
    UpdateWindow(*(HWND *)(LVar2 + 8));
  }
  return;
}



/* 004240c0  FUN_004240c0  646 bytes, 0 callers */

void __fastcall FUN_004240c0(int param_1)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0;
  do {
    local_4 = 0;
    iVar8 = local_8;
    do {
      uVar5 = *(uint *)(param_1 + 0x398);
      iVar1 = iVar8 * 0x18;
      bVar2 = *(byte *)(DAT_0043453c + 0x10 + iVar1);
      iVar7 = (local_8 * uVar5 * 0x30 + local_4) * uVar5;
      if (*(byte *)(param_1 + 0x3c6 + iVar8 * 2) != bVar2) {
        FUN_004243c0((uint)bVar2,uVar5,*(int *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24),
                     (undefined4 *)(*(int *)(param_1 + 0x25c) + iVar7),*(int *)(param_1 + 0x15c8));
        *(undefined1 *)(param_1 + 0x3c6 + iVar8 * 2) = *(undefined1 *)(DAT_0043453c + 0x10 + iVar1);
        *(undefined1 *)(param_1 + 0x3c7 + iVar8 * 2) = 1;
      }
      if (*(byte *)(DAT_0043453c + iVar1) < 0x40) {
        iVar9 = *(int *)(param_1 + 0x15cc);
        uVar12 = *(undefined4 *)(param_1 + 0x24);
        iVar6 = *(int *)(param_1 + 0x25c) + iVar7;
        iVar11 = *(int *)(param_1 + 0x20);
        iVar10 = *(int *)(param_1 + 0x398);
        uVar5 = FUN_0041b520((uint)*(byte *)(DAT_0043453c + iVar1));
        FUN_00424460(uVar5,iVar10,iVar11,uVar12,iVar6,iVar9);
        *(undefined1 *)(param_1 + 0x3c6 + iVar8 * 2) = 0xff;
        *(undefined1 *)(param_1 + 0x3c7 + iVar8 * 2) = 1;
        if ((DAT_004376a1 != '\0') &&
           (bVar2 = *(byte *)(DAT_00434538 + 0x220 + (uint)*(byte *)(DAT_0043453c + iVar1) * 0x224),
           bVar2 != 0xff)) {
          iVar9 = *(int *)(param_1 + 0x398);
          FUN_004244b0((uint)bVar2,iVar9,*(int *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24),
                       iVar9 * iVar9 * -0x30 + *(int *)(param_1 + 0x25c) + iVar7);
          *(undefined1 *)(param_1 + 0x3c4 + iVar8 * 2) = 0xff;
          *(undefined1 *)(param_1 + 0x3c5 + iVar8 * 2) = 1;
        }
      }
      iVar1 = *(int *)(DAT_0043453c + 0x14 + iVar1);
      if (iVar1 != 0) {
        FUN_00424460((DAT_00435b1c & 1) + iVar1,*(int *)(param_1 + 0x398),*(int *)(param_1 + 0x20),
                     *(undefined4 *)(param_1 + 0x24),*(int *)(param_1 + 0x25c) + iVar7,
                     *(int *)(param_1 + 0x15cc));
        *(undefined1 *)(param_1 + 0x3c6 + iVar8 * 2) = 0xff;
        *(undefined1 *)(param_1 + 0x3c7 + iVar8 * 2) = 1;
      }
      iVar8 = iVar8 + 0x30;
      local_4 = local_4 + 1;
    } while (local_4 < 0x30);
    local_8 = local_8 + 1;
  } while (local_8 < 0x30);
  if (DAT_004365dc != 2) {
    iVar1 = *(int *)(param_1 + 0x398);
    bVar2 = *(byte *)(param_1 + 0x3c1);
    iVar8 = iVar1 + 0x1078;
    bVar3 = *(byte *)(param_1 + 0x3c0);
    iVar7 = 0;
    if (0 < iVar1) {
      do {
        iVar9 = 0;
        if (0 < *(int *)(param_1 + 0x398)) {
          do {
            cVar4 = *(char *)(iVar8 + iVar9 + DAT_00435fd4);
            if (cVar4 != 'p') {
              *(char *)(*(int *)(param_1 + 0x398) * iVar7 * 0x30 + *(int *)(param_1 + 0x25c) +
                        ((uint)bVar2 * iVar1 * 0x30 + (uint)bVar3) * iVar1 + iVar9) = cVar4;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < *(int *)(param_1 + 0x398));
        }
        iVar8 = iVar8 + 0x100;
        iVar7 = iVar7 + 1;
      } while (iVar7 < *(int *)(param_1 + 0x398));
    }
    iVar8 = param_1 + ((uint)*(byte *)(param_1 + 0x3c0) * 0x30 + (uint)*(byte *)(param_1 + 0x3c1)) *
                      2;
    *(undefined1 *)(iVar8 + 0x3c6) = 0xff;
    *(undefined1 *)(iVar8 + 0x3c7) = 1;
  }
  return;
}



/* 004243c0  FUN_004243c0  66 bytes, 4 callers */

void __cdecl
FUN_004243c0(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 *param_5,int param_6
            )

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (0 < (int)param_2) {
    uVar1 = param_2;
    puVar3 = (undefined4 *)(param_6 + param_2 * param_2 * param_1);
    do {
      puVar4 = puVar3;
      puVar5 = param_5;
      for (uVar2 = param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      for (uVar2 = param_2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
      param_5 = (undefined4 *)((int)param_5 + param_3);
      uVar1 = uVar1 - 1;
      puVar3 = (undefined4 *)((int)puVar3 + param_2);
    } while (uVar1 != 0);
  }
  return;
}



/* 00424410  FUN_00424410  72 bytes, 1 callers */

void __cdecl
FUN_00424410(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6,
            char param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (0 < param_2) {
    iVar2 = param_6 + param_2 * param_2 * param_1;
    iVar1 = param_2;
    do {
      iVar3 = 0;
      if (0 < param_2) {
        do {
          iVar4 = iVar3 + 1;
          *(char *)(iVar3 + param_5) = *(char *)(iVar3 + iVar2) + param_7;
          iVar3 = iVar4;
        } while (iVar4 < param_2);
      }
      iVar2 = iVar2 + param_2;
      param_5 = param_5 + param_3;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}



/* 00424460  FUN_00424460  72 bytes, 4 callers */

void __cdecl
FUN_00424460(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (0 < param_2) {
    iVar2 = param_2 * param_2 * param_1 + param_6;
    iVar1 = param_2;
    do {
      iVar3 = 0;
      if (0 < param_2) {
        do {
          if (*(char *)(iVar3 + iVar2) != 'p') {
            *(char *)(iVar3 + param_5) = *(char *)(iVar3 + iVar2);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < param_2);
      }
      param_5 = param_5 + param_3;
      iVar2 = iVar2 + param_2;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}



/* 004244b0  FUN_004244b0  101 bytes, 4 callers */

void __cdecl FUN_004244b0(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((DAT_004376a1 != '\0') &&
     (iVar2 = param_1 * 0x2000 + 0xc0 + param_2, iVar1 = param_2, 0 < param_2)) {
    do {
      iVar3 = 0;
      if (0 < param_2) {
        do {
          if (*(char *)(DAT_00435fd4 + iVar2 + iVar3) != 'p') {
            *(undefined1 *)(iVar3 + param_5) = *(undefined1 *)(DAT_00435fd4 + iVar2 + iVar3);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < param_2);
      }
      param_5 = param_5 + param_3;
      iVar2 = iVar2 + 0x100;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}



/* 00424520  FUN_00424520  255 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00424520(void *this,uint param_1)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  local_c = *(undefined4 *)((int)this + 0x260);
  local_8 = *(undefined4 *)((int)this + 0x264);
  iVar1 = param_1 * 0x38 + DAT_00434534;
  FUN_00423f90(this,(uint)*(byte *)(iVar1 + 8),(uint)*(byte *)(iVar1 + 9),(undefined4 *)0x0,0);
  FUN_004095d0(0x7a,param_1 << 0x10,*(HWND *)(DAT_004344e4 + 8));
  FUN_00424620(this,(ushort *)&local_c);
  if ((DAT_004365cd != param_1) && (DAT_00437570 == 0)) {
    iVar1 = FUN_0041abd0(5);
    local_c = 0x17000f;
    DAT_00437570 = 0xcc;
    local_8 = 0x2f002f;
    local_4 = 0x2f;
    local_3 = 0x17;
    DAT_0043757c = 1;
    DAT_0043757d = 7;
    local_2 = 0x2f;
    local_1 = 0xf;
    DAT_00437574 = (int)*(char *)((int)&local_c + iVar1 * 2);
    _DAT_00437578 = (int)*(char *)((int)&local_c + iVar1 * 2 + 1);
  }
  return;
}



/* 00424620  FUN_00424620  48 bytes, 3 callers */

void __thiscall FUN_00424620(void *this,ushort *param_1)

{
  FUN_00424b90(this,CONCAT31((int3)(((uint)*param_1 << 0x10) >> 8),4));
  FUN_00424cc0(this,CONCAT31((int3)(((uint)param_1[2] << 0x10) >> 8),4));
  return;
}



/* 00424650  FUN_00424650  282 bytes, 0 callers */

void __thiscall FUN_00424650(void *this,int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char local_8;
  
  iVar4 = param_1 * 0x38 + DAT_00434534;
  bVar1 = *(byte *)(iVar4 + 8);
  bVar2 = *(byte *)(iVar4 + 9);
  if ((*(byte *)(iVar4 + 4) & 0x40) == 0) {
    local_8 = '\0';
    if (param_2 != 0) {
      local_8 = '\x10';
    }
    iVar4 = -1;
    do {
      iVar5 = -1;
      iVar6 = (bVar1 - 1) * 0x30 + (uint)bVar2 + iVar4;
      do {
        if (((iVar4 != 0) || (iVar5 != 0)) && ((iVar4 != 1 || (iVar5 != 0)))) {
          iVar3 = *(int *)((int)this + 0x398);
          FUN_00424410((uint)*(byte *)(DAT_0043453c + 0x10 + iVar6 * 0x18),iVar3,
                       *(int *)((int)this + 0x20),*(undefined4 *)((int)this + 0x24),
                       *(int *)((int)this + 0x25c) +
                       (((uint)bVar2 + iVar4) * iVar3 * 0x30 + iVar5 + (uint)bVar1) * iVar3,
                       *(int *)((int)this + 0x15c8),local_8);
          *(undefined1 *)((int)this + iVar6 * 2 + 0x3c6) = 0xff;
        }
        iVar6 = iVar6 + 0x30;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 2);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    InvalidateRect(*(HWND *)((int)this + 8),(RECT *)0x0,0);
    UpdateWindow(*(HWND *)((int)this + 8));
  }
  return;
}



/* 00424770  FUN_00424770  51 bytes, 3 callers */

void __fastcall FUN_00424770(int *param_1)

{
  LONG LVar1;
  
  (**(code **)(*param_1 + 100))();
  LVar1 = FUN_0040a0c0(0xea61);
  if (LVar1 != 0) {
    InvalidateRect(*(HWND *)(LVar1 + 8),(RECT *)0x0,0);
    UpdateWindow(*(HWND *)(LVar1 + 8));
  }
  return;
}



/* 004247b0  FUN_004247b0  562 bytes, 1 callers */

void FUN_004247b0(void)

{
  int iVar1;
  byte *pbVar2;
  uint *puVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte local_2;
  byte local_1;
  
  if (((*(byte *)(DAT_00434534 + 4) & 0x40) != 0) || (*(int *)(DAT_00434534 + 0xc) == 0x40)) {
    return;
  }
  local_2 = *(byte *)(DAT_00434534 + 8);
  local_1 = *(byte *)(DAT_00434534 + 9);
  iVar7 = *(int *)(DAT_00434534 + 0xc);
  iVar1 = iVar7 * 0x224;
  if ((*(byte *)(DAT_00434538 + iVar1) == local_2) &&
     (((byte *)(DAT_00434538 + iVar1))[1] == local_1)) {
    return;
  }
  if (DAT_004365dc != 0) {
    FUN_00409f90();
  }
  iVar5 = FUN_004237e0(iVar7,&local_2);
  if (iVar5 == 0) {
    FUN_0040a1c0(0x15f95);
    FUN_00409370(s_There_is_no_through_path__00434464,0);
    return;
  }
  cVar4 = *(char *)(DAT_00434538 + 0x220 + iVar1);
  if (cVar4 == '\x03') {
    DAT_00434544 = 1;
  }
  else {
    if (cVar4 != '\x04') goto LAB_0042488b;
    DAT_00434544 = 0;
  }
  DAT_0043454c = iVar7;
  FUN_004095d0(0x76,0,*(HWND *)(DAT_004344e4 + 8));
LAB_0042488b:
  pbVar2 = (byte *)(DAT_00434538 + 0xd + iVar1);
  *pbVar2 = *pbVar2 & 0x20 | 0xd;
  *(byte *)(DAT_00434538 + 2 + iVar1) = local_2;
  *(byte *)(DAT_00434538 + 3 + iVar1) = local_1;
  pbVar2 = (byte *)(DAT_00434538 + 0x10 + iVar1);
  *pbVar2 = *pbVar2 & 0xf3;
  FUN_00405360();
  FUN_004056f0(&local_2);
  FUN_0041a680((uint)*(byte *)(DAT_00434538 + iVar1),(uint)((byte *)(DAT_00434538 + iVar1))[1]);
  *(undefined4 *)(DAT_00434538 + 0x18 + iVar1) = 0x1f0;
  FUN_00405000(iVar7,(uint)local_2,(uint)local_1);
  iVar7 = DAT_00434538 + iVar1;
  if ((*(byte *)(iVar7 + 0xd) & 0x20) != 0) {
    uVar6 = (uint)*(byte *)(iVar7 + 4);
    if (*(byte *)(DAT_0043453c + 0x10 +
                 ((uint)*(byte *)(iVar7 + 2) * 0x30 + (uint)*(byte *)(iVar7 + 3)) * 0x18) - uVar6 ==
        0x14) {
      puVar3 = (uint *)(DAT_00434534 + 4 + uVar6 * 0x38);
      *puVar3 = *puVar3 & 0xfffffffd;
      puVar3 = (uint *)(DAT_00434534 + 4 + (uint)*(byte *)(DAT_00434538 + 4 + iVar1) * 0x38);
      *puVar3 = *puVar3 & 0xfffffffb;
    }
    else {
      puVar3 = (uint *)(DAT_00434534 + 4 + uVar6 * 0x38);
      *puVar3 = *puVar3 | 2;
    }
  }
  puVar3 = (uint *)(DAT_00434538 + 0x21c + iVar1);
  *puVar3 = *puVar3 & 0xfffffffe;
  FUN_0040a1c0(0x15f92);
  DAT_004365dc = 0;
  return;
}



/* 004249f0  FUN_004249f0  28 bytes, 1 callers */

void __thiscall FUN_004249f0(void *this,uint *param_1)

{
  *param_1 = (uint)*(byte *)((int)this + 0x3c0);
  param_1[1] = (uint)*(byte *)((int)this + 0x3c1);
  return;
}



/* 00424a10  FUN_00424a10  376 bytes, 0 callers */

void __fastcall FUN_00424a10(void *param_1)

{
  int iVar1;
  SHORT SVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  tagPOINT local_34;
  tagMSG local_2c;
  tagRECT local_10;
  
  if (*(int *)((int)param_1 + 0x17f4) == 0) {
    GetClientRect(*(HWND *)((int)param_1 + 8),&local_10);
    iVar3 = *(int *)((int)param_1 + 0x17f0);
    uVar7 = *(uint *)((int)param_1 + 0x14) & 0xffff;
    uVar4 = *(uint *)((int)param_1 + 0x14) >> 0x10;
    iVar1 = *(int *)((int)param_1 + 0x264);
    local_34.y = iVar1;
    if ((int)uVar4 < iVar3) {
      local_34.y = 0;
      iVar5 = iVar1 - (iVar3 - uVar4);
      if (0 < iVar5) {
        local_34.y = iVar5;
      }
    }
    if (iVar3 < (int)uVar4) {
      local_34.y = (uVar4 - iVar3) + iVar1;
    }
    iVar3 = *(int *)((int)param_1 + 0x17ec);
    local_34.x = *(uint *)((int)param_1 + 0x260);
    if ((int)uVar7 < iVar3) {
      local_34.x = 0;
      uVar6 = *(int *)((int)param_1 + 0x260) - (iVar3 - uVar7);
      if (0 < (int)uVar6) {
        local_34.x = uVar6;
      }
    }
    if (iVar3 < (int)uVar7) {
      local_34.x = (uVar7 - iVar3) + *(int *)((int)param_1 + 0x260);
    }
    SVar2 = GetAsyncKeyState(2);
    if (SVar2 == 0) {
      PeekMessageA(&local_2c,*(HWND *)((int)param_1 + 8),0x200,0x209,1);
      return;
    }
    *(uint *)((int)param_1 + 0x17ec) = uVar7;
    *(undefined4 *)((int)param_1 + 0x17e8) = 1;
    *(uint *)((int)param_1 + 0x17f0) = uVar4;
    FUN_00424620(param_1,(ushort *)&local_34);
    GetCursorPos(&local_34);
    ScreenToClient(*(HWND *)((int)param_1 + 8),&local_34);
    PostMessageA(*(HWND *)((int)param_1 + 8),0x200,2,local_34.y << 0x10 | local_34.x & 0xffffU);
  }
  else {
    iVar3 = *(int *)((int)param_1 + 0x17f4) + -1;
    *(int *)((int)param_1 + 0x17f4) = iVar3;
    if (iVar3 == 0) {
      PeekMessageA(&local_2c,*(HWND *)((int)param_1 + 8),0x200,0x209,1);
      return;
    }
  }
  return;
}



/* 00424b90  FUN_00424b90  267 bytes, 3 callers */

void __thiscall FUN_00424b90(void *this,uint param_1)

{
  uint uVar1;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  tagRECT local_2c;
  tagSCROLLINFO local_1c;
  
  GetWindowRect(*(HWND *)((int)this + 8),&local_2c);
  iVar4 = *(int *)((int)this + 0x260);
  local_2c.right = (local_2c.right - local_2c.left) - *(int *)((int)this + 0x18);
  local_2c.bottom = (local_2c.bottom - local_2c.top) - *(int *)((int)this + 0x1c);
  switch(param_1 & 0xffff) {
  case 0:
    uVar1 = iVar4 - 8;
    break;
  case 1:
    uVar1 = iVar4 + 8;
    break;
  case 2:
    uVar1 = iVar4 - local_2c.right;
    break;
  case 3:
    uVar1 = iVar4 + local_2c.right;
    break;
  case 4:
  case 5:
    uVar1 = param_1 >> 0x10;
    break;
  default:
    goto switchD_00424bdb_default;
  }
  if ((int)uVar1 < 0) {
    uVar1 = 0;
  }
  iVar4 = *(int *)((int)this + 0x20);
  local_1c.cbSize = 0x1c;
  local_1c.fMask = 0x17;
  BVar2 = GetScrollInfo(*(HWND *)((int)this + 8),1,&local_1c);
  if ((BVar2 != 0) && (local_1c.nMax != 0)) {
    iVar3 = GetSystemMetrics(2);
    iVar4 = iVar4 + iVar3;
  }
  local_1c.nPos = uVar1;
  if (iVar4 - local_2c.right < (int)uVar1) {
    local_1c.nPos = iVar4 - local_2c.right;
  }
  *(int *)((int)this + 0x260) = local_1c.nPos;
  local_1c.nMin = 0;
  local_1c.nMax = iVar4;
  if (*(int *)((int)this + 0x20) <= local_2c.right) {
    local_1c.nMax = 0;
  }
  local_1c.nPage = local_2c.right;
  SetScrollInfo(*(HWND *)((int)this + 8),0,&local_1c,1);
  (**(code **)(*(int *)this + 100))();
switchD_00424bdb_default:
  return;
}



/* 00424cc0  FUN_00424cc0  302 bytes, 3 callers */

void __thiscall FUN_00424cc0(void *this,uint param_1)

{
  BOOL BVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  tagRECT local_3c;
  tagSCROLLINFO local_2c;
  tagRECT local_10;
  
  GetWindowRect(*(HWND *)((int)this + 8),&local_3c);
  iVar4 = *(int *)((int)this + 0x264);
  local_3c.right = (local_3c.right - local_3c.left) - *(int *)((int)this + 0x18);
  local_3c.bottom = (local_3c.bottom - local_3c.top) - *(int *)((int)this + 0x1c);
  switch(param_1 & 0xffff) {
  case 0:
    uVar3 = iVar4 - 8;
    break;
  case 1:
    uVar3 = iVar4 + 8;
    break;
  case 2:
    uVar3 = iVar4 - local_3c.bottom;
    break;
  case 3:
    uVar3 = iVar4 + local_3c.bottom;
    break;
  case 4:
  case 5:
    uVar3 = param_1 >> 0x10;
    break;
  default:
    goto switchD_00424d0c_default;
  }
  if ((int)uVar3 < 0) {
    uVar3 = 0;
  }
  iVar4 = *(int *)((int)this + 0x24);
  local_2c.cbSize = 0x1c;
  local_2c.fMask = 0x17;
  BVar1 = GetScrollInfo(*(HWND *)((int)this + 8),0,&local_2c);
  if ((BVar1 != 0) && (local_2c.nMax != 0)) {
    iVar2 = GetSystemMetrics(3);
    iVar4 = iVar4 + iVar2;
  }
  iVar2 = GetSystemMetrics(0x21);
  if ((iVar4 - iVar2) - local_3c.bottom < (int)uVar3) {
    uVar3 = iVar4 - local_3c.bottom;
  }
  GetClientRect(*(HWND *)((int)this + 8),&local_10);
  *(uint *)((int)this + 0x264) = uVar3;
  local_2c.nMin = 0;
  local_2c.nMax = iVar4;
  if (*(int *)((int)this + 0x24) <= local_10.bottom) {
    local_2c.nMax = 0;
  }
  local_2c.nPage = local_3c.bottom;
  local_2c.nPos = uVar3;
  SetScrollInfo(*(HWND *)((int)this + 8),1,&local_2c,1);
  (**(code **)(*(int *)this + 100))();
switchD_00424d0c_default:
  return;
}



/* 00424e10  FUN_00424e10  310 bytes, 1 callers */

undefined4 * __thiscall FUN_00424e10(void *this,LPCSTR param_1)

{
  char cVar1;
  LSTATUS LVar2;
  int iVar3;
  DWORD cbData;
  uint uVar4;
  char *pcVar5;
  DWORD local_110;
  uint local_10c;
  DWORD local_108;
  BYTE local_104 [260];
  
  FUN_00424f60(this,param_1);
  *(undefined4 *)this = 0x2c;
  *(undefined4 *)((int)this + 4) = 0;
  while( true ) {
    LVar2 = RegCreateKeyExA((HKEY)0x80000002,(LPCSTR)((int)this + 0x44),0,(LPSTR)0x0,0,0xf003f,
                            (LPSECURITY_ATTRIBUTES)0x0,(PHKEY)((int)this + 0x148),&local_110);
    if (LVar2 != 0) {
      return this;
    }
    if (local_110 == 1) break;
    local_10c = 0xffffffff;
    pcVar5 = &DAT_00434484;
    do {
      if (local_10c == 0) break;
      local_10c = local_10c - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    local_108 = 1;
    local_10c = ~local_10c;
    LVar2 = RegQueryValueExA(*(HKEY *)((int)this + 0x148),&DAT_00434480,(LPDWORD)0x0,&local_108,
                             local_104,&local_10c);
    if (LVar2 == 0) {
      uVar4 = 0xffffffff;
      pcVar5 = &DAT_00434484;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      iVar3 = _strncmp(&DAT_00434484,(char *)local_104,~uVar4 - 1);
      if (iVar3 == 0) {
        return this;
      }
    }
    RegDeleteKeyA((HKEY)0x80000002,(LPCSTR)((int)this + 0x44));
  }
  cbData = lstrlenA(s_LordMonarch_00434498);
  RegSetValueExA(*(HKEY *)((int)this + 0x148),s_DisplayName_0043448c,0,1,
                 (BYTE *)s_LordMonarch_00434498,cbData);
  uVar4 = 0xffffffff;
  pcVar5 = &DAT_00434484;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  RegSetValueExA(*(HKEY *)((int)this + 0x148),&DAT_00434480,0,1,&DAT_00434484,~uVar4);
  return this;
}



/* 00424f50  FUN_00424f50  1 bytes, 1 callers */

void FUN_00424f50(void)

{
  return;
}



/* 00424f60  FUN_00424f60  32 bytes, 1 callers */

void __thiscall FUN_00424f60(void *this,LPCSTR param_1)

{
  lstrcpyA((LPSTR)((int)this + 0x44),s_SOFTWARE_Falcom__004344a4);
  lstrcatA((LPSTR)((int)this + 0x44),param_1);
  return;
}



/* 00424f80  FUN_00424f80  21 bytes, 1 callers */

void __thiscall FUN_00424f80(void *this,LPCSTR param_1)

{
  RegDeleteValueA(*(HKEY *)((int)this + 0x148),param_1);
  return;
}



/* 00424fa0  FUN_00424fa0  97 bytes, 2 callers */

bool __thiscall FUN_00424fa0(void *this,LPCSTR param_1)

{
  LSTATUS LVar1;
  DWORD local_8 [2];
  
  local_8[1] = 3;
  local_8[0] = 0x34;
  LVar1 = RegQueryValueExA(*(HKEY *)((int)this + 0x148),param_1,(LPDWORD)0x0,local_8 + 1,this,
                           local_8);
  *(int *)((int)this + 0x34) = *(int *)((int)this + 0x1c);
  *(int *)((int)this + 0x38) = *(int *)((int)this + 0x20);
  *(int *)((int)this + 0x3c) = *(int *)((int)this + 0x24) - *(int *)((int)this + 0x1c);
  *(int *)((int)this + 0x40) = *(int *)((int)this + 0x28) - *(int *)((int)this + 0x20);
  return LVar1 == 0;
}



/* 00425010  FUN_00425010  61 bytes, 2 callers */

bool __thiscall FUN_00425010(void *this,LPCSTR param_1,HWND param_2)

{
  BOOL BVar1;
  LSTATUS LVar2;
  
  BVar1 = GetWindowPlacement(param_2,this);
  if (BVar1 == 0) {
    return false;
  }
  LVar2 = RegSetValueExA(*(HKEY *)((int)this + 0x148),param_1,0,3,this,0x34);
  return LVar2 == 0;
}



/* 00425050  FUN_00425050  45 bytes, 1 callers */

bool __thiscall FUN_00425050(void *this,LPCSTR param_1,BYTE *param_2,DWORD param_3,DWORD param_4)

{
  LSTATUS LVar1;
  
  LVar1 = RegSetValueExA(*(HKEY *)((int)this + 0x148),param_1,0,param_4,param_2,param_3);
  return LVar1 == 0;
}



/* 00425080  FUN_00425080  67 bytes, 1 callers */

bool __thiscall FUN_00425080(void *this,LPCSTR param_1,LPBYTE param_2,DWORD param_3,DWORD param_4)

{
  LSTATUS LVar1;
  DWORD local_8;
  DWORD local_4;
  
  local_4 = param_4;
  local_8 = param_3;
  LVar1 = RegQueryValueExA(*(HKEY *)((int)this + 0x148),param_1,(LPDWORD)0x0,&local_4,param_2,
                           &local_8);
  return LVar1 == 0;
}



/* 004250d0  FUN_004250d0  144 bytes, 2 callers */

undefined4 * __fastcall FUN_004250d0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &PTR_FUN_00430830;
  param_1[0x94] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  iVar1 = GetSystemMetrics(0);
  param_1[8] = iVar1;
  iVar1 = GetSystemMetrics(1);
  param_1[9] = iVar1;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x95] = 0;
  param_1[0x96] = 0;
  param_1[0x97] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[0x9a] = 0xffffffff;
  param_1[0x9b] = 0xffffffff;
  *(undefined1 *)(param_1 + 0xe1) = 0;
  param_1[0xe2] = 0xc0;
  param_1[0xe3] = 0xc0;
  return param_1;
}



/* 00425160  FUN_00425160  30 bytes, 0 callers */

undefined4 * __thiscall FUN_00425160(void *this,byte param_1)

{
  FUN_00425180(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 00425180  FUN_00425180  108 bytes, 3 callers */

void __fastcall FUN_00425180(undefined4 *param_1)

{
  HMENU hMenu;
  
  *param_1 = &PTR_FUN_00430830;
  param_1[2] = 0;
  if ((HDC)param_1[0x95] != (HDC)0x0) {
    DeleteDC((HDC)param_1[0x95]);
    param_1[0x95] = 0;
  }
  if ((HGDIOBJ)param_1[0x96] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)param_1[0x96]);
    param_1[0x96] = 0;
  }
  hMenu = GetMenu((HWND)param_1[0x94]);
  if (hMenu != (HMENU)0x0) {
    DeleteMenu(hMenu,param_1[1] + 1000,0);
  }
  return;
}



/* 004251f0  FUN_004251f0  31 bytes, 0 callers */

void __thiscall
FUN_004251f0(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)((int)this + 8) = param_1;
  *(undefined4 *)((int)this + 0xc) = param_2;
  *(undefined4 *)((int)this + 0x10) = param_3;
  *(undefined4 *)((int)this + 0x14) = param_4;
  return;
}



/* 00425210  FUN_00425210  431 bytes, 1 callers */

undefined4 __thiscall FUN_00425210(void *this,int param_1,int param_2)

{
  undefined4 *puVar1;
  void *pvVar2;
  bool bVar3;
  undefined3 extraout_var;
  LONG LVar4;
  int iVar5;
  int iVar6;
  HMENU hMenu;
  tagRECT local_20;
  tagRECT local_10;
  
  *(int *)((int)this + 4) = param_2;
  puVar1 = (undefined4 *)((int)this + 0x38);
  *puVar1 = 0;
  *(int *)((int)this + 0x250) = param_1;
  *(int *)((int)this + 0x40) = *(int *)((int)this + 0x18) + *(int *)((int)this + 0x20);
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(int *)((int)this + 0x44) = *(int *)((int)this + 0x24) + *(int *)((int)this + 0x1c);
  bVar3 = FUN_00424fa0(DAT_00436460,(LPCSTR)((int)this + 0x14c));
  pvVar2 = DAT_00436460;
  bVar3 = CONCAT31(extraout_var,bVar3) != 1;
  if (bVar3) {
    *puVar1 = *(undefined4 *)((int)this + 0x28);
    *(undefined4 *)((int)this + 0x3c) = *(undefined4 *)((int)this + 0x2c);
    *(undefined4 *)((int)this + 0x40) = *(undefined4 *)((int)this + 0x30);
    *(undefined4 *)((int)this + 0x44) = *(undefined4 *)((int)this + 0x34);
  }
  else {
    *puVar1 = *(undefined4 *)((int)DAT_00436460 + 0x34);
    *(undefined4 *)((int)this + 0x3c) = *(undefined4 *)((int)pvVar2 + 0x38);
    *(undefined4 *)((int)this + 0x40) = *(undefined4 *)((int)pvVar2 + 0x3c);
    *(undefined4 *)((int)this + 0x44) = *(undefined4 *)((int)pvVar2 + 0x40);
  }
  if ((((*(int *)((int)this + 0x3c) == 0) || (bVar3)) && (*(int *)((int)this + 4) != 0xea65)) &&
     (*(int *)((int)this + 4) != 70000)) {
    LVar4 = FUN_0040a0c0(0xea65);
    if ((LVar4 != 0) && (DAT_004376a3 == '\0')) {
      GetWindowRect(*(HWND *)(LVar4 + 8),&local_20);
      *(int *)((int)this + 0x3c) = *(int *)((int)this + 0x3c) + (local_20.bottom - local_20.top);
      if (*(int *)((int)this + 4) == 60000) {
        GetClientRect(*(HWND *)(DAT_004344e4 + 8),&local_10);
        if (local_10.bottom < *(int *)((int)this + 0x44) + *(int *)((int)this + 0x3c)) {
          *(LONG *)((int)this + 0x44) = local_10.bottom - *(int *)((int)this + 0x3c);
        }
      }
    }
  }
  iVar6 = *(int *)this;
  iVar5 = (**(code **)(iVar6 + 8))();
  if (iVar5 != 0) {
    iVar6 = (**(code **)(iVar6 + 0xc))();
    if (iVar6 != 0) {
      hMenu = GetMenu(*(HWND *)((int)this + 0x250));
      if (hMenu != (HMENU)0x0) {
        InsertMenuA(hMenu,0x9caf,0,*(int *)((int)this + 4) + 1000,(LPCSTR)((int)this + 0x48));
      }
      SetWindowPos(*(HWND *)((int)this + 8),(HWND)0x0,0,0,0,0,3);
      InvalidateRect(*(HWND *)((int)this + 8),(RECT *)0x0,0);
      UpdateWindow(*(HWND *)((int)this + 8));
      return 1;
    }
  }
  FUN_00409370(s_Fatal_error__Quitting__004344b8,0);
  return 0;
}



/* 00425420  FUN_00425420  552 bytes, 0 callers */

undefined4 __fastcall FUN_00425420(int *param_1)

{
  uint uVar1;
  HWND pHVar2;
  
  uVar1 = param_1[3];
  if (uVar1 < 0x10) {
    if (uVar1 == 0xf) {
      (**(code **)(*param_1 + 0x40))();
      return 0;
    }
    if (uVar1 == 1) {
      (**(code **)(*param_1 + 0x20))();
      return 0;
    }
    if (uVar1 == 2) {
      (**(code **)(*param_1 + 0x68))();
      return 1;
    }
    return 0;
  }
  if (uVar1 < 0x25) {
    if (uVar1 == 0x24) {
      (**(code **)(*param_1 + 0x60))();
      return 0;
    }
    if (uVar1 == 0x10) {
      (**(code **)(*param_1 + 0x3c))();
      return 0;
    }
    return 0;
  }
  if (uVar1 < 0x112) {
    if (uVar1 == 0x111) {
      (**(code **)(*param_1 + 0x24))();
      return 1;
    }
    if (uVar1 == 0x47) {
      (**(code **)(*param_1 + 0x5c))();
      return 1;
    }
    return 0;
  }
  if (uVar1 < 0x201) {
    if (uVar1 == 0x200) {
      (**(code **)(*param_1 + 0x44))();
      return 0;
    }
    if (uVar1 == 0x113) {
      (**(code **)(*param_1 + 100))();
      return 1;
    }
    return 0;
  }
  if (uVar1 < 0x211) {
    if (uVar1 == 0x210) {
      (**(code **)(*param_1 + 0x6c))();
      return 1;
    }
    switch(uVar1) {
    case 0x201:
      SetCapture((HWND)param_1[2]);
      FUN_00425a30((int)param_1);
      (**(code **)(*param_1 + 0x48))();
      if ((HWND)param_1[0x94] != (HWND)0x0) {
        pHVar2 = GetWindow((HWND)param_1[0x94],5);
        if ((HWND)param_1[2] != pHVar2) {
          BringWindowToTop((HWND)param_1[2]);
        }
      }
      return 0;
    case 0x202:
      ClipCursor((RECT *)0x0);
      (**(code **)(*param_1 + 0x4c))();
      ReleaseCapture();
      *(undefined1 *)(param_1 + 0xe1) = 0;
      param_1[0x9a] = -1;
      param_1[0x9b] = -1;
      return 0;
    case 0x203:
      (**(code **)(*param_1 + 0x50))();
      return 0;
    case 0x204:
      SetCapture((HWND)param_1[2]);
      FUN_00425ad0();
      (**(code **)(*param_1 + 0x58))();
      return 0;
    case 0x205:
      ClipCursor((RECT *)0x0);
      (**(code **)(*param_1 + 0x54))();
      ReleaseCapture();
      *(undefined1 *)(param_1 + 0xe1) = 0;
      param_1[0x9a] = -1;
      param_1[0x9b] = -1;
      return 0;
    }
  }
  else {
    if (uVar1 == 0x214) {
      (**(code **)(*param_1 + 0x30))();
      return 1;
    }
    if (uVar1 == 0x216) {
      (**(code **)(*param_1 + 0x2c))();
      return 1;
    }
    if (uVar1 == 0x30f) {
      FUN_0040e640(0x4365f0);
      return 1;
    }
  }
  return 0;
}



/* 00425680  FUN_00425680  14 bytes, 0 callers */

void __fastcall FUN_00425680(int param_1)

{
  SetWindowLongA(*(HWND *)(param_1 + 8),-0x15,param_1);
  return;
}



/* 00425690  FUN_00425690  51 bytes, 0 callers */

void __fastcall FUN_00425690(int *param_1)

{
  if (param_1[0x97] != 0) {
    GdiFlush();
    (**(code **)(*param_1 + 0x18))();
    InvalidateRect((HWND)param_1[2],(RECT *)0x0,0);
    UpdateWindow((HWND)param_1[2]);
  }
  return;
}



/* 004256d0  FUN_004256d0  225 bytes, 0 callers */

void __fastcall FUN_004256d0(int param_1)

{
  HDC hdc;
  HPALETTE hPal;
  HGDIOBJ h;
  tagRECT local_50;
  tagPAINTSTRUCT local_40;
  
  hdc = BeginPaint(*(HWND *)(param_1 + 8),&local_40);
  if (hdc != (HDC)0x0) {
    hPal = SelectPalette(local_40.hdc,DAT_004365f4,0);
    SelectPalette(*(HDC *)(param_1 + 0x254),DAT_004365f4,0);
    RealizePalette(hdc);
    h = SelectObject(hdc,*(HGDIOBJ *)(DAT_004344e4 + 0x3a4));
    GetClientRect(*(HWND *)(param_1 + 8),&local_50);
    StretchBlt(local_40.hdc,0,0,local_50.right,local_50.bottom,*(HDC *)(param_1 + 0x254),
               *(int *)(param_1 + 0x260),*(int *)(param_1 + 0x264),local_50.right,local_50.bottom,
               0xcc0020);
    SelectObject(hdc,h);
    SelectPalette(hdc,hPal,1);
    EndPaint(*(HWND *)(param_1 + 8),&local_40);
  }
  return;
}



/* 004257e0  FUN_004257e0  268 bytes, 0 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004257e0(int *param_1)

{
  int iVar1;
  HDC hdc;
  HDC pHVar2;
  HBITMAP pHVar3;
  
  _DAT_00435fdc = param_1[8];
  _DAT_00435fe0 = -param_1[9];
  _DAT_00435fec = 0;
  if ((HDC)param_1[0x95] != (HDC)0x0) {
    DeleteDC((HDC)param_1[0x95]);
    param_1[0x95] = 0;
  }
  if ((HGDIOBJ)param_1[0x96] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)param_1[0x96]);
    param_1[0x96] = 0;
  }
  hdc = GetDC((HWND)param_1[2]);
  pHVar2 = CreateCompatibleDC(hdc);
  param_1[0x95] = (int)pHVar2;
  pHVar3 = CreateDIBSection((HDC)param_1[0x95],(BITMAPINFO *)&DAT_00435fd8,0,
                            (void **)(param_1 + 0x97),(HANDLE)0x0,0);
  param_1[0x96] = (int)pHVar3;
  ReleaseDC((HWND)param_1[2],hdc);
  if (param_1[0x96] == 0) {
    return 0;
  }
  SetBkMode((HDC)param_1[0x95],1);
  SetTextColor((HDC)param_1[0x95],0xffffff);
  SelectPalette((HDC)param_1[0x95],DAT_004365f4,0);
  SelectObject((HDC)param_1[0x95],(HGDIOBJ)param_1[0x96]);
  iVar1 = *param_1;
  (**(code **)(iVar1 + 0x1c))();
  (**(code **)(iVar1 + 0x18))();
  return 1;
}



/* 00425970  FUN_00425970  145 bytes, 1 callers */

void __fastcall FUN_00425970(int param_1)

{
  BOOL BVar1;
  int Y;
  int X;
  tagPOINT local_8;
  
  if (((*(int *)(param_1 + 0x268) != -1) || (*(int *)(param_1 + 0x26c) != -1)) &&
     (*(int *)(param_1 + 0x10) == 1)) {
    BVar1 = GetCursorPos(&local_8);
    if (BVar1 != 0) {
      X = (*(int *)(param_1 + 0x270) - *(int *)(param_1 + 0x268)) + local_8.x;
      Y = (*(int *)(param_1 + 0x274) - *(int *)(param_1 + 0x26c)) + local_8.y;
      SetWindowPos(*(HWND *)(param_1 + 8),(HWND)0x0,X,Y,0,0,5);
      *(LONG *)(param_1 + 0x268) = local_8.x;
      *(LONG *)(param_1 + 0x26c) = local_8.y;
      *(int *)(param_1 + 0x270) = X;
      *(int *)(param_1 + 0x274) = Y;
      *(undefined1 *)(param_1 + 900) = 1;
    }
  }
  return;
}



/* 00425a30  FUN_00425a30  155 bytes, 1 callers */

void __fastcall FUN_00425a30(int param_1)

{
  tagRECT local_10;
  
  GetWindowRect(*(HWND *)(param_1 + 0x250),&local_10);
  if (*(int *)(DAT_004344e4 + 8) == *(int *)(param_1 + 8)) {
    local_10.left = 0;
    local_10.top = 0;
    local_10.right = GetSystemMetrics(0);
    local_10.bottom = GetSystemMetrics(1);
  }
  ClipCursor(&local_10);
  GetWindowRect(*(HWND *)(param_1 + 8),&local_10);
  ((LPPOINT)(param_1 + 0x270))->x = local_10.left;
  *(LONG *)(param_1 + 0x274) = local_10.top;
  if (*(HWND *)(param_1 + 0x250) != (HWND)0x0) {
    ScreenToClient(*(HWND *)(param_1 + 0x250),(LPPOINT)(param_1 + 0x270));
  }
  GetCursorPos((LPPOINT)(param_1 + 0x268));
  return;
}



/* 00425ad0  FUN_00425ad0  1 bytes, 1 callers */

void FUN_00425ad0(void)

{
  return;
}



/* 00425af0  FUN_00425af0  46 bytes, 1 callers */

void __fastcall FUN_00425af0(int param_1)

{
  if (*(HWND *)(param_1 + 8) != (HWND)0x0) {
    FUN_00425010(DAT_00436460,(LPCSTR)(param_1 + 0x14c),*(HWND *)(param_1 + 8));
    DestroyWindow(*(HWND *)(param_1 + 8));
  }
  FUN_00408e40();
  return;
}



/* 00425bd0  FUN_00425bd0  13 bytes, 18 callers */

undefined4 * __fastcall FUN_00425bd0(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return param_1;
}



/* 00425be0  FUN_00425be0  28 bytes, 8 callers */

void __fastcall FUN_00425be0(int *param_1)

{
  if (param_1[1] != 0) {
    if (*param_1 != 0) {
      FUN_00425c80(param_1);
    }
    FUN_00425c20(param_1);
  }
  return;
}



/* 00425c00  FUN_00425c00  24 bytes, 9 callers */

void __thiscall FUN_00425c00(void *this,SIZE_T param_1)

{
  FUN_00425cb0(this,param_1);
  FUN_00425c50(this);
  return;
}



/* 00425c20  FUN_00425c20  34 bytes, 6 callers */

void __fastcall FUN_00425c20(int *param_1)

{
  HGLOBAL pvVar1;
  
  if (param_1[1] != 0) {
    if (*param_1 != 0) {
      FUN_00425c80(param_1);
    }
    pvVar1 = GlobalFree((HGLOBAL)param_1[1]);
    param_1[1] = (int)pvVar1;
  }
  return;
}



/* 00425c50  FUN_00425c50  44 bytes, 1 callers */

int __fastcall FUN_00425c50(int *param_1)

{
  LPVOID pvVar1;
  
  if ((HGLOBAL)param_1[1] == (HGLOBAL)0x0) {
    return 0;
  }
  if (*param_1 == 0) {
    pvVar1 = GlobalLock((HGLOBAL)param_1[1]);
    param_1[2] = (int)pvVar1;
    if (pvVar1 != (LPVOID)0x0) {
      *param_1 = 1;
    }
  }
  return param_1[2];
}



/* 00425c80  FUN_00425c80  45 bytes, 7 callers */

undefined4 __fastcall FUN_00425c80(int *param_1)

{
  if ((*param_1 != 0) && ((HGLOBAL)param_1[1] != (HGLOBAL)0x0)) {
    GlobalUnlock((HGLOBAL)param_1[1]);
    GetLastError();
    *param_1 = 0;
    return 1;
  }
  return 0;
}



/* 00425cb0  FUN_00425cb0  23 bytes, 1 callers */

void __thiscall FUN_00425cb0(void *this,SIZE_T param_1)

{
  HGLOBAL pvVar1;
  
  pvVar1 = GlobalAlloc(2,param_1);
  *(HGLOBAL *)((int)this + 4) = pvVar1;
  return;
}



/* 00425ce0  FUN_00425ce0  10 bytes, 0 callers */

void FUN_00425ce0(void)

{
  FUN_0041a420((undefined4 *)&DAT_004376c8);
  return;
}



/* 00425cf0  FUN_00425cf0  14 bytes, 0 callers */

void FUN_00425cf0(void)

{
  FUN_00429100(&LAB_00425d00);
  return;
}



/* 00425d20  FUN_00425d20  10 bytes, 0 callers */

void FUN_00425d20(void)

{
  FUN_0040c860(0x435db0);
  return;
}



/* 00425d30  FUN_00425d30  14 bytes, 0 callers */

void FUN_00425d30(void)

{
  FUN_00429100(&LAB_00425d40);
  return;
}



/* 00425d80  FUN_00425d80  10 bytes, 0 callers */

void FUN_00425d80(void)

{
  FUN_00425bd0((undefined4 *)&DAT_00435b10);
  return;
}



/* 00425d90  FUN_00425d90  14 bytes, 0 callers */

void FUN_00425d90(void)

{
  FUN_00429100(&LAB_00425da0);
  return;
}



/* 00425dc0  FUN_00425dc0  10 bytes, 0 callers */

void FUN_00425dc0(void)

{
  FUN_00425bd0((undefined4 *)&DAT_00435b00);
  return;
}



/* 00425dd0  FUN_00425dd0  14 bytes, 0 callers */

void FUN_00425dd0(void)

{
  FUN_00429100(&LAB_00425de0);
  return;
}



/* 00425e00  FUN_00425e00  10 bytes, 0 callers */

void FUN_00425e00(void)

{
  FUN_00425bd0((undefined4 *)&DAT_00435af0);
  return;
}



/* 00425e10  FUN_00425e10  14 bytes, 0 callers */

void FUN_00425e10(void)

{
  FUN_00429100(&LAB_00425e20);
  return;
}



/* 00425e40  FUN_00425e40  10 bytes, 0 callers */

void FUN_00425e40(void)

{
  FUN_00425bd0((undefined4 *)&DAT_00437800);
  return;
}



/* 00425e50  FUN_00425e50  14 bytes, 0 callers */

void FUN_00425e50(void)

{
  FUN_00429100(&LAB_00425e60);
  return;
}



/* 00425e80  FUN_00425e80  10 bytes, 0 callers */

void FUN_00425e80(void)

{
  FUN_00425bd0((undefined4 *)&DAT_00437810);
  return;
}



/* 00425e90  FUN_00425e90  14 bytes, 0 callers */

void FUN_00425e90(void)

{
  FUN_00429100(&LAB_00425ea0);
  return;
}



/* 00425ec0  FUN_00425ec0  10 bytes, 0 callers */

void FUN_00425ec0(void)

{
  FUN_00425bd0((undefined4 *)&DAT_004377f0);
  return;
}



/* 00425ed0  FUN_00425ed0  14 bytes, 0 callers */

void FUN_00425ed0(void)

{
  FUN_00429100(&LAB_00425ee0);
  return;
}



/* 00425f00  FUN_00425f00  10 bytes, 0 callers */

void FUN_00425f00(void)

{
  FUN_00425bd0((undefined4 *)&DAT_00437820);
  return;
}



/* 00425f10  FUN_00425f10  14 bytes, 0 callers */

void FUN_00425f10(void)

{
  FUN_00429100(&LAB_00425f20);
  return;
}



/* 00425f40  FUN_00425f40  10 bytes, 0 callers */

void FUN_00425f40(void)

{
  FUN_00425bd0((undefined4 *)&DAT_004377e0);
  return;
}



/* 00425f50  FUN_00425f50  14 bytes, 0 callers */

void FUN_00425f50(void)

{
  FUN_00429100(&LAB_00425f60);
  return;
}



/* 00425f80  FUN_00425f80  10 bytes, 0 callers */

void FUN_00425f80(void)

{
  FUN_00425bd0((undefined4 *)&DAT_004376b8);
  return;
}



/* 00425f90  FUN_00425f90  14 bytes, 0 callers */

void FUN_00425f90(void)

{
  FUN_00429100(&LAB_00425fa0);
  return;
}



/* 00425fc0  FUN_00425fc0  10 bytes, 0 callers */

void FUN_00425fc0(void)

{
  FUN_00425bd0((undefined4 *)&DAT_00435c98);
  return;
}



/* 00425fd0  FUN_00425fd0  14 bytes, 0 callers */

void FUN_00425fd0(void)

{
  FUN_00429100(&LAB_00425fe0);
  return;
}



/* 00426000  FUN_00426000  10 bytes, 0 callers */

void FUN_00426000(void)

{
  FUN_0040e480(0x4365f0);
  return;
}



/* 00426010  FUN_00426010  14 bytes, 0 callers */

void FUN_00426010(void)

{
  FUN_00429100(&LAB_00426020);
  return;
}



/* 00426030  FUN_00426030  16 bytes, 1 callers */

undefined4 * __thiscall FUN_00426030(void *this,undefined4 param_1)

{
  *(undefined4 *)this = param_1;
  DAT_004344d0 = param_1;
  return this;
}



/* 00426040  FUN_00426040  776 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

WPARAM __fastcall FUN_00426040(undefined4 *param_1)

{
  char cVar1;
  ATOM AVar2;
  int iVar3;
  HWND hWnd;
  int *piVar4;
  undefined4 *puVar5;
  HACCEL hAccTable;
  BOOL BVar6;
  undefined4 *unaff_FS_OFFSET;
  uchar local_158 [256];
  tagMSG local_58;
  WNDCLASSA local_3c;
  undefined4 *local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00426355;
  *unaff_FS_OFFSET = &local_10;
  GetModuleFileNameA(DAT_004344d0,&DAT_00437588,0x102);
  FUN_00429160(&DAT_00437588,(uchar *)0x0,(uchar *)0x0,local_158,(uchar *)0x0);
  iVar3 = lstrlenA(&DAT_00437588);
  cVar1 = (&DAT_00437588)[iVar3];
  while (cVar1 != '\\') {
    (&DAT_00437588)[iVar3] = 0;
    cVar1 = (&DAT_00437587)[iVar3];
    iVar3 = iVar3 + -1;
  }
  (&DAT_00437588)[iVar3] = 0x5c;
  (&DAT_00437589)[iVar3] = 0;
  hWnd = FindWindowA(s_DS795_FRAME_004321f4,(LPCSTR)0x0);
  if (hWnd == (HWND)0x0) {
    local_3c.hInstance = (HINSTANCE)*param_1;
    local_3c.cbClsExtra = 0;
    local_3c.cbWndExtra = 0;
    local_3c.style = 0x30c8;
    local_3c.lpfnWndProc = (WNDPROC)&LAB_00426570;
    local_3c.hIcon = LoadIconA(local_3c.hInstance,(LPCSTR)0x6f);
    local_3c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_3c.hbrBackground = GetStockObject(4);
    local_3c.lpszMenuName = (LPCSTR)0x65;
    local_3c.lpszClassName = s_DS795_FRAME_004321f4;
    AVar2 = RegisterClassA(&local_3c);
    if (AVar2 != 0) {
      local_3c.lpszMenuName = (LPCSTR)0x0;
      local_3c.hbrBackground = (HBRUSH)0x0;
      local_3c.style = 0x30cb;
      local_3c.lpfnWndProc = (WNDPROC)&LAB_004264c0;
      local_3c.lpszClassName = s_DS795_WND_0043255c;
      AVar2 = RegisterClassA(&local_3c);
      if (AVar2 != 0) {
        local_14 = (undefined4 *)FUN_00427f90(0x3a8);
        local_8 = 0;
        piVar4 = (int *)0x0;
        if (local_14 != (undefined4 *)0x0) {
          piVar4 = FUN_004070e0(local_14);
        }
        local_8 = 0xffffffff;
        DAT_004344e4 = piVar4;
        if (piVar4 != (int *)0x0) {
          local_14 = (undefined4 *)FUN_00427f90(0x14c);
          local_8 = 1;
          puVar5 = (undefined4 *)0x0;
          if (local_14 != (void *)0x0) {
            puVar5 = FUN_00424e10(local_14,(LPCSTR)local_158);
          }
          local_8 = 0xffffffff;
          DAT_00436460 = puVar5;
          if (puVar5 != (undefined4 *)0x0) {
            FUN_0040bcf0(&DAT_00436468,(undefined2 *)&DAT_00437588);
            FUN_0040e4a0(&DAT_004365f0,0);
            _DAT_00435fe8 = 0;
            _DAT_00435fec = 0;
            _DAT_00435ff0 = 0;
            _DAT_00435ff4 = 0;
            _DAT_00435fd8 = 0x28;
            _DAT_00435ffc = 0;
            _DAT_00435ff8 = 0x100;
            _DAT_00435fe4 = 1;
            _DAT_00435fe6 = 8;
            iVar3 = (**(code **)(*DAT_004344e4 + 4))(0,70000);
            if (iVar3 != 0) {
              BVar6 = 1;
              hAccTable = LoadAcceleratorsA(DAT_004344d0,(LPCSTR)0x71);
              do {
                iVar3 = PeekMessageA(&local_58,(HWND)0x0,0,0,0);
                while ((iVar3 != 0 && (BVar6 = GetMessageA(&local_58,(HWND)0x0,0,0), BVar6 != 0))) {
                  iVar3 = TranslateAcceleratorA(local_58.hwnd,hAccTable,&local_58);
                  if (iVar3 == 0) {
                    TranslateMessage(&local_58);
                    DispatchMessageA(&local_58);
                  }
                  iVar3 = PeekMessageA(&local_58,(HWND)0x0,0,0,0);
                }
                if (DAT_004344e0 == 0) {
                  DAT_004344e0 = 0x1e - DAT_00437698;
                  FUN_0040a5e0();
                  FUN_004263a0();
                }
              } while (BVar6 != 0);
              goto LAB_004260ee;
            }
            (**(code **)(*DAT_004344e4 + 0x3c))();
            DAT_004344e4 = (int *)0x0;
          }
        }
      }
    }
  }
  else {
    BringWindowToTop(hWnd);
    SetForegroundWindow(hWnd);
  }
  local_58.wParam = 0;
LAB_004260ee:
  *unaff_FS_OFFSET = local_10;
  return local_58.wParam;
}



/* 00426370  FUN_00426370  41 bytes, 1 callers */

undefined4 FUN_00426370(undefined4 param_1,int param_2)

{
  undefined4 local_4;
  
  if (param_2 == 0) {
    FUN_00426030(&local_4,param_1);
    FUN_00426040(&local_4);
  }
  return 0;
}



/* 004263a0  FUN_004263a0  93 bytes, 1 callers */

void FUN_004263a0(void)

{
  int *piVar1;
  
  if (DAT_004344f0 != (int *)0x0) {
    (**(code **)(*DAT_004344f0 + 100))();
  }
  if (DAT_004344f4 != (int *)0x0) {
    (**(code **)(*DAT_004344f4 + 100))();
  }
  if (DAT_004344ec != (int *)0x0) {
    (**(code **)(*DAT_004344ec + 100))();
  }
  piVar1 = &DAT_004344f8;
  do {
    if ((int *)*piVar1 != (int *)0x0) {
      (**(code **)(*(int *)*piVar1 + 100))();
    }
    piVar1 = piVar1 + 1;
  } while (piVar1 < &DAT_00434508);
  return;
}



/* 00426400  FUN_00426400  58 bytes, 0 callers */

void FUN_00426400(void)

{
  DAT_004344dc = 1;
  FUN_00409370(s_A_problem_has_occurred__Aborting_00434554,0);
  if (DAT_004344e4 != (int *)0x0) {
    (**(code **)(*DAT_004344e4 + 0x3c))();
    DAT_004344e4 = (int *)0x0;
  }
  return;
}



/* 00426630  FUN_00426630  240 bytes, 1 callers */

undefined4 * __fastcall FUN_00426630(undefined4 *param_1)

{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00426720;
  *unaff_FS_OFFSET = &local_10;
  FUN_00427770(param_1);
  local_8 = 0;
  *param_1 = &PTR_FUN_004308a0;
  wsprintfA((LPSTR)(param_1 + 0x53),s_Code0_00432468);
  wsprintfA((LPSTR)(param_1 + 0x12),s_Unit_Window_00434580);
  param_1[0x9e] = 0x54400000;
  param_1[8] = 0xb0;
  param_1[9] = 0xb0;
  iVar1 = GetSystemMetrics(8);
  param_1[7] = param_1[7] + iVar1 * 2;
  iVar1 = GetSystemMetrics(7);
  param_1[6] = param_1[6] + iVar1 * 2;
  wsprintfA((LPSTR)(param_1 + 0x12),s_Unit_Window_00434580);
  iVar1 = param_1[8] + param_1[6];
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = iVar1;
  param_1[0x11] = param_1[9] + param_1[7];
  param_1[10] = param_1[6] + 0xb0;
  param_1[0xb] = 0;
  param_1[0xc] = iVar1;
  param_1[0xd] = param_1[9] + param_1[7];
  *(undefined1 *)(param_1 + 0xe9) = 0;
  *(undefined1 *)((int)param_1 + 0x3a5) = 0;
  DAT_004344f0 = param_1;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}



/* 00426740  FUN_00426740  30 bytes, 0 callers */

undefined4 * __thiscall FUN_00426740(void *this,byte param_1)

{
  FUN_00426760(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 00426760  FUN_00426760  71 bytes, 1 callers */

void __fastcall FUN_00426760(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_004267a7;
  *param_1 = &PTR_FUN_004308a0;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  DAT_004344f0 = 0;
  FUN_004267b1();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 004267b1  FUN_004267b1  8 bytes, 1 callers */

void FUN_004267b1(void)

{
  int unaff_EBP;
  
  FUN_00427820(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 004267e0  FUN_004267e0  228 bytes, 0 callers */

void __fastcall FUN_004267e0(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  
  *(undefined4 *)(param_1 + 0x39c) = 0;
  *(undefined4 *)(param_1 + 0x3a0) = 0;
  *(undefined4 *)(param_1 + 0x394) = 0x40;
  iVar7 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    do {
      uVar3 = *(uint *)(param_1 + 0x20);
      iVar5 = iVar7 + 1;
      puVar6 = (undefined4 *)(iVar7 * 0x100 + 0x7000 + DAT_00435fd4);
      puVar8 = (undefined4 *)(iVar7 * uVar3 + *(int *)(param_1 + 0x25c));
      for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
      iVar7 = iVar5;
    } while (iVar5 < *(int *)(param_1 + 0x24));
  }
  iVar7 = 0;
  SelectObject(*(HDC *)(param_1 + 0x254),*(HGDIOBJ *)(DAT_004344e4 + 0x3a4));
  do {
    iVar5 = iVar7;
    iVar10 = 0;
    do {
      iVar1 = DAT_00435fd4 + iVar5;
      iVar4 = iVar10 + 1;
      iVar9 = (iVar10 + 0x10) * *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x25c) + iVar7;
      *(undefined4 *)(iVar9 + 0x48) = *(undefined4 *)(iVar1 + 0x3000);
      *(undefined4 *)(iVar9 + 0x4c) = *(undefined4 *)(iVar1 + 0x3004);
      iVar1 = DAT_00435fd4 + iVar5;
      iVar5 = iVar5 + 0x100;
      iVar10 = (iVar10 + 0x60) * *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x25c) + iVar7;
      *(undefined4 *)(iVar10 + 0x48) = *(undefined4 *)(iVar1 + 0x3000);
      *(undefined4 *)(iVar10 + 0x4c) = *(undefined4 *)(iVar1 + 0x3004);
      iVar10 = iVar4;
    } while (iVar4 < 0x10);
    iVar7 = iVar7 + 8;
  } while (iVar7 < 0x50);
  return;
}



/* 004268d0  FUN_004268d0  40 bytes, 0 callers */

void __fastcall FUN_004268d0(int param_1)

{
  tagPOINT local_8;
  
  if (*(char *)(param_1 + 900) == '\0') {
    GetCursorPos(&local_8);
    FUN_0040a980(&local_8.x);
  }
  return;
}



/* 00426900  FUN_00426900  2213 bytes, 0 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00426900(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  LPCSTR pCVar11;
  uint local_14;
  uint local_8;
  int local_4;
  
  if (DAT_004344e8 != (void *)0x0) {
    FUN_004249f0(DAT_004344e8,&local_8);
    iVar4 = *(int *)(param_1 + 0x20);
    iVar2 = (local_8 * 0x30 + local_4) * 0x18;
    uVar5 = (uint)*(byte *)(DAT_0043453c + 0x10 + iVar2);
    iVar8 = uVar5 << 10;
    iVar3 = 0;
    do {
      puVar9 = (undefined4 *)(DAT_00436454 + iVar8);
      iVar8 = iVar8 + 0x20;
      puVar10 = (undefined4 *)
                (*(int *)(param_1 + 0x20) * iVar3 + *(int *)(param_1 + 0x25c) + iVar4 * 0x70 + 0x10)
      ;
      for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x20);
    iVar4 = *(int *)(param_1 + 0x20);
    iVar3 = 0;
    do {
      iVar8 = *(int *)(param_1 + 0x20) * iVar3;
      iVar3 = iVar3 + 1;
      puVar9 = (undefined4 *)(iVar8 + *(int *)(param_1 + 0x25c) + iVar4 * 0x78 + 0x40);
      for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar9 = 0x70707070;
        puVar9 = puVar9 + 1;
      }
    } while (iVar3 < 0x10);
    iVar4 = uVar5 - 8;
    if ((iVar4 < 0) || (3 < iVar4)) {
      iVar4 = *(int *)(DAT_0043453c + 0xc + iVar2);
      local_14 = (uint)(iVar4 * 0x1e) / 0xff;
      wsprintfA((LPSTR)(param_1 + 0x3a6),s_DEF__6d_004345ac,iVar4);
      iVar4 = *(int *)(param_1 + 0x20);
      iVar3 = 0;
      do {
        iVar8 = *(int *)(param_1 + 0x20) * iVar3;
        iVar3 = iVar3 + 1;
        puVar9 = (undefined4 *)(iVar8 + *(int *)(param_1 + 0x25c) + iVar4 * 0x90 + 0x40);
        for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar9 = 0x70707070;
          puVar9 = puVar9 + 1;
        }
      } while (iVar3 < 0x10);
    }
    else {
      iVar4 = *(int *)(DAT_0043453c + 0xc + iVar2);
      local_14 = (uint)(iVar4 * 0x1e) / 0x90;
      wsprintfA((LPSTR)(param_1 + 0x3a6),s_NUM__6d_004345b8,iVar4);
      iVar4 = *(int *)(param_1 + 0x20);
      iVar3 = 0;
      do {
        iVar8 = *(int *)(param_1 + 0x20) * iVar3;
        iVar3 = iVar3 + 1;
        puVar9 = (undefined4 *)(iVar8 + *(int *)(param_1 + 0x25c) + iVar4 * 0x90 + 0x40);
        for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar9 = 0x70707070;
          puVar9 = puVar9 + 1;
        }
      } while (iVar3 < 0x10);
      iVar4 = lstrlenA(&DAT_00435b86 + (_DAT_004365e0 & 0xf) * 0x11);
      iVar3 = 0xc;
      if (iVar4 < 0xd) {
        iVar3 = lstrlenA(&DAT_00435b86 + (_DAT_004365e0 & 0xf) * 0x11);
      }
      TextOutA(*(HDC *)(param_1 + 0x254),0x40,0x90,&DAT_00435b86 + (_DAT_004365e0 & 0xf) * 0x11,
               iVar3);
    }
    iVar4 = lstrlenA((LPCSTR)(param_1 + 0x3a6));
    iVar3 = 0xc;
    if (iVar4 < 0xd) {
      iVar3 = lstrlenA((LPCSTR)(param_1 + 0x3a6));
    }
    TextOutA(*(HDC *)(param_1 + 0x254),0x40,0x78,(LPCSTR)(param_1 + 0x3a6),iVar3);
    if (0x1e < local_14) {
      local_14 = 0x1e;
    }
    uVar5 = *(uint *)(param_1 + 0x3a0);
    while (uVar5 != local_14) {
      iVar3 = *(int *)(param_1 + 0x3a0);
      iVar8 = iVar3 % 10;
      iVar4 = (iVar8 + *(int *)(param_1 + 0x20) * 0xc) * 8 + 0x48;
      if (iVar3 < (int)local_14) {
        iVar6 = 0;
        do {
          puVar10 = (undefined4 *)
                    (*(int *)(param_1 + 0x20) * iVar6 + *(int *)(param_1 + 0x25c) + iVar4);
          puVar9 = (undefined4 *)
                   (iVar6 * 0x100 + ((iVar3 / 10 + 4) * 0x200 + iVar8) * 8 + DAT_00435fd4);
          iVar6 = iVar6 + 1;
          *puVar10 = *puVar9;
          puVar10[1] = puVar9[1];
        } while (iVar6 < 0x10);
        *(int *)(param_1 + 0x3a0) = *(int *)(param_1 + 0x3a0) + 1;
      }
      else {
        iVar6 = 0;
        do {
          puVar10 = (undefined4 *)
                    (*(int *)(param_1 + 0x20) * iVar6 + *(int *)(param_1 + 0x25c) + iVar4);
          puVar9 = (undefined4 *)
                   (iVar6 * 0x100 + ((iVar3 / 10 + 3) * 0x200 + iVar8) * 8 + DAT_00435fd4);
          iVar6 = iVar6 + 1;
          *puVar10 = *puVar9;
          puVar10[1] = puVar9[1];
        } while (iVar6 < 0x10);
        *(int *)(param_1 + 0x3a0) = *(int *)(param_1 + 0x3a0) + -1;
      }
      uVar5 = *(uint *)(param_1 + 0x3a0);
    }
    if (*(byte *)(DAT_0043453c + iVar2) < 0x40) {
      *(uint *)(param_1 + 0x394) = (uint)*(byte *)(DAT_0043453c + iVar2);
    }
    if (*(char *)(DAT_00434538 + 0x10 + *(int *)(param_1 + 0x394) * 0x224) == -0x80) {
      *(undefined4 *)(param_1 + 0x394) = 0x40;
    }
    if (*(uint *)(param_1 + 0x394) < 0x40) {
      uVar5 = FUN_0041b520(*(uint *)(param_1 + 0x394));
      iVar4 = *(int *)(param_1 + 0x20);
      iVar8 = 0;
      iVar3 = 0;
      do {
        iVar3 = iVar3 + 0x20;
        puVar9 = (undefined4 *)(DAT_00436440 + uVar5 * 0x400 + -0x20 + iVar3);
        puVar10 = (undefined4 *)
                  (*(int *)(param_1 + 0x20) * iVar8 + *(int *)(param_1 + 0x25c) +
                  iVar4 * 0x30 + 0x10);
        for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        }
        iVar8 = iVar8 + 1;
      } while (iVar3 < 0x400);
      bVar1 = *(byte *)(DAT_00434538 + 0x220 + *(int *)(param_1 + 0x394) * 0x224);
      if (bVar1 == 0xff) {
        iVar4 = *(int *)(param_1 + 0x20);
        iVar3 = 0;
        do {
          puVar9 = (undefined4 *)
                   (*(int *)(param_1 + 0x20) * iVar3 + *(int *)(param_1 + 0x25c) +
                   (iVar4 + 1) * 0x10);
          for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar9 = 0x70707070;
            puVar9 = puVar9 + 1;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 0x20);
      }
      else {
        iVar8 = 0;
        iVar4 = *(int *)(param_1 + 0x20);
        iVar3 = (uint)bVar1 * 0x2000 + 0xe0;
        do {
          iVar6 = *(int *)(param_1 + 0x20) * iVar8;
          puVar9 = (undefined4 *)(DAT_00435fd4 + iVar3);
          iVar3 = iVar3 + 0x100;
          iVar8 = iVar8 + 1;
          puVar10 = (undefined4 *)(iVar6 + *(int *)(param_1 + 0x25c) + (iVar4 + 1) * 0x10);
          for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
        } while (iVar8 < 0x20);
      }
      iVar4 = *(int *)(param_1 + 0x20);
      iVar3 = 0;
      do {
        puVar9 = (undefined4 *)
                 (*(int *)(param_1 + 0x20) * iVar3 + *(int *)(param_1 + 0x25c) + (iVar4 + 1) * 0x40)
        ;
        for (iVar8 = 0x18; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar9 = 0x70707070;
          puVar9 = puVar9 + 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x10);
      bVar1 = *(byte *)(DAT_00434538 + 0xd + *(int *)(param_1 + 0x394) * 0x224);
      if ((bVar1 & 0x20) == 0) {
        bVar1 = bVar1 & 0xf;
        if (bVar1 == 0xe) {
          pCVar11 = &DAT_00435c85;
        }
        else {
          pCVar11 = &DAT_00435b86 + (uint)bVar1 * 0x11;
        }
      }
      else {
        pCVar11 = &DAT_00435c63;
      }
      wsprintfA((LPSTR)(param_1 + 0x3a6),pCVar11);
      iVar4 = lstrlenA((LPCSTR)(param_1 + 0x3a6));
      iVar3 = 0xc;
      if (iVar4 < 0xd) {
        iVar3 = lstrlenA((LPCSTR)(param_1 + 0x3a6));
      }
      iVar8 = 0;
      TextOutA(*(HDC *)(param_1 + 0x254),0x40,0x40,(LPCSTR)(param_1 + 0x3a6),iVar3);
      iVar4 = *(int *)(param_1 + 0x20);
      do {
        puVar9 = (undefined4 *)
                 (*(int *)(param_1 + 0x20) * iVar8 + *(int *)(param_1 + 0x25c) + iVar4 * 0x28 + 0x40
                 );
        for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar9 = 0x70707070;
          puVar9 = puVar9 + 1;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < 0x10);
      wsprintfA((LPSTR)(param_1 + 0x3a6),s_STR__6d_004345a0,
                *(undefined4 *)(DAT_00434538 + 8 + *(int *)(param_1 + 0x394) * 0x224));
      iVar4 = lstrlenA((LPCSTR)(param_1 + 0x3a6));
      iVar3 = 0xc;
      if (iVar4 < 0xd) {
        iVar3 = lstrlenA((LPCSTR)(param_1 + 0x3a6));
      }
      TextOutA(*(HDC *)(param_1 + 0x254),0x40,0x28,(LPCSTR)(param_1 + 0x3a6),iVar3);
      uVar5 = *(uint *)(DAT_00434538 + 8 + *(int *)(param_1 + 0x394) * 0x224);
      if (uVar5 < 1000) {
        local_14 = (uVar5 * 10) / 1000;
      }
      else if (uVar5 < 10000) {
        local_14 = (uVar5 * 10) / 10000 + 10;
      }
      else {
        local_14 = (uVar5 * 10) / 100000 + 0x14;
      }
      if (0x1e < local_14) {
        local_14 = 0x1e;
      }
      uVar5 = *(uint *)(param_1 + 0x39c);
      while (uVar5 != local_14) {
        iVar3 = *(int *)(param_1 + 0x39c);
        iVar8 = iVar3 % 10;
        iVar4 = (iVar8 + *(int *)(param_1 + 0x20) * 2) * 8 + 0x48;
        if (iVar3 < (int)local_14) {
          iVar6 = 0;
          do {
            puVar10 = (undefined4 *)
                      (*(int *)(param_1 + 0x20) * iVar6 + *(int *)(param_1 + 0x25c) + iVar4);
            puVar9 = (undefined4 *)
                     (iVar6 * 0x100 + ((iVar3 / 10 + 4) * 0x200 + iVar8) * 8 + DAT_00435fd4);
            iVar6 = iVar6 + 1;
            *puVar10 = *puVar9;
            puVar10[1] = puVar9[1];
          } while (iVar6 < 0x10);
          *(int *)(param_1 + 0x39c) = *(int *)(param_1 + 0x39c) + 1;
        }
        else {
          iVar6 = 0;
          do {
            puVar10 = (undefined4 *)
                      (*(int *)(param_1 + 0x20) * iVar6 + *(int *)(param_1 + 0x25c) + iVar4);
            puVar9 = (undefined4 *)
                     (iVar6 * 0x100 + ((iVar3 / 10 + 3) * 0x200 + iVar8) * 8 + DAT_00435fd4);
            iVar6 = iVar6 + 1;
            *puVar10 = *puVar9;
            puVar10[1] = puVar9[1];
          } while (iVar6 < 0x10);
          *(int *)(param_1 + 0x39c) = *(int *)(param_1 + 0x39c) + -1;
        }
        uVar5 = *(uint *)(param_1 + 0x39c);
      }
    }
    else {
      iVar4 = *(int *)(param_1 + 0x20);
      iVar3 = 0;
      do {
        puVar9 = (undefined4 *)
                 (*(int *)(param_1 + 0x20) * iVar3 + *(int *)(param_1 + 0x25c) + (iVar4 + 1) * 0x10)
        ;
        for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar9 = 0x70707070;
          puVar9 = puVar9 + 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x40);
      iVar3 = 0;
      iVar4 = (*(int *)(param_1 + 0x20) + 1) * 0x40;
      do {
        puVar9 = (undefined4 *)
                 (*(int *)(param_1 + 0x20) * iVar3 + *(int *)(param_1 + 0x25c) + iVar4);
        for (iVar8 = 0x18; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar9 = 0x70707070;
          puVar9 = puVar9 + 1;
        }
        puVar9 = (undefined4 *)
                 ((iVar3 + -0x18) * *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x25c) + iVar4);
        for (iVar8 = 0x18; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar9 = 0x70707070;
          puVar9 = puVar9 + 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x10);
      iVar4 = *(int *)(param_1 + 0x39c);
      iVar3 = *(int *)(param_1 + 0x20);
      if (iVar4 != 0) {
        iVar8 = 0;
        do {
          puVar10 = (undefined4 *)
                    (*(int *)(param_1 + 0x20) * iVar8 + *(int *)(param_1 + 0x25c) +
                    (iVar4 % 10 + iVar3 * 2) * 8 + 0x48);
          puVar9 = (undefined4 *)
                   (iVar8 * 0x100 + ((iVar4 / 10 + 3) * 0x200 + iVar4 % 10) * 8 + DAT_00435fd4);
          iVar8 = iVar8 + 1;
          *puVar10 = *puVar9;
          puVar10[1] = puVar9[1];
        } while (iVar8 < 0x10);
        *(int *)(param_1 + 0x39c) = *(int *)(param_1 + 0x39c) + -1;
      }
    }
    if (DAT_004365dc != 0) {
      iVar4 = *(int *)(param_1 + 0x20);
      iVar3 = 0;
      do {
        puVar9 = (undefined4 *)
                 (*(int *)(param_1 + 0x20) * iVar3 + *(int *)(param_1 + 0x25c) + (iVar4 + 1) * 0x40)
        ;
        for (iVar8 = 0x18; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar9 = 0x70707070;
          puVar9 = puVar9 + 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x10);
      iVar4 = *(int *)(DAT_0043453c + 8 + iVar2);
      if (iVar4 == 0x1f0) {
        wsprintfA((LPSTR)(param_1 + 0x3a6),s_DIS________00434594);
      }
      else {
        wsprintfA((LPSTR)(param_1 + 0x3a6),s_DIS___d_0043458c,iVar4);
      }
      iVar4 = lstrlenA((LPCSTR)(param_1 + 0x3a6));
      iVar2 = 0xc;
      if (iVar4 < 0xd) {
        iVar2 = lstrlenA((LPCSTR)(param_1 + 0x3a6));
      }
      TextOutA(*(HDC *)(param_1 + 0x254),0x40,0x40,(LPCSTR)(param_1 + 0x3a6),iVar2);
    }
  }
  return;
}



/* 004271b0  FUN_004271b0  39 bytes, 2 callers */

void __thiscall FUN_004271b0(void *this,byte *param_1)

{
  if ((*param_1 < 0x30) && (param_1[1] < 0x30)) {
    *(byte *)((int)this + 0x3a4) = *param_1;
    *(byte *)((int)this + 0x3a5) = param_1[1];
  }
  return;
}



/* 004271e0  FUN_004271e0  37 bytes, 1 callers */

void FUN_004271e0(void)

{
  DAT_004365d0 = 0;
  DAT_004365d4 = 0;
  DAT_0043451c = 0;
  FUN_00405330();
  FUN_004273f0();
  FUN_00427210();
  FUN_0041b370();
  return;
}



/* 00427210  FUN_00427210  155 bytes, 4 callers */

void FUN_00427210(void)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  byte *pbVar4;
  
  iVar3 = 0;
  do {
    iVar3 = iVar3 + 0x18;
    *(undefined1 *)(DAT_0043453c + -0x18 + iVar3) = 0x40;
    *(undefined4 *)(DAT_0043453c + -4 + iVar3) = 0;
  } while (iVar3 < 0xd800);
  iVar3 = 0;
  cVar2 = '\0';
  do {
    puVar1 = (uint *)(DAT_00434538 + 0x21c + iVar3);
    *puVar1 = *puVar1 & 0xfffffffe;
    *(undefined1 *)(DAT_00434538 + 0x220 + iVar3) = 0xff;
    pbVar4 = (byte *)(DAT_00434538 + iVar3);
    if ((pbVar4[0x10] & 0x80) == 0) {
      *(char *)(DAT_0043453c + ((uint)*pbVar4 * 0x30 + (uint)pbVar4[1]) * 0x18) = cVar2;
    }
    iVar3 = iVar3 + 0x224;
    cVar2 = cVar2 + '\x01';
  } while (iVar3 < 0x8900);
  FUN_0041b640();
  DAT_004365dc = 0;
  return;
}



/* 004272b0  FUN_004272b0  248 bytes, 2 callers */

void FUN_004272b0(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = DAT_00434534;
  for (iVar2 = 0x46; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = DAT_00434538;
  for (iVar2 = 0x2240; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 0x224;
    *(undefined1 *)((int)DAT_00434538 + iVar2 + 0x10) = 0x80;
    puVar1 = (uint *)((int)DAT_00434538 + iVar2 + 0x21c);
    *puVar1 = *puVar1 & 0xfffffffe;
    *(undefined1 *)((int)DAT_00434538 + iVar2 + 0x220) = 0xff;
    *(undefined4 *)((int)DAT_00434538 + iVar2 + 0x18) = 0x1f0;
    iVar2 = iVar3;
  } while (iVar3 < 0x8900);
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 0x38;
    *(undefined4 *)((int)DAT_00434534 + iVar2 + 0x18) = 5000;
    *(undefined1 *)((int)DAT_00434534 + iVar2 + 0x1c) = 0;
    *(undefined1 *)((int)DAT_00434534 + iVar2 + 0x1e) = 0x80;
    *(undefined4 *)((int)DAT_00434534 + iVar2 + 0x14) = 0;
    puVar1 = (uint *)((int)DAT_00434534 + iVar2 + 4);
    *puVar1 = *puVar1 & 0xfffffff7;
    puVar1 = (uint *)((int)DAT_00434534 + iVar2 + 4);
    *puVar1 = *puVar1 & 0xfffffffe;
    puVar1 = (uint *)((int)DAT_00434534 + iVar2 + 4);
    *puVar1 = *puVar1 & 0xffffffef;
    puVar1 = (uint *)((int)DAT_00434534 + iVar2 + 4);
    *puVar1 = *puVar1 & 0xffffffbf;
    puVar1 = (uint *)((int)DAT_00434534 + iVar2 + 4);
    *puVar1 = *puVar1 & 0xfffffffd;
    puVar1 = (uint *)((int)DAT_00434534 + iVar2 + 4);
    *puVar1 = *puVar1 & 0xfffffffb;
    puVar1 = (uint *)((int)DAT_00434534 + iVar2 + 4);
    *puVar1 = *puVar1 & 0xffffffdf;
    iVar2 = iVar3;
  } while (iVar3 < 0x118);
  return;
}



/* 004273b0  FUN_004273b0  54 bytes, 1 callers */

void FUN_004273b0(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 0x18;
    *(undefined1 *)(DAT_0043453c + -8 + iVar1) = 0x30;
    *(undefined4 *)(DAT_0043453c + -0xc + iVar1) = 100;
  } while (iVar1 < 0xd800);
  DAT_004365a0 = 0xffffffff;
  return;
}



/* 004273f0  FUN_004273f0  885 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004273f0(void)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint local_10 [2];
  undefined1 local_8;
  char local_4;
  
  iVar8 = 0;
  FUN_004272b0();
  local_10[0] = 0x38;
  iVar7 = 0;
  do {
    pbVar1 = (byte *)(DAT_0043453c + 0x10 + iVar8);
    bVar2 = *pbVar1;
    uVar6 = (uint)bVar2;
    if (uVar6 == 6) {
      *pbVar1 = 0;
      *(undefined4 *)(DAT_0043453c + 0xc + iVar8) = 100;
      if ((local_10[0] != 0) && (iVar4 = FUN_0041cdc0(), iVar4 < 0x40)) {
        local_10[0] = local_10[0] - 1;
        iVar3 = iVar4 * 0x224;
        *(char *)(DAT_00434538 + iVar3) = (char)(iVar7 / 0x30);
        *(char *)(DAT_00434538 + 1 + iVar3) = (char)(iVar7 % 0x30);
        ((undefined2 *)(DAT_00434538 + iVar3))[1] = *(undefined2 *)(DAT_00434538 + iVar3);
        *(undefined1 *)(DAT_00434538 + 0xc + iVar3) = 6;
        *(undefined1 *)(DAT_00434538 + 0xd + iVar3) = 0xe;
        *(undefined1 *)(DAT_00434538 + 4 + iVar3) = 4;
        *(undefined4 *)(DAT_00434538 + 8 + iVar3) = 200;
        *(undefined1 *)(DAT_00434538 + 0xf + iVar3) = 0x81;
        *(char *)(DAT_0043453c + iVar8) = (char)iVar4;
        *(undefined1 *)(DAT_00434538 + 0x10 + iVar3) = 0;
      }
    }
    else if ((0x13 < bVar2) && (bVar2 < 0x18)) {
      iVar4 = ((uVar6 * 8 + -0xa0) - (uVar6 - 0x14)) * 8;
      local_8 = (undefined1)(iVar7 / 0x30);
      *(undefined1 *)(DAT_00434534 + 8 + iVar4) = local_8;
      local_4 = (char)(iVar7 % 0x30);
      *(char *)(DAT_00434534 + 9 + iVar4) = local_4;
      uVar5 = (undefined1)(uVar6 - 0x14);
      *(undefined1 *)(DAT_00434534 + iVar4) = uVar5;
      iVar3 = FUN_0041cdc0();
      *(int *)(DAT_00434534 + 0xc + iVar4) = iVar3;
      iVar3 = iVar3 * 0x224;
      *(undefined1 *)(DAT_00434538 + iVar3) = local_8;
      *(char *)(DAT_00434538 + 1 + iVar3) = local_4;
      ((undefined2 *)(DAT_00434538 + iVar3))[1] = *(undefined2 *)(DAT_00434538 + iVar3);
      *(undefined1 *)(DAT_00434538 + 0xc + iVar3) = 6;
      *(undefined1 *)(DAT_00434538 + 0xd + iVar3) = 0x2d;
      *(undefined1 *)(DAT_00434538 + 4 + iVar3) = uVar5;
      *(undefined4 *)(DAT_00434538 + 8 + iVar3) = 1000;
      *(undefined1 *)(DAT_00434538 + 0x10 + iVar3) = 0;
      iVar4 = FUN_0041cdc0();
      iVar4 = iVar4 * 0x224;
      *(undefined1 *)(DAT_00434538 + iVar4) = local_8;
      *(char *)(DAT_00434538 + 1 + iVar4) = local_4 + '\x01';
      ((undefined2 *)(DAT_00434538 + iVar4))[1] = *(undefined2 *)(DAT_00434538 + iVar4);
      *(undefined1 *)(DAT_00434538 + 0xc + iVar4) = 6;
      *(undefined1 *)(DAT_00434538 + 0xd + iVar4) = 1;
      *(undefined1 *)(DAT_00434538 + 4 + iVar4) = uVar5;
      *(undefined4 *)(DAT_00434538 + 8 + iVar4) = 200;
      *(undefined1 *)(DAT_00434538 + 0x10 + iVar4) = 0;
    }
    iVar8 = iVar8 + 0x18;
    iVar7 = iVar7 + 1;
  } while (iVar8 < 0xd800);
  iVar7 = 0;
  *(undefined1 *)(DAT_00434534 + 0xe0) = 4;
  *(undefined4 *)(DAT_00434534 + 0xf8) = 5000;
  *(undefined1 *)(DAT_00434534 + 0xfe) = 0x80;
  *(undefined4 *)(DAT_00434534 + 0xf4) = 0;
  *(uint *)(DAT_00434534 + 0xe4) = *(uint *)(DAT_00434534 + 0xe4) & 0xfffffffe;
  *(uint *)(DAT_00434534 + 0xe4) = *(uint *)(DAT_00434534 + 0xe4) & 0xfffffffd;
  iVar8 = 0;
  *(uint *)(DAT_00434534 + 0xe4) = *(uint *)(DAT_00434534 + 0xe4) & 0xfffffffb;
  *(uint *)(DAT_00434534 + 0xe4) = *(uint *)(DAT_00434534 + 0xe4) & 0xffffffdf;
  *(undefined4 *)(DAT_00434534 + 0xec) = 0;
  do {
    bVar2 = *(byte *)(DAT_0043453c + 0x10 + iVar8);
    if ((7 < bVar2) && (bVar2 < 0xc)) {
      DAT_00437580 = bVar2 - 8;
      FUN_0041ee10(iVar7 / 0x30,iVar7 % 0x30,(char *)local_10);
      *(uint *)(DAT_0043453c + 0xc + iVar8) = ((local_10[0] & 0xff) + 1) * 0x10;
    }
    iVar8 = iVar8 + 0x18;
    iVar7 = iVar7 + 1;
  } while (iVar8 < 0xd800);
  DAT_004365c4 = 3000;
  DAT_004365c8 = 0;
  if ((DAT_0043450c <= DAT_00436a00) && (DAT_0043450c != 0)) {
    DAT_004365c4 = *(int *)(&DAT_004369d4 + DAT_0043450c * 0x38) + 3000;
  }
  DAT_004365bc = DAT_004365c4;
  _DAT_004365e0 = 1;
  DAT_004365e4 = 0;
  return;
}



/* 00427770  FUN_00427770  116 bytes, 7 callers */

undefined4 * __fastcall FUN_00427770(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_004277e4;
  *unaff_FS_OFFSET = &local_10;
  FUN_004250d0(param_1);
  local_8 = 0;
  *param_1 = &PTR_FUN_00430910;
  wsprintfA((LPSTR)(param_1 + 0xa0),s_DS795_WND_0043255c);
  param_1[0x9f] = 0x80;
  param_1[0x9e] = 0x54c80000;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}



/* 00427800  FUN_00427800  30 bytes, 0 callers */

undefined4 * __thiscall FUN_00427800(void *this,byte param_1)

{
  FUN_00427820(this);
  if ((param_1 & 1) != 0) {
    FUN_00427f80(this);
  }
  return this;
}



/* 00427820  FUN_00427820  61 bytes, 8 callers */

void __fastcall FUN_00427820(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_0042785d;
  *param_1 = &PTR_FUN_00430910;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_00427867();
  *unaff_FS_OFFSET = local_10;
  return;
}



/* 00427867  FUN_00427867  8 bytes, 1 callers */

void FUN_00427867(void)

{
  int unaff_EBP;
  
  FUN_00425180(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}



/* 00427970  FUN_00427970  44 bytes, 0 callers */

undefined4 * __thiscall FUN_00427970(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  
  InitCommonControls();
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = param_1;
  uVar1 = FUN_00427f90(0x400);
  *(undefined4 *)((int)this + 8) = uVar1;
  return this;
}



/* 004279a0  FUN_004279a0  30 bytes, 2 callers */

void __fastcall FUN_004279a0(undefined4 *param_1)

{
  FUN_00427f80((LPVOID)param_1[2]);
  if ((HWND)*param_1 != (HWND)0x0) {
    DestroyWindow((HWND)*param_1);
  }
  return;
}



/* 004279c0  FUN_004279c0  70 bytes, 0 callers */

bool __fastcall FUN_004279c0(undefined4 *param_1)

{
  HWND pHVar1;
  
  pHVar1 = CreateWindowExA(0x80,s_tooltips_class32_004345c4,(LPCSTR)0x0,0x80000001,-0x80000000,
                           -0x80000000,-0x80000000,-0x80000000,(HWND)param_1[1],(HMENU)0x0,
                           DAT_004344d0,(LPVOID)0x0);
  *param_1 = pHVar1;
  return (bool)('\x01' - (pHVar1 == (HWND)0x0));
}



/* 00427a10  FUN_00427a10  118 bytes, 1 callers */

void __thiscall
FUN_00427a10(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_28 [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_4;
  
  puVar2 = local_28;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_28[2] = *(undefined4 *)((int)this + 4);
  local_28[3] = param_1;
  local_4 = param_2;
  local_28[0] = 0x28;
  local_28[1] = 0;
  local_18 = param_3;
  local_14 = param_4;
  local_10 = param_5;
  local_c = param_6;
  SendMessageA(*(HWND *)this,0x404,0,(LPARAM)local_28);
  return;
}



/* 00427a90  FUN_00427a90  137 bytes, 1 callers */

void __thiscall
FUN_00427a90(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_28 [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar2 = local_28;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_28[2] = *(undefined4 *)((int)this + 4);
  local_28[3] = param_1;
  local_8 = DAT_004344d0;
  local_4 = param_2;
  local_28[0] = 0x28;
  local_18 = param_3;
  local_14 = param_4;
  local_10 = param_5;
  local_c = param_6;
  SendMessageA(*(HWND *)this,0x405,0,(LPARAM)local_28);
  SendMessageA(*(HWND *)this,0x404,0,(LPARAM)local_28);
  return;
}



/* 00427b20  FUN_00427b20  101 bytes, 0 callers */

void __thiscall FUN_00427b20(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_1c [4];
  DWORD local_c;
  tagPOINT local_8;
  
  puVar2 = local_1c;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_1c[0] = *(undefined4 *)((int)this + 4);
  local_1c[1] = param_1;
  local_1c[2] = param_2;
  local_1c[3] = param_3;
  local_c = timeGetTime();
  GetCursorPos(&local_8);
  SendMessageA(*(HWND *)this,0x407,0,(LPARAM)local_1c);
  return;
}



/* 00427b86  GetOpenFileNameA  6 bytes, 1 callers */

BOOL GetOpenFileNameA(LPOPENFILENAMEA param_1)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00427b86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetOpenFileNameA(param_1);
  return BVar1;
}



/* 00427b90  _JumpToContinuation  46 bytes, 1 callers */

/* Library Function - Single Match
    void __stdcall _JumpToContinuation(void *,struct EHRegistrationNode *)
   
   Library: Visual Studio 1998 Release */

void _JumpToContinuation(void *param_1,EHRegistrationNode *param_2)

{
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)*unaff_FS_OFFSET;
                    /* WARNING: Could not recover jumptable at 0x00427bbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_1)();
  return;
}



/* 00427bd0  _CallMemberFunction0  7 bytes, 1 callers */

/* Library Function - Single Match
    void __stdcall _CallMemberFunction0(void *,void *)
   
   Library: Visual Studio 1998 Release */

void _CallMemberFunction0(void *param_1,void *param_2)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x00427bd5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_2)();
  return;
}



/* 00427be0  FID_conflict:_CallMemberFunction1  7 bytes, 1 callers */

/* Library Function - Multiple Matches With Different Base Names
    void __stdcall _CallMemberFunction1(void *,void *,void *)
    void __stdcall _CallMemberFunction2(void *,void *,void *,int)
   
   Library: Visual Studio 1998 Release */

void FID_conflict__CallMemberFunction1(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x00427be5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}



/* 00427bf0  FID_conflict:_CallMemberFunction1  7 bytes, 1 callers */

/* Library Function - Multiple Matches With Different Base Names
    void __stdcall _CallMemberFunction1(void *,void *,void *)
    void __stdcall _CallMemberFunction2(void *,void *,void *,int)
   
   Library: Visual Studio 1998 Release */

void FID_conflict__CallMemberFunction1(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x00427bf5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}



/* 00427c00  _UnwindNestedFrames  81 bytes, 2 callers */

/* Library Function - Single Match
    void __stdcall _UnwindNestedFrames(struct EHRegistrationNode *,struct EHExceptionRecord *)
   
   Library: Visual Studio 1998 Release */

void _UnwindNestedFrames(EHRegistrationNode *param_1,EHExceptionRecord *param_2)

{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  
  puVar1 = (undefined4 *)*unaff_FS_OFFSET;
  RtlUnwind(param_1,(PVOID)0x427c2c,(PEXCEPTION_RECORD)param_2,(PVOID)0x0);
  *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffffd;
  *puVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = puVar1;
  return;
}



/* 00427c60  ___CxxFrameHandler  60 bytes, 0 callers */

/* Library Function - Single Match
    ___CxxFrameHandler
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl
___CxxFrameHandler(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,
                  void *param_4)

{
  _s_FuncInfo *in_EAX;
  undefined4 uVar1;
  
  uVar1 = ___InternalCxxFrameHandler
                    (param_1,param_2,param_3,param_4,in_EAX,0,(EHRegistrationNode *)0x0,0);
  return uVar1;
}



/* 00427ca0  _CallCatchBlock2  98 bytes, 1 callers */

/* Library Function - Single Match
    void * __cdecl _CallCatchBlock2(struct EHRegistrationNode *,struct _s_FuncInfo const *,void
   *,int,unsigned long)
   
   Library: Visual Studio 1998 Release */

void * __cdecl
_CallCatchBlock2(EHRegistrationNode *param_1,_s_FuncInfo *param_2,void *param_3,int param_4,
                ulong param_5)

{
  void *pvVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *local_10;
  _s_FuncInfo *local_c;
  EHRegistrationNode *local_8;
  int local_4;
  
  local_c = param_2;
  local_8 = param_1;
  local_10 = &LAB_00427d10;
  local_4 = param_4 + 1;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  pvVar1 = (void *)__CallSettingFrame_12(param_3,param_1,param_5);
  *unaff_FS_OFFSET = local_14;
  return pvVar1;
}



/* 00427d40  _CallSETranslator  209 bytes, 1 callers */

/* Library Function - Single Match
    int __cdecl _CallSETranslator(struct EHExceptionRecord *,struct EHRegistrationNode *,void *,void
   *,struct _s_FuncInfo const *,int,struct EHRegistrationNode *)
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl
_CallSETranslator(EHExceptionRecord *param_1,EHRegistrationNode *param_2,void *param_3,void *param_4
                 ,_s_FuncInfo *param_5,int param_6,EHRegistrationNode *param_7)

{
  int *unaff_FS_OFFSET;
  undefined4 *local_38;
  code *local_34;
  _s_FuncInfo *local_30;
  EHRegistrationNode *local_2c;
  int local_28;
  EHRegistrationNode *local_24;
  undefined4 local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  int local_14;
  EHExceptionRecord *local_10;
  void *local_c;
  undefined4 local_8;
  
  local_18 = &stack0xfffffffc;
  local_1c = &stack0xffffffbc;
  local_34 = TranslatorGuardHandler;
  local_30 = param_5;
  local_2c = param_2;
  local_28 = param_6;
  local_24 = param_7;
  local_14 = 0;
  local_20 = 0x427dd7;
  local_38 = (undefined4 *)*unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_38;
  local_8 = 1;
  local_10 = param_1;
  local_c = param_3;
  (*DAT_00434790)(*(undefined4 *)param_1,&local_10);
  if (local_14 == 0) {
    *unaff_FS_OFFSET = (int)local_38;
  }
  else {
    *local_38 = *(undefined4 *)*unaff_FS_OFFSET;
    *unaff_FS_OFFSET = (int)local_38;
  }
  return 0;
}



/* 00427e20  TranslatorGuardHandler  98 bytes, 0 callers */

/* Library Function - Single Match
    enum _EXCEPTION_DISPOSITION __cdecl TranslatorGuardHandler(struct EHExceptionRecord *,struct
   TranslatorGuardRN *,void *,void *)
   
   Library: Visual Studio 1998 Release */

_EXCEPTION_DISPOSITION __cdecl
TranslatorGuardHandler
          (EHExceptionRecord *param_1,TranslatorGuardRN *param_2,void *param_3,void *param_4)

{
  _EXCEPTION_DISPOSITION _Var1;
  
  if (((byte)param_1[4] & 0x66) != 0) {
    *(undefined4 *)(param_2 + 0x24) = 1;
    return 1;
  }
  ___InternalCxxFrameHandler
            (param_1,*(EHRegistrationNode **)(param_2 + 0xc),param_3,(void *)0x0,
             *(_s_FuncInfo **)(param_2 + 8),*(int *)(param_2 + 0x10),
             *(EHRegistrationNode **)(param_2 + 0x14),1);
  if (*(int *)(param_2 + 0x24) == 0) {
    _UnwindNestedFrames((EHRegistrationNode *)param_2,param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x00427e7f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = (**(code **)(param_2 + 0x18))();
  return _Var1;
}



/* 00427e8c  __global_unwind2  32 bytes, 0 callers */

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x427ea4,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}



/* 00427ece  __local_unwind2  104 bytes, 1 callers */

/* Library Function - Single Match
    __local_unwind2
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

void __cdecl __local_unwind2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  int iStack_10;
  
  iStack_10 = param_1;
  puStack_18 = &LAB_00427eac;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_00427f62();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}



/* 00427f36  __abnormal_termination  35 bytes, 1 callers */

/* Library Function - Single Match
    __abnormal_termination
   
   Library: Visual Studio */

int __cdecl __abnormal_termination(void)

{
  int iVar1;
  int iVar2;
  int *unaff_FS_OFFSET;
  
  iVar2 = 0;
  iVar1 = *unaff_FS_OFFSET;
  if ((*(undefined1 **)(iVar1 + 4) == &LAB_00427eac) &&
     (*(int *)(iVar1 + 8) == *(int *)(*(int *)(iVar1 + 0xc) + 0xc))) {
    iVar2 = 1;
  }
  return iVar2;
}



/* 00427f59  FUN_00427f59  9 bytes, 1 callers */

void __fastcall FUN_00427f59(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_004345e0 = param_1;
  DAT_004345dc = in_EAX;
  DAT_004345e4 = unaff_EBP;
  return;
}



/* 00427f62  FUN_00427f62  24 bytes, 1 callers */

void FUN_00427f62(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_004345e0 = *(undefined4 *)(unaff_EBP + 8);
  DAT_004345dc = in_EAX;
  DAT_004345e4 = unaff_EBP;
  return;
}



/* 00427f80  FUN_00427f80  14 bytes, 27 callers */

void __cdecl FUN_00427f80(LPVOID param_1)

{
  FUN_0042a030(param_1);
  return;
}



/* 00427f90  FUN_00427f90  16 bytes, 7 callers */

void __cdecl FUN_00427f90(SIZE_T param_1)

{
  FUN_0042a070(param_1,1);
  return;
}



/* 00427fa0  __ftol  39 bytes, 4 callers */

/* Library Function - Single Match
    __ftol
   
   Library: Visual Studio */

longlong __ftol(void)

{
  float10 in_ST0;
  
  return (longlong)ROUND(in_ST0);
}



/* 00427fd0  __fpmath  23 bytes, 1 callers */

/* Library Function - Single Match
    __fpmath
   
   Library: Visual Studio 1998 Release */

void __cdecl __fpmath(int param_1)

{
  FUN_00428000();
  DAT_004345f4 = FUN_0042a140();
  __setdefaultprecision();
  return;
}



/* 00428000  FUN_00428000  56 bytes, 1 callers */

void FUN_00428000(void)

{
  PTR_FUN_0043480c = &LAB_0042a2d0;
  PTR_FUN_00434810 = &LAB_0042a350;
  PTR_FUN_00434814 = &LAB_0042a260;
  PTR_FUN_00434818 = &LAB_0042a330;
  PTR_FUN_00434808 = &LAB_0042a6f0;
  PTR_FUN_0043481c = &LAB_0042a6f0;
  return;
}



/* 00428040  _sprintf  103 bytes, 7 callers */

/* Library Function - Single Match
    _sprintf
   
   Library: Visual Studio 1998 Release */

int __cdecl _sprintf(char *_Dest,char *_Format,...)

{
  int iVar1;
  FILE local_20;
  
  local_20._flag = 0x42;
  local_20._base = _Dest;
  local_20._ptr = _Dest;
  local_20._cnt = 0x7fffffff;
  iVar1 = FUN_0042a8e0(&local_20,(byte *)_Format,(undefined4 *)&stack0x0000000c);
  local_20._cnt = local_20._cnt + -1;
  if (-1 < local_20._cnt) {
    *local_20._ptr = '\0';
    return iVar1;
  }
  FUN_0042a790(0,&local_20);
  return iVar1;
}



/* 004280b0  FUN_004280b0  10 bytes, 1 callers */

void __cdecl FUN_004280b0(undefined4 param_1)

{
  DAT_00434604 = param_1;
  return;
}



/* 004280c0  _rand  42 bytes, 1 callers */

/* Library Function - Single Match
    _rand
   
   Library: Visual Studio 1998 Release */

int __cdecl _rand(void)

{
  DAT_00434604 = DAT_00434604 * 0x343fd + 0x269ec3;
  return (DAT_00434604 & 0x7fff0000) >> 0x10;
}



/* 004280f0  FUN_004280f0  122 bytes, 2 callers */

/* WARNING: Removing unreachable block (ram,0x00428154) */

void __cdecl FUN_004280f0(int param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  uStack_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_00430980;
  puStack_10 = &LAB_0042b3d8;
  *unaff_FS_OFFSET = &uStack_14;
  local_8 = 0;
  while (param_3 = param_3 + -1, -1 < param_3) {
    (*param_4)(unaff_EDI);
  }
  return;
}



/* 00428180  __ArrayUnwind  103 bytes, 2 callers */

/* Library Function - Single Match
    void __stdcall __ArrayUnwind(void *,unsigned int,int,void (__thiscall*)(void *))
   
   Library: Visual Studio 1998 Release */

void __ArrayUnwind(void *param_1,uint param_2,int param_3,_func_void_void_ptr *param_4)

{
  void *unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_00430990;
  puStack_10 = &LAB_0042b3d8;
  *unaff_FS_OFFSET = &local_14;
  local_8 = 0;
  while (param_3 = param_3 + -1, -1 < param_3) {
    (*param_4)(unaff_EDI);
  }
  *unaff_FS_OFFSET = local_14;
  return;
}



/* 00428220  FUN_00428220  122 bytes, 2 callers */

/* WARNING: Removing unreachable block (ram,0x00428284) */

void __cdecl
FUN_00428220(void *param_1,uint param_2,int param_3,undefined *param_4,_func_void_void_ptr *param_5)

{
  undefined4 *unaff_FS_OFFSET;
  int local_20;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  uStack_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_004309a0;
  puStack_10 = &LAB_0042b3d8;
  *unaff_FS_OFFSET = &uStack_14;
  local_8 = 0;
  local_20 = 0;
  if (0 < param_3) {
    do {
      (*(code *)param_4)();
      local_20 = local_20 + 1;
    } while (local_20 < param_3);
  }
  return;
}



/* 004282b0  FUN_004282b0  279 bytes, 2 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl
FUN_004282b0(int param_1,uint param_2,ushort param_3,undefined4 param_4,uint param_5,uint param_6)

{
  float10 fVar1;
  uint uVar2;
  float10 fVar3;
  
  fVar1 = (float10)CONCAT28(param_3,CONCAT44(param_2,param_1));
  while (!CARRY4(param_2,param_2)) {
    if (param_1 == 0 && param_2 == 0) {
      return 0;
    }
    if ((param_3 & 0x7fff) != 0) {
      return param_3 & 0x7fff;
    }
    uVar2 = param_6 & 0x7fff;
    if (uVar2 == 0) {
      if (CARRY4(param_5,param_5)) {
        return param_5 * 2;
      }
    }
    else if ((uVar2 == 0x7fff) || (uVar2 = param_5 * 2, !CARRY4(param_5,param_5))) {
      return uVar2;
    }
    fVar3 = fVar1 * (float10)_DAT_00434628;
    param_1 = SUB104(fVar3,0);
    param_3 = (ushort)((unkuint10)fVar3 >> 0x40);
    param_2 = (uint)((unkuint10)fVar3 >> 0x20);
  }
  uVar2 = param_2 * 2 ^ 0xe000000;
  if ((uVar2 & 0xe000000) != 0) {
    return uVar2;
  }
  uVar2 = (param_2 & 0x7fffffff) >> 0x1b;
  if ((&DAT_00434610)[uVar2] != '\0') {
    if (((param_3 & 0x7fff) != 0) && ((param_3 & 0x7fff) != 0x7fff)) {
      if ((param_6 & 0x7fff) != 1) {
        return param_6 & 0x7fff;
      }
      return 1;
    }
    return param_3 & 0x7fff;
  }
  return uVar2;
}



/* 004283c7  FUN_004283c7  1183 bytes, 2 callers */

float10 FUN_004283c7(void)

{
  code *pcVar1;
  uint in_EAX;
  float10 in_ST0;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 extraout_ST0_04;
  float10 extraout_ST0_05;
  float10 extraout_ST0_06;
  float10 extraout_ST0_07;
  float10 extraout_ST0_08;
  float10 extraout_ST0_09;
  float10 extraout_ST0_10;
  float10 extraout_ST0_11;
  float10 extraout_ST0_12;
  float10 extraout_ST0_13;
  float10 extraout_ST0_14;
  float10 in_ST1;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 extraout_ST1_02;
  unkbyte10 in_ST2;
  unkbyte10 in_ST3;
  float10 in_ST4;
  float10 in_ST5;
  float10 in_ST6;
  float10 in_ST7;
  int iVar2;
  uint uVar9;
  ushort uVar16;
  int iVar23;
  uint uVar24;
  ushort uVar25;
  undefined2 in_stack_ffffffea;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  ushort uVar17;
  ushort uVar18;
  ushort uVar19;
  ushort uVar20;
  ushort uVar21;
  ushort uVar22;
  
  uVar25 = (ushort)((unkuint10)in_ST0 >> 0x40);
  iVar23 = SUB104(in_ST0,0);
  uVar24 = (uint)((unkuint10)in_ST0 >> 0x20);
  uVar16 = (ushort)((unkuint10)in_ST1 >> 0x40);
  iVar2 = SUB104(in_ST1,0);
  uVar9 = (uint)((unkuint10)in_ST1 >> 0x20);
  uVar17 = (ushort)((unkuint10)in_ST2 >> 0x40);
  iVar3 = (int)in_ST2;
  uVar10 = (uint)((unkuint10)in_ST2 >> 0x20);
  uVar18 = (ushort)((unkuint10)in_ST3 >> 0x40);
  iVar4 = (int)in_ST3;
  uVar11 = (uint)((unkuint10)in_ST3 >> 0x20);
  uVar19 = (ushort)((unkuint10)in_ST4 >> 0x40);
  iVar5 = SUB104(in_ST4,0);
  uVar12 = (uint)((unkuint10)in_ST4 >> 0x20);
  uVar20 = (ushort)((unkuint10)in_ST5 >> 0x40);
  iVar6 = SUB104(in_ST5,0);
  uVar13 = (uint)((unkuint10)in_ST5 >> 0x20);
  uVar21 = (ushort)((unkuint10)in_ST6 >> 0x40);
  iVar7 = SUB104(in_ST6,0);
  uVar14 = (uint)((unkuint10)in_ST6 >> 0x20);
  uVar22 = (ushort)((unkuint10)in_ST7 >> 0x40);
  iVar8 = SUB104(in_ST7,0);
  uVar15 = (uint)((unkuint10)in_ST7 >> 0x20);
  switch(in_EAX & 0x3f) {
  case 0:
    return in_ST0 / in_ST0;
  case 1:
    pcVar1 = (code *)swi(6);
    in_ST0 = (float10)(*pcVar1)();
  case 2:
    return in_ST0 / in_ST0;
  case 3:
    pcVar1 = (code *)swi(6);
    in_ST0 = (float10)(*pcVar1)();
  case 4:
    return in_ST0 / in_ST0;
  case 5:
    return in_ST1;
  case 6:
    return in_ST0 / in_ST0;
  case 7:
    return in_ST1;
  case 8:
    FUN_004282b0(iVar2,uVar9,uVar16,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return extraout_ST0;
  case 9:
    pcVar1 = (code *)swi(6);
    in_ST0 = (float10)(*pcVar1)();
    in_ST1 = extraout_ST1;
  case 10:
    FUN_004282b0(SUB104(in_ST0,0),(uint)((unkuint10)in_ST0 >> 0x20),
                 (ushort)((unkuint10)in_ST0 >> 0x40),SUB104(in_ST1,0),
                 (uint)((unkuint10)in_ST1 >> 0x20),
                 CONCAT22(in_stack_ffffffea,(short)((unkuint10)in_ST1 >> 0x40)));
    return extraout_ST0_00;
  case 0xb:
    pcVar1 = (code *)swi(6);
    in_ST0 = (float10)(*pcVar1)();
    in_ST1 = extraout_ST1_00;
  case 0xc:
    FUN_004282b0(SUB104(in_ST0,0),(uint)((unkuint10)in_ST0 >> 0x20),
                 (ushort)((unkuint10)in_ST0 >> 0x40),SUB104(in_ST1,0),
                 (uint)((unkuint10)in_ST1 >> 0x20),
                 CONCAT22(in_stack_ffffffea,(short)((unkuint10)in_ST1 >> 0x40)));
    return in_ST0;
  case 0xd:
    FUN_004282b0(iVar23,uVar24,uVar25,iVar2,uVar9,CONCAT22(in_stack_ffffffea,uVar16));
    return extraout_ST0_01;
  case 0xe:
    FUN_004282b0(iVar2,uVar9,uVar16,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return (float10)CONCAT28(uVar25,CONCAT44(uVar24,iVar23));
  case 0xf:
    FUN_004282b0(iVar2,uVar9,uVar16,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return extraout_ST0_02;
  case 0x10:
    FUN_004282b0(iVar3,uVar10,uVar17,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return extraout_ST0_03;
  case 0x11:
    pcVar1 = (code *)swi(6);
    in_ST0 = (float10)(*pcVar1)();
  case 0x12:
    FUN_004282b0(SUB104(in_ST0,0),(uint)((unkuint10)in_ST0 >> 0x20),
                 (ushort)((unkuint10)in_ST0 >> 0x40),(int)in_ST2,(uint)((unkuint10)in_ST2 >> 0x20),
                 CONCAT22(in_stack_ffffffea,(short)((unkuint10)in_ST2 >> 0x40)));
    return extraout_ST0_04;
  case 0x13:
    pcVar1 = (code *)swi(6);
    in_ST0 = (float10)(*pcVar1)();
  case 0x14:
    FUN_004282b0(SUB104(in_ST0,0),(uint)((unkuint10)in_ST0 >> 0x20),
                 (ushort)((unkuint10)in_ST0 >> 0x40),(int)in_ST2,(uint)((unkuint10)in_ST2 >> 0x20),
                 CONCAT22(in_stack_ffffffea,(short)((unkuint10)in_ST2 >> 0x40)));
    return in_ST0;
  case 0x15:
    FUN_004282b0(iVar23,uVar24,uVar25,iVar3,uVar10,CONCAT22(in_stack_ffffffea,uVar17));
    return extraout_ST1_01;
  case 0x16:
    FUN_004282b0(iVar3,uVar10,uVar17,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return (float10)CONCAT28(uVar25,CONCAT44(uVar24,iVar23));
  case 0x17:
    FUN_004282b0(iVar3,uVar10,uVar17,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return extraout_ST1_02;
  case 0x18:
    FUN_004282b0(iVar4,uVar11,uVar18,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return extraout_ST0_05;
  case 0x19:
    pcVar1 = (code *)swi(6);
    in_ST0 = (float10)(*pcVar1)();
  case 0x1a:
    FUN_004282b0(SUB104(in_ST0,0),(uint)((unkuint10)in_ST0 >> 0x20),
                 (ushort)((unkuint10)in_ST0 >> 0x40),(int)in_ST3,(uint)((unkuint10)in_ST3 >> 0x20),
                 CONCAT22(in_stack_ffffffea,(short)((unkuint10)in_ST3 >> 0x40)));
    return extraout_ST0_06;
  case 0x1b:
    pcVar1 = (code *)swi(6);
    in_ST0 = (float10)(*pcVar1)();
  case 0x1c:
    FUN_004282b0(SUB104(in_ST0,0),(uint)((unkuint10)in_ST0 >> 0x20),
                 (ushort)((unkuint10)in_ST0 >> 0x40),(int)in_ST3,(uint)((unkuint10)in_ST3 >> 0x20),
                 CONCAT22(in_stack_ffffffea,(short)((unkuint10)in_ST3 >> 0x40)));
    return in_ST0;
  case 0x1d:
    FUN_004282b0(iVar23,uVar24,uVar25,iVar4,uVar11,CONCAT22(in_stack_ffffffea,uVar18));
    return in_ST4;
  case 0x1e:
    FUN_004282b0(iVar4,uVar11,uVar18,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return (float10)CONCAT28(uVar25,CONCAT44(uVar24,iVar23));
  case 0x1f:
    FUN_004282b0(iVar4,uVar11,uVar18,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return in_ST4;
  case 0x20:
    FUN_004282b0(iVar5,uVar12,uVar19,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return extraout_ST0_07;
  case 0x21:
    pcVar1 = (code *)swi(6);
    in_ST0 = (float10)(*pcVar1)();
  case 0x22:
    FUN_004282b0(SUB104(in_ST0,0),(uint)((unkuint10)in_ST0 >> 0x20),
                 (ushort)((unkuint10)in_ST0 >> 0x40),SUB104(in_ST4,0),
                 (uint)((unkuint10)in_ST4 >> 0x20),
                 CONCAT22(in_stack_ffffffea,(short)((unkuint10)in_ST4 >> 0x40)));
    return extraout_ST0_08;
  case 0x23:
    pcVar1 = (code *)swi(6);
    in_ST0 = (float10)(*pcVar1)();
  case 0x24:
    FUN_004282b0(SUB104(in_ST0,0),(uint)((unkuint10)in_ST0 >> 0x20),
                 (ushort)((unkuint10)in_ST0 >> 0x40),SUB104(in_ST4,0),
                 (uint)((unkuint10)in_ST4 >> 0x20),
                 CONCAT22(in_stack_ffffffea,(short)((unkuint10)in_ST4 >> 0x40)));
    return in_ST0;
  case 0x25:
    FUN_004282b0(iVar23,uVar24,uVar25,iVar5,uVar12,CONCAT22(in_stack_ffffffea,uVar19));
    return in_ST5;
  case 0x26:
    FUN_004282b0(iVar5,uVar12,uVar19,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return (float10)CONCAT28(uVar25,CONCAT44(uVar24,iVar23));
  case 0x27:
    FUN_004282b0(iVar5,uVar12,uVar19,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return in_ST5;
  case 0x28:
    FUN_004282b0(iVar6,uVar13,uVar20,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return extraout_ST0_09;
  case 0x29:
    pcVar1 = (code *)swi(6);
    in_ST0 = (float10)(*pcVar1)();
  case 0x2a:
    FUN_004282b0(SUB104(in_ST0,0),(uint)((unkuint10)in_ST0 >> 0x20),
                 (ushort)((unkuint10)in_ST0 >> 0x40),SUB104(in_ST5,0),
                 (uint)((unkuint10)in_ST5 >> 0x20),
                 CONCAT22(in_stack_ffffffea,(short)((unkuint10)in_ST5 >> 0x40)));
    return extraout_ST0_10;
  case 0x2b:
    pcVar1 = (code *)swi(6);
    in_ST0 = (float10)(*pcVar1)();
  case 0x2c:
    FUN_004282b0(SUB104(in_ST0,0),(uint)((unkuint10)in_ST0 >> 0x20),
                 (ushort)((unkuint10)in_ST0 >> 0x40),SUB104(in_ST5,0),
                 (uint)((unkuint10)in_ST5 >> 0x20),
                 CONCAT22(in_stack_ffffffea,(short)((unkuint10)in_ST5 >> 0x40)));
    return in_ST0;
  case 0x2d:
    FUN_004282b0(iVar23,uVar24,uVar25,iVar6,uVar13,CONCAT22(in_stack_ffffffea,uVar20));
    return in_ST6;
  case 0x2e:
    FUN_004282b0(iVar6,uVar13,uVar20,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return (float10)CONCAT28(uVar25,CONCAT44(uVar24,iVar23));
  case 0x2f:
    FUN_004282b0(iVar6,uVar13,uVar20,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return in_ST6;
  case 0x30:
    FUN_004282b0(iVar7,uVar14,uVar21,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return extraout_ST0_11;
  case 0x31:
    pcVar1 = (code *)swi(6);
    in_ST0 = (float10)(*pcVar1)();
  case 0x32:
    FUN_004282b0(SUB104(in_ST0,0),(uint)((unkuint10)in_ST0 >> 0x20),
                 (ushort)((unkuint10)in_ST0 >> 0x40),SUB104(in_ST6,0),
                 (uint)((unkuint10)in_ST6 >> 0x20),
                 CONCAT22(in_stack_ffffffea,(short)((unkuint10)in_ST6 >> 0x40)));
    return extraout_ST0_12;
  case 0x33:
    pcVar1 = (code *)swi(6);
    in_ST0 = (float10)(*pcVar1)();
  case 0x34:
    FUN_004282b0(SUB104(in_ST0,0),(uint)((unkuint10)in_ST0 >> 0x20),
                 (ushort)((unkuint10)in_ST0 >> 0x40),SUB104(in_ST6,0),
                 (uint)((unkuint10)in_ST6 >> 0x20),
                 CONCAT22(in_stack_ffffffea,(short)((unkuint10)in_ST6 >> 0x40)));
    return in_ST0;
  case 0x35:
    FUN_004282b0(iVar23,uVar24,uVar25,iVar7,uVar14,CONCAT22(in_stack_ffffffea,uVar21));
    return in_ST7;
  case 0x36:
    FUN_004282b0(iVar7,uVar14,uVar21,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return (float10)CONCAT28(uVar25,CONCAT44(uVar24,iVar23));
  case 0x37:
    FUN_004282b0(iVar7,uVar14,uVar21,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return in_ST7;
  case 0x38:
    FUN_004282b0(iVar8,uVar15,uVar22,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return extraout_ST0_13;
  case 0x39:
    pcVar1 = (code *)swi(6);
    in_ST0 = (float10)(*pcVar1)();
  case 0x3a:
    FUN_004282b0(SUB104(in_ST0,0),(uint)((unkuint10)in_ST0 >> 0x20),
                 (ushort)((unkuint10)in_ST0 >> 0x40),SUB104(in_ST7,0),
                 (uint)((unkuint10)in_ST7 >> 0x20),
                 CONCAT22(in_stack_ffffffea,(short)((unkuint10)in_ST7 >> 0x40)));
    return extraout_ST0_14;
  case 0x3b:
    pcVar1 = (code *)swi(6);
    in_ST0 = (float10)(*pcVar1)();
  case 0x3c:
    FUN_004282b0(SUB104(in_ST0,0),(uint)((unkuint10)in_ST0 >> 0x20),
                 (ushort)((unkuint10)in_ST0 >> 0x40),SUB104(in_ST7,0),
                 (uint)((unkuint10)in_ST7 >> 0x20),
                 CONCAT22(in_stack_ffffffea,(short)((unkuint10)in_ST7 >> 0x40)));
    return in_ST0;
  case 0x3d:
    FUN_004282b0(iVar23,uVar24,uVar25,iVar8,uVar15,CONCAT22(in_stack_ffffffea,uVar22));
    return in_ST7;
  case 0x3e:
    FUN_004282b0(iVar8,uVar15,uVar22,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return (float10)CONCAT28(uVar25,CONCAT44(uVar24,iVar23));
  case 0x3f:
    FUN_004282b0(iVar8,uVar15,uVar22,iVar23,uVar24,CONCAT22(in_stack_ffffffea,uVar25));
    return in_ST7;
  }
}



/* 00428866  __fdivp_sti_st  19 bytes, 2 callers */

/* Library Function - Single Match
    __fdivp_sti_st
   
   Library: Visual Studio */

void __fdivp_sti_st(void)

{
  unkbyte10 in_ST0;
  unkbyte10 in_ST1;
  undefined2 in_stack_ffffffea;
  
  FUN_004282b0((int)in_ST0,(uint)((unkuint10)in_ST0 >> 0x20),(ushort)((unkuint10)in_ST0 >> 0x40),
               (int)in_ST1,(uint)((unkuint10)in_ST1 >> 0x20),
               CONCAT22(in_stack_ffffffea,(short)((unkuint10)in_ST1 >> 0x40)));
  return;
}



/* 0042888c  __adj_fdiv_m32  76 bytes, 1 callers */

/* Library Function - Single Match
    __adj_fdiv_m32
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

undefined4 __adj_fdiv_m32(uint param_1)

{
  undefined4 in_EAX;
  ushort in_FPUStatusWord;
  
  if ((param_1 & 0x7f800000) == 0x7f800000) {
    return in_EAX;
  }
  if ((in_FPUStatusWord & 0x3800) != 0) {
    __fdivp_sti_st();
    return in_EAX;
  }
  __fdivp_sti_st();
  return in_EAX;
}



/* 004288d8  __adj_fdiv_m64  76 bytes, 0 callers */

/* Library Function - Single Match
    __adj_fdiv_m64
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

undefined4 __adj_fdiv_m64(undefined4 param_1,uint param_2)

{
  undefined4 in_EAX;
  ushort in_FPUStatusWord;
  
  if ((param_2 & 0x7ff00000) == 0x7ff00000) {
    return in_EAX;
  }
  if ((in_FPUStatusWord & 0x3800) != 0) {
    __fdivp_sti_st();
    return in_EAX;
  }
  __fdivp_sti_st();
  return in_EAX;
}



/* 00429040  _strncmp  56 bytes, 1 callers */

/* Library Function - Single Match
    _strncmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar5 = 0;
  sVar3 = _MaxCount;
  pcVar6 = _Str1;
  if (_MaxCount != 0) {
    do {
      if (sVar3 == 0) break;
      sVar3 = sVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar4 = _MaxCount - sVar3;
    do {
      pcVar6 = _Str2;
      pcVar7 = _Str1;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = _Str1 + 1;
      pcVar6 = _Str2 + 1;
      cVar2 = *_Str1;
      cVar1 = *_Str2;
      _Str2 = pcVar6;
      _Str1 = pcVar7;
    } while (cVar1 == cVar2);
    uVar5 = 0;
    if ((byte)pcVar6[-1] <= (byte)pcVar7[-1]) {
      if (pcVar6[-1] == pcVar7[-1]) {
        return 0;
      }
      uVar5 = 0xfffffffe;
    }
    uVar5 = ~uVar5;
  }
  return uVar5;
}



/* 00429080  FUN_00429080  121 bytes, 1 callers */

undefined4 __cdecl FUN_00429080(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  LPVOID pvVar3;
  
  uVar1 = FUN_0042b630(DAT_00438a94);
  if (uVar1 < (uint)((int)DAT_00438a90 + (4 - (int)DAT_00438a94))) {
    iVar2 = FUN_0042b630(DAT_00438a94);
    pvVar3 = FUN_0042b5c0(DAT_00438a94,iVar2 + 0x10);
    if (pvVar3 == (LPVOID)0x0) {
      return 0;
    }
    DAT_00438a90 = (undefined4 *)
                   (((int)DAT_00438a90 - (int)DAT_00438a94 & 0xfffffffcU) + (int)pvVar3);
    DAT_00438a94 = pvVar3;
  }
  *DAT_00438a90 = param_1;
  DAT_00438a90 = DAT_00438a90 + 1;
  return param_1;
}



/* 00429100  FUN_00429100  19 bytes, 13 callers */

int __cdecl FUN_00429100(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00429080(param_1);
  return -(uint)(iVar1 == 0);
}



/* 00429160  FUN_00429160  348 bytes, 1 callers */

void __cdecl FUN_00429160(byte *param_1,uchar *param_2,uchar *param_3,uchar *param_4,uchar *param_5)

{
  byte bVar1;
  byte *_Source;
  size_t sVar2;
  byte *pbVar3;
  byte *local_4;
  
  local_4 = (byte *)0x0;
  if (param_1[1] == 0x3a) {
    if (param_2 != (uchar *)0x0) {
      __mbsnbcpy(param_2,param_1,2);
      param_2[2] = '\0';
    }
    param_1 = param_1 + 2;
  }
  else if (param_2 != (uchar *)0x0) {
    *param_2 = '\0';
  }
  _Source = (byte *)0x0;
  bVar1 = *param_1;
  pbVar3 = param_1;
  while (bVar1 != 0) {
    bVar1 = *pbVar3;
    if ((*(byte *)((int)&DAT_004348a0 + bVar1 + 1) & 4) == 0) {
      if ((bVar1 == 0x2f) || (bVar1 == 0x5c)) {
        _Source = pbVar3 + 1;
      }
      else if (bVar1 == 0x2e) {
        local_4 = pbVar3;
      }
    }
    else {
      pbVar3 = pbVar3 + 1;
    }
    pbVar3 = pbVar3 + 1;
    bVar1 = *pbVar3;
  }
  if (_Source == (byte *)0x0) {
    _Source = param_1;
    if (param_3 != (uchar *)0x0) {
      *param_3 = '\0';
    }
  }
  else if (param_3 != (uchar *)0x0) {
    sVar2 = (int)_Source - (int)param_1;
    if (0xfe < sVar2) {
      sVar2 = 0xff;
    }
    __mbsnbcpy(param_3,param_1,sVar2);
    param_3[sVar2] = '\0';
  }
  if ((local_4 == (byte *)0x0) || (local_4 < _Source)) {
    if (param_4 != (uchar *)0x0) {
      sVar2 = (int)pbVar3 - (int)_Source;
      if (0xfe < sVar2) {
        sVar2 = 0xff;
      }
      __mbsnbcpy(param_4,_Source,sVar2);
      param_4[sVar2] = '\0';
    }
    if (param_5 != (uchar *)0x0) {
      *param_5 = '\0';
    }
  }
  else {
    if (param_4 != (uchar *)0x0) {
      sVar2 = (int)local_4 - (int)_Source;
      if (0xfe < sVar2) {
        sVar2 = 0xff;
      }
      __mbsnbcpy(param_4,_Source,sVar2);
      param_4[sVar2] = '\0';
    }
    if (param_5 != (uchar *)0x0) {
      sVar2 = (int)pbVar3 - (int)local_4;
      if (0xfe < sVar2) {
        sVar2 = 0xff;
      }
      __mbsnbcpy(param_5,local_4,sVar2);
      param_5[sVar2] = '\0';
      return;
    }
  }
  return;
}



/* 004292c0  entry  351 bytes, 0 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  byte bVar1;
  DWORD DVar2;
  HMODULE pHVar3;
  UINT UVar4;
  byte *pbVar5;
  undefined4 *unaff_FS_OFFSET;
  int iVar6;
  _STARTUPINFOA local_74;
  undefined1 *local_1c;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &DAT_004309b0;
  puStack_10 = &LAB_0042b3d8;
  *unaff_FS_OFFSET = &local_14;
  local_1c = &stack0xffffff80;
  DVar2 = GetVersion();
  _DAT_0043486c = DVar2 >> 8 & 0xff;
  DAT_00434860 = DVar2 >> 0x10;
  _DAT_00434868 = DVar2 & 0xff;
  _DAT_00434864 = _DAT_00434868 * 0x100 + _DAT_0043486c;
  FUN_0042c280();
  local_8 = 0;
  FUN_0042c0a0();
  FUN_0042b9a0();
  DAT_00438a98 = (byte *)GetCommandLineA();
  DAT_00434770 = FUN_0042bf00();
  if ((DAT_00434770 == (LPSTR)0x0) || (DAT_00438a98 == (byte *)0x0)) {
    FUN_0042b4e0(0xffffffff);
  }
  __setargv();
  FUN_0042bba0();
  FUN_0042b4b0();
  bVar1 = *DAT_00438a98;
  pbVar5 = DAT_00438a98;
  if (bVar1 == 0x22) {
    pbVar5 = DAT_00438a98 + 1;
    if (*pbVar5 != 0x22) {
      do {
        if (*pbVar5 == 0) break;
        iVar6 = __ismbblead((uint)*pbVar5);
        if (iVar6 != 0) {
          pbVar5 = pbVar5 + 1;
        }
        pbVar5 = pbVar5 + 1;
      } while (*pbVar5 != 0x22);
      if (*pbVar5 != 0x22) goto LAB_004293b7;
    }
    pbVar5 = pbVar5 + 1;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar5[1];
      pbVar5 = pbVar5 + 1;
    }
  }
LAB_004293b7:
  bVar1 = *pbVar5;
  while ((bVar1 != 0 && (*pbVar5 < 0x21))) {
    pbVar5 = pbVar5 + 1;
    bVar1 = *pbVar5;
  }
  local_74.dwFlags = 0;
  GetStartupInfoA(&local_74);
  iVar6 = 0;
  pHVar3 = GetModuleHandleA((LPCSTR)0x0);
  UVar4 = FUN_00426370(pHVar3,iVar6);
  FUN_0042b4e0(UVar4);
  *unaff_FS_OFFSET = local_14;
  return;
}



/* 00429450  __amsg_exit  38 bytes, 4 callers */

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_0043477c == 1) {
    __FF_MSGBANNER();
  }
  FUN_0042c2e0(param_1);
  (*(code *)PTR___exit_00434778)(0xff);
  return;
}



/* 00429480  ___InternalCxxFrameHandler  188 bytes, 2 callers */

/* Library Function - Single Match
    ___InternalCxxFrameHandler
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl
___InternalCxxFrameHandler
          (EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
          _s_FuncInfo *param_5,int param_6,EHRegistrationNode *param_7,undefined4 param_8)

{
  undefined4 uVar1;
  
  if (*(int *)param_5 != 0x19930520) {
    FUN_00429fb0();
  }
  if (((byte)param_1[4] & 0x66) != 0) {
    if ((*(int *)(param_5 + 4) != 0) && (param_6 == 0)) {
      ___FrameUnwindToState((int)param_2,param_4,(int)param_5,-1);
    }
    return 1;
  }
  if (*(int *)(param_5 + 0xc) != 0) {
    if (((*(int *)param_1 == -0x1f928c9d) && (0x19930520 < *(uint *)(param_1 + 0x14))) &&
       (*(code **)(*(int *)(param_1 + 0x1c) + 8) != (code *)0x0)) {
      uVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 8))
                        (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
      return uVar1;
    }
    FUN_00429540(param_1,param_2,param_3,param_4,param_5,(char)param_8,param_6,param_7);
  }
  return 1;
}



/* 00429540  FUN_00429540  659 bytes, 1 callers */

void __cdecl
FUN_00429540(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
            _s_FuncInfo *param_5,char param_6,int param_7,EHRegistrationNode *param_8)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  EHExceptionRecord *pEVar5;
  bool bVar6;
  undefined3 extraout_var;
  _s_HandlerType *p_Var7;
  int iVar8;
  int *piVar9;
  byte *pbVar10;
  int iVar11;
  byte *pbVar12;
  _s_TryBlockMapEntry *p_Stack_18;
  uint uStack_c;
  uint uStack_8;
  uint *puStack_4;
  
  iVar2 = *(int *)(param_2 + 8);
  if ((iVar2 < -1) || (*(int *)(param_5 + 4) <= iVar2)) {
    FUN_00429fb0();
  }
  pEVar5 = DAT_00434788;
  if ((((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
      (*(int *)(param_1 + 0x14) == 0x19930520)) && (*(int *)(param_1 + 0x1c) == 0)) {
    if (DAT_00434788 == (EHExceptionRecord *)0x0) {
      return;
    }
    param_1 = DAT_00434788;
    param_3 = DAT_0043478c;
    bVar6 = FID_conflict__ValidateRead(DAT_00434788,1);
    if (CONCAT31(extraout_var,bVar6) == 0) {
      FUN_00429fb0();
    }
    if (((*(int *)pEVar5 == -0x1f928c9d) && (*(int *)(pEVar5 + 0x10) == 3)) &&
       ((*(int *)(pEVar5 + 0x14) == 0x19930520 && (*(int *)(pEVar5 + 0x1c) == 0)))) {
      FUN_00429fb0();
    }
  }
  if (((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
     (*(int *)(param_1 + 0x14) == 0x19930520)) {
    p_Stack_18 = GetRangeOfTrysToCheck(param_5,param_7,iVar2,&uStack_c,&uStack_8);
    if (uStack_c < uStack_8) {
      do {
        if ((*(int *)p_Stack_18 <= iVar2) && (iVar2 <= *(int *)(p_Stack_18 + 4))) {
          p_Var7 = *(_s_HandlerType **)(p_Stack_18 + 0x10);
          for (iVar3 = *(int *)(p_Stack_18 + 0xc); iVar3 != 0; iVar3 = iVar3 + -1) {
            piVar9 = *(int **)(*(int *)(param_1 + 0x1c) + 0xc);
            for (iVar8 = *piVar9; iVar8 != 0; iVar8 = iVar8 + -1) {
              piVar9 = piVar9 + 1;
              iVar11 = *(int *)(p_Var7 + 4);
              puStack_4 = *(uint **)(param_1 + 0x1c);
              pbVar4 = (byte *)*piVar9;
              if ((iVar11 == 0) || (*(char *)(iVar11 + 8) == '\0')) {
LAB_004296f4:
                bVar6 = true;
              }
              else {
                if (iVar11 == *(int *)(pbVar4 + 4)) {
LAB_004296ce:
                  if (((((*pbVar4 & 2) == 0) || (((byte)*p_Var7 & 8) != 0)) &&
                      (((*puStack_4 & 1) == 0 || (((byte)*p_Var7 & 1) != 0)))) &&
                     (((*puStack_4 & 2) == 0 || (((byte)*p_Var7 & 2) != 0)))) goto LAB_004296f4;
                }
                else {
                  pbVar10 = (byte *)(iVar11 + 8);
                  pbVar12 = (byte *)(*(int *)(pbVar4 + 4) + 8);
                  do {
                    bVar1 = *pbVar10;
                    bVar6 = bVar1 < *pbVar12;
                    if (bVar1 != *pbVar12) {
LAB_004296c5:
                      iVar11 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
                      goto LAB_004296ca;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar10[1];
                    bVar6 = bVar1 < pbVar12[1];
                    if (bVar1 != pbVar12[1]) goto LAB_004296c5;
                    pbVar10 = pbVar10 + 2;
                    pbVar12 = pbVar12 + 2;
                  } while (bVar1 != 0);
                  iVar11 = 0;
LAB_004296ca:
                  if (iVar11 == 0) goto LAB_004296ce;
                }
                bVar6 = false;
              }
              if (bVar6) {
                CatchIt(param_1,param_2,param_3,param_4,param_5,p_Var7,(_s_CatchableType *)*piVar9,
                        p_Stack_18,param_7,param_8);
                goto LAB_00429752;
              }
            }
            p_Var7 = p_Var7 + 0x10;
          }
        }
LAB_00429752:
        p_Stack_18 = p_Stack_18 + 0x14;
        uStack_c = uStack_c + 1;
      } while (uStack_c < uStack_8);
    }
    if (param_6 != '\0') {
      DestructExceptionObject(param_1,'\x01');
      return;
    }
  }
  else {
    if (param_6 == '\0') {
      FUN_004297e0(param_1,param_2,param_3,param_4,param_5,iVar2,param_7,param_8);
      return;
    }
    FUN_00429f30();
  }
  return;
}



/* 004297e0  FUN_004297e0  213 bytes, 1 callers */

void __cdecl
FUN_004297e0(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
            _s_FuncInfo *param_5,int param_6,int param_7,EHRegistrationNode *param_8)

{
  int iVar1;
  _s_TryBlockMapEntry *p_Var2;
  int iVar3;
  uint local_8;
  uint local_4;
  
  if (((DAT_00434790 == 0) ||
      (iVar1 = _CallSETranslator(param_1,param_2,param_3,param_4,param_5,param_7,param_8),
      iVar1 == 0)) &&
     (p_Var2 = GetRangeOfTrysToCheck(param_5,param_7,param_6,&local_8,&local_4), local_8 < local_4))
  {
    do {
      if ((*(int *)p_Var2 <= param_6) && (param_6 <= *(int *)(p_Var2 + 4))) {
        iVar3 = *(int *)(p_Var2 + 0xc) * 0x10 + *(int *)(p_Var2 + 0x10);
        iVar1 = *(int *)(iVar3 + -0xc);
        if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
          CatchIt(param_1,param_2,param_3,param_4,param_5,(_s_HandlerType *)(iVar3 + -0x10),
                  (_s_CatchableType *)0x0,p_Var2,param_7,param_8);
        }
      }
      p_Var2 = p_Var2 + 0x14;
      local_8 = local_8 + 1;
    } while (local_8 < local_4);
  }
  return;
}



/* 004298c0  GetRangeOfTrysToCheck  159 bytes, 2 callers */

/* Library Function - Single Match
    struct _s_TryBlockMapEntry const * __cdecl GetRangeOfTrysToCheck(struct _s_FuncInfo const
   *,int,int,unsigned int *,unsigned int *)
   
   Library: Visual Studio 1998 Release */

_s_TryBlockMapEntry * __cdecl
GetRangeOfTrysToCheck(_s_FuncInfo *param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint local_c;
  uint local_8;
  
  iVar1 = *(int *)(param_1 + 0x10);
  uVar3 = *(uint *)(param_1 + 0xc);
  local_c = uVar3;
  if (-1 < param_2) {
    piVar2 = (int *)(uVar3 * 0x14 + 4 + iVar1);
    local_8 = uVar3;
    do {
      if (uVar3 == 0xffffffff) {
        FUN_00429fb0();
      }
      uVar3 = uVar3 - 1;
      if (((piVar2[-5] < param_3) && (param_3 <= piVar2[-4])) || (uVar3 == 0xffffffff)) {
        param_2 = param_2 + -1;
        local_c = local_8;
        local_8 = uVar3;
      }
      piVar2 = piVar2 + -5;
    } while (-1 < param_2);
  }
  uVar3 = uVar3 + 1;
  *param_4 = uVar3;
  *param_5 = local_c;
  if ((*(uint *)(param_1 + 0xc) < local_c) || (local_c < uVar3)) {
    FUN_00429fb0();
  }
  return (_s_TryBlockMapEntry *)(iVar1 + uVar3 * 0x14);
}



/* 00429960  ___FrameUnwindToState  190 bytes, 2 callers */

/* Library Function - Single Match
    ___FrameUnwindToState
   
   Library: Visual Studio 1998 Release */

void __cdecl ___FrameUnwindToState(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_004309c0;
  puStack_10 = &LAB_0042b3d8;
  *unaff_FS_OFFSET = &local_14;
  for (iVar1 = *(int *)(param_1 + 8); iVar1 != param_4;
      iVar1 = *(int *)(*(int *)(param_3 + 8) + iVar1 * 8)) {
    local_8 = 0xffffffff;
    if ((iVar1 < 0) || (*(int *)(param_3 + 4) <= iVar1)) {
      FUN_00429fb0();
    }
    local_8 = 0;
    iVar2 = *(int *)(*(int *)(param_3 + 8) + 4 + iVar1 * 8);
    if (iVar2 != 0) {
      __CallSettingFrame_12(iVar2,param_1,0x103);
    }
  }
  local_8 = 0xffffffff;
  if (iVar1 != param_4) {
    FUN_00429fb0();
  }
  *(int *)(param_1 + 8) = iVar1;
  *unaff_FS_OFFSET = local_14;
  return;
}



/* 00429a50  CatchIt  148 bytes, 2 callers */

/* Library Function - Single Match
    void __cdecl CatchIt(struct EHExceptionRecord *,struct EHRegistrationNode *,struct _CONTEXT
   *,void *,struct _s_FuncInfo const *,struct _s_HandlerType const *,struct _s_CatchableType const
   *,struct _s_TryBlockMapEntry const *,int,struct EHRegistrationNode *)
   
   Library: Visual Studio 1998 Release */

void __cdecl
CatchIt(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
       _s_FuncInfo *param_5,_s_HandlerType *param_6,_s_CatchableType *param_7,
       _s_TryBlockMapEntry *param_8,int param_9,EHRegistrationNode *param_10)

{
  void *pvVar1;
  
  if (param_7 != (_s_CatchableType *)0x0) {
    BuildCatchObject(param_1,param_2,param_6,param_7);
  }
  if (param_10 == (EHRegistrationNode *)0x0) {
    param_10 = param_2;
  }
  _UnwindNestedFrames(param_10,param_1);
  ___FrameUnwindToState((int)param_2,param_4,(int)param_5,*(int *)param_8);
  *(int *)(param_2 + 8) = *(int *)(param_8 + 4) + 1;
  pvVar1 = (void *)FUN_00429af0(param_1,param_2,param_3,param_5,*(void **)(param_6 + 0xc),param_9,
                                0x100);
  if (pvVar1 != (void *)0x0) {
    _JumpToContinuation(pvVar1,param_2);
  }
  return;
}



/* 00429af0  FUN_00429af0  213 bytes, 1 callers */

void __cdecl
FUN_00429af0(EHExceptionRecord *param_1,EHRegistrationNode *param_2,undefined4 param_3,
            _s_FuncInfo *param_4,void *param_5,int param_6,ulong param_7)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  uStack_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_004309d0;
  puStack_10 = &LAB_0042b3d8;
  *unaff_FS_OFFSET = &uStack_14;
  uVar3 = DAT_0043478c;
  uVar2 = DAT_00434788;
  uVar1 = *(undefined4 *)(param_2 + -4);
  DAT_00434788 = param_1;
  DAT_0043478c = param_3;
  local_8 = 1;
  pvVar4 = _CallCatchBlock2(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  *(undefined4 *)(param_2 + -4) = uVar1;
  DAT_00434788 = (EHExceptionRecord *)uVar2;
  DAT_0043478c = uVar3;
  if ((((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
      (*(int *)(param_1 + 0x14) == 0x19930520)) && (pvVar4 != (void *)0x0)) {
    iVar5 = __abnormal_termination();
    DestructExceptionObject(param_1,(uchar)iVar5);
  }
  return;
}



/* 00429c30  BuildCatchObject  496 bytes, 1 callers */

/* Library Function - Single Match
    void __cdecl BuildCatchObject(struct EHExceptionRecord *,struct EHRegistrationNode *,struct
   _s_HandlerType const *,struct _s_CatchableType const *)
   
   Library: Visual Studio 1998 Release */

void __cdecl
BuildCatchObject(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_s_HandlerType *param_3,
                _s_CatchableType *param_4)

{
  EHRegistrationNode *_Dst;
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  void *pvVar2;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  size_t _Size;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_004309e8;
  puStack_10 = &LAB_0042b3d8;
  *unaff_FS_OFFSET = &local_14;
  if (((*(int *)(param_3 + 4) != 0) && (*(char *)(*(int *)(param_3 + 4) + 8) != '\0')) &&
     (*(int *)(param_3 + 8) != 0)) {
    _Dst = param_2 + *(int *)(param_3 + 8) + 0xc;
    local_8 = 0;
    if (((byte)*param_3 & 8) == 0) {
      if (((byte)*param_4 & 1) == 0) {
        if (*(int *)(param_4 + 0x18) == 0) {
          bVar1 = FID_conflict__ValidateRead(*(void **)(param_1 + 0x18),1);
          if ((CONCAT31(extraout_var_03,bVar1) != 0) &&
             (bVar1 = FID_conflict__ValidateRead(_Dst,1), CONCAT31(extraout_var_04,bVar1) != 0)) {
            _Size = *(size_t *)(param_4 + 0x14);
            pvVar2 = AdjustPointer(*(void **)(param_1 + 0x18),(PMD *)(param_4 + 8));
            FID_conflict__memcpy(_Dst,pvVar2,_Size);
            goto LAB_00429e1e;
          }
        }
        else {
          bVar1 = FID_conflict__ValidateRead(*(void **)(param_1 + 0x18),1);
          if (((CONCAT31(extraout_var_05,bVar1) != 0) &&
              (bVar1 = FID_conflict__ValidateRead(_Dst,1), CONCAT31(extraout_var_06,bVar1) != 0)) &&
             (iVar3 = _ValidateExecute(*(_func_int **)(param_4 + 0x18)), iVar3 != 0)) {
            if (((byte)*param_4 & 4) == 0) {
              AdjustPointer(*(void **)(param_1 + 0x18),(PMD *)(param_4 + 8));
              FID_conflict__CallMemberFunction1(_Dst,*(undefined **)(param_4 + 0x18));
            }
            else {
              AdjustPointer(*(void **)(param_1 + 0x18),(PMD *)(param_4 + 8));
              FID_conflict__CallMemberFunction1(_Dst,*(undefined **)(param_4 + 0x18));
            }
            goto LAB_00429e1e;
          }
        }
      }
      else {
        bVar1 = FID_conflict__ValidateRead(*(void **)(param_1 + 0x18),1);
        if ((CONCAT31(extraout_var_01,bVar1) != 0) &&
           (bVar1 = FID_conflict__ValidateRead(_Dst,1), CONCAT31(extraout_var_02,bVar1) != 0)) {
          FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0x18),*(size_t *)(param_4 + 0x14));
          if ((*(int *)(param_4 + 0x14) == 4) && (*(void **)_Dst != (void *)0x0)) {
            pvVar2 = AdjustPointer(*(void **)_Dst,(PMD *)(param_4 + 8));
            *(void **)_Dst = pvVar2;
          }
          goto LAB_00429e1e;
        }
      }
    }
    else {
      bVar1 = FID_conflict__ValidateRead(*(void **)(param_1 + 0x18),1);
      if ((CONCAT31(extraout_var,bVar1) != 0) &&
         (bVar1 = FID_conflict__ValidateRead(_Dst,1), CONCAT31(extraout_var_00,bVar1) != 0)) {
        pvVar2 = *(void **)(param_1 + 0x18);
        *(void **)_Dst = pvVar2;
        pvVar2 = AdjustPointer(pvVar2,(PMD *)(param_4 + 8));
        *(void **)_Dst = pvVar2;
        goto LAB_00429e1e;
      }
    }
    FUN_00429fb0();
  }
LAB_00429e1e:
  *unaff_FS_OFFSET = local_14;
  return;
}



/* 00429e30  DestructExceptionObject  97 bytes, 2 callers */

/* Library Function - Single Match
    void __cdecl DestructExceptionObject(struct EHExceptionRecord *,unsigned char)
   
   Library: Visual Studio 1998 Release */

void __cdecl DestructExceptionObject(EHExceptionRecord *param_1,uchar param_2)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_004309f8;
  puStack_10 = &LAB_0042b3d8;
  *unaff_FS_OFFSET = &local_14;
  if ((param_1 != (EHExceptionRecord *)0x0) &&
     (*(void **)(*(int *)(param_1 + 0x1c) + 4) != (void *)0x0)) {
    local_8 = 0;
    _CallMemberFunction0(*(void **)(param_1 + 0x18),*(void **)(*(int *)(param_1 + 0x1c) + 4));
  }
  *unaff_FS_OFFSET = local_14;
  return;
}



/* 00429eb0  AdjustPointer  33 bytes, 1 callers */

/* Library Function - Single Match
    void * __cdecl AdjustPointer(void *,struct PMD const &)
   
   Library: Visual Studio 1998 Release */

void * __cdecl AdjustPointer(void *param_1,PMD *param_2)

{
  int iVar1;
  void *pvVar2;
  
  pvVar2 = (void *)(*(int *)param_2 + (int)param_1);
  iVar1 = *(int *)(param_2 + 4);
  if (-1 < iVar1) {
    pvVar2 = (void *)((int)pvVar2 +
                     iVar1 + *(int *)(*(int *)(iVar1 + (int)param_1) + *(int *)(param_2 + 8)));
  }
  return pvVar2;
}



/* 00429ee0  __CallSettingFrame@12  72 bytes, 2 callers */

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Library Function - Single Match
    __CallSettingFrame@12
   
   Library: Visual Studio 1998 Release */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)FUN_00427f59(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  FUN_00427f59(param_3);
  return;
}



/* 00429f30  FUN_00429f30  89 bytes, 3 callers */

void FUN_00429f30(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  uStack_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_00430a08;
  puStack_10 = &LAB_0042b3d8;
  *unaff_FS_OFFSET = &uStack_14;
  if (DAT_00434794 != (code *)0x0) {
    local_8 = 1;
    (*DAT_00434794)();
  }
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* 00429fb0  FUN_00429fb0  89 bytes, 5 callers */

void FUN_00429fb0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  uStack_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_00430a20;
  puStack_10 = &LAB_0042b3d8;
  *unaff_FS_OFFSET = &uStack_14;
  if (PTR_FUN_0043479c != (undefined *)0x0) {
    local_8 = 1;
    (*(code *)PTR_FUN_0043479c)();
  }
  local_8 = 0xffffffff;
  FUN_00429f30();
  return;
}



/* 0042a030  FUN_0042a030  24 bytes, 9 callers */

void __cdecl FUN_0042a030(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    HeapFree(DAT_00438980,0,param_1);
  }
  return;
}



/* 0042a050  FUN_0042a050  20 bytes, 7 callers */

void __cdecl FUN_0042a050(SIZE_T param_1)

{
  FUN_0042a070(param_1,DAT_00434eb0);
  return;
}



/* 0042a070  FUN_0042a070  64 bytes, 2 callers */

int __cdecl FUN_0042a070(SIZE_T param_1,int param_2)

{
  int iVar1;
  
  if (0xffffffe0 < param_1) {
    return 0;
  }
  if (param_1 == 0) {
    param_1 = 1;
  }
  while( true ) {
    iVar1 = FUN_0042a0b0(param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (param_2 == 0) break;
    iVar1 = FUN_0042c740(param_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 0;
}



/* 0042a0b0  FUN_0042a0b0  21 bytes, 1 callers */

void __cdecl FUN_0042a0b0(SIZE_T param_1)

{
  HeapAlloc(DAT_00438980,0,param_1);
  return;
}



/* 0042a0d0  __setdefaultprecision  19 bytes, 1 callers */

/* Library Function - Single Match
    __setdefaultprecision
   
   Library: Visual Studio 1998 Release */

void __setdefaultprecision(void)

{
  __controlfp(0x10000,0x30000);
  return;
}



/* 0042a0f0  __ms_p5_test_fdiv  79 bytes, 1 callers */

/* Library Function - Single Match
    __ms_p5_test_fdiv
   
   Library: Visual Studio 1998 Release */

undefined1 __ms_p5_test_fdiv(void)

{
  return 0;
}



/* 0042a140  FUN_0042a140  278 bytes, 1 callers */

undefined4 FUN_0042a140(void)

{
  undefined1 uVar1;
  undefined3 extraout_var;
  HMODULE hModule;
  FARPROC pFVar2;
  FARPROC pFVar3;
  FARPROC pFVar4;
  FARPROC pFVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined3 extraout_var_00;
  uint unaff_EDI;
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  uVar1 = __ms_p5_test_fdiv();
  if (CONCAT31(extraout_var,uVar1) != 0) {
    return 1;
  }
  hModule = LoadLibraryA(s_KERNEL32_004347f8);
  if (hModule == (HMODULE)0x0) {
    return 0;
  }
  pFVar2 = GetProcAddress(hModule,s_GetProcessAffinityMask_004347e0);
  if (pFVar2 == (FARPROC)0x0) {
    return 0;
  }
  pFVar3 = GetProcAddress(hModule,s_GetCurrentProcess_004347cc);
  if (pFVar3 == (FARPROC)0x0) {
    return 0;
  }
  pFVar4 = GetProcAddress(hModule,s_SetThreadAffinityMask_004347b4);
  if (pFVar4 == (FARPROC)0x0) {
    return 0;
  }
  pFVar5 = GetProcAddress(hModule,s_GetCurrentThread_004347a0);
  if (pFVar5 == (FARPROC)0x0) {
    return 0;
  }
  iVar6 = (*pFVar3)();
  iVar6 = (*pFVar2)(iVar6,auStack_4,auStack_8);
  if (iVar6 == 0) {
    return 0;
  }
  iVar6 = 0;
  do {
    uVar7 = 1 << ((byte)iVar6 & 0x1f);
    if ((unaff_EDI & uVar7) != 0) {
      iVar8 = (*pFVar5)(uVar7);
      (*pFVar4)(iVar8);
      uVar1 = __ms_p5_test_fdiv();
      if (CONCAT31(extraout_var_00,uVar1) != 0) {
        iVar6 = (*pFVar5)(unaff_EDI);
        (*pFVar4)(iVar6);
        return 1;
      }
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x20);
  iVar6 = (*pFVar5)(unaff_EDI);
  (*pFVar4)(iVar6);
  return 0;
}



/* 0042a3a0  __cftoe  310 bytes, 1 callers */

/* Library Function - Single Match
    __cftoe
   
   Library: Visual Studio 1998 Release */

errno_t __cdecl __cftoe(double *_Value,char *_Buf,size_t _SizeInBytes,int _Dec,int _Caps)

{
  int *_Digits;
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  STRFLT unaff_EBP;
  bool bVar4;
  
  _Digits = DAT_0043782c;
  if (DAT_00434820 == '\0') {
    _Digits = (int *)__fltout();
    __fptostr(_Buf + (uint)(*_Digits == 0x2d) + (uint)(0 < (int)_SizeInBytes),_SizeInBytes + 1,
              (int)_Digits,unaff_EBP);
  }
  else {
    __shift(_Buf + (*DAT_0043782c == 0x2d),(uint)(0 < (int)_SizeInBytes));
  }
  pcVar1 = _Buf;
  if (*_Digits == 0x2d) {
    pcVar1 = _Buf + 1;
    *_Buf = '-';
  }
  pcVar2 = pcVar1;
  if (0 < (int)_SizeInBytes) {
    pcVar2 = pcVar1 + 1;
    *pcVar1 = *pcVar2;
    *pcVar2 = DAT_00434eb8;
  }
  bVar4 = DAT_00434820 == '\0';
  *(undefined4 *)(pcVar2 + _SizeInBytes + bVar4) = DAT_0043482c;
  *(undefined2 *)(pcVar2 + _SizeInBytes + bVar4 + 4) = DAT_00434830;
  pcVar2 = pcVar2 + (DAT_00434820 == '\0') + _SizeInBytes;
  if (_Dec != 0) {
    *pcVar2 = 'E';
  }
  if (*(char *)_Digits[3] != '0') {
    iVar3 = _Digits[1] + -1;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
      pcVar2[1] = '-';
    }
    if (99 < iVar3) {
      pcVar2[2] = pcVar2[2] + (char)(iVar3 / 100);
      iVar3 = iVar3 % 100;
    }
    if (9 < iVar3) {
      pcVar2[3] = pcVar2[3] + (char)(iVar3 / 10);
      iVar3 = iVar3 % 10;
    }
    pcVar2[4] = pcVar2[4] + (char)iVar3;
  }
  return (errno_t)_Buf;
}



/* 0042a4e0  __cftof  251 bytes, 1 callers */

/* Library Function - Single Match
    __cftof
   
   Library: Visual Studio 1998 Release */

errno_t __cdecl __cftof(double *_Value,char *_Buf,size_t _SizeInBytes,int _Dec)

{
  int iVar1;
  int *_Digits;
  uint uVar2;
  uint uVar3;
  STRFLT unaff_EBP;
  char *pcVar4;
  char *pcVar5;
  
  _Digits = DAT_0043782c;
  if (DAT_00434820 == '\0') {
    _Digits = (int *)__fltout();
    __fptostr(_Buf + (*_Digits == 0x2d),_Digits[1] + _SizeInBytes,(int)_Digits,unaff_EBP);
  }
  else if (DAT_00434824 == _SizeInBytes) {
    iVar1 = DAT_00434824 + (*DAT_0043782c == 0x2d);
    _Buf[iVar1] = '0';
    (_Buf + iVar1)[1] = '\0';
  }
  pcVar5 = _Buf;
  if (*_Digits == 0x2d) {
    pcVar5 = _Buf + 1;
    *_Buf = '-';
  }
  if (_Digits[1] < 1) {
    pcVar4 = pcVar5 + 1;
    __shift(pcVar5,1);
    *pcVar5 = '0';
  }
  else {
    pcVar4 = pcVar5 + _Digits[1];
  }
  if (0 < (int)_SizeInBytes) {
    __shift(pcVar4,1);
    *pcVar4 = DAT_00434eb8;
    iVar1 = _Digits[1];
    if (iVar1 < 0) {
      if (DAT_00434820 == '\0') {
        uVar3 = -iVar1;
        if ((int)_SizeInBytes <= -iVar1) {
          uVar3 = _SizeInBytes;
        }
      }
      else {
        uVar3 = -iVar1;
      }
      __shift(pcVar4 + 1,uVar3);
      uVar2 = uVar3 >> 2;
      pcVar5 = pcVar4 + 1;
      while (uVar2 != 0) {
        uVar2 = uVar2 - 1;
        builtin_strncpy(pcVar5,"0000",4);
        pcVar5 = pcVar5 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar5 = '0';
        pcVar5 = pcVar5 + 1;
      }
    }
  }
  return (errno_t)_Buf;
}



/* 0042a5e0  FUN_0042a5e0  176 bytes, 0 callers */

void __cdecl FUN_0042a5e0(double *param_1,char *param_2,size_t param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  STRFLT unaff_EBP;
  bool bVar5;
  
  DAT_0043782c = (int *)__fltout();
  DAT_00434824 = DAT_0043782c[1] + -1;
  iVar1 = *DAT_0043782c;
  __fptostr(param_2 + (iVar1 == 0x2d),param_3,(int)DAT_0043782c,unaff_EBP);
  DAT_00434828 = DAT_00434824 < DAT_0043782c[1] + -1;
  iVar3 = DAT_0043782c[1] + -1;
  if ((-5 < iVar3) && (iVar3 < (int)param_3)) {
    bVar5 = DAT_00434824 < DAT_0043782c[1] + -1;
    pcVar2 = param_2 + (iVar1 == 0x2d);
    DAT_00434824 = iVar3;
    if (bVar5) {
      do {
        pcVar4 = pcVar2;
        pcVar2 = pcVar4 + 1;
      } while (*pcVar4 != '\0');
      pcVar4[-1] = '\0';
    }
    __cftof_g(param_1,param_2,param_3);
    return;
  }
  DAT_00434824 = iVar3;
  __cftoe_g(param_1,param_2,param_3,param_4);
  return;
}



/* 0042a690  __cftoe_g  43 bytes, 1 callers */

/* Library Function - Single Match
    __cftoe_g
   
   Library: Visual Studio 1998 Release */

void __cdecl __cftoe_g(double *param_1,char *param_2,size_t param_3,int param_4)

{
  int unaff_retaddr;
  
  DAT_00434820 = 1;
  __cftoe(param_1,param_2,param_3,param_4,unaff_retaddr);
  DAT_00434820 = 0;
  return;
}



/* 0042a6c0  __cftof_g  38 bytes, 1 callers */

/* Library Function - Single Match
    __cftof_g
   
   Library: Visual Studio 1998 Release */

void __cdecl __cftof_g(double *param_1,char *param_2,size_t param_3)

{
  int unaff_retaddr;
  
  DAT_00434820 = 1;
  __cftof(param_1,param_2,param_3,unaff_retaddr);
  DAT_00434820 = 0;
  return;
}



/* 0042a760  __shift  43 bytes, 2 callers */

/* Library Function - Single Match
    __shift
   
   Library: Visual Studio 1998 Release */

void __cdecl __shift(char *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  if (param_2 != 0) {
    uVar2 = 0xffffffff;
    pcVar3 = param_1;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FID_conflict__memcpy(param_1 + param_2,param_1,~uVar2);
  }
  return;
}



/* 0042a790  FUN_0042a790  328 bytes, 2 callers */

uint __cdecl FUN_0042a790(uint param_1,FILE *param_2)

{
  uint uVar1;
  FILE *_File;
  byte bVar2;
  undefined3 extraout_var;
  undefined *puVar3;
  uint uVar4;
  uint uVar5;
  
  _File = param_2;
  uVar1 = param_2->_file;
  uVar4 = param_2->_flag;
  if (((uVar4 & 0x82) == 0) || ((uVar4 & 0x40) != 0)) {
    param_2->_flag = uVar4 | 0x20;
    return 0xffffffff;
  }
  if ((uVar4 & 1) != 0) {
    param_2->_cnt = 0;
    if ((param_2->_flag & 0x10U) == 0) {
      param_2->_flag = param_2->_flag | 0x20;
      return 0xffffffff;
    }
    param_2->_ptr = param_2->_base;
    param_2->_flag = param_2->_flag & 0xfffffffe;
  }
  uVar4 = param_2->_flag;
  uVar5 = 0;
  param_2->_flag = uVar4 | 2;
  param_2->_flag = uVar4 & 0xffffffef | 2;
  param_2->_cnt = 0;
  if ((param_2->_flag & 0x10cU) == 0) {
    if ((param_2 == (FILE *)&DAT_00435120) || (param_2 == (FILE *)&DAT_00435140)) {
      bVar2 = FUN_0042d4d0(uVar1);
      if (CONCAT31(extraout_var,bVar2) != 0) goto LAB_0042a814;
    }
    __getbuf(_File);
  }
LAB_0042a814:
  if ((_File->_flag & 0x108U) == 0) {
    uVar4 = 1;
    uVar5 = FUN_0042d190(uVar1,(char *)&param_1,1);
  }
  else {
    uVar4 = (int)_File->_ptr - (int)_File->_base;
    _File->_ptr = _File->_base + 1;
    _File->_cnt = _File->_bufsiz + -1;
    if ((int)uVar4 < 1) {
      puVar3 = &DAT_00434b50;
      if (uVar1 != 0xffffffff) {
        puVar3 = (undefined *)
                 (*(int *)((int)&DAT_00438990 + ((int)(uVar1 & 0xffffffe7) >> 3)) +
                 (uVar1 & 0x1f) * 8);
      }
      if ((puVar3[4] & 0x20) != 0) {
        FUN_0042d3c0(uVar1,0,2);
      }
    }
    else {
      uVar5 = FUN_0042d190(uVar1,_File->_base,uVar4);
    }
    *_File->_base = (char)param_1;
  }
  if (uVar4 != uVar5) {
    _File->_flag = _File->_flag | 0x20;
    return 0xffffffff;
  }
  return param_1 & 0xff;
}



/* 0042a8e0  FUN_0042a8e0  2255 bytes, 1 callers */

int __cdecl FUN_0042a8e0(FILE *param_1,byte *param_2,undefined4 *param_3)

{
  char cVar1;
  byte *pbVar2;
  wchar_t wVar3;
  uint uVar4;
  wchar_t *pwVar5;
  int iVar6;
  short *psVar7;
  int *piVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  byte bVar12;
  undefined1 *puVar13;
  wchar_t *pwVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  char *pcVar17;
  undefined8 uVar18;
  char local_248 [2];
  char local_246;
  char local_245;
  char local_244 [4];
  wchar_t *local_240;
  int local_23c;
  undefined8 local_238;
  int local_230;
  undefined8 local_22c;
  int local_224;
  int local_220;
  int local_21c;
  int local_218;
  int local_214;
  int local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined1 uStack_1;
  
  local_230 = 0;
  bVar12 = *param_2;
  local_218 = 0;
  pbVar2 = param_2;
  puVar15 = local_200;
  puVar16 = local_200;
  do {
    if ((bVar12 == 0) || (param_2 = pbVar2 + 1, local_230 < 0)) {
      return local_230;
    }
    if (((char)bVar12 < ' ') || ('x' < (char)bVar12)) {
      uVar4 = 0;
    }
    else {
      uVar4 = (byte)(&DAT_00430a38)[(char)bVar12] & 0xf;
    }
    local_218 = (int)((char)(&DAT_00430a58)[uVar4 * 8 + local_218] >> 4);
    switch(local_218) {
    case 0:
switchD_0042a961_caseD_0:
      local_21c = 0;
      if ((PTR_DAT_00434ec0[(uint)bVar12 * 2 + 1] & 0x80) != 0) {
        write_char((int)(char)bVar12,param_1,&local_230);
        bVar12 = *param_2;
        param_2 = pbVar2 + 2;
      }
      write_char((int)(char)bVar12,param_1,&local_230);
      break;
    case 1:
      local_20c = 0;
      local_210 = 0;
      local_224 = 0;
      local_220 = 0;
      local_23c = -1;
      puVar15 = (undefined1 *)0x0;
      local_21c = 0;
      break;
    case 2:
      switch(bVar12) {
      case 0x20:
        puVar15 = (undefined1 *)((uint)puVar15 | 2);
        break;
      case 0x23:
        puVar15 = (undefined1 *)((uint)puVar15 | 0x80);
        break;
      case 0x2b:
        puVar15 = (undefined1 *)((uint)puVar15 | 1);
        break;
      case 0x2d:
        puVar15 = (undefined1 *)((uint)puVar15 | 4);
        break;
      case 0x30:
        puVar15 = (undefined1 *)((uint)puVar15 | 8);
      }
      break;
    case 3:
      if (bVar12 == 0x2a) {
        local_224 = FUN_0042b390((int *)&param_3);
        if (local_224 < 0) {
          local_224 = -local_224;
          puVar15 = (undefined1 *)((uint)puVar15 | 4);
        }
      }
      else {
        local_224 = (char)bVar12 + -0x30 + local_224 * 10;
      }
      break;
    case 4:
      local_23c = 0;
      break;
    case 5:
      if (bVar12 == 0x2a) {
        local_23c = FUN_0042b390((int *)&param_3);
        if (local_23c < 0) {
          local_23c = -1;
        }
      }
      else {
        local_23c = (char)bVar12 + -0x30 + local_23c * 10;
      }
      break;
    case 6:
      switch(bVar12) {
      case 0x49:
        if ((*param_2 != 0x36) || (pbVar2[2] != 0x34)) {
          local_218 = 0;
          goto switchD_0042a961_caseD_0;
        }
        param_2 = pbVar2 + 3;
        puVar15 = (undefined1 *)((uint)puVar15 | 0x8000);
        break;
      case 0x68:
        puVar15 = (undefined1 *)((uint)puVar15 | 0x20);
        break;
      case 0x6c:
        puVar15 = (undefined1 *)((uint)puVar15 | 0x10);
        break;
      case 0x77:
        puVar15 = (undefined1 *)((uint)puVar15 | 0x800);
      }
      break;
    case 7:
      pwVar14 = local_240;
      switch(bVar12) {
      case 0x43:
        if (((uint)puVar15 & 0x830) == 0) {
          puVar15 = (undefined1 *)((uint)puVar15 | 0x800);
        }
      case 99:
        if (((uint)puVar15 & 0x810) == 0) {
          puVar16 = (undefined1 *)0x1;
          uVar9 = FUN_0042b390((int *)&param_3);
          local_200 = (undefined1 *)CONCAT31(local_200._1_3_,(char)uVar9);
        }
        else {
          wVar3 = FUN_0042b3c0(&param_3);
          puVar16 = (undefined1 *)_wctomb((char *)&local_200,wVar3);
          if ((int)puVar16 < 0) {
            local_210 = 1;
          }
        }
        pwVar14 = (wchar_t *)&local_200;
        break;
      case 0x45:
      case 0x47:
        local_20c = 1;
        bVar12 = bVar12 + 0x20;
      case 0x65:
      case 0x66:
      case 0x67:
        puVar13 = (undefined1 *)((uint)puVar15 | 0x40);
        local_240 = (wchar_t *)&local_200;
        if (local_23c < 0) {
          local_23c = 6;
        }
        else if ((local_23c == 0) && (bVar12 == 0x67)) {
          local_23c = 1;
        }
        local_208 = *param_3;
        local_204 = param_3[1];
        param_3 = param_3 + 2;
        (*(code *)PTR_FUN_00434808)(&local_208,&local_200,(int)(char)bVar12,local_23c,local_20c);
        if ((((uint)puVar15 & 0x80) != 0) && (local_23c == 0)) {
          (*(code *)PTR_FUN_00434814)(&local_200);
        }
        if ((bVar12 == 0x67) && (((uint)puVar15 & 0x80) == 0)) {
          (*(code *)PTR_FUN_0043480c)(&local_200);
        }
        if ((char)local_200 == '-') {
          puVar13 = (undefined1 *)((uint)puVar15 | 0x140);
          local_240 = (wchar_t *)((int)&local_200 + 1);
        }
        uVar4 = 0xffffffff;
        pwVar14 = local_240;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          wVar3 = *pwVar14;
          pwVar14 = (wchar_t *)((int)pwVar14 + 1);
        } while ((char)wVar3 != '\0');
        puVar16 = (undefined1 *)(~uVar4 - 1);
        puVar15 = puVar13;
        pwVar14 = local_240;
        break;
      case 0x53:
        if (((uint)puVar15 & 0x830) == 0) {
          puVar15 = (undefined1 *)((uint)puVar15 | 0x800);
        }
      case 0x73:
        iVar11 = 0x7fffffff;
        if (local_23c != -1) {
          iVar11 = local_23c;
        }
        local_240 = (wchar_t *)FUN_0042b390((int *)&param_3);
        if (((uint)puVar15 & 0x810) == 0) {
          pwVar14 = local_240;
          if (local_240 == (wchar_t *)0x0) {
            local_240 = (wchar_t *)PTR_DAT_0043484c;
            pwVar14 = (wchar_t *)PTR_DAT_0043484c;
          }
          for (; (iVar11 != 0 && (iVar11 = iVar11 + -1, (char)*pwVar14 != '\0'));
              pwVar14 = (wchar_t *)((int)pwVar14 + 1)) {
          }
          puVar16 = (undefined1 *)((int)pwVar14 - (int)local_240);
          pwVar14 = local_240;
        }
        else {
          pwVar5 = local_240;
          if (local_240 == (wchar_t *)0x0) {
            pwVar5 = (wchar_t *)PTR_DAT_00434850;
          }
          puVar16 = (undefined1 *)0x0;
          local_21c = 1;
          pwVar14 = pwVar5;
          local_240 = pwVar5;
          if (0 < iVar11) {
            do {
              pwVar14 = local_240;
              if ((*pwVar5 == L'\0') ||
                 (iVar6 = _wctomb(local_248,*pwVar5), pwVar14 = local_240, iVar6 == 0)) break;
              puVar16 = puVar16 + iVar6;
              pwVar5 = pwVar5 + 1;
            } while ((int)puVar16 < iVar11);
          }
        }
        break;
      case 0x5a:
        psVar7 = (short *)FUN_0042b390((int *)&param_3);
        if ((psVar7 == (short *)0x0) ||
           (pwVar14 = *(wchar_t **)(psVar7 + 2), pwVar14 == (wchar_t *)0x0)) {
          uVar4 = 0xffffffff;
          local_240 = (wchar_t *)PTR_DAT_0043484c;
          pcVar17 = PTR_DAT_0043484c;
          do {
            if (uVar4 == 0) break;
            uVar4 = uVar4 - 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar17 + 1;
          } while (cVar1 != '\0');
          puVar16 = (undefined1 *)(~uVar4 - 1);
          pwVar14 = local_240;
        }
        else if (((uint)puVar15 & 0x800) == 0) {
          local_21c = 0;
          puVar16 = (undefined1 *)(int)*psVar7;
        }
        else {
          local_21c = 1;
          puVar16 = (undefined1 *)((uint)(int)*psVar7 >> 1);
        }
        break;
      case 100:
      case 0x69:
        puVar15 = (undefined1 *)((uint)puVar15 | 0x40);
        uVar4 = 10;
        goto LAB_0042ad74;
      case 0x6e:
        piVar8 = (int *)FUN_0042b390((int *)&param_3);
        if (((uint)puVar15 & 0x20) == 0) {
          *piVar8 = local_230;
        }
        else {
          *(short *)piVar8 = (short)local_230;
        }
        local_210 = 1;
        pwVar14 = local_240;
        break;
      case 0x6f:
        uVar4 = 8;
        if (((uint)puVar15 & 0x80) != 0) {
          puVar15 = (undefined1 *)((uint)puVar15 | 0x200);
        }
        goto LAB_0042ad74;
      case 0x70:
        local_23c = 8;
      case 0x58:
        local_214 = 7;
        goto LAB_0042ad50;
      case 0x75:
        uVar4 = 10;
        goto LAB_0042ad74;
      case 0x78:
        local_214 = 0x27;
LAB_0042ad50:
        uVar4 = 0x10;
        if (((uint)puVar15 & 0x80) != 0) {
          local_246 = '0';
          local_220 = 2;
          local_245 = (char)local_214 + 'Q';
        }
LAB_0042ad74:
        if (((uint)puVar15 & 0x8000) == 0) {
          if (((uint)puVar15 & 0x20) == 0) {
            if (((uint)puVar15 & 0x40) == 0) {
              uVar10 = FUN_0042b390((int *)&param_3);
              goto LAB_0042ae10;
            }
            iVar11 = FUN_0042b390((int *)&param_3);
            local_238 = (ulonglong)iVar11;
          }
          else if (((uint)puVar15 & 0x40) == 0) {
            uVar10 = FUN_0042b390((int *)&param_3);
            uVar10 = uVar10 & 0xffff;
LAB_0042ae10:
            local_238 = (ulonglong)uVar10;
          }
          else {
            uVar9 = FUN_0042b390((int *)&param_3);
            local_238 = (ulonglong)(int)(short)uVar9;
          }
        }
        else {
          local_238 = FUN_0042b3a0((int *)&param_3);
        }
        if (((((uint)puVar15 & 0x40) == 0) || (0 < (int)local_238._4_4_)) ||
           (-1 < (longlong)local_238)) {
          local_22c = local_238;
        }
        else {
          puVar15 = (undefined1 *)((uint)puVar15 | 0x100);
          local_22c = CONCAT44(-(local_238._4_4_ + ((uint)local_238 != 0)),-(uint)local_238);
        }
        if (((uint)puVar15 & 0x8000) == 0) {
          local_22c = local_22c & 0xffffffff;
        }
        if (local_23c < 0) {
          local_23c = 1;
        }
        else {
          puVar15 = (undefined1 *)((uint)puVar15 & 0xfffffff7);
        }
        pwVar14 = (wchar_t *)register0x00000010;
        if ((local_22c._4_4_ == 0) && ((uint)local_22c == 0)) {
          local_220 = 0;
        }
        while( true ) {
          local_240 = (wchar_t *)((int)pwVar14 + -1);
          iVar11 = local_23c + -1;
          if (((local_23c < 1) && (local_22c._4_4_ == 0)) && ((uint)local_22c == 0)) break;
          local_238 = (ulonglong)uVar4;
          local_23c = iVar11;
          uVar18 = __aullrem((uint)local_22c,local_22c._4_4_,uVar4,0);
          iVar11 = (int)uVar18 + 0x30;
          local_22c = __aulldiv((uint)local_22c,local_22c._4_4_,(uint)local_238,local_238._4_4_);
          if (0x39 < iVar11) {
            iVar11 = iVar11 + local_214;
          }
          *(char *)local_240 = (char)iVar11;
          pwVar14 = local_240;
        }
        puVar16 = &uStack_1 + -(int)local_240;
        local_23c = iVar11;
        if ((((uint)puVar15 & 0x200) != 0) &&
           (((char)*pwVar14 != '0' || (puVar16 == (undefined1 *)0x0)))) {
          puVar16 = &stack0x00000000 + -(int)local_240;
          *(char *)local_240 = '0';
          pwVar14 = local_240;
        }
      }
      local_240 = pwVar14;
      if (local_210 == 0) {
        if (((uint)puVar15 & 0x40) != 0) {
          if (((uint)puVar15 & 0x100) == 0) {
            if (((uint)puVar15 & 1) == 0) {
              if (((uint)puVar15 & 2) == 0) goto LAB_0042b09a;
              local_246 = ' ';
            }
            else {
              local_246 = '+';
            }
          }
          else {
            local_246 = '-';
          }
          local_220 = 1;
        }
LAB_0042b09a:
        iVar11 = (local_224 - (int)puVar16) - local_220;
        local_238 = CONCAT44(local_238._4_4_,iVar11);
        if (((uint)puVar15 & 0xc) == 0) {
          write_multi_char(0x20,iVar11,param_1,&local_230);
        }
        write_string(&local_246,local_220,param_1,&local_230);
        if ((((uint)puVar15 & 8) != 0) && (((uint)puVar15 & 4) == 0)) {
          write_multi_char(0x30,(uint)local_238,param_1,&local_230);
        }
        if ((local_21c == 0) || (pwVar14 = local_240, puVar13 = puVar16, (int)puVar16 < 1)) {
          write_string((char *)local_240,(int)puVar16,param_1,&local_230);
        }
        else {
          do {
            puVar13 = puVar13 + -1;
            iVar11 = _wctomb(local_244,*pwVar14);
            if (iVar11 < 1) break;
            write_string(local_244,iVar11,param_1,&local_230);
            pwVar14 = pwVar14 + 1;
          } while (puVar13 != (undefined1 *)0x0);
        }
        if (((uint)puVar15 & 4) != 0) {
          write_multi_char(0x20,(uint)local_238,param_1,&local_230);
        }
      }
    }
    bVar12 = *param_2;
    pbVar2 = param_2;
  } while( true );
}



/* 0042b2c0  write_char  65 bytes, 3 callers */

/* Library Function - Single Match
    _write_char
   
   Library: Visual Studio 1998 Release */

void __cdecl write_char(uint param_1,FILE *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_2->_cnt + -1;
  param_2->_cnt = iVar1;
  if (iVar1 < 0) {
    uVar2 = FUN_0042a790(param_1,param_2);
  }
  else {
    *param_2->_ptr = (char)param_1;
    uVar2 = (uint)(byte)*param_2->_ptr;
    param_2->_ptr = param_2->_ptr + 1;
  }
  if (uVar2 == 0xffffffff) {
    *param_3 = -1;
    return;
  }
  *param_3 = *param_3 + 1;
  return;
}



/* 0042b310  write_multi_char  49 bytes, 1 callers */

/* Library Function - Single Match
    _write_multi_char
   
   Library: Visual Studio 1998 Release */

void __cdecl write_multi_char(uint param_1,int param_2,FILE *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    write_char(param_1,param_3,param_4);
    param_2 = param_2 + -1;
  } while (*param_4 != -1);
  return;
}



/* 0042b350  write_string  55 bytes, 1 callers */

/* Library Function - Single Match
    _write_string
   
   Library: Visual Studio 1998 Release */

void __cdecl write_string(char *param_1,int param_2,FILE *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    write_char((int)*param_1,param_3,param_4);
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
  } while (*param_4 != -1);
  return;
}



/* 0042b390  FUN_0042b390  15 bytes, 1 callers */

undefined4 __cdecl FUN_0042b390(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}



/* 0042b3a0  FUN_0042b3a0  21 bytes, 1 callers */

undefined8 __cdecl FUN_0042b3a0(int *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}



/* 0042b3c0  FUN_0042b3c0  16 bytes, 1 callers */

undefined2 __cdecl FUN_0042b3c0(undefined4 *param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)*param_1;
  *param_1 = puVar1 + 2;
  return *puVar1;
}



/* 0042b495  FUN_0042b495  27 bytes, 0 callers */

void FUN_0042b495(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}



/* 0042b4b0  FUN_0042b4b0  48 bytes, 1 callers */

void FUN_0042b4b0(void)

{
  if (PTR___fpmath_004345f8 != (undefined *)0x0) {
    (*(code *)PTR___fpmath_004345f8)();
  }
  FUN_0042b5a0((undefined4 *)&DAT_00432044,(undefined4 *)&DAT_00432050);
  FUN_0042b5a0((undefined4 *)&DAT_00432000,(undefined4 *)&DAT_00432040);
  return;
}



/* 0042b4e0  FUN_0042b4e0  18 bytes, 1 callers */

void __cdecl FUN_0042b4e0(UINT param_1)

{
  FUN_0042b520(param_1,0,0);
  return;
}



/* 0042b500  __exit  18 bytes, 3 callers */

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __exit(int _Code)

{
  FUN_0042b520(_Code,1,0);
  return;
}



/* 0042b520  FUN_0042b520  128 bytes, 2 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042b520(UINT param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  
  _DAT_00434898 = 1;
  DAT_00434894 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_00438a94 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_00438a90 + -4), DAT_00438a94 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_00438a94 <= puVar1);
    }
    FUN_0042b5a0((undefined4 *)&DAT_00432054,(undefined4 *)&DAT_0043205c);
  }
  FUN_0042b5a0((undefined4 *)&DAT_00432060,(undefined4 *)&DAT_00432064);
  if (param_3 == 0) {
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  return;
}



/* 0042b5a0  FUN_0042b5a0  32 bytes, 2 callers */

void __cdecl FUN_0042b5a0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 0042b5c0  FUN_0042b5c0  111 bytes, 1 callers */

LPVOID __cdecl FUN_0042b5c0(LPVOID param_1,uint param_2)

{
  LPVOID pvVar1;
  int iVar2;
  
  if (param_1 == (LPVOID)0x0) {
    pvVar1 = (LPVOID)FUN_0042a050(param_2);
    return pvVar1;
  }
  if (param_2 != 0) {
    do {
      if (param_2 < 0xffffffe1) {
        pvVar1 = HeapReAlloc(DAT_00438980,0,param_1,param_2);
      }
      else {
        pvVar1 = (LPVOID)0x0;
      }
      if (pvVar1 != (LPVOID)0x0) {
        return pvVar1;
      }
      if (DAT_00434eb0 == 0) {
        return (LPVOID)0x0;
      }
      iVar2 = FUN_0042c740(param_2);
    } while (iVar2 != 0);
    return (LPVOID)0x0;
  }
  FUN_0042a030(param_1);
  return (LPVOID)0x0;
}



/* 0042b630  FUN_0042b630  21 bytes, 1 callers */

void __cdecl FUN_0042b630(LPCVOID param_1)

{
  HeapSize(DAT_00438980,0,param_1);
  return;
}



/* 0042b650  __mbsnbcpy  134 bytes, 1 callers */

/* Library Function - Single Match
    __mbsnbcpy
   
   Library: Visual Studio 1998 Release */

uchar * __cdecl __mbsnbcpy(uchar *_Dest,uchar *_Source,size_t _Count)

{
  byte bVar1;
  uchar *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  size_t sVar5;
  
  pbVar4 = _Dest;
  if (DAT_004349a4 == 0) {
    puVar2 = (uchar *)FUN_0042d780((char *)_Dest,(char *)_Source,_Count);
    return puVar2;
  }
  do {
    while( true ) {
      pbVar3 = pbVar4;
      pbVar4 = pbVar3;
      sVar5 = _Count;
      if (_Count == 0) goto joined_r0x0042b6b3;
      sVar5 = _Count - 1;
      bVar1 = *_Source;
      if ((*(byte *)((int)&DAT_004348a0 + bVar1 + 1) & 4) == 0) break;
      *pbVar3 = bVar1;
      pbVar4 = pbVar3 + 1;
      if (sVar5 == 0) {
        *pbVar3 = 0;
        goto joined_r0x0042b6b3;
      }
      bVar1 = _Source[1];
      sVar5 = _Count - 2;
      *pbVar4 = bVar1;
      pbVar4 = pbVar3 + 2;
      _Source = _Source + 2;
      _Count = sVar5;
      if (bVar1 == 0) {
        *pbVar3 = 0;
        goto joined_r0x0042b6b3;
      }
    }
    *pbVar3 = bVar1;
    pbVar4 = pbVar3 + 1;
    _Source = _Source + 1;
    _Count = sVar5;
  } while (bVar1 != 0);
joined_r0x0042b6b3:
  for (; sVar5 != 0; sVar5 = sVar5 - 1) {
    *pbVar4 = 0;
    pbVar4 = pbVar4 + 1;
  }
  return _Dest;
}



/* 0042b6e0  FUN_0042b6e0  475 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0042b6e0(int param_1)

{
  byte *pbVar1;
  byte bVar2;
  UINT CodePage;
  UINT *pUVar3;
  BOOL BVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  BYTE *pBVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  int local_18;
  _cpinfo local_14;
  
  CodePage = getSystemCP(param_1);
  if (DAT_004349a4 == CodePage) {
    return 0;
  }
  if (CodePage == 0) {
    setSBCS();
    return 0;
  }
  local_18 = 0;
  pUVar3 = &DAT_004349c8;
  do {
    if (*pUVar3 == CodePage) {
      uVar5 = 0;
      puVar10 = &DAT_004348a0;
      for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined1 *)puVar10 = 0;
      do {
        pbVar9 = &DAT_004349d8 + (uVar5 + local_18 * 6) * 8;
        bVar2 = *pbVar9;
        while ((bVar2 != 0 && (pbVar9[1] != 0))) {
          uVar7 = (uint)*pbVar9;
          if (uVar7 <= pbVar9[1]) {
            bVar2 = (&DAT_004349c0)[uVar5];
            do {
              pbVar1 = (byte *)((int)&DAT_004348a0 + uVar7 + 1);
              *pbVar1 = *pbVar1 | bVar2;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= pbVar9[1]);
          }
          pbVar9 = pbVar9 + 2;
          bVar2 = *pbVar9;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < 4);
      DAT_004349a4 = CodePage;
      _DAT_004349a8 = _CPtoLCID(CodePage);
      DAT_004349b0 = *(undefined4 *)(&DAT_004349cc + local_18 * 0x30);
      DAT_004349b4 = *(undefined4 *)(&DAT_004349d0 + local_18 * 0x30);
      DAT_004349b8 = *(undefined4 *)(local_18 * 0x30 + 0x4349d4);
      return 0;
    }
    pUVar3 = pUVar3 + 0xc;
    local_18 = local_18 + 1;
  } while (pUVar3 < &DAT_00434ab8);
  BVar4 = GetCPInfo(CodePage,&local_14);
  if (BVar4 == 1) {
    puVar10 = &DAT_004348a0;
    for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined1 *)puVar10 = 0;
    if (local_14.MaxCharSize < 2) {
      _DAT_004349a8 = 0;
      DAT_004349a4 = 0;
    }
    else {
      pBVar8 = local_14.LeadByte;
      while ((local_14.LeadByte[0] != 0 && (pBVar8[1] != 0))) {
        uVar5 = (uint)*pBVar8;
        if (uVar5 <= pBVar8[1]) {
          do {
            pbVar9 = (byte *)((int)&DAT_004348a0 + uVar5 + 1);
            *pbVar9 = *pbVar9 | 4;
            uVar5 = uVar5 + 1;
          } while (uVar5 <= pBVar8[1]);
        }
        pBVar8 = pBVar8 + 2;
        local_14.LeadByte[0] = *pBVar8;
      }
      uVar5 = 1;
      do {
        pbVar9 = (byte *)((int)&DAT_004348a0 + uVar5 + 1);
        *pbVar9 = *pbVar9 | 8;
        uVar5 = uVar5 + 1;
      } while (uVar5 < 0xff);
      DAT_004349a4 = CodePage;
      _DAT_004349a8 = _CPtoLCID(CodePage);
    }
    DAT_004349b0 = 0;
    DAT_004349b4 = 0;
    DAT_004349b8 = 0;
    return 0;
  }
  if (DAT_004349bc == 0) {
    return 0xffffffff;
  }
  setSBCS();
  return 0;
}



/* 0042b8c0  getSystemCP  77 bytes, 1 callers */

/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Release */

int __cdecl getSystemCP(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_004349bc = 1;
                    /* WARNING: Could not recover jumptable at 0x0042b8dd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_004349bc = 1;
                    /* WARNING: Could not recover jumptable at 0x0042b8f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_004353a0;
  }
  DAT_004349bc = (uint)bVar2;
  return param_1;
}



/* 0042b910  _CPtoLCID  56 bytes, 1 callers */

/* Library Function - Single Match
    _CPtoLCID
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl _CPtoLCID(undefined4 param_1)

{
  switch(param_1) {
  case 0x3a4:
    return 0x411;
  default:
    return 0;
  case 0x3a8:
    return 0x804;
  case 0x3b5:
    return 0x412;
  case 0x3b6:
    return 0x404;
  }
}



/* 0042b970  setSBCS  44 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_004348a0;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_004349b0 = 0;
  DAT_004349a4 = 0;
  _DAT_004349a8 = 0;
  DAT_004349b4 = 0;
  DAT_004349b8 = 0;
  return;
}



/* 0042b9a0  FUN_0042b9a0  11 bytes, 1 callers */

void FUN_0042b9a0(void)

{
  FUN_0042b6e0(-3);
  return;
}



/* 0042bb40  __ismbblead  18 bytes, 1 callers */

/* Library Function - Single Match
    __ismbblead
   
   Library: Visual Studio 1998 Release */

int __cdecl __ismbblead(uint _C)

{
  int iVar1;
  
  iVar1 = x_ismbbtype((byte)_C,0,4);
  return iVar1;
}



/* 0042bb60  x_ismbbtype  58 bytes, 1 callers */

/* Library Function - Single Match
    _x_ismbbtype
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl x_ismbbtype(byte param_1,uint param_2,byte param_3)

{
  uint uVar1;
  
  if ((param_3 & *(byte *)((int)&DAT_004348a0 + param_1 + 1)) == 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = *(ushort *)(&DAT_00434eca + (uint)param_1 * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}



/* 0042bba0  FUN_0042bba0  219 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042bba0(void)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  
  iVar7 = 0;
  cVar1 = *DAT_00434770;
  pcVar6 = DAT_00434770;
  while (cVar1 != '\0') {
    if (*pcVar6 != '=') {
      iVar7 = iVar7 + 1;
    }
    uVar3 = 0xffffffff;
    pcVar9 = pcVar6;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    pcVar6 = pcVar6 + ~uVar3;
    cVar1 = *pcVar6;
  }
  piVar2 = (int *)FUN_0042a050(iVar7 * 4 + 4);
  _DAT_0043487c = piVar2;
  if (piVar2 == (int *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *DAT_00434770;
  pcVar6 = DAT_00434770;
  do {
    if (cVar1 == '\0') {
      FUN_0042a030(DAT_00434770);
      *piVar2 = 0;
      return;
    }
    uVar3 = 0xffffffff;
    pcVar9 = pcVar6;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    if (*pcVar6 != '=') {
      iVar7 = FUN_0042a050(~uVar3);
      *piVar2 = iVar7;
      if (iVar7 == 0) {
        __amsg_exit(9);
      }
      uVar4 = 0xffffffff;
      pcVar9 = pcVar6;
      do {
        pcVar8 = pcVar9;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar8 = pcVar9 + 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar8;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      pcVar9 = (char *)*piVar2;
      piVar2 = piVar2 + 1;
      pcVar8 = pcVar8 + -uVar4;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
    }
    pcVar6 = pcVar6 + ~uVar3;
    cVar1 = *pcVar6;
  } while( true );
}



/* 0042bc80  __setargv  155 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setargv
   
   Library: Visual Studio 1998 Release */

int __cdecl __setargv(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_8;
  int local_4;
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_00437830,0x104);
  _DAT_0043488c = &DAT_00437830;
  pbVar2 = &DAT_00437830;
  if (*DAT_00438a98 != 0) {
    pbVar2 = DAT_00438a98;
  }
  parse_cmdline(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = (undefined4 *)FUN_0042a050(local_8 * 4 + local_4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_00434874 = puVar1;
  _DAT_00434870 = local_8 + -1;
  return local_8 + -1;
}



/* 0042bd20  parse_cmdline  466 bytes, 1 callers */

/* Library Function - Single Match
    _parse_cmdline
   
   Library: Visual Studio 1998 Release */

void __cdecl
parse_cmdline(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  
  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  if (*param_1 == 0x22) {
    pbVar6 = param_1 + 1;
    bVar1 = *pbVar6;
    while ((bVar1 != 0x22 && (*pbVar6 != 0))) {
      if (((*(byte *)((int)&DAT_004348a0 + *pbVar6 + 1) & 4) != 0) &&
         (*param_5 = *param_5 + 1, param_3 != (byte *)0x0)) {
        bVar1 = *pbVar6;
        pbVar6 = pbVar6 + 1;
        *param_3 = bVar1;
        param_3 = param_3 + 1;
      }
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *pbVar6;
        param_3 = param_3 + 1;
      }
      pbVar6 = pbVar6 + 1;
      bVar1 = *pbVar6;
    }
    *param_5 = *param_5 + 1;
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    if (*pbVar6 == 0x22) {
      pbVar6 = pbVar6 + 1;
    }
  }
  else {
    do {
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      bVar1 = *param_1;
      pbVar6 = param_1 + 1;
      if ((*(byte *)((int)&DAT_004348a0 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar6;
          param_3 = param_3 + 1;
        }
        pbVar6 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_0042bd90;
      param_1 = pbVar6;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_0042bd90:
      pbVar6 = pbVar6 + -1;
    }
    else if (param_3 != (byte *)0x0) {
      param_3[-1] = 0;
    }
  }
  bVar3 = false;
  while (*pbVar6 != 0) {
    for (; (*pbVar6 == 0x20 || (*pbVar6 == 9)); pbVar6 = pbVar6 + 1) {
    }
    if (*pbVar6 == 0) break;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_3;
      param_2 = param_2 + 1;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      bVar2 = true;
      uVar5 = 0;
      bVar1 = *pbVar6;
      while (bVar1 == 0x5c) {
        pbVar6 = pbVar6 + 1;
        uVar5 = uVar5 + 1;
        bVar1 = *pbVar6;
      }
      if (*pbVar6 == 0x22) {
        pbVar4 = pbVar6;
        if ((uVar5 & 1) == 0) {
          if ((!bVar3) || (pbVar4 = pbVar6 + 1, *pbVar4 != 0x22)) {
            bVar2 = false;
            pbVar4 = pbVar6;
          }
          bVar3 = !bVar3;
        }
        uVar5 = uVar5 >> 1;
        pbVar6 = pbVar4;
      }
      while (uVar5 != 0) {
        uVar5 = uVar5 - 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      bVar1 = *pbVar6;
      if ((bVar1 == 0) || ((!bVar3 && ((bVar1 == 0x20 || (bVar1 == 9)))))) break;
      if (bVar2) {
        if (param_3 == (byte *)0x0) {
          if ((*(byte *)((int)&DAT_004348a0 + bVar1 + 1) & 4) != 0) {
            pbVar6 = pbVar6 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_5 = *param_5 + 1;
          goto LAB_0042bec1;
        }
        pbVar4 = param_3;
        if ((*(byte *)((int)&DAT_004348a0 + bVar1 + 1) & 4) != 0) {
          *param_3 = bVar1;
          pbVar6 = pbVar6 + 1;
          pbVar4 = param_3 + 1;
          *param_5 = *param_5 + 1;
        }
        bVar1 = *pbVar6;
        param_3 = pbVar4 + 1;
        pbVar6 = pbVar6 + 1;
        *pbVar4 = bVar1;
        *param_5 = *param_5 + 1;
      }
      else {
LAB_0042bec1:
        pbVar6 = pbVar6 + 1;
      }
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *param_5 = *param_5 + 1;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}



/* 0042bf00  FUN_0042bf00  411 bytes, 1 callers */

LPSTR FUN_0042bf00(void)

{
  char cVar1;
  WCHAR WVar2;
  LPWCH pWVar3;
  SIZE_T cbMultiByte;
  LPSTR pCVar4;
  uint uVar5;
  LPWCH pWVar6;
  char *pcVar7;
  WCHAR *pWVar8;
  int iVar10;
  LPSTR pCVar11;
  LPWCH local_4;
  WCHAR *pWVar9;
  
  pWVar3 = local_4;
  if (DAT_00434b48 == 0) {
    pWVar3 = GetEnvironmentStringsW();
    if (pWVar3 == (LPWCH)0x0) {
      local_4 = (LPWCH)GetEnvironmentStrings();
      if (local_4 == (LPWCH)0x0) {
        return (LPSTR)0x0;
      }
      DAT_00434b48 = 2;
    }
    else {
      DAT_00434b48 = 1;
    }
  }
  if (DAT_00434b48 != 1) {
    if (DAT_00434b48 != 2) {
      return (LPSTR)0x0;
    }
    if ((local_4 == (LPWCH)0x0) && (local_4 = (LPWCH)GetEnvironmentStrings(), local_4 == (LPWCH)0x0)
       ) {
      return (LPSTR)0x0;
    }
    cVar1 = (char)*local_4;
    pWVar3 = local_4;
    while (cVar1 != '\0') {
      do {
        pWVar6 = pWVar3;
        pWVar3 = (LPWCH)((int)pWVar6 + 1);
      } while (*(char *)pWVar3 != '\0');
      pWVar3 = pWVar6 + 1;
      cVar1 = (char)*pWVar3;
    }
    pcVar7 = (char *)((int)pWVar3 + (1 - (int)local_4));
    pCVar4 = (LPSTR)FUN_0042a050((SIZE_T)pcVar7);
    if (pCVar4 == (LPSTR)0x0) {
      FreeEnvironmentStringsA((LPCH)local_4);
      return (LPSTR)0x0;
    }
    pWVar3 = local_4;
    pCVar11 = pCVar4;
    for (uVar5 = (uint)pcVar7 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pCVar11 = *(undefined4 *)pWVar3;
      pWVar3 = pWVar3 + 2;
      pCVar11 = pCVar11 + 4;
    }
    for (uVar5 = (uint)pcVar7 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pCVar11 = (CHAR)*pWVar3;
      pWVar3 = (LPWCH)((int)pWVar3 + 1);
      pCVar11 = pCVar11 + 1;
    }
    FreeEnvironmentStringsA((LPCH)local_4);
    return pCVar4;
  }
  if ((pWVar3 == (LPWCH)0x0) && (pWVar3 = GetEnvironmentStringsW(), pWVar3 == (LPWCH)0x0)) {
    return (LPSTR)0x0;
  }
  WVar2 = *pWVar3;
  pWVar8 = pWVar3;
  while (WVar2 != L'\0') {
    do {
      pWVar9 = pWVar8;
      pWVar8 = pWVar9 + 1;
    } while (*pWVar8 != L'\0');
    pWVar8 = pWVar9 + 2;
    WVar2 = *pWVar8;
  }
  iVar10 = ((int)pWVar8 - (int)pWVar3 >> 1) + 1;
  cbMultiByte = WideCharToMultiByte(0,0,pWVar3,iVar10,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
  if ((cbMultiByte != 0) && (pCVar4 = (LPSTR)FUN_0042a050(cbMultiByte), pCVar4 != (LPSTR)0x0)) {
    iVar10 = WideCharToMultiByte(0,0,pWVar3,iVar10,pCVar4,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar10 == 0) {
      FUN_0042a030(pCVar4);
      pCVar4 = (LPSTR)0x0;
    }
    FreeEnvironmentStringsW(pWVar3);
    return pCVar4;
  }
  FreeEnvironmentStringsW(pWVar3);
  return (LPSTR)0x0;
}



/* 0042c0a0  FUN_0042c0a0  467 bytes, 1 callers */

void FUN_0042c0a0(void)

{
  undefined4 *puVar1;
  DWORD DVar2;
  HANDLE hFile;
  UINT *pUVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  int iVar8;
  UINT UVar9;
  UINT UVar10;
  _STARTUPINFOA local_44;
  
  puVar1 = (undefined4 *)FUN_0042a050(0x100);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_00438984 = 0x20;
  DAT_00438990 = puVar1;
  if (puVar1 < puVar1 + 0x40) {
    do {
      *(undefined1 *)(puVar1 + 1) = 0;
      puVar6 = puVar1 + 2;
      *puVar1 = 0xffffffff;
      *(undefined1 *)((int)puVar1 + 5) = 10;
      puVar1 = puVar6;
    } while (puVar6 < DAT_00438990 + 0x40);
  }
  GetStartupInfoA(&local_44);
  if ((local_44.cbReserved2 != 0) && ((UINT *)local_44.lpReserved2 != (UINT *)0x0)) {
    UVar9 = *(UINT *)local_44.lpReserved2;
    pUVar3 = (UINT *)((int)local_44.lpReserved2 + 4);
    pbVar7 = (byte *)(UVar9 + (int)pUVar3);
    if (0x7ff < (int)UVar9) {
      UVar9 = 0x800;
    }
    UVar10 = UVar9;
    if ((int)DAT_00438984 < (int)UVar9) {
      piVar4 = &DAT_00438994;
      do {
        puVar1 = (undefined4 *)FUN_0042a050(0x100);
        UVar10 = DAT_00438984;
        if (puVar1 == (undefined4 *)0x0) break;
        *piVar4 = (int)puVar1;
        DAT_00438984 = DAT_00438984 + 0x20;
        if (puVar1 < puVar1 + 0x40) {
          do {
            *(undefined1 *)(puVar1 + 1) = 0;
            puVar6 = puVar1 + 2;
            *puVar1 = 0xffffffff;
            *(undefined1 *)((int)puVar1 + 5) = 10;
            puVar1 = puVar6;
          } while (puVar6 < (undefined4 *)(*piVar4 + 0x100));
        }
        piVar4 = piVar4 + 1;
        UVar10 = UVar9;
      } while ((int)DAT_00438984 < (int)UVar9);
    }
    uVar5 = 0;
    if (0 < (int)UVar10) {
      do {
        if (((*(HANDLE *)pbVar7 != (HANDLE)0xffffffff) && ((*pUVar3 & 1) != 0)) &&
           (DVar2 = GetFileType(*(HANDLE *)pbVar7), DVar2 != 0)) {
          puVar1 = (undefined4 *)
                   (*(int *)((int)&DAT_00438990 + ((int)(uVar5 & 0xffffffe7) >> 3)) +
                   (uVar5 & 0x1f) * 8);
          *puVar1 = *(undefined4 *)pbVar7;
          *(byte *)(puVar1 + 1) = (byte)*pUVar3;
        }
        uVar5 = uVar5 + 1;
        pUVar3 = (UINT *)((int)pUVar3 + 1);
        pbVar7 = pbVar7 + 4;
      } while ((int)uVar5 < (int)UVar10);
    }
  }
  iVar8 = 0;
  do {
    piVar4 = DAT_00438990 + iVar8 * 2;
    if (*piVar4 == -1) {
      DVar2 = 0xfffffff6;
      *(undefined1 *)(piVar4 + 1) = 0x81;
      if (iVar8 != 0) {
        DVar2 = (iVar8 == 1) - 0xc;
      }
      hFile = GetStdHandle(DVar2);
      if ((hFile == (HANDLE)0xffffffff) || (DVar2 = GetFileType(hFile), DVar2 == 0)) {
        *(byte *)(piVar4 + 1) = *(byte *)(piVar4 + 1) | 0x40;
      }
      else {
        *piVar4 = (int)hFile;
        if ((DVar2 & 0xff) == 2) {
          *(byte *)(piVar4 + 1) = *(byte *)(piVar4 + 1) | 0x40;
        }
        else if ((DVar2 & 0xff) == 3) {
          *(byte *)(piVar4 + 1) = *(byte *)(piVar4 + 1) | 8;
        }
      }
    }
    else {
      *(byte *)(piVar4 + 1) = *(byte *)(piVar4 + 1) | 0x80;
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 < 3);
  SetHandleCount(DAT_00438984);
  return;
}



/* 0042c280  FUN_0042c280  21 bytes, 1 callers */

void FUN_0042c280(void)

{
  DAT_00438980 = HeapCreate(1,0x1000,0);
  return;
}



/* 0042c2a0  __FF_MSGBANNER  61 bytes, 1 callers */

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_0043477c == 1) || ((DAT_0043477c == 0 && (DAT_00434780 == 1)))) {
    FUN_0042c2e0(0xfc);
    if (DAT_00434e48 != (code *)0x0) {
      (*DAT_00434e48)();
    }
    FUN_0042c2e0(0xff);
  }
  return;
}



/* 0042c2e0  FUN_0042c2e0  494 bytes, 3 callers */

void __cdecl FUN_0042c2e0(int param_1)

{
  char cVar1;
  int iVar2;
  DWORD DVar3;
  HANDLE hFile;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  CHAR *pCVar10;
  char *pcVar11;
  DWORD local_1a8;
  char local_1a4 [100];
  char acStack_140 [60];
  CHAR local_104 [260];
  
  iVar2 = 0;
  piVar4 = &DAT_00434dc0;
  do {
    if (*piVar4 == param_1) break;
    piVar4 = piVar4 + 2;
    iVar2 = iVar2 + 1;
  } while (piVar4 < &DAT_00434e48);
  if ((&DAT_00434dc0)[iVar2 * 2] == param_1) {
    if ((DAT_0043477c == 1) || ((DAT_0043477c == 0 && (DAT_00434780 == 1)))) {
      hFile = *(HANDLE *)(DAT_00438990 + 0x10);
      if (hFile == (HANDLE)0xffffffff) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar8 = *(char **)(iVar2 * 8 + 0x434dc4);
      uVar6 = 0xffffffff;
      pcVar9 = pcVar8;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      WriteFile(hFile,pcVar8,~uVar6 - 1,&local_1a8,(LPOVERLAPPED)0x0);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,local_104,0x104);
      if (DVar3 == 0) {
        pcVar8 = s_<program_name_unknown>_00434e98;
        pCVar10 = local_104;
        for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined4 *)pCVar10 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pCVar10 = pCVar10 + 4;
        }
        *(undefined2 *)pCVar10 = *(undefined2 *)pcVar8;
        pCVar10[2] = pcVar8[2];
      }
      pcVar8 = local_104;
      uVar6 = 0xffffffff;
      pcVar9 = local_104;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      if (0x3c < ~uVar6) {
        uVar6 = 0xffffffff;
        pcVar8 = local_104;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        pcVar8 = acStack_140 + ~uVar6;
        FUN_0042d780(pcVar8,&DAT_00434e94,3);
      }
      pcVar9 = s_Runtime_Error__Program__00434e78;
      pcVar11 = local_1a4;
      for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar11 = pcVar11 + 4;
      }
      *(undefined2 *)pcVar11 = *(undefined2 *)pcVar9;
      uVar6 = 0xffffffff;
      do {
        pcVar9 = pcVar8;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar5 = -1;
      pcVar8 = local_1a4;
      do {
        pcVar11 = pcVar8;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar11 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar1 != '\0');
      pcVar8 = pcVar9 + -uVar6;
      pcVar9 = pcVar11 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar8 = (char *)&DAT_00434e74;
      do {
        pcVar9 = pcVar8;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar5 = -1;
      pcVar8 = local_1a4;
      do {
        pcVar11 = pcVar8;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar11 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar1 != '\0');
      pcVar8 = pcVar9 + -uVar6;
      pcVar9 = pcVar11 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar8 = *(char **)(iVar2 * 8 + 0x434dc4);
      do {
        pcVar9 = pcVar8;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar2 = -1;
      pcVar8 = local_1a4;
      do {
        pcVar11 = pcVar8;
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        pcVar11 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar1 != '\0');
      pcVar8 = pcVar9 + -uVar6;
      pcVar9 = pcVar11 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      ___crtMessageBoxA(local_1a4,s_Microsoft_Visual_C___Runtime_Lib_00434e4c,0x12010);
      return;
    }
  }
  return;
}



/* 0042c500  FUN_0042c500  88 bytes, 0 callers */

int FUN_0042c500(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    FUN_00429f30();
    return 1;
  }
  if (DAT_00437934 != (_func_int *)0x0) {
    iVar2 = _ValidateExecute(DAT_00437934);
    if (iVar2 != 0) {
      iVar2 = (*DAT_00437934)(param_1);
      return iVar2;
    }
  }
  return 0;
}



/* 0042c570  FID_conflict:_ValidateRead  32 bytes, 2 callers */

/* Library Function - Multiple Matches With Different Base Names
    int __cdecl _ValidateRead(void const *,unsigned int)
    int __cdecl _ValidateWrite(void *,unsigned int)
   
   Library: Visual Studio 1998 Release */

bool __cdecl FID_conflict__ValidateRead(void *param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return BVar1 == 0;
}



/* 0042c590  FID_conflict:_ValidateRead  32 bytes, 1 callers */

/* Library Function - Multiple Matches With Different Base Names
    int __cdecl _ValidateRead(void const *,unsigned int)
    int __cdecl _ValidateWrite(void *,unsigned int)
   
   Library: Visual Studio 1998 Release */

bool __cdecl FID_conflict__ValidateRead(LPVOID param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadWritePtr(param_1,param_2);
  return BVar1 == 0;
}



/* 0042c5b0  _ValidateExecute  27 bytes, 2 callers */

/* Library Function - Single Match
    int __cdecl _ValidateExecute(int (__stdcall*)(void))
   
   Library: Visual Studio 1998 Release */

int __cdecl _ValidateExecute(_func_int *param_1)

{
  BOOL BVar1;
  
  BVar1 = IsBadCodePtr((FARPROC)param_1);
  return (uint)(BVar1 == 0);
}



/* 0042c5d0  FID_conflict:_memcpy  285 bytes, 2 callers */

/* Library Function - Multiple Matches With Different Base Names
    _memcpy
    _memmove
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl FID_conflict__memcpy(void *_Dst,void *_Src,size_t _Size)

{
  uint uVar1;
  int in_EDX;
  uint uVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  
  if ((_Src < _Dst) && (_Dst < (void *)((int)_Src + _Size))) {
    puVar3 = (undefined4 *)((int)_Src + _Size);
    puVar5 = (undefined4 *)((int)_Dst + _Size);
    if (((uint)puVar5 & 3) == 0) {
      uVar1 = _Size >> 2;
      while( true ) {
        puVar5 = puVar5 + -1;
        puVar3 = puVar3 + -1;
        if (uVar1 == 0) break;
        uVar1 = uVar1 - 1;
        *puVar5 = *puVar3;
      }
      switch(_Size & 3) {
      case 1:
switchD_0042c699_caseD_1:
        *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar3 + 3);
        return _Dst;
      case 2:
switchD_0042c699_caseD_2:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        return _Dst;
      case 3:
switchD_0042c699_caseD_3:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        *(undefined1 *)((int)puVar5 + 1) = *(undefined1 *)((int)puVar3 + 1);
        return _Dst;
      }
    }
    else {
      puVar4 = (undefined1 *)((int)puVar3 + -1);
      puVar6 = (undefined1 *)((int)puVar5 + -1);
      if (_Size < 0xd) {
        for (; _Size != 0; _Size = _Size - 1) {
          *puVar6 = *puVar4;
          puVar4 = puVar4 + -1;
          puVar6 = puVar6 + -1;
        }
        return _Dst;
      }
      uVar2 = -in_EDX & 3;
      uVar1 = _Size - uVar2;
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + -1;
        puVar6 = puVar6 + -1;
      }
      puVar3 = (undefined4 *)(puVar4 + -3);
      puVar5 = (undefined4 *)(puVar6 + -3);
      for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + -1;
        puVar5 = puVar5 + -1;
      }
      switch(uVar1 & 3) {
      case 1:
        goto switchD_0042c699_caseD_1;
      case 2:
        goto switchD_0042c699_caseD_2;
      case 3:
        goto switchD_0042c699_caseD_3;
      }
    }
    return _Dst;
  }
  puVar3 = _Dst;
  if (((uint)_Dst & 3) == 0) {
    for (uVar1 = _Size >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *(undefined4 *)_Src;
      _Src = (undefined4 *)((int)_Src + 4);
      puVar3 = puVar3 + 1;
    }
    switch(_Size & 3) {
    case 1:
switchD_0042c600_caseD_1:
      *(undefined1 *)puVar3 = *(undefined1 *)_Src;
      return _Dst;
    case 2:
switchD_0042c600_caseD_2:
      *(undefined2 *)puVar3 = *(undefined2 *)_Src;
      return _Dst;
    case 3:
switchD_0042c600_caseD_3:
      *(undefined2 *)puVar3 = *(undefined2 *)_Src;
      *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)_Src + 2);
      return _Dst;
    }
  }
  else {
    puVar4 = _Dst;
    if (_Size < 0xd) {
      for (; _Size != 0; _Size = _Size - 1) {
        *puVar4 = *(undefined1 *)_Src;
        _Src = (undefined1 *)((int)_Src + 1);
        puVar4 = puVar4 + 1;
      }
      return _Dst;
    }
    uVar2 = -(int)_Dst & 3;
    uVar1 = _Size - uVar2;
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)_Src;
      _Src = (undefined4 *)((int)_Src + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
    for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = *(undefined4 *)_Src;
      _Src = (undefined4 *)((int)_Src + 4);
      puVar3 = puVar3 + 1;
    }
    switch(uVar1 & 3) {
    case 1:
      goto switchD_0042c600_caseD_1;
    case 2:
      goto switchD_0042c600_caseD_2;
    case 3:
      goto switchD_0042c600_caseD_3;
    }
  }
  return _Dst;
}



/* 0042c720  _abort  27 bytes, 1 callers */

/* Library Function - Single Match
    _abort
   
   Library: Visual Studio 1998 Release */

void __cdecl _abort(void)

{
  FUN_0042c2e0(10);
  _raise(0x16);
                    /* WARNING: Subroutine does not return */
  __exit(3);
}



/* 0042c740  FUN_0042c740  33 bytes, 3 callers */

undefined4 __cdecl FUN_0042c740(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_00437938 != (code *)0x0) {
    iVar1 = (*DAT_00437938)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



/* 0042c770  __control87  63 bytes, 1 callers */

/* Library Function - Single Match
    __control87
   
   Library: Visual Studio 1998 Release */

uint __cdecl __control87(uint _NewValue,uint _Mask)

{
  uint uVar1;
  ushort in_FPUControlWord;
  
  uVar1 = __abstract_cw(in_FPUControlWord);
  __hw_cw();
  return ~_Mask & uVar1 | _Mask & _NewValue;
}



/* 0042c7b0  __controlfp  24 bytes, 1 callers */

/* Library Function - Single Match
    __controlfp
   
   Library: Visual Studio 1998 Release */

uint __cdecl __controlfp(uint _NewValue,uint _Mask)

{
  uint uVar1;
  
  uVar1 = __control87(_NewValue,_Mask & 0xfff7ffff);
  return uVar1;
}



/* 0042c7d0  __abstract_cw  161 bytes, 1 callers */

/* Library Function - Single Match
    __abstract_cw
   
   Library: Visual Studio 1998 Release */

uint __cdecl __abstract_cw(ushort param_1)

{
  uint uVar1;
  ushort uVar2;
  
  uVar1 = 0;
  if ((param_1 & 1) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x10) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x20) != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x80000;
  }
  uVar2 = param_1 & 0xc00;
  if (uVar2 == 0x400) {
    uVar1 = uVar1 | 0x100;
  }
  else if (uVar2 == 0x800) {
    uVar1 = uVar1 | 0x200;
  }
  else if (uVar2 == 0xc00) {
    uVar1 = uVar1 | 0x300;
  }
  if ((param_1 & 0x300) == 0) {
    uVar1 = uVar1 | 0x20000;
  }
  else if ((param_1 & 0x300) == 0x200) {
    uVar1 = uVar1 | 0x10000;
  }
  if ((param_1 & 0x1000) != 0) {
    uVar1 = uVar1 | 0x40000;
  }
  return uVar1;
}



/* 0042c880  __hw_cw  141 bytes, 1 callers */

/* Library Function - Single Match
    __hw_cw
   
   Library: Visual Studio 1998 Release */

void __hw_cw(void)

{
  return;
}



/* 0042c910  FUN_0042c910  11 bytes, 1 callers */

void FUN_0042c910(void)

{
  __amsg_exit(2);
  return;
}



/* 0042c920  __isctype  145 bytes, 2 callers */

/* Library Function - Single Match
    __isctype
   
   Library: Visual Studio 1998 Release */

int __cdecl __isctype(int _C,int _Type)

{
  LPCSTR _LpSrcStr;
  BOOL BVar1;
  byte bVar2;
  BOOL unaff_EBX;
  undefined4 local_6;
  undefined1 local_2;
  
  if (_C + 1U < 0x101) {
    return (uint)*(ushort *)(PTR_DAT_00434ec0 + _C * 2) & _Type;
  }
  bVar2 = (byte)((uint)_C >> 8);
  if ((PTR_DAT_00434ec0[(uint)bVar2 * 2 + 1] & 0x80) == 0) {
    _LpSrcStr = (LPCSTR)0x1;
    local_6._0_3_ = CONCAT12((char)_C,(undefined2)local_6);
    local_6 = (uint)(uint3)local_6;
  }
  else {
    _LpSrcStr = (LPCSTR)0x2;
    local_6._0_3_ = CONCAT12(bVar2,(undefined2)local_6);
    local_2 = 0;
    local_6 = CONCAT13((char)_C,(uint3)local_6);
  }
  BVar1 = ___crtGetStringTypeA
                    ((_locale_t)0x1,(int)&local_6 + 2,_LpSrcStr,(int)&local_6,(LPWORD)0x0,0,
                     unaff_EBX);
  if (BVar1 == 0) {
    return 0;
  }
  return local_6 & 0xffff & _Type;
}



/* 0042c9c0  FID_conflict:_tolower  229 bytes, 0 callers */

/* Library Function - Multiple Matches With Different Base Names
    __tolower_lk
    _tolower
   
   Library: Visual Studio 1998 Release */

int __cdecl FID_conflict__tolower(int _C)

{
  uint uVar1;
  LPCSTR _LpSrcStr;
  int iVar2;
  int unaff_EBX;
  uint in_stack_fffffff8;
  byte local_4;
  byte local_3;
  undefined1 local_2;
  
  if (DAT_00435390 == (_locale_t)0x0) {
    if ((0x40 < _C) && (_C < 0x5b)) {
      _C = _C + 0x20;
    }
    return _C;
  }
  if (_C < 0x100) {
    if (DAT_00434eb4 < 2) {
      uVar1 = *(ushort *)(PTR_DAT_00434ec0 + _C * 2) & 1;
    }
    else {
      uVar1 = __isctype(_C,1);
    }
    if (uVar1 == 0) {
      return _C;
    }
  }
  local_4 = (byte)((uint)_C >> 8);
  if ((PTR_DAT_00434ec0[(uint)local_4 * 2 + 1] & 0x80) == 0) {
    _LpSrcStr = (LPCSTR)0x1;
    local_3 = 0;
    local_4 = (byte)_C;
  }
  else {
    _LpSrcStr = (LPCSTR)0x2;
    local_2 = 0;
    local_3 = (byte)_C;
  }
  iVar2 = ___crtLCMapStringA(DAT_00435390,(LPCWSTR)0x100,(DWORD)&local_4,_LpSrcStr,
                             (int)&stack0xfffffff8,(LPSTR)0x3,0,unaff_EBX,in_stack_fffffff8);
  if (iVar2 == 0) {
    return _C;
  }
  if (iVar2 == 1) {
    return in_stack_fffffff8 & 0xff;
  }
  return in_stack_fffffff8 & 0xffff;
}



/* 0042cab0  __ZeroTail  100 bytes, 1 callers */

/* Library Function - Single Match
    __ZeroTail
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl __ZeroTail(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = (int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5;
  bVar1 = (byte)(param_2 >> 0x1f);
  if ((*(uint *)(param_1 + iVar2 * 4) &
      ~(-1 << (0x1f - ((((byte)param_2 ^ bVar1) - bVar1 & 0x1f ^ bVar1) - bVar1) & 0x1f))) != 0) {
    return 0;
  }
  iVar2 = iVar2 + 1;
  if (iVar2 < 3) {
    piVar3 = (int *)(param_1 + iVar2 * 4);
    do {
      if (*piVar3 != 0) {
        return 0;
      }
      piVar3 = piVar3 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
  }
  return 1;
}



/* 0042cb20  __IncMan  99 bytes, 1 callers */

/* Library Function - Single Match
    __IncMan
   
   Library: Visual Studio 1998 Release */

void __cdecl __IncMan(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  
  iVar2 = (int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5;
  bVar1 = (byte)(param_2 >> 0x1f);
  puVar4 = (uint *)(param_1 + iVar2 * 4);
  iVar3 = FUN_0042ddb0(*puVar4,1 << (0x1f - ((((byte)param_2 ^ bVar1) - bVar1 & 0x1f ^ bVar1) -
                                            bVar1) & 0x1f),puVar4);
  iVar2 = iVar2 + -1;
  if (-1 < iVar2) {
    puVar4 = (uint *)(param_1 + iVar2 * 4);
    do {
      if (iVar3 == 0) {
        return;
      }
      iVar3 = FUN_0042ddb0(*puVar4,1,puVar4);
      iVar2 = iVar2 + -1;
      puVar4 = puVar4 + -1;
    } while (-1 < iVar2);
  }
  return;
}



/* 0042cb90  __RoundMan  172 bytes, 1 callers */

/* Library Function - Single Match
    __RoundMan
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl __RoundMan(int param_1,int param_2)

{
  uint *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_4;
  
  local_4 = 0;
  iVar3 = (int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5;
  bVar2 = (byte)(param_2 >> 0x1f);
  bVar2 = 0x1f - ((((byte)param_2 ^ bVar2) - bVar2 & 0x1f ^ bVar2) - bVar2);
  puVar1 = (uint *)(param_1 + iVar3 * 4);
  if ((*puVar1 & 1 << (bVar2 & 0x1f)) != 0) {
    iVar4 = __ZeroTail(param_1,param_2 + 1);
    if (iVar4 == 0) {
      local_4 = __IncMan(param_1,param_2 + -1);
    }
  }
  iVar3 = iVar3 + 1;
  *puVar1 = *puVar1 & -1 << (bVar2 & 0x1f);
  if (iVar3 < 3) {
    puVar5 = (undefined4 *)(param_1 + iVar3 * 4);
    for (iVar4 = 3 - iVar3; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
  }
  return local_4;
}



/* 0042cc40  __CopyMan  29 bytes, 1 callers */

/* Library Function - Single Match
    __CopyMan
   
   Library: Visual Studio 1998 Release */

void __cdecl __CopyMan(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 3;
  do {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = uVar1;
    param_1 = param_1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}



/* 0042cc60  __FillZeroMan  15 bytes, 1 callers */

/* Library Function - Single Match
    __FillZeroMan
   
   Library: Visual Studio 1998 Release */

void __cdecl __FillZeroMan(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



/* 0042cc70  __IsZeroMan  29 bytes, 1 callers */

/* Library Function - Single Match
    __IsZeroMan
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl __IsZeroMan(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*param_1 != 0) {
      return 0;
    }
    param_1 = param_1 + 1;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  return 1;
}



/* 0042cc90  FUN_0042cc90  173 bytes, 1 callers */

void __cdecl FUN_0042cc90(uint *param_1,int param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  
  iVar3 = (int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5;
  bVar2 = (byte)(param_2 >> 0x1f);
  uVar5 = 0;
  bVar2 = (((byte)param_2 ^ bVar2) - bVar2 & 0x1f ^ bVar2) - bVar2;
  iVar6 = 3;
  puVar4 = param_1;
  do {
    uVar1 = *puVar4;
    uVar8 = uVar1 >> (bVar2 & 0x1f);
    *puVar4 = uVar8;
    *puVar4 = uVar5 | uVar8;
    uVar5 = (~(-1 << (bVar2 & 0x1f)) & uVar1) << (0x20 - bVar2 & 0x1f);
    iVar6 = iVar6 + -1;
    puVar4 = puVar4 + 1;
  } while (iVar6 != 0);
  iVar6 = 2;
  puVar7 = param_1 + 2;
  puVar4 = param_1 + (2 - iVar3);
  do {
    if (iVar6 < iVar3) {
      *puVar7 = 0;
    }
    else {
      *puVar7 = *puVar4;
    }
    puVar4 = puVar4 + -1;
    puVar7 = puVar7 + -1;
    iVar6 = iVar6 + -1;
  } while (-1 < iVar6);
  return;
}



/* 0042cd40  __ld12cvt  459 bytes, 2 callers */

/* Library Function - Single Match
    __ld12cvt
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl __ld12cvt(ushort *param_1,uint *param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint local_18;
  uint local_14;
  int local_10;
  undefined4 local_c [3];
  
  uVar1 = param_1[5];
  uVar4 = uVar1 & 0x7fff;
  iVar5 = uVar4 - 0x3fff;
  local_14 = *(uint *)(param_1 + 1);
  local_18 = *(uint *)(param_1 + 3);
  local_10 = (uint)*param_1 << 0x10;
  if (iVar5 == -0x3fff) {
    iVar5 = 0;
    iVar2 = __IsZeroMan((int *)&local_18);
    if (iVar2 == 0) {
      __FillZeroMan(&local_18);
      uVar3 = 2;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    __CopyMan(local_c,&local_18);
    iVar2 = __RoundMan((int)&local_18,param_3[2]);
    if (iVar2 != 0) {
      iVar5 = uVar4 - 0x3ffe;
    }
    iVar2 = param_3[1];
    if (iVar5 < iVar2 - param_3[2]) {
      iVar5 = 0;
      __FillZeroMan(&local_18);
      uVar3 = 2;
    }
    else if (iVar2 < iVar5) {
      if (iVar5 < *param_3) {
        iVar5 = iVar5 + param_3[5];
        local_18 = local_18 & 0x7fffffff;
        FUN_0042cc90(&local_18,param_3[3]);
        uVar3 = 0;
      }
      else {
        __FillZeroMan(&local_18);
        local_18 = local_18 | 0x80000000;
        FUN_0042cc90(&local_18,param_3[3]);
        iVar5 = param_3[5] + *param_3;
        uVar3 = 1;
      }
    }
    else {
      __CopyMan(&local_18,local_c);
      FUN_0042cc90(&local_18,iVar2 - iVar5);
      __RoundMan((int)&local_18,param_3[2]);
      iVar5 = 0;
      FUN_0042cc90(&local_18,param_3[3] + 1);
      uVar3 = 2;
    }
  }
  local_18 = iVar5 << (0x1fU - (char)param_3[3] & 0x1f) | ((uVar1 & 0x8000) == 0) - 1 & 0x80000000 |
             local_18;
  if (param_3[4] == 0x40) {
    param_2[1] = local_18;
    *param_2 = local_14;
    return uVar3;
  }
  if (param_3[4] == 0x20) {
    *param_2 = local_18;
  }
  return uVar3;
}



/* 0042cf10  FID_conflict:__ld12tod  24 bytes, 1 callers */

/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 1998 Release */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *_Ifp,_CRT_DOUBLE *_D)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt((ushort *)_Ifp,(uint *)_D,(int *)&DAT_004350d0);
  return IVar1;
}



/* 0042cf30  FID_conflict:__ld12tod  24 bytes, 1 callers */

/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 1998 Release */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *_Ifp,_CRT_DOUBLE *_D)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt((ushort *)_Ifp,(uint *)_D,(int *)&DAT_004350e8);
  return IVar1;
}



/* 0042cf50  FID_conflict:__atodbl  53 bytes, 0 callers */

/* Library Function - Multiple Matches With Different Base Names
    __atodbl
    __atoflt
   
   Library: Visual Studio 1998 Release */

int __cdecl FID_conflict___atodbl(_CRT_FLOAT *_Result,char *_Str)

{
  INTRNCVT_STATUS IVar1;
  int local_10;
  _LDBL12 local_c;
  
  FUN_0042dfc0((ushort *)&local_c,&local_10,(byte *)_Str,0,0,0,0);
  IVar1 = FID_conflict___ld12tod(&local_c,(_CRT_DOUBLE *)_Result);
  return IVar1;
}



/* 0042cf90  FID_conflict:__atodbl  53 bytes, 0 callers */

/* Library Function - Multiple Matches With Different Base Names
    __atodbl
    __atoflt
   
   Library: Visual Studio 1998 Release */

int __cdecl FID_conflict___atodbl(_CRT_FLOAT *_Result,char *_Str)

{
  INTRNCVT_STATUS IVar1;
  int local_10;
  _LDBL12 local_c;
  
  FUN_0042dfc0((ushort *)&local_c,&local_10,(byte *)_Str,0,0,0,0);
  IVar1 = FID_conflict___ld12tod(&local_c,(_CRT_DOUBLE *)_Result);
  return IVar1;
}



/* 0042cfd0  __fptostr  129 bytes, 3 callers */

/* Library Function - Single Match
    __fptostr
   
   Library: Visual Studio 1998 Release */

errno_t __cdecl __fptostr(char *_Buf,size_t _SizeInBytes,int _Digits,STRFLT _PtFlt)

{
  char cVar1;
  size_t sVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  pcVar7 = _Buf + 1;
  pcVar5 = *(char **)(_Digits + 0xc);
  *_Buf = '0';
  sVar2 = _SizeInBytes;
  pcVar6 = pcVar7;
  if (0 < (int)_SizeInBytes) {
    do {
      cVar1 = *pcVar5;
      if (cVar1 == '\0') {
        *pcVar6 = '0';
      }
      else {
        pcVar5 = pcVar5 + 1;
        *pcVar6 = cVar1;
      }
      pcVar6 = pcVar6 + 1;
      _SizeInBytes = _SizeInBytes - 1;
      sVar2 = 0;
    } while (_SizeInBytes != 0);
  }
  *pcVar6 = '\0';
  if ((-1 < (int)sVar2) && ('4' < *pcVar5)) {
    pcVar6 = pcVar6 + -1;
    cVar1 = *pcVar6;
    while (cVar1 == '9') {
      *pcVar6 = '0';
      pcVar6 = pcVar6 + -1;
      cVar1 = *pcVar6;
    }
    *pcVar6 = *pcVar6 + '\x01';
  }
  if (*_Buf == '1') {
    *(int *)(_Digits + 4) = *(int *)(_Digits + 4) + 1;
    return sVar2;
  }
  uVar3 = 0xffffffff;
  do {
    pcVar5 = pcVar7;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar7 = pcVar5 + -uVar3;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)_Buf = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    _Buf = _Buf + 4;
  }
  for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *_Buf = *pcVar7;
    pcVar7 = pcVar7 + 1;
    _Buf = _Buf + 1;
  }
  return uVar3;
}



/* 0042d060  __fltout  103 bytes, 3 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __fltout
   
   Library: Visual Studio 1998 Release */

undefined * __fltout(void)

{
  uint local_c;
  uint local_8;
  ushort local_4;
  
  FUN_0042d0d0(&local_c,(uint *)&stack0x00000004);
  _DAT_00437968 = FUN_0042e710(local_c,local_8,local_4,0x11,0,&DAT_00437940);
  _DAT_0043796c = &DAT_00437944;
  _DAT_00437960 = (int)DAT_00437942;
  _DAT_00437964 = (int)DAT_00437940;
  return &DAT_00437960;
}



/* 0042d0d0  FUN_0042d0d0  187 bytes, 1 callers */

void __cdecl FUN_0042d0d0(uint *param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  
  uVar1 = *(ushort *)((int)param_2 + 6);
  uVar5 = (uVar1 & 0x7ff0) >> 4;
  uVar4 = 0x80000000;
  uVar2 = param_2[1];
  uVar3 = *param_2;
  if (uVar5 == 0) {
    if (((uVar2 & 0xfffff) == 0) && (uVar3 == 0)) {
      *(undefined2 *)(param_1 + 2) = 0;
      param_1[1] = 0;
      *param_1 = 0;
      return;
    }
    uVar5 = 0x3c01;
    uVar4 = 0;
  }
  else if (uVar5 == 0x7ff) {
    uVar5 = 0x7fff;
  }
  else {
    uVar5 = uVar5 + 0x3c00;
  }
  *param_1 = uVar3 << 0xb;
  param_1[1] = uVar3 >> 0x15 | (uVar2 & 0xfffff) << 0xb | uVar4;
  while (uVar4 == 0) {
    uVar5 = uVar5 - 1;
    uVar2 = *param_1;
    uVar3 = param_1[1];
    *param_1 = uVar2 * 2;
    param_1[1] = uVar2 >> 0x1f | uVar3 * 2;
    uVar4 = uVar3 * 2 & 0x80000000;
  }
  *(ushort *)(param_1 + 2) = uVar5 | uVar1 & 0x8000;
  return;
}



/* 0042d190  FUN_0042d190  555 bytes, 2 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_0042d190(uint param_1,char *param_2,uint param_3)

{
  byte bVar1;
  char cVar2;
  BOOL BVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  uint local_418;
  DWORD local_414;
  int *local_410;
  int local_40c;
  DWORD local_408;
  char local_404 [1028];
  
  if (param_1 < DAT_00438984) {
    local_410 = (int *)((int)&DAT_00438990 + ((int)(param_1 & 0xffffffe7) >> 3));
    local_40c = (param_1 & 0x1f) * 8;
    bVar1 = *(byte *)(*local_410 + 4 + local_40c);
    if ((bVar1 & 1) != 0) {
      iVar5 = 0;
      local_408 = 0;
      if (param_3 == 0) {
        return 0;
      }
      if ((bVar1 & 0x20) != 0) {
        FUN_0042d3c0(param_1,0,2);
      }
      if ((*(byte *)((undefined4 *)(local_40c + *local_410) + 1) & 0x80) == 0) {
        BVar3 = WriteFile(*(HANDLE *)(local_40c + *local_410),param_2,param_3,&local_414,
                          (LPOVERLAPPED)0x0);
        if (BVar3 == 0) {
LAB_0042d2d5:
          local_418 = GetLastError();
        }
        else {
          local_418 = 0;
          local_408 = local_414;
        }
      }
      else {
        local_418 = 0;
        pcVar6 = param_2;
        do {
          if (param_3 <= (uint)((int)pcVar6 - (int)param_2)) break;
          pcVar4 = local_404;
          do {
            if (param_3 <= (uint)((int)pcVar6 - (int)param_2)) break;
            cVar2 = *pcVar6;
            pcVar6 = pcVar6 + 1;
            if (cVar2 == '\n') {
              *pcVar4 = '\r';
              iVar5 = iVar5 + 1;
              pcVar4 = pcVar4 + 1;
            }
            *pcVar4 = cVar2;
            pcVar4 = pcVar4 + 1;
          } while ((int)pcVar4 - (int)local_404 < 0x400);
          BVar3 = WriteFile(*(HANDLE *)(*local_410 + local_40c),local_404,
                            (int)pcVar4 - (int)local_404,&local_414,(LPOVERLAPPED)0x0);
          if (BVar3 == 0) goto LAB_0042d2d5;
          local_408 = local_408 + local_414;
        } while ((int)pcVar4 - (int)local_404 <= (int)local_414);
      }
      if (local_408 != 0) {
        return local_408 - iVar5;
      }
      if (local_418 == 0) {
        if (((*(byte *)(*local_410 + 4 + local_40c) & 0x40) != 0) && (*param_2 == '\x1a')) {
          return 0;
        }
        _DAT_00434854 = 0x1c;
        _DAT_00434858 = 0;
        return -1;
      }
      if (local_418 != 5) {
        FUN_0042eab0(local_418);
        return -1;
      }
      _DAT_00434854 = 9;
      _DAT_00434858 = local_418;
      return -1;
    }
  }
  _DAT_00434854 = 9;
  _DAT_00434858 = 0;
  return -1;
}



/* 0042d3c0  FUN_0042d3c0  188 bytes, 2 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

DWORD __cdecl FUN_0042d3c0(uint param_1,LONG param_2,DWORD param_3)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  HANDLE hFile;
  DWORD DVar4;
  uint uVar5;
  
  if (param_1 < DAT_00438984) {
    piVar1 = (int *)((int)&DAT_00438990 + ((int)(param_1 & 0xffffffe7) >> 3));
    iVar2 = (param_1 & 0x1f) * 8;
    if ((*(byte *)(*piVar1 + 4 + iVar2) & 1) != 0) {
      hFile = (HANDLE)FUN_0042ebb0(param_1);
      if (hFile == (HANDLE)0xffffffff) {
        _DAT_00434854 = 9;
        return 0xffffffff;
      }
      DVar4 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);
      uVar5 = 0;
      if (DVar4 == 0xffffffff) {
        uVar5 = GetLastError();
      }
      if (uVar5 != 0) {
        FUN_0042eab0(uVar5);
        return 0xffffffff;
      }
      pbVar3 = (byte *)(*piVar1 + 4 + iVar2);
      *pbVar3 = *pbVar3 & 0xfd;
      return DVar4;
    }
  }
  _DAT_00434854 = 9;
  _DAT_00434858 = 0;
  return 0xffffffff;
}



/* 0042d480  __getbuf  75 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __getbuf
   
   Library: Visual Studio 1998 Release */

void __cdecl __getbuf(FILE *_File)

{
  char *pcVar1;
  
  _DAT_00435380 = _DAT_00435380 + 1;
  pcVar1 = (char *)FUN_0042a050(0x1000);
  _File->_base = pcVar1;
  if (pcVar1 == (char *)0x0) {
    _File->_flag = _File->_flag | 4;
    _File->_base = (char *)&_File->_charbuf;
    _File->_bufsiz = 2;
  }
  else {
    _File->_flag = _File->_flag | 8;
    _File->_bufsiz = 0x1000;
  }
  _File->_ptr = _File->_base;
  _File->_cnt = 0;
  return;
}



/* 0042d4d0  FUN_0042d4d0  42 bytes, 1 callers */

byte __cdecl FUN_0042d4d0(uint param_1)

{
  if (DAT_00438984 <= param_1) {
    return 0;
  }
  return *(byte *)(*(int *)((int)&DAT_00438990 + ((int)(param_1 & 0xffffffe7) >> 3)) + 4 +
                  (param_1 & 0x1f) * 8) & 0x40;
}



/* 0042d5f0  _wctomb  146 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _wctomb
   
   Library: Visual Studio 1998 Release */

int __cdecl _wctomb(char *_MbCh,wchar_t _WCh)

{
  int iVar1;
  BOOL local_4;
  
  if (_MbCh == (char *)0x0) {
    return 0;
  }
  if (DAT_00435390 == 0) {
    if (0xff < (ushort)_WCh) {
      _DAT_00434854 = 0x2a;
      return -1;
    }
    *_MbCh = (char)_WCh;
    return 1;
  }
  local_4 = 0;
  iVar1 = WideCharToMultiByte(DAT_004353a0,0x220,&_WCh,1,_MbCh,DAT_00434eb4,(LPCSTR)0x0,&local_4);
  if ((iVar1 == 0) || (local_4 != 0)) {
    _DAT_00434854 = 0x2a;
    iVar1 = -1;
  }
  return iVar1;
}



/* 0042d690  __aulldiv  104 bytes, 1 callers */

/* Library Function - Single Match
    __aulldiv
   
   Library: Visual Studio */

undefined8 __aulldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar6;
  
  uVar9 = param_1;
  uVar6 = param_4;
  uVar7 = param_2;
  uVar3 = param_3;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar5 = uVar6 >> 1;
      uVar3 = (uint)(CONCAT14((uVar6 & 1) != 0,uVar3) >> 1);
      uVar8 = uVar7 >> 1;
      uVar9 = (uint)(CONCAT14((uVar7 & 1) != 0,uVar9) >> 1);
      uVar6 = uVar5;
      uVar7 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar9) / (ulonglong)uVar3;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar9 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar9)) ||
       ((param_2 <= uVar9 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}



/* 0042d700  __aullrem  117 bytes, 1 callers */

/* Library Function - Single Match
    __aullrem
   
   Library: Visual Studio */

undefined8 __aullrem(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  
  uVar4 = param_1;
  uVar9 = param_4;
  uVar10 = param_2;
  uVar3 = param_3;
  if (param_4 == 0) {
    iVar6 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %
                 (ulonglong)param_3);
    iVar7 = 0;
  }
  else {
    do {
      uVar5 = uVar9 >> 1;
      uVar3 = (uint)(CONCAT14((uVar9 & 1) != 0,uVar3) >> 1);
      uVar8 = uVar10 >> 1;
      uVar4 = (uint)(CONCAT14((uVar10 & 1) != 0,uVar4) >> 1);
      uVar9 = uVar5;
      uVar10 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar4) / (ulonglong)uVar3;
    uVar3 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar4 = (uint)lVar2;
    uVar10 = uVar9 + uVar3;
    if (((CARRY4(uVar9,uVar3)) || (param_2 < uVar10)) || ((param_2 <= uVar10 && (param_1 < uVar4))))
    {
      bVar11 = uVar4 < param_3;
      uVar4 = uVar4 - param_3;
      uVar10 = (uVar10 - param_4) - (uint)bVar11;
    }
    iVar6 = -(uVar4 - param_1);
    iVar7 = -(uint)(uVar4 - param_1 != 0) - ((uVar10 - param_2) - (uint)(uVar4 < param_1));
  }
  return CONCAT44(iVar7,iVar6);
}



/* 0042d780  FUN_0042d780  36 bytes, 2 callers */

char * __cdecl FUN_0042d780(char *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = param_1;
  if (param_3 != 0) {
    do {
      pcVar2 = pcVar1;
      if (*param_2 == '\0') break;
      pcVar2 = pcVar1 + 1;
      *pcVar1 = *param_2;
      param_3 = param_3 + -1;
      param_2 = param_2 + 1;
      pcVar1 = pcVar2;
    } while (param_3 != 0);
    for (; param_3 != 0; param_3 = param_3 + -1) {
      *pcVar2 = '\0';
      pcVar2 = pcVar2 + 1;
    }
  }
  return param_1;
}



/* 0042d7b0  ___crtMessageBoxA  146 bytes, 1 callers */

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_004353a4 != (FARPROC)0x0) {
LAB_0042d7ff:
    if (DAT_004353a8 != (FARPROC)0x0) {
      iVar1 = (*DAT_004353a8)();
    }
    if ((iVar1 != 0) && (DAT_004353ac != (FARPROC)0x0)) {
      iVar1 = (*DAT_004353ac)(iVar1);
    }
    iVar1 = (*DAT_004353a4)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA(s_user32_dll_004353e0);
  if (hModule != (HMODULE)0x0) {
    DAT_004353a4 = GetProcAddress(hModule,s_MessageBoxA_004353d4);
    if (DAT_004353a4 != (FARPROC)0x0) {
      DAT_004353a8 = GetProcAddress(hModule,s_GetActiveWindow_004353c4);
      DAT_004353ac = GetProcAddress(hModule,s_GetLastActivePopup_004353b0);
      goto LAB_0042d7ff;
    }
  }
  return 0;
}



/* 0042d850  _raise  337 bytes, 1 callers */

/* Library Function - Single Match
    _raise
   
   Library: Visual Studio 1998 Release */

int __cdecl _raise(int _SigNum)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  code *pcVar7;
  undefined4 local_4;
  
  switch(_SigNum) {
  case 2:
    puVar6 = &DAT_004353ec;
    pcVar7 = DAT_004353ec;
    break;
  default:
    return -1;
  case 4:
  case 8:
  case 0xb:
    uVar3 = siglookup(_SigNum);
    puVar6 = (undefined4 *)(uVar3 + 8);
    pcVar7 = (code *)*puVar6;
    break;
  case 0xf:
    puVar6 = &DAT_004353f8;
    pcVar7 = DAT_004353f8;
    break;
  case 0x15:
    puVar6 = &DAT_004353f0;
    pcVar7 = DAT_004353f0;
    break;
  case 0x16:
    puVar6 = &DAT_004353f4;
    pcVar7 = DAT_004353f4;
  }
  uVar2 = DAT_00434b40;
  uVar1 = DAT_00434b3c;
  if (pcVar7 == (code *)0x1) {
    return 0;
  }
  if (pcVar7 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (((_SigNum == 8) || (_SigNum == 0xb)) || (uVar5 = local_4, _SigNum == 4)) {
    DAT_00434b40 = 0;
    uVar5 = uVar2;
    if (_SigNum == 8) {
      DAT_00434b3c = 0x8c;
      local_4 = uVar1;
      goto LAB_0042d91c;
    }
  }
  else {
LAB_0042d91c:
    if (_SigNum == 8) {
      if (DAT_00434b30 < DAT_00434b34 + DAT_00434b30) {
        puVar6 = (undefined4 *)(DAT_00434b30 * 0xc + 0x434ac0);
        iVar4 = DAT_00434b34;
        do {
          *puVar6 = 0;
          puVar6 = puVar6 + 3;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      goto LAB_0042d95d;
    }
  }
  *puVar6 = 0;
LAB_0042d95d:
  if (_SigNum == 8) {
    (*pcVar7)(8,DAT_00434b3c);
  }
  else {
    (*pcVar7)(_SigNum);
    if ((_SigNum != 0xb) && (_SigNum != 4)) {
      return 0;
    }
  }
  if (_SigNum == 8) {
    DAT_00434b3c = local_4;
  }
  DAT_00434b40 = uVar5;
  return 0;
}



/* 0042d9e0  siglookup  49 bytes, 1 callers */

/* Library Function - Single Match
    _siglookup
   
   Library: Visual Studio 1998 Release */

uint __cdecl siglookup(int param_1)

{
  undefined *puVar1;
  
  puVar1 = &DAT_00434ab8;
  do {
    if (*(int *)(puVar1 + 4) == param_1) break;
    puVar1 = puVar1 + 0xc;
  } while (puVar1 < &DAT_00434ab8 + DAT_00434b38 * 0xc);
  return -(uint)(*(int *)(puVar1 + 4) == param_1) & (uint)puVar1;
}



/* 0042da20  ___crtGetStringTypeA  291 bytes, 1 callers */

/* Library Function - Single Match
    ___crtGetStringTypeA
   
   Library: Visual Studio 1998 Release */

BOOL __cdecl
___crtGetStringTypeA
          (_locale_t _Plocinfo,DWORD _DWInfoType,LPCSTR _LpSrcStr,int _CchSrc,LPWORD _LpCharType,
          int _Code_page,BOOL _BError)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  LPCWSTR lpWideCharStr;
  WORD local_2;
  
  iVar3 = DAT_00435438;
  if (DAT_00435438 == 0) {
    BVar1 = GetStringTypeA(0,1,&DAT_0043543c,1,&local_2);
    if (BVar1 == 0) {
      BVar1 = GetStringTypeW(1,(LPCWSTR)&DAT_00435440,1,&local_2);
      if (BVar1 == 0) {
        return 0;
      }
      iVar3 = 1;
    }
    else {
      iVar3 = 2;
    }
  }
  DAT_00435438 = iVar3;
  if (iVar3 != 2) {
    if (iVar3 == 1) {
      BVar1 = 0;
      lpWideCharStr = (LPCWSTR)0x0;
      if (_LpCharType == (LPWORD)0x0) {
        _LpCharType = DAT_004353a0;
      }
      iVar2 = MultiByteToWideChar((UINT)_LpCharType,9,(LPCSTR)_DWInfoType,(int)_LpSrcStr,(LPWSTR)0x0
                                  ,0);
      iVar3 = BVar1;
      if (((iVar2 != 0) && (lpWideCharStr = FUN_0042ec00(2,iVar2), lpWideCharStr != (LPCWSTR)0x0))
         && (iVar2 = MultiByteToWideChar((UINT)_LpCharType,1,(LPCSTR)_DWInfoType,(int)_LpSrcStr,
                                         lpWideCharStr,iVar2), iVar2 != 0)) {
        iVar3 = GetStringTypeW((DWORD)_Plocinfo,lpWideCharStr,iVar2,(LPWORD)_CchSrc);
      }
      FUN_0042a030(lpWideCharStr);
    }
    return iVar3;
  }
  if (_Code_page == 0) {
    _Code_page = DAT_00435390;
  }
  BVar1 = GetStringTypeA(_Code_page,(DWORD)_Plocinfo,(LPCSTR)_DWInfoType,(int)_LpSrcStr,
                         (LPWORD)_CchSrc);
  return BVar1;
}



/* 0042db50  ___crtLCMapStringA  555 bytes, 1 callers */

/* Library Function - Single Match
    ___crtLCMapStringA
   
   Library: Visual Studio 1998 Release */

int __cdecl
___crtLCMapStringA(_locale_t _Plocinfo,LPCWSTR _LocaleName,DWORD _DwMapFlag,LPCSTR _LpSrcStr,
                  int _CchSrc,LPSTR _LpDestStr,int _CchDest,int _Code_page,BOOL _BError)

{
  int iVar1;
  LPCWSTR lpWideCharStr;
  int iVar2;
  LPCWSTR lpDestStr;
  
  if (DAT_00435448 == 0) {
    iVar1 = LCMapStringA(0,0x100,&DAT_0043543c,1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringW(0,0x100,(LPCWSTR)&DAT_00435440,1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_00435448 = 1;
    }
    else {
      DAT_00435448 = 2;
    }
  }
  if (0 < (int)_LpSrcStr) {
    _LpSrcStr = (LPCSTR)_strncnt((char *)_DwMapFlag,(size_t)_LpSrcStr);
  }
  if (DAT_00435448 == 2) {
    iVar1 = LCMapStringA((LCID)_Plocinfo,(DWORD)_LocaleName,(LPCSTR)_DwMapFlag,(int)_LpSrcStr,
                         (LPSTR)_CchSrc,(int)_LpDestStr);
    return iVar1;
  }
  if (DAT_00435448 != 1) {
    return DAT_00435448;
  }
  lpDestStr = (LPCWSTR)0x0;
  if (_CchDest == 0) {
    _CchDest = DAT_004353a0;
  }
  iVar1 = MultiByteToWideChar(_CchDest,9,(LPCSTR)_DwMapFlag,(int)_LpSrcStr,(LPWSTR)0x0,0);
  if (iVar1 == 0) {
    return 0;
  }
  lpWideCharStr = (LPCWSTR)FUN_0042a050(iVar1 * 2);
  if (lpWideCharStr == (LPCWSTR)0x0) {
    return 0;
  }
  iVar2 = MultiByteToWideChar(_CchDest,1,(LPCSTR)_DwMapFlag,(int)_LpSrcStr,lpWideCharStr,iVar1);
  if ((iVar2 != 0) &&
     (iVar2 = LCMapStringW((LCID)_Plocinfo,(DWORD)_LocaleName,lpWideCharStr,iVar1,(LPWSTR)0x0,0),
     iVar2 != 0)) {
    if (((uint)_LocaleName & 0x400) == 0) {
      lpDestStr = (LPCWSTR)FUN_0042a050(iVar2 * 2);
      if ((lpDestStr == (LPCWSTR)0x0) ||
         (iVar1 = LCMapStringW((LCID)_Plocinfo,(DWORD)_LocaleName,lpWideCharStr,iVar1,lpDestStr,
                               iVar2), iVar1 == 0)) goto LAB_0042dccb;
      if (_LpDestStr == (LPSTR)0x0) {
        iVar2 = WideCharToMultiByte(_CchDest,0x220,lpDestStr,iVar2,(LPSTR)0x0,0,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        iVar1 = iVar2;
      }
      else {
        iVar2 = WideCharToMultiByte(_CchDest,0x220,lpDestStr,iVar2,(LPSTR)_CchSrc,(int)_LpDestStr,
                                    (LPCSTR)0x0,(LPBOOL)0x0);
        iVar1 = iVar2;
      }
    }
    else {
      if (_LpDestStr == (LPSTR)0x0) goto LAB_0042dd62;
      if ((int)_LpDestStr < iVar2) goto LAB_0042dccb;
      iVar1 = LCMapStringW((LCID)_Plocinfo,(DWORD)_LocaleName,lpWideCharStr,iVar1,(LPWSTR)_CchSrc,
                           (int)_LpDestStr);
    }
    if (iVar1 != 0) {
LAB_0042dd62:
      FUN_0042a030(lpWideCharStr);
      FUN_0042a030(lpDestStr);
      return iVar2;
    }
  }
LAB_0042dccb:
  FUN_0042a030(lpWideCharStr);
  FUN_0042a030(lpDestStr);
  return 0;
}



/* 0042dd80  _strncnt  44 bytes, 1 callers */

/* Library Function - Single Match
    _strncnt
   
   Library: Visual Studio 1998 Release */

size_t __cdecl _strncnt(char *_String,size_t _Cnt)

{
  size_t sVar1;
  char *pcVar2;
  
  pcVar2 = _String;
  sVar1 = _Cnt;
  while (sVar1 != 0) {
    sVar1 = sVar1 - 1;
    if (*pcVar2 == '\0') goto LAB_0042dda5;
    pcVar2 = pcVar2 + 1;
  }
  if (*pcVar2 == '\0') {
LAB_0042dda5:
    _Cnt = (int)pcVar2 - (int)_String;
  }
  return _Cnt;
}



/* 0042ddb0  FUN_0042ddb0  35 bytes, 3 callers */

undefined4 __cdecl FUN_0042ddb0(uint param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = param_1 + param_2;
  if ((uVar1 < param_1) || (uVar1 < param_2)) {
    uVar2 = 1;
  }
  *param_3 = uVar1;
  return uVar2;
}



/* 0042dde0  ___add_12  102 bytes, 2 callers */

/* Library Function - Single Match
    ___add_12
   
   Library: Visual Studio 1998 Release */

void __cdecl ___add_12(uint *param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = FUN_0042ddb0(*param_1,*param_2,param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_0042ddb0(param_1[1],1,param_1 + 1);
    if (iVar1 != 0) {
      param_1[2] = param_1[2] + 1;
    }
  }
  iVar1 = FUN_0042ddb0(param_1[1],param_2[1],param_1 + 1);
  if (iVar1 != 0) {
    param_1[2] = param_1[2] + 1;
  }
  FUN_0042ddb0(param_1[2],param_2[2],param_1 + 2);
  return;
}



/* 0042de50  ___shl_12  62 bytes, 3 callers */

/* Library Function - Single Match
    ___shl_12
   
   Library: Visual Studio 1998 Release */

void __cdecl ___shl_12(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  *param_1 = uVar1 * 2;
  param_1[1] = uVar2 * 2 | uVar1 >> 0x1f;
  param_1[2] = param_1[2] * 2 | uVar2 >> 0x1f;
  return;
}



/* 0042de90  ___shr_12  54 bytes, 2 callers */

/* Library Function - Single Match
    ___shr_12
   
   Library: Visual Studio 1998 Release */

void __cdecl ___shr_12(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1[2];
  uVar2 = param_1[1];
  param_1[2] = uVar1 >> 1;
  param_1[1] = uVar2 >> 1 | uVar1 << 0x1f;
  *param_1 = *param_1 >> 1 | uVar2 << 0x1f;
  return;
}



/* 0042ded0  FUN_0042ded0  232 bytes, 1 callers */

void __cdecl FUN_0042ded0(char *param_1,int param_2,uint *param_3)

{
  byte bVar1;
  uint uVar2;
  short sVar3;
  uint local_c;
  uint local_8;
  uint local_4;
  
  sVar3 = 0x404e;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_c = *param_3;
    local_8 = param_3[1];
    local_4 = param_3[2];
    ___shl_12(param_3);
    ___shl_12(param_3);
    ___add_12(param_3,&local_c);
    ___shl_12(param_3);
    local_c = (uint)*param_1;
    local_8 = 0;
    local_4 = 0;
    ___add_12(param_3,&local_c);
    param_1 = param_1 + 1;
  }
  uVar2 = param_3[2];
  while (uVar2 == 0) {
    sVar3 = sVar3 + -0x10;
    uVar2 = param_3[1] >> 0x10;
    param_3[2] = uVar2;
    param_3[1] = param_3[1] << 0x10 | *param_3 >> 0x10;
    *param_3 = *param_3 << 0x10;
  }
  bVar1 = *(byte *)((int)param_3 + 9);
  while ((bVar1 & 0x80) == 0) {
    sVar3 = sVar3 + -1;
    ___shl_12(param_3);
    bVar1 = *(byte *)((int)param_3 + 9);
  }
  *(short *)((int)param_3 + 10) = sVar3;
  return;
}



/* 0042dfc0  FUN_0042dfc0  1578 bytes, 2 callers */

undefined4 __cdecl
FUN_0042dfc0(ushort *param_1,int *param_2,byte *param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  byte bVar8;
  char *pcVar9;
  char *pcVar10;
  byte *pbVar11;
  int iVar12;
  uint uVar13;
  ushort local_52;
  uint local_50;
  byte *local_4c;
  int local_48;
  undefined4 local_40;
  int local_3c;
  undefined4 local_28 [5];
  char local_11;
  ushort local_c;
  undefined4 local_a;
  undefined4 local_6;
  ushort local_2;
  
  local_3c = 1;
  pcVar10 = (char *)local_28;
  iVar12 = 0;
  local_52 = 0;
  local_50 = 0;
  bVar2 = false;
  bVar4 = false;
  bVar3 = false;
  bVar5 = false;
  iVar7 = 0;
  bVar6 = false;
  local_48 = 0;
  local_40 = 0;
  local_4c = param_3;
  for (; (((bVar8 = *param_3, bVar8 == 0x20 || (bVar8 == 9)) || (bVar8 == 10)) || (bVar8 == 0xd));
      param_3 = param_3 + 1) {
  }
  do {
    bVar8 = *param_3;
    pbVar11 = param_3 + 1;
    switch(iVar7) {
    case 0:
      if (((char)bVar8 < '1') || ('9' < (char)bVar8)) {
        if (bVar8 == DAT_00434eb8) {
          iVar7 = 5;
        }
        else if (bVar8 == 0x2b) {
          local_52 = 0;
          iVar7 = 2;
        }
        else if (bVar8 == 0x2d) {
          local_52 = 0x8000;
          iVar7 = 2;
        }
        else {
          if (bVar8 != 0x30) goto switchD_0042e270_caseD_2c;
          iVar7 = 1;
        }
        break;
      }
      iVar7 = 3;
      goto LAB_0042e474;
    case 1:
      bVar2 = true;
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 3;
        goto LAB_0042e474;
      }
      if (bVar8 == DAT_00434eb8) {
        iVar7 = 4;
      }
      else {
        switch(bVar8) {
        case 0x2b:
        case 0x2d:
          iVar7 = 0xb;
          pbVar11 = param_3;
          break;
        default:
          goto switchD_0042e270_caseD_2c;
        case 0x30:
          iVar7 = 1;
          break;
        case 0x44:
        case 0x45:
        case 100:
        case 0x65:
          iVar7 = 6;
        }
      }
      break;
    case 2:
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 3;
        goto LAB_0042e474;
      }
      if (bVar8 == DAT_00434eb8) {
        iVar7 = 5;
      }
      else if (bVar8 == 0x30) {
        iVar7 = 1;
      }
      else {
        iVar7 = 10;
        pbVar11 = local_4c;
      }
      break;
    case 3:
      bVar2 = true;
      while( true ) {
        if (DAT_00434eb4 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_00434ec0 + (uint)bVar8 * 2) & 4;
        }
        else {
          uVar13 = __isctype((uint)bVar8,4);
        }
        if (uVar13 == 0) break;
        if (local_50 < 0x19) {
          local_50 = local_50 + 1;
          *pcVar10 = bVar8 - 0x30;
          bVar8 = *pbVar11;
          pcVar10 = pcVar10 + 1;
          pbVar11 = pbVar11 + 1;
        }
        else {
          bVar8 = *pbVar11;
          pbVar11 = pbVar11 + 1;
          local_48 = local_48 + 1;
        }
      }
      if (bVar8 == DAT_00434eb8) {
        iVar7 = 4;
      }
      else {
        switch(bVar8) {
        case 0x2b:
        case 0x2d:
          iVar7 = 0xb;
          pbVar11 = pbVar11 + -1;
          break;
        default:
          goto switchD_0042e270_caseD_2c;
        case 0x44:
        case 0x45:
        case 100:
        case 0x65:
          iVar7 = 6;
        }
      }
      break;
    case 4:
      bVar2 = true;
      bVar4 = true;
      if (local_50 == 0) {
        while (bVar8 == 0x30) {
          local_48 = local_48 + -1;
          bVar8 = *pbVar11;
          pbVar11 = pbVar11 + 1;
        }
      }
      while( true ) {
        if (DAT_00434eb4 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_00434ec0 + (uint)bVar8 * 2) & 4;
        }
        else {
          uVar13 = __isctype((uint)bVar8,4);
        }
        if (uVar13 == 0) break;
        pcVar9 = pcVar10;
        if (local_50 < 0x19) {
          pcVar9 = pcVar10 + 1;
          local_50 = local_50 + 1;
          local_48 = local_48 + -1;
          *pcVar10 = bVar8 - 0x30;
        }
        bVar8 = *pbVar11;
        pbVar11 = pbVar11 + 1;
        pcVar10 = pcVar9;
      }
      switch(bVar8) {
      case 0x2b:
      case 0x2d:
        iVar7 = 0xb;
        pbVar11 = pbVar11 + -1;
        break;
      default:
        goto switchD_0042e270_caseD_2c;
      case 0x44:
      case 0x45:
      case 100:
      case 0x65:
        iVar7 = 6;
      }
      break;
    case 5:
      bVar4 = true;
      if (DAT_00434eb4 < 2) {
        uVar13 = *(ushort *)(PTR_DAT_00434ec0 + (uint)bVar8 * 2) & 4;
      }
      else {
        uVar13 = __isctype((uint)bVar8,4);
      }
      if (uVar13 != 0) {
        iVar7 = 4;
        goto LAB_0042e474;
      }
      iVar7 = 10;
      pbVar11 = local_4c;
      break;
    case 6:
      local_4c = param_3 + -1;
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 9;
        goto LAB_0042e474;
      }
      if (bVar8 == 0x2b) {
        iVar7 = 7;
      }
      else if (bVar8 == 0x2d) {
        local_3c = -1;
        iVar7 = 7;
      }
      else if (bVar8 == 0x30) {
        iVar7 = 8;
      }
      else {
        iVar7 = 10;
        pbVar11 = local_4c;
      }
      break;
    case 7:
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 9;
        goto LAB_0042e474;
      }
      if (bVar8 == 0x30) {
        iVar7 = 8;
      }
      else {
        iVar7 = 10;
        pbVar11 = local_4c;
      }
      break;
    case 8:
      bVar3 = true;
      while (bVar8 == 0x30) {
        bVar8 = *pbVar11;
        pbVar11 = pbVar11 + 1;
      }
      if (('0' < (char)bVar8) && ((char)bVar8 < ':')) {
        iVar7 = 9;
        goto LAB_0042e474;
      }
      goto switchD_0042e270_caseD_2c;
    case 9:
      bVar3 = true;
      iVar12 = 0;
      while( true ) {
        if (DAT_00434eb4 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_00434ec0 + (uint)bVar8 * 2) & 4;
        }
        else {
          uVar13 = __isctype((uint)bVar8,4);
        }
        if (uVar13 == 0) goto LAB_0042e3fa;
        iVar12 = (char)bVar8 + -0x30 + iVar12 * 10;
        if (0x1450 < iVar12) break;
        bVar8 = *pbVar11;
        pbVar11 = pbVar11 + 1;
      }
      iVar12 = 0x1451;
LAB_0042e3fa:
      while( true ) {
        if (DAT_00434eb4 < 2) {
          uVar13 = *(ushort *)(PTR_DAT_00434ec0 + (uint)bVar8 * 2) & 4;
        }
        else {
          uVar13 = __isctype((uint)bVar8,4);
        }
        if (uVar13 == 0) break;
        bVar8 = *pbVar11;
        pbVar11 = pbVar11 + 1;
      }
switchD_0042e270_caseD_2c:
      iVar7 = 10;
LAB_0042e474:
      pbVar11 = pbVar11 + -1;
      break;
    case 0xb:
      if (param_7 == 0) goto switchD_0042e270_caseD_2c;
      local_4c = param_3;
      if (bVar8 == 0x2b) {
        iVar7 = 7;
      }
      else if (bVar8 == 0x2d) {
        local_3c = -1;
        iVar7 = 7;
      }
      else {
        iVar7 = 10;
        pbVar11 = param_3;
      }
    }
    param_3 = pbVar11;
  } while (iVar7 != 10);
  *param_2 = (int)pbVar11;
  if (bVar2) {
    if (0x18 < local_50) {
      if ('\x04' < local_11) {
        local_11 = local_11 + '\x01';
      }
      pcVar10 = pcVar10 + -1;
      local_48 = local_48 + 1;
      local_50 = 0x18;
    }
    if (local_50 == 0) {
      local_c = 0;
      local_6 = 0;
      local_2 = 0;
      local_28[0] = 0;
      goto LAB_0042e572;
    }
    pcVar10 = pcVar10 + -1;
    cVar1 = *pcVar10;
    while (cVar1 == '\0') {
      pcVar10 = pcVar10 + -1;
      local_50 = local_50 - 1;
      local_48 = local_48 + 1;
      cVar1 = *pcVar10;
    }
    FUN_0042ded0((char *)local_28,local_50,(uint *)&local_c);
    if (local_3c < 0) {
      iVar12 = -iVar12;
    }
    uVar13 = iVar12 + local_48;
    if (!bVar3) {
      uVar13 = uVar13 + param_5;
    }
    if (!bVar4) {
      uVar13 = uVar13 - param_6;
    }
    if ((int)uVar13 < 0x1451) {
      if (-0x1451 < (int)uVar13) {
        FUN_0042f110((int *)&local_c,uVar13,param_4);
        local_28[0] = local_a;
        goto LAB_0042e572;
      }
      bVar6 = true;
    }
    else {
      bVar5 = true;
    }
  }
  local_6 = local_28[0];
  local_c = (ushort)local_28[0];
  local_2 = (ushort)local_28[0];
LAB_0042e572:
  if (bVar2) {
    if (bVar5) {
      local_2 = 0x7fff;
      local_6 = 0x80000000;
      local_c = 0;
      local_28[0] = 0;
      local_40 = 2;
    }
    else if (bVar6) {
      local_c = 0;
      local_6 = 0;
      local_2 = 0;
      local_28[0] = 0;
      local_40 = 1;
    }
  }
  else {
    local_c = 0;
    local_6 = 0;
    local_2 = 0;
    local_28[0] = 0;
    local_40 = 4;
  }
  *(undefined4 *)(param_1 + 1) = local_28[0];
  *param_1 = local_c;
  *(undefined4 *)(param_1 + 3) = local_6;
  param_1[5] = local_52 | local_2;
  return local_40;
}



/* 0042e710  FUN_0042e710  923 bytes, 1 callers */

undefined4 __cdecl
FUN_0042e710(int param_1,uint param_2,ushort param_3,int param_4,byte param_5,short *param_6)

{
  short *psVar1;
  ushort uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  short *psVar7;
  int iVar8;
  short sVar9;
  undefined2 local_28;
  undefined4 uStack_26;
  undefined4 uStack_22;
  undefined1 local_1e;
  char cStack_1d;
  undefined4 local_1c;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_18 = 0xcc;
  local_17 = 0xcc;
  local_16 = 0xcc;
  local_15 = 0xcc;
  local_14 = 0xcc;
  local_13 = 0xcc;
  local_12 = 0xcc;
  local_11 = 0xcc;
  local_10 = 0xcc;
  local_f = 0xcc;
  local_e = 0xfb;
  local_d = 0x3f;
  local_1c = 1;
  uVar2 = param_3 & 0x7fff;
  if ((param_3 & 0x8000) == 0) {
    *(undefined1 *)(param_6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(param_6 + 1) = 0x2d;
  }
  if (((uVar2 == 0) && (param_2 == 0)) && (param_1 == 0)) {
    *(undefined1 *)(param_6 + 1) = 0x20;
    *param_6 = 0;
    *(undefined1 *)((int)param_6 + 3) = 1;
    *(undefined1 *)(param_6 + 2) = 0x30;
    *(undefined1 *)((int)param_6 + 5) = 0;
    return 1;
  }
  if (uVar2 == 0x7fff) {
    *param_6 = 1;
    if (((param_2 != 0x80000000) || (param_1 != 0)) && ((param_2 & 0x40000000) == 0)) {
      *(undefined4 *)(param_6 + 2) = DAT_00435464;
      param_6[4] = DAT_00435468;
      *(undefined1 *)(param_6 + 5) = DAT_0043546a;
      *(undefined1 *)((int)param_6 + 3) = 6;
      return 0;
    }
    if ((((param_3 & 0x8000) != 0) && (param_2 == 0xc0000000)) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = DAT_0043545c;
      param_6[4] = DAT_00435460;
      *(undefined1 *)((int)param_6 + 3) = 5;
      return 0;
    }
    if ((param_2 == 0x80000000) && (param_1 == 0)) {
      *(undefined4 *)(param_6 + 2) = DAT_00435454;
      param_6[4] = DAT_00435458;
      *(undefined1 *)((int)param_6 + 3) = 5;
      return 0;
    }
    *(undefined4 *)(param_6 + 2) = DAT_0043544c;
    param_6[4] = DAT_00435450;
    *(undefined1 *)(param_6 + 5) = DAT_00435452;
    *(undefined1 *)((int)param_6 + 3) = 6;
    return 0;
  }
  local_1e = (undefined1)uVar2;
  cStack_1d = (char)(uVar2 >> 8);
  sVar9 = (short)(((uint)(uVar2 >> 8) + (param_2 >> 0x18) * 2) * 0x4d + (uint)uVar2 * 0x4d10 +
                  -0x134312f4 >> 0x10);
  local_28 = 0;
  uStack_22 = param_2;
  uStack_26 = param_1;
  FUN_0042f110((int *)&local_28,-(int)sVar9,1);
  if (0x3ffe < CONCAT11(cStack_1d,local_1e)) {
    sVar9 = sVar9 + 1;
    FUN_0042ee60((int *)&local_28,(int *)&local_18);
  }
  *param_6 = sVar9;
  if (((param_5 & 1) != 0) && (param_4 = param_4 + sVar9, param_4 < 1)) {
    *(undefined1 *)(param_6 + 1) = 0x20;
    *param_6 = 0;
    *(undefined1 *)((int)param_6 + 3) = 1;
    *(undefined1 *)(param_6 + 2) = 0x30;
    *(undefined1 *)((int)param_6 + 5) = 0;
    return 1;
  }
  if (0x15 < param_4) {
    param_4 = 0x15;
  }
  iVar8 = 8;
  uVar2 = CONCAT11(cStack_1d,local_1e);
  local_1e = 0;
  cStack_1d = '\0';
  iVar4 = uVar2 - 0x3ffe;
  do {
    ___shl_12((uint *)&local_28);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if (iVar4 < 0) {
    for (uVar5 = -iVar4 & 0xff; uVar5 != 0; uVar5 = uVar5 - 1) {
      ___shr_12((uint *)&local_28);
    }
  }
  psVar1 = param_6 + 2;
  iVar8 = param_4 + 1;
  psVar7 = psVar1;
  psVar6 = psVar1;
  iVar4 = uStack_26;
  uVar5 = uStack_22;
  if (0 < iVar8) {
    do {
      uStack_22._2_2_ = (undefined2)(uVar5 >> 0x10);
      uStack_22._0_2_ = (undefined2)uVar5;
      uStack_26._2_2_ = (undefined2)((uint)iVar4 >> 0x10);
      uStack_26._0_2_ = (undefined2)iVar4;
      psVar6 = (short *)((int)psVar7 + 1);
      local_c = CONCAT22((undefined2)uStack_26,local_28);
      local_8 = CONCAT22((undefined2)uStack_22,uStack_26._2_2_);
      local_4 = CONCAT13(cStack_1d,CONCAT12(local_1e,uStack_22._2_2_));
      uStack_26 = iVar4;
      uStack_22 = uVar5;
      ___shl_12((uint *)&local_28);
      ___shl_12((uint *)&local_28);
      ___add_12((uint *)&local_28,&local_c);
      ___shl_12((uint *)&local_28);
      iVar8 = iVar8 + -1;
      *(char *)psVar7 = cStack_1d + '0';
      cStack_1d = '\0';
      psVar7 = psVar6;
      iVar4 = uStack_26;
      uVar5 = uStack_22;
    } while (iVar8 != 0);
  }
  psVar7 = psVar6 + -1;
  if (*(char *)((int)psVar6 + -1) < '5') {
    if (psVar7 < psVar1) {
LAB_0042ea89:
      *param_6 = 0;
      *(char *)psVar1 = '0';
      *(undefined1 *)(param_6 + 1) = 0x20;
      *(undefined1 *)((int)param_6 + 3) = 1;
      *(undefined1 *)((int)param_6 + 5) = 0;
      return 1;
    }
    do {
      if ((char)*psVar7 != '0') break;
      psVar7 = (short *)((int)psVar7 + -1);
    } while (psVar1 <= psVar7);
    if (psVar7 < psVar1) goto LAB_0042ea89;
    goto LAB_0042ea5b;
  }
  if (psVar7 < psVar1) {
LAB_0042ea55:
    *param_6 = *param_6 + 1;
    psVar7 = (short *)((int)psVar7 + 1);
  }
  else {
    do {
      if ((char)*psVar7 != '9') break;
      *(char *)psVar7 = '0';
      psVar7 = (short *)((int)psVar7 + -1);
    } while (psVar1 <= psVar7);
    if (psVar7 < psVar1) goto LAB_0042ea55;
  }
  *(char *)psVar7 = (char)*psVar7 + '\x01';
LAB_0042ea5b:
  cVar3 = ((char)psVar7 - (char)param_6) + -3;
  *(char *)((int)param_6 + 3) = cVar3;
  *(undefined1 *)(cVar3 + 4 + (int)param_6) = 0;
  return local_1c;
}



/* 0042eab0  FUN_0042eab0  102 bytes, 3 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042eab0(uint param_1)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = 0;
  puVar2 = &DAT_00435470;
  _DAT_00434858 = param_1;
  do {
    if (*puVar2 == param_1) {
      _DAT_00434854 = *(undefined4 *)(iVar1 * 8 + 0x435474);
      return;
    }
    puVar2 = puVar2 + 2;
    iVar1 = iVar1 + 1;
  } while (puVar2 < &DAT_004355d8);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    _DAT_00434854 = 0xd;
    return;
  }
  if ((0xbb < param_1) && (param_1 < 0xcb)) {
    _DAT_00434854 = 8;
    return;
  }
  _DAT_00434854 = 0x16;
  return;
}



/* 0042eb20  FUN_0042eb20  144 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0042eb20(uint param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  DWORD nStdHandle;
  
  if (param_1 < DAT_00438984) {
    piVar1 = (int *)((int)&DAT_00438990 + ((int)(param_1 & 0xffffffe7) >> 3));
    iVar2 = (param_1 & 0x1f) * 8;
    piVar3 = (int *)(*piVar1 + iVar2);
    if (((*(byte *)(piVar3 + 1) & 1) != 0) && (*piVar3 != -1)) {
      if (DAT_00434780 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_0042eb86;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_0042eb86:
      *(undefined4 *)(*piVar1 + iVar2) = 0xffffffff;
      return 0;
    }
  }
  _DAT_00434854 = 9;
  _DAT_00434858 = 0;
  return 0xffffffff;
}



/* 0042ebb0  FUN_0042ebb0  67 bytes, 3 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0042ebb0(uint param_1)

{
  undefined4 *puVar1;
  
  if ((param_1 < DAT_00438984) &&
     (puVar1 = (undefined4 *)
               (*(int *)((int)&DAT_00438990 + ((int)(param_1 & 0xffffffe7) >> 3)) +
               (param_1 & 0x1f) * 8), (*(byte *)(puVar1 + 1) & 1) != 0)) {
    return *puVar1;
  }
  _DAT_00434854 = 9;
  _DAT_00434858 = 0;
  return 0xffffffff;
}



/* 0042ec00  FUN_0042ec00  82 bytes, 1 callers */

LPVOID __cdecl FUN_0042ec00(int param_1,int param_2)

{
  LPVOID pvVar1;
  int iVar2;
  uint dwBytes;
  
  dwBytes = param_1 * param_2;
  if (dwBytes == 0) {
    dwBytes = 1;
  }
  do {
    if (dwBytes < 0xffffffe1) {
      pvVar1 = HeapAlloc(DAT_00438980,8,dwBytes);
    }
    else {
      pvVar1 = (LPVOID)0x0;
    }
    if (pvVar1 != (LPVOID)0x0) {
      return pvVar1;
    }
    if (DAT_00434eb0 == 0) {
      return (LPVOID)0x0;
    }
    iVar2 = FUN_0042c740(dwBytes);
  } while (iVar2 != 0);
  return (LPVOID)0x0;
}



/* 0042ec60  FUN_0042ec60  115 bytes, 0 callers */

int FUN_0042ec60(void)

{
  FILE *_File;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 3;
  if (3 < DAT_00437970) {
    iVar2 = 0xc;
    do {
      _File = *(FILE **)(DAT_00437974 + iVar2);
      if (_File != (FILE *)0x0) {
        if ((_File->_flag & 0x83U) != 0) {
          iVar1 = _fclose(_File);
          if (iVar1 != -1) {
            iVar3 = iVar3 + 1;
          }
        }
        if (0x4f < iVar2) {
          FUN_0042a030(*(LPVOID *)(DAT_00437974 + iVar2));
          *(undefined4 *)(DAT_00437974 + iVar2) = 0;
        }
      }
      iVar2 = iVar2 + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_00437970);
  }
  return iVar3;
}



/* 0042ece0  _fflush  76 bytes, 1 callers */

/* Library Function - Single Match
    _fflush
   
   Library: Visual Studio 1998 Release */

int __cdecl _fflush(FILE *_File)

{
  int iVar1;
  
  if (_File == (FILE *)0x0) {
    iVar1 = FUN_0042edb0(0);
    return iVar1;
  }
  iVar1 = __flush(_File);
  if (iVar1 != 0) {
    return -1;
  }
  if ((_File->_flag & 0x4000) != 0) {
    iVar1 = FUN_0042f200(_File->_file);
    return (iVar1 == 0) - 1;
  }
  return 0;
}



/* 0042ed30  __flush  100 bytes, 2 callers */

/* Library Function - Single Match
    __flush
   
   Library: Visual Studio 1998 Release */

int __cdecl __flush(FILE *_File)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  if ((((byte)_File->_flag & 3) == 2) && ((_File->_flag & 0x108U) != 0)) {
    uVar2 = (int)_File->_ptr - (int)_File->_base;
    if (0 < (int)uVar2) {
      uVar1 = FUN_0042d190(_File->_file,_File->_base,uVar2);
      if (uVar1 == uVar2) {
        if ((_File->_flag & 0x80U) != 0) {
          _File->_flag = _File->_flag & 0xfffffffd;
        }
      }
      else {
        _File->_flag = _File->_flag | 0x20;
        iVar3 = -1;
      }
    }
  }
  _File->_ptr = _File->_base;
  _File->_cnt = 0;
  return iVar3;
}



/* 0042edb0  FUN_0042edb0  107 bytes, 1 callers */

int __cdecl FUN_0042edb0(int param_1)

{
  FILE *_File;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = 0;
  iVar3 = 0;
  do {
    _File = *(FILE **)(DAT_00437974 + iVar4);
    if ((_File != (FILE *)0x0) && ((_File->_flag & 0x83U) != 0)) {
      if (param_1 == 1) {
        iVar1 = _fflush(_File);
        if (iVar1 != -1) {
          iVar2 = iVar2 + 1;
        }
      }
      else if ((param_1 == 0) && ((_File->_flag & 2U) != 0)) {
        iVar1 = _fflush(_File);
        if (iVar1 == -1) {
          iVar3 = -1;
        }
      }
    }
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x800);
  if (param_1 != 1) {
    iVar2 = iVar3;
  }
  return iVar2;
}



/* 0042ee20  FUN_0042ee20  49 bytes, 0 callers */

char * __cdecl FUN_0042ee20(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  
  iVar2 = -1;
  pcVar4 = param_1;
  do {
    pcVar3 = pcVar4;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar3 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar3;
  } while (cVar1 != '\0');
  bVar5 = pcVar3 + -1 == (char *)0x0;
  iVar2 = param_3;
  pcVar4 = param_2;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar4 == '\0';
    pcVar4 = pcVar4 + 1;
  } while (!bVar5);
  if (bVar5) {
    iVar2 = iVar2 + 1;
  }
  pcVar4 = pcVar3 + -1;
  for (iVar2 = -(iVar2 - param_3); iVar2 != 0; iVar2 = iVar2 + -1) {
    *pcVar4 = *param_2;
    param_2 = param_2 + 1;
    pcVar4 = pcVar4 + 1;
  }
  *pcVar4 = '\0';
  return param_1;
}



/* 0042ee60  FUN_0042ee60  678 bytes, 2 callers */

void __cdecl FUN_0042ee60(int *param_1,int *param_2)

{
  uint *puVar1;
  ushort uVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  ushort local_1a;
  undefined4 local_18;
  short local_14 [4];
  int local_c;
  int local_8;
  int local_4;
  
  local_18._0_1_ = 0;
  local_18._1_1_ = 0;
  local_18._2_2_ = 0;
  local_14[0] = 0;
  local_14[1] = 0;
  local_14[2] = 0;
  local_14[3] = 0;
  uVar2 = (*(ushort *)((int)param_2 + 10) ^ *(ushort *)((int)param_1 + 10)) & 0x8000;
  uVar4 = *(ushort *)((int)param_1 + 10) & 0x7fff;
  uVar5 = *(ushort *)((int)param_2 + 10) & 0x7fff;
  local_1a = uVar4 + uVar5;
  if (((0x7ffe < uVar4) || (0x7ffe < uVar5)) || (0xbffd < local_1a)) {
    param_1[1] = 0;
    *param_1 = 0;
    param_1[2] = (-(uint)(uVar2 == 0) & 0x80000000) - 0x8000;
    return;
  }
  if (local_1a < 0x3fc0) {
    param_1[2] = 0;
    param_1[1] = 0;
    *param_1 = 0;
    return;
  }
  if (((uVar4 == 0) && (local_1a = local_1a + 1, (param_1[2] & 0x7fffffffU) == 0)) &&
     ((param_1[1] == 0 && (*param_1 == 0)))) {
    *(undefined2 *)((int)param_1 + 10) = 0;
    return;
  }
  if (((uVar5 == 0) && (local_1a = local_1a + 1, (param_2[2] & 0x7fffffffU) == 0)) &&
     ((param_2[1] == 0 && (*param_2 == 0)))) {
    param_1[2] = 0;
    param_1[1] = 0;
    *param_1 = 0;
    return;
  }
  local_8 = 0;
  local_c = 0;
  do {
    iVar7 = 8;
    iVar8 = local_c * 2;
    local_4 = 5 - local_c;
    if (0 < 5 - local_c) {
      puVar1 = (uint *)((int)&local_18 + local_8);
      do {
        iVar3 = FUN_0042ddb0(*puVar1,(uint)*(ushort *)(iVar7 + (int)param_2) *
                                     (uint)*(ushort *)(iVar8 + (int)param_1),puVar1);
        if (iVar3 != 0) {
          *(short *)((int)local_14 + local_8) = *(short *)((int)local_14 + local_8) + 1;
        }
        iVar8 = iVar8 + 2;
        iVar7 = iVar7 + -2;
        local_4 = local_4 + -1;
      } while (local_4 != 0);
    }
    local_8 = local_8 + 2;
    local_c = local_c + 1;
  } while (local_c < 5);
  local_1a = local_1a + 0xc002;
  if (0 < (short)local_1a) {
    do {
      if ((local_14[3] & 0x8000U) != 0) break;
      ___shl_12(&local_18);
      local_1a = local_1a - 1;
    } while (0 < (short)local_1a);
    if (0 < (short)local_1a) goto LAB_0042f033;
  }
  local_1a = local_1a - 1;
  if ((short)local_1a < 0) {
    iVar8 = CONCAT22(local_18._2_2_,CONCAT11(local_18._1_1_,(byte)local_18));
    sVar6 = -local_1a;
    local_1a = 0;
    do {
      if (((byte)local_18 & 1) != 0) {
        iVar8 = iVar8 + 1;
      }
      ___shr_12(&local_18);
      sVar6 = sVar6 + -1;
    } while (sVar6 != 0);
  }
  else {
    iVar8 = CONCAT22(local_18._2_2_,CONCAT11(local_18._1_1_,(byte)local_18));
  }
  if (iVar8 != 0) {
    local_18._0_1_ = (byte)local_18 | 1;
  }
LAB_0042f033:
  iVar7 = CONCAT22(local_14[2],local_14[1]);
  iVar8 = CONCAT22(local_14[0],local_18._2_2_);
  if (0x8000 < CONCAT11(local_18._1_1_,(byte)local_18)) {
    if (CONCAT22(local_14[0],local_18._2_2_) == -1) {
      iVar8 = 0;
      if (CONCAT22(local_14[2],local_14[1]) == -1) {
        if (local_14[3] == 0xffff) {
          local_14[3] = 0x8000;
          local_1a = local_1a + 1;
          iVar7 = 0;
          iVar8 = 0;
        }
        else {
          local_14[3] = local_14[3] + 1;
          iVar7 = 0;
          iVar8 = 0;
        }
      }
      else {
        iVar7 = CONCAT22(local_14[2],local_14[1]) + 1;
      }
    }
    else {
      iVar8 = CONCAT22(local_14[0],local_18._2_2_) + 1;
      iVar7 = CONCAT22(local_14[2],local_14[1]);
    }
  }
  local_14[0] = (short)((uint)iVar8 >> 0x10);
  local_18._2_2_ = (undefined2)iVar8;
  local_14[2] = (short)((uint)iVar7 >> 0x10);
  local_14[1] = (short)iVar7;
  if (local_1a < 0x7fff) {
    *(undefined2 *)param_1 = local_18._2_2_;
    *(uint *)((int)param_1 + 2) = CONCAT22(local_14[1],local_14[0]);
    *(uint *)((int)param_1 + 6) = CONCAT22(local_14[3],local_14[2]);
    *(ushort *)((int)param_1 + 10) = uVar2 | local_1a;
    return;
  }
  param_1[1] = 0;
  *param_1 = 0;
  param_1[2] = (-(uint)(uVar2 == 0) & 0x80000000) - 0x8000;
  return;
}



/* 0042f110  FUN_0042f110  123 bytes, 2 callers */

void __cdecl FUN_0042f110(int *param_1,uint param_2,int param_3)

{
  ushort *puVar1;
  uint uVar2;
  ushort *puVar3;
  uint uVar4;
  undefined *puVar5;
  ushort local_c;
  undefined4 uStack_a;
  undefined2 uStack_6;
  undefined4 local_4;
  
  puVar5 = &DAT_00435580;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      puVar5 = &DAT_004356e0;
    }
    if (param_3 == 0) {
      *(undefined2 *)param_1 = 0;
    }
    while (param_2 != 0) {
      puVar5 = puVar5 + 0x54;
      uVar4 = (int)param_2 >> 3;
      uVar2 = param_2 & 7;
      param_2 = uVar4;
      if (uVar2 != 0) {
        puVar1 = (ushort *)(puVar5 + uVar2 * 0xc);
        puVar3 = puVar1;
        if (0x7fff < *puVar1) {
          puVar3 = &local_c;
          local_c = (ushort)*(undefined4 *)puVar1;
          uStack_a._0_2_ = (undefined2)((uint)*(undefined4 *)puVar1 >> 0x10);
          uStack_a._2_2_ = (undefined2)*(undefined4 *)(puVar1 + 2);
          uStack_6 = (undefined2)((uint)*(undefined4 *)(puVar1 + 2) >> 0x10);
          local_4 = *(undefined4 *)(puVar1 + 4);
          uStack_a = CONCAT22(uStack_a._2_2_,(undefined2)uStack_a) + -1;
        }
        FUN_0042ee60(param_1,(int *)puVar3);
      }
    }
  }
  return;
}



/* 0042f190  _fclose  112 bytes, 1 callers */

/* Library Function - Single Match
    _fclose
   
   Library: Visual Studio 1998 Release */

int __cdecl _fclose(FILE *_File)

{
  int iVar1;
  int iVar2;
  
  iVar2 = -1;
  if ((_File->_flag & 0x40U) != 0) {
    _File->_flag = 0;
    return -1;
  }
  if ((_File->_flag & 0x83U) != 0) {
    iVar2 = __flush(_File);
    __freebuf(_File);
    iVar1 = __close(_File->_file);
    if (iVar1 < 0) {
      iVar2 = -1;
    }
    else if (_File->_tmpfname != (char *)0x0) {
      FUN_0042a030(_File->_tmpfname);
      _File->_tmpfname = (char *)0x0;
    }
  }
  _File->_flag = 0;
  return iVar2;
}



/* 0042f200  FUN_0042f200  111 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0042f200(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  undefined4 uVar3;
  
  if ((param_1 < DAT_00438984) &&
     ((*(byte *)(*(int *)((int)&DAT_00438990 + ((int)(param_1 & 0xffffffe7) >> 3)) + 4 +
                (param_1 & 0x1f) * 8) & 1) != 0)) {
    hFile = (HANDLE)FUN_0042ebb0(param_1);
    BVar1 = FlushFileBuffers(hFile);
    DVar2 = 0;
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    uVar3 = 0;
    if (DVar2 != 0) {
      _DAT_00434854 = 9;
      _DAT_00434858 = DVar2;
      return 0xffffffff;
    }
  }
  else {
    _DAT_00434854 = 9;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



/* 0042f270  __freebuf  57 bytes, 1 callers */

/* Library Function - Single Match
    __freebuf
   
   Library: Visual Studio 1998 Release */

void __cdecl __freebuf(FILE *_File)

{
  if (((_File->_flag & 0x83U) != 0) && ((_File->_flag & 8U) != 0)) {
    FUN_0042a030(_File->_base);
    _File->_ptr = (char *)0x0;
    _File->_flag = _File->_flag & 0xfffffbf7;
    _File->_base = (char *)0x0;
    _File->_cnt = 0;
  }
  return;
}



/* 0042f2b0  __close  199 bytes, 1 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __close
   
   Library: Visual Studio 1998 Release */

int __cdecl __close(int _FileHandle)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  HANDLE hObject;
  BOOL BVar5;
  DWORD DVar6;
  
  if (DAT_00438984 <= (uint)_FileHandle) {
    _DAT_00434854 = 9;
    _DAT_00434858 = 0;
    return -1;
  }
  piVar1 = (int *)((int)&DAT_00438990 + ((int)(_FileHandle & 0xffffffe7U) >> 3));
  iVar2 = (_FileHandle & 0x1fU) * 8;
  if ((*(byte *)(*piVar1 + 4 + iVar2) & 1) == 0) {
    _DAT_00434854 = 9;
    _DAT_00434858 = 0;
    return -1;
  }
  if ((_FileHandle == 1) || (_FileHandle == 2)) {
    iVar3 = FUN_0042ebb0(1);
    iVar4 = FUN_0042ebb0(2);
    if (iVar3 != iVar4) goto LAB_0042f30b;
  }
  else {
LAB_0042f30b:
    hObject = (HANDLE)FUN_0042ebb0(_FileHandle);
    BVar5 = CloseHandle(hObject);
    if (BVar5 == 0) {
      DVar6 = GetLastError();
      goto LAB_0042f32b;
    }
  }
  DVar6 = 0;
LAB_0042f32b:
  FUN_0042eb20(_FileHandle);
  if (DVar6 == 0) {
    *(undefined1 *)(*piVar1 + 4 + iVar2) = 0;
    return 0;
  }
  FUN_0042eab0(DVar6);
  return -1;
}



/* 0042f378  RtlUnwind  6 bytes, 2 callers */

void RtlUnwind(PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue)

{
                    /* WARNING: Could not recover jumptable at 0x0042f378. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnwind(TargetFrame,TargetIp,ExceptionRecord,ReturnValue);
  return;
}


