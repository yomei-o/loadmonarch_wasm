/* 00427a90 */

void __thiscall
FUN_00427a90(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_28 [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar2 = local_28;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_28[2] = *(undefined4 *)((int)this + 4);
  local_28[3] = param_1;
  local_8 = DAT_004344d0;
  local_4 = param_2;
  local_28[0] = 0x28;
  local_18 = param_3;
  local_14 = param_4;
  local_10 = param_5;
  local_c = param_6;
  SendMessageA(*(HWND *)this,0x405,0,(LPARAM)local_28);
  SendMessageA(*(HWND *)this,0x404,0,(LPARAM)local_28);
  return;
}


