/* 0040fb20 */

void __fastcall FUN_0040fb20(int *param_1)

{
  int iVar1;
  
  FUN_00408e20();
  FUN_0040f510(param_1);
  iVar1 = FUN_00405900((int)(param_1 + 0x48));
  if (iVar1 == 0) {
    FUN_00409370(s_Failed_in_reading_file__004335e8,0);
    return;
  }
  DAT_0043451c = 0;
  FUN_00405330();
  FUN_00427210();
  FUN_0041b370();
  (**(code **)(*param_1 + 0x38))();
  return;
}


