/* 00412780 */

void __fastcall FUN_00412780(void *param_1)

{
  LPSTR _Dest;
  int iVar1;
  char *pcVar2;
  WPARAM wParam;
  int iVar3;
  
  SendDlgItemMessageA(*(HWND *)((int)param_1 + 4),0x3ea,0x184,0,0);
  if (-1 < DAT_00436a00) {
    _Dest = (LPSTR)((int)param_1 + 0x1c);
    iVar3 = 0;
    do {
      iVar1 = iVar3 + 1;
      pcVar2 = FUN_0041a620(&DAT_004376c8,iVar3);
      FUN_00409490(_Dest,&DAT_00432120,pcVar2);
      pcVar2 = FUN_0041a650(&DAT_004376c8,iVar3);
      _sprintf(_Dest,s_Map_3d____s_00433980,iVar1,pcVar2);
      SendDlgItemMessageA(*(HWND *)((int)param_1 + 4),0x3ea,0x180,0,(LPARAM)_Dest);
      iVar3 = iVar1;
    } while (iVar1 <= DAT_00436a00);
  }
  wParam = 0;
  if (DAT_00434510 != 0xffffffff) {
    wParam = DAT_00434510;
  }
  SendDlgItemMessageA(*(HWND *)((int)param_1 + 4),0x3ea,0x186,wParam,0);
  FUN_004128f0(param_1);
  return;
}


