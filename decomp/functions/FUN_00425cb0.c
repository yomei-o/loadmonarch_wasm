/* 00425cb0 */

void __thiscall FUN_00425cb0(void *this,SIZE_T param_1)

{
  HGLOBAL pvVar1;
  
  pvVar1 = GlobalAlloc(2,param_1);
  *(HGLOBAL *)((int)this + 4) = pvVar1;
  return;
}


