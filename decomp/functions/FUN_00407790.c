/* 00407790 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00407790(void)

{
  int iVar1;
  _SYSTEMTIME local_10;
  
  GetLocalTime(&local_10);
  iVar1 = 5;
  DAT_004365e8 = local_10.wMilliseconds;
  DAT_004365cc = 1;
  FUN_004280b0((uint)local_10.wMilliseconds);
  do {
    FUN_0041abf0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_004273b0();
  FUN_00405330();
  FUN_004272b0();
  FUN_00427210();
  FUN_0041b370();
  _DAT_00434540 = 3;
  return 1;
}


