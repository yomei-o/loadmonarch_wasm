/* 00428220 */

/* WARNING: Removing unreachable block (ram,0x00428284) */

void __cdecl
FUN_00428220(void *param_1,uint param_2,int param_3,undefined *param_4,_func_void_void_ptr *param_5)

{
  undefined4 *unaff_FS_OFFSET;
  int local_20;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  uStack_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_004309a0;
  puStack_10 = &LAB_0042b3d8;
  *unaff_FS_OFFSET = &uStack_14;
  local_8 = 0;
  local_20 = 0;
  if (0 < param_3) {
    do {
      (*(code *)param_4)();
      local_20 = local_20 + 1;
    } while (local_20 < param_3);
  }
  return;
}


