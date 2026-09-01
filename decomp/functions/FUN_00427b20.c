/* 00427b20 */

void __thiscall FUN_00427b20(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_1c [4];
  DWORD local_c;
  tagPOINT local_8;
  
  puVar2 = local_1c;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_1c[0] = *(undefined4 *)((int)this + 4);
  local_1c[1] = param_1;
  local_1c[2] = param_2;
  local_1c[3] = param_3;
  local_c = timeGetTime();
  GetCursorPos(&local_8);
  SendMessageA(*(HWND *)this,0x407,0,(LPARAM)local_1c);
  return;
}


