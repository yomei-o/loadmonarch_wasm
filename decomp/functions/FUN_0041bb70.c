/* 0041bb70 */

void __fastcall FUN_0041bb70(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar1 = *(int *)(param_1 + 0x10);
  piVar2 = *(int **)(param_1 + 0x14);
  iVar10 = piVar2[3];
  iVar8 = piVar2[2];
  iVar9 = piVar2[1];
  iVar11 = *piVar2;
  iVar4 = GetSystemMetrics(0x20);
  iVar3 = iVar4 * 2;
  iVar5 = GetSystemMetrics(0x21);
  iVar6 = GetSystemMetrics(0x33);
  iVar6 = iVar6 + iVar5 * 2;
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(iVar1) {
  case 3:
    break;
  case 5:
    *piVar2 = (piVar2[2] -
              *(int *)(*(int *)(*(int *)(param_1 + 0x394) + 0x1c) + 8 +
                      *(int *)(param_1 + 0x39c) * 0x10)) + iVar4 * -2;
    piVar2[1] = (piVar2[3] -
                *(int *)(*(int *)(*(int *)(param_1 + 0x394) + 0x1c) + 0xc +
                        *(int *)(param_1 + 0x39c) * 0x10)) - iVar6;
    return;
  case 7:
    iVar8 = *(int *)(param_1 + 0x394);
    iVar11 = 1;
    *(undefined4 *)(param_1 + 0x39c) = 1;
    iVar10 = (iVar10 - iVar9) - (*(int *)(iVar8 + 0x14) + iVar6);
    if (1 < *(int *)(iVar8 + 0x24)) {
      iVar9 = 0x10;
      do {
        iVar4 = *(int *)(*(int *)(iVar8 + 0x1c) + 0xc + iVar9);
        if (iVar10 == iVar4) {
          *(int *)(param_1 + 0x39c) = iVar11;
          break;
        }
        if (iVar10 < iVar4) break;
        iVar9 = iVar9 + 0x10;
        iVar11 = iVar11 + 1;
        *(int *)(param_1 + 0x39c) = *(int *)(param_1 + 0x39c) + 1;
      } while (iVar11 < *(int *)(iVar8 + 0x24));
    }
    if (iVar1 == 3) {
      piVar2[1] = (piVar2[3] -
                  *(int *)(*(int *)(param_1 + 0x39c) * 0x10 + 0xc + *(int *)(iVar8 + 0x1c))) - iVar6
      ;
      piVar2[2] = *(int *)(*(int *)(*(int *)(param_1 + 0x394) + 0x1c) + 8 +
                          *(int *)(param_1 + 0x39c) * 0x10) + *piVar2 + iVar3;
      return;
    }
    if (iVar1 == 6) {
      piVar2[3] = *(int *)(*(int *)(param_1 + 0x39c) * 0x10 + 0xc + *(int *)(iVar8 + 0x1c)) +
                  piVar2[1] + iVar6;
      piVar2[2] = *(int *)(*(int *)(*(int *)(param_1 + 0x394) + 0x1c) + 8 +
                          *(int *)(param_1 + 0x39c) * 0x10) + *piVar2 + iVar3;
      return;
    }
    return;
  case 9:
                    /* WARNING: This code block may not be properly labeled as switch case */
    piVar2[2] = *(int *)(*(int *)(*(int *)(param_1 + 0x394) + 0x1c) + 8 +
                        *(int *)(param_1 + 0x39c) * 0x10) + *piVar2 + iVar3;
    piVar2[3] = *(int *)(*(int *)(*(int *)(param_1 + 0x394) + 0x1c) + 0xc +
                        *(int *)(param_1 + 0x39c) * 0x10) + piVar2[1] + iVar6;
  default:
    return;
  }
  iVar10 = *(int *)(*(int *)(param_1 + 0x394) + 0x24);
  iVar9 = iVar10;
  if (0 < iVar10) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x394) + 0x1c);
    piVar7 = (int *)(iVar10 * 0x10 + 8 + iVar5);
    do {
      if ((iVar8 - iVar11) + iVar4 * -2 <= *piVar7) {
        iVar8 = iVar10 + -1;
        if (0 < iVar8) {
          piVar7 = (int *)(iVar8 * 0x10 + 8 + iVar5);
          goto LAB_0041bc1c;
        }
        break;
      }
      iVar9 = iVar9 + -1;
      piVar7 = piVar7 + -4;
      iVar10 = iVar10 + -1;
    } while (0 < iVar10);
  }
  goto LAB_0041bc2a;
  while( true ) {
    iVar9 = iVar9 + -1;
    piVar7 = piVar7 + -4;
    iVar8 = iVar8 + -1;
    if (iVar8 < 1) break;
LAB_0041bc1c:
    if (*piVar7 != *(int *)(iVar10 * 0x10 + 8 + iVar5)) break;
  }
LAB_0041bc2a:
  if (iVar9 == 0) {
    iVar9 = 1;
  }
  iVar10 = *(int *)(*(int *)(param_1 + 0x394) + 0x1c);
  iVar8 = (piVar2[3] - *(int *)(iVar9 * 0x10 + 0xc + iVar10)) - iVar6;
  if (iVar8 < 0) {
    piVar2[1] = (piVar2[3] - *(int *)(*(int *)(param_1 + 0x39c) * 0x10 + 0xc + iVar10)) - iVar6;
  }
  else {
    piVar2[1] = iVar8;
    *(int *)(param_1 + 0x39c) = iVar9;
  }
  if (iVar1 != 1) {
    piVar2[2] = *(int *)(*(int *)(*(int *)(param_1 + 0x394) + 0x1c) + 8 +
                        *(int *)(param_1 + 0x39c) * 0x10) + *piVar2 + iVar3;
    return;
  }
  *piVar2 = (piVar2[2] -
            *(int *)(*(int *)(*(int *)(param_1 + 0x394) + 0x1c) + 8 +
                    *(int *)(param_1 + 0x39c) * 0x10)) + iVar4 * -2;
  return;
}


