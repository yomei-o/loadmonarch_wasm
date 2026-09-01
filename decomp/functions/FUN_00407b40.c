/* 00407b40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00407b40(int *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  int *piVar4;
  int iVar5;
  byte *pbVar6;
  void *this;
  LONG LVar7;
  uint uVar8;
  
  uVar3 = DAT_004376b6;
  uVar8 = param_1[4];
  if (uVar8 < 0x9c56) {
    if ((uVar8 < 0x9c54) && (uVar8 != 0x9c4c)) {
      FUN_00408e40();
      return;
    }
  }
  else if (uVar8 < 0x9c62) {
    if (uVar8 != 0x9c61) {
      if (uVar8 == 0x9c5e) {
        FUN_00408db0();
        FUN_00408e40();
        return;
      }
      FUN_00408e40();
      return;
    }
  }
  else if (uVar8 < 0x9c6d) {
    if (uVar8 == 0x9c6c) {
      (**(code **)(*param_1 + 0x3c))();
      FUN_00408e40();
      return;
    }
    if (uVar8 < 0x9c65) goto switchD_00407c3c_caseD_9c7f;
    if (0x9c66 < uVar8) {
      if (uVar8 == 0x9c67) {
        FUN_004093b0();
        FUN_00408e40();
        return;
      }
      FUN_00408e40();
      return;
    }
  }
  else {
    if (uVar8 < 0x9c73) {
      if (uVar8 < 0x9c70) {
        if (uVar8 == 0x9c6d) {
          FUN_00408d80();
          FUN_00408e40();
          return;
        }
        FUN_00408e40();
        return;
      }
      if (uVar8 == 0x9c70) {
        DAT_004376ae = 8;
      }
      else if (uVar8 == 0x9c71) {
        DAT_004376ae = 0x10;
      }
      else {
        if (uVar8 != 0x9c72) {
          return;
        }
        DAT_004376ae = 0x20;
      }
      piVar4 = (int *)FUN_0040a0c0(60000);
      if (piVar4 != (int *)0x0) {
        if ((uint)DAT_004376ae == piVar4[0xe6]) {
          return;
        }
        (**(code **)(*piVar4 + 0x3c))();
      }
      FUN_00408590(param_1,60000);
      FUN_00408e40();
      return;
    }
    if (0x9c77 < uVar8) {
      if (uVar8 < 0x9c94) {
        if (uVar8 < 0x9c90) {
          switch(uVar8) {
          case 0x9c7d:
            if ((DAT_004365dc != 1) && (DAT_004365dc != 5)) {
              iVar5 = FUN_00409e90();
              if (iVar5 == 0) {
                DAT_004365dc = 0;
                FUN_00408e40();
                FUN_00408e40();
                return;
              }
              FUN_00409d50(0x9c7d,1);
              FUN_0040a1c0(90000);
              DAT_004365dc = 1;
              DAT_004321c8 = DAT_004321c8 | 1;
              FUN_00408e40();
              FUN_00408e40();
              return;
            }
            FUN_00409f90();
            return;
          case 0x9c7e:
            if ((DAT_004365dc != 1) && (DAT_004365dc != 5)) {
              iVar5 = FUN_00409f10();
              if (iVar5 == 0) {
                DAT_004365dc = 0;
                FUN_00408e40();
                FUN_00408e40();
                return;
              }
              FUN_00409d50(0x9c7e,1);
              FUN_0040a1c0(90000);
              DAT_004365dc = 1;
              DAT_004321c8 = DAT_004321c8 | 2;
              FUN_00408e40();
              FUN_00408e40();
              return;
            }
            FUN_00409f90();
            return;
          case 0x9c82:
            DAT_004376b6 = 0;
            FUN_00409570();
            DAT_004376b6 = uVar3;
            FUN_00408e40();
            return;
          case 0x9c83:
            FUN_004095d0(0x69,0,(HWND)param_1[2]);
            FUN_00408e40();
            return;
          case 0x9c84:
            FUN_004095d0(0x69,1,(HWND)param_1[2]);
            FUN_00408e40();
            return;
          case 0x9c85:
            FUN_004095d0(0x69,2,(HWND)param_1[2]);
            FUN_00408e40();
            return;
          case 0x9c86:
            FUN_004095d0(0x69,3,(HWND)param_1[2]);
            FUN_00408e40();
            return;
          case 0x9c87:
            FUN_004095d0(0x72,0,(HWND)param_1[2]);
            FUN_00408e40();
            return;
          }
        }
        else {
          iVar5 = *(int *)(DAT_00434534 + -0x223f74 + uVar8 * 0x38);
          if (iVar5 != 0x40) {
            if (DAT_004321c4 != 0x40) {
              *(undefined1 *)(DAT_00434538 + 0x220 + DAT_004321c4 * 0x224) = 0xff;
              DAT_004321c4 = 0x40;
              FUN_00408de0(0);
            }
            pbVar6 = (byte *)(iVar5 * 0x224 + DAT_00434538);
            bVar1 = *pbVar6;
            bVar2 = pbVar6[1];
            pbVar6[0x220] = 0xc;
            DAT_004321b8 = 0;
            DAT_004321c0 = 1;
            DAT_004321c4 = iVar5;
            FUN_00408de0(1);
            this = (void *)FUN_0040a0c0(60000);
            if (this != (void *)0x0) {
              FUN_00423f90(this,(uint)bVar1,(uint)bVar2,(undefined4 *)0x0,0);
              FUN_00408e40();
              return;
            }
          }
        }
      }
      else {
        if (uVar8 < 0xc351) {
          if (uVar8 != 50000) {
            switch(uVar8) {
            case 0x9cac:
              FUN_00408940((int)param_1);
              FUN_00408e40();
              return;
            case 0x9cad:
              piVar4 = (int *)FUN_0040a0c0(0xea65);
              if (piVar4 != (int *)0x0) {
                DAT_004376a3 = DAT_004376a3 + 1 & 1;
                (**(code **)(*piVar4 + 0x3c))();
                FUN_00408590(param_1,0xea65);
                FUN_00408e40();
                return;
              }
              break;
            case 0x9cae:
              FUN_00408d50();
              FUN_00408e40();
              return;
            case 0x9caf:
              FUN_0040a4b0();
              FUN_00408e40();
              return;
            case 0x9cb1:
              LVar7 = FUN_0040a0c0(60000);
              if (LVar7 != 0) {
                FUN_004247b0();
                FUN_00408e40();
                return;
              }
              break;
            case 0x9cb2:
              FUN_00408b80();
              FUN_00408e40();
              return;
            case 0x9cb4:
            case 0x9cb5:
              goto switchD_00407c5e_caseD_9cb4;
            case 0x9cb7:
              FUN_0040a2f0();
              FUN_00408e40();
              return;
            case 0x9cb8:
              FUN_0040b0a0();
              FUN_00408e40();
              return;
            }
            goto switchD_00407c3c_caseD_9c7f;
          }
        }
        else {
          if (0xea63 < uVar8) {
            if (uVar8 < 0xee4c) {
              if (uVar8 < 61000) {
                if (0xea64 < uVar8) {
                  if (0xea69 < uVar8) {
                    FUN_00408e40();
                    return;
                  }
                  goto LAB_00408161;
                }
                goto switchD_00407c3c_caseD_9c7f;
              }
            }
            else {
              if (uVar8 < 0xee4d) goto switchD_00407c3c_caseD_9c7f;
              if (0xee51 < uVar8) {
                FUN_00408e40();
                return;
              }
            }
            FUN_00408b30(uVar8 - 1000);
            goto switchD_00407c3c_caseD_9c7f;
          }
          if (59999 < uVar8) {
LAB_00408161:
            FUN_00408590(param_1,uVar8);
            FUN_00408e40();
            return;
          }
          if (uVar8 < 0xc353) goto switchD_00407c3c_caseD_9c7f;
          if (0xc362 < uVar8) {
            FUN_00408e40();
            return;
          }
        }
        DAT_004365e4 = uVar8 - 50000;
        _DAT_004365e0 = (uint)(char)(&DAT_00434444)[(param_1[4] - 50000U) / 3];
        uVar8 = (param_1[4] - 50000U) % 3;
        if (uVar8 == 1) {
          _DAT_004365e0 = _DAT_004365e0 | 0x50;
        }
        if (uVar8 == 2) {
          _DAT_004365e0 = _DAT_004365e0 | 0x90;
          FUN_00408e40();
          return;
        }
      }
switchD_00407c3c_caseD_9c7f:
      FUN_00408e40();
      return;
    }
    if ((uVar8 != 0x9c77) && (uVar8 != 0x9c73)) {
      FUN_00408e40();
      return;
    }
  }
switchD_00407c5e_caseD_9cb4:
  FUN_004095d0(uVar8,0,(HWND)param_1[2]);
  FUN_00408e40();
  return;
}


