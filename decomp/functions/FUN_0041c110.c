/* 0041c110 */

undefined4 __thiscall FUN_0041c110(void *this,HWND param_1,uint param_2)

{
  int iVar1;
  HWND pHVar2;
  byte *pbVar3;
  WPARAM WVar4;
  uint uVar5;
  int local_10 [2];
  int local_8;
  
  iVar1 = FUN_0041bf70(this,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  pHVar2 = CreateToolbarEx(param_1,0x102,0x9c68,*(int *)((int)this + 0x20),DAT_004344d0,0x66,
                           *(LPCTBBUTTON *)((int)this + 0x18),*(int *)((int)this + 0x24),
                           *(int *)this,*(int *)((int)this + 4),*(int *)((int)this + 8),
                           *(int *)((int)this + 0xc),0x14);
  *(HWND *)((int)this + 0x28) = pHVar2;
  if (pHVar2 == (HWND)0x0) {
    return 0;
  }
  iVar1 = FUN_00427f90((*(int *)((int)this + 0x24) + 1) * 0x10);
  *(int *)((int)this + 0x1c) = iVar1;
  if (iVar1 == 0) {
    return 0;
  }
  uVar5 = 0;
  if (*(int *)((int)this + 0x24) != -1 && -1 < *(int *)((int)this + 0x24) + 1) {
    do {
      FUN_0041c290(this,uVar5,0);
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < *(int *)((int)this + 0x24) + 1);
  }
  FUN_0041c290(this,1,1);
  WVar4 = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  if (0 < *(int *)((int)this + 0x24)) {
    pbVar3 = (byte *)(*(int *)((int)this + 0x18) + 9);
    do {
      if ((*pbVar3 & 1) != 0) {
        FUN_0041c250(this,0x41d,WVar4,(LPARAM)local_10);
        *(int *)((int)this + 0x10) = local_8 - local_10[0];
        iVar1 = FUN_0041c270((int)this);
        *(int *)((int)this + 0x14) = iVar1 - *(int *)((int)this + 0xc);
        break;
      }
      pbVar3 = pbVar3 + 0x14;
      WVar4 = WVar4 + 1;
    } while ((int)WVar4 < *(int *)((int)this + 0x24));
  }
  DAT_00433fa4 = SetWindowLongA(*(HWND *)((int)this + 0x28),-4,0x41c380);
  ShowWindow(*(HWND *)((int)this + 0x28),5);
  return 1;
}


