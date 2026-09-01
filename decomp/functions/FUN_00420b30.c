/* 00420b30 */

void __cdecl FUN_00420b30(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = param_1 * 0x224;
  iVar5 = 0;
  *(undefined1 *)(DAT_00434538 + 0x220 + iVar4) = 0xff;
  *(undefined4 *)(DAT_00434538 + 8 + iVar4) = 0;
  *(undefined4 *)(DAT_00434538 + 0x18 + iVar4) = 0x1f0;
  *(undefined1 *)(DAT_00434538 + 0xe + iVar4) = 3;
  if ((*(byte *)(DAT_00434538 + iVar4 + 0xd) & 0x20) != 0) {
    uVar3 = (uint)*(byte *)(DAT_00434538 + iVar4 + 4);
    iVar6 = uVar3 * 0x38;
    puVar1 = (uint *)(DAT_00434534 + 4 + iVar6);
    *puVar1 = *puVar1 | 1;
    *(undefined1 *)(DAT_00434534 + 0x1f + iVar6) = *(undefined1 *)(DAT_00434538 + 0xf + iVar4);
    *(undefined4 *)(DAT_00434534 + 0xc + iVar6) = 0x40;
    do {
      iVar6 = DAT_00434538 + iVar5;
      if (((*(byte *)(iVar6 + 0x10) & 0x80) == 0) && (*(byte *)(iVar6 + 4) == uVar3)) {
        *(byte *)(iVar6 + 0xd) = *(byte *)(iVar6 + 0xd) & 0x20 | 0xc;
        *(undefined1 *)(DAT_00434538 + 0xc + iVar5) = 6;
        pbVar2 = (byte *)(DAT_00434538 + 0x10 + iVar5);
        *pbVar2 = *pbVar2 | 1;
        *(undefined1 *)(DAT_00434538 + 0x220 + iVar5) = 0xff;
        *(undefined4 *)(DAT_00434538 + 0x18 + iVar5) = 0x1f0;
      }
      iVar5 = iVar5 + 0x224;
    } while (iVar5 < 0x8900);
  }
  *(undefined1 *)(DAT_0043453c + (param_2 * 0x30 + param_3) * 0x18) = 0x40;
  *(undefined1 *)(DAT_00434538 + 0x10 + iVar4) = 0x80;
  return;
}


