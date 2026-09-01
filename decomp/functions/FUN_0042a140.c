/* 0042a140 */

undefined4 FUN_0042a140(void)

{
  undefined1 uVar1;
  undefined3 extraout_var;
  HMODULE hModule;
  FARPROC pFVar2;
  FARPROC pFVar3;
  FARPROC pFVar4;
  FARPROC pFVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined3 extraout_var_00;
  uint unaff_EDI;
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  uVar1 = __ms_p5_test_fdiv();
  if (CONCAT31(extraout_var,uVar1) != 0) {
    return 1;
  }
  hModule = LoadLibraryA(s_KERNEL32_004347f8);
  if (hModule == (HMODULE)0x0) {
    return 0;
  }
  pFVar2 = GetProcAddress(hModule,s_GetProcessAffinityMask_004347e0);
  if (pFVar2 == (FARPROC)0x0) {
    return 0;
  }
  pFVar3 = GetProcAddress(hModule,s_GetCurrentProcess_004347cc);
  if (pFVar3 == (FARPROC)0x0) {
    return 0;
  }
  pFVar4 = GetProcAddress(hModule,s_SetThreadAffinityMask_004347b4);
  if (pFVar4 == (FARPROC)0x0) {
    return 0;
  }
  pFVar5 = GetProcAddress(hModule,s_GetCurrentThread_004347a0);
  if (pFVar5 == (FARPROC)0x0) {
    return 0;
  }
  iVar6 = (*pFVar3)();
  iVar6 = (*pFVar2)(iVar6,auStack_4,auStack_8);
  if (iVar6 == 0) {
    return 0;
  }
  iVar6 = 0;
  do {
    uVar7 = 1 << ((byte)iVar6 & 0x1f);
    if ((unaff_EDI & uVar7) != 0) {
      iVar8 = (*pFVar5)(uVar7);
      (*pFVar4)(iVar8);
      uVar1 = __ms_p5_test_fdiv();
      if (CONCAT31(extraout_var_00,uVar1) != 0) {
        iVar6 = (*pFVar5)(unaff_EDI);
        (*pFVar4)(iVar6);
        return 1;
      }
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x20);
  iVar6 = (*pFVar5)(unaff_EDI);
  (*pFVar4)(iVar6);
  return 0;
}


