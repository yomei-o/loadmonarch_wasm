/* 0042c2a0 */

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_0043477c == 1) || ((DAT_0043477c == 0 && (DAT_00434780 == 1)))) {
    FUN_0042c2e0(0xfc);
    if (DAT_00434e48 != (code *)0x0) {
      (*DAT_00434e48)();
    }
    FUN_0042c2e0(0xff);
  }
  return;
}


