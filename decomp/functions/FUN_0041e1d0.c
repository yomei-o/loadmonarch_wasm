/* 0041e1d0 */

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


