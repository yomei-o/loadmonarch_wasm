/* 0040a210 */

void FUN_0040a210(void)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  CHAR local_104 [260];
  
  pcVar4 = SetWindowTextA_exref;
  if (DAT_004376ab != '\0') {
    pcVar1 = s_Quest_004323fc;
    if (DAT_004365cc == '\0') {
      pcVar1 = s_Single_004323f4;
    }
    iVar2 = DAT_0043450c + 1;
    pcVar3 = FUN_0041a650(&DAT_004376c8,DAT_0043450c);
    wsprintfA(local_104,s__s__s__d___s_004323e4,&DAT_004376dc,pcVar3,iVar2,pcVar1);
    pcVar4 = SetWindowTextA_exref;
    SetWindowTextA(*(HWND *)(DAT_004344e4 + 8),local_104);
  }
  if (DAT_004344e8 != 0) {
    pcVar1 = s_Quest_004323fc;
    if (DAT_004365cc == '\0') {
      pcVar1 = s_Single_004323f4;
    }
    iVar2 = DAT_0043450c + 1;
    pcVar3 = FUN_0041a650(&DAT_004376c8,DAT_0043450c);
    wsprintfA(local_104,s__s__s__d___s_004323e4,s_Map_Window_004323d8,pcVar3,iVar2,pcVar1);
    (*pcVar4)(*(undefined4 *)(DAT_004344e8 + 8),local_104);
  }
  return;
}


