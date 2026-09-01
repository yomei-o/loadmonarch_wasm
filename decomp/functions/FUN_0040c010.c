/* 0040c010 */

undefined4 FUN_0040c010(LPCSTR param_1,LPVOID param_2,DWORD param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined3 extraout_var_00;
  undefined4 uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined2 local_230 [272];
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040c0b7;
  *unaff_FS_OFFSET = &local_10;
  FUN_0041f8b0((int)local_230);
  local_8 = 0;
  do {
    bVar1 = FUN_0041f9f0(local_230,param_1);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      iVar2 = FUN_0041fa80(local_230,param_2,param_3,0);
      if (iVar2 != 0) {
        local_8 = 0xffffffff;
        FUN_0040c0c1();
        uVar3 = 1;
        goto LAB_0040c091;
      }
      FUN_0041fa40(local_230);
    }
    bVar1 = FUN_0040c2e0();
  } while (CONCAT31(extraout_var_00,bVar1) != 0);
  local_8 = 0xffffffff;
  FUN_0040c0c1();
  uVar3 = 0;
LAB_0040c091:
  *unaff_FS_OFFSET = local_10;
  return uVar3;
}


