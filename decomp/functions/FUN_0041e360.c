/* 0041e360 */

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


