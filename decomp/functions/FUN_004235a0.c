/* 004235a0 */

undefined4 __fastcall FUN_004235a0(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_00423480(param_1);
  local_10 = *(int *)(param_1 + 0x398);
  local_c = (*(int *)(param_1 + 0x39c) + *(int *)(param_1 + 0x260)) / local_10;
  iVar2 = (*(int *)(param_1 + 0x3a0) + *(int *)(param_1 + 0x264)) / local_10;
  iVar3 = (*(int *)(param_1 + 0x3ac) + *(int *)(param_1 + 0x260)) / local_10;
  local_10 = (*(int *)(param_1 + 0x3b0) + *(int *)(param_1 + 0x264)) / local_10;
  if (iVar3 == local_c) {
    iVar3 = iVar3 + 1;
  }
  if (local_10 == iVar2) {
    local_10 = local_10 + 1;
  }
  iVar6 = iVar3;
  if (iVar3 < local_c) {
    iVar6 = local_c;
    local_c = iVar3;
  }
  local_8 = iVar2;
  if (local_10 < iVar2) {
    local_8 = local_10;
    local_10 = iVar2;
  }
  iVar2 = 0;
  iVar3 = 0;
  DAT_00434440 = 0x40;
  do {
    iVar4 = iVar2 / 0x30;
    if ((local_c <= iVar4) && (iVar4 < iVar6)) {
      iVar5 = iVar2 % 0x30;
      if ((local_8 <= iVar5) && ((iVar5 < local_10 && (*(byte *)(DAT_0043453c + iVar3) < 0x40)))) {
        iVar4 = FUN_0040a020((uint)*(byte *)(DAT_0043453c + iVar3),iVar4,iVar5,1);
        if (iVar4 == 1) {
          if ((*(byte *)(DAT_00434538 + 0xd + (uint)*(byte *)(DAT_0043453c + iVar3) * 0x224) & 0x20)
              != 0) {
            DAT_00434440 = (uint)*(byte *)(DAT_0043453c + iVar3);
          }
          *(int *)(param_1 + 0x394) = *(int *)(param_1 + 0x394) + 1;
        }
      }
    }
    iVar3 = iVar3 + 0x18;
    iVar2 = iVar2 + 1;
  } while (iVar3 < 0xd800);
  if (*(int *)(param_1 + 0x394) == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x394) == 1) {
    return 1;
  }
  if (DAT_00434440 != 0x40) {
    puVar1 = (uint *)(DAT_00434538 + 0x21c + DAT_00434440 * 0x224);
    *puVar1 = *puVar1 & 0xfffffffe;
    *(undefined1 *)(DAT_00434538 + 0x220 + DAT_00434440 * 0x224) = 0xff;
    DAT_00434440 = 0x40;
  }
  return 1;
}


