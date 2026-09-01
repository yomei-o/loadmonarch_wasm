/* 004095d0 */

void __cdecl FUN_004095d0(uint param_1,uint param_2,HWND param_3)

{
  void *pvVar1;
  undefined4 *this;
  undefined4 *unaff_FS_OFFSET;
  uint local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00409bc2;
  *unaff_FS_OFFSET = &local_10;
  this = (undefined4 *)0x0;
  FUN_00408de0(1);
  if (param_1 < 0x71) {
    if (param_1 == 0x70) {
      pvVar1 = (void *)FUN_00427f90(0x23998);
      local_8 = 1;
      this = (undefined4 *)0x0;
      if (pvVar1 != (void *)0x0) {
        this = FUN_00418cd0(pvVar1,0x70);
      }
      local_8 = 0xffffffff;
      local_14 = 0x70;
      goto LAB_00409616;
    }
    if (param_1 == 0x69) {
      pvVar1 = (void *)FUN_00427f90(0x583c);
      local_8 = 0;
      this = (undefined4 *)0x0;
      if (pvVar1 != (void *)0x0) {
        this = FUN_0040fb80(pvVar1,0x69,param_2);
      }
      local_8 = 0xffffffff;
      local_14 = 0x69;
      goto LAB_00409616;
    }
  }
  else if (param_1 < 0x77) {
    if (param_1 == 0x76) {
      pvVar1 = (void *)FUN_00427f90(0x24c);
      local_8 = 3;
      this = (undefined4 *)0x0;
      if (pvVar1 != (void *)0x0) {
        this = FUN_00412ed0(pvVar1,0x76);
      }
      local_8 = 0xffffffff;
      local_14 = 0x76;
      goto LAB_00409616;
    }
    if (param_1 == 0x72) {
      pvVar1 = (void *)FUN_00427f90(0x234);
      local_8 = 2;
      this = (undefined4 *)0x0;
      if (pvVar1 != (void *)0x0) {
        this = FUN_00411fe0(pvVar1,0x72);
      }
      local_8 = 0xffffffff;
      local_14 = 0x72;
      goto LAB_00409616;
    }
  }
  else {
    if (0x9c4c < param_1) {
      switch(param_1) {
      case 0x9c54:
        this = (undefined4 *)FUN_00427f90(0x234);
        local_8 = 7;
        if (this == (undefined4 *)0x0) {
          this = (undefined4 *)0x0;
        }
        else {
          FUN_0040e6b0(this,param_1);
          *this = &PTR_LAB_00430128;
        }
        local_8 = 0xffffffff;
        local_14 = 0x68;
        break;
      case 0x9c55:
        pvVar1 = (void *)FUN_00427f90(0x460);
        this = (undefined4 *)0x0;
        local_8 = 9;
        if (pvVar1 != (void *)0x0) {
          this = FUN_0040f580(pvVar1,param_1);
        }
        local_8 = 0xffffffff;
        local_14 = 0x6a;
        break;
      default:
        goto switchD_004096be_caseD_9c56;
      case 0x9c61:
        pvVar1 = (void *)FUN_00427f90(0x238);
        this = (undefined4 *)0x0;
        local_8 = 10;
        if (pvVar1 != (void *)0x0) {
          this = FUN_0040ef20(pvVar1,param_1);
        }
        local_8 = 0xffffffff;
        local_14 = 0x73;
        break;
      case 0x9c65:
        pvVar1 = (void *)FUN_00427f90(0x9398);
        this = (undefined4 *)0x0;
        local_8 = 0xb;
        if (pvVar1 != (void *)0x0) {
          this = FUN_00413e50(pvVar1,param_1);
        }
        local_8 = 0xffffffff;
        local_14 = 0x7b;
        break;
      case 0x9c66:
        pvVar1 = (void *)FUN_00427f90(0x23c);
        this = (undefined4 *)0x0;
        local_8 = 0xc;
        if (pvVar1 != (void *)0x0) {
          this = FUN_00413ad0(pvVar1,param_1);
        }
        local_8 = 0xffffffff;
        local_14 = 0x7c;
        break;
      case 0x9c73:
        pvVar1 = (void *)FUN_00427f90(0x460);
        this = (undefined4 *)0x0;
        local_8 = 0xd;
        if (pvVar1 != (void *)0x0) {
          this = FUN_0040fa00(pvVar1,param_1);
        }
        local_8 = 0xffffffff;
        local_14 = 0x6b;
        break;
      case 0x9c77:
        pvVar1 = (void *)FUN_00427f90(0x234);
        this = (undefined4 *)0x0;
        local_8 = 0xe;
        if (pvVar1 != (void *)0x0) {
          this = FUN_0040ee10(pvVar1,param_1);
        }
        local_8 = 0xffffffff;
        local_14 = 0x78;
        break;
      case 0x9cb4:
        pvVar1 = (void *)FUN_00427f90(0x22748);
        this = (undefined4 *)0x0;
        local_8 = 0xf;
        if (pvVar1 != (void *)0x0) {
          this = FUN_00418460(pvVar1,param_1);
        }
        local_8 = 0xffffffff;
        local_14 = 0x7e;
        break;
      case 0x9cb5:
        this = (undefined4 *)FUN_00427f90(0x234);
        local_8 = 0x10;
        if (this == (undefined4 *)0x0) {
          this = (undefined4 *)0x0;
        }
        else {
          FUN_0040e6b0(this,param_1);
          *this = &PTR_LAB_004300e8;
        }
        local_8 = 0xffffffff;
        local_14 = 0x7f;
      }
      goto LAB_00409616;
    }
    if (param_1 == 0x9c4c) {
      pvVar1 = (void *)FUN_00427f90(0x238);
      local_8 = 6;
      this = (undefined4 *)0x0;
      if (pvVar1 != (void *)0x0) {
        this = FUN_004132b0(pvVar1,0x9c4c);
      }
      local_8 = 0xffffffff;
      local_14 = 0x77;
      goto LAB_00409616;
    }
    if (param_1 == 0x79) {
      pvVar1 = (void *)FUN_00427f90(0x234);
      local_8 = 4;
      this = (undefined4 *)0x0;
      if (pvVar1 != (void *)0x0) {
        this = FUN_00418980(pvVar1,0x79);
      }
      local_8 = 0xffffffff;
      local_14 = 0x79;
      goto LAB_00409616;
    }
    if (param_1 == 0x7a) {
      pvVar1 = (void *)FUN_00427f90(0x244);
      local_8 = 5;
      this = (undefined4 *)0x0;
      if (pvVar1 != (void *)0x0) {
        this = FUN_00411ab0(pvVar1,0x7a,param_2);
      }
      local_8 = 0xffffffff;
      local_14 = 0x7a;
      goto LAB_00409616;
    }
  }
switchD_004096be_caseD_9c56:
LAB_00409616:
  if (this != (undefined4 *)0x0) {
    DAT_004321bc = 1;
    DialogBoxParamA(DAT_004344d0,(LPCSTR)(local_14 & 0xffff),param_3,(DLGPROC)&LAB_00426440,
                    (LPARAM)this);
    if (this != (undefined4 *)0x0) {
      (**(code **)*this)(1);
    }
    DAT_004321bc = 0;
  }
  FUN_00408e40();
  FUN_00408de0(0);
  *unaff_FS_OFFSET = local_10;
  return;
}


