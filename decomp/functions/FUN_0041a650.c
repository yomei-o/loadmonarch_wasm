/* 0041a650 */

char * __thiscall FUN_0041a650(void *this,int param_1)

{
  if ((*(int *)this != 0) && (param_1 < *(int *)((int)this + 4))) {
    return (char *)(*(int *)this + param_1 * 0x208);
  }
  return s_Error_00433f9c;
}


