/* 0041d870 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041d870(void)

{
  byte *pbVar1;
  int *piVar2;
  uint *puVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte local_a;
  byte local_9;
  byte local_8;
  char local_7;
  byte local_5;
  byte local_4;
  
  iVar5 = DAT_00437580 * 0x38 + DAT_00434534;
  uVar6 = *(uint *)(iVar5 + 4);
  if ((uVar6 & 0x40) != 0) {
    cVar4 = *(char *)(iVar5 + 0x1f);
    if (cVar4 != '\x04') {
      *(char *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) = cVar4 + '\b';
      iVar5 = -1;
      do {
        iVar7 = -1;
        do {
          pbVar1 = (byte *)(DAT_0043453c + 0x10 +
                           ((DAT_0043644c + iVar5) * 0x30 + DAT_00436450 + iVar7) * 0x18);
          if (*pbVar1 - DAT_00437580 == 0xc) {
            *pbVar1 = *(char *)(DAT_00434534 + 0x1f + DAT_00437580 * 0x38) + 0xc;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < 2);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 2);
      return;
    }
    *(undefined1 *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) = 0;
    iVar5 = -1;
    do {
      iVar7 = -1;
      do {
        pbVar1 = (byte *)(DAT_0043453c + 0x10 +
                         ((DAT_0043644c + iVar5) * 0x30 + DAT_00436450 + iVar7) * 0x18);
        if (*pbVar1 - DAT_00437580 == 0xc) {
          *pbVar1 = 0;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < 2);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
    return;
  }
  if ((uVar6 & 1) == 0) {
    FUN_0041ee10(DAT_0043644c,DAT_00436450,(char *)&local_8);
    piVar2 = (int *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18);
    *piVar2 = *piVar2 + local_8 + 1;
    puVar3 = (uint *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18);
    uVar6 = *puVar3;
    if ((local_8 + 1) * 0x10 <= uVar6) {
      if (0xfe < uVar6) {
        uVar6 = 0xff;
      }
      *puVar3 = uVar6;
      if (local_7 == '\0') {
        iVar5 = FUN_0041c780((char *)&local_a);
        if (iVar5 == 1) {
          iVar5 = ((uint)local_a * 0x30 + (uint)local_9) * 0x18;
          *(undefined4 *)(DAT_0043453c + 0xc + iVar5) = 100;
          *(char *)(DAT_0043453c + 0x10 + iVar5) = (char)DAT_00437580 + '\f';
          if (*(uint *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18) < 200) {
            return;
          }
        }
      }
      else {
        iVar5 = ((uint)local_4 + (uint)local_5 * 0x30) * 0x18;
        *(undefined4 *)(DAT_0043453c + 0xc + iVar5) = 100;
        *(char *)(DAT_0043453c + 0x10 + iVar5) = (char)DAT_00437580 + '\f';
        if (*(uint *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18) < 200) {
          return;
        }
      }
      if (DAT_0043756c < 0x40) {
        iVar5 = DAT_0043756c * 0x224 + DAT_00434538;
        if (*(byte *)(iVar5 + 4) == DAT_00437580) {
          piVar2 = (int *)(iVar5 + 8);
          *piVar2 = *piVar2 + *(int *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18);
          *(undefined4 *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18) = 1;
          puVar3 = (uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224);
          if (100000 < *puVar3) {
            *puVar3 = 100000;
            return;
          }
        }
      }
      else {
        iVar5 = FUN_0041cdc0();
        if (iVar5 != 0x40) {
          iVar7 = iVar5 * 0x224;
          *(undefined1 *)(DAT_00434538 + 4 + iVar7) = (undefined1)DAT_00437580;
          *(int *)(DAT_00434538 + 8 + iVar7) =
               *(int *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18) + -1;
          *(undefined1 *)(DAT_00434538 + iVar7) = (undefined1)DAT_0043644c;
          *(undefined1 *)(DAT_00434538 + 1 + iVar7) = (undefined1)DAT_00436450;
          ((undefined2 *)(DAT_00434538 + iVar7))[1] = *(undefined2 *)(DAT_00434538 + iVar7);
          *(undefined1 *)(DAT_00434538 + 0x10 + iVar7) = 0;
          *(undefined1 *)(DAT_00434538 + 0x220 + iVar7) = 0xff;
          *(char *)(DAT_0043453c + DAT_00437690 * 0x18) = (char)iVar5;
          *(undefined4 *)(DAT_0043453c + 0xc + DAT_00437690 * 0x18) = 1;
          if ((DAT_004365cd == DAT_00437580) && (_DAT_004365e0 != 1)) {
            pbVar1 = (byte *)(DAT_00434538 + 0x10 + iVar7);
            *pbVar1 = *pbVar1 | 4;
            *(byte *)(DAT_00434538 + 0xd + iVar7) = (byte)_DAT_004365e0 | 0x10;
            return;
          }
          *(undefined1 *)(DAT_00434538 + 0xd + iVar7) = 1;
        }
      }
    }
  }
  return;
}


