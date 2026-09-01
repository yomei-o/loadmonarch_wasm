/* 0040bcf0 */

void __thiscall FUN_0040bcf0(void *this,undefined2 *param_1)

{
  UINT UVar1;
  
  *(undefined2 *)this = *param_1;
  *(undefined1 *)((int)this + 2) = *(undefined1 *)(param_1 + 1);
  *(undefined1 *)((int)this + 3) = 0;
  UVar1 = GetDriveTypeA(this);
  *(UINT *)((int)this + 0x130) = UVar1;
  if (UVar1 == 5) {
    FUN_0040bd30((int)this);
  }
  return;
}


