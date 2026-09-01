/* 0041fe40 */

undefined4 __thiscall FUN_0041fe40(void *this,undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  char *pcVar3;
  uint uVar4;
  
  *(undefined4 *)((int)this + 0x214) = param_1;
  uVar4 = 0;
  while( true ) {
    iVar1 = *(int *)((int)this + 0x214);
    if (*(uint *)(iVar1 + 0xc) <= uVar4) {
      return 1;
    }
    *(undefined2 *)(iVar1 + 0x10) = **(undefined2 **)(iVar1 + 4);
    iVar1 = *(int *)((int)this + 0x214);
    uVar4 = uVar4 + *(ushort *)(iVar1 + 0x10);
    if (*(uint *)(iVar1 + 0xc) <= uVar4) break;
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 2;
    if (**(char **)(*(int *)((int)this + 0x214) + 4) == '\0') {
      FUN_00420240(this);
    }
    else {
      FUN_0041fef0((int)this);
    }
    pcVar2 = *(code **)(*(int *)((int)this + 0x214) + 0x14);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(*(int *)((int)this + 0x214));
    }
    uVar4 = uVar4 + 1;
    iVar1 = *(int *)((int)this + 0x214);
    if (*(int *)(iVar1 + 0xc) + 1U <= uVar4) {
      return 1;
    }
    pcVar3 = *(char **)(iVar1 + 4);
    *(char **)(iVar1 + 4) = pcVar3 + 1;
    if (*pcVar3 == '\0') {
      return 0;
    }
  }
  return 1;
}


