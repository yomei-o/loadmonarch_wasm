/* 0041c410 */

undefined4 __cdecl FUN_0041c410(undefined1 *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_14;
  int local_10;
  int local_c;
  
  iVar3 = FUN_0041ec60(100);
  if (iVar3 == 0) {
    uVar4 = FUN_0041c580(param_1);
    return uVar4;
  }
  iVar8 = 0x1f9;
  uVar5 = DAT_00437580 + 8;
  iVar3 = 0;
  local_c = 0;
  bVar1 = *(byte *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38);
  do {
    iVar9 = *(int *)(DAT_0043453c + iVar3 + 8);
    if (iVar9 < 0x1f0) {
      bVar2 = *(byte *)(DAT_0043453c + iVar3 + 0x10);
      uVar6 = (uint)bVar2;
      if (uVar6 == 5) {
joined_r0x0041c4fc:
        if (iVar9 < iVar8) goto switchD_0041c4d9_caseD_1;
      }
      else {
        iVar9 = iVar9 + 8;
        if (((iVar9 < iVar8) && (uVar6 != uVar5)) && (uVar6 != bVar1 + 8)) {
          if ((uVar6 == 0) || ((0xb < bVar2 && (bVar2 < 0x10)))) {
            iVar7 = FUN_0041e670(local_c / 0x30,local_c % 0x30);
            if (iVar7 == 0) goto switchD_0041c4d9_caseD_1;
          }
          else {
            switch(uVar6) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 8:
            case 9:
            case 10:
            case 0xb:
switchD_0041c4d9_caseD_1:
              iVar8 = iVar9;
              local_14 = local_c / 0x30;
              local_10 = local_c % 0x30;
              break;
            case 5:
              goto joined_r0x0041c4fc;
            }
          }
        }
      }
    }
    iVar3 = iVar3 + 0x18;
    local_c = local_c + 1;
    if (0xd7ff < iVar3) {
      iVar8 = iVar8 + -8;
      if (iVar8 < 0) {
        iVar8 = 0;
      }
      else if (0x1ef < iVar8) {
        return 0;
      }
      *(int *)(param_1 + 4) = iVar8;
      *param_1 = (undefined1)local_14;
      param_1[1] = (undefined1)local_10;
      return 1;
    }
  } while( true );
}


