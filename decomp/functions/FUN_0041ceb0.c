/* 0041ceb0 */

int __cdecl FUN_0041ceb0(int param_1)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar1 = 0;
  pbVar3 = (byte *)(DAT_0043453c + 0x10);
  iVar2 = 0x900;
  do {
    if (((uint)*pbVar3 - param_1 == 8) || ((uint)*pbVar3 - param_1 == 0xc)) {
      iVar1 = iVar1 + 1;
    }
    pbVar3 = pbVar3 + 0x18;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return iVar1;
}


