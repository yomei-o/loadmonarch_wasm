/* 00411d70 */

void __fastcall FUN_00411d70(int param_1)

{
  int iVar1;
  int local_8 [2];
  
  if (*(int *)(param_1 + 0x23c) == 0) {
    FUN_004243c0((uint)*(byte *)(DAT_00434534 + *(int *)(param_1 + 0x234) * 0x38) << 3 | 0x66,0x20,
                 0x100,0x40,(undefined4 *)(*(int *)(param_1 + 0x22c) + 0x1010),DAT_00436440);
    FUN_0040a1c0(DAT_00434514 * 100 + 8);
  }
  iVar1 = *(int *)(param_1 + 0x23c);
  if ((0 < iVar1) && (iVar1 < 5)) {
    FUN_004243c0((iVar1 + (uint)*(byte *)(DAT_00434534 + *(int *)(param_1 + 0x234) * 0x38) * 8) - 1
                 | 0xa4,0x20,0x100,0x40,(undefined4 *)(*(int *)(param_1 + 0x22c) + 0x1010),
                 DAT_00436440);
  }
  local_8[0] = 0x100;
  local_8[1] = 0x40;
  if (*(int *)(param_1 + 0x23c) == 6) {
    wsprintfA((LPSTR)(param_1 + 0x1c),s__s_has_Fallen_00433814,
              &DAT_00435b31 +
              (uint)*(byte *)(DAT_00434534 + *(int *)(param_1 + 0x234) * 0x38) * 0x11);
    FUN_0040a870(0x30,0x18,0,1,(LPSTR)(param_1 + 0x1c),*(HDC *)(param_1 + 0x224),1,local_8);
  }
  return;
}


