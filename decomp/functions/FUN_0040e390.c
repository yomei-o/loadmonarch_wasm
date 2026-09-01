/* 0040e390 */

void __thiscall FUN_0040e390(void *this,UINT_PTR param_1,LPCSTR param_2)

{
  if (*(HMENU *)this != (HMENU)0x0) {
    AppendMenuA(*(HMENU *)this,0x10,param_1,param_2);
  }
  return;
}


