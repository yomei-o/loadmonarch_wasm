/* 00419010 */

void __fastcall FUN_00419010(void *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar1 = 0x100;
  puVar3 = (undefined4 *)((int)param_1 + 0x22994);
  do {
    *puVar3 = 0xffffffff;
    iVar1 = iVar1 + -1;
    puVar3[0x200] = 0xffffffff;
    puVar3 = puVar3 + 2;
  } while (iVar1 != 0);
  iVar1 = 0;
  if (0 < DAT_00435dc8) {
    iVar4 = 0;
    do {
      if (*(int *)(DAT_00435db0 + iVar4) != -1) {
        iVar2 = ((int *)(DAT_00435db0 + iVar4))[0x42];
        if (iVar2 == 0) {
          iVar2 = FUN_004198a0((int)param_1);
          if (iVar2 != -1) {
            FUN_0040ec50(param_1,0x3fb,DAT_00435db0 + iVar4 + 4);
            *(undefined4 *)((int)param_1 + iVar2 * 8 + 0x22994) =
                 *(undefined4 *)(DAT_00435db0 + iVar4);
            *(int *)((int)param_1 + iVar2 * 8 + 0x22998) = iVar1;
          }
        }
        else if ((iVar2 == 1) && (iVar2 = FUN_004198c0((int)param_1), iVar2 != -1)) {
          FUN_0040ec50(param_1,0x3fc,DAT_00435db0 + iVar4 + 4);
          *(undefined4 *)((int)param_1 + iVar2 * 8 + 0x23194) =
               *(undefined4 *)(DAT_00435db0 + iVar4);
          *(int *)((int)param_1 + iVar2 * 8 + 0x23198) = iVar1;
        }
      }
      iVar4 = iVar4 + 0x220;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_00435dc8);
  }
  FUN_0040eca0(param_1,0x4aa,0x435dcc);
  return;
}


