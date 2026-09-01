/* 0041aaf0 */

undefined4 FUN_0041aaf0(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  bool bVar5;
  float10 fVar6;
  longlong lVar7;
  
  iVar4 = 0;
  DAT_00436428 = 0;
  puVar3 = (uint *)(DAT_00434534 + 0x14);
  DAT_00436424 = 0;
  do {
    uVar1 = *puVar3;
    if (((char)iVar4 != DAT_00436400) &&
       (DAT_00436428 = *puVar3 + DAT_00436428, uVar1 = DAT_00436424, DAT_00436428 == 0xffffffff)) {
      DAT_00436428 = 0xffffffff;
    }
    DAT_00436424 = uVar1;
    puVar3 = puVar3 + 0xe;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  DAT_00436430 = 0;
  bVar5 = DAT_00436410 != 0;
  if (DAT_004345f4 == 0) {
    fVar6 = (float10)DAT_00436428 / (float10)DAT_00436424;
  }
  else {
    fVar6 = FUN_004283c7();
  }
  uVar2 = 0;
  DAT_0043642c = (float)(fVar6 * (float10)100.0);
  if ((bVar5) && (0x42c80000 < (int)DAT_0043642c)) {
    lVar7 = __ftol();
    DAT_00436430 = (uint)lVar7;
    uVar2 = 500;
    if (500 < DAT_00436430) {
      DAT_00436430 = 500;
    }
  }
  return uVar2;
}


