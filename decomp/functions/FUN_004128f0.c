/* 004128f0 */

void __fastcall FUN_004128f0(void *param_1)

{
  LPSTR _Dest;
  int iVar1;
  HWND hWnd;
  char *lpString;
  
  iVar1 = FUN_0040ec30(param_1,0x3ea);
  if (iVar1 != -1) {
    hWnd = GetDlgItem(*(HWND *)((int)param_1 + 4),0x40f);
    lpString = FUN_0041a650(&DAT_004376c8,iVar1);
    _Dest = (LPSTR)((int)param_1 + 0x1c);
    SetWindowTextA(hWnd,lpString);
    wsprintfA(_Dest,&DAT_00432100);
    FUN_0040ed20(param_1,0x45d,_Dest);
    if (DAT_004376cc - DAT_00436a00 == 1) {
      wsprintfA(_Dest,s_Overall_004339d4);
    }
    else {
      wsprintfA(_Dest,s__d_Map_s__004339c8);
    }
    FUN_0040ed20(param_1,0x41b,_Dest);
    if ((DAT_004376cc - DAT_00436a00 != 1) && (DAT_00436a00 == iVar1)) {
      FUN_0040ed20(param_1,0x45e,&DAT_004339c0);
      FUN_0040ed20(param_1,0x45b,&DAT_004339c0);
      FUN_0040ed20(param_1,0x45c,&DAT_004339bc);
      FUN_0040ed20(param_1,0x49c,&DAT_004339bc);
      FUN_0040ed20(param_1,0x49d,&DAT_004339bc);
      FUN_0040ed20(param_1,0x49e,&DAT_004339bc);
      FUN_0040ed20(param_1,0x4a2,&DAT_004339bc);
      FUN_0040ed20(param_1,0x4a0,&DAT_004339bc);
      FUN_0040ed20(param_1,0x49f,&DAT_004339bc);
      FUN_0040ed20(param_1,0x4a1,&DAT_004339bc);
      FUN_0040ed20(param_1,0x4a3,&DAT_004339bc);
      return;
    }
    wsprintfA(_Dest,s__d_days_004339b4);
    FUN_0040ed20(param_1,0x45b,_Dest);
    wsprintfA(_Dest,s__d_days_004339b4);
    FUN_0040ed20(param_1,0x45e,_Dest);
    wsprintfA(_Dest,s__d_days_004339b4);
    FUN_0040ed20(param_1,0x45c,_Dest);
    wsprintfA(_Dest,&DAT_00432608);
    FUN_0040ed20(param_1,0x49c,_Dest);
    wsprintfA(_Dest,&DAT_00432608);
    FUN_0040ed20(param_1,0x49d,_Dest);
    _sprintf(_Dest,s__3_2f_004339ac,(double)(float)(&DAT_00436a10)[iVar1 * 0xe]);
    FUN_0040ed20(param_1,0x49e,_Dest);
    wsprintfA(_Dest,s____d_days_004339a0);
    FUN_0040ed20(param_1,0x4a2,_Dest);
    wsprintfA(_Dest,s__d_p__00433998);
    FUN_0040ed20(param_1,0x4a0,_Dest);
    wsprintfA(_Dest,s__d_p__00433998);
    FUN_0040ed20(param_1,0x49f,_Dest);
    _sprintf(_Dest,s__3_2f_004339ac,(double)*(float *)(&DAT_00436a14 + iVar1 * 0x38));
    FUN_0040ed20(param_1,0x4a1,_Dest);
    wsprintfA(_Dest,s____d_days_0043398c);
    FUN_0040ed20(param_1,0x4a3,_Dest);
  }
  return;
}


