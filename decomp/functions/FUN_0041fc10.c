/* 0041fc10 */

BOOL __thiscall FUN_0041fc10(void *this,LPCVOID param_1,DWORD param_2)

{
  BOOL BVar1;
  
  BVar1 = WriteFile(*(HANDLE *)((int)this + 0x108),param_1,param_2,(LPDWORD)((int)this + 0x10c),
                    (LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    FUN_0041fc90(this);
    return 0;
  }
  if (*(LPDWORD)((int)this + 0x10c) != param_2) {
    BVar1 = 0;
  }
  return BVar1;
}


