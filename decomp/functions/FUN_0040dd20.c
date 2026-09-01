/* 0040dd20 */

int * __fastcall FUN_0040dd20(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040dd9e;
  *unaff_FS_OFFSET = &local_10;
  piVar1 = param_1 + 0x14;
  FUN_0040db50(param_1);
  local_8 = 0;
  *param_1 = (int)&PTR_FUN_00430238;
  piVar3 = piVar1;
  for (iVar2 = 0x103; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  iVar2 = FUN_0040de60(param_1);
  if (iVar2 == 0) {
    *(undefined1 *)piVar1 = 0;
    DAT_004376b4 = 1;
  }
  else {
    *(undefined1 *)piVar1 = 1;
    FUN_0040df80((int)param_1);
  }
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


