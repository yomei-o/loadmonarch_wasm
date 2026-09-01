/* 004164a0 */

void __fastcall FUN_004164a0(void *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((*(int *)((int)param_1 + 0x238) == 0x14) || (*(int *)((int)param_1 + 0x238) == 0)) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x666c) = 2;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined4 *)((int)param_1 + 0x6668) = 1000;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    iVar2 = (uint)*(byte *)((int)param_1 + 0x9388) * 0x38;
    *(undefined1 *)((int)param_1 + 0x6664) = *(undefined1 *)(DAT_00434534 + iVar2);
    *(undefined1 *)((int)param_1 + 0x6660) = 2;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x6aa4) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6661) = 2;
    *(undefined1 *)((int)param_1 + 0x6894) = 0;
    *(undefined1 *)((int)param_1 + 0x6890) = 6;
    *(undefined4 *)((int)param_1 + 0x688c) = 1000;
    *(undefined1 *)((int)param_1 + 0x6891) = 1;
    cVar1 = *(char *)(DAT_00434534 + iVar2);
    *(undefined1 *)((int)param_1 + 0x6884) = 2;
    *(undefined1 *)((int)param_1 + 0x6885) = 0;
    *(undefined4 *)((int)param_1 + 0x689c) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x6cc8) = 0xff;
    *(byte *)((int)param_1 + 0x6888) = cVar1 + 1U & 3;
    *(undefined1 *)((int)param_1 + 0x6ab8) = 0;
    *(undefined1 *)((int)param_1 + 0x6ab4) = 6;
    *(undefined1 *)((int)param_1 + 0x6ab5) = 1;
    *(undefined4 *)((int)param_1 + 0x6ab0) = 1000;
    *(undefined1 *)((int)param_1 + 0x6aac) = *(undefined1 *)(DAT_00434534 + iVar2);
    *(undefined1 *)((int)param_1 + 0x6aa8) = 0;
    *(undefined1 *)((int)param_1 + 0x9250) = 0;
    *(undefined1 *)((int)param_1 + 0x9190) = 2;
    *(undefined4 *)((int)param_1 + 0x6ac0) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x6aa9) = 4;
    *(undefined1 *)((int)param_1 + 0x9230) = 0;
    *(undefined1 *)((int)param_1 + 0x9220) = 1;
    *(undefined1 *)((int)param_1 + 0x9140) = 0x30;
    *(undefined1 *)((int)param_1 + 0x9320) = 0x30;
    *(undefined1 *)((int)param_1 + 0x9248) = 0x7a;
    *(undefined1 *)((int)param_1 + 0x91b8) = 0x34;
    *(undefined1 *)((int)param_1 + 0x92a8) = 0x31;
    *(undefined1 *)((int)param_1 + 0x91d0) = 0x5a;
    *(undefined1 *)((int)param_1 + 0x92c0) = 0x59;
    *(undefined1 *)((int)param_1 + 0x9158) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9338) = 0x38;
  }
  iVar2 = *(int *)((int)param_1 + 0x238);
  if (iVar2 == 5) {
    *(undefined4 *)((int)param_1 + 0x6668) = 100;
  }
  else if (iVar2 == 10) {
    *(undefined4 *)((int)param_1 + 0x6ac0) = 0;
    *(undefined4 *)((int)param_1 + 0x6abc) = 4;
    *(undefined1 *)((int)param_1 + 0x6ac4) = 4;
    *(undefined1 *)((int)param_1 + 0x6ac5) = 4;
    *(undefined1 *)((int)param_1 + 0x6ac6) = 2;
    *(undefined1 *)((int)param_1 + 0x6ac7) = 2;
  }
  else if (iVar2 == 0xf) {
    *(undefined4 *)((int)param_1 + 0x6668) = 1000;
  }
  if ((9 < iVar2) && (iVar2 < 0x1e)) {
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
    FUN_0040a870(0x10,8,8,9,s_Useful_for_00433d08,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    FUN_0040a870(0x10,0x28,8,9,s_reinforcing_units_00433cf4,*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
  }
  return;
}


