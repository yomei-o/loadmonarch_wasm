/* 00417190 */

void __fastcall FUN_00417190(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((*(int *)((int)param_1 + 0x238) == 0) || (*(int *)((int)param_1 + 0x238) == 0x3e)) {
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
    *(undefined1 *)((int)param_1 + 0x91b8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9230) = 0x38;
    *(undefined1 *)((int)param_1 + 0x92a8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9320) = 0x38;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x6661) = 4;
    *(undefined1 *)((int)param_1 + 0x9140) = 0x44;
    *(undefined1 *)((int)param_1 + 0x9158) = 0x34;
    *(undefined1 *)((int)param_1 + 0x9170) = 0x5a;
    *(undefined1 *)((int)param_1 + 0x91e8) = 0x7a;
    *(undefined1 *)((int)param_1 + 0x9260) = 0x3a;
    *(undefined1 *)((int)param_1 + 0x92d8) = 0x3a;
    *(undefined1 *)((int)param_1 + 0x9350) = 0x3a;
  }
  iVar2 = *(int *)((int)param_1 + 0x238);
  switch(iVar2) {
  case 2:
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667d) = 4;
    *(undefined4 *)((int)param_1 + 0x6674) = 2;
    *(undefined1 *)((int)param_1 + 0x667c) = 2;
    break;
  case 7:
    *(undefined1 *)((int)param_1 + 0x666c) = 2;
    break;
  case 10:
    *(undefined1 *)((int)param_1 + 0x91e8) = 0x25;
    break;
  case 0xf:
    *(undefined4 *)((int)param_1 + 0x6674) = 4;
    *(undefined1 *)((int)param_1 + 0x667c) = 2;
    *(undefined1 *)((int)param_1 + 0x667d) = 2;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    *(undefined1 *)((int)param_1 + 0x6660) = 1;
    *(undefined1 *)((int)param_1 + 0x6661) = 3;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667f) = 4;
    break;
  case 0x14:
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    break;
  case 0x28:
    *(undefined1 *)((int)param_1 + 0x92d8) = 0x25;
  }
  if ((7 < iVar2) && (iVar2 < 0x12)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x1400 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
    FUN_0040a870(0x10,8,8,9,s_Repairing_paths_00433dd8,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0x10,0x28,8,9,s_will_let_you_pass_00433dc4,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  if ((0x13 < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x1e)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c00 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x5000 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
    FUN_0040a870(0x10,0x68,8,9,s_and_you_can_also_00433db0,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0x10,0x88,8,9,s_build_new_ones_00433da0,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  if ((0x1d < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x28)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x2800 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c00 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x5000 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
    piVar1 = (int *)((int)param_1 + 0x938c);
    FUN_0040a870(0x10,0x48,8,9,s_but_doing_so_00433d90,*(HDC *)((int)param_1 + 0x224),1,piVar1);
    FUN_0040a870(0x10,0x68,8,9,s_will_cost_you_3_000_00433d7c,*(HDC *)((int)param_1 + 0x224),1,
                 piVar1);
    FUN_0040a870(0x10,0x88,8,9,s_cash_points_so_00433d6c,*(HDC *)((int)param_1 + 0x224),1,piVar1);
  }
  if ((0x28 < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x33)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c00 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
    FUN_0040a870(0x10,0x68,8,9,s_plan_carefully__00433d5c,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  return;
}


