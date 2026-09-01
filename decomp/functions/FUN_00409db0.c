/* 00409db0 */

void __cdecl FUN_00409db0(WPARAM param_1,int param_2)

{
  void *this;
  HMENU hMenu;
  
  this = (void *)FUN_0040a0c0(0xea65);
  if (this != (void *)0x0) {
    FUN_0041bf10(this,param_1,param_2);
  }
  if ((DAT_004344e4 != 0) && (hMenu = GetMenu(*(HWND *)(DAT_004344e4 + 8)), hMenu != (HMENU)0x0)) {
    EnableMenuItem(hMenu,param_1,(uint)(param_2 != 1));
  }
  return;
}


