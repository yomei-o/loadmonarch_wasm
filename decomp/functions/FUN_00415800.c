/* 00415800 */

void __fastcall FUN_00415800(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 0x238) == 0) {
    *(undefined1 *)(param_1 + 0x6880) = 0xff;
    *(undefined1 *)(param_1 + 0x6670) = 0;
    *(undefined1 *)(param_1 + 0x666c) = 6;
    *(undefined4 *)(param_1 + 0x6668) = 100;
    *(undefined1 *)(param_1 + 0x666d) = 1;
    *(undefined1 *)(param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)(param_1 + 0x9388) * 0x38);
    *(undefined1 *)(param_1 + 0x9250) = 0;
    *(undefined4 *)(param_1 + 0x6678) = 0x1e;
  }
  *(undefined4 *)(param_1 + 0x244) = 0;
  do {
    puVar2 = (undefined4 *)(*(int *)(param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x244) * 0xa0 + *(int *)(param_1 + 0x22c));
    for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    iVar1 = *(int *)(param_1 + 0x244) + 1;
    *(int *)(param_1 + 0x244) = iVar1;
  } while (iVar1 < 0x20);
  FUN_0040a870(8,8,8,9,s_Hanging_around_00433c08,*(HDC *)(param_1 + 0x224),1,
               (int *)(param_1 + 0x938c));
  return;
}


