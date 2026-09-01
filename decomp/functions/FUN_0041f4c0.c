/* 0041f4c0 */

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


