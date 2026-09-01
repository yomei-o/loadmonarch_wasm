/* 00424520 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00424520(void *this,uint param_1)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  local_c = *(undefined4 *)((int)this + 0x260);
  local_8 = *(undefined4 *)((int)this + 0x264);
  iVar1 = param_1 * 0x38 + DAT_00434534;
  FUN_00423f90(this,(uint)*(byte *)(iVar1 + 8),(uint)*(byte *)(iVar1 + 9),(undefined4 *)0x0,0);
  FUN_004095d0(0x7a,param_1 << 0x10,*(HWND *)(DAT_004344e4 + 8));
  FUN_00424620(this,(ushort *)&local_c);
  if ((DAT_004365cd != param_1) && (DAT_00437570 == 0)) {
    iVar1 = FUN_0041abd0(5);
    local_c = 0x17000f;
    DAT_00437570 = 0xcc;
    local_8 = 0x2f002f;
    local_4 = 0x2f;
    local_3 = 0x17;
    DAT_0043757c = 1;
    DAT_0043757d = 7;
    local_2 = 0x2f;
    local_1 = 0xf;
    DAT_00437574 = (int)*(char *)((int)&local_c + iVar1 * 2);
    _DAT_00437578 = (int)*(char *)((int)&local_c + iVar1 * 2 + 1);
  }
  return;
}


