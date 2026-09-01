/* 0041e560 */

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


