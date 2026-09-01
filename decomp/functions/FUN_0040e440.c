/* 0040e440 */

void __thiscall FUN_0040e440(void *this,UINT param_1,UINT param_2)

{
  if (*(HMENU *)this != (HMENU)0x0) {
    EnableMenuItem(*(HMENU *)this,param_1,param_2);
  }
  return;
}


