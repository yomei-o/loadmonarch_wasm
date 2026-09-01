/* 0042ece0 */

/* Library Function - Single Match
    _fflush
   
   Library: Visual Studio 1998 Release */

int __cdecl _fflush(FILE *_File)

{
  int iVar1;
  
  if (_File == (FILE *)0x0) {
    iVar1 = FUN_0042edb0(0);
    return iVar1;
  }
  iVar1 = __flush(_File);
  if (iVar1 != 0) {
    return -1;
  }
  if ((_File->_flag & 0x4000) != 0) {
    iVar1 = FUN_0042f200(_File->_file);
    return (iVar1 == 0) - 1;
  }
  return 0;
}


