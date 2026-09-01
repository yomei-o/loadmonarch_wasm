/* 00420460 */

uint __fastcall FUN_00420460(int param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  undefined2 *puVar3;
  undefined4 in_EAX;
  undefined2 uVar4;
  int *piVar5;
  
  uVar4 = (undefined2)((uint)in_EAX >> 0x10);
  if (*(char *)(param_1 + 0x21c) == '\0') {
    puVar3 = *(undefined2 **)(*(int *)(param_1 + 0x214) + 4);
    piVar5 = (int *)(*(int *)(param_1 + 0x214) + 4);
    uVar1 = *puVar3;
    uVar4 = (undefined2)((uint)puVar3 >> 0x10);
    *(undefined1 *)(param_1 + 0x21c) = 0x10;
    *(undefined2 *)(param_1 + 0x21a) = uVar1;
    *piVar5 = *piVar5 + 2;
    *(short *)(param_1 + 0x218) = *(short *)(param_1 + 0x218) + 2;
  }
  uVar2 = *(ushort *)(param_1 + 0x21a);
  *(char *)(param_1 + 0x21c) = *(char *)(param_1 + 0x21c) + -1;
  *(ushort *)(param_1 + 0x21a) = uVar2 >> 1;
  return CONCAT22(uVar4,uVar2) & 0xffff0001;
}


