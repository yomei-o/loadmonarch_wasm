/* 004158e0 */

void __fastcall FUN_004158e0(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((*(int *)((int)param_1 + 0x238) == 0) || (*(int *)((int)param_1 + 0x238) == 0x50)) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    *(undefined4 *)((int)param_1 + 0x6668) = 100;
    *(undefined1 *)((int)param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38);
    *(undefined1 *)((int)param_1 + 0x9250) = 0;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x6660) = 2;
    *(undefined1 *)((int)param_1 + 0x6661) = 2;
    *(undefined1 *)((int)param_1 + 0x9230) = 0x7b;
    *(undefined1 *)((int)param_1 + 0x9350) = 0x7b;
    *(undefined1 *)((int)param_1 + 0x9140) = 4;
    *(undefined1 *)((int)param_1 + 0x9320) = 4;
    *(undefined1 *)((int)param_1 + 0x9380) = 4;
    *(undefined1 *)((int)param_1 + 0x91a0) = 4;
  }
  switch(*(int *)((int)param_1 + 0x238)) {
  case 5:
    *(char *)((int)param_1 + 0x9260) = *(char *)((int)param_1 + 0x9388) + '\b';
    break;
  case 10:
    *(undefined4 *)((int)param_1 + 0x6674) = 2;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 0;
    *(undefined1 *)((int)param_1 + 0x667d) = 0;
    break;
  case 0x12:
    *(char *)((int)param_1 + 0x9170) = *(char *)((int)param_1 + 0x9388) + '\b';
    break;
  case 0x14:
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined4 *)((int)param_1 + 0x6674) = 2;
    *(undefined1 *)((int)param_1 + 0x667c) = 2;
    *(undefined1 *)((int)param_1 + 0x667d) = 2;
    break;
  case 0x1d:
    *(char *)((int)param_1 + 0x9140) = *(char *)((int)param_1 + 0x9388) + '\b';
    break;
  case 0x1e:
    *(undefined4 *)((int)param_1 + 0x6674) = 6;
    *(undefined1 *)((int)param_1 + 0x667c) = 4;
    *(undefined1 *)((int)param_1 + 0x667d) = 6;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    *(undefined1 *)((int)param_1 + 0x667f) = 4;
    *(undefined1 *)((int)param_1 + 0x6681) = 4;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x6680) = 2;
    break;
  case 0x28:
    *(char *)((int)param_1 + 0x9320) = *(char *)((int)param_1 + 0x9388) + '\b';
    break;
  case 0x2c:
    *(undefined4 *)((int)param_1 + 0x6674) = 6;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 6;
    *(undefined1 *)((int)param_1 + 0x667d) = 0;
    *(undefined1 *)((int)param_1 + 0x667e) = 6;
    *(undefined1 *)((int)param_1 + 0x667f) = 6;
    *(undefined1 *)((int)param_1 + 0x6680) = 4;
    *(undefined1 *)((int)param_1 + 0x6681) = 6;
    break;
  case 0x37:
    *(char *)((int)param_1 + 0x9380) = *(char *)((int)param_1 + 0x9388) + '\b';
    break;
  case 0x38:
    *(undefined4 *)((int)param_1 + 0x6674) = 2;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 0;
    *(undefined1 *)((int)param_1 + 0x667d) = 0;
    break;
  case 0x3c:
    *(char *)((int)param_1 + 0x9290) = *(char *)((int)param_1 + 0x9388) + '\b';
    break;
  case 0x41:
    *(undefined4 *)((int)param_1 + 0x6674) = 2;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 0;
    *(undefined1 *)((int)param_1 + 0x667d) = 0;
    break;
  case 0x46:
    *(char *)((int)param_1 + 0x91a0) = *(char *)((int)param_1 + 0x9388) + '\b';
    break;
  case 0x4a:
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
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
    FUN_0040a870(4,8,8,9,s_Unit_will_think_and_00433c68,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(4,0x28,8,9,s_act_on_it_s_own__00433c54,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  if ((0x27 < *(int *)((int)param_1 + 0x238)) && (*(int *)((int)param_1 + 0x238) < 0x3d)) {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
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
    FUN_0040a870(4,0x28,8,9,s_But_they_00433c48,*(HDC *)((int)param_1 + 0x224),1,piVar1);
    FUN_0040a870(4,0x48,8,9,s_won_t_remove_00433c38,*(HDC *)((int)param_1 + 0x224),1,piVar1);
    FUN_0040a870(4,0x68,8,9,s_any_barriers_00433c28,*(HDC *)((int)param_1 + 0x224),1,piVar1);
    FUN_0040a870(4,0x88,8,9,s_without_orders__00433c18,*(HDC *)((int)param_1 + 0x224),1,piVar1);
  }
  return;
}


