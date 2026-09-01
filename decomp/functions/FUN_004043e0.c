/* 004043e0 */

void __fastcall FUN_004043e0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00404454;
  *param_1 = &PTR_FUN_00430000;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0;
  DAT_004344ec = 0;
  puVar1 = (undefined4 *)param_1[0x149];
  if (puVar1 != (undefined4 *)0x0) {
    FUN_004279a0(puVar1);
    FUN_00427f80(puVar1);
    param_1[0x149] = 0;
  }
  local_8 = 0xffffffff;
  FUN_0040445e();
  *unaff_FS_OFFSET = local_10;
  return;
}


