/* 0041d6d0 */

/* WARNING: Type propagation algorithm not settling */

void __cdecl FUN_0041d6d0(int param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_40 = 0xffffffff;
  local_3c = 0;
  local_38 = 0xffffffff;
  local_34 = 0xffffffff;
  local_30 = 0;
  local_2c = 0xffffffff;
  local_28 = 1;
  local_24 = 0xffffffff;
  local_20 = 1;
  local_1c = 0;
  local_18 = 1;
  local_14 = 1;
  local_10 = 0;
  local_c = 1;
  local_8 = 0xffffffff;
  local_4 = 1;
  if (param_1 < 8) {
    uVar1 = *(undefined1 *)((int)&local_3c + param_1 * 8);
    *param_2 = *(undefined1 *)(&local_40 + param_1 * 2);
    param_2[1] = uVar1;
  }
  return;
}


