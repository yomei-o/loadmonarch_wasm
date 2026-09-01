/* 0040f1b0 */

void __fastcall FUN_0040f1b0(void *param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  DAT_004376a4 = FUN_0040ed00(param_1,0x42c);
  DAT_004376a5 = FUN_0040ed00(param_1,0x42e);
  DAT_004376a6 = FUN_0040ed00(param_1,0x42b);
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 1;
    uVar1 = FUN_0040ed00(param_1,iVar2 + 0x42f);
    (&DAT_004376a7)[iVar2] = uVar1;
    iVar2 = iVar3;
  } while (iVar3 < 4);
  DAT_004376ad = FUN_0040ed00(param_1,0x459);
  DAT_004376a1 = FUN_0040ed00(param_1,0x45a);
  FUN_0040a800();
  FUN_0040eb70((int)param_1);
  return;
}


