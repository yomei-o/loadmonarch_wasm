/* 0042f2b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __close
   
   Library: Visual Studio 1998 Release */

int __cdecl __close(int _FileHandle)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  HANDLE hObject;
  BOOL BVar5;
  DWORD DVar6;
  
  if (DAT_00438984 <= (uint)_FileHandle) {
    _DAT_00434854 = 9;
    _DAT_00434858 = 0;
    return -1;
  }
  piVar1 = (int *)((int)&DAT_00438990 + ((int)(_FileHandle & 0xffffffe7U) >> 3));
  iVar2 = (_FileHandle & 0x1fU) * 8;
  if ((*(byte *)(*piVar1 + 4 + iVar2) & 1) == 0) {
    _DAT_00434854 = 9;
    _DAT_00434858 = 0;
    return -1;
  }
  if ((_FileHandle == 1) || (_FileHandle == 2)) {
    iVar3 = FUN_0042ebb0(1);
    iVar4 = FUN_0042ebb0(2);
    if (iVar3 != iVar4) goto LAB_0042f30b;
  }
  else {
LAB_0042f30b:
    hObject = (HANDLE)FUN_0042ebb0(_FileHandle);
    BVar5 = CloseHandle(hObject);
    if (BVar5 == 0) {
      DVar6 = GetLastError();
      goto LAB_0042f32b;
    }
  }
  DVar6 = 0;
LAB_0042f32b:
  FUN_0042eb20(_FileHandle);
  if (DVar6 == 0) {
    *(undefined1 *)(*piVar1 + 4 + iVar2) = 0;
    return 0;
  }
  FUN_0042eab0(DVar6);
  return -1;
}


