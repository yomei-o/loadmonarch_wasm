/* 00419110 */

void __thiscall FUN_00419110(void *this,WPARAM param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int nIDButton;
  
  SendDlgItemMessageA(*(HWND *)((int)this + 4),0x3fb,0x186,param_1,0);
  if (*(int *)((int)this + param_1 * 8 + 0x22994) != -1) {
    FUN_0040eca0(this,0x46b,0x43250c);
    iVar4 = *(int *)((int)this + param_1 * 8 + 0x22998);
    if (*(char *)((int)this + 0x22588) != '\0') {
      iVar3 = iVar4 * 0x220;
      piVar1 = (int *)(DAT_00435db0 + 0x110 + iVar3);
      if (*(int *)((int)this + 0x22590) < *piVar1) {
        *piVar1 = *(int *)((int)this + 0x22590);
      }
      uVar2 = *(uint *)((int)this + *(int *)(DAT_00435db0 + 0x110 + iVar3) * 4 + 0x22594);
      wsprintfA((LPSTR)((int)this + 0x1c),s__02dmin_02dsec_00433ec8,uVar2 & 0xff,uVar2 >> 8 & 0xff);
      FUN_0040eca0(this,0x471,(LPARAM)((int)this + 0x1c));
    }
    iVar4 = iVar4 * 0x220;
    nIDButton = 0;
    SetDlgItemInt(*(HWND *)((int)this + 4),0x46d,*(UINT *)(DAT_00435db0 + 0x110 + iVar4),0);
    iVar3 = *(int *)(DAT_00435db0 + 0x10c + iVar4);
    if (iVar3 == 0) {
      nIDButton = 0x468;
      CheckDlgButton(*(HWND *)((int)this + 4),0x46a,0);
      FUN_0040eca0(this,0x46b,DAT_00435db0 + iVar4 + 0x114);
    }
    else if (iVar3 == 2) {
      nIDButton = 0x46a;
      CheckDlgButton(*(HWND *)((int)this + 4),0x468,0);
    }
    FUN_0040ed80(this,0x46d,(uint)(*(int *)(DAT_00435db0 + 0x110 + iVar4) != 0));
    CheckDlgButton(*(HWND *)((int)this + 4),nIDButton,1);
  }
  return;
}


