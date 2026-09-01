/* 00408870 */

void FUN_00408870(void)

{
  int *piVar1;
  tagPOINT local_8;
  
  switch(DAT_004365dc) {
  case 0:
    GetCursorPos(&local_8);
    DAT_004365dc = 3;
    GetCursorPos(&local_8);
    FUN_0040a980(&local_8.x);
    return;
  case 1:
    FUN_00409f90();
    return;
  case 3:
    DAT_004365dc = 1;
    piVar1 = (int *)FUN_0040a0c0(60000);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 100))();
      return;
    }
    break;
  case 4:
    FUN_00409f90();
    DAT_004365dc = 1;
    return;
  case 5:
    DAT_004365dc = 1;
  }
  return;
}


