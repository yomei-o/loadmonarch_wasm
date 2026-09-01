/* 0041e0a0 */

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


