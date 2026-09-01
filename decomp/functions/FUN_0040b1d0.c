/* 0040b1d0 */

void __cdecl FUN_0040b1d0(void *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int *piVar4;
  CHAR local_104 [260];
  
  iVar1 = 0;
  piVar4 = &DAT_004344f8;
  iVar2 = 0;
  puVar3 = &DAT_00435b31;
  do {
    wsprintfA(local_104,&DAT_00432100,puVar3);
    FUN_0040e310(param_1,iVar2 + 0xea66,local_104,0);
    if (*piVar4 != 0) {
      FUN_0040e420(param_1,iVar2 + 0xea66);
    }
    if ((*(byte *)(DAT_00434534 + 4 + iVar1) & 0x40) != 0) {
      FUN_0040e440(param_1,iVar2 + 0xea66,1);
    }
    iVar1 = iVar1 + 0x38;
    piVar4 = piVar4 + 1;
    puVar3 = puVar3 + 0x11;
    iVar2 = iVar2 + 1;
  } while (puVar3 < &DAT_00435b75);
  return;
}


