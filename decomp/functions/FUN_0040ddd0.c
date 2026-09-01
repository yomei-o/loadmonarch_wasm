/* 0040ddd0 */

void __fastcall FUN_0040ddd0(undefined4 *param_1)

{
  MCIERROR MVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_0040de42;
  *param_1 = &PTR_FUN_00430238;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0;
  if (*(ushort *)((int)param_1 + 6) != 0) {
    MVar1 = mciSendCommandA((uint)*(ushort *)((int)param_1 + 6),0x804,2,0);
    *(undefined2 *)((int)param_1 + 6) = 0;
    *(undefined1 *)(param_1 + 0x14) = 0;
    param_1[0x13] = MVar1;
  }
  local_8 = 0xffffffff;
  FUN_0040de4c();
  *unaff_FS_OFFSET = local_10;
  return;
}


