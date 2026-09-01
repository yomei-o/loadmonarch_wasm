/* 0040f960 */

void __fastcall FUN_0040f960(void *param_1)

{
  LPSTR lpFileName;
  int iVar1;
  int iVar2;
  BOOL BVar3;
  
  iVar1 = (int)param_1 + 0x120;
  lpFileName = (LPSTR)((int)param_1 + 0x1c);
  FUN_0040f510(param_1);
  wsprintfA(lpFileName,s_Delete___s__004335dc,iVar1);
  iVar2 = FUN_00409370(lpFileName,4);
  if (iVar2 == 6) {
    FUN_0040bda0(&DAT_00436468,lpFileName,iVar1);
    BVar3 = DeleteFileA(lpFileName);
    if (BVar3 == 0) {
      wsprintfA(lpFileName,s_Failed_in_deleating_filename_the_004335b4,iVar1);
      FUN_00409370(lpFileName,0);
    }
    FUN_0040ed80(param_1,0x3fc,0);
    FUN_0040ed80(param_1,0x3fb,0);
    FUN_0040f370(param_1,0x3f7);
  }
  return;
}


