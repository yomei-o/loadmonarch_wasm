/* 0040c3d0 */

undefined4 FUN_0040c3d0(LPCSTR param_1)

{
  bool bVar1;
  BOOL BVar2;
  undefined3 extraout_var;
  
  do {
    BVar2 = DeleteFileA(param_1);
    if (BVar2 != 0) {
      return 1;
    }
    wsprintfA(&DAT_00435ed0,&DAT_00432510);
    DAT_00434530 = GetLastError();
    bVar1 = FUN_0040c2e0();
  } while (CONCAT31(extraout_var,bVar1) != 0);
  return 0;
}


