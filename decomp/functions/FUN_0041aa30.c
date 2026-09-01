/* 0041aa30 */

void FUN_0041aa30(void)

{
  longlong lVar1;
  ulonglong uVar2;
  
  DAT_00436418 = FUN_0041cdf0();
  DAT_00436414 = FUN_0041ceb0((uint)DAT_00436400);
  if (DAT_004345f4 != 0) {
    FUN_004283c7();
  }
  lVar1 = __ftol();
  DAT_0043641c = (float)(int)lVar1 * 0.01;
  uVar2 = __ftol();
  DAT_00436420 = (int)((uVar2 & 0xffffffff) / 100);
  return;
}


