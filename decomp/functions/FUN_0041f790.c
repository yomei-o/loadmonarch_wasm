/* 0041f790 */

void FUN_0041f790(void)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    *(undefined1 *)(DAT_00434538 + 0x220 + iVar3) = 0xff;
    iVar1 = DAT_00434538 + iVar3;
    if (((*(byte *)(iVar1 + 0x10) & 0x80) == 0) && (*(byte *)(iVar1 + 4) == DAT_004365cd)) {
      if ((*(byte *)(iVar1 + 0xd) & 0x20) == 0) {
        if (((*(byte *)(iVar1 + 0x10) & 4) != 0) || ((*(byte *)(iVar1 + 0xd) & 0x10) != 0)) {
          *(byte *)(iVar1 + 0x220) = ((byte)(DAT_00435b1c >> 1) & 1) + 10;
        }
        if (DAT_0043451c == -1) {
          bVar2 = *(byte *)(DAT_00434538 + iVar3 + 0xd) & 0xf;
          if ((4 < bVar2) && (bVar2 < 8)) {
            *(byte *)(DAT_00434538 + iVar3 + 0x220) = ((byte)(DAT_00435b1c >> 1) & 1) + 8;
          }
        }
        iVar1 = DAT_00434538 + iVar3;
        if ((*(uint *)(iVar1 + 8) < 100) && ((*(byte *)(iVar1 + 0xd) & 0xf) == 2)) {
          *(byte *)(iVar1 + 0x220) = ((byte)(DAT_00435b1c >> 1) & 1) + 6;
        }
      }
      else if ((*(int *)(iVar1 + 0x18) != 0x1f0) ||
              ((*(byte *)(DAT_00434534 + 4 + (uint)DAT_004365cd * 0x38) & 2) != 0)) {
        *(byte *)(iVar1 + 0x220) = ((byte)(DAT_00435b1c >> 1) & 3) + 0xc;
      }
    }
    iVar3 = iVar3 + 0x224;
  } while (iVar3 < 0x8900);
  return;
}


