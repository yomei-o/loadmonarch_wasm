/* 00414a70 */

void __fastcall FUN_00414a70(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((*(int *)(param_1 + 0x238) == 0) || (*(int *)(param_1 + 0x238) == 0x32)) {
    iVar1 = 0;
    *(undefined4 *)(param_1 + 0x238) = 0;
    *(undefined1 *)(param_1 + 0x9140) = 0x60;
    *(undefined1 *)(param_1 + 0x91b8) = 0x68;
    *(undefined1 *)(param_1 + 0x9230) = 0x68;
    *(undefined1 *)(param_1 + 0x92a8) = 0x68;
    *(undefined1 *)(param_1 + 0x9320) = 0x60;
    *(undefined1 *)(param_1 + 0x9338) = 0x61;
    *(undefined1 *)(param_1 + 0x9350) = 0x61;
    *(undefined1 *)(param_1 + 0x9368) = 0x61;
    *(undefined1 *)(param_1 + 0x9380) = 0x60;
    *(undefined1 *)(param_1 + 0x91a0) = 0x60;
    *(undefined1 *)(param_1 + 0x9308) = 0x62;
    *(undefined1 *)(param_1 + 0x9290) = 0x62;
    *(undefined1 *)(param_1 + 0x9218) = 0x62;
    *(undefined1 *)(param_1 + 0x9188) = 100;
    *(undefined1 *)(param_1 + 0x9170) = 100;
    *(undefined1 *)(param_1 + 0x9158) = 100;
    puVar2 = (undefined1 *)(param_1 + 0x6880);
    do {
      *puVar2 = 0xff;
      puVar2[-0x214] = 6;
      puVar2[-0x213] = 0x20;
      *(undefined4 *)(puVar2 + -0x218) = 1000;
      puVar2[-0x212] = 0;
      puVar2[-0x210] = 0;
      puVar2[-0x21c] = (char)iVar1;
      iVar1 = iVar1 + 1;
      *(undefined4 *)(puVar2 + -0x208) = 0x1e;
      puVar2 = puVar2 + 0x224;
    } while (iVar1 < 4);
    *(undefined1 *)(param_1 + 0x91c0) = 0;
    *(undefined1 *)(param_1 + 0x92b0) = 1;
    *(undefined1 *)(param_1 + 0x91f0) = 2;
    *(undefined1 *)(param_1 + 0x92e0) = 3;
  }
  iVar1 = *(int *)(param_1 + 0x238);
  if (iVar1 == 10) {
    *(undefined1 *)(param_1 + 0x6880) = 0xff;
    *(undefined1 *)(param_1 + 0x6660) = 1;
    *(undefined1 *)(param_1 + 0x6661) = 1;
    *(undefined1 *)(param_1 + 0x667c) = 4;
    *(undefined1 *)(param_1 + 0x667d) = 5;
    *(undefined4 *)(param_1 + 0x6678) = 0;
    *(undefined1 *)(param_1 + 0x667e) = 5;
    *(undefined1 *)(param_1 + 0x667f) = 5;
    *(undefined1 *)(param_1 + 0x6680) = 5;
    *(undefined1 *)(param_1 + 0x6681) = 4;
    *(undefined1 *)(param_1 + 0x6683) = 5;
    *(undefined1 *)(param_1 + 0x6684) = 5;
    *(undefined1 *)(param_1 + 0x6682) = 6;
    *(undefined1 *)(param_1 + 0x6685) = 5;
    *(undefined1 *)(param_1 + 0x6686) = 5;
    *(undefined1 *)(param_1 + 0x6687) = 6;
    *(undefined1 *)(param_1 + 0x6688) = 0;
    *(undefined1 *)(param_1 + 0x6689) = 5;
    *(undefined1 *)(param_1 + 0x668a) = 5;
    *(undefined1 *)(param_1 + 0x668b) = 5;
    *(undefined1 *)(param_1 + 0x668c) = 5;
    *(undefined1 *)(param_1 + 0x668d) = 0;
    *(undefined4 *)(param_1 + 0x6674) = 0x14;
    *(undefined1 *)(param_1 + 0x668e) = 2;
    *(undefined1 *)(param_1 + 0x668f) = 2;
  }
  if (iVar1 == 0xb) {
    *(undefined1 *)(param_1 + 0x6894) = 2;
  }
  if (iVar1 == 0x12) {
    *(undefined1 *)(param_1 + 0x6cdc) = 2;
  }
  if (iVar1 == 0x1a) {
    *(undefined1 *)(param_1 + 0x6ab8) = 2;
  }
  if (iVar1 == 0x24) {
    *(undefined1 *)(param_1 + 0x666c) = 6;
  }
  if (iVar1 < 0x28) {
    *(undefined4 *)(param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)(param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)(*(int *)(param_1 + 0x244) * 0xa0 + *(int *)(param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar1 = *(int *)(param_1 + 0x244) + 1;
      *(int *)(param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
  }
  iVar1 = *(int *)(param_1 + 0x238);
  if (iVar1 < 10) {
    FUN_0040a870(0x10,8,8,9,s_The_rules_are____00433b08,*(HDC *)(param_1 + 0x224),1,
                 (int *)(param_1 + 0x938c));
    return;
  }
  if (iVar1 < 0x14) {
    FUN_0040a870(0x10,8,8,9,s_easy_and_simple___00433af4,*(HDC *)(param_1 + 0x224),1,
                 (int *)(param_1 + 0x938c));
    return;
  }
  if (iVar1 < 0x1e) {
    FUN_0040a870(0x10,8,8,9,s_defeat_everyone__00433ae0,*(HDC *)(param_1 + 0x224),1,
                 (int *)(param_1 + 0x938c));
    return;
  }
  if (iVar1 < 0x28) {
    FUN_0040a870(0x10,8,8,9,s_That_s_all_to_it__00433acc,*(HDC *)(param_1 + 0x224),1,
                 (int *)(param_1 + 0x938c));
  }
  return;
}


