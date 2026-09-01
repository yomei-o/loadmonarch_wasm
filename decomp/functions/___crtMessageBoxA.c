/* 0042d7b0 */

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_004353a4 != (FARPROC)0x0) {
LAB_0042d7ff:
    if (DAT_004353a8 != (FARPROC)0x0) {
      iVar1 = (*DAT_004353a8)();
    }
    if ((iVar1 != 0) && (DAT_004353ac != (FARPROC)0x0)) {
      iVar1 = (*DAT_004353ac)(iVar1);
    }
    iVar1 = (*DAT_004353a4)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA(s_user32_dll_004353e0);
  if (hModule != (HMODULE)0x0) {
    DAT_004353a4 = GetProcAddress(hModule,s_MessageBoxA_004353d4);
    if (DAT_004353a4 != (FARPROC)0x0) {
      DAT_004353a8 = GetProcAddress(hModule,s_GetActiveWindow_004353c4);
      DAT_004353ac = GetProcAddress(hModule,s_GetLastActivePopup_004353b0);
      goto LAB_0042d7ff;
    }
  }
  return 0;
}


