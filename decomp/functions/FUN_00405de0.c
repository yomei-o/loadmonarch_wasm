/* 00405de0 */

undefined4 __cdecl FUN_00405de0(uint param_1)

{
  undefined1 *puVar1;
  bool bVar2;
  LPVOID pvVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined3 extraout_var;
  int iVar6;
  int iVar7;
  undefined4 *unaff_FS_OFFSET;
  bool bVar8;
  CHAR local_340 [260];
  undefined2 local_23c [272];
  int local_1c [3];
  undefined4 local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00405fa9;
  *unaff_FS_OFFSET = &local_10;
  if (((int)param_1 < 0) || (DAT_004376cc < param_1)) {
    param_1 = DAT_004376cc;
  }
  if (DAT_004376cc == param_1) {
    param_1 = DAT_004376cc - 1;
  }
  DAT_004321c8 = 0;
  DAT_0043450c = param_1;
  DAT_004365a0 = param_1;
  FUN_0041f8b0((int)local_23c);
  local_8 = 0;
  FUN_00425bd0(local_1c);
  local_8._0_1_ = 1;
  pvVar3 = (LPVOID)FUN_00425c00(local_1c,0x902);
  if (pvVar3 == (LPVOID)0x0) {
    local_8 = (uint)local_8._1_3_ << 8;
  }
  else {
    pcVar5 = FUN_0041a620(&DAT_004376c8,DAT_0043450c);
    bVar8 = false;
    FUN_00409490(local_340,&DAT_00432120,pcVar5);
    bVar2 = FUN_0041f9f0(local_23c,local_340);
    if (CONCAT31(extraout_var,bVar2) != 0) {
      iVar6 = FUN_0041fa80(local_23c,pvVar3,0x902,0);
      bVar8 = iVar6 != 0;
      FUN_0041fa40(local_23c);
    }
    if (bVar8) {
      iVar6 = 0;
      iVar7 = 0;
      do {
        puVar1 = (undefined1 *)(iVar6 + (int)pvVar3);
        iVar7 = iVar7 + 0x18;
        iVar6 = iVar6 + 1;
        *(undefined1 *)(DAT_0043453c + -8 + iVar7) = *puVar1;
        *(undefined4 *)(DAT_0043453c + -0xc + iVar7) = 100;
        *(undefined1 *)(DAT_0043453c + -0x18 + iVar7) = 0x40;
      } while (iVar7 < 0xd800);
      DAT_004365a4 = (uint)*(byte *)((int)pvVar3 + 0x900);
      FUN_00425c80(local_1c);
      FUN_00425c20(local_1c);
      iVar6 = FUN_00405fc0(DAT_004365a4);
      if (iVar6 != 0) {
        DAT_00434510 = param_1;
        FUN_004271e0();
        FUN_004084e0(DAT_004344e4);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00405fa1();
        local_8 = 0xffffffff;
        FUN_00405fb3();
        uVar4 = 1;
        goto LAB_00405e7c;
      }
      local_8 = (uint)local_8._1_3_ << 8;
    }
    else {
      local_8 = (uint)local_8._1_3_ << 8;
    }
  }
  FUN_00405fa1();
  local_8 = 0xffffffff;
  FUN_00405fb3();
  uVar4 = 0;
LAB_00405e7c:
  *unaff_FS_OFFSET = local_10;
  return uVar4;
}


