/* 004271b0 */

void __thiscall FUN_004271b0(void *this,byte *param_1)

{
  if ((*param_1 < 0x30) && (param_1[1] < 0x30)) {
    *(byte *)((int)this + 0x3a4) = *param_1;
    *(byte *)((int)this + 0x3a5) = param_1[1];
  }
  return;
}


