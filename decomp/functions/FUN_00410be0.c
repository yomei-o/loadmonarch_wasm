/* 00410be0 */

void __fastcall FUN_00410be0(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)((int)param_1 + 0x238) == 0) {
    FUN_0040a870(0x16,0x14,6,7,s_You_have_be_defeated_00433760,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    FUN_0040a870(0x16,0x23,6,7,s_Please_try_again___0043372c,*(HDC *)((int)param_1 + 0x224),0,
                 (int *)0x0);
    FUN_0040a870(0x52,0x6e,2,3,s_Game_Over_00433754,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    if (*(int *)((int)param_1 + 0x238) == 0) {
      *(undefined4 *)((int)param_1 + 0x260) = 0xe0;
      *(undefined4 *)((int)param_1 + 0x264) = 0xd0;
      *(byte *)((int)param_1 + 0x36a) = (DAT_004365cd | 0xc) << 3;
      *(byte *)((int)param_1 + 0x36c) = DAT_004365cd;
      *(undefined1 *)((int)param_1 + 0x369) = 2;
      FUN_00411340(param_1,0,3,1);
      iVar1 = 1;
      puVar2 = (undefined4 *)((int)param_1 + 0x378);
      iVar3 = 0x20;
      do {
        *puVar2 = 0xe0;
        iVar4 = iVar3 + 0x10;
        puVar2[1] = 0xd0;
        *(byte *)((int)puVar2 + 0x10a) = DAT_004365cd << 3;
        *(byte *)(puVar2 + 0x43) = DAT_004365cd;
        *(undefined1 *)((int)puVar2 + 0x109) = 2;
        FUN_00411340(param_1,iVar1,iVar1 + 4,(short)iVar3);
        iVar1 = iVar1 + 1;
        puVar2 = puVar2 + 0x46;
        iVar3 = iVar4;
      } while (iVar4 < 0x70);
    }
  }
  return;
}


