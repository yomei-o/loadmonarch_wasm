/* 00422610 */

undefined4 * __fastcall FUN_00422610(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 *unaff_FS_OFFSET;
  tagRECT local_24;
  undefined4 *local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00422830;
  *unaff_FS_OFFSET = &local_10;
  local_14 = param_1;
  FUN_00427770(param_1);
  local_8 = 0;
  *param_1 = &PTR_FUN_004307c0;
  uVar1 = (uint)DAT_004376ae;
  param_1[0x9e] = 0x54f40000;
  param_1[0x9f] = 0x80;
  param_1[0xe6] = uVar1;
  iVar2 = GetSystemMetrics(0x20);
  param_1[6] = iVar2 * 2;
  iVar2 = GetSystemMetrics(0x21);
  iVar3 = GetSystemMetrics(0x33);
  *(undefined1 *)(param_1 + 0xf0) = 1;
  *(undefined1 *)((int)param_1 + 0x3c1) = 1;
  param_1[7] = iVar2 * 2 + iVar3;
  *(undefined2 *)(param_1 + 0xf1) = *(undefined2 *)(param_1 + 0xf0);
  param_1[0xef] = 0;
  iVar2 = param_1[0xe6];
  param_1[0xeb] = iVar2;
  param_1[0xec] = iVar2;
  param_1[0xed] = iVar2;
  param_1[0xee] = param_1[0xec];
  wsprintfA((LPSTR)(param_1 + 0x53),s_MapInfo_c_00434458,
            (int)(char)(&DAT_0043444c)[(int)(iVar2 + (iVar2 >> 0x1f & 0xfU)) >> 4]);
  iVar2 = param_1[0xe6];
  param_1[8] = iVar2 * 0x30;
  param_1[9] = iVar2 * 0x30;
  if (iVar2 == 8) {
    param_1[0x572] = DAT_0043645c;
    uVar6 = DAT_00436448;
  }
  else if (iVar2 == 0x10) {
    param_1[0x572] = DAT_00436458;
    uVar6 = DAT_00436444;
  }
  else {
    if (iVar2 != 0x20) goto LAB_0042275b;
    param_1[0x572] = DAT_00436454;
    uVar6 = DAT_00436440;
  }
  param_1[0x573] = uVar6;
LAB_0042275b:
  param_1[10] = 0;
  iVar2 = GetSystemMetrics(0x20);
  param_1[0xb] = iVar2 * 2 + 0xb0;
  param_1[0xc] = param_1[6] + param_1[8];
  *(undefined1 *)(param_1 + 0x575) = 0;
  param_1[0xd] = param_1[9] + param_1[7];
  GetClientRect(*(HWND *)(DAT_004344e4 + 8),&local_24);
  if (local_24.right <= (int)(param_1[0xc] + param_1[10])) {
    param_1[0xc] = local_24.right - param_1[10];
  }
  if (local_24.bottom <= (int)(param_1[0xd] + param_1[0xb])) {
    param_1[0xd] = local_24.bottom - param_1[0xb];
  }
  pcVar4 = s_Quest_004323fc;
  if (DAT_004365cc == '\0') {
    pcVar4 = s_Single_004323f4;
  }
  iVar2 = DAT_0043450c + 1;
  DAT_004344e8 = param_1;
  pcVar5 = FUN_0041a650(&DAT_004376c8,DAT_0043450c);
  wsprintfA((LPSTR)(param_1 + 0x12),s__s__s__d___s_004323e4,s_Map_Window_004323d8,pcVar5,iVar2,
            pcVar4);
  param_1[0x5fa] = 0;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


