/* 004292c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  byte bVar1;
  DWORD DVar2;
  HMODULE pHVar3;
  UINT UVar4;
  byte *pbVar5;
  undefined4 *unaff_FS_OFFSET;
  int iVar6;
  _STARTUPINFOA local_74;
  undefined1 *local_1c;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &DAT_004309b0;
  puStack_10 = &LAB_0042b3d8;
  *unaff_FS_OFFSET = &local_14;
  local_1c = &stack0xffffff80;
  DVar2 = GetVersion();
  _DAT_0043486c = DVar2 >> 8 & 0xff;
  DAT_00434860 = DVar2 >> 0x10;
  _DAT_00434868 = DVar2 & 0xff;
  _DAT_00434864 = _DAT_00434868 * 0x100 + _DAT_0043486c;
  FUN_0042c280();
  local_8 = 0;
  FUN_0042c0a0();
  FUN_0042b9a0();
  DAT_00438a98 = (byte *)GetCommandLineA();
  DAT_00434770 = FUN_0042bf00();
  if ((DAT_00434770 == (LPSTR)0x0) || (DAT_00438a98 == (byte *)0x0)) {
    FUN_0042b4e0(0xffffffff);
  }
  __setargv();
  FUN_0042bba0();
  FUN_0042b4b0();
  bVar1 = *DAT_00438a98;
  pbVar5 = DAT_00438a98;
  if (bVar1 == 0x22) {
    pbVar5 = DAT_00438a98 + 1;
    if (*pbVar5 != 0x22) {
      do {
        if (*pbVar5 == 0) break;
        iVar6 = __ismbblead((uint)*pbVar5);
        if (iVar6 != 0) {
          pbVar5 = pbVar5 + 1;
        }
        pbVar5 = pbVar5 + 1;
      } while (*pbVar5 != 0x22);
      if (*pbVar5 != 0x22) goto LAB_004293b7;
    }
    pbVar5 = pbVar5 + 1;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar5[1];
      pbVar5 = pbVar5 + 1;
    }
  }
LAB_004293b7:
  bVar1 = *pbVar5;
  while ((bVar1 != 0 && (*pbVar5 < 0x21))) {
    pbVar5 = pbVar5 + 1;
    bVar1 = *pbVar5;
  }
  local_74.dwFlags = 0;
  GetStartupInfoA(&local_74);
  iVar6 = 0;
  pHVar3 = GetModuleHandleA((LPCSTR)0x0);
  UVar4 = FUN_00426370(pHVar3,iVar6);
  FUN_0042b4e0(UVar4);
  *unaff_FS_OFFSET = local_14;
  return;
}


