/* 00421270 */

undefined4 FUN_00421270(void)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint local_c;
  uint local_8;
  uint local_4;
  
  uVar6 = 0x1f0;
  bVar3 = 0;
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  do {
    pbVar4 = (byte *)((uint)bVar3 * 0x224 + DAT_00434538);
    if (((pbVar4[0x10] & 0x80) == 0) && ((pbVar4[0xd] & 0x20) != 0)) {
      if ((pbVar4[4] != DAT_00437580) &&
         (*(byte *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) != pbVar4[4])) {
        uVar1 = *(uint *)(DAT_0043453c + 8 + ((uint)*pbVar4 * 0x30 + (uint)pbVar4[1]) * 0x18);
        if ((uVar1 < 0x1f0) && (uVar1 < uVar6)) {
          uVar6 = uVar1;
          local_c = (uint)bVar3;
          local_8 = (uint)pbVar4[1];
          local_4 = (uint)*pbVar4;
        }
      }
    }
    bVar3 = bVar3 + 1;
  } while (bVar3 < 0x40);
  if (0x1ef < uVar6) {
    return 0;
  }
  iVar2 = DAT_0043756c * 0x224 + DAT_00434538;
  uVar1 = *(uint *)(iVar2 + 8);
  if (uVar1 < uVar6 * 2) {
    return 0;
  }
  iVar5 = local_c * 0x224 + DAT_00434538;
  if ((uint)*(byte *)(DAT_0043453c + 0x10 + (local_4 * 0x30 + local_8) * 0x18) -
      (uint)*(byte *)(iVar5 + 4) == 0x14) {
    uVar6 = *(int *)(iVar5 + 8) * 3;
    if (uVar1 < uVar6) {
      if (uVar1 <= uVar6 >> 2) {
        return 0;
      }
      *(undefined1 *)(iVar2 + 2) = (undefined1)local_4;
      *(char *)(DAT_00434538 + 3 + DAT_0043756c * 0x224) = (char)local_8 + '\x02';
      iVar2 = FUN_00405000(DAT_0043756c,local_4,local_8 + 2);
      if (iVar2 == 0) {
        return 0;
      }
      *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 2;
      *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
      return 1;
    }
  }
  else if (uVar1 < *(uint *)(iVar5 + 8)) {
    *(undefined2 *)(iVar2 + 2) =
         *(undefined2 *)(DAT_00434534 + 8 + (uint)*(byte *)(iVar5 + 4) * 0x38);
    iVar2 = DAT_0043756c * 0x224 + DAT_00434538;
    iVar2 = FUN_00405000(DAT_0043756c,(uint)*(byte *)(iVar2 + 2),(uint)*(byte *)(iVar2 + 3));
    if (iVar2 == 0) {
      return 0;
    }
    *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 2;
    *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
    return 1;
  }
  *(undefined2 *)(iVar2 + 2) = *(undefined2 *)(iVar5 + 2);
  iVar2 = DAT_0043756c * 0x224 + DAT_00434538;
  iVar2 = FUN_00405000(DAT_0043756c,(uint)*(byte *)(iVar2 + 2),(uint)*(byte *)(iVar2 + 3));
  if (iVar2 == 0) {
    return 0;
  }
  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 1;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  return 1;
}


