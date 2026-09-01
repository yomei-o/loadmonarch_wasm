/* 0041c300 */

void FUN_0041c300(int param_1)

{
  uint uVar1;
  int iVar2;
  CHAR local_100 [256];
  
  if (*(int *)(param_1 + 8) == -0x208) {
    iVar2 = LoadStringA(DAT_004344d0,*(UINT *)(param_1 + 4),local_100,0x100);
    if (0 < iVar2) {
      uVar1 = *(uint *)(param_1 + 4);
      if ((0x9c8f < uVar1) && (uVar1 < 0x9c94)) {
        wsprintfA(local_100,&DAT_00433fb4,uVar1 * 0x11 + 0x38f5a1);
      }
      *(CHAR **)(param_1 + 0xc) = local_100;
    }
  }
  return;
}


