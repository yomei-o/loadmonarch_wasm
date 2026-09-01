/* 00410680 */

void __fastcall FUN_00410680(void *param_1)

{
  LPSTR _Dest;
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  byte *pbVar5;
  
  pcVar4 = wsprintfA_exref;
  if (*(int *)((int)param_1 + 0x238) == 0) {
    FUN_0040ffe0((int)param_1);
    FUN_0040a870(0x16,0x14,6,7,s_Bravo__you_win__004336dc,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    FUN_0040a870(0x16,0x23,6,7,s_Go_to_the_next_stage_004336c4,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    _Dest = (LPSTR)((int)param_1 + 0x1c);
    FUN_0040a870(0x16,0x32,6,7,s__004336b0,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    FUN_0041a650(&DAT_004376c8,DAT_0043450c);
    pcVar4 = wsprintfA_exref;
    wsprintfA(_Dest,s_Map_d__s_004336a4,DAT_0043450c + 1);
    FUN_0040a870(0x16,0x49,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    _sprintf(_Dest,s_Area__3_2f_Per__00433688,(double)DAT_0043641c);
    FUN_0040a870(0x16,0x5f,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    wsprintfA(_Dest,s_Remaining__6d_days_00433670);
    FUN_0040a870(0x16,0x6e,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    wsprintfA(_Dest,s_Bonus__6d_days_00433658);
    FUN_0040a870(0x16,0x7d,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    wsprintfA(_Dest,s_Penalty__6d_days_00433640);
    FUN_0040a870(0x16,0x8c,4,5,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
  }
  if (*(int *)((int)param_1 + 0x238) == 0x14) {
    (*pcVar4)((LPCSTR)((int)param_1 + 0x1c),s_Total_bonus__6d_days_00433628);
    FUN_0040a870(0x16,0xaa,2,3,(LPCSTR)((int)param_1 + 0x1c),*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
  }
  if (*(int *)((int)param_1 + 0x238) == 0) {
    *(undefined4 *)((int)param_1 + 0x260) = 0xe0;
    *(undefined4 *)((int)param_1 + 0x264) = 0xd0;
    iVar3 = 1;
    *(byte *)((int)param_1 + 0x36a) = (DAT_004365cd | 0xc) << 3;
    iVar2 = 0x20;
    pbVar5 = (byte *)((int)param_1 + 0x482);
    *(byte *)((int)param_1 + 0x36c) = DAT_004365cd;
    *(undefined1 *)((int)param_1 + 0x369) = 2;
    FUN_00411340(param_1,0,0,1);
    do {
      pbVar5[-0xffffffff0000010a] = 0xe0;
      pbVar5[-0xffffffff00000109] = 0;
      pbVar5[-0xffffffff00000108] = 0;
      pbVar5[-0xffffffff00000107] = 0;
      pbVar5[-0xffffffff00000106] = 0xd0;
      pbVar5[-0xffffffff00000105] = 0;
      pbVar5[-0xffffffff00000104] = 0;
      pbVar5[-0xffffffff00000103] = 0;
      *pbVar5 = DAT_004365cd << 3;
      pbVar5[2] = DAT_004365cd;
      pbVar5[-1] = 2;
      FUN_00411340(param_1,iVar3,0,(short)iVar2);
      iVar1 = FUN_0041abd0(100);
      if (iVar1 < 0x1e) {
        *pbVar5 = *pbVar5 | 0x40;
      }
      else if (iVar1 < 0x3c) {
        *pbVar5 = *pbVar5 | 0x20;
      }
      iVar2 = iVar2 + 0x10;
      pbVar5 = pbVar5 + 0x118;
      iVar3 = iVar3 + 1;
    } while (iVar2 < 0x110);
  }
  return;
}


