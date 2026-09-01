/* 00419290 */

void __thiscall FUN_00419290(void *this,WPARAM param_1)

{
  SendDlgItemMessageA(*(HWND *)((int)this + 4),0x3fc,0x186,param_1,0);
  if (*(int *)((int)this + param_1 * 8 + 0x23194) != -1) {
    FUN_0040ed80(this,0x442,1);
    FUN_0040ed80(this,0x443,1);
    FUN_0040eca0(this,0x46c,
                 *(int *)((int)this + param_1 * 8 + 0x23198) * 0x220 + DAT_00435db0 + 0x114);
  }
  return;
}


