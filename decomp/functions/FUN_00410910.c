/* 00410910 */

void __fastcall FUN_00410910(void *param_1)

{
  LPSTR _Dest;
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_8 [2];
  
  if (*(int *)((int)param_1 + 0x238) == 0) {
    FUN_0040ffe0((int)param_1);
    FUN_0040a870(0x16,0xf,6,7,s_Bravo__you_win__004336dc,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0
                );
    FUN_0040a870(0x16,0x1d,6,7,s_But_day_s_over_00433740,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0
                );
    _Dest = (LPSTR)((int)param_1 + 0x1c);
    FUN_0040a870(0x16,0x2b,6,7,s_Please_try_again___0043372c,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    local_8[0] = 0x100;
    local_8[1] = 0x100;
    FUN_0041a650(&DAT_004376c8,DAT_0043450c);
    wsprintfA(_Dest,s_Map_d__s_004336a4,DAT_0043450c + 1);
    FUN_0040a870(0x16,0x49,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,local_8);
    _sprintf(_Dest,s_Area__3_2f_Per__00433688,(double)DAT_0043641c);
    FUN_0040a870(0x16,0x5f,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,local_8);
    wsprintfA(_Dest,s_Remaining__6d_days_00433670);
    FUN_0040a870(0x16,0x6e,2,3,_Dest,*(HDC *)((int)param_1 + 0x224),0,local_8);
    FUN_0040a870(0x16,0x7d,2,3,s_Bonus_no_count_00433710,*(HDC *)((int)param_1 + 0x224),0,local_8);
    FUN_0040a870(0x16,0x8c,4,5,s_Penalty_no_count_004336f4,*(HDC *)((int)param_1 + 0x224),0,local_8)
    ;
    if (*(int *)((int)param_1 + 0x238) == 0) {
      *(undefined4 *)((int)param_1 + 0x260) = 0xe0;
      *(undefined4 *)((int)param_1 + 0x264) = 0xd0;
      *(byte *)((int)param_1 + 0x36a) = (DAT_004365cd | 0xc) << 3;
      bVar1 = DAT_004365cd;
      *(undefined1 *)((int)param_1 + 0x369) = 2;
      *(byte *)((int)param_1 + 0x36c) = bVar1;
      FUN_00411340(param_1,0,1,1);
      *(undefined4 *)((int)param_1 + 0x13e0) = 0;
      *(undefined4 *)((int)param_1 + 0x13e4) = 0xd0;
      iVar5 = 0x20;
      *(undefined1 *)((int)param_1 + 0x14ea) = 0xc0;
      *(undefined1 *)((int)param_1 + 0x14ec) = 4;
      *(undefined1 *)((int)param_1 + 0x14e9) = 1;
      pbVar3 = (byte *)((int)param_1 + 0x482);
      FUN_00411340(param_1,0x10,2,0x16);
      local_8[0] = 1;
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
        pbVar3[-1] = 2;
        FUN_00411340(param_1,local_8[0],0xc,(short)iVar5);
        iVar2 = FUN_0041abd0(100);
        if (iVar2 < 0x1e) {
          *pbVar3 = *pbVar3 | 0x40;
        }
        else if (iVar2 < 0x3c) {
          *pbVar3 = *pbVar3 | 0x20;
        }
        iVar5 = iVar5 + 0x10;
        pbVar3 = pbVar3 + 0x118;
        local_8[0] = local_8[0] + 1;
      } while (iVar5 < 0x110);
    }
  }
  if (0x39 < *(int *)((int)param_1 + 0x238)) {
    *(undefined4 *)((int)param_1 + 0x248) = 0;
    do {
      iVar5 = *(int *)((int)param_1 + 0x248) * 0x100;
      puVar4 = (undefined4 *)(DAT_00435fd4 + 0x38030 + iVar5);
      puVar6 = (undefined4 *)(iVar5 + 0x3868 + (int)param_1);
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      iVar5 = *(int *)((int)param_1 + 0x248) + 1;
      *(int *)((int)param_1 + 0x248) = iVar5;
    } while (iVar5 < 0x20);
  }
  return;
}


