/* 0040e310 */

void __thiscall FUN_0040e310(void *this,UINT_PTR param_1,LPCSTR param_2,UINT param_3)

{
  if (*(HMENU *)this != (HMENU)0x0) {
    AppendMenuA(*(HMENU *)this,param_3,param_1,param_2);
  }
  return;
}


