/* 00408b80 */

void FUN_00408b80(void)

{
  int iVar1;
  HCURSOR pHVar2;
  HANDLE pvVar3;
  BOOL BVar4;
  code *pcVar5;
  undefined4 *puVar6;
  CHAR local_348 [260];
  _WIN32_FIND_DATAA local_244;
  CHAR local_104 [260];
  
  iVar1 = FUN_00409370(s_High_Scores_will_be_cleared_and_t_00432284,4);
  if (iVar1 == 6) {
    pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
    SetCursor(pHVar2);
    puVar6 = &DAT_00436a00;
    for (iVar1 = 0x2da; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    FUN_0040bda0(&DAT_00436468,local_348,s___ds7_0043227c);
    pvVar3 = FindFirstFileA(local_348,&local_244);
    pcVar5 = FindClose_exref;
    if (pvVar3 != (HANDLE)0xffffffff) {
      do {
        FUN_0040bda0(&DAT_00436468,local_348,local_244.cFileName);
        iVar1 = FUN_0040c3d0(local_348);
        if (iVar1 == 0) {
          FindClose(pvVar3);
          return;
        }
        BVar4 = FindNextFileA(pvVar3,&local_244);
        pcVar5 = FindClose_exref;
      } while (BVar4 != 0);
      FindClose(pvVar3);
    }
    FUN_0040bda0(&DAT_00436468,local_348,s___dat_00432274);
    pvVar3 = FindFirstFileA(local_348,&local_244);
    if (pvVar3 != (HANDLE)0xffffffff) {
      do {
        FUN_0040bda0(&DAT_00436468,local_348,local_244.cFileName);
        iVar1 = FUN_0040c3d0(local_348);
        if (iVar1 == 0) {
          (*pcVar5)(pvVar3);
          return;
        }
        BVar4 = FindNextFileA(pvVar3,&local_244);
      } while (BVar4 != 0);
      (*pcVar5)(pvVar3);
    }
    FUN_00405790(s_Score_v11_0043210c,local_104);
    FUN_0040bda0(&DAT_00436468,local_348,local_104);
    FUN_0040c3d0(local_348);
    DAT_004376b5 = 0;
    pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    SetCursor(pHVar2);
    DAT_00434510 = 0xffffffff;
    DAT_004365cc = 1;
    FUN_00405de0(0);
  }
  return;
}


