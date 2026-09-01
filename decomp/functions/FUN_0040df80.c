/* 0040df80 */

void __fastcall FUN_0040df80(int param_1)

{
  MCIERROR MVar1;
  
  if (*(ushort *)(param_1 + 6) != 0) {
    MVar1 = mciSendCommandA((uint)*(ushort *)(param_1 + 6),0x808,2,0);
    *(MCIERROR *)(param_1 + 0x4c) = MVar1;
  }
  return;
}


