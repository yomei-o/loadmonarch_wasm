/* 004198e0 */

undefined4 * __fastcall FUN_004198e0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_004199c2;
  *unaff_FS_OFFSET = &local_10;
  FUN_00427770(param_1);
  local_8 = 0;
  *param_1 = &PTR_FUN_00430650;
  wsprintfA((LPSTR)(param_1 + 0x53),s_Code1_00432460);
  wsprintfA((LPSTR)(param_1 + 0x12),s_Progress_Window_00433f54);
  param_1[0x9f] = 0;
  param_1[0x9e] = 0x54400000;
  param_1[8] = 0xb0;
  param_1[9] = 0xb0;
  iVar1 = GetSystemMetrics(8);
  param_1[7] = param_1[7] + iVar1 * 2;
  iVar1 = GetSystemMetrics(7);
  param_1[6] = param_1[6] + iVar1 * 2;
  wsprintfA((LPSTR)(param_1 + 0x12),s_Progress_Window_00433f54);
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = param_1[6] + param_1[8];
  param_1[0x11] = param_1[9] + param_1[7];
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = param_1[6] + param_1[8];
  param_1[0xd] = param_1[9] + param_1[7];
  DAT_004344f4 = param_1;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


