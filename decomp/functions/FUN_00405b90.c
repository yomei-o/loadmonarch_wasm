/* 00405b90 */

undefined4 __cdecl FUN_00405b90(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_448 [544];
  undefined1 local_228 [260];
  CHAR local_124 [260];
  undefined4 local_20 [3];
  undefined4 *local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00405dc6;
  *unaff_FS_OFFSET = &local_10;
  iVar1 = FUN_004057f0();
  if (iVar1 != 0) {
    FUN_0041f8b0((int)local_448);
    local_8 = 0;
    FUN_00405740(param_1,(int)local_228,&DAT_0043211c);
    FUN_0040bda0(&DAT_00436468,local_124,local_228);
    DAT_004365a0 = DAT_0043450c;
    GetLocalTime((LPSYSTEMTIME)&DAT_004365ac);
    iVar1 = FUN_0040c0d0(local_124,&DAT_004365a0,0x4c);
    if (iVar1 == 0) {
      local_8 = 0xffffffff;
      FUN_00405dd0();
    }
    else {
      if ((DAT_004365d0 != -1) || (DAT_004365d4 != 0)) {
        local_8 = 0xffffffff;
        FUN_00405dd0();
        uVar2 = 1;
        goto LAB_00405bbc;
      }
      FUN_00425bd0(local_20);
      local_8._0_1_ = 1;
      local_14 = (undefined4 *)FUN_00425c00(local_20,0x16218);
      if (local_14 == (undefined4 *)0x0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00405da8();
        local_8 = 0xffffffff;
        FUN_00405dd0();
      }
      else {
        puVar3 = DAT_00434534;
        puVar4 = local_14;
        for (iVar1 = 0x46; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
        puVar3 = DAT_0043453c;
        puVar4 = local_14 + 0x46;
        for (iVar1 = 0x3600; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
        puVar3 = DAT_00434538;
        puVar4 = local_14 + 0x3646;
        for (iVar1 = 0x2240; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
        FUN_00405740(param_1,(int)local_228,&DAT_00432118);
        FUN_0040bda0(&DAT_00436468,local_124,local_228);
        iVar1 = FUN_0040c0d0(local_124,local_14,0x16218);
        if (iVar1 != 0) {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00405da8();
          local_8 = 0xffffffff;
          FUN_00405dd0();
          uVar2 = 1;
          goto LAB_00405bbc;
        }
        if (DAT_00434530 == 0x70) {
          FUN_00405740(param_1,(int)local_228,&DAT_0043211c);
          FUN_0040bda0(&DAT_00436468,local_124,local_228);
          FUN_0040c3d0(local_124);
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00405da8();
        local_8 = 0xffffffff;
        FUN_00405dd0();
      }
    }
  }
  uVar2 = 0;
LAB_00405bbc:
  *unaff_FS_OFFSET = local_10;
  return uVar2;
}


