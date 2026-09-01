/* 0042ec00 */

LPVOID __cdecl FUN_0042ec00(int param_1,int param_2)

{
  LPVOID pvVar1;
  int iVar2;
  uint dwBytes;
  
  dwBytes = param_1 * param_2;
  if (dwBytes == 0) {
    dwBytes = 1;
  }
  do {
    if (dwBytes < 0xffffffe1) {
      pvVar1 = HeapAlloc(DAT_00438980,8,dwBytes);
    }
    else {
      pvVar1 = (LPVOID)0x0;
    }
    if (pvVar1 != (LPVOID)0x0) {
      return pvVar1;
    }
    if (DAT_00434eb0 == 0) {
      return (LPVOID)0x0;
    }
    iVar2 = FUN_0042c740(dwBytes);
  } while (iVar2 != 0);
  return (LPVOID)0x0;
}


