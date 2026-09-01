/* 00427970 */

undefined4 * __thiscall FUN_00427970(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  
  InitCommonControls();
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = param_1;
  uVar1 = FUN_00427f90(0x400);
  *(undefined4 *)((int)this + 8) = uVar1;
  return this;
}


