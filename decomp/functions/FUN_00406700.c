/* 00406700 */

bool __cdecl FUN_00406700(LPVOID param_1,undefined4 *param_2,LPCSTR param_3,byte param_4)

{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined2 local_230 [272];
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040679d;
  *unaff_FS_OFFSET = &local_10;
  FUN_0041f8b0((int)local_230);
  local_8 = 0;
  iVar1 = FUN_0041f930(local_230,param_3,param_1,0x8030,1);
  if (iVar1 == 0) {
    local_8 = 0xffffffff;
    FUN_004067a7();
  }
  else {
    FUN_00406c70((int)param_1,param_2,(uint)param_4);
    FUN_0041fa40(local_230);
    local_8 = 0xffffffff;
    FUN_004067a7();
  }
  *unaff_FS_OFFSET = local_10;
  return iVar1 != 0;
}


