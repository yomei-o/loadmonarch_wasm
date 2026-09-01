/* 0042d3c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

DWORD __cdecl FUN_0042d3c0(uint param_1,LONG param_2,DWORD param_3)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  HANDLE hFile;
  DWORD DVar4;
  uint uVar5;
  
  if (param_1 < DAT_00438984) {
    piVar1 = (int *)((int)&DAT_00438990 + ((int)(param_1 & 0xffffffe7) >> 3));
    iVar2 = (param_1 & 0x1f) * 8;
    if ((*(byte *)(*piVar1 + 4 + iVar2) & 1) != 0) {
      hFile = (HANDLE)FUN_0042ebb0(param_1);
      if (hFile == (HANDLE)0xffffffff) {
        _DAT_00434854 = 9;
        return 0xffffffff;
      }
      DVar4 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);
      uVar5 = 0;
      if (DVar4 == 0xffffffff) {
        uVar5 = GetLastError();
      }
      if (uVar5 != 0) {
        FUN_0042eab0(uVar5);
        return 0xffffffff;
      }
      pbVar3 = (byte *)(*piVar1 + 4 + iVar2);
      *pbVar3 = *pbVar3 & 0xfd;
      return DVar4;
    }
  }
  _DAT_00434854 = 9;
  _DAT_00434858 = 0;
  return 0xffffffff;
}


