/* 004272b0 */

void FUN_004272b0(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = DAT_00434534;
  for (iVar2 = 0x46; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = DAT_00434538;
  for (iVar2 = 0x2240; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 0x224;
    *(undefined1 *)((int)DAT_00434538 + iVar2 + 0x10) = 0x80;
    puVar1 = (uint *)((int)DAT_00434538 + iVar2 + 0x21c);
    *puVar1 = *puVar1 & 0xfffffffe;
    *(undefined1 *)((int)DAT_00434538 + iVar2 + 0x220) = 0xff;
    *(undefined4 *)((int)DAT_00434538 + iVar2 + 0x18) = 0x1f0;
    iVar2 = iVar3;
  } while (iVar3 < 0x8900);
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 0x38;
    *(undefined4 *)((int)DAT_00434534 + iVar2 + 0x18) = 5000;
    *(undefined1 *)((int)DAT_00434534 + iVar2 + 0x1c) = 0;
    *(undefined1 *)((int)DAT_00434534 + iVar2 + 0x1e) = 0x80;
    *(undefined4 *)((int)DAT_00434534 + iVar2 + 0x14) = 0;
    puVar1 = (uint *)((int)DAT_00434534 + iVar2 + 4);
    *puVar1 = *puVar1 & 0xfffffff7;
    puVar1 = (uint *)((int)DAT_00434534 + iVar2 + 4);
    *puVar1 = *puVar1 & 0xfffffffe;
    puVar1 = (uint *)((int)DAT_00434534 + iVar2 + 4);
    *puVar1 = *puVar1 & 0xffffffef;
    puVar1 = (uint *)((int)DAT_00434534 + iVar2 + 4);
    *puVar1 = *puVar1 & 0xffffffbf;
    puVar1 = (uint *)((int)DAT_00434534 + iVar2 + 4);
    *puVar1 = *puVar1 & 0xfffffffd;
    puVar1 = (uint *)((int)DAT_00434534 + iVar2 + 4);
    *puVar1 = *puVar1 & 0xfffffffb;
    puVar1 = (uint *)((int)DAT_00434534 + iVar2 + 4);
    *puVar1 = *puVar1 & 0xffffffdf;
    iVar2 = iVar3;
  } while (iVar3 < 0x118);
  return;
}


