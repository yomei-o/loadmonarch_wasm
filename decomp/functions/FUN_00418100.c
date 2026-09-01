/* 00418100 */

void __fastcall FUN_00418100(void *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((*(int *)((int)param_1 + 0x238) == 0) || (*(int *)((int)param_1 + 0x238) == 0x28)) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x666c) = 4;
    *(undefined4 *)((int)param_1 + 0x6668) = 1000;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    *(undefined1 *)((int)param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38);
    *(undefined1 *)((int)param_1 + 0x6660) = 0;
    *(undefined1 *)((int)param_1 + 0x9160) = 0;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x91b8) = 0x62;
    *(undefined1 *)((int)param_1 + 0x92a8) = 0x62;
    *(undefined1 *)((int)param_1 + 0x6661) = 2;
    *(undefined1 *)((int)param_1 + 0x9140) = 99;
    *(undefined1 *)((int)param_1 + 0x9230) = 5;
    *(undefined1 *)((int)param_1 + 0x9320) = 0x66;
    *(undefined1 *)((int)param_1 + 0x9158) = 0x6d;
    *(undefined1 *)((int)param_1 + 0x9380) = 0x6c;
    *(undefined1 *)((int)param_1 + 0x9308) = 0x6b;
    *(undefined1 *)((int)param_1 + 0x9218) = 0x6e;
    *(undefined1 *)((int)param_1 + 0x91a0) = 0x69;
    *(undefined1 *)((int)param_1 + 0x9188) = 0x67;
    *(undefined1 *)((int)param_1 + 0x9158) = 0x6d;
    *(undefined1 *)((int)param_1 + 0x9338) = 0x65;
    *(undefined1 *)((int)param_1 + 0x9350) = 0x65;
    *(undefined1 *)((int)param_1 + 0x9368) = 0x65;
  }
  iVar2 = *(int *)((int)param_1 + 0x238);
  switch(iVar2) {
  case 0:
  case 6:
    *(undefined1 *)((int)param_1 + 0x6890) = 4;
    *(undefined1 *)((int)param_1 + 0x6891) = 1;
    *(undefined1 *)((int)param_1 + 0x6894) = 0;
    *(undefined1 *)((int)param_1 + 0x6aa4) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6888) = 4;
    *(undefined1 *)((int)param_1 + 0x6885) = 0;
    *(undefined1 *)((int)param_1 + 0x9220) = 1;
    *(undefined4 *)((int)param_1 + 0x6898) = 4;
    *(undefined4 *)((int)param_1 + 0x688c) = 1000;
    *(undefined4 *)((int)param_1 + 0x689c) = 0x1e;
    *(undefined4 *)((int)param_1 + 0x689c) = 0;
    *(undefined1 *)((int)param_1 + 0x68a0) = 6;
    *(undefined1 *)((int)param_1 + 0x68a1) = 6;
    *(undefined1 *)((int)param_1 + 0x68a2) = 6;
    *(undefined1 *)((int)param_1 + 0x68a3) = 6;
    *(undefined1 *)((int)param_1 + 0x6884) = 2;
    *(undefined1 *)((int)param_1 + 0x666c) = 4;
    break;
  case 3:
  case 9:
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    break;
  case 5:
  case 0xb:
    *(undefined1 *)((int)param_1 + 0x9280) = 0x14;
    break;
  case 0xc:
    *(undefined4 *)((int)param_1 + 0x6674) = 3;
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667d) = 2;
    *(undefined1 *)((int)param_1 + 0x667c) = 4;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    break;
  case 0x12:
    *(undefined1 *)((int)param_1 + 0x666c) = 2;
    break;
  case 0x14:
    *(undefined1 *)((int)param_1 + 0x9230) = 0x6a;
  }
  if ((9 < iVar2) && (iVar2 < 0x23)) {
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
    FUN_0040a870(0x10,0x48,8,9,s_None_appear_00433e68,*(HDC *)((int)param_1 + 0x224),1,piVar1);
    FUN_0040a870(0x10,0x68,8,9,s_if_exit_is_00433e5c,*(HDC *)((int)param_1 + 0x224),1,piVar1);
    FUN_0040a870(0x10,0x88,8,9,s_destroyed__00433e50,*(HDC *)((int)param_1 + 0x224),1,piVar1);
  }
  return;
}


