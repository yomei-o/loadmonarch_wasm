/* 0041d050 */

void __thiscall FUN_0041d050(void *this,int param_1,int param_2)

{
  int iVar1;
  
  *(int *)((int)this + 0x394) = param_2 + -0xea66;
  wsprintfA((LPSTR)((int)this + 0x14c),s_Cnt_d_00433fdc,param_2 + -0xea66);
  wsprintfA((LPSTR)((int)this + 0x48),s__s__s_00433fc4,s_Status_Window_00433fcc,
            &DAT_00435b31 + *(int *)((int)this + 0x394) * 0x11);
  (&DAT_004344f8)[*(int *)((int)this + 0x394)] = this;
  iVar1 = *(int *)((int)this + 0x394) << 4;
  *(int *)((int)this + 0x28) = iVar1;
  *(int *)((int)this + 0x2c) = iVar1;
  *(undefined4 *)((int)this + 0x30) = *(undefined4 *)((int)this + 0x40);
  *(undefined4 *)((int)this + 0x34) = *(undefined4 *)((int)this + 0x44);
  FUN_00425210(this,param_1,param_2);
  return;
}


