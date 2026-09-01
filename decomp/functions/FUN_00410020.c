/* 00410020 */

void __fastcall FUN_00410020(void *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  switch(*(undefined4 *)((int)param_1 + 0x23c)) {
  case 0:
    FUN_00410680(param_1);
    break;
  case 1:
    FUN_00410910(param_1);
    break;
  case 2:
    FUN_00410be0(param_1);
    break;
  case 3:
    FUN_00410d00(param_1);
    break;
  case 4:
    FUN_00411050(param_1);
  }
  puVar4 = (undefined4 *)((int)param_1 + 0x1838);
  puVar5 = (undefined4 *)(*(int *)((int)param_1 + 0x22c) + 0xc000);
  for (iVar3 = 0x1000; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  iVar3 = 0;
  piVar6 = (int *)((int)param_1 + 0x25c);
  do {
    if ((char)piVar6[-1] != '\0') {
      if (*(int *)((int)param_1 + 0x5838) == 0) {
        iVar2 = *piVar6;
        *piVar6 = iVar2 + -1;
        if (iVar2 + -1 == 0) {
          FUN_00410200(param_1,iVar3);
        }
      }
      else {
        *(int *)((int)param_1 + 0x5838) = *(int *)((int)param_1 + 0x5838) + -1;
      }
      FUN_004104d0(param_1,iVar3);
    }
    piVar6 = piVar6 + 0x46;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x14);
  *(undefined4 *)((int)param_1 + 0x248) = 0;
  do {
    *(undefined4 *)((int)param_1 + 0x244) = 0;
    do {
      iVar3 = *(int *)((int)param_1 + 0x248) * 0x100;
      cVar1 = *(char *)(DAT_00435fd4 + iVar3 + 0x2c000 + *(int *)((int)param_1 + 0x244));
      if (cVar1 != 'p') {
        *(char *)(*(int *)((int)param_1 + 0x22c) + iVar3 + 0xc000 + *(int *)((int)param_1 + 0x244))
             = cVar1;
      }
      iVar3 = *(int *)((int)param_1 + 0x248) * 0x100;
      cVar1 = *(char *)(DAT_00435fd4 + iVar3 + 0x2c0e0 + *(int *)((int)param_1 + 0x244));
      if (cVar1 != 'p') {
        *(char *)(*(int *)((int)param_1 + 0x22c) + iVar3 + 0xc0e0 + *(int *)((int)param_1 + 0x244))
             = cVar1;
      }
      iVar3 = *(int *)((int)param_1 + 0x244) + 1;
      *(int *)((int)param_1 + 0x244) = iVar3;
    } while (iVar3 < 0x20);
    iVar3 = *(int *)((int)param_1 + 0x248) + 1;
    *(int *)((int)param_1 + 0x248) = iVar3;
  } while (iVar3 < 0x40);
  if (*(int *)((int)param_1 + 0x238) == 400) {
    FUN_0040ffe0((int)param_1);
    FUN_0040a870(0xe,0x14,6,7,s_Click_here_00433614,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
    FUN_0040a870(0xe,0x28,6,7,s_to_go_on__00433600,*(HDC *)((int)param_1 + 0x224),0,(int *)0x0);
  }
  InvalidateRect(*(HWND *)((int)param_1 + 4),(RECT *)0x0,0);
  UpdateWindow(*(HWND *)((int)param_1 + 4));
  if (*(int *)((int)param_1 + 0x238) < 1000) {
    *(int *)((int)param_1 + 0x238) = *(int *)((int)param_1 + 0x238) + 1;
  }
  return;
}


