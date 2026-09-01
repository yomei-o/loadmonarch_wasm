/* 00419610 */

void __fastcall FUN_00419610(void *param_1)

{
  int iVar1;
  WPARAM WVar2;
  
  wsprintfA((LPSTR)((int)param_1 + 900),s___wav_00433f4c);
  *(char **)((int)param_1 + 0x244) = s_WAVE_FILE_00433f38;
  *(undefined4 *)((int)param_1 + 0x248) = 0;
  *(char **)((int)param_1 + 0x268) = s_Choose_a_WAVE_file__00433f24;
  *(undefined **)((int)param_1 + 0x274) = &DAT_00433f20;
  iVar1 = FUN_004196b0((int)param_1);
  if (iVar1 == 1) {
    WVar2 = FUN_0040ec30(param_1,0x3fc);
    if ((WVar2 != 0xffffffff) && (*(int *)((int)param_1 + WVar2 * 8 + 0x23194) != -1)) {
      wsprintfA((LPSTR)(*(int *)((int)param_1 + WVar2 * 8 + 0x23198) * 0x220 + DAT_00435db0 + 0x114)
                ,(LPSTR)((int)param_1 + 900));
      FUN_00419290(param_1,WVar2);
    }
  }
  return;
}


