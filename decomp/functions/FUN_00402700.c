/* 00402700 */

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


