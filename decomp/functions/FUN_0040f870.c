/* 0040f870 */

void __fastcall FUN_0040f870(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined2 local_230 [272];
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040f948;
  *unaff_FS_OFFSET = &local_10;
  FUN_0041f8b0((int)local_230);
  local_8 = 0;
  FUN_0040bda0(&DAT_00436468,(LPSTR)(param_1 + 7),param_1 + 0x48);
  bVar1 = FUN_0041f9f0(local_230,(LPCSTR)(param_1 + 7));
  FUN_0041fa40(local_230);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iVar2 = FUN_00409370(s_Overwrite_saved_game__0043359c,4);
    if (iVar2 == 7) goto LAB_0040f8eb;
  }
  FUN_0040ed80(param_1,0x3fc,0);
  FUN_0040ed80(param_1,0x3fb,0);
  iVar2 = FUN_00405b90((int)(param_1 + 0x48));
  if (iVar2 == 0) {
    FUN_00409370(s_Failed_in_writting_file__00433580,0);
  }
  (**(code **)(*param_1 + 0x38))();
LAB_0040f8eb:
  local_8 = 0xffffffff;
  FUN_0040f952();
  *unaff_FS_OFFSET = local_10;
  return;
}


