/* 0040a5e0 */

void FUN_0040a5e0(void)

{
  POINT Point;
  BOOL BVar1;
  HWND pHVar2;
  LONG LVar3;
  int iVar4;
  tagPOINT local_8;
  
  if (((((DAT_00434524 == 0) && (DAT_00434528 == 0)) && (DAT_0043452c == 0)) &&
      ((DAT_004365d0 != 0 && (DAT_004365d4 != -1)))) && (DAT_004365dc == 0)) {
    if (((DAT_004376ad != '\0') && (BVar1 = GetCursorPos(&local_8), BVar1 != 0)) &&
       ((Point.y = local_8.y, Point.x = local_8.x, pHVar2 = WindowFromPoint(Point),
        pHVar2 != (HWND)0x0 && (LVar3 = FUN_0040a0c0(60000), *(HWND *)(LVar3 + 8) == pHVar2)))) {
      return;
    }
    DAT_0043781c = 4;
    DAT_00435b1c = DAT_00435b1c + 1;
    FUN_0041d740();
    FUN_004204f0();
    FUN_0040b270();
    FUN_0041b370();
    FUN_0041b4f0();
    if (DAT_004344e8 != (int *)0x0) {
      (**(code **)(*DAT_004344e8 + 100))();
    }
    FUN_0040a110();
    FUN_0041f790();
    FUN_0041f090();
    iVar4 = FUN_0041f4c0();
    if (iVar4 == 1) {
      FUN_0040cd20(&DAT_00435db0,DAT_00434514 + 2,0);
    }
    FUN_0040a6f0();
  }
  return;
}


