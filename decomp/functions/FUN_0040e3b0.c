/* 0040e3b0 */

void __thiscall FUN_0040e3b0(void *this,UINT_PTR param_1,UINT param_2)

{
  CHAR local_104 [260];
  
  if (*(int *)this != 0) {
    LoadStringA(DAT_004344d0,param_2,local_104,0x103);
    AppendMenuA(*(HMENU *)this,0x10,param_1,local_104);
  }
  return;
}


