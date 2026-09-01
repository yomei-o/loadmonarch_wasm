/* 00405510 */

void __cdecl FUN_00405510(int param_1)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8;
  
  iVar6 = 0;
  local_8 = 0;
  do {
    if (((local_8 != param_1) &&
        (pbVar2 = (byte *)(DAT_00434538 + iVar6), (pbVar2[0x10] & 0x80) == 0)) &&
       (*(int *)(pbVar2 + 0x18) == 0x1f0)) {
      iVar3 = 0;
      iVar5 = param_1 * 0x224 + DAT_00434538;
      if (*(byte *)(DAT_00434534 + 0x1e + (uint)*(byte *)(iVar5 + 4) * 0x38) == pbVar2[4]) {
        iVar3 = 1;
      }
      else if (pbVar2[4] == *(byte *)(iVar5 + 4)) {
        if (100000 < (uint)(*(int *)(pbVar2 + 8) + *(int *)(iVar5 + 8))) {
          iVar3 = 1;
        }
      }
      else if ((uint)*(byte *)(DAT_0043453c + 0x10 + ((uint)*pbVar2 * 0x30 + (uint)pbVar2[1]) * 0x18
                              ) - (uint)pbVar2[4] == 0x14) {
        iVar4 = 2;
        if ((pbVar2[0xd] & 0x20) != 0) {
          iVar4 = 4;
        }
        if ((99999 < (uint)(*(int *)(pbVar2 + 8) * iVar4)) ||
           (*(uint *)(iVar5 + 8) < (uint)(*(int *)(pbVar2 + 8) * iVar4))) {
LAB_00405608:
          iVar3 = 4;
        }
      }
      else {
        uVar1 = *(uint *)(pbVar2 + 8);
        if ((0xcccc < uVar1) || (*(uint *)(iVar5 + 8) < (uVar1 >> 2) + uVar1)) goto LAB_00405608;
      }
      if (iVar3 != 0) {
        if (iVar3 == 1) {
          *(undefined1 *)(DAT_0043453c + 4 + ((uint)*pbVar2 * 0x30 + (uint)pbVar2[1]) * 0x18) = 1;
        }
        else {
          *(undefined1 *)(DAT_0043453c + -0x14 + ((uint)*pbVar2 * 0x30 + (uint)pbVar2[1]) * 0x18) =
               1;
          *(undefined1 *)
           (DAT_0043453c + 0x1c +
           ((uint)*(byte *)(DAT_00434538 + iVar6) * 0x30 + (uint)((byte *)(DAT_00434538 + iVar6))[1]
           ) * 0x18) = 1;
          *(undefined1 *)
           (DAT_0043453c + -0x47c +
           ((uint)*(byte *)(DAT_00434538 + iVar6) * 0x30 + (uint)((byte *)(DAT_00434538 + iVar6))[1]
           ) * 0x18) = 1;
          *(undefined1 *)
           (DAT_0043453c + 0x484 +
           ((uint)*(byte *)(DAT_00434538 + iVar6) * 0x30 + (uint)((byte *)(DAT_00434538 + iVar6))[1]
           ) * 0x18) = 1;
        }
      }
    }
    iVar6 = iVar6 + 0x224;
    local_8 = local_8 + 1;
    if (0x88ff < iVar6) {
      return;
    }
  } while( true );
}


