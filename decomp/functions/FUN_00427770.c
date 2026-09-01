/* 00427770 */

undefined4 * __fastcall FUN_00427770(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_004277e4;
  *unaff_FS_OFFSET = &local_10;
  FUN_004250d0(param_1);
  local_8 = 0;
  *param_1 = &PTR_FUN_00430910;
  wsprintfA((LPSTR)(param_1 + 0xa0),s_DS795_WND_0043255c);
  param_1[0x9f] = 0x80;
  param_1[0x9e] = 0x54c80000;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


