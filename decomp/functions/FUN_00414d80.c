/* 00414d80 */

void __fastcall FUN_00414d80(void *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char local_10 [8];
  char local_8 [8];
  
  if (*(int *)((int)param_1 + 0x238) == 0) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x9140) = 8;
    *(undefined4 *)((int)param_1 + 0x250) = 0;
    iVar1 = 0;
    *(undefined1 *)((int)param_1 + 0x9170) = 9;
    *(undefined1 *)((int)param_1 + 0x9188) = 10;
    *(undefined1 *)((int)param_1 + 0x91a0) = 0xb;
    puVar2 = (undefined1 *)((int)param_1 + 0x6880);
    do {
      *puVar2 = 0xff;
      iVar1 = iVar1 + 0x38;
      puVar2[-0x214] = 6;
      puVar2[-0x213] = 0x20;
      puVar2[-0x210] = 0;
      puVar2[-0x21c] = *(undefined1 *)(DAT_00434534 + -0x38 + iVar1);
      *(undefined4 *)(puVar2 + -0x208) = 0x1e;
      puVar2[0x224] = 0xff;
      puVar2[0x10] = 6;
      puVar2[0x11] = 1;
      *(undefined4 *)(puVar2 + 0xc) = 100;
      puVar2[0x14] = 0;
      puVar2[8] = *(undefined1 *)(DAT_00434534 + -0x38 + iVar1);
      *(undefined4 *)(puVar2 + 0x1c) = 0x1e;
      puVar2[0x448] = 0xff;
      puVar2[0x234] = 6;
      puVar2[0x235] = 1;
      *(undefined4 *)(puVar2 + 0x230) = 1000;
      puVar2[0x238] = 0;
      puVar2[0x22c] = *(undefined1 *)(DAT_00434534 + -0x38 + iVar1);
      *(undefined4 *)(puVar2 + 0x240) = 0x1e;
      puVar2[0x66c] = 0xff;
      puVar2[0x458] = 6;
      puVar2[0x459] = 1;
      *(undefined4 *)(puVar2 + 0x454) = 10000;
      puVar2[0x45c] = 0;
      puVar2[0x450] = *(undefined1 *)(DAT_00434534 + -0x38 + iVar1);
      *(undefined4 *)(puVar2 + 0x464) = 0x1e;
      puVar2 = puVar2 + 0x890;
    } while (iVar1 < 0xe0);
    *(undefined1 *)((int)param_1 + 0x91a8) = 0;
    *(undefined1 *)((int)param_1 + 0x9220) = 1;
    *(undefined1 *)((int)param_1 + 0x91d8) = 4;
    *(undefined1 *)((int)param_1 + 0x9298) = 2;
    *(undefined1 *)((int)param_1 + 0x9310) = 3;
    *(undefined1 *)((int)param_1 + 0x9250) = 5;
    *(undefined1 *)((int)param_1 + 0x92c8) = 6;
    *(undefined1 *)((int)param_1 + 0x9340) = 7;
    *(undefined1 *)((int)param_1 + 0x91f0) = 8;
    *(undefined1 *)((int)param_1 + 0x9268) = 9;
    *(undefined1 *)((int)param_1 + 0x92e0) = 10;
    *(undefined1 *)((int)param_1 + 0x9358) = 0xb;
    *(undefined1 *)((int)param_1 + 0x9208) = 0xc;
    *(undefined1 *)((int)param_1 + 0x9280) = 0xd;
    *(undefined1 *)((int)param_1 + 0x88a0) = 4;
    *(undefined1 *)((int)param_1 + 0x88a1) = 1;
    *(undefined1 *)((int)param_1 + 0x92f8) = 0xe;
    *(undefined1 *)((int)param_1 + 0x9370) = 0xf;
    *(undefined1 *)((int)param_1 + 0x9238) = 0x10;
    *(undefined1 *)((int)param_1 + 0x88ad) = 1;
    *(undefined1 *)((int)param_1 + 0x88b0) = 0;
    *(undefined1 *)((int)param_1 + 0x8ac0) = 0xff;
    *(undefined1 *)((int)param_1 + 0x88ac) = 6;
    *(undefined4 *)((int)param_1 + 0x88a8) = 1000;
    *(undefined4 *)((int)param_1 + 35000) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x88a4) = 4;
  }
  if ((*(byte *)((int)param_1 + 0x238) & 4) != 0) {
    local_10[1] = 5;
    local_10[2] = 9;
    local_10[3] = 0xd;
    local_10[4] = 0x11;
    local_8[0] = '\0';
    local_8[1] = 4;
    local_8[3] = 2;
    local_8[4] = 3;
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    local_10[0] = '\x01';
    local_8[2] = 1;
    do {
      puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               ((*(int *)((int)param_1 + 0x244) + local_10[*(int *)((int)param_1 + 0x250)] * 8) *
                0xa0 + -0x500 + *(int *)((int)param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar1 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
    wsprintfA((LPSTR)((int)param_1 + 0x1c),&DAT_00432100,
              &DAT_00435b31 + local_8[*(int *)((int)param_1 + 0x250)] * 0x11);
    FUN_0040a870(0x20,(int)local_10[*(int *)((int)param_1 + 0x250)] << 3,8,9,
                 (LPSTR)((int)param_1 + 0x1c),*(HDC *)((int)param_1 + 0x224),1,
                 (int *)((int)param_1 + 0x938c));
    if ((((byte)*(undefined4 *)((int)param_1 + 0x238) & 7) == 7) &&
       (iVar1 = *(int *)((int)param_1 + 0x250) + 1, *(int *)((int)param_1 + 0x250) = iVar1,
       4 < iVar1)) {
      *(undefined4 *)((int)param_1 + 0x250) = 0;
    }
  }
  return;
}


