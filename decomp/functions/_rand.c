/* 004280c0 */

/* Library Function - Single Match
    _rand
   
   Library: Visual Studio 1998 Release */

int __cdecl _rand(void)

{
  DAT_00434604 = DAT_00434604 * 0x343fd + 0x269ec3;
  return (DAT_00434604 & 0x7fff0000) >> 0x10;
}


