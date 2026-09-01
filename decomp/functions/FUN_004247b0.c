/* 004247b0 */

void FUN_004247b0(void)

{
  int iVar1;
  byte *pbVar2;
  uint *puVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte local_2;
  byte local_1;
  
  if (((*(byte *)(DAT_00434534 + 4) & 0x40) != 0) || (*(int *)(DAT_00434534 + 0xc) == 0x40)) {
    return;
  }
  local_2 = *(byte *)(DAT_00434534 + 8);
  local_1 = *(byte *)(DAT_00434534 + 9);
  iVar7 = *(int *)(DAT_00434534 + 0xc);
  iVar1 = iVar7 * 0x224;
  if ((*(byte *)(DAT_00434538 + iVar1) == local_2) &&
     (((byte *)(DAT_00434538 + iVar1))[1] == local_1)) {
    return;
  }
  if (DAT_004365dc != 0) {
    FUN_00409f90();
  }
  iVar5 = FUN_004237e0(iVar7,&local_2);
  if (iVar5 == 0) {
    FUN_0040a1c0(0x15f95);
    FUN_00409370(s_There_is_no_through_path__00434464,0);
    return;
  }
  cVar4 = *(char *)(DAT_00434538 + 0x220 + iVar1);
  if (cVar4 == '\x03') {
    DAT_00434544 = 1;
  }
  else {
    if (cVar4 != '\x04') goto LAB_0042488b;
    DAT_00434544 = 0;
  }
  DAT_0043454c = iVar7;
  FUN_004095d0(0x76,0,*(HWND *)(DAT_004344e4 + 8));
LAB_0042488b:
  pbVar2 = (byte *)(DAT_00434538 + 0xd + iVar1);
  *pbVar2 = *pbVar2 & 0x20 | 0xd;
  *(byte *)(DAT_00434538 + 2 + iVar1) = local_2;
  *(byte *)(DAT_00434538 + 3 + iVar1) = local_1;
  pbVar2 = (byte *)(DAT_00434538 + 0x10 + iVar1);
  *pbVar2 = *pbVar2 & 0xf3;
  FUN_00405360();
  FUN_004056f0(&local_2);
  FUN_0041a680((uint)*(byte *)(DAT_00434538 + iVar1),(uint)((byte *)(DAT_00434538 + iVar1))[1]);
  *(undefined4 *)(DAT_00434538 + 0x18 + iVar1) = 0x1f0;
  FUN_00405000(iVar7,(uint)local_2,(uint)local_1);
  iVar7 = DAT_00434538 + iVar1;
  if ((*(byte *)(iVar7 + 0xd) & 0x20) != 0) {
    uVar6 = (uint)*(byte *)(iVar7 + 4);
    if (*(byte *)(DAT_0043453c + 0x10 +
                 ((uint)*(byte *)(iVar7 + 2) * 0x30 + (uint)*(byte *)(iVar7 + 3)) * 0x18) - uVar6 ==
        0x14) {
      puVar3 = (uint *)(DAT_00434534 + 4 + uVar6 * 0x38);
      *puVar3 = *puVar3 & 0xfffffffd;
      puVar3 = (uint *)(DAT_00434534 + 4 + (uint)*(byte *)(DAT_00434538 + 4 + iVar1) * 0x38);
      *puVar3 = *puVar3 & 0xfffffffb;
    }
    else {
      puVar3 = (uint *)(DAT_00434534 + 4 + uVar6 * 0x38);
      *puVar3 = *puVar3 | 2;
    }
  }
  puVar3 = (uint *)(DAT_00434538 + 0x21c + iVar1);
  *puVar3 = *puVar3 & 0xfffffffe;
  FUN_0040a1c0(0x15f92);
  DAT_004365dc = 0;
  return;
}


