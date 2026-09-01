/* 00409d50 */

void __cdecl FUN_00409d50(WPARAM param_1,int param_2)

{
  void *this;
  HMENU hMenu;
  
  this = (void *)FUN_0040a0c0(0xea65);
  if (this != (void *)0x0) {
    FUN_0041bef0(this,param_1,param_2);
  }
  hMenu = GetMenu(DAT_004344d4);
  if (hMenu != (HMENU)0x0) {
    CheckMenuItem(hMenu,param_1,-(uint)(param_2 == 1) & 8);
  }
  return;
}


