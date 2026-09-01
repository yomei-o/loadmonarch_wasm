/* 00408aa0 */

void __fastcall FUN_00408aa0(int param_1)

{
  HMENU hMnu;
  LONG LVar1;
  UINT UVar2;
  LPCSTR lpNewItem;
  LPCSTR pCVar3;
  uint uVar4;
  int iVar5;
  
  hMnu = GetMenu(*(HWND *)(param_1 + 8));
  if (hMnu != (HMENU)0x0) {
    iVar5 = 0;
    lpNewItem = &DAT_00435b31;
    do {
      UVar2 = iVar5 + 0x9c90;
      pCVar3 = lpNewItem + 0x11;
      iVar5 = iVar5 + 1;
      ModifyMenuA(hMnu,UVar2,0,UVar2,lpNewItem);
      lpNewItem = pCVar3;
    } while (pCVar3 < &DAT_00435b75);
    uVar4 = 0;
    do {
      LVar1 = FUN_0040a0c0(uVar4 + 60000);
      if (LVar1 != 0) {
        UVar2 = GetMenuState(hMnu,uVar4 + 61000,0);
        if (UVar2 == 0xffffffff) {
          InsertMenuA(hMnu,0x9caf,0,uVar4 + 61000,(LPCSTR)(LVar1 + 0x48));
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 10);
  }
  return;
}


