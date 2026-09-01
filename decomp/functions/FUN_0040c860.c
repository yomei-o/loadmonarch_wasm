/* 0040c860 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_0040c860(int param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040c8e8;
  *unaff_FS_OFFSET = &local_10;
  FUN_00425bd0((undefined4 *)(param_1 + 4));
  DAT_004358d8 = 0;
  DAT_004358dc = 0;
  DAT_004358e0 = 0;
  DAT_004358c8 = 0;
  DAT_004358cc = 0;
  DAT_004358d0 = 0;
  _DAT_004358a8 = 0xffffffff;
  _DAT_004358ac = 0xffffffff;
  _DAT_004358b0 = 0xffffffff;
  _DAT_004358b4 = 0xffffffff;
  _DAT_004358b8 = 0xffffffff;
  _DAT_004358bc = 0xffffffff;
  _DAT_004358c0 = 0xffffffff;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


