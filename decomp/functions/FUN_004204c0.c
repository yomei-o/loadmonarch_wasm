/* 004204c0 */

undefined2 __thiscall FUN_004204c0(void *this,int param_1)

{
  uint uVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  for (; param_1 != 0; param_1 = param_1 + -1) {
    uVar1 = FUN_00420460((int)this);
    iVar3 = uVar1 + iVar3 * 2;
    uVar2 = (undefined2)iVar3;
  }
  return uVar2;
}


