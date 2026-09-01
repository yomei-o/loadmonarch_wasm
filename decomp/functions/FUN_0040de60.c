/* 0040de60 */

undefined4 __fastcall FUN_0040de60(int *param_1)

{
  MCIERROR MVar1;
  undefined4 uVar2;
  
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[2] = 0;
  param_1[4] = (int)s_cdaudio_004326d4;
  MVar1 = mciSendCommandA(0,0x803,0x2002,(DWORD_PTR)(param_1 + 2));
  param_1[0x13] = MVar1;
  if (MVar1 != 0) {
    *(undefined2 *)((int)param_1 + 6) = 0;
    return 0;
  }
  *(short *)((int)param_1 + 6) = (short)param_1[3];
  uVar2 = FUN_0040dfb0(param_1);
  return uVar2;
}


