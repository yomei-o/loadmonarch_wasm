/* 00423760 */

undefined4 __thiscall FUN_00423760(void *this,int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = 0;
  if ((param_1 < 0x30) && (param_2 < 0x30)) {
    iVar3 = 0;
    iVar4 = 0;
    *(char *)((int)this + 0x3c2) = (char)param_1;
    *(char *)((int)this + 0x3c3) = (char)param_2;
    do {
      if ((*(byte *)(DAT_00434538 + 0x21c + iVar4) & 1) != 0) {
        iVar1 = FUN_004237e0(iVar3,(byte *)((int)this + 0x3c2));
        if (iVar1 == 1) {
          uVar2 = 1;
        }
      }
      iVar4 = iVar4 + 0x224;
      iVar3 = iVar3 + 1;
    } while (iVar4 < 0x8900);
    return uVar2;
  }
  return 0;
}


