/* 0040dbf0 */

undefined4 __fastcall FUN_0040dbf0(int *param_1)

{
  MCIERROR MVar1;
  
  if (*(short *)((int)param_1 + 6) != 0) {
    (**(code **)(*param_1 + 0xc))();
  }
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[4] = (int)s_sequencer_004326c8;
  param_1[2] = 0;
  MVar1 = mciSendCommandA(0,0x803,0x2202,(DWORD_PTR)(param_1 + 2));
  param_1[0x13] = MVar1;
  if (MVar1 != 0) {
    (**(code **)(*param_1 + 0xc))();
    return 0;
  }
  *(short *)((int)param_1 + 6) = (short)param_1[3];
  return 1;
}


