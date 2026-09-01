/* 004149a0 */

void __fastcall FUN_004149a0(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (*(int *)(param_1 + 0x238) == 0) {
    puVar2 = (undefined1 *)(param_1 + 0x9140);
    iVar1 = 0x19;
    do {
      *puVar2 = 0;
      puVar2 = puVar2 + 0x18;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    *(undefined1 *)(param_1 + 0x91d0) = 0x70;
    *(undefined1 *)(param_1 + 0x9248) = 0x74;
    *(undefined1 *)(param_1 + 0x92c0) = 0x71;
    *(undefined1 *)(param_1 + 0x91e8) = 0x72;
    *(undefined1 *)(param_1 + 0x9260) = 0x14;
    *(undefined1 *)(param_1 + 0x92d8) = 0x73;
    *(undefined1 *)(param_1 + 0x9200) = 0x78;
    *(undefined1 *)(param_1 + 0x9278) = 0x1d;
    *(undefined1 *)(param_1 + 0x92f0) = 0x79;
    *(undefined1 *)(param_1 + 0x6880) = 0xff;
    *(undefined1 *)(param_1 + 0x6670) = 0;
    *(undefined1 *)(param_1 + 0x666c) = 6;
    *(undefined4 *)(param_1 + 0x6668) = 100;
    *(undefined1 *)(param_1 + 0x666d) = 0x20;
    *(undefined1 *)(param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)(param_1 + 0x9388) * 0x38);
    *(undefined1 *)(param_1 + 0x9250) = 0;
    *(undefined4 *)(param_1 + 0x6678) = 0x1e;
    *(undefined1 *)(param_1 + 0x6660) = 2;
    *(undefined1 *)(param_1 + 0x6661) = 2;
  }
  return;
}


