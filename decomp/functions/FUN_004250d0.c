/* 004250d0 */

undefined4 * __fastcall FUN_004250d0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &PTR_FUN_00430830;
  param_1[0x94] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  iVar1 = GetSystemMetrics(0);
  param_1[8] = iVar1;
  iVar1 = GetSystemMetrics(1);
  param_1[9] = iVar1;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x95] = 0;
  param_1[0x96] = 0;
  param_1[0x97] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[0x9a] = 0xffffffff;
  param_1[0x9b] = 0xffffffff;
  *(undefined1 *)(param_1 + 0xe1) = 0;
  param_1[0xe2] = 0xc0;
  param_1[0xe3] = 0xc0;
  return param_1;
}


