/* 00424fa0 */

bool __thiscall FUN_00424fa0(void *this,LPCSTR param_1)

{
  LSTATUS LVar1;
  DWORD local_8 [2];
  
  local_8[1] = 3;
  local_8[0] = 0x34;
  LVar1 = RegQueryValueExA(*(HKEY *)((int)this + 0x148),param_1,(LPDWORD)0x0,local_8 + 1,this,
                           local_8);
  *(int *)((int)this + 0x34) = *(int *)((int)this + 0x1c);
  *(int *)((int)this + 0x38) = *(int *)((int)this + 0x20);
  *(int *)((int)this + 0x3c) = *(int *)((int)this + 0x24) - *(int *)((int)this + 0x1c);
  *(int *)((int)this + 0x40) = *(int *)((int)this + 0x28) - *(int *)((int)this + 0x20);
  return LVar1 == 0;
}


