/* 0041a620 */

char * __thiscall FUN_0041a620(void *this,int param_1)

{
  if ((*(int *)this != 0) && (param_1 < *(int *)((int)this + 4))) {
    return (char *)(*(int *)this + 0x104 + param_1 * 0x208);
  }
  return s_Error_00433f9c;
}


