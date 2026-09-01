/* 0041c780 */

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


