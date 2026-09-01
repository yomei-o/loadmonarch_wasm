/* 00408200 */

void __fastcall FUN_00408200(int param_1)

{
  int iVar1;
  LONG LVar2;
  
  iVar1 = FUN_004094c0();
  if (iVar1 != 0) {
    FUN_00408290(param_1);
    LVar2 = FUN_0040a0c0(0xea65);
    DAT_004376a2 = '\x01' - (LVar2 == 0);
    FUN_004093b0();
    FUN_004057d0();
    FUN_00425af0(param_1);
  }
  return;
}


