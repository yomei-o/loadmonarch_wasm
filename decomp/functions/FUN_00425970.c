/* 00425970 */

void __fastcall FUN_00425970(int param_1)

{
  BOOL BVar1;
  int Y;
  int X;
  tagPOINT local_8;
  
  if (((*(int *)(param_1 + 0x268) != -1) || (*(int *)(param_1 + 0x26c) != -1)) &&
     (*(int *)(param_1 + 0x10) == 1)) {
    BVar1 = GetCursorPos(&local_8);
    if (BVar1 != 0) {
      X = (*(int *)(param_1 + 0x270) - *(int *)(param_1 + 0x268)) + local_8.x;
      Y = (*(int *)(param_1 + 0x274) - *(int *)(param_1 + 0x26c)) + local_8.y;
      SetWindowPos(*(HWND *)(param_1 + 8),(HWND)0x0,X,Y,0,0,5);
      *(LONG *)(param_1 + 0x268) = local_8.x;
      *(LONG *)(param_1 + 0x26c) = local_8.y;
      *(int *)(param_1 + 0x270) = X;
      *(int *)(param_1 + 0x274) = Y;
      *(undefined1 *)(param_1 + 900) = 1;
    }
  }
  return;
}


