/* 0041dc60 */

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


