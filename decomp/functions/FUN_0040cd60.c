/* 0040cd60 */

int __thiscall FUN_0040cd60(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)((int)this + 0x18)) {
    piVar2 = *(int **)this;
    do {
      if (*piVar2 == param_1) {
        return iVar1;
      }
      piVar2 = piVar2 + 0x88;
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)((int)this + 0x18));
  }
  return -1;
}


