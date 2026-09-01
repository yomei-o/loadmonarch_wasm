/* 0042b5c0 */

LPVOID __cdecl FUN_0042b5c0(LPVOID param_1,uint param_2)

{
  LPVOID pvVar1;
  int iVar2;
  
  if (param_1 == (LPVOID)0x0) {
    pvVar1 = (LPVOID)FUN_0042a050(param_2);
    return pvVar1;
  }
  if (param_2 != 0) {
    do {
      if (param_2 < 0xffffffe1) {
        pvVar1 = HeapReAlloc(DAT_00438980,0,param_1,param_2);
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
      iVar2 = FUN_0042c740(param_2);
    } while (iVar2 != 0);
    return (LPVOID)0x0;
  }
  FUN_0042a030(param_1);
  return (LPVOID)0x0;
}


