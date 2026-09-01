/* 0040c430 */

undefined4 * __fastcall FUN_0040c430(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040c4dd;
  *unaff_FS_OFFSET = &local_10;
  FUN_004250d0(param_1);
  local_8 = 0;
  *param_1 = &PTR_FUN_00430168;
  wsprintfA((LPSTR)(param_1 + 0xa0),s_DS795_WND_0043255c);
  wsprintfA((LPSTR)(param_1 + 0x53),s_Title_00432554);
  wsprintfA((LPSTR)(param_1 + 0x12),s_Falcom_Co__00432548);
  param_1[0x9f] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0x9e] = 0x14000000;
  param_1[8] = 0x100;
  param_1[9] = 0xc0;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


