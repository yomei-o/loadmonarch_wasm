/* 0041b640 */

void FUN_0041b640(void)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  
  uVar2 = FUN_0041cdf0();
  *(undefined4 *)(DAT_00434534 + 0x34) = 0;
  *(undefined4 *)(DAT_00434534 + 0x6c) = 0;
  *(undefined4 *)(DAT_00434534 + 0xa4) = 0;
  *(undefined4 *)(DAT_00434534 + 0xdc) = 0;
  if (ABS((float)uVar2) != 0.0) {
    iVar4 = 0;
    iVar3 = 0;
    while( true ) {
      iVar4 = iVar4 + 0x38;
      FUN_0041ceb0(iVar3);
      if (DAT_004345f4 != 0) {
        __adj_fdiv_m32((uint)(float)uVar2);
      }
      lVar5 = __ftol();
      fVar1 = (float)(int)lVar5 * 0.01;
      if (0xdf < iVar4) break;
      *(float *)(DAT_00434534 + -4 + iVar4) = fVar1;
      iVar3 = iVar3 + 1;
    }
    *(float *)(DAT_00434534 + -4 + iVar4) = fVar1;
  }
  return;
}


