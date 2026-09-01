/* 00423220 */

void __fastcall FUN_00423220(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  HPEN h;
  HDC hdc;
  HGDIOBJ h_00;
  int local_38;
  int local_34;
  POINT local_28;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  HPALETTE local_4;
  
  piVar1 = (int *)(param_1 + 0x3a4);
  if (((*piVar1 == -1) ||
      (iVar3 = *(int *)(param_1 + 0x398),
      ((*(int *)(param_1 + 0x3ac) + *(int *)(param_1 + 0x260)) / iVar3) * iVar3 - *piVar1 !=
      *(int *)(param_1 + 0x260))) ||
     (((*(int *)(param_1 + 0x3b0) + *(int *)(param_1 + 0x264)) / iVar3) * iVar3 -
      *(int *)(param_1 + 0x3a8) != *(int *)(param_1 + 0x264))) {
    h = CreatePen(0,(int)(*(int *)(param_1 + 0x398) + (*(int *)(param_1 + 0x398) >> 0x1f & 7U)) >> 3
                  ,0x1000040);
    if (h != (HPEN)0x0) {
      hdc = GetDC(*(HWND *)(param_1 + 8));
      if (hdc == (HDC)0x0) {
        DeleteObject(h);
        return;
      }
      local_4 = SelectPalette(hdc,DAT_004365f4,0);
      piVar2 = (int *)(param_1 + 0x39c);
      h_00 = SelectObject(hdc,h);
      local_8 = SetROP2(hdc,7);
      MoveToEx(hdc,*piVar2,*(int *)(param_1 + 0x3a0),(LPPOINT)0x0);
      iVar3 = *piVar1;
      if (iVar3 != -1) {
        local_28.x = *piVar2;
        local_28.y = *(LONG *)(param_1 + 0x3a8);
        local_1c = *(undefined4 *)(param_1 + 0x3a8);
        local_10 = *piVar2;
        local_14 = *(undefined4 *)(param_1 + 0x3a0);
        local_c = *(undefined4 *)(param_1 + 0x3a0);
        local_20 = iVar3;
        local_18 = iVar3;
        PolylineTo(hdc,&local_28,4);
      }
      MoveToEx(hdc,*piVar2,*(int *)(param_1 + 0x3a0),(LPPOINT)0x0);
      iVar3 = *(int *)(param_1 + 0x398);
      local_38 = ((*(int *)(param_1 + 0x260) + *(int *)(param_1 + 0x3ac)) / iVar3) * iVar3 -
                 *(int *)(param_1 + 0x260);
      local_34 = ((*(int *)(param_1 + 0x264) + *(int *)(param_1 + 0x3b0)) / iVar3) * iVar3 -
                 *(int *)(param_1 + 0x264);
      local_28.x = *piVar2;
      if (local_38 == local_28.x) {
        local_38 = local_28.x + iVar3;
      }
      if (local_34 == *(int *)(param_1 + 0x3a0)) {
        local_34 = iVar3 + *(int *)(param_1 + 0x3a0);
      }
      local_14 = *(undefined4 *)(param_1 + 0x3a0);
      local_28.y = local_34;
      local_20 = local_38;
      local_1c = local_34;
      local_18 = local_38;
      local_10 = *piVar2;
      local_c = *(undefined4 *)(param_1 + 0x3a0);
      PolylineTo(hdc,&local_28,4);
      *piVar1 = local_38;
      *(int *)(param_1 + 0x3a8) = local_34;
      if (h_00 != (HGDIOBJ)0x0) {
        SelectObject(hdc,h_00);
      }
      SetROP2(hdc,local_8);
      SelectPalette(hdc,local_4,1);
      ReleaseDC(*(HWND *)(param_1 + 8),hdc);
      DeleteObject(h);
    }
  }
  return;
}


