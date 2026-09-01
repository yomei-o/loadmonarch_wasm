/* 004240c0 */

void __fastcall FUN_004240c0(int param_1)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0;
  do {
    local_4 = 0;
    iVar8 = local_8;
    do {
      uVar5 = *(uint *)(param_1 + 0x398);
      iVar1 = iVar8 * 0x18;
      bVar2 = *(byte *)(DAT_0043453c + 0x10 + iVar1);
      iVar7 = (local_8 * uVar5 * 0x30 + local_4) * uVar5;
      if (*(byte *)(param_1 + 0x3c6 + iVar8 * 2) != bVar2) {
        FUN_004243c0((uint)bVar2,uVar5,*(int *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24),
                     (undefined4 *)(*(int *)(param_1 + 0x25c) + iVar7),*(int *)(param_1 + 0x15c8));
        *(undefined1 *)(param_1 + 0x3c6 + iVar8 * 2) = *(undefined1 *)(DAT_0043453c + 0x10 + iVar1);
        *(undefined1 *)(param_1 + 0x3c7 + iVar8 * 2) = 1;
      }
      if (*(byte *)(DAT_0043453c + iVar1) < 0x40) {
        iVar9 = *(int *)(param_1 + 0x15cc);
        uVar12 = *(undefined4 *)(param_1 + 0x24);
        iVar6 = *(int *)(param_1 + 0x25c) + iVar7;
        iVar11 = *(int *)(param_1 + 0x20);
        iVar10 = *(int *)(param_1 + 0x398);
        uVar5 = FUN_0041b520((uint)*(byte *)(DAT_0043453c + iVar1));
        FUN_00424460(uVar5,iVar10,iVar11,uVar12,iVar6,iVar9);
        *(undefined1 *)(param_1 + 0x3c6 + iVar8 * 2) = 0xff;
        *(undefined1 *)(param_1 + 0x3c7 + iVar8 * 2) = 1;
        if ((DAT_004376a1 != '\0') &&
           (bVar2 = *(byte *)(DAT_00434538 + 0x220 + (uint)*(byte *)(DAT_0043453c + iVar1) * 0x224),
           bVar2 != 0xff)) {
          iVar9 = *(int *)(param_1 + 0x398);
          FUN_004244b0((uint)bVar2,iVar9,*(int *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24),
                       iVar9 * iVar9 * -0x30 + *(int *)(param_1 + 0x25c) + iVar7);
          *(undefined1 *)(param_1 + 0x3c4 + iVar8 * 2) = 0xff;
          *(undefined1 *)(param_1 + 0x3c5 + iVar8 * 2) = 1;
        }
      }
      iVar1 = *(int *)(DAT_0043453c + 0x14 + iVar1);
      if (iVar1 != 0) {
        FUN_00424460((DAT_00435b1c & 1) + iVar1,*(int *)(param_1 + 0x398),*(int *)(param_1 + 0x20),
                     *(undefined4 *)(param_1 + 0x24),*(int *)(param_1 + 0x25c) + iVar7,
                     *(int *)(param_1 + 0x15cc));
        *(undefined1 *)(param_1 + 0x3c6 + iVar8 * 2) = 0xff;
        *(undefined1 *)(param_1 + 0x3c7 + iVar8 * 2) = 1;
      }
      iVar8 = iVar8 + 0x30;
      local_4 = local_4 + 1;
    } while (local_4 < 0x30);
    local_8 = local_8 + 1;
  } while (local_8 < 0x30);
  if (DAT_004365dc != 2) {
    iVar1 = *(int *)(param_1 + 0x398);
    bVar2 = *(byte *)(param_1 + 0x3c1);
    iVar8 = iVar1 + 0x1078;
    bVar3 = *(byte *)(param_1 + 0x3c0);
    iVar7 = 0;
    if (0 < iVar1) {
      do {
        iVar9 = 0;
        if (0 < *(int *)(param_1 + 0x398)) {
          do {
            cVar4 = *(char *)(iVar8 + iVar9 + DAT_00435fd4);
            if (cVar4 != 'p') {
              *(char *)(*(int *)(param_1 + 0x398) * iVar7 * 0x30 + *(int *)(param_1 + 0x25c) +
                        ((uint)bVar2 * iVar1 * 0x30 + (uint)bVar3) * iVar1 + iVar9) = cVar4;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < *(int *)(param_1 + 0x398));
        }
        iVar8 = iVar8 + 0x100;
        iVar7 = iVar7 + 1;
      } while (iVar7 < *(int *)(param_1 + 0x398));
    }
    iVar8 = param_1 + ((uint)*(byte *)(param_1 + 0x3c0) * 0x30 + (uint)*(byte *)(param_1 + 0x3c1)) *
                      2;
    *(undefined1 *)(iVar8 + 0x3c6) = 0xff;
    *(undefined1 *)(iVar8 + 0x3c7) = 1;
  }
  return;
}


