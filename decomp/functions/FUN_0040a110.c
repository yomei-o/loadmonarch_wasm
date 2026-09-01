/* 0040a110 */

void FUN_0040a110(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  uVar1 = 0;
  uVar4 = 0;
  piVar3 = (int *)(DAT_00434534 + 0x10);
  do {
    if (uVar1 != DAT_004365cd) {
      uVar4 = uVar4 + *piVar3;
    }
    piVar3 = piVar3 + 0xe;
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 4);
  if (*(uint *)(DAT_00434534 + 0x10 + (uint)DAT_004365cd * 0x38) < uVar4) {
    iVar2 = FUN_0040cdc0(0);
    if (iVar2 != DAT_00434514) {
      FUN_0040cd20(&DAT_00435db0,DAT_00434514,0);
    }
  }
  if (uVar4 < *(uint *)(DAT_00434534 + 0x10 + (uint)DAT_004365cd * 0x38) >> 3) {
    iVar2 = FUN_0040cdc0(0);
    if (iVar2 - DAT_00434514 != 1) {
      FUN_0040cd20(&DAT_00435db0,DAT_00434514 + 1,0);
    }
  }
  return;
}


