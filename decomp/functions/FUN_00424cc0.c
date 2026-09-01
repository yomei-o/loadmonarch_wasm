/* 00424cc0 */

void __thiscall FUN_00424cc0(void *this,uint param_1)

{
  BOOL BVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  tagRECT local_3c;
  tagSCROLLINFO local_2c;
  tagRECT local_10;
  
  GetWindowRect(*(HWND *)((int)this + 8),&local_3c);
  iVar4 = *(int *)((int)this + 0x264);
  local_3c.right = (local_3c.right - local_3c.left) - *(int *)((int)this + 0x18);
  local_3c.bottom = (local_3c.bottom - local_3c.top) - *(int *)((int)this + 0x1c);
  switch(param_1 & 0xffff) {
  case 0:
    uVar3 = iVar4 - 8;
    break;
  case 1:
    uVar3 = iVar4 + 8;
    break;
  case 2:
    uVar3 = iVar4 - local_3c.bottom;
    break;
  case 3:
    uVar3 = iVar4 + local_3c.bottom;
    break;
  case 4:
  case 5:
    uVar3 = param_1 >> 0x10;
    break;
  default:
    goto switchD_00424d0c_default;
  }
  if ((int)uVar3 < 0) {
    uVar3 = 0;
  }
  iVar4 = *(int *)((int)this + 0x24);
  local_2c.cbSize = 0x1c;
  local_2c.fMask = 0x17;
  BVar1 = GetScrollInfo(*(HWND *)((int)this + 8),0,&local_2c);
  if ((BVar1 != 0) && (local_2c.nMax != 0)) {
    iVar2 = GetSystemMetrics(3);
    iVar4 = iVar4 + iVar2;
  }
  iVar2 = GetSystemMetrics(0x21);
  if ((iVar4 - iVar2) - local_3c.bottom < (int)uVar3) {
    uVar3 = iVar4 - local_3c.bottom;
  }
  GetClientRect(*(HWND *)((int)this + 8),&local_10);
  *(uint *)((int)this + 0x264) = uVar3;
  local_2c.nMin = 0;
  local_2c.nMax = iVar4;
  if (*(int *)((int)this + 0x24) <= local_10.bottom) {
    local_2c.nMax = 0;
  }
  local_2c.nPage = local_3c.bottom;
  local_2c.nPos = uVar3;
  SetScrollInfo(*(HWND *)((int)this + 8),1,&local_2c,1);
  (**(code **)(*(int *)this + 100))();
switchD_00424d0c_default:
  return;
}


