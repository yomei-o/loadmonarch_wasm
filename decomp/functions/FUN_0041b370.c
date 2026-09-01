/* 0041b370 */

void FUN_0041b370(void)

{
  uint *puVar1;
  int *piVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  do {
    iVar5 = iVar5 + 0x38;
    *(undefined4 *)(DAT_00434534 + -8 + iVar5) = 0;
    *(undefined4 *)(DAT_00434534 + -0x14 + iVar5) = 0;
    *(undefined4 *)(DAT_00434534 + -0x10 + iVar5) = 0;
    *(undefined4 *)(DAT_00434534 + -0xc + iVar5) = 0;
  } while (iVar5 < 0x118);
  iVar5 = 0;
  do {
    bVar3 = *(byte *)(DAT_0043453c + 0x10 + iVar5);
    if (bVar3 == 5) {
      *(int *)(DAT_00434534 + 0xf0) =
           *(int *)(DAT_00434534 + 0xf0) + *(int *)(DAT_0043453c + iVar5 + 0xc);
    }
    else {
      iVar6 = bVar3 - 8;
      if ((iVar6 < 4) && (-1 < iVar6)) {
        puVar1 = (uint *)(DAT_00434534 + 0x30 + iVar6 * 0x38);
        uVar4 = *(int *)(DAT_0043453c + iVar5 + 0xc) + *puVar1;
        *puVar1 = uVar4;
        if (99999 < uVar4) {
          *puVar1 = 100000;
        }
        piVar2 = (int *)(DAT_00434534 + 0x2c + iVar6 * 0x38);
        *piVar2 = *piVar2 + 1;
      }
    }
    iVar5 = iVar5 + 0x18;
  } while (iVar5 < 0xd800);
  iVar5 = 0;
  do {
    iVar6 = DAT_00434538 + iVar5;
    if (((*(byte *)(iVar6 + 0x10) & 0x80) == 0) && ((*(byte *)(iVar6 + 0xd) & 0x20) == 0)) {
      puVar1 = (uint *)(DAT_00434534 + 0x28 + (uint)*(byte *)(iVar6 + 4) * 0x38);
      uVar4 = *(int *)(iVar6 + 8) + *puVar1;
      *puVar1 = uVar4;
      if (99999 < uVar4) {
        *puVar1 = 100000;
      }
      piVar2 = (int *)(DAT_00434534 + 0x24 + (uint)*(byte *)(DAT_00434538 + 4 + iVar5) * 0x38);
      *piVar2 = *piVar2 + 1;
    }
    iVar5 = iVar5 + 0x224;
  } while (iVar5 < 0x8900);
  iVar5 = 0;
  do {
    iVar6 = DAT_00434534 + iVar5;
    uVar4 = *(int *)(iVar6 + 0x28) + *(int *)(iVar6 + 0x30);
    *(undefined4 *)(iVar6 + 0x10) = 100000;
    if (uVar4 < 0x186a1) {
      *(uint *)(iVar6 + 0x10) = uVar4;
    }
    iVar5 = iVar5 + 0x38;
  } while (iVar5 < 0x118);
  iVar5 = 0;
  do {
    if (*(int *)(DAT_00434534 + iVar5 + 0x10) == 0) {
      *(undefined1 *)(DAT_00434534 + iVar5 + 0x1f) = 4;
      puVar1 = (uint *)(DAT_00434534 + 4 + iVar5);
      *puVar1 = *puVar1 | 0x10;
    }
    iVar5 = iVar5 + 0x38;
  } while (iVar5 < 0xe0);
  return;
}


