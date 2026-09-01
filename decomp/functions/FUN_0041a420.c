/* 0041a420 */

undefined4 * __fastcall FUN_0041a420(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041a47d;
  *unaff_FS_OFFSET = &local_10;
  FUN_00425bd0(param_1 + 2);
  local_8 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  wsprintfA((LPSTR)(param_1 + 5),&DAT_00433f6c);
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


