/* 004015a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004015a0(void)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  if (*(byte *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) - DAT_00437580 == 0x14) {
    puVar2 = (uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
    uVar6 = *puVar2;
    uVar5 = *(uint *)(DAT_00434534 + 0x10 + DAT_00437580 * 0x38);
    if (uVar5 < uVar6 >> 1) {
      if (0x3f < *(byte *)(DAT_0043453c + 0x18 + (DAT_0043644c * 0x30 + DAT_00436450) * 0x18)) {
        iVar7 = FUN_0041cdc0();
        if ((iVar7 != 0x40) &&
           (uVar6 = *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 2, uVar6 != 0)) {
          *(uint *)(DAT_00434538 + 8 + iVar7 * 0x224) = uVar6;
          iVar1 = iVar7 * 0x224;
          piVar3 = (int *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
          *piVar3 = *piVar3 - uVar6;
          *(undefined1 *)(DAT_00434538 + 4 + iVar1) = (undefined1)DAT_00437580;
          *(undefined1 *)(DAT_00434538 + iVar1) = (undefined1)DAT_0043644c;
          *(char *)(DAT_00434538 + 1 + iVar1) = (char)DAT_00436450 + '\x01';
          ((undefined2 *)(DAT_00434538 + iVar1))[1] = *(undefined2 *)(DAT_00434538 + iVar1);
          *(undefined1 *)(DAT_00434538 + 0x220 + iVar1) = 0xff;
          *(char *)(DAT_0043453c + 0x18 + (DAT_0043644c * 0x30 + DAT_00436450) * 0x18) = (char)iVar7
          ;
          *(undefined1 *)(DAT_00434538 + 0x10 + iVar1) = 0;
          if ((DAT_004365cd == DAT_00437580) && (_DAT_004365e0 != 1)) {
            pbVar4 = (byte *)(DAT_00434538 + 0x10 + iVar1);
            *pbVar4 = *pbVar4 | 4;
            *(undefined1 *)(DAT_00434538 + 0xd + iVar1) = DAT_004365e0;
            return;
          }
          *(undefined1 *)(DAT_00434538 + 0xd + iVar1) = 1;
        }
      }
    }
    else if (uVar6 < uVar5) {
      uVar6 = (uVar5 - uVar6 >> 3) + uVar6;
      if (99999 < uVar6) {
        *puVar2 = 100000;
        return;
      }
      *puVar2 = uVar6;
      return;
    }
  }
  return;
}


