/* 0041b700 */

undefined4 * __fastcall FUN_0041b700(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar3;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041b86a;
  *unaff_FS_OFFSET = &local_10;
  FUN_00427770(param_1);
  local_8 = 0;
  *param_1 = &PTR_FUN_004306e0;
  param_1[0xe6] = (uint)DAT_004376a3;
  param_1[0xe7] = DAT_004376b0;
  wsprintfA((LPSTR)(param_1 + 0x12),s_Tool_Bar_00433fa8);
  param_1[0xe5] = 0;
  if (param_1[0xe6] == 0) {
    param_1[7] = 2;
    iVar1 = GetSystemMetrics(0x20);
    iVar2 = GetSystemMetrics(0);
    param_1[6] = iVar1 * 2 + iVar2;
    iVar1 = GetSystemMetrics(0);
    param_1[8] = iVar1;
    iVar1 = GetSystemMetrics(1);
    param_1[9] = iVar1;
    param_1[10] = 0;
    param_1[0xb] = 0;
    iVar1 = GetSystemMetrics(0);
    pcVar3 = s_Code5_00432448;
    param_1[0xc] = iVar1;
    param_1[0xd] = 0x1c;
    param_1[0x9e] = 0x54000000;
    param_1[0x9f] = 0;
  }
  else {
    iVar1 = GetSystemMetrics(0x21);
    iVar2 = GetSystemMetrics(0x33);
    param_1[7] = iVar1 * 2 + iVar2;
    iVar1 = GetSystemMetrics(0x20);
    param_1[6] = iVar1 * 2;
    iVar1 = GetSystemMetrics(0);
    param_1[8] = iVar1;
    iVar1 = GetSystemMetrics(1);
    param_1[9] = iVar1;
    param_1[10] = 0;
    param_1[0xb] = 0;
    iVar1 = GetSystemMetrics(0);
    pcVar3 = s_Code4_00432450;
    param_1[0xc] = iVar1;
    param_1[0x9e] = 0x54c40000;
    param_1[0x9f] = 0x80;
    param_1[0xd] = param_1[7] + 0x1c;
  }
  wsprintfA((LPSTR)(param_1 + 0x53),pcVar3);
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


