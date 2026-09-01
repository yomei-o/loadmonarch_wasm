/* 00421f20 */

undefined4 FUN_00421f20(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = FUN_0041ec60(100);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = 0;
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  do {
    uVar3 = FUN_0041abf0();
    uVar5 = (uVar3 >> 8) * 0x30 >> 8;
    uVar3 = (uVar3 & 0xff) * 0x30 >> 8;
    iVar4 = (uVar5 * 0x30 + uVar3) * 0x18 + DAT_0043453c;
    if (((*(char *)(iVar4 + 0x10) == '\0') && (uVar1 = *(uint *)(iVar4 + 8), uVar1 < 0x1f0)) &&
       (uVar1 * 2 < *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224))) {
      iVar4 = FUN_0041e670(uVar5,uVar3);
      if (iVar4 == 0) {
        iVar4 = FUN_00405000(DAT_0043756c,uVar5,uVar3);
        if (iVar4 == 1) {
          *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 5;
          *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
          return 1;
        }
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  return 0;
}


