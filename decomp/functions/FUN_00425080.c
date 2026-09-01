/* 00425080 */

bool __thiscall FUN_00425080(void *this,LPCSTR param_1,LPBYTE param_2,DWORD param_3,DWORD param_4)

{
  LSTATUS LVar1;
  DWORD local_8;
  DWORD local_4;
  
  local_4 = param_4;
  local_8 = param_3;
  LVar1 = RegQueryValueExA(*(HKEY *)((int)this + 0x148),param_1,(LPDWORD)0x0,&local_4,param_2,
                           &local_8);
  return LVar1 == 0;
}


