/* 00401000 */

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


