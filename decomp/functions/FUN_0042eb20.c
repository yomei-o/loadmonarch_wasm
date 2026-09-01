/* 0042eb20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0042eb20(uint param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  DWORD nStdHandle;
  
  if (param_1 < DAT_00438984) {
    piVar1 = (int *)((int)&DAT_00438990 + ((int)(param_1 & 0xffffffe7) >> 3));
    iVar2 = (param_1 & 0x1f) * 8;
    piVar3 = (int *)(*piVar1 + iVar2);
    if (((*(byte *)(piVar3 + 1) & 1) != 0) && (*piVar3 != -1)) {
      if (DAT_00434780 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_0042eb86;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_0042eb86:
      *(undefined4 *)(*piVar1 + iVar2) = 0xffffffff;
      return 0;
    }
  }
  _DAT_00434854 = 9;
  _DAT_00434858 = 0;
  return 0xffffffff;
}


