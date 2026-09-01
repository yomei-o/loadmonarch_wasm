/* 00425210 */

undefined4 __thiscall FUN_00425210(void *this,int param_1,int param_2)

{
  undefined4 *puVar1;
  void *pvVar2;
  bool bVar3;
  undefined3 extraout_var;
  LONG LVar4;
  int iVar5;
  int iVar6;
  HMENU hMenu;
  tagRECT local_20;
  tagRECT local_10;
  
  *(int *)((int)this + 4) = param_2;
  puVar1 = (undefined4 *)((int)this + 0x38);
  *puVar1 = 0;
  *(int *)((int)this + 0x250) = param_1;
  *(int *)((int)this + 0x40) = *(int *)((int)this + 0x18) + *(int *)((int)this + 0x20);
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(int *)((int)this + 0x44) = *(int *)((int)this + 0x24) + *(int *)((int)this + 0x1c);
  bVar3 = FUN_00424fa0(DAT_00436460,(LPCSTR)((int)this + 0x14c));
  pvVar2 = DAT_00436460;
  bVar3 = CONCAT31(extraout_var,bVar3) != 1;
  if (bVar3) {
    *puVar1 = *(undefined4 *)((int)this + 0x28);
    *(undefined4 *)((int)this + 0x3c) = *(undefined4 *)((int)this + 0x2c);
    *(undefined4 *)((int)this + 0x40) = *(undefined4 *)((int)this + 0x30);
    *(undefined4 *)((int)this + 0x44) = *(undefined4 *)((int)this + 0x34);
  }
  else {
    *puVar1 = *(undefined4 *)((int)DAT_00436460 + 0x34);
    *(undefined4 *)((int)this + 0x3c) = *(undefined4 *)((int)pvVar2 + 0x38);
    *(undefined4 *)((int)this + 0x40) = *(undefined4 *)((int)pvVar2 + 0x3c);
    *(undefined4 *)((int)this + 0x44) = *(undefined4 *)((int)pvVar2 + 0x40);
  }
  if ((((*(int *)((int)this + 0x3c) == 0) || (bVar3)) && (*(int *)((int)this + 4) != 0xea65)) &&
     (*(int *)((int)this + 4) != 70000)) {
    LVar4 = FUN_0040a0c0(0xea65);
    if ((LVar4 != 0) && (DAT_004376a3 == '\0')) {
      GetWindowRect(*(HWND *)(LVar4 + 8),&local_20);
      *(int *)((int)this + 0x3c) = *(int *)((int)this + 0x3c) + (local_20.bottom - local_20.top);
      if (*(int *)((int)this + 4) == 60000) {
        GetClientRect(*(HWND *)(DAT_004344e4 + 8),&local_10);
        if (local_10.bottom < *(int *)((int)this + 0x44) + *(int *)((int)this + 0x3c)) {
          *(LONG *)((int)this + 0x44) = local_10.bottom - *(int *)((int)this + 0x3c);
        }
      }
    }
  }
  iVar6 = *(int *)this;
  iVar5 = (**(code **)(iVar6 + 8))();
  if (iVar5 != 0) {
    iVar6 = (**(code **)(iVar6 + 0xc))();
    if (iVar6 != 0) {
      hMenu = GetMenu(*(HWND *)((int)this + 0x250));
      if (hMenu != (HMENU)0x0) {
        InsertMenuA(hMenu,0x9caf,0,*(int *)((int)this + 4) + 1000,(LPCSTR)((int)this + 0x48));
      }
      SetWindowPos(*(HWND *)((int)this + 8),(HWND)0x0,0,0,0,0,3);
      InvalidateRect(*(HWND *)((int)this + 8),(RECT *)0x0,0);
      UpdateWindow(*(HWND *)((int)this + 8));
      return 1;
    }
  }
  FUN_00409370(s_Fatal_error__Quitting__004344b8,0);
  return 0;
}


