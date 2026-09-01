/* 00419570 */

void __fastcall FUN_00419570(void *param_1)

{
  int iVar1;
  WPARAM WVar2;
  
  wsprintfA((LPSTR)((int)param_1 + 900),s___mid___smf_00433f14);
  *(undefined4 *)((int)param_1 + 0x248) = 0;
  *(char **)((int)param_1 + 0x244) = s_MIDI_FILE_00433ef8;
  *(char **)((int)param_1 + 0x268) = s_Choose_a_MIDI_file__00433ee4;
  *(undefined4 *)((int)param_1 + 0x274) = 0;
  iVar1 = FUN_004196b0((int)param_1);
  if (iVar1 == 1) {
    WVar2 = FUN_0040ec30(param_1,0x3fb);
    if ((WVar2 != 0xffffffff) && (*(int *)((int)param_1 + WVar2 * 8 + 0x22994) != -1)) {
      wsprintfA((LPSTR)(*(int *)((int)param_1 + WVar2 * 8 + 0x22998) * 0x220 + DAT_00435db0 + 0x114)
                ,(LPSTR)((int)param_1 + 900));
      FUN_00419110(param_1,WVar2);
    }
  }
  return;
}


