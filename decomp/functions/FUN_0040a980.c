/* 0040a980 */

undefined4 __cdecl FUN_0040a980(int *param_1)

{
  LONG LVar1;
  WPARAM wParam;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined1 *this;
  undefined1 *puVar5;
  undefined4 *unaff_FS_OFFSET;
  UINT_PTR UVar6;
  UINT UVar7;
  CHAR local_150 [256];
  UINT_PTR UStack_50;
  undefined1 local_4c [20];
  undefined1 local_38 [12];
  UINT_PTR local_2c;
  UINT_PTR local_28;
  UINT_PTR local_24;
  UINT_PTR local_20;
  UINT_PTR local_1c;
  UINT_PTR local_18;
  HMENU local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040b072;
  *unaff_FS_OFFSET = &local_10;
  FUN_0040e2f0(&local_28);
  local_8 = 0;
  FUN_0040e2f0(&local_24);
  local_8._0_1_ = 1;
  FUN_0040e2f0(&local_14);
  local_8._0_1_ = 2;
  FUN_0040e2f0(&local_20);
  local_8._0_1_ = 3;
  FUN_0040e2f0(&local_2c);
  local_8._0_1_ = 4;
  FUN_0040e2f0(&local_1c);
  local_8._0_1_ = 5;
  FUN_0040e2f0(&local_18);
  local_8._0_1_ = 6;
  FUN_00428220(local_4c,4,8,FUN_0040e2f0,thunk_FUN_0040e460);
  local_8 = CONCAT31(local_8._1_3_,7);
  if (DAT_004365d4 == 0) {
    if (DAT_00434524 == 1) {
      if (DAT_004365d0 == -1) {
        UVar7 = 0x9c6e;
        UVar6 = 0x9c6d;
      }
      else {
        UVar7 = 0x9c6d;
        UVar6 = 0x9c6d;
      }
    }
    else {
      UVar7 = 0x9c5e;
      UVar6 = 0x9c5e;
    }
  }
  else {
    UVar7 = 0x9cae;
    UVar6 = 0x9cae;
  }
  FUN_0040e330(&local_14,UVar6,UVar7,0);
  FUN_0040e400(&local_14);
  if (DAT_004365d4 == 0) {
    UVar6 = 0xc353;
    iVar4 = 0;
    this = local_4c;
    do {
      FUN_0040e310(this,UVar6,&DAT_00435b97,0);
      FUN_0040e310(this,UVar6 + 1,&DAT_00435b86,0);
      wsprintfA(local_150,s__s_continue_00432470,&DAT_00435b86 + (char)(&DAT_00434445)[iVar4] * 0x11
               );
      puVar5 = this + 4;
      FUN_0040e310(this,UVar6 + 2,local_150,0);
      UVar6 = UVar6 + 3;
      iVar4 = iVar4 + 1;
      this = puVar5;
    } while (puVar5 < local_38);
    uVar3 = 0;
    do {
      wsprintfA(local_150,&DAT_00432100,&DAT_00435b86 + (char)(&DAT_00434444)[uVar3] * 0x11);
      switch(uVar3) {
      case 0:
        UVar6 = 50000;
        goto LAB_0040ab69;
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
        FUN_0040e390(&local_20,*(UINT_PTR *)(local_4c + uVar3 * 4 + -4),local_150);
        break;
      case 6:
        UVar6 = 0xc362;
LAB_0040ab69:
        FUN_0040e310(&local_20,UVar6,local_150,0);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 7);
    FUN_0040e420(&local_20,DAT_004365e4 + 50000);
    FUN_0040b180(&local_2c);
    if (DAT_00434524 == 0) {
      FUN_0040e330(&local_14,0x9c7e,0x9c7e,0);
      FUN_0040e330(&local_14,0x9c7d,0x9c7d,0);
    }
    FUN_0040e3b0(&local_14,local_20,0x9caa);
    FUN_0040e400(&local_14);
    if (DAT_00434524 == 0) {
      FUN_0040e330(&local_14,0x9cb1,0x9cb1,0);
    }
    FUN_0040e3b0(&local_14,local_2c,0x9cb7);
    FUN_0040e400(&local_14);
  }
  LVar1 = FUN_0040a0c0(60000);
  if (LVar1 != 0) {
    iVar4 = *(int *)(LVar1 + 0x398);
    FUN_0040e330(&local_24,0x9c70,0x9c70,-(uint)(iVar4 == 8) & 8);
    FUN_0040e330(&local_24,0x9c71,0x9c71,-(uint)(iVar4 == 0x10) & 8);
    FUN_0040e330(&local_24,0x9c72,0x9c72,-(uint)(iVar4 == 0x20) & 8);
    FUN_0040e3b0(&local_14,local_24,0x9cab);
  }
  FUN_0040e330(&local_18,0x9cac,0x9cac,-(uint)(DAT_004376ab == '\0') & 8);
  LVar1 = FUN_0040a0c0(0xea65);
  FUN_0040e330(&local_18,0xea65,0xea65,-(uint)(LVar1 == 0) & 8);
  FUN_0040e400(&local_18);
  FUN_0040e330(&local_18,0x9cad,0x9cad,(DAT_004376a3 == '\0') - 1 & 8);
  LVar1 = FUN_0040a0c0(0xea65);
  if (LVar1 == 0) {
    FUN_0040e440(&local_18,0x9cad,1);
  }
  FUN_0040e400(&local_18);
  LVar1 = FUN_0040a0c0(0xea61);
  FUN_0040e330(&local_18,0xea61,0xea61,(LVar1 == 0) - 1 & 8);
  LVar1 = FUN_0040a0c0(0xea63);
  FUN_0040e330(&local_18,0xea63,0xea63,(LVar1 == 0) - 1 & 8);
  LVar1 = FUN_0040a0c0(0xea62);
  iVar4 = 0;
  FUN_0040e330(&local_18,0xea62,0xea62,(LVar1 == 0) - 1 & 8);
  FUN_0040e400(&local_18);
  do {
    LVar1 = FUN_0040a0c0(iVar4 + 60000);
    if (LVar1 != 0) {
      FUN_0040e310(&local_18,iVar4 + 61000,(LPCSTR)(LVar1 + 0x48),0);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 10);
  FUN_0040e330(&local_18,0x9caf,0x9caf,0);
  FUN_0040e400(&local_14);
  FUN_0040e3b0(&local_14,local_18,0x9cc4);
  FUN_0040e330(&local_28,0x9c54,0x9c54,0);
  FUN_0040e330(&local_28,0x9cb5,0x9cb5,0);
  FUN_0040e330(&local_1c,0x9c73,0x9c73,0);
  FUN_0040e330(&local_1c,0x9c55,0x9c55,0);
  FUN_0040e3b0(&local_1c,local_28,0x9c74);
  FUN_0040e400(&local_1c);
  FUN_0040e330(&local_1c,0x9cae,0x9cae,0);
  FUN_0040e400(&local_1c);
  FUN_0040e330(&local_1c,0x9cb2,0x9cb2,0);
  FUN_0040e400(&local_1c);
  FUN_0040e330(&local_1c,0x9c6c,0x9c6c,0);
  FUN_0040e400(&local_14);
  FUN_0040e3b0(&local_14,local_1c,0x9cc2);
  FUN_0040e400(&local_14);
  FUN_0040e330(&local_14,0,0x9cc5,0);
  DAT_004365dc = 4;
  wParam = TrackPopupMenu(local_14,0x102,*param_1,param_1[1],0,DAT_004344d4,(RECT *)0x0);
  if (wParam == 0) {
    DAT_004365dc = 0;
    local_8._0_1_ = 6;
    FUN_0040b02f();
    local_8._0_1_ = 5;
    FUN_0040b042();
    local_8._0_1_ = 4;
    FUN_0040b04a();
    local_8._0_1_ = 3;
    FUN_0040b052();
    local_8._0_1_ = 2;
    FUN_0040b05a();
    local_8._0_1_ = 1;
    FUN_0040b062();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0040b06a();
    local_8 = 0xffffffff;
    FUN_0040b07c();
    uVar2 = 0;
  }
  else {
    PostMessageA(*(HWND *)(DAT_004344e4 + 8),0x111,wParam,0);
    if ((wParam != 0x9c7e) && (wParam != 0x9c7d)) {
      DAT_004365dc = 0;
    }
    local_8._0_1_ = 6;
    FUN_0040b02f();
    local_8._0_1_ = 5;
    FUN_0040b042();
    local_8._0_1_ = 4;
    FUN_0040b04a();
    local_8._0_1_ = 3;
    FUN_0040b052();
    local_8._0_1_ = 2;
    FUN_0040b05a();
    local_8._0_1_ = 1;
    FUN_0040b062();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0040b06a();
    local_8 = 0xffffffff;
    FUN_0040b07c();
    uVar2 = 1;
  }
  *unaff_FS_OFFSET = local_10;
  return uVar2;
}


