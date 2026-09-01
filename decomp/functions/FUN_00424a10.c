/* 00424a10 */

void __fastcall FUN_00424a10(void *param_1)

{
  int iVar1;
  SHORT SVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  tagPOINT local_34;
  tagMSG local_2c;
  tagRECT local_10;
  
  if (*(int *)((int)param_1 + 0x17f4) == 0) {
    GetClientRect(*(HWND *)((int)param_1 + 8),&local_10);
    iVar3 = *(int *)((int)param_1 + 0x17f0);
    uVar7 = *(uint *)((int)param_1 + 0x14) & 0xffff;
    uVar4 = *(uint *)((int)param_1 + 0x14) >> 0x10;
    iVar1 = *(int *)((int)param_1 + 0x264);
    local_34.y = iVar1;
    if ((int)uVar4 < iVar3) {
      local_34.y = 0;
      iVar5 = iVar1 - (iVar3 - uVar4);
      if (0 < iVar5) {
        local_34.y = iVar5;
      }
    }
    if (iVar3 < (int)uVar4) {
      local_34.y = (uVar4 - iVar3) + iVar1;
    }
    iVar3 = *(int *)((int)param_1 + 0x17ec);
    local_34.x = *(uint *)((int)param_1 + 0x260);
    if ((int)uVar7 < iVar3) {
      local_34.x = 0;
      uVar6 = *(int *)((int)param_1 + 0x260) - (iVar3 - uVar7);
      if (0 < (int)uVar6) {
        local_34.x = uVar6;
      }
    }
    if (iVar3 < (int)uVar7) {
      local_34.x = (uVar7 - iVar3) + *(int *)((int)param_1 + 0x260);
    }
    SVar2 = GetAsyncKeyState(2);
    if (SVar2 == 0) {
      PeekMessageA(&local_2c,*(HWND *)((int)param_1 + 8),0x200,0x209,1);
      return;
    }
    *(uint *)((int)param_1 + 0x17ec) = uVar7;
    *(undefined4 *)((int)param_1 + 0x17e8) = 1;
    *(uint *)((int)param_1 + 0x17f0) = uVar4;
    FUN_00424620(param_1,(ushort *)&local_34);
    GetCursorPos(&local_34);
    ScreenToClient(*(HWND *)((int)param_1 + 8),&local_34);
    PostMessageA(*(HWND *)((int)param_1 + 8),0x200,2,local_34.y << 0x10 | local_34.x & 0xffffU);
  }
  else {
    iVar3 = *(int *)((int)param_1 + 0x17f4) + -1;
    *(int *)((int)param_1 + 0x17f4) = iVar3;
    if (iVar3 == 0) {
      PeekMessageA(&local_2c,*(HWND *)((int)param_1 + 8),0x200,0x209,1);
      return;
    }
  }
  return;
}


