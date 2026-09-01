/* 00421ba0 */

undefined4 __cdecl FUN_00421ba0(uint param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined2 local_8;
  uint local_4;
  
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  iVar1 = FUN_0041c410((undefined1 *)&local_8);
  if (iVar1 == 0) {
    return 0;
  }
  if (param_1 <= local_4) {
    return 0;
  }
  iVar1 = DAT_0043756c * 0x224 + DAT_00434538;
  if (*(uint *)(iVar1 + 8) < local_4 * 2) {
    return 0;
  }
  switch(*(undefined1 *)
          (DAT_0043453c + 0x10 + ((uint)(byte)local_8 * 0x30 + (uint)local_8._1_1_) * 0x18)) {
  case 0:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    uVar2 = 5;
    break;
  case 1:
  case 2:
  case 3:
  case 4:
    uVar2 = 8;
    break;
  case 5:
    uVar2 = 0xb;
    break;
  default:
    return 0;
  case 8:
  case 9:
  case 10:
  case 0xb:
    uVar2 = 4;
  }
  *(undefined2 *)(iVar1 + 2) = local_8;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = uVar2;
  iVar1 = FUN_00405000(DAT_0043756c,(uint)(byte)local_8,(uint)local_8._1_1_);
  if (iVar1 == 0) {
    return 0;
  }
  if ((*(byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) & 0xf) == 0xb) {
    FUN_004051b0(DAT_0043756c);
  }
  return 1;
}


