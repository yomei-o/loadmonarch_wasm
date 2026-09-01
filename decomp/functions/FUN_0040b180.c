/* 0040b180 */

void __cdecl FUN_0040b180(void *param_1)

{
  LPCSTR pCVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  pCVar1 = &DAT_00435b31;
  iVar2 = 0;
  do {
    FUN_0040e310(param_1,iVar3 + 0x9c90U,pCVar1,0);
    if ((*(byte *)(DAT_00434534 + 4 + iVar2) & 0x40) != 0) {
      FUN_0040e440(param_1,iVar3 + 0x9c90U,1);
    }
    iVar2 = iVar2 + 0x38;
    pCVar1 = pCVar1 + 0x11;
    iVar3 = iVar3 + 1;
  } while (pCVar1 < &DAT_00435b75);
  return;
}


