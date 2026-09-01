/* 00408240 */

undefined4 __fastcall FUN_00408240(int param_1)

{
  bool bVar1;
  MMRESULT MVar2;
  undefined3 extraout_var;
  
  MVar2 = timeSetEvent(0x10,0x10,&LAB_0040a5c0,0,1);
  *(MMRESULT *)(param_1 + 0x398) = MVar2;
  if (MVar2 == 0) {
    return 0;
  }
  bVar1 = FUN_004087e0(param_1);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    return 0;
  }
  DAT_004344e0 = 0;
  return 1;
}


