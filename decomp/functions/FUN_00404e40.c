/* 00404e40 */

void __fastcall FUN_00404e40(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  LPSTR pCVar5;
  char *pcVar6;
  undefined8 uVar7;
  
  if (*(int *)(param_1 + 0x524) != 0) {
    uVar4 = 0;
    pCVar5 = (LPSTR)(param_1 + 0x528);
    do {
      uVar2 = (int)uVar4 >> 0x1f;
      iVar1 = (int)uVar4 / 2;
      if (((uVar4 ^ uVar2) - uVar2 & 1 ^ uVar2) == uVar2) {
        _sprintf(pCVar5,s__s_Area_Occupied__3_2f_004320dc,&DAT_00435b31 + iVar1 * 0x11,
                 (double)*(float *)(DAT_00434534 + 0x34 + iVar1 * 0x38));
      }
      else {
        wsprintfA(pCVar5,s__s_Funds__d_004320f4,&DAT_00435b31 + iVar1 * 0x11);
      }
      pCVar5 = pCVar5 + 0x100;
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 8);
    uVar4 = 0;
    pCVar5 = (LPSTR)(param_1 + 0xd28);
    do {
      uVar2 = (int)uVar4 >> 0x1f;
      iVar1 = (int)uVar4 / 2;
      iVar3 = iVar1 * 0x38 + DAT_00434534;
      if ((*(byte *)(iVar3 + 4) & 0x40) == 0) {
        if (((uVar4 ^ uVar2) - uVar2 & 1 ^ uVar2) == uVar2) {
          uVar7 = CONCAT44(*(undefined4 *)(DAT_00434538 + 8 + *(int *)(iVar3 + 0xc) * 0x224),
                           &DAT_00435b31 + iVar1 * 0x11);
          pcVar6 = s__s_Leader_Strength__d_004320b8;
        }
        else {
          uVar7 = CONCAT44(*(undefined4 *)(iVar3 + 0x10),&DAT_00435b31 + iVar1 * 0x11);
          pcVar6 = s__s_Unit_Totals__d_004320a4;
        }
        wsprintfA(pCVar5,pcVar6,uVar7);
      }
      else {
        wsprintfA(pCVar5,s__s_Defeated_004320d0);
      }
      pCVar5 = pCVar5 + 0x100;
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 8);
    if (*(int *)(DAT_00434534 + 0xf0) == 0) {
      wsprintfA((LPSTR)(param_1 + 0x1528),s__s_Defeated_004320d0);
    }
    else {
      wsprintfA((LPSTR)(param_1 + 0x1528),s__s_Unit_and_Base_Totals__d_00432088,&DAT_00435b75);
    }
    InvalidateRect((HWND)**(undefined4 **)(param_1 + 0x524),(RECT *)0x0,0);
    UpdateWindow((HWND)**(undefined4 **)(param_1 + 0x524));
  }
  return;
}


