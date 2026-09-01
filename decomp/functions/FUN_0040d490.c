/* 0040d490 */

int __thiscall FUN_0040d490(void *this,undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  DWORD DVar3;
  BOOL BVar4;
  undefined3 extraout_var_00;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar5;
  CHAR local_440 [260];
  undefined2 local_33c [272];
  CHAR local_11c [260];
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040d90a;
  *unaff_FS_OFFSET = &local_10;
  FUN_0041f8b0((int)local_33c);
  local_8 = 0;
  local_14 = 1;
  iVar2 = FUN_0040c1c0(&DAT_00436468);
  if (iVar2 != 0) {
    wsprintfA(local_440,s_USnd_02d_cfg_004325a8,param_1);
    iVar2 = FUN_0040bda0(&DAT_00436468,local_11c,local_440);
    if (iVar2 != 0) {
      do {
        local_14 = 1;
        bVar1 = FUN_0041f9a0(local_33c,local_11c);
        if (CONCAT31(extraout_var,bVar1) == 0) {
          local_14 = 0;
        }
        else {
          wsprintfA(local_11c,s__entry__004326bc);
          DVar3 = lstrlenA(local_11c);
          BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
          if (BVar4 == 0) {
            local_14 = 0;
          }
          wsprintfA(local_11c,s_NAME__s_004326b0,param_2);
          DVar3 = lstrlenA(local_11c);
          BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
          if (BVar4 == 0) {
            local_14 = 0;
          }
          wsprintfA(local_11c,s_MAX__d_004326a8,*(undefined4 *)((int)this + 0x18));
          DVar3 = lstrlenA(local_11c);
          BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
          if (BVar4 == 0) {
            local_14 = 0;
          }
          local_18 = 0;
          if (0 < *(int *)((int)this + 0x18)) {
            iVar2 = 0;
            do {
              if (*(int *)(*(int *)this + iVar2) != -1) {
                wsprintfA(local_11c,s___d__004326a0,local_18);
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
                wsprintfA(local_11c,s_ENTRY__d_00432694,*(undefined4 *)(*(int *)this + iVar2));
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
                wsprintfA(local_11c,s_MODE__d_00432688,*(undefined4 *)(*(int *)this + 0x108 + iVar2)
                         );
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
                wsprintfA(local_11c,s_DEVICE__d_0043267c,
                          *(undefined4 *)(*(int *)this + 0x10c + iVar2));
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
                wsprintfA(local_11c,s_NAME__s_004326b0,*(int *)this + iVar2 + 4);
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
                if (*(int *)(*(int *)this + iVar2 + 0x108) == 0) {
                  pcVar5 = s_MIDI__s_00432670;
                }
                else {
                  pcVar5 = s_WAVE__s_00432664;
                }
                wsprintfA(local_11c,pcVar5,*(int *)this + iVar2 + 0x114);
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
                wsprintfA(local_11c,s_CD__d_0043265c,*(undefined4 *)(*(int *)this + 0x110 + iVar2));
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
                wsprintfA(local_11c,s_LOOP__d_00432650,(uint)*(byte *)(*(int *)this + 0x214 + iVar2)
                         );
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
                wsprintfA(local_11c,&DAT_004324cc);
                DVar3 = lstrlenA(local_11c);
                BVar4 = FUN_0041fc10(local_33c,local_11c,DVar3);
                if (BVar4 == 0) {
                  local_14 = 0;
                }
              }
              iVar2 = iVar2 + 0x220;
              local_18 = local_18 + 1;
            } while (local_18 < *(int *)((int)this + 0x18));
          }
          FUN_0041fa40(local_33c);
        }
        if (local_14 != 0) goto LAB_0040d8f9;
        bVar1 = FUN_0040c2e0();
      } while (CONCAT31(extraout_var_00,bVar1) != 0);
      FUN_00409370(s_Failed_in_saving_environment__00432630,0);
      local_8 = 0xffffffff;
      FUN_0040d914();
      local_14 = 0;
      goto LAB_0040d8e6;
    }
  }
LAB_0040d8f9:
  local_8 = 0xffffffff;
  FUN_0040d914();
LAB_0040d8e6:
  *unaff_FS_OFFSET = local_10;
  return local_14;
}


