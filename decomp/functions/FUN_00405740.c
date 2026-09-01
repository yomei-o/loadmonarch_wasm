/* 00405740 */

void __cdecl FUN_00405740(int param_1,int param_2,undefined1 *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  do {
    cVar1 = *(char *)(param_1 + iVar2);
    if ((cVar1 == '.') || (cVar1 == '\0')) break;
    *(char *)(param_2 + iVar2) = cVar1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xff);
  *(undefined1 *)(param_2 + iVar2) = 0x2e;
  iVar3 = iVar2 + 3;
  *(undefined1 *)(param_2 + -2 + iVar3) = *param_3;
  *(undefined1 *)(param_2 + -1 + iVar3) = param_3[1];
  *(undefined1 *)(param_2 + iVar3) = param_3[2];
  *(undefined1 *)(iVar2 + 4 + param_2) = 0;
  return;
}


