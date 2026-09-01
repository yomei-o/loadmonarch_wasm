/* 004150b0 */

void __fastcall FUN_004150b0(void *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((*(int *)((int)param_1 + 0x238) == 0) || (*(int *)((int)param_1 + 0x238) == 0x3c)) {
    FUN_004146f0(param_1);
    *(undefined4 *)((int)param_1 + 0x254) = 1;
    *(undefined4 *)((int)param_1 + 0x25c) = 1;
    *(undefined4 *)((int)param_1 + 600) = 0;
    *(undefined1 *)((int)param_1 + 0x91a0) = 4;
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    cVar1 = *(char *)((int)param_1 + 0x9388) + '\f';
    *(char *)((int)param_1 + 0x9260) = *(char *)((int)param_1 + 0x9388) + '\b';
    *(char *)((int)param_1 + 0x91e8) = cVar1;
    *(char *)((int)param_1 + 0x9248) = cVar1;
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    *(undefined4 *)((int)param_1 + 0x6668) = 100;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x6664) = *DAT_00434534;
    *(undefined1 *)((int)param_1 + 0x6660) = 2;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x9250) = 0;
    *(undefined1 *)((int)param_1 + 0x6661) = 2;
  }
  iVar2 = *(int *)((int)param_1 + 0x238);
  if (iVar2 == 4) {
    *(undefined4 *)((int)param_1 + 600) = 1;
    *(undefined4 *)((int)param_1 + 0x25c) = 1;
  }
  if (iVar2 == 6) {
    *(undefined4 *)((int)param_1 + 600) = 2;
    *(undefined4 *)((int)param_1 + 0x25c) = 1;
  }
  if (iVar2 == 8) {
    *(undefined4 *)((int)param_1 + 600) = 2;
    *(undefined4 *)((int)param_1 + 0x25c) = 2;
  }
  if (iVar2 == 0xd) {
    *(undefined1 *)((int)param_1 + 0x6880) = 0;
  }
  if (iVar2 == 0x10) {
    *(undefined4 *)((int)param_1 + 600) = 2;
    *(undefined4 *)((int)param_1 + 0x25c) = 3;
  }
  if (iVar2 == 0x12) {
    *(undefined4 *)((int)param_1 + 600) = 2;
    *(undefined4 *)((int)param_1 + 0x25c) = 4;
  }
  if (iVar2 == 0x14) {
    *(undefined4 *)((int)param_1 + 600) = 1;
    *(undefined4 *)((int)param_1 + 0x25c) = 4;
  }
  if (iVar2 == 0x16) {
    *(undefined4 *)((int)param_1 + 600) = 0;
    *(undefined4 *)((int)param_1 + 0x25c) = 4;
  }
  if (iVar2 == 0x19) {
    *(undefined1 *)((int)param_1 + 0x6880) = 2;
  }
  if ((0x18 < iVar2) && (iVar2 < 0x27)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x300c0 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0xa00 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x80);
  }
  if ((0x1a < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x21)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x380c0 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               ((*(int *)((int)param_1 + 0x238) * 0x10 + *(int *)((int)param_1 + 0x244)) * 0xa0 +
                -0x10400 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x10);
  }
  if ((0x20 < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x27)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x30090 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c38 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x30);
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x33090 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c38 + *(int *)((int)param_1 + 0x22c));
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x10);
  }
  iVar2 = *(int *)((int)param_1 + 0x238);
  if (iVar2 == 0x2d) {
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 6;
    *(undefined1 *)((int)param_1 + 0x667d) = 6;
    *(undefined1 *)((int)param_1 + 0x667e) = 0;
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined4 *)((int)param_1 + 0x6674) = 4;
    *(undefined1 *)((int)param_1 + 0x667f) = 0;
  }
  if (iVar2 == 0x32) {
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    *(undefined1 *)((int)param_1 + 0x91a0) = 0;
  }
  if (iVar2 == 0x35) {
    *(undefined4 *)((int)param_1 + 0x6674) = 4;
    *(undefined1 *)((int)param_1 + 0x667c) = 2;
    *(undefined1 *)((int)param_1 + 0x667d) = 2;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667f) = 4;
  }
  if (iVar2 == 0x3b) {
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
  }
  if (iVar2 < 0x29) {
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
      iVar2 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar2;
    } while (iVar2 < 0x20);
  }
  iVar2 = *(int *)((int)param_1 + 0x238);
  if (iVar2 < 10) {
    FUN_0040a870(0,8,8,9,s_1_Choose_character_00433b50,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    return;
  }
  if (iVar2 < 0xf) {
    FUN_0040a870(0,8,4,5,s_Left_button_00433b44,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    return;
  }
  if (iVar2 < 0x19) {
    FUN_0040a870(0,8,8,9,s_2_Choose_destination_00433b2c,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    return;
  }
  if (iVar2 < 0x1b) {
    FUN_0040a870(0,8,4,5,s_Left_button_00433b44,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    return;
  }
  if (iVar2 < 0x24) {
    FUN_0040a870(0,8,8,9,s_3_Choose_order_00433b1c,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    return;
  }
  if (iVar2 < 0x29) {
    FUN_0040a870(0,8,4,5,s_Left_button_00433b44,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  return;
}


