/* 00425010 */

bool __thiscall FUN_00425010(void *this,LPCSTR param_1,HWND param_2)

{
  BOOL BVar1;
  LSTATUS LVar2;
  
  BVar1 = GetWindowPlacement(param_2,this);
  if (BVar1 == 0) {
    return false;
  }
  LVar2 = RegSetValueExA(*(HKEY *)((int)this + 0x148),param_1,0,3,this,0x34);
  return LVar2 == 0;
}


