/* 00411050 */

void __fastcall FUN_00411050(void *param_1)

{
  LPSTR _Dest;
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int local_8 [2];
  
  if (*(int *)((int)param_1 + 0x238) == 0) {
    local_8[0] = 0x100;
    local_8[1] = 0x100;
    FUN_0040a870(0x16,0x14,6,7,s_Single_map_mode_00433800,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    _Dest = (LPSTR)((int)param_1 + 0x1c);
    FUN_0040a870(0x16,0x23,6,7,s_Please_try_again___0043372c,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    FUN_0041a650(&DAT_004376c8,DAT_0043450c);
    wsprintfA(_Dest,s_Map_d__s_004336a4,DAT_0043450c + 1);
    FUN_0040a870(0x16,0x49,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),1,local_8);
    wsprintfA(_Dest,s_Area_P_E___6d__6d_004337e8,DAT_00436414);
    FUN_0040a870(0x16,0x5f,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    _sprintf(_Dest,s_Area__3_2f_Per__00433688,(double)DAT_0043641c);
    FUN_0040a870(0x16,0x6e,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    if (DAT_00436410 == 0) {
      wsprintfA(_Dest,s_Penalty_no_count_004336f4);
    }
    else {
      wsprintfA(_Dest,s_Penalty__6d_days_00433640);
    }
    FUN_0040a870(0x16,0x7d,4,5,_Dest,*(HDC *)((int)param_1 + 0x224),0,local_8);
    wsprintfA(_Dest,s_Losses__6d__6d_004337d0,DAT_00436424);
    FUN_0040a870(0x16,0x8f,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,local_8);
    _sprintf(_Dest,s_Battle_effic__3_2f_Per_004337b4,(double)DAT_0043642c);
    FUN_0040a870(0x16,0x9e,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,local_8);
    wsprintfA(_Dest,s_Bonus__6d_days_00433658);
    FUN_0040a870(0x16,0xad,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,local_8);
    if (*(int *)((int)param_1 + 0x238) == 0) {
      *(undefined4 *)((int)param_1 + 0x260) = 0xe0;
      *(undefined4 *)((int)param_1 + 0x264) = 0xd0;
      iVar2 = 1;
      *(byte *)((int)param_1 + 0x36a) = (DAT_004365cd | 0xc) << 3;
      iVar4 = 0x20;
      pbVar3 = (byte *)((int)param_1 + 0x482);
      *(byte *)((int)param_1 + 0x36c) = DAT_004365cd;
      *(undefined1 *)((int)param_1 + 0x369) = 2;
      FUN_00411340(param_1,0,0xd,1);
      do {
        pbVar3[-0xffffffff0000010a] = 0xe0;
        pbVar3[-0xffffffff00000109] = 0;
        pbVar3[-0xffffffff00000108] = 0;
        pbVar3[-0xffffffff00000107] = 0;
        pbVar3[-0xffffffff00000106] = 0xd0;
        pbVar3[-0xffffffff00000105] = 0;
        pbVar3[-0xffffffff00000104] = 0;
        pbVar3[-0xffffffff00000103] = 0;
        *pbVar3 = DAT_004365cd << 3;
        pbVar3[2] = DAT_004365cd;
        iVar1 = FUN_0041abd0(3);
        pbVar3[-1] = (char)iVar1 + 1;
        FUN_00411340(param_1,iVar2,0xd,(short)iVar4);
        iVar1 = FUN_0041abd0(100);
        if (iVar1 < 0x1e) {
          *pbVar3 = *pbVar3 | 0x40;
        }
        else if (iVar1 < 0x3c) {
          *pbVar3 = *pbVar3 | 0x20;
        }
        iVar4 = iVar4 + 0x10;
        pbVar3 = pbVar3 + 0x118;
        iVar2 = iVar2 + 1;
      } while (iVar4 < 0x110);
    }
  }
  return;
}


