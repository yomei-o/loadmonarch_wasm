/* 00422d20 */

void __fastcall FUN_00422d20(void *param_1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *this;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 local_14;
  RECT local_10;
  
  uVar5 = (*(int *)((int)param_1 + 0x260) + *(int *)((int)param_1 + 0x3ac)) /
          *(int *)((int)param_1 + 0x398);
  uVar6 = (*(int *)((int)param_1 + 0x3b0) + *(int *)((int)param_1 + 0x264)) /
          *(int *)((int)param_1 + 0x398);
  if (((((int)uVar5 < 0x2f) && ((int)uVar6 < 0x2f)) && (0 < (int)uVar5)) &&
     ((0 < (int)uVar6 &&
      ((*(byte *)((int)param_1 + 0x3c0) != uVar5 || (*(byte *)((int)param_1 + 0x3c1) != uVar6))))))
  {
    if (DAT_004376ad == '\0') {
      FUN_00408e10((10 - (uint)DAT_004376ac) * 2);
    }
    local_14 = (undefined1)uVar5;
    local_10.bottom = *(int *)((int)param_1 + 0x398);
    *(undefined1 *)((int)param_1 + 0x3c0) = local_14;
    *(char *)((int)param_1 + 0x3c1) = (char)uVar6;
    local_10.left =
         ((uint)*(byte *)((int)param_1 + 0x3c4) - *(int *)((int)param_1 + 0x260) / local_10.bottom)
         * local_10.bottom - *(int *)((int)param_1 + 0x260) % local_10.bottom;
    local_10.top = ((uint)*(byte *)((int)param_1 + 0x3c5) -
                   *(int *)((int)param_1 + 0x264) / local_10.bottom) * local_10.bottom -
                   *(int *)((int)param_1 + 0x264) % local_10.bottom;
    local_10.right = local_10.left + local_10.bottom;
    local_10.bottom = local_10.bottom + local_10.top;
    iVar9 = 0;
    FUN_00422fd0(param_1,(uint)*(byte *)((int)param_1 + 0x3c4),(uint)*(byte *)((int)param_1 + 0x3c5)
                );
    InvalidateRect(*(HWND *)((int)param_1 + 8),&local_10,0);
    *(undefined2 *)((int)param_1 + 0x3c4) = *(undefined2 *)((int)param_1 + 0x3c0);
    *(undefined4 *)((int)param_1 + 0x3b4) = *(undefined4 *)((int)param_1 + 0x3ac);
    *(undefined4 *)((int)param_1 + 0x3b8) = *(undefined4 *)((int)param_1 + 0x3b0);
    local_10.bottom = *(int *)((int)param_1 + 0x398);
    local_10.left =
         ((uint)*(byte *)((int)param_1 + 0x3c0) - *(int *)((int)param_1 + 0x260) / local_10.bottom)
         * local_10.bottom - *(int *)((int)param_1 + 0x260) % local_10.bottom;
    local_10.top = ((uint)*(byte *)((int)param_1 + 0x3c1) -
                   *(int *)((int)param_1 + 0x264) / local_10.bottom) * local_10.bottom -
                   *(int *)((int)param_1 + 0x264) % local_10.bottom;
    local_10.right = local_10.left + local_10.bottom;
    local_10.bottom = local_10.bottom + local_10.top;
    InvalidateRect(*(HWND *)((int)param_1 + 8),&local_10,1);
    FUN_00422fd0(param_1,(uint)*(byte *)((int)param_1 + 0x3c0),(uint)*(byte *)((int)param_1 + 0x3c1)
                );
    if (DAT_004365dc != 2) {
      iVar4 = *(int *)((int)param_1 + 0x398);
      bVar1 = *(byte *)((int)param_1 + 0x3c1);
      bVar2 = *(byte *)((int)param_1 + 0x3c0);
      iVar7 = 0;
      if (0 < iVar4) {
        do {
          iVar8 = 0;
          if (0 < *(int *)((int)param_1 + 0x398)) {
            do {
              cVar3 = *(char *)(DAT_00435fd4 + iVar9 + iVar8 + iVar4 + 0x1078);
              if (cVar3 != 'p') {
                *(char *)(*(int *)((int)param_1 + 0x398) * iVar7 * 0x30 +
                          *(int *)((int)param_1 + 0x25c) +
                          ((uint)bVar1 * iVar4 * 0x30 + (uint)bVar2) * iVar4 + iVar8) = cVar3;
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < *(int *)((int)param_1 + 0x398));
          }
          iVar9 = iVar9 + 0x100;
          iVar7 = iVar7 + 1;
        } while (iVar7 < *(int *)((int)param_1 + 0x398));
      }
    }
    this = (int *)FUN_0040a0c0(0xea61);
    if (this != (int *)0x0) {
      FUN_004271b0(this,(byte *)((int)param_1 + 0x3c0));
      (**(code **)(*this + 100))();
    }
    UpdateWindow(*(HWND *)((int)param_1 + 8));
  }
  return;
}


