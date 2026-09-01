/* 00407240 */

void __fastcall FUN_00407240(undefined4 *param_1)

{
  LPVOID pvVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00407306;
  *param_1 = &PTR_FUN_00430078;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0;
  if ((HGDIOBJ)param_1[0xe8] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)param_1[0xe8]);
    param_1[0xe8] = 0;
  }
  if ((HGDIOBJ)param_1[0xe9] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)param_1[0xe9]);
    param_1[0xe9] = 0;
  }
  pvVar1 = DAT_00436460;
  if (DAT_00436460 != (LPVOID)0x0) {
    FUN_00424f50();
    FUN_00427f80(pvVar1);
    DAT_00436460 = (LPVOID)0x0;
  }
  DAT_004344e4 = 0;
  PostQuitMessage(0);
  local_8 = 0xffffffff;
  FUN_00407310();
  *unaff_FS_OFFSET = local_10;
  return;
}


