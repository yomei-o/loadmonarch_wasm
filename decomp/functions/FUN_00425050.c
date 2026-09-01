/* 00425050 */

bool __thiscall FUN_00425050(void *this,LPCSTR param_1,BYTE *param_2,DWORD param_3,DWORD param_4)

{
  LSTATUS LVar1;
  
  LVar1 = RegSetValueExA(*(HKEY *)((int)this + 0x148),param_1,0,param_4,param_2,param_3);
  return LVar1 == 0;
}


