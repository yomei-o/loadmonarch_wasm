/* 00429af0 */

void __cdecl
FUN_00429af0(EHExceptionRecord *param_1,EHRegistrationNode *param_2,undefined4 param_3,
            _s_FuncInfo *param_4,void *param_5,int param_6,ulong param_7)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  uStack_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_004309d0;
  puStack_10 = &LAB_0042b3d8;
  *unaff_FS_OFFSET = &uStack_14;
  uVar3 = DAT_0043478c;
  uVar2 = DAT_00434788;
  uVar1 = *(undefined4 *)(param_2 + -4);
  DAT_00434788 = param_1;
  DAT_0043478c = param_3;
  local_8 = 1;
  pvVar4 = _CallCatchBlock2(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  *(undefined4 *)(param_2 + -4) = uVar1;
  DAT_00434788 = (EHExceptionRecord *)uVar2;
  DAT_0043478c = uVar3;
  if ((((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
      (*(int *)(param_1 + 0x14) == 0x19930520)) && (pvVar4 != (void *)0x0)) {
    iVar5 = __abnormal_termination();
    DestructExceptionObject(param_1,(uchar)iVar5);
  }
  return;
}


