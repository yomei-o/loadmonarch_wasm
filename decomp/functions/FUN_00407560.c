/* 00407560 */

undefined4 FUN_00407560(void)

{
  bool bVar1;
  undefined3 extraout_var;
  LPVOID pvVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_410 [192];
  undefined2 local_350 [272];
  CHAR local_130 [260];
  int local_2c [3];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040772d;
  *unaff_FS_OFFSET = &local_10;
  FUN_0041f8b0((int)local_350);
  local_8 = 0;
  FUN_00409490(local_130,s_DATA__004321b0,s_data1_rgb_00432238);
  bVar1 = FUN_0041f9f0(local_350,local_130);
  if (CONCAT31(extraout_var,bVar1) == 1) {
    FUN_0041fa80(local_350,local_410,0xc0,0);
    FUN_0041fa40(local_350);
    FUN_0040e560(&DAT_004365f0,local_410,0x80,0x30);
  }
  FUN_00425bd0(local_2c);
  local_8._0_1_ = 1;
  pvVar2 = (LPVOID)FUN_00425c00(local_2c,0x40000);
  if (pvVar2 != (LPVOID)0x0) {
    FUN_00409490(local_130,s_DATA__004321b0,s_data1_bz_0043222c);
    iVar4 = FUN_0041f930(local_350,local_130,pvVar2,0x40000,1);
    if (iVar4 != 0) {
      iVar4 = 0;
      local_14 = 0;
      do {
        local_1c = 0x10;
        local_18 = local_14;
        do {
          local_20 = 0x10;
          iVar5 = local_18;
          do {
            iVar6 = 0;
            do {
              if (*(char *)((int)pvVar2 + iVar4 + iVar6) == '\x1f') {
                *(undefined1 *)((int)pvVar2 + iVar4 + iVar6) = 0x70;
                *(undefined1 *)(DAT_00435fd4 + iVar6 + iVar5) = 0x70;
              }
              else {
                *(char *)(DAT_00435fd4 + iVar6 + iVar5) =
                     *(char *)((int)pvVar2 + iVar4 + iVar6) + 'p';
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 < 0x10);
            iVar4 = iVar4 + 0x10;
            iVar5 = iVar5 + 0x100;
            local_20 = local_20 + -1;
          } while (local_20 != 0);
          local_18 = local_18 + 0x10;
          local_1c = local_1c + -1;
        } while (local_1c != 0);
        local_14 = local_14 + 0x1000;
      } while (local_14 < 0x40000);
      FUN_00425c80(local_2c);
      FUN_00425c20(local_2c);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00407725();
      local_8 = 0xffffffff;
      FUN_00407737();
      uVar3 = 1;
      goto LAB_00407635;
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00407725();
  local_8 = 0xffffffff;
  FUN_00407737();
  uVar3 = 0;
LAB_00407635:
  *unaff_FS_OFFSET = local_10;
  return uVar3;
}


