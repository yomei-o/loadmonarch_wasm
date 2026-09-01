/* 004273f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004273f0(void)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint local_10 [2];
  undefined1 local_8;
  char local_4;
  
  iVar8 = 0;
  FUN_004272b0();
  local_10[0] = 0x38;
  iVar7 = 0;
  do {
    pbVar1 = (byte *)(DAT_0043453c + 0x10 + iVar8);
    bVar2 = *pbVar1;
    uVar6 = (uint)bVar2;
    if (uVar6 == 6) {
      *pbVar1 = 0;
      *(undefined4 *)(DAT_0043453c + 0xc + iVar8) = 100;
      if ((local_10[0] != 0) && (iVar4 = FUN_0041cdc0(), iVar4 < 0x40)) {
        local_10[0] = local_10[0] - 1;
        iVar3 = iVar4 * 0x224;
        *(char *)(DAT_00434538 + iVar3) = (char)(iVar7 / 0x30);
        *(char *)(DAT_00434538 + 1 + iVar3) = (char)(iVar7 % 0x30);
        ((undefined2 *)(DAT_00434538 + iVar3))[1] = *(undefined2 *)(DAT_00434538 + iVar3);
        *(undefined1 *)(DAT_00434538 + 0xc + iVar3) = 6;
        *(undefined1 *)(DAT_00434538 + 0xd + iVar3) = 0xe;
        *(undefined1 *)(DAT_00434538 + 4 + iVar3) = 4;
        *(undefined4 *)(DAT_00434538 + 8 + iVar3) = 200;
        *(undefined1 *)(DAT_00434538 + 0xf + iVar3) = 0x81;
        *(char *)(DAT_0043453c + iVar8) = (char)iVar4;
        *(undefined1 *)(DAT_00434538 + 0x10 + iVar3) = 0;
      }
    }
    else if ((0x13 < bVar2) && (bVar2 < 0x18)) {
      iVar4 = ((uVar6 * 8 + -0xa0) - (uVar6 - 0x14)) * 8;
      local_8 = (undefined1)(iVar7 / 0x30);
      *(undefined1 *)(DAT_00434534 + 8 + iVar4) = local_8;
      local_4 = (char)(iVar7 % 0x30);
      *(char *)(DAT_00434534 + 9 + iVar4) = local_4;
      uVar5 = (undefined1)(uVar6 - 0x14);
      *(undefined1 *)(DAT_00434534 + iVar4) = uVar5;
      iVar3 = FUN_0041cdc0();
      *(int *)(DAT_00434534 + 0xc + iVar4) = iVar3;
      iVar3 = iVar3 * 0x224;
      *(undefined1 *)(DAT_00434538 + iVar3) = local_8;
      *(char *)(DAT_00434538 + 1 + iVar3) = local_4;
      ((undefined2 *)(DAT_00434538 + iVar3))[1] = *(undefined2 *)(DAT_00434538 + iVar3);
      *(undefined1 *)(DAT_00434538 + 0xc + iVar3) = 6;
      *(undefined1 *)(DAT_00434538 + 0xd + iVar3) = 0x2d;
      *(undefined1 *)(DAT_00434538 + 4 + iVar3) = uVar5;
      *(undefined4 *)(DAT_00434538 + 8 + iVar3) = 1000;
      *(undefined1 *)(DAT_00434538 + 0x10 + iVar3) = 0;
      iVar4 = FUN_0041cdc0();
      iVar4 = iVar4 * 0x224;
      *(undefined1 *)(DAT_00434538 + iVar4) = local_8;
      *(char *)(DAT_00434538 + 1 + iVar4) = local_4 + '\x01';
      ((undefined2 *)(DAT_00434538 + iVar4))[1] = *(undefined2 *)(DAT_00434538 + iVar4);
      *(undefined1 *)(DAT_00434538 + 0xc + iVar4) = 6;
      *(undefined1 *)(DAT_00434538 + 0xd + iVar4) = 1;
      *(undefined1 *)(DAT_00434538 + 4 + iVar4) = uVar5;
      *(undefined4 *)(DAT_00434538 + 8 + iVar4) = 200;
      *(undefined1 *)(DAT_00434538 + 0x10 + iVar4) = 0;
    }
    iVar8 = iVar8 + 0x18;
    iVar7 = iVar7 + 1;
  } while (iVar8 < 0xd800);
  iVar7 = 0;
  *(undefined1 *)(DAT_00434534 + 0xe0) = 4;
  *(undefined4 *)(DAT_00434534 + 0xf8) = 5000;
  *(undefined1 *)(DAT_00434534 + 0xfe) = 0x80;
  *(undefined4 *)(DAT_00434534 + 0xf4) = 0;
  *(uint *)(DAT_00434534 + 0xe4) = *(uint *)(DAT_00434534 + 0xe4) & 0xfffffffe;
  *(uint *)(DAT_00434534 + 0xe4) = *(uint *)(DAT_00434534 + 0xe4) & 0xfffffffd;
  iVar8 = 0;
  *(uint *)(DAT_00434534 + 0xe4) = *(uint *)(DAT_00434534 + 0xe4) & 0xfffffffb;
  *(uint *)(DAT_00434534 + 0xe4) = *(uint *)(DAT_00434534 + 0xe4) & 0xffffffdf;
  *(undefined4 *)(DAT_00434534 + 0xec) = 0;
  do {
    bVar2 = *(byte *)(DAT_0043453c + 0x10 + iVar8);
    if ((7 < bVar2) && (bVar2 < 0xc)) {
      DAT_00437580 = bVar2 - 8;
      FUN_0041ee10(iVar7 / 0x30,iVar7 % 0x30,(char *)local_10);
      *(uint *)(DAT_0043453c + 0xc + iVar8) = ((local_10[0] & 0xff) + 1) * 0x10;
    }
    iVar8 = iVar8 + 0x18;
    iVar7 = iVar7 + 1;
  } while (iVar8 < 0xd800);
  DAT_004365c4 = 3000;
  DAT_004365c8 = 0;
  if ((DAT_0043450c <= DAT_00436a00) && (DAT_0043450c != 0)) {
    DAT_004365c4 = *(int *)(&DAT_004369d4 + DAT_0043450c * 0x38) + 3000;
  }
  DAT_004365bc = DAT_004365c4;
  _DAT_004365e0 = 1;
  DAT_004365e4 = 0;
  return;
}


