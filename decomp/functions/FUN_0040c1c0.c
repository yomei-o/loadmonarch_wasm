/* 0040c1c0 */

undefined4 __fastcall FUN_0040c1c0(void *param_1)

{
  bool bVar1;
  int iVar2;
  HANDLE hFindFile;
  BOOL BVar3;
  undefined3 extraout_var;
  _SECURITY_ATTRIBUTES local_354;
  undefined2 local_348;
  undefined1 local_346;
  undefined1 local_345;
  undefined2 local_244;
  undefined1 local_242;
  _WIN32_FIND_DATAA local_140;
  
  iVar2 = FUN_0040bda0(param_1,(LPSTR)&local_244,&DAT_0043250c);
  if (iVar2 == 0) {
    return 0;
  }
  if (*(int *)((int)param_1 + 0x130) == 5) {
    local_348 = local_244;
    local_346 = local_242;
    local_345 = 0;
  }
  else {
    lstrcpyA((LPSTR)&local_348,&DAT_00437588);
  }
  lstrcatA((LPSTR)&local_348,&DAT_00432504);
  hFindFile = FindFirstFileA((LPCSTR)&local_348,&local_140);
  if (hFindFile == (HANDLE)0xffffffff) {
    local_354.nLength = 0;
    do {
      BVar3 = CreateDirectoryA((LPCSTR)&local_348,&local_354);
      if (BVar3 != 0) {
        return 1;
      }
      DAT_00434530 = GetLastError();
      bVar1 = FUN_0040c2e0();
    } while (CONCAT31(extraout_var,bVar1) != 0);
    return 0;
  }
  FindClose(hFindFile);
  if (local_140.dwFileAttributes != 0x10) {
    DeleteFileA((LPCSTR)&local_244);
    DAT_00434530 = GetLastError();
    return 0;
  }
  return 1;
}


