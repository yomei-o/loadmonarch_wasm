/* 0040e6b0 */

undefined4 * __thiscall FUN_0040e6b0(void *this,WPARAM param_1)

{
  *(undefined ***)this = &PTR_FUN_00430250;
  *(WPARAM *)((int)this + 0x14) = param_1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x228) = 0;
  *(undefined4 *)((int)this + 0x224) = 0;
  *(undefined4 *)((int)this + 0x230) = 0;
  FUN_00409d50(param_1,1);
  ClipCursor((RECT *)0x0);
  return this;
}


