/* 00421750 */

undefined4 FUN_00421750(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char local_7;
  char local_6;
  char local_5;
  int local_4;
  
  local_7 = '\0';
  do {
    FUN_0041d6d0((uint)*(byte *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224) + local_7 * 2 & 7,
                 &local_6);
    iVar2 = FUN_0041ec30(DAT_0043644c,DAT_00436450,(int)local_6,(int)local_5);
    if (iVar2 != 0) {
      local_4 = local_6 + DAT_0043644c;
      iVar2 = local_5 + DAT_00436450;
      if (*(byte *)(DAT_0043453c + 0x10 + (local_4 * 0x30 + iVar2) * 0x18) < 0x30) {
        pbVar1 = (byte *)(DAT_00434538 + 0xc + DAT_0043756c * 0x224);
        *pbVar1 = local_7 * '\x02' + *pbVar1 & 7;
        iVar3 = FUN_00420c60(local_4,iVar2);
        if (iVar3 == 1) {
          return 1;
        }
        iVar3 = FUN_00420610(local_4,iVar2);
        if (iVar3 == 1) {
          return 1;
        }
        iVar3 = (local_4 * 0x30 + iVar2) * 0x18;
        if (*(byte *)(DAT_0043453c + iVar3) < 0x40) {
          return 0;
        }
        iVar4 = FUN_004208b0(local_4,iVar2);
        if (iVar4 == 1) {
          return 1;
        }
        *(undefined1 *)(DAT_0043453c + DAT_00437690 * 0x18) = 0x40;
        *(undefined1 *)(DAT_0043453c + iVar3) = (undefined1)DAT_0043756c;
        *(undefined1 *)(DAT_00434538 + DAT_0043756c * 0x224) = (undefined1)local_4;
        *(char *)(DAT_00434538 + 1 + DAT_0043756c * 0x224) = (char)iVar2;
        return 1;
      }
    }
    local_7 = local_7 + '\x01';
    if ('\x03' < local_7) {
      return 0;
    }
  } while( true );
}


