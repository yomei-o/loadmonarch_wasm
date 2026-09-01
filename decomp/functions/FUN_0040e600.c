/* 0040e600 */

undefined4 __fastcall FUN_0040e600(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  if (*(int *)(param_1 + 4) == 0) {
    bVar1 = FUN_0040e530(param_1);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      return 0;
    }
  }
  SetPaletteEntries(*(HPALETTE *)(param_1 + 4),0,0x100,(PALETTEENTRY *)(param_1 + 0xc));
  return 1;
}


