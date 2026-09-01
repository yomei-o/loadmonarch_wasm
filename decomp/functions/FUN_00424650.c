/* 00424650 */

void __thiscall FUN_00424650(void *this,int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char local_8;
  
  iVar4 = param_1 * 0x38 + DAT_00434534;
  bVar1 = *(byte *)(iVar4 + 8);
  bVar2 = *(byte *)(iVar4 + 9);
  if ((*(byte *)(iVar4 + 4) & 0x40) == 0) {
    local_8 = '\0';
    if (param_2 != 0) {
      local_8 = '\x10';
    }
    iVar4 = -1;
    do {
      iVar5 = -1;
      iVar6 = (bVar1 - 1) * 0x30 + (uint)bVar2 + iVar4;
      do {
        if (((iVar4 != 0) || (iVar5 != 0)) && ((iVar4 != 1 || (iVar5 != 0)))) {
          iVar3 = *(int *)((int)this + 0x398);
          FUN_00424410((uint)*(byte *)(DAT_0043453c + 0x10 + iVar6 * 0x18),iVar3,
                       *(int *)((int)this + 0x20),*(undefined4 *)((int)this + 0x24),
                       *(int *)((int)this + 0x25c) +
                       (((uint)bVar2 + iVar4) * iVar3 * 0x30 + iVar5 + (uint)bVar1) * iVar3,
                       *(int *)((int)this + 0x15c8),local_8);
          *(undefined1 *)((int)this + iVar6 * 2 + 0x3c6) = 0xff;
        }
        iVar6 = iVar6 + 0x30;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 2);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    InvalidateRect(*(HWND *)((int)this + 8),(RECT *)0x0,0);
    UpdateWindow(*(HWND *)((int)this + 8));
  }
  return;
}


