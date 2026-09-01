/* 00417b20 */

void __fastcall FUN_00417b20(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((*(int *)((int)param_1 + 0x238) == 0) || (*(int *)((int)param_1 + 0x238) == 0x3c)) {
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
    *(undefined1 *)((int)param_1 + 0x9170) = 0x38;
    *(undefined1 *)((int)param_1 + 0x92d8) = 0x3a;
    *(undefined1 *)((int)param_1 + 0x9350) = 0x3a;
    *(undefined1 *)((int)param_1 + 0x91d0) = 0x34;
    *(undefined1 *)((int)param_1 + 0x91e8) = 0x5a;
    *(undefined1 *)((int)param_1 + 0x9260) = 0x25;
  }
  iVar1 = *(int *)((int)param_1 + 0x238);
  switch(iVar1) {
  case 2:
    *(undefined1 *)((int)param_1 + 0x6890) = 6;
    *(undefined1 *)((int)param_1 + 0x6891) = 1;
    *(undefined1 *)((int)param_1 + 0x6894) = 0;
    *(undefined1 *)((int)param_1 + 0x6aa4) = 0xff;
    *(undefined4 *)((int)param_1 + 0x688c) = 1000;
    *(undefined1 *)((int)param_1 + 0x6885) = 1;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 0;
    *(undefined1 *)((int)param_1 + 0x68a1) = 0;
    *(undefined1 *)((int)param_1 + 0x68a2) = 6;
    *(undefined1 *)((int)param_1 + 0x68a3) = 6;
    *(undefined1 *)((int)param_1 + 0x68a4) = 6;
    *(undefined1 *)((int)param_1 + 0x9328) = 1;
    *(undefined1 *)((int)param_1 + 0x6888) = 4;
    *(undefined1 *)((int)param_1 + 0x6884) = 4;
    *(undefined4 *)((int)param_1 + 0x6898) = 5;
    break;
  case 9:
  case 0x2b:
    *(undefined1 *)((int)param_1 + 0x9280) = 0x14;
    break;
  case 0xc:
    *(undefined4 *)((int)param_1 + 0x6674) = 3;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 2;
    *(undefined1 *)((int)param_1 + 0x667d) = 4;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    break;
  case 0x11:
    *(undefined1 *)((int)param_1 + 0x666c) = 2;
    break;
  case 0x14:
    *(undefined1 *)((int)param_1 + 0x9260) = 0x7a;
    break;
  case 0x16:
    *(undefined1 *)((int)param_1 + 0x6891) = 1;
    *(undefined1 *)((int)param_1 + 0x6894) = 0;
    *(undefined1 *)((int)param_1 + 0x6885) = 1;
    *(undefined1 *)((int)param_1 + 0x6888) = 4;
    *(undefined1 *)((int)param_1 + 0x6884) = 4;
    *(undefined1 *)((int)param_1 + 0x6aa4) = 0xff;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 0;
    *(undefined1 *)((int)param_1 + 0x68a1) = 0;
    *(undefined1 *)((int)param_1 + 0x9328) = 1;
    *(undefined1 *)((int)param_1 + 0x6890) = 6;
    *(undefined4 *)((int)param_1 + 0x688c) = 1000;
    *(undefined4 *)((int)param_1 + 0x6898) = 2;
    break;
  case 0x19:
    *(undefined1 *)((int)param_1 + 0x6890) = 6;
    break;
  case 0x1a:
    *(undefined4 *)((int)param_1 + 0x6898) = 2;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 4;
    *(undefined1 *)((int)param_1 + 0x68a1) = 4;
    break;
  case 0x1d:
    *(undefined1 *)((int)param_1 + 0x9328) = 0x14;
    break;
  case 0x1e:
    *(undefined4 *)((int)param_1 + 0x6674) = 2;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 4;
    *(undefined1 *)((int)param_1 + 0x667d) = 4;
    break;
  case 0x20:
    *(undefined1 *)((int)param_1 + 0x6891) = 1;
    *(undefined1 *)((int)param_1 + 0x6894) = 0;
    *(undefined1 *)((int)param_1 + 0x6aa4) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6885) = 1;
    *(undefined1 *)((int)param_1 + 0x6888) = 2;
    *(undefined4 *)((int)param_1 + 0x6898) = 2;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 0;
    *(undefined1 *)((int)param_1 + 0x68a1) = 0;
    *(undefined1 *)((int)param_1 + 0x9328) = 1;
    *(undefined1 *)((int)param_1 + 0x6890) = 6;
    *(undefined4 *)((int)param_1 + 0x688c) = 100;
    *(undefined1 *)((int)param_1 + 0x6884) = 4;
    break;
  case 0x21:
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    break;
  case 0x23:
    *(undefined1 *)((int)param_1 + 0x6890) = 6;
    break;
  case 0x26:
    *(undefined1 *)((int)param_1 + 0x9260) = 0x25;
    break;
  case 0x28:
    *(undefined4 *)((int)param_1 + 0x6898) = 2;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 6;
    *(undefined1 *)((int)param_1 + 0x68a1) = 6;
  }
  if ((0x11 < iVar1) && (iVar1 < 0x1d)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      puVar2 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar3 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x3c00 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar2 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar3 = (undefined4 *)
               (*(int *)((int)param_1 + 0x244) * 0xa0 + 0x5000 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      iVar1 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
    FUN_0040a870(0x10,0x68,8,9,s_Blocks_out_00433e44,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0x10,0x88,8,9,s_unwanted_units_00433e34,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  if ((0x1f < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x23)) {
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
      iVar1 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
    FUN_0040a870(0x10,8,8,9,s_but____00433d38,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  if ((0x25 < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x3a)) {
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
    FUN_0040a870(0,8,8,9,s_Enemy_units_can_00433e24,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0,0x28,8,9,s_still_pass_through__00433e10,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  return;
}


