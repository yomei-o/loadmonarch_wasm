/* 0040d0e0 */

undefined4 __thiscall FUN_0040d0e0(void *this,LPCSTR param_1)

{
  int *this_00;
  int iVar1;
  undefined4 uVar2;
  UINT UVar3;
  int iVar4;
  UINT UVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_544 [544];
  CHAR local_324 [260];
  CHAR local_220 [260];
  char local_11c;
  undefined1 local_11b [259];
  UINT local_18;
  int local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040d3f2;
  *unaff_FS_OFFSET = &local_10;
  FUN_0041f8b0((int)local_544);
  local_8 = 0;
  iVar1 = FUN_0041fc60(local_544,param_1);
  if (iVar1 != 0) {
    GetPrivateProfileStringA
              (s_entry_00432618,&DAT_00432620,s_no_name_00432628,(LPSTR)((int)this + 0x1c),0x104,
               param_1);
    UVar3 = GetPrivateProfileIntA(s_entry_00432618,&DAT_00432614,0,param_1);
    if (UVar3 != 0) {
      this_00 = (int *)((int)this + 4);
      *(UINT *)((int)this + 0x18) = UVar3;
      FUN_00425c80(this_00);
      FUN_00425c20(this_00);
      iVar1 = FUN_00425c00(this_00,*(int *)((int)this + 0x18) * 0x220);
      *(int *)this = iVar1;
      if (iVar1 != 0) {
        local_14 = 0;
        if (0 < *(int *)((int)this + 0x18)) {
          iVar1 = 0;
          do {
            *(undefined4 *)(*(int *)this + iVar1) = 0xffffffff;
            iVar4 = *(int *)this + iVar1;
            iVar1 = iVar1 + 0x220;
            wsprintfA((LPSTR)(iVar4 + 4),&DAT_0043260c);
            local_14 = local_14 + 1;
            *(undefined4 *)(*(int *)this + -0x118 + iVar1) = 0;
            *(undefined4 *)(*(int *)this + -0x114 + iVar1) = 0;
            *(undefined4 *)(*(int *)this + -0x110 + iVar1) = 0;
            *(undefined1 *)(*(int *)this + -0xc + iVar1) = 0;
            *(undefined4 *)(*(int *)this + -8 + iVar1) = 0;
            *(undefined4 *)(*(int *)this + -4 + iVar1) = 0;
          } while (local_14 < *(int *)((int)this + 0x18));
        }
        local_14 = 0;
        if (0 < *(int *)((int)this + 0x18)) {
          do {
            wsprintfA(local_220,&DAT_00432608,local_14);
            UVar3 = GetPrivateProfileIntA(local_220,s_ENTRY_00432600,-1,param_1);
            if (UVar3 != 0xffffffff) {
              FUN_0040ce10(this,UVar3,0);
              GetPrivateProfileStringA
                        (local_220,&DAT_00432620,s_no_name_00432628,&local_11c,0x104,param_1);
              FUN_0040cf80(this,UVar3,&local_11c);
              UVar5 = GetPrivateProfileIntA(local_220,&DAT_004325fc,0,param_1);
              FUN_0040cfc0(this,UVar3,UVar5);
              UVar5 = GetPrivateProfileIntA(local_220,s_DEVICE_004325f4,0,param_1);
              if (UVar5 < 3) {
                FUN_0040ce60(this,UVar3,UVar5);
              }
              local_18 = GetPrivateProfileIntA(local_220,&DAT_004325ec,0,param_1);
              FUN_0040d020(this,UVar3,local_18);
              if (local_18 == 0) {
                GetPrivateProfileStringA
                          (local_220,&DAT_004325d8,s__Lm000_mid_004325e0,&local_11c,0x104,param_1);
              }
              else {
                GetPrivateProfileStringA
                          (local_220,&DAT_004325c0,s__Lm90000_wav_004325c8,&local_11c,0x104,param_1)
                ;
              }
              if (local_11c == '*') {
                FUN_00409490(local_324,s_Sound__0043258c,local_11b);
                lstrcpyA(&local_11c,local_324);
              }
              FUN_0040cf40(this,UVar3,&local_11c);
              UVar5 = GetPrivateProfileIntA(local_220,&DAT_004325b8,0,param_1);
              FUN_0040cff0(this,UVar3,(char)UVar5);
            }
            local_14 = local_14 + 1;
          } while (local_14 < *(int *)((int)this + 0x18));
        }
        local_8 = 0xffffffff;
        FUN_0040d3fc();
        uVar2 = 1;
        goto LAB_0040d136;
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_0040d3fc();
  uVar2 = 0;
LAB_0040d136:
  *unaff_FS_OFFSET = local_10;
  return uVar2;
}


