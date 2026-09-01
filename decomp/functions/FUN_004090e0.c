/* 004090e0 */

void FUN_004090e0(void)

{
  WPARAM WVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = (uint)(DAT_0043450c != -1);
  if (DAT_004365d4 == -1) {
    uVar3 = 0;
  }
  FUN_00409db0(0x9c90,uVar3);
  FUN_00409db0(0x9c91,uVar3);
  FUN_00409db0(0x9c92,uVar3);
  FUN_00409db0(0x9c93,uVar3);
  FUN_00409db0(0x9c4c,uVar3);
  FUN_00409db0(0x9c7d,uVar3);
  FUN_00409db0(0x9c7e,uVar3);
  FUN_00409db0(0x9c6d,uVar3);
  FUN_00409db0(0x9c5e,uVar3);
  FUN_00409d50(0x9c6d,(uint)(DAT_00434524 == 0));
  FUN_00409d50(0x9c5e,DAT_00434524);
  if (DAT_004365dc == 0) {
    FUN_00409d50(0x9c7d,0);
    FUN_00409d50(0x9c7e,0);
  }
  FUN_00409db0(0x9cae,uVar3);
  if (DAT_004365d0 == -1) {
    FUN_00409db0(0x9c4c,0);
    FUN_00409db0(0x9cb1,1);
    if (DAT_004365d0 == -1) goto LAB_00409268;
  }
  FUN_00409db0(0x9c7d,0);
  FUN_00409db0(0x9c7e,0);
  FUN_00409db0(0x9cae,0);
  FUN_00409d50(0x9c7d,0);
  FUN_00409d50(0x9c7e,0);
  FUN_00409db0(0x9cb1,0);
LAB_00409268:
  if (DAT_004365d4 == -1) {
    FUN_00409db0(0x9cae,1);
    FUN_00409db0(0x9cb1,0);
  }
  FUN_00409db0(0x9cb1,(uint)(DAT_00434524 == 0));
  FUN_00409db0(0x9c7d,(uint)(DAT_00434524 == 0));
  iVar4 = 0;
  iVar5 = 0;
  FUN_00409db0(0x9c7e,(uint)(DAT_00434524 == 0));
  do {
    puVar2 = (uint *)(DAT_00434534 + 4 + iVar5);
    WVar1 = iVar4 + 0x9c90;
    iVar5 = iVar5 + 0x38;
    iVar4 = iVar4 + 1;
    FUN_00409db0(WVar1,(uint)((*puVar2 & 0x40) == 0));
  } while (iVar5 < 0xe0);
  if (DAT_004321c8 == 0) {
    FUN_00409d50(0x9c7d,0);
    FUN_00409d50(0x9c7e,0);
  }
  else {
    if ((DAT_004321c8 & 1) != 0) {
      FUN_00409d50(0x9c7d,1);
    }
    if ((DAT_004321c8 & 2) != 0) {
      FUN_00409d50(0x9c7e,1);
      return;
    }
  }
  return;
}


