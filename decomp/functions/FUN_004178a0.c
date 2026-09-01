/* 004178a0 */

void __fastcall FUN_004178a0(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((*(int *)((int)param_1 + 0x238) == 0) || (*(int *)((int)param_1 + 0x238) == 0x19)) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    *(undefined4 *)((int)param_1 + 0x6668) = 1000;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    *(undefined1 *)((int)param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38);
    *(undefined1 *)((int)param_1 + 0x6660) = 0;
    *(undefined1 *)((int)param_1 + 0x9190) = 0;
    *(undefined1 *)((int)param_1 + 0x9140) = 0x30;
    *(undefined1 *)((int)param_1 + 0x9230) = 0x38;
    *(undefined1 *)((int)param_1 + 0x92a8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9320) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9158) = 0x30;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x6661) = 4;
    *(undefined1 *)((int)param_1 + 0x91b8) = 0x44;
    *(undefined1 *)((int)param_1 + 0x91d0) = 0x34;
    *(undefined1 *)((int)param_1 + 0x91e8) = 0x3c;
    *(undefined1 *)((int)param_1 + 0x9260) = 0x7b;
    *(undefined1 *)((int)param_1 + 0x92d8) = 0x3b;
    *(undefined1 *)((int)param_1 + 0x9350) = 0x3a;
    *(undefined1 *)((int)param_1 + 0x9170) = 0x38;
  }
  iVar1 = *(int *)((int)param_1 + 0x238);
  switch(iVar1) {
  case 2:
    *(undefined4 *)((int)param_1 + 0x6674) = 3;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 2;
    *(undefined1 *)((int)param_1 + 0x667d) = 4;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    break;
  case 7:
    *(undefined1 *)((int)param_1 + 0x666c) = 2;
    break;
  case 10:
    *(undefined1 *)((int)param_1 + 0x9260) = 0;
    break;
  case 0xf:
    *(undefined1 *)((int)param_1 + 0x6660) = 2;
    *(undefined4 *)((int)param_1 + 0x6674) = 4;
    *(undefined1 *)((int)param_1 + 0x667c) = 2;
    *(undefined1 *)((int)param_1 + 0x667d) = 2;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    *(undefined1 *)((int)param_1 + 0x667f) = 4;
    *(undefined1 *)((int)param_1 + 0x6661) = 3;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    break;
  case 0x14:
    *(undefined1 *)((int)param_1 + 0x9328) = 0x14;
  }
  if ((5 < iVar1) && (iVar1 < 0x12)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar2 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar3 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar2 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar3 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x1400 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      iVar1 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
    FUN_0040a870(0x10,8,8,9,s_Destroying_barriers_00433dfc,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0x10,0x28,8,9,s_will_allow_passage_00433de8,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  return;
}


