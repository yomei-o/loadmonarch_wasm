/* 0042f200 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0042f200(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  undefined4 uVar3;
  
  if ((param_1 < DAT_00438984) &&
     ((*(byte *)(*(int *)((int)&DAT_00438990 + ((int)(param_1 & 0xffffffe7) >> 3)) + 4 +
                (param_1 & 0x1f) * 8) & 1) != 0)) {
    hFile = (HANDLE)FUN_0042ebb0(param_1);
    BVar1 = FlushFileBuffers(hFile);
    DVar2 = 0;
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    uVar3 = 0;
    if (DVar2 != 0) {
      _DAT_00434854 = 9;
      _DAT_00434858 = DVar2;
      return 0xffffffff;
    }
  }
  else {
    _DAT_00434854 = 9;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


