/* 004228d0 */

undefined4 __fastcall FUN_004228d0(void *param_1)

{
  uint uVar1;
  tagRECT local_10;
  
  uVar1 = *(uint *)((int)param_1 + 0xc);
  if (0x112 < uVar1) {
    if (uVar1 == 0x114) {
      if (DAT_004376ad == '\0') {
        FUN_00408e10(2);
      }
      FUN_00424b90(param_1,*(uint *)((int)param_1 + 0x10));
      return 0;
    }
    if (uVar1 != 0x115) {
      if (uVar1 != 0x203) {
        return 0;
      }
      return 1;
    }
    if (DAT_004376ad == '\0') {
      FUN_00408e10(2);
    }
    FUN_00424cc0(param_1,*(uint *)((int)param_1 + 0x10));
    return 0;
  }
  if (uVar1 == 0x112) {
    if (*(int *)((int)param_1 + 0x10) != 0xf030) {
      return 0;
    }
    GetClientRect(DAT_004344d8,&local_10);
    MoveWindow(*(HWND *)((int)param_1 + 8),0,0,local_10.right,local_10.bottom,1);
    return 1;
  }
  if ((uVar1 == 0x47) && (*(int *)((int)param_1 + 0x25c) != 0)) {
    FUN_00424b90(param_1,CONCAT31((int3)(((uint)*(ushort *)((int)param_1 + 0x260) << 0x10) >> 8),5))
    ;
    FUN_00424cc0(param_1,CONCAT31((int3)(((uint)*(ushort *)((int)param_1 + 0x264) << 0x10) >> 8),5))
    ;
    return 0;
  }
  return 0;
}


