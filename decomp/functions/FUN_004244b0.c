/* 004244b0 */

void __cdecl FUN_004244b0(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((DAT_004376a1 != '\0') &&
     (iVar2 = param_1 * 0x2000 + 0xc0 + param_2, iVar1 = param_2, 0 < param_2)) {
    do {
      iVar3 = 0;
      if (0 < param_2) {
        do {
          if (*(char *)(DAT_00435fd4 + iVar2 + iVar3) != 'p') {
            *(undefined1 *)(iVar3 + param_5) = *(undefined1 *)(DAT_00435fd4 + iVar2 + iVar3);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < param_2);
      }
      param_5 = param_5 + param_3;
      iVar2 = iVar2 + 0x100;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


