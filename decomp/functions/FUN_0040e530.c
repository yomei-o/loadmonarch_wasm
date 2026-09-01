/* 0040e530 */

bool __fastcall FUN_0040e530(int param_1)

{
  HPALETTE pHVar1;
  
  ((LOGPALETTE *)(param_1 + 8))->palVersion = 0x300;
  *(undefined2 *)(param_1 + 10) = 0x100;
  pHVar1 = CreatePalette((LOGPALETTE *)(param_1 + 8));
  *(HPALETTE *)(param_1 + 4) = pHVar1;
  return (bool)('\x01' - (pHVar1 == (HPALETTE)0x0));
}


