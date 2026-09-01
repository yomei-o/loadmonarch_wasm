/* 00427210 */

void FUN_00427210(void)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  byte *pbVar4;
  
  iVar3 = 0;
  do {
    iVar3 = iVar3 + 0x18;
    *(undefined1 *)(DAT_0043453c + -0x18 + iVar3) = 0x40;
    *(undefined4 *)(DAT_0043453c + -4 + iVar3) = 0;
  } while (iVar3 < 0xd800);
  iVar3 = 0;
  cVar2 = '\0';
  do {
    puVar1 = (uint *)(DAT_00434538 + 0x21c + iVar3);
    *puVar1 = *puVar1 & 0xfffffffe;
    *(undefined1 *)(DAT_00434538 + 0x220 + iVar3) = 0xff;
    pbVar4 = (byte *)(DAT_00434538 + iVar3);
    if ((pbVar4[0x10] & 0x80) == 0) {
      *(char *)(DAT_0043453c + ((uint)*pbVar4 * 0x30 + (uint)pbVar4[1]) * 0x18) = cVar2;
    }
    iVar3 = iVar3 + 0x224;
    cVar2 = cVar2 + '\x01';
  } while (iVar3 < 0x8900);
  FUN_0041b640();
  DAT_004365dc = 0;
  return;
}


