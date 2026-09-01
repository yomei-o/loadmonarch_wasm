/* 0041f9f0 */

bool __thiscall FUN_0041f9f0(void *this,LPCSTR param_1)

{
  HANDLE pvVar1;
  
  lstrcpyA(this,param_1);
  pvVar1 = CreateFileA(param_1,0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  *(HANDLE *)((int)this + 0x108) = pvVar1;
  if (pvVar1 == (HANDLE)0xffffffff) {
    FUN_0041fc90(this);
    return false;
  }
  return (bool)('\x01' - (pvVar1 == (HANDLE)0xffffffff));
}


