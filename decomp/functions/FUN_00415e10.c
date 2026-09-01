/* 00415e10 */

void __fastcall FUN_00415e10(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((*(int *)((int)param_1 + 0x238) == 0x4b) || (*(int *)((int)param_1 + 0x238) == 0)) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    *(undefined4 *)((int)param_1 + 0x6668) = 100;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    *(undefined1 *)((int)param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38);
    *(undefined1 *)((int)param_1 + 0x9250) = 0;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x91b8) = 0x39;
    *(undefined1 *)((int)param_1 + 0x9320) = 0x48;
    *(undefined1 *)((int)param_1 + 0x6660) = 2;
    *(undefined1 *)((int)param_1 + 0x6661) = 2;
    *(undefined1 *)((int)param_1 + 0x9230) = 0x38;
    *(undefined1 *)((int)param_1 + 0x92a8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9380) = 0x41;
    *(undefined1 *)((int)param_1 + 0x9338) = 0x31;
    *(undefined1 *)((int)param_1 + 0x9350) = 0x31;
    *(undefined1 *)((int)param_1 + 0x9368) = 0x31;
    *(undefined1 *)((int)param_1 + 0x9308) = 0x32;
    *(undefined1 *)((int)param_1 + 0x9290) = 0x32;
    *(undefined1 *)((int)param_1 + 0x9218) = 0x32;
    *(undefined1 *)((int)param_1 + 0x91a0) = 0x32;
  }
  switch(*(int *)((int)param_1 + 0x238)) {
  case 2:
    *(char *)((int)param_1 + 0x9260) = *(char *)((int)param_1 + 0x9388) + '\b';
    break;
  case 10:
    *(char *)((int)param_1 + 0x91e8) = *(char *)((int)param_1 + 0x9388) + '\f';
    break;
  case 0xc:
    *(char *)((int)param_1 + 0x92d8) = *(char *)((int)param_1 + 0x9388) + '\f';
    break;
  case 0xe:
    *(char *)((int)param_1 + 0x9248) = *(char *)((int)param_1 + 0x9388) + '\f';
    break;
  case 0x10:
    *(char *)((int)param_1 + 0x9278) = *(char *)((int)param_1 + 0x9388) + '\f';
    break;
  case 0x12:
    *(char *)((int)param_1 + 0x91d0) = *(char *)((int)param_1 + 0x9388) + '\f';
    break;
  case 0x14:
    *(char *)((int)param_1 + 0x92c0) = *(char *)((int)param_1 + 0x9388) + '\f';
    break;
  case 0x16:
    *(char *)((int)param_1 + 0x9200) = *(char *)((int)param_1 + 0x9388) + '\f';
    break;
  case 0x18:
    *(char *)((int)param_1 + 0x92f0) = *(char *)((int)param_1 + 0x9388) + '\f';
    break;
  case 0x1e:
  case 0x28:
  case 0x32:
  case 0x3c:
    *(undefined1 *)((int)param_1 + 0x6890) = 4;
    *(undefined1 *)((int)param_1 + 0x6894) = 0;
    *(undefined1 *)((int)param_1 + 0x6aa4) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6891) = 1;
    *(undefined4 *)((int)param_1 + 0x688c) = 100;
    *(undefined1 *)((int)param_1 + 0x6888) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38);
    *(undefined1 *)((int)param_1 + 0x6884) = 0;
    *(undefined1 *)((int)param_1 + 0x6885) = 0;
    *(undefined4 *)((int)param_1 + 0x6898) = 4;
    *(undefined1 *)((int)param_1 + 0x68a2) = 4;
    *(undefined1 *)((int)param_1 + 0x68a3) = 4;
    *(undefined4 *)((int)param_1 + 0x689c) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x9130) = 1;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 6;
    *(undefined1 *)((int)param_1 + 0x68a1) = 6;
    break;
  case 0x2d:
    *(undefined4 *)((int)param_1 + 0x6668) = 1000;
    break;
  case 0x41:
    *(undefined4 *)((int)param_1 + 0x6668) = 10000;
  }
  if (*(int *)((int)param_1 + 0x238) < 0x14) {
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
    FUN_0040a870(4,8,8,9,s_Sets_up_a_base_00433ce4,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(4,0x28,8,9,s_and_stays_there__00433cd0,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  if ((0x1d < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x2d)) {
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
    piVar1 = (int *)((int)param_1 + 0x938c);
    FUN_0040a870(4,8,8,9,s_Later__00433cc8,*(HDC *)((int)param_1 + 0x224),1,piVar1);
    FUN_0040a870(4,0x28,8,9,s_more_units_will_00433cb8,*(HDC *)((int)param_1 + 0x224),1,piVar1);
    FUN_0040a870(4,0x68,8,9,s_gather_there__00433ca8,*(HDC *)((int)param_1 + 0x224),1,piVar1);
  }
  if ((0x2c < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x37)) {
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
    FUN_0040a870(0x10,0x68,8,9,s_Population_00433c9c,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0x10,0x88,8,9,s_1_000_or_more_00433c8c,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  if ((0x40 < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x4b)) {
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
    FUN_0040a870(0x10,0x68,8,9,s_Population_00433c9c,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0x10,0x88,8,9,s_10_000_or_more_00433c7c,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  return;
}


