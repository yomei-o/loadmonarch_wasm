/* 0041f0d0 */

void __cdecl FUN_0041f0d0(uint param_1)

{
  uint *puVar1;
  int iVar2;
  byte *pbVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = param_1 * 0x38;
  if ((*(byte *)(DAT_00434534 + iVar2 + 4) & 1) == 0) {
    FUN_00420aa0(*(int *)(DAT_00434534 + iVar2 + 0xc),4);
  }
  if (DAT_004344e8 != (void *)0x0) {
    FUN_00424520(DAT_004344e8,param_1);
  }
  *(undefined1 *)
   (DAT_0043453c + 0x10 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  *(undefined1 *)
   (DAT_0043453c + 0x28 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  *(undefined1 *)
   (DAT_0043453c + -0x458 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  *(undefined1 *)
   (DAT_0043453c + -0x470 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  *(undefined1 *)
   (DAT_0043453c + -0x488 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  *(undefined1 *)
   (DAT_0043453c + -8 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  *(undefined1 *)
   (DAT_0043453c + 0x478 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  *(undefined1 *)
   (DAT_0043453c + 0x490 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  *(undefined1 *)
   (DAT_0043453c + 0x4a8 +
   ((uint)*(byte *)(DAT_00434534 + iVar2 + 8) * 0x30 + (uint)*(byte *)(DAT_00434534 + iVar2 + 9)) *
   0x18) = 0;
  piVar6 = (int *)(DAT_00434534 + 0x18 + (uint)*(byte *)(DAT_00434534 + iVar2 + 0x1f) * 0x38);
  *piVar6 = *piVar6 + *(int *)(DAT_00434534 + iVar2 + 0x18);
  puVar1 = (uint *)(DAT_00434534 + 0x18 + (uint)*(byte *)(DAT_00434534 + 0x1f + iVar2) * 0x38);
  if (100000 < *puVar1) {
    *puVar1 = 100000;
  }
  cVar4 = '\0';
  *(undefined4 *)(DAT_00434534 + 0x18 + iVar2) = 0;
  *(undefined1 *)(DAT_00434534 + 0x1c + iVar2) = 0;
  puVar1 = (uint *)(DAT_00434534 + 4 + iVar2);
  *puVar1 = *puVar1 | 0x40;
  FUN_00405330();
  iVar2 = 4;
  pbVar3 = (byte *)(DAT_00434534 + 4);
  do {
    if ((*pbVar3 & 0x40) != 0) {
      cVar4 = cVar4 + '\x01';
    }
    pbVar3 = pbVar3 + 0x38;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (cVar4 == '\x02') {
    iVar5 = 0;
    iVar2 = 0;
    piVar6 = &DAT_004344f8;
    do {
      if (((*(uint *)(DAT_00434534 + iVar5 + 4) & 0x40) == 0) &&
         (*(byte *)(DAT_00434534 + iVar5 + 0x1e) < 4)) {
        FUN_004095d0(0x7a,CONCAT31((int3)((uint)(iVar2 << 0x10) >> 8),1),*(HWND *)(DAT_004344e4 + 8)
                    );
        *(undefined1 *)(DAT_00434534 + 0x1e + iVar5) = 0x80;
      }
      if ((int *)*piVar6 != (int *)0x0) {
        (**(code **)(*(int *)*piVar6 + 0x1c))();
        (**(code **)(*(int *)*piVar6 + 100))();
      }
      piVar6 = piVar6 + 1;
      iVar5 = iVar5 + 0x38;
      iVar2 = iVar2 + 1;
    } while (iVar5 < 0xe0);
  }
  FUN_00408e40();
  return;
}


