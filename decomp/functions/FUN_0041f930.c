/* 0041f930 */

undefined4 __thiscall
FUN_0041f930(void *this,LPCSTR param_1,LPVOID param_2,DWORD param_3,int param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  lstrcpyA(this,param_1);
  if (*(int *)((int)this + 0x108) != -1) {
    FUN_0041fa40(this);
  }
  bVar1 = FUN_0041f9f0(this,param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iVar2 = FUN_0041fa80(this,param_2,param_3,param_4);
    if (iVar2 != 0) {
      iVar2 = FUN_0041fa40(this);
      if (iVar2 != 0) {
        return 1;
      }
    }
  }
  return 0;
}


