/* 0040c0d0 */

undefined4 FUN_0040c0d0(LPCSTR param_1,LPCVOID param_2,DWORD param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  BOOL BVar3;
  undefined3 extraout_var_01;
  undefined4 uVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined2 local_234 [272];
  void *local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040c1a5;
  *unaff_FS_OFFSET = &local_10;
  FUN_0041f8b0((int)local_234);
  local_8 = 0;
  do {
    iVar2 = FUN_0040c1c0(local_14);
    if (iVar2 != 0) break;
    bVar1 = FUN_0040c2e0();
  } while (CONCAT31(extraout_var,bVar1) != 0);
  do {
    bVar1 = FUN_0041f9a0(local_234,param_1);
    if (CONCAT31(extraout_var_00,bVar1) != 0) {
      BVar3 = FUN_0041fc10(local_234,param_2,param_3);
      if (BVar3 != 0) {
        local_8 = 0xffffffff;
        FUN_0040c1af();
        uVar4 = 1;
        goto LAB_0040c17f;
      }
      FUN_0041fa40(local_234);
    }
    if (DAT_00434530 == 0x70) {
      FUN_0040c3d0(param_1);
    }
    bVar1 = FUN_0040c2e0();
  } while (CONCAT31(extraout_var_01,bVar1) != 0);
  local_8 = 0xffffffff;
  FUN_0040c1af();
  uVar4 = 0;
LAB_0040c17f:
  *unaff_FS_OFFSET = local_10;
  return uVar4;
}


