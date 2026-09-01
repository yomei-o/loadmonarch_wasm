/* 00420c60 */

undefined4 __cdecl FUN_00420c60(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar4 = (param_1 * 0x30 + param_2) * 0x18;
  bVar2 = *(byte *)(DAT_0043453c + iVar4);
  if (0x3f < bVar2) {
    return 0;
  }
  uVar5 = (uint)bVar2;
  iVar1 = uVar5 * 0x224;
  iVar6 = DAT_00434538 + iVar1;
  iVar3 = DAT_0043756c * 0x224 + DAT_00434538;
  if (*(char *)(iVar6 + 4) == *(char *)(iVar3 + 4)) {
    return 0;
  }
  if (*(char *)(DAT_00434534 + 0x1e + (uint)*(byte *)(iVar3 + 4) * 0x38) == *(char *)(iVar6 + 4)) {
    return 0;
  }
  if ((*(byte *)(iVar6 + 0xd) & 0xf) == 0xc) {
    return 0;
  }
  if ((0x1ef < *(uint *)(iVar6 + 0x18)) &&
     ((*(char *)(iVar3 + 0xc) + 4U & 6) != *(byte *)(iVar6 + 0xc))) {
    *(byte *)(iVar6 + 0xc) = *(char *)(iVar3 + 0xc) + 4U & 6;
  }
  iVar3 = *(byte *)(DAT_0043453c + 0x10 + DAT_00437690 * 0x18) - 0x14;
  if ((iVar3 < 4) && (-1 < iVar3)) {
    FUN_00420e70(DAT_0043756c,uVar5,(*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 2) + 1);
    return 1;
  }
  iVar4 = *(byte *)(DAT_0043453c + 0x10 + iVar4) - 0x14;
  if ((iVar4 < 4) && (-1 < iVar4)) {
    FUN_00420e70(DAT_0043756c,uVar5,(*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 3) + 1);
    FUN_00420e70(uVar5,DAT_0043756c,(*(uint *)(DAT_00434538 + 8 + iVar1) >> 3) + 1);
    return 1;
  }
  FUN_00420e70(DAT_0043756c,uVar5,(*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 3) + 1);
  FUN_00420e70(uVar5,DAT_0043756c,(*(uint *)(DAT_00434538 + 8 + iVar1) >> 4) + 1);
  return 1;
}


