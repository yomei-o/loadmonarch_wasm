/* 00429450 */

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_0043477c == 1) {
    __FF_MSGBANNER();
  }
  FUN_0042c2e0(param_1);
  (*(code *)PTR___exit_00434778)(0xff);
  return;
}


