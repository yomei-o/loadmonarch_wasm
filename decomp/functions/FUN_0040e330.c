/* 0040e330 */

void __thiscall FUN_0040e330(void *this,UINT_PTR param_1,UINT param_2,UINT param_3)

{
  CHAR local_104 [260];
  
  if (*(int *)this != 0) {
    LoadStringA(DAT_004344d0,param_2,local_104,0x103);
    AppendMenuA(*(HMENU *)this,param_3,param_1,local_104);
  }
  return;
}


