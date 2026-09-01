/* 00405fc0 */

undefined4 __cdecl FUN_00405fc0(int param_1)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  byte *pbVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  char *pcVar6;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  char *pcVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *unaff_FS_OFFSET;
  CHAR local_268 [256];
  CHAR local_168 [260];
  char local_64 [24];
  undefined4 local_4c;
  char acStack_25 [9];
  int local_1c [3];
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_004065c4;
  *unaff_FS_OFFSET = &local_10;
  SendMessageA(DAT_004344d4,0x111,0x9c5e,0);
  if (DAT_004365a4 != -1) {
    iVar4 = FUN_0040cdc0(0);
    if (iVar4 - param_1 != 2) {
      FUN_0040cd20(&DAT_00435db0,param_1 + 2,0);
    }
    if (param_1 != DAT_00434514) {
      DAT_00434510 = DAT_0043450c;
      DAT_00434514 = param_1;
      DAT_004365a4 = param_1;
      FUN_00425bd0(local_1c);
      local_8 = 0;
      pbVar5 = (byte *)FUN_00425c00(local_1c,0x8030);
      if (pbVar5 == (byte *)0x0) {
        local_8 = 0xffffffff;
        FUN_004065ce();
        uVar3 = 0;
        goto LAB_00406007;
      }
      wsprintfA(local_268,s_B__03ds_bz_0043218c,param_1);
      FUN_00409490(local_168,&DAT_00432188,local_268);
      bVar2 = FUN_00406640(pbVar5,DAT_0043645c,local_168,8);
      if (CONCAT31(extraout_var,bVar2) == 0) {
        wsprintfA(local_168,s__s___No_Files_found__00432170,local_268);
        FUN_00409370(local_168,0);
        local_8 = 0xffffffff;
        FUN_004065ce();
        uVar3 = 0;
        goto LAB_00406007;
      }
      wsprintfA(local_268,s_B__03dm_bz_00432164,param_1);
      FUN_00409490(local_168,&DAT_00432188,local_268);
      bVar2 = FUN_00406640(pbVar5,DAT_00436458,local_168,0x10);
      if (CONCAT31(extraout_var_00,bVar2) == 0) {
        wsprintfA(local_168,s__s___No_Files_found__00432170,local_268);
        FUN_00409370(local_168,0);
        local_8 = 0xffffffff;
        FUN_004065ce();
        uVar3 = 0;
        goto LAB_00406007;
      }
      wsprintfA(local_268,s_B__03dl_bz_00432158,param_1);
      FUN_00409490(local_168,&DAT_00432188,local_268);
      bVar2 = FUN_00406640(pbVar5,DAT_00436454,local_168,0x20);
      if (CONCAT31(extraout_var_01,bVar2) == 0) {
        wsprintfA(local_168,s__s___No_Files_found__00432170,local_268);
        FUN_00409370(local_168,0);
        local_8 = 0xffffffff;
        FUN_004065ce();
        uVar3 = 0;
        goto LAB_00406007;
      }
      FUN_004065e0(0x10,0x10,(int)pbVar5);
      iVar4 = 0x10;
      pbVar8 = pbVar5 + 0x8000;
      do {
        *pbVar8 = (byte)(((uint)*pbVar8 * 0x55) / 100);
        pbVar8[1] = (byte)(((uint)pbVar8[1] * 0x55) / 100);
        iVar4 = iVar4 + -1;
        pbVar8[2] = (byte)(((uint)pbVar8[2] * 0x55) / 100);
        pbVar8 = pbVar8 + 3;
      } while (iVar4 != 0);
      FUN_004065e0(0x20,0x10,(int)pbVar5);
      pbVar8 = pbVar5 + 0x7ea0;
      puVar9 = &DAT_00435b20;
      do {
        puVar11 = (undefined4 *)((int)puVar9 + 0x11);
        *puVar9 = *(undefined4 *)pbVar8;
        puVar9[1] = *(undefined4 *)(pbVar8 + 4);
        puVar9[2] = *(undefined4 *)(pbVar8 + 8);
        puVar9[3] = *(undefined4 *)(pbVar8 + 0xc);
        *(undefined1 *)(puVar9 + 4) = 0;
        pbVar8 = pbVar8 + 0x10;
        puVar9 = puVar11;
      } while (puVar11 < &DAT_00435c96);
      pcVar7 = &DAT_00435b31;
      iVar4 = 1;
      do {
        cVar1 = *pcVar7;
        pcVar6 = pcVar7 + 0x11;
        *pcVar7 = ' ';
        acStack_25[iVar4] = cVar1 + '\x10';
        pcVar7[0xd] = '\0';
        pcVar7[0xe] = '\0';
        pcVar7[0xf] = '\0';
        pcVar7 = pcVar6;
        iVar4 = iVar4 + 1;
      } while (pcVar6 < &DAT_00435b86);
      wsprintfA(local_268,s_C__03ds_bz_0043214c,param_1);
      FUN_00409490(local_168,&DAT_00432144,local_268);
      bVar2 = FUN_00406700(pbVar5,DAT_00436448,local_168,8);
      if (CONCAT31(extraout_var_02,bVar2) == 0) {
        wsprintfA(local_168,s__s___No_Files_found__00432170,local_268);
        FUN_00409370(local_168,0);
        local_8 = 0xffffffff;
        FUN_004065ce();
        uVar3 = 0;
        goto LAB_00406007;
      }
      wsprintfA(local_268,s_C__03dm_bz_00432138,param_1);
      FUN_00409490(local_168,&DAT_00432144,local_268);
      bVar2 = FUN_00406700(pbVar5,DAT_00436444,local_168,0x10);
      if (CONCAT31(extraout_var_03,bVar2) == 0) {
        wsprintfA(local_168,s__s___No_Files_found__00432170,local_268);
        FUN_00409370(local_168,0);
        local_8 = 0xffffffff;
        FUN_004065ce();
        uVar3 = 0;
        goto LAB_00406007;
      }
      iVar4 = 0;
      puVar9 = DAT_00436440;
      do {
        wsprintfA(local_268,s_C__03dl_c_bz_00432128,param_1,iVar4 + 0x31);
        FUN_00409490(local_168,&DAT_00432144,local_268);
        bVar2 = FUN_00406700(pbVar5,puVar9,local_168,0x20);
        if (CONCAT31(extraout_var_04,bVar2) == 0) {
          wsprintfA(local_168,s__s___No_Files_found__00432170,local_268);
          FUN_00409370(local_168,0);
          local_8 = 0xffffffff;
          FUN_004065ce();
          uVar3 = 0;
          goto LAB_00406007;
        }
        puVar9 = puVar9 + 0x4000;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
      FUN_004065e0(0x30,0x10,(int)pbVar5);
      FUN_00425c80(local_1c);
      FUN_00425c20(local_1c);
      local_64[0] = '\0';
      local_64[1] = 0;
      local_64[2] = 0x96;
      iVar4 = 0;
      do {
        iVar10 = iVar4 + 1;
        FUN_0040e5d0(&DAT_004365f0,((byte)acStack_25[iVar4 + 1] & 0xf) + 0x30,
                     local_64 + iVar4 * 4 + 4);
        iVar4 = iVar10;
      } while (iVar10 < 5);
      FUN_0040e5d0(&DAT_004365f0,0x1f,&DAT_00437568);
      FUN_0040e5d0(&DAT_004365f0,0x3f,(undefined1 *)&DAT_0043768c);
      local_4c = DAT_0043768c;
      FUN_0040e560(&DAT_004365f0,local_64,0x70,7);
      pcVar7 = local_64 + 2;
      do {
        *pcVar7 = -1;
        pcVar6 = pcVar7 + 4;
        pcVar7[-2] = -1;
        pcVar7[-1] = -1;
        pcVar7 = pcVar6;
      } while (pcVar6 < acStack_25 + 3);
      FUN_0040e560(&DAT_004365f0,local_64,0x50,0x10);
      FUN_0040e600(0x4365f0);
      FUN_00409e10();
      local_8 = 0xffffffff;
      FUN_004065ce();
    }
  }
  uVar3 = 1;
LAB_00406007:
  *unaff_FS_OFFSET = local_10;
  return uVar3;
}


