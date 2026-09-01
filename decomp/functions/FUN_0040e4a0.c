/* 0040e4a0 */

bool __thiscall FUN_0040e4a0(void *this,undefined4 param_1)

{
  bool bVar1;
  HDC hdc;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  *(undefined4 *)this = param_1;
  hdc = CreateDCA(s_DISPLAY_004326e8,(LPCSTR)0x0,(LPCSTR)0x0,(DEVMODEA *)0x0);
  if (hdc != (HDC)0x0) {
    GetSystemPaletteEntries(hdc,0,0x100,(LPPALETTEENTRY)((int)this + 0xc));
    puVar2 = (undefined1 *)((int)this + 0xe);
    puVar3 = &DAT_00436000;
    do {
      puVar4 = puVar3 + 4;
      *puVar3 = *puVar2;
      puVar3[1] = puVar2[-1];
      puVar3[2] = puVar2[-2];
      puVar3[3] = 0;
      puVar2 = puVar2 + 4;
      puVar3 = puVar4;
    } while (puVar4 < &DAT_00436400);
    DeleteDC(hdc);
  }
  if (*(int *)((int)this + 4) == 0) {
    bVar1 = FUN_0040e530((int)this);
    return bVar1;
  }
  return true;
}


