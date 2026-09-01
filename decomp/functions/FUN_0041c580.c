/* 0041c580 */

undefined4 __cdecl FUN_0041c580(undefined1 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_10;
  int local_c;
  
  iVar3 = 0x1f9;
  piVar5 = (int *)(DAT_0043453c + 8);
  iVar4 = 0;
  do {
    iVar2 = *piVar5;
    if (iVar2 < 0x1f0) {
      uVar1 = (uint)*(byte *)(piVar5 + 2);
      if (uVar1 == 5) {
joined_r0x0041c619:
        if (iVar2 < iVar3) {
switchD_0041c60a_caseD_1:
          iVar3 = iVar2;
          local_10 = iVar4 / 0x30;
          local_c = iVar4 % 0x30;
        }
      }
      else {
        iVar2 = iVar2 + 8;
        if (((iVar2 < iVar3) && (DAT_00437580 + 8U != uVar1)) &&
           (*(byte *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) + 8 != uVar1)) {
          switch(uVar1) {
          case 1:
          case 2:
          case 3:
          case 4:
          case 8:
          case 9:
          case 10:
          case 0xb:
            goto switchD_0041c60a_caseD_1;
          case 5:
            goto joined_r0x0041c619;
          }
        }
      }
    }
    piVar5 = piVar5 + 6;
    iVar4 = iVar4 + 1;
    if (0x8ff < iVar4) {
      iVar3 = iVar3 + -8;
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      else if (0x1ef < iVar3) {
        return 0;
      }
      *(int *)(param_1 + 4) = iVar3;
      *param_1 = (undefined1)local_10;
      param_1[1] = (undefined1)local_c;
      return 1;
    }
  } while( true );
}


