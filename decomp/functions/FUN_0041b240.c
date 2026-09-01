/* 0041b240 */

void FUN_0041b240(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  ulonglong uVar5;
  
  if (DAT_00436a00 != 0) {
    iVar3 = 0;
    iVar4 = 0;
    if (0 < DAT_00436a00) {
      piVar2 = &DAT_00436a0c;
      do {
        iVar4 = iVar4 + 1;
        piVar2[5] = (iVar3 + 3000) - piVar2[-1];
        uVar5 = __ftol();
        piVar2[7] = (int)((uVar5 & 0xffffffff) / 100);
        *piVar2 = 0;
        *piVar2 = piVar2[5];
        iVar1 = piVar2[5] + piVar2[3];
        *piVar2 = iVar1;
        iVar1 = iVar1 - piVar2[7];
        *piVar2 = iVar1;
        piVar2[6] = iVar1 - iVar3;
        iVar3 = *piVar2;
        piVar2 = piVar2 + 0xe;
      } while (iVar4 < DAT_00436a00);
    }
    if (DAT_004376cc - iVar4 == 1) {
      if ((&DAT_00436a08)[iVar4 * 0xe] != 0) {
        (&DAT_00436a20)[iVar4 * 0xe] = (iVar3 + 3000) - (&DAT_00436a08)[iVar4 * 0xe];
        uVar5 = __ftol();
        (&DAT_00436a28)[iVar4 * 0xe] = (int)((uVar5 & 0xffffffff) / 100);
        (&DAT_00436a0c)[iVar4 * 0xe] = 0;
        (&DAT_00436a0c)[iVar4 * 0xe] = (&DAT_00436a20)[iVar4 * 0xe];
        iVar1 = (&DAT_00436a20)[iVar4 * 0xe] + (&DAT_00436a18)[iVar4 * 0xe];
        (&DAT_00436a0c)[iVar4 * 0xe] = iVar1;
        iVar1 = iVar1 - (&DAT_00436a28)[iVar4 * 0xe];
        (&DAT_00436a0c)[iVar4 * 0xe] = iVar1;
        (&DAT_00436a24)[iVar4 * 0xe] = iVar1 - iVar3;
      }
    }
  }
  return;
}


