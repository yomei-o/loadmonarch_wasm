/* 004187f0 */

void __fastcall FUN_004187f0(void *param_1)

{
  undefined1 extraout_AL;
  UINT UVar1;
  
  DAT_0043769e = FUN_0040ed00(param_1,0x441);
  DAT_0043769f = FUN_0040ed00(param_1,0x442);
  UVar1 = IsDlgButtonChecked(*(HWND *)((int)param_1 + 4),0x497);
  DAT_004376a0 = (char)UVar1;
  UVar1 = IsDlgButtonChecked(*(HWND *)((int)param_1 + 4),0x4a6);
  extraout_AL = (undefined1)UVar1;
  DAT_004376b4 = extraout_AL;
  if (DAT_0043769e == '\0') {
    FUN_0040ccf0(0);
  }
  else if (*(int *)((int)param_1 + 0x22338) != -1) {
    FUN_0040cd20(&DAT_00435db0,*(int *)((int)param_1 + 0x22338),0);
  }
  if (DAT_0043769f == '\0') {
    FUN_0040ccf0(1);
  }
  FUN_0040d490(&DAT_00435db0,3,&DAT_00435dcc);
  FUN_0040eb70((int)param_1);
  return;
}


