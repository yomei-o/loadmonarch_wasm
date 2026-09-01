/* 0040e0c0 */

undefined4 __fastcall FUN_0040e0c0(int *param_1)

{
  MCIERROR MVar1;
  
  if (*(short *)((int)param_1 + 6) != 0) {
    (**(code **)(*param_1 + 0xc))();
  }
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[4] = (int)s_waveaudio_004326dc;
  param_1[2] = 0;
  MVar1 = mciSendCommandA(0,0x803,0x2202,(DWORD_PTR)(param_1 + 2));
  param_1[0x13] = MVar1;
  if (MVar1 != 0) {
    *(undefined2 *)((int)param_1 + 6) = 0;
    return 0;
  }
  *(short *)((int)param_1 + 6) = (short)param_1[3];
  return 1;
}


