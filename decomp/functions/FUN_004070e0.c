/* 004070e0 */

undefined4 * __fastcall FUN_004070e0(undefined4 *param_1)

{
  int iVar1;
  HFONT pHVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040720b;
  *unaff_FS_OFFSET = &local_10;
  FUN_00427770(param_1);
  local_8 = 0;
  *param_1 = &PTR_FUN_00430078;
  wsprintfA((LPSTR)(param_1 + 0x53),s_Code7_00432210);
  wsprintfA((LPSTR)(param_1 + 0x12),s_Frame_Window_00432200);
  wsprintfA((LPSTR)(param_1 + 0xa0),s_DS795_FRAME_004321f4);
  param_1[0x9f] = 0x100;
  param_1[0x9e] = 0xcf0000;
  iVar1 = GetSystemMetrics(0x20);
  param_1[6] = iVar1 * 2;
  iVar1 = GetSystemMetrics(0x21);
  param_1[7] = iVar1 * 2;
  iVar1 = GetSystemMetrics(4);
  param_1[7] = param_1[7] + iVar1;
  param_1[10] = 0;
  param_1[0xb] = 0;
  iVar1 = GetSystemMetrics(0);
  param_1[0xc] = iVar1;
  iVar1 = GetSystemMetrics(1);
  param_1[0xd] = iVar1;
  param_1[0xe6] = 0;
  param_1[0xe7] = 0;
  param_1[0xe5] = 0;
  pHVar2 = CreateFontA(10,0,0,0,400,0,0,0,0x80,3,0,2,0x11,s_MS_Sans_Serif_004321e4);
  param_1[0xe8] = pHVar2;
  pHVar2 = CreateFontA(0xf,0,0,0,600,0,0,0,0xff,0,0,0,1,s_MS_Sans_Serif_004321e4);
  param_1[0xe9] = pHVar2;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


