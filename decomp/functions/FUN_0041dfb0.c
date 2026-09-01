/* 0041dfb0 */

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


