/* 00423480 */

void __fastcall FUN_00423480(int param_1)

{
  HPEN h;
  HDC hdc;
  HGDIOBJ h_00;
  int rop2;
  POINT local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(param_1 + 0x394) = 0;
  h = CreatePen(0,(int)(*(int *)(param_1 + 0x398) + (*(int *)(param_1 + 0x398) >> 0x1f & 7U)) >> 3,
                0x1000040);
  if (h != (HPEN)0x0) {
    hdc = GetDC(*(HWND *)(param_1 + 8));
    if (hdc == (HDC)0x0) {
      DeleteObject(h);
      return;
    }
    h_00 = SelectObject(hdc,h);
    rop2 = SetROP2(hdc,7);
    MoveToEx(hdc,*(int *)(param_1 + 0x39c),*(int *)(param_1 + 0x3a0),(LPPOINT)0x0);
    local_20.x = *(LONG *)(param_1 + 0x39c);
    local_20.y = *(LONG *)(param_1 + 0x3a8);
    local_18 = *(undefined4 *)(param_1 + 0x3a4);
    local_14 = *(undefined4 *)(param_1 + 0x3a8);
    local_c = *(undefined4 *)(param_1 + 0x3a0);
    local_4 = *(undefined4 *)(param_1 + 0x3a0);
    local_8 = *(undefined4 *)(param_1 + 0x39c);
    local_10 = local_18;
    PolylineTo(hdc,&local_20,4);
    if (h_00 != (HGDIOBJ)0x0) {
      SelectObject(hdc,h_00);
    }
    SetROP2(hdc,rop2);
    ReleaseDC(*(HWND *)(param_1 + 8),hdc);
    DeleteObject(h);
    ClipCursor((RECT *)0x0);
  }
  return;
}


