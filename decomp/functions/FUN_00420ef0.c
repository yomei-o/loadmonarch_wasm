/* 00420ef0 */

undefined4 FUN_00420ef0(void)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  
  bVar3 = 0;
  while ((((DAT_00437580 == bVar3 || (*(byte *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) == bVar3)
           ) || (uVar1 = *(uint *)(DAT_00434534 + 4 + (uint)bVar3 * 0x38), (uVar1 & 2) == 0)) ||
         ((uVar1 & 4) == 0))) {
    bVar3 = bVar3 + 1;
    if (3 < bVar3) {
      return 0;
    }
  }
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  iVar2 = (uint)bVar3 * 0x38 + DAT_00434534;
  uVar1 = *(uint *)(DAT_0043453c + 8 +
                   ((uint)*(byte *)(iVar2 + 0x21) + (uint)*(byte *)(iVar2 + 0x20) * 0x30) * 0x18);
  if (0x1ef < uVar1) {
    return 0;
  }
  iVar4 = DAT_0043756c * 0x224 + DAT_00434538;
  if (*(uint *)(iVar4 + 8) < uVar1 * 2) {
    return 0;
  }
  *(undefined2 *)(iVar4 + 2) = *(undefined2 *)(iVar2 + 0x20);
  iVar2 = DAT_0043756c * 0x224 + DAT_00434538;
  iVar2 = FUN_00405000(DAT_0043756c,(uint)*(byte *)(iVar2 + 2),(uint)*(byte *)(iVar2 + 3));
  if (iVar2 == 0) {
    return 0;
  }
  FUN_004051b0(DAT_0043756c);
  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 10;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  return 1;
}


