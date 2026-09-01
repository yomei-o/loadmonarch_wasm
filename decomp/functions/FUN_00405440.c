/* 00405440 */

void __cdecl FUN_00405440(int param_1)

{
  bool bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int local_8;
  
  iVar2 = 0;
  local_8 = 0;
  do {
    if (((local_8 != param_1) &&
        (pbVar3 = (byte *)(DAT_00434538 + iVar2), (pbVar3[0x10] & 0x80) == 0)) &&
       (*(int *)(pbVar3 + 0x18) == 0x1f0)) {
      bVar1 = false;
      iVar4 = param_1 * 0x224 + DAT_00434538;
      if ((*(byte *)(DAT_00434534 + 0x1e + (uint)*(byte *)(iVar4 + 4) * 0x38) == pbVar3[4]) ||
         ((pbVar3[4] == *(byte *)(iVar4 + 4) &&
          (100000 < (uint)(*(int *)(pbVar3 + 8) + *(int *)(iVar4 + 8)))))) {
        bVar1 = true;
      }
      if (bVar1) {
        *(undefined1 *)(DAT_0043453c + 4 + ((uint)*pbVar3 * 0x30 + (uint)pbVar3[1]) * 0x18) = 1;
      }
    }
    iVar2 = iVar2 + 0x224;
    local_8 = local_8 + 1;
  } while (iVar2 < 0x8900);
  return;
}


