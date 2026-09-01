/* 00426900 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00426900(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  LPCSTR pCVar11;
  uint local_14;
  uint local_8;
  int local_4;
  
  if (DAT_004344e8 != (void *)0x0) {
    FUN_004249f0(DAT_004344e8,&local_8);
    iVar4 = *(int *)(param_1 + 0x20);
    iVar2 = (local_8 * 0x30 + local_4) * 0x18;
    uVar5 = (uint)*(byte *)(DAT_0043453c + 0x10 + iVar2);
    iVar8 = uVar5 << 10;
    iVar3 = 0;
    do {
      puVar9 = (undefined4 *)(DAT_00436454 + iVar8);
      iVar8 = iVar8 + 0x20;
      puVar10 = (undefined4 *)
                (*(int *)(param_1 + 0x20) * iVar3 + *(int *)(param_1 + 0x25c) + iVar4 * 0x70 + 0x10)
      ;
      for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x20);
    iVar4 = *(int *)(param_1 + 0x20);
    iVar3 = 0;
    do {
      iVar8 = *(int *)(param_1 + 0x20) * iVar3;
      iVar3 = iVar3 + 1;
      puVar9 = (undefined4 *)(iVar8 + *(int *)(param_1 + 0x25c) + iVar4 * 0x78 + 0x40);
      for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar9 = 0x70707070;
        puVar9 = puVar9 + 1;
      }
    } while (iVar3 < 0x10);
    iVar4 = uVar5 - 8;
    if ((iVar4 < 0) || (3 < iVar4)) {
      iVar4 = *(int *)(DAT_0043453c + 0xc + iVar2);
      local_14 = (uint)(iVar4 * 0x1e) / 0xff;
      wsprintfA((LPSTR)(param_1 + 0x3a6),s_DEF__6d_004345ac,iVar4);
      iVar4 = *(int *)(param_1 + 0x20);
      iVar3 = 0;
      do {
        iVar8 = *(int *)(param_1 + 0x20) * iVar3;
        iVar3 = iVar3 + 1;
        puVar9 = (undefined4 *)(iVar8 + *(int *)(param_1 + 0x25c) + iVar4 * 0x90 + 0x40);
        for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar9 = 0x70707070;
          puVar9 = puVar9 + 1;
        }
      } while (iVar3 < 0x10);
    }
    else {
      iVar4 = *(int *)(DAT_0043453c + 0xc + iVar2);
      local_14 = (uint)(iVar4 * 0x1e) / 0x90;
      wsprintfA((LPSTR)(param_1 + 0x3a6),s_NUM__6d_004345b8,iVar4);
      iVar4 = *(int *)(param_1 + 0x20);
      iVar3 = 0;
      do {
        iVar8 = *(int *)(param_1 + 0x20) * iVar3;
        iVar3 = iVar3 + 1;
        puVar9 = (undefined4 *)(iVar8 + *(int *)(param_1 + 0x25c) + iVar4 * 0x90 + 0x40);
        for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar9 = 0x70707070;
          puVar9 = puVar9 + 1;
        }
      } while (iVar3 < 0x10);
      iVar4 = lstrlenA(&DAT_00435b86 + (_DAT_004365e0 & 0xf) * 0x11);
      iVar3 = 0xc;
      if (iVar4 < 0xd) {
        iVar3 = lstrlenA(&DAT_00435b86 + (_DAT_004365e0 & 0xf) * 0x11);
      }
      TextOutA(*(HDC *)(param_1 + 0x254),0x40,0x90,&DAT_00435b86 + (_DAT_004365e0 & 0xf) * 0x11,
               iVar3);
    }
    iVar4 = lstrlenA((LPCSTR)(param_1 + 0x3a6));
    iVar3 = 0xc;
    if (iVar4 < 0xd) {
      iVar3 = lstrlenA((LPCSTR)(param_1 + 0x3a6));
    }
    TextOutA(*(HDC *)(param_1 + 0x254),0x40,0x78,(LPCSTR)(param_1 + 0x3a6),iVar3);
    if (0x1e < local_14) {
      local_14 = 0x1e;
    }
    uVar5 = *(uint *)(param_1 + 0x3a0);
    while (uVar5 != local_14) {
      iVar3 = *(int *)(param_1 + 0x3a0);
      iVar8 = iVar3 % 10;
      iVar4 = (iVar8 + *(int *)(param_1 + 0x20) * 0xc) * 8 + 0x48;
      if (iVar3 < (int)local_14) {
        iVar6 = 0;
        do {
          puVar10 = (undefined4 *)
                    (*(int *)(param_1 + 0x20) * iVar6 + *(int *)(param_1 + 0x25c) + iVar4);
          puVar9 = (undefined4 *)
                   (iVar6 * 0x100 + ((iVar3 / 10 + 4) * 0x200 + iVar8) * 8 + DAT_00435fd4);
          iVar6 = iVar6 + 1;
          *puVar10 = *puVar9;
          puVar10[1] = puVar9[1];
        } while (iVar6 < 0x10);
        *(int *)(param_1 + 0x3a0) = *(int *)(param_1 + 0x3a0) + 1;
      }
      else {
        iVar6 = 0;
        do {
          puVar10 = (undefined4 *)
                    (*(int *)(param_1 + 0x20) * iVar6 + *(int *)(param_1 + 0x25c) + iVar4);
          puVar9 = (undefined4 *)
                   (iVar6 * 0x100 + ((iVar3 / 10 + 3) * 0x200 + iVar8) * 8 + DAT_00435fd4);
          iVar6 = iVar6 + 1;
          *puVar10 = *puVar9;
          puVar10[1] = puVar9[1];
        } while (iVar6 < 0x10);
        *(int *)(param_1 + 0x3a0) = *(int *)(param_1 + 0x3a0) + -1;
      }
      uVar5 = *(uint *)(param_1 + 0x3a0);
    }
    if (*(byte *)(DAT_0043453c + iVar2) < 0x40) {
      *(uint *)(param_1 + 0x394) = (uint)*(byte *)(DAT_0043453c + iVar2);
    }
    if (*(char *)(DAT_00434538 + 0x10 + *(int *)(param_1 + 0x394) * 0x224) == -0x80) {
      *(undefined4 *)(param_1 + 0x394) = 0x40;
    }
    if (*(uint *)(param_1 + 0x394) < 0x40) {
      uVar5 = FUN_0041b520(*(uint *)(param_1 + 0x394));
      iVar4 = *(int *)(param_1 + 0x20);
      iVar8 = 0;
      iVar3 = 0;
      do {
        iVar3 = iVar3 + 0x20;
        puVar9 = (undefined4 *)(DAT_00436440 + uVar5 * 0x400 + -0x20 + iVar3);
        puVar10 = (undefined4 *)
                  (*(int *)(param_1 + 0x20) * iVar8 + *(int *)(param_1 + 0x25c) +
                  iVar4 * 0x30 + 0x10);
        for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        }
        iVar8 = iVar8 + 1;
      } while (iVar3 < 0x400);
      bVar1 = *(byte *)(DAT_00434538 + 0x220 + *(int *)(param_1 + 0x394) * 0x224);
      if (bVar1 == 0xff) {
        iVar4 = *(int *)(param_1 + 0x20);
        iVar3 = 0;
        do {
          puVar9 = (undefined4 *)
                   (*(int *)(param_1 + 0x20) * iVar3 + *(int *)(param_1 + 0x25c) +
                   (iVar4 + 1) * 0x10);
          for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar9 = 0x70707070;
            puVar9 = puVar9 + 1;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 0x20);
      }
      else {
        iVar8 = 0;
        iVar4 = *(int *)(param_1 + 0x20);
        iVar3 = (uint)bVar1 * 0x2000 + 0xe0;
        do {
          iVar6 = *(int *)(param_1 + 0x20) * iVar8;
          puVar9 = (undefined4 *)(DAT_00435fd4 + iVar3);
          iVar3 = iVar3 + 0x100;
          iVar8 = iVar8 + 1;
          puVar10 = (undefined4 *)(iVar6 + *(int *)(param_1 + 0x25c) + (iVar4 + 1) * 0x10);
          for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
        } while (iVar8 < 0x20);
      }
      iVar4 = *(int *)(param_1 + 0x20);
      iVar3 = 0;
      do {
        puVar9 = (undefined4 *)
                 (*(int *)(param_1 + 0x20) * iVar3 + *(int *)(param_1 + 0x25c) + (iVar4 + 1) * 0x40)
        ;
        for (iVar8 = 0x18; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar9 = 0x70707070;
          puVar9 = puVar9 + 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x10);
      bVar1 = *(byte *)(DAT_00434538 + 0xd + *(int *)(param_1 + 0x394) * 0x224);
      if ((bVar1 & 0x20) == 0) {
        bVar1 = bVar1 & 0xf;
        if (bVar1 == 0xe) {
          pCVar11 = &DAT_00435c85;
        }
        else {
          pCVar11 = &DAT_00435b86 + (uint)bVar1 * 0x11;
        }
      }
      else {
        pCVar11 = &DAT_00435c63;
      }
      wsprintfA((LPSTR)(param_1 + 0x3a6),pCVar11);
      iVar4 = lstrlenA((LPCSTR)(param_1 + 0x3a6));
      iVar3 = 0xc;
      if (iVar4 < 0xd) {
        iVar3 = lstrlenA((LPCSTR)(param_1 + 0x3a6));
      }
      iVar8 = 0;
      TextOutA(*(HDC *)(param_1 + 0x254),0x40,0x40,(LPCSTR)(param_1 + 0x3a6),iVar3);
      iVar4 = *(int *)(param_1 + 0x20);
      do {
        puVar9 = (undefined4 *)
                 (*(int *)(param_1 + 0x20) * iVar8 + *(int *)(param_1 + 0x25c) + iVar4 * 0x28 + 0x40
                 );
        for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar9 = 0x70707070;
          puVar9 = puVar9 + 1;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < 0x10);
      wsprintfA((LPSTR)(param_1 + 0x3a6),s_STR__6d_004345a0,
                *(undefined4 *)(DAT_00434538 + 8 + *(int *)(param_1 + 0x394) * 0x224));
      iVar4 = lstrlenA((LPCSTR)(param_1 + 0x3a6));
      iVar3 = 0xc;
      if (iVar4 < 0xd) {
        iVar3 = lstrlenA((LPCSTR)(param_1 + 0x3a6));
      }
      TextOutA(*(HDC *)(param_1 + 0x254),0x40,0x28,(LPCSTR)(param_1 + 0x3a6),iVar3);
      uVar5 = *(uint *)(DAT_00434538 + 8 + *(int *)(param_1 + 0x394) * 0x224);
      if (uVar5 < 1000) {
        local_14 = (uVar5 * 10) / 1000;
      }
      else if (uVar5 < 10000) {
        local_14 = (uVar5 * 10) / 10000 + 10;
      }
      else {
        local_14 = (uVar5 * 10) / 100000 + 0x14;
      }
      if (0x1e < local_14) {
        local_14 = 0x1e;
      }
      uVar5 = *(uint *)(param_1 + 0x39c);
      while (uVar5 != local_14) {
        iVar3 = *(int *)(param_1 + 0x39c);
        iVar8 = iVar3 % 10;
        iVar4 = (iVar8 + *(int *)(param_1 + 0x20) * 2) * 8 + 0x48;
        if (iVar3 < (int)local_14) {
          iVar6 = 0;
          do {
            puVar10 = (undefined4 *)
                      (*(int *)(param_1 + 0x20) * iVar6 + *(int *)(param_1 + 0x25c) + iVar4);
            puVar9 = (undefined4 *)
                     (iVar6 * 0x100 + ((iVar3 / 10 + 4) * 0x200 + iVar8) * 8 + DAT_00435fd4);
            iVar6 = iVar6 + 1;
            *puVar10 = *puVar9;
            puVar10[1] = puVar9[1];
          } while (iVar6 < 0x10);
          *(int *)(param_1 + 0x39c) = *(int *)(param_1 + 0x39c) + 1;
        }
        else {
          iVar6 = 0;
          do {
            puVar10 = (undefined4 *)
                      (*(int *)(param_1 + 0x20) * iVar6 + *(int *)(param_1 + 0x25c) + iVar4);
            puVar9 = (undefined4 *)
                     (iVar6 * 0x100 + ((iVar3 / 10 + 3) * 0x200 + iVar8) * 8 + DAT_00435fd4);
            iVar6 = iVar6 + 1;
            *puVar10 = *puVar9;
            puVar10[1] = puVar9[1];
          } while (iVar6 < 0x10);
          *(int *)(param_1 + 0x39c) = *(int *)(param_1 + 0x39c) + -1;
        }
        uVar5 = *(uint *)(param_1 + 0x39c);
      }
    }
    else {
      iVar4 = *(int *)(param_1 + 0x20);
      iVar3 = 0;
      do {
        puVar9 = (undefined4 *)
                 (*(int *)(param_1 + 0x20) * iVar3 + *(int *)(param_1 + 0x25c) + (iVar4 + 1) * 0x10)
        ;
        for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar9 = 0x70707070;
          puVar9 = puVar9 + 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x40);
      iVar3 = 0;
      iVar4 = (*(int *)(param_1 + 0x20) + 1) * 0x40;
      do {
        puVar9 = (undefined4 *)
                 (*(int *)(param_1 + 0x20) * iVar3 + *(int *)(param_1 + 0x25c) + iVar4);
        for (iVar8 = 0x18; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar9 = 0x70707070;
          puVar9 = puVar9 + 1;
        }
        puVar9 = (undefined4 *)
                 ((iVar3 + -0x18) * *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x25c) + iVar4);
        for (iVar8 = 0x18; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar9 = 0x70707070;
          puVar9 = puVar9 + 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x10);
      iVar4 = *(int *)(param_1 + 0x39c);
      iVar3 = *(int *)(param_1 + 0x20);
      if (iVar4 != 0) {
        iVar8 = 0;
        do {
          puVar10 = (undefined4 *)
                    (*(int *)(param_1 + 0x20) * iVar8 + *(int *)(param_1 + 0x25c) +
                    (iVar4 % 10 + iVar3 * 2) * 8 + 0x48);
          puVar9 = (undefined4 *)
                   (iVar8 * 0x100 + ((iVar4 / 10 + 3) * 0x200 + iVar4 % 10) * 8 + DAT_00435fd4);
          iVar8 = iVar8 + 1;
          *puVar10 = *puVar9;
          puVar10[1] = puVar9[1];
        } while (iVar8 < 0x10);
        *(int *)(param_1 + 0x39c) = *(int *)(param_1 + 0x39c) + -1;
      }
    }
    if (DAT_004365dc != 0) {
      iVar4 = *(int *)(param_1 + 0x20);
      iVar3 = 0;
      do {
        puVar9 = (undefined4 *)
                 (*(int *)(param_1 + 0x20) * iVar3 + *(int *)(param_1 + 0x25c) + (iVar4 + 1) * 0x40)
        ;
        for (iVar8 = 0x18; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar9 = 0x70707070;
          puVar9 = puVar9 + 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x10);
      iVar4 = *(int *)(DAT_0043453c + 8 + iVar2);
      if (iVar4 == 0x1f0) {
        wsprintfA((LPSTR)(param_1 + 0x3a6),s_DIS________00434594);
      }
      else {
        wsprintfA((LPSTR)(param_1 + 0x3a6),s_DIS___d_0043458c,iVar4);
      }
      iVar4 = lstrlenA((LPCSTR)(param_1 + 0x3a6));
      iVar2 = 0xc;
      if (iVar4 < 0xd) {
        iVar2 = lstrlenA((LPCSTR)(param_1 + 0x3a6));
      }
      TextOutA(*(HDC *)(param_1 + 0x254),0x40,0x40,(LPCSTR)(param_1 + 0x3a6),iVar2);
    }
  }
  return;
}


