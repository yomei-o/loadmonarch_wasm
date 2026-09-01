/* 00424b90 */

void __thiscall FUN_00424b90(void *this,uint param_1)

{
  uint uVar1;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  tagRECT local_2c;
  tagSCROLLINFO local_1c;
  
  GetWindowRect(*(HWND *)((int)this + 8),&local_2c);
  iVar4 = *(int *)((int)this + 0x260);
  local_2c.right = (local_2c.right - local_2c.left) - *(int *)((int)this + 0x18);
  local_2c.bottom = (local_2c.bottom - local_2c.top) - *(int *)((int)this + 0x1c);
  switch(param_1 & 0xffff) {
  case 0:
    uVar1 = iVar4 - 8;
    break;
  case 1:
    uVar1 = iVar4 + 8;
    break;
  case 2:
    uVar1 = iVar4 - local_2c.right;
    break;
  case 3:
    uVar1 = iVar4 + local_2c.right;
    break;
  case 4:
  case 5:
    uVar1 = param_1 >> 0x10;
    break;
  default:
    goto switchD_00424bdb_default;
  }
  if ((int)uVar1 < 0) {
    uVar1 = 0;
  }
  iVar4 = *(int *)((int)this + 0x20);
  local_1c.cbSize = 0x1c;
  local_1c.fMask = 0x17;
  BVar2 = GetScrollInfo(*(HWND *)((int)this + 8),1,&local_1c);
  if ((BVar2 != 0) && (local_1c.nMax != 0)) {
    iVar3 = GetSystemMetrics(2);
    iVar4 = iVar4 + iVar3;
  }
  local_1c.nPos = uVar1;
  if (iVar4 - local_2c.right < (int)uVar1) {
    local_1c.nPos = iVar4 - local_2c.right;
  }
  *(int *)((int)this + 0x260) = local_1c.nPos;
  local_1c.nMin = 0;
  local_1c.nMax = iVar4;
  if (*(int *)((int)this + 0x20) <= local_2c.right) {
    local_1c.nMax = 0;
  }
  local_1c.nPage = local_2c.right;
  SetScrollInfo(*(HWND *)((int)this + 8),0,&local_1c,1);
  (**(code **)(*(int *)this + 100))();
switchD_00424bdb_default:
  return;
}


