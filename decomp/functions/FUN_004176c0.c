/* 004176c0 */

void __fastcall FUN_004176c0(void *param_1)

{
  if ((*(int *)((int)param_1 + 0x238) == 0) || (*(int *)((int)param_1 + 0x238) == 0x14)) {
    FUN_004146f0(param_1);
    *(undefined1 *)((int)param_1 + 0x6880) = 0xff;
    *(undefined1 *)((int)param_1 + 0x6670) = 0;
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
    *(undefined4 *)((int)param_1 + 0x6668) = 1000;
    *(undefined1 *)((int)param_1 + 0x666d) = 1;
    *(undefined1 *)((int)param_1 + 0x6664) =
         *(undefined1 *)(DAT_00434534 + (uint)*(byte *)((int)param_1 + 0x9388) * 0x38);
    *(undefined1 *)((int)param_1 + 0x9250) = 0;
    *(undefined4 *)((int)param_1 + 0x6678) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x9140) = 0x44;
    *(undefined1 *)((int)param_1 + 0x6660) = 2;
    *(undefined1 *)((int)param_1 + 0x6661) = 2;
    *(undefined1 *)((int)param_1 + 0x9320) = 0x48;
    *(undefined1 *)((int)param_1 + 0x91b8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9230) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9380) = 0x41;
    *(undefined1 *)((int)param_1 + 0x92a8) = 0x38;
    *(undefined1 *)((int)param_1 + 0x9338) = 0x31;
    *(undefined1 *)((int)param_1 + 0x9350) = 0x31;
    *(undefined1 *)((int)param_1 + 0x91a0) = 0x42;
    *(undefined1 *)((int)param_1 + 0x9368) = 0x31;
    *(undefined1 *)((int)param_1 + 0x9308) = 0x32;
    *(undefined1 *)((int)param_1 + 0x9290) = 0x32;
    *(undefined1 *)((int)param_1 + 0x9218) = 0x32;
    *(undefined1 *)((int)param_1 + 0x9188) = 0x34;
    *(undefined1 *)((int)param_1 + 0x9170) = 0x34;
    *(undefined1 *)((int)param_1 + 0x9158) = 0x34;
    *(undefined1 *)((int)param_1 + 0x91d0) = 4;
    *(undefined1 *)((int)param_1 + 0x92c0) = 4;
    *(undefined1 *)((int)param_1 + 0x92f0) = 4;
    *(undefined1 *)((int)param_1 + 0x9200) = 4;
  }
  switch(*(undefined4 *)((int)param_1 + 0x238)) {
  case 2:
    *(undefined4 *)((int)param_1 + 0x6678) = 0;
    *(undefined1 *)((int)param_1 + 0x667c) = 0;
    *(undefined1 *)((int)param_1 + 0x667e) = 4;
    *(undefined1 *)((int)param_1 + 0x667f) = 4;
    *(undefined1 *)((int)param_1 + 0x6682) = 0;
    *(undefined1 *)((int)param_1 + 0x6680) = 6;
    *(undefined1 *)((int)param_1 + 0x6681) = 6;
    *(undefined4 *)((int)param_1 + 0x6674) = 8;
    *(undefined1 *)((int)param_1 + 0x667d) = 2;
    *(undefined1 *)((int)param_1 + 0x6683) = 0;
    return;
  case 6:
    *(undefined1 *)((int)param_1 + 0x91d0) = 0;
    return;
  case 9:
    *(undefined1 *)((int)param_1 + 0x92c0) = 0;
    return;
  case 0xc:
    *(undefined1 *)((int)param_1 + 0x92f0) = 0;
    return;
  case 0xf:
    *(undefined1 *)((int)param_1 + 0x9200) = 0;
    return;
  case 0x10:
    *(undefined1 *)((int)param_1 + 0x666c) = 6;
  }
  return;
}


