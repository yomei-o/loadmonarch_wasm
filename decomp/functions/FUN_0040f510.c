/* 0040f510 */

void __fastcall FUN_0040f510(void *param_1)

{
  char cVar1;
  WPARAM WVar2;
  int iVar3;
  
  iVar3 = (int)param_1 + 0x120;
  WVar2 = FUN_0040ec30(param_1,0x3f7);
  FUN_0040ec70(param_1,0x3f7,WVar2,iVar3);
  iVar3 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + iVar3 + 0x120);
    if ((cVar1 == '.') || (cVar1 == '\0')) break;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xff);
  *(undefined1 *)((int)param_1 + iVar3 + 0x120) = 0x2e;
  *(undefined1 *)((int)param_1 + iVar3 + 0x121) = 100;
  *(undefined1 *)((int)param_1 + iVar3 + 0x122) = 0x73;
  *(undefined1 *)((int)param_1 + iVar3 + 0x123) = 0x37;
  *(undefined1 *)((int)param_1 + iVar3 + 0x124) = 0;
  return;
}


