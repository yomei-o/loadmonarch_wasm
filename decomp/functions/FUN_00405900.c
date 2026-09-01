/* 00405900 */

undefined4 __cdecl FUN_00405900(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_494 [544];
  undefined1 local_274 [260];
  CHAR local_170 [260];
  undefined4 local_6c [19];
  undefined4 local_20 [3];
  undefined4 local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00405b78;
  *unaff_FS_OFFSET = &local_10;
  iVar1 = FUN_00405860();
  if (iVar1 != 0) {
    FUN_0041f8b0((int)local_494);
    local_8 = 0;
    FUN_00405740(param_1,(int)local_274,&DAT_0043211c);
    FUN_0040bda0(&DAT_00436468,local_170,local_274);
    iVar1 = FUN_0040c010(local_170,local_6c,0x4c);
    if (iVar1 == 0) {
      local_8 = 0xffffffff;
      FUN_00405b82();
    }
    else {
      puVar3 = local_6c;
      puVar4 = &DAT_004365a0;
      for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      DAT_004365d4 = 0;
      DAT_004365dc = 0;
      DAT_004321c8 = 0;
      if (DAT_004365d0 == 0) {
        DAT_00434510 = 0xffffffff;
        local_14 = FUN_00405de0(DAT_004365a0);
        local_8 = 0xffffffff;
        FUN_00405b82();
        goto LAB_0040592c;
      }
      uVar2 = 3000;
      if (((int)DAT_004365a0 <= DAT_00436a00) && (DAT_004365a0 != 0)) {
        uVar2 = *(int *)(&DAT_004369d4 + DAT_004365a0 * 0x38) + 3000;
      }
      if (uVar2 < DAT_004365c8) {
        DAT_004365c4 = 0;
      }
      else {
        DAT_004365c4 = uVar2 - DAT_004365c8;
      }
      FUN_00425bd0(local_20);
      local_8._0_1_ = 1;
      puVar3 = (undefined4 *)FUN_00425c00(local_20,0x16218);
      if (puVar3 == (undefined4 *)0x0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00405b41();
        local_8 = 0xffffffff;
        FUN_00405b82();
      }
      else {
        FUN_00405740(param_1,(int)local_274,&DAT_00432118);
        FUN_0040bda0(&DAT_00436468,local_170,local_274);
        iVar1 = FUN_0040c010(local_170,puVar3,0x16218);
        if (iVar1 != 0) {
          puVar4 = puVar3;
          puVar5 = DAT_00434534;
          for (iVar1 = 0x46; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
          puVar4 = puVar3 + 0x46;
          puVar5 = DAT_0043453c;
          for (iVar1 = 0x3600; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
          puVar3 = puVar3 + 0x3646;
          puVar4 = DAT_00434538;
          for (iVar1 = 0x2240; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar4 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar4 = puVar4 + 1;
          }
          DAT_0043450c = DAT_004365a0;
          DAT_00434514 = 0xffffffff;
          FUN_00405fc0(DAT_004365a4);
          FUN_00427210();
          FUN_004084e0(DAT_004344e4);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00405b41();
          local_8 = 0xffffffff;
          FUN_00405b82();
          local_14 = 1;
          goto LAB_0040592c;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00405b41();
        local_8 = 0xffffffff;
        FUN_00405b82();
      }
    }
  }
  local_14 = 0;
LAB_0040592c:
  *unaff_FS_OFFSET = local_10;
  return local_14;
}


