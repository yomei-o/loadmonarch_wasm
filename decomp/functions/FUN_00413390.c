/* 00413390 */

undefined4 __fastcall FUN_00413390(void *param_1)

{
  uint uVar1;
  HWND hWnd;
  int iVar2;
  int *piVar3;
  int local_14;
  int local_10;
  int local_c [3];
  
  local_c[0] = 0x447;
  local_c[1] = 0x448;
  uVar1 = 0;
  local_14 = 0;
  local_c[2] = 0x449;
  do {
    if (DAT_004365cd == uVar1) {
      local_14 = *(int *)(DAT_00434534 + 0x2c + uVar1 * 0x38);
      break;
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 4);
  iVar2 = 0;
  uVar1 = 0;
  local_10 = 1;
  piVar3 = local_c;
  do {
    if (DAT_004365cd == uVar1) {
      if (*(char *)(DAT_00434534 + 0x1e + iVar2) != -0x80) {
        FUN_0040ed80(param_1,0x432,1);
      }
      *(char *)((int)param_1 + 0x234) = (char)uVar1;
    }
    else {
      if (local_14 < *(int *)(DAT_00434534 + 0x2c + iVar2)) {
        hWnd = GetDlgItem(*(HWND *)((int)param_1 + 4),*piVar3);
        EnableWindow(hWnd,0);
      }
      piVar3 = piVar3 + 1;
      *(undefined1 *)(local_10 + 0x234 + (int)param_1) = *(undefined1 *)(DAT_00434534 + iVar2);
      local_10 = local_10 + 1;
    }
    iVar2 = iVar2 + 0x38;
    uVar1 = uVar1 + 1;
  } while (iVar2 < 0xe0);
  return 1;
}


