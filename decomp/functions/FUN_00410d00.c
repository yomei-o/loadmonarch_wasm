/* 00410d00 */

void __fastcall FUN_00410d00(void *param_1)

{
  LPSTR _Dest;
  int iVar1;
  code *pcVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  HDC pHVar6;
  
  pcVar2 = wsprintfA_exref;
  if (*(int *)((int)param_1 + 0x238) == 0) {
    FUN_0040ffe0((int)param_1);
    FUN_0040a870(0x16,0x14,6,7,s_Bravo__you_win__004336dc,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    FUN_0040a870(0x16,0x23,6,7,s_Go_to_the_next_stage_004336c4,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    _Dest = (LPSTR)((int)param_1 + 0x1c);
    FUN_0040a870(0x16,0x32,6,7,s__004336b0,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    FUN_0041a650(&DAT_004376c8,DAT_0043450c);
    pcVar2 = wsprintfA_exref;
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
    (*pcVar2)((LPCSTR)((int)param_1 + 0x1c),s_Total_bonus__6d_days_00433628);
    FUN_0040a870(0x16,0xaa,2,3,(LPCSTR)((int)param_1 + 0x1c),*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
  }
  if ((*(int *)((int)param_1 + 0x238) < 0x14) || (0x50 < *(int *)((int)param_1 + 0x238)))
  goto LAB_00410f7d;
  if (DAT_00436438 == 0) {
    FUN_0040ffe0((int)param_1);
    (*pcVar2)((int)param_1 + 0x1c);
    pHVar6 = *(HDC *)((int)param_1 + 0x224);
    iVar5 = 7;
    iVar4 = 6;
  }
  else {
    if (DAT_00436438 < 1) {
      FUN_0040ffe0((int)param_1);
      (*pcVar2)((int)param_1 + 0x1c,s_You_lose__d_days__00433778);
      pHVar6 = *(HDC *)((int)param_1 + 0x224);
    }
    else {
      FUN_0040ffe0((int)param_1);
      (*pcVar2)((int)param_1 + 0x1c,s_You_gain__d_days__0043378c);
      pHVar6 = *(HDC *)((int)param_1 + 0x224);
      if ((*(byte *)((int)param_1 + 0x238) & 1) != 0) {
        iVar5 = 7;
        iVar4 = 6;
        goto LAB_00410f71;
      }
    }
    iVar5 = 5;
    iVar4 = 4;
  }
LAB_00410f71:
  FUN_0040a870(0x16,0x1e,iVar4,iVar5,(LPCSTR)((int)param_1 + 0x1c),pHVar6,0,(int *)0x0);
LAB_00410f7d:
  if (*(int *)((int)param_1 + 0x238) == 0) {
    *(undefined4 *)((int)param_1 + 0x260) = 0;
    *(undefined4 *)((int)param_1 + 0x264) = 0xd0;
    iVar4 = 1;
    *(byte *)((int)param_1 + 0x36a) = (DAT_004365cd | 0xc) << 3;
    iVar5 = 0x20;
    pbVar3 = (byte *)((int)param_1 + 0x482);
    *(byte *)((int)param_1 + 0x36c) = DAT_004365cd;
    *(undefined1 *)((int)param_1 + 0x369) = 2;
    FUN_00411340(param_1,0,4,1);
    do {
      pbVar3[-0xffffffff0000010a] = 0;
      pbVar3[-0xffffffff00000109] = 0;
      pbVar3[-0xffffffff00000108] = 0;
      pbVar3[-0xffffffff00000107] = 0;
      pbVar3[-0xffffffff00000106] = 0xd0;
      pbVar3[-0xffffffff00000105] = 0;
      pbVar3[-0xffffffff00000104] = 0;
      pbVar3[-0xffffffff00000103] = 0;
      *pbVar3 = DAT_004365cd << 3;
      pbVar3[2] = DAT_004365cd;
      pbVar3[-1] = 2;
      FUN_00411340(param_1,iVar4,4,(short)iVar5);
      iVar1 = FUN_0041abd0(100);
      if (iVar1 < 0x1e) {
        *pbVar3 = *pbVar3 | 0x40;
      }
      else if (iVar1 < 0x3c) {
        *pbVar3 = *pbVar3 | 0x20;
      }
      iVar5 = iVar5 + 0x10;
      pbVar3 = pbVar3 + 0x118;
      iVar4 = iVar4 + 1;
    } while (iVar5 < 0x110);
  }
  return;
}


