/* 0040a6f0 */

void FUN_0040a6f0(void)

{
  int iVar1;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  iVar1 = (int)(char)(&DAT_004321d0)[DAT_00435b1c & 0xf];
  local_2 = (undefined1)((int)((uint)DAT_0043756a * iVar1) / 100);
  local_4 = (undefined1)((int)((uint)DAT_00437568 * iVar1) / 100);
  local_1 = 1;
  local_3 = (undefined1)((int)((uint)DAT_00437569 * iVar1) / 100);
  FUN_0040e560(&DAT_004365f0,&local_4,0x1f,1);
  local_2 = (undefined1)((int)((uint)DAT_0043768c._2_1_ * iVar1) / 100);
  local_4 = (undefined1)((int)((uint)(byte)DAT_0043768c * iVar1) / 100);
  local_1 = 1;
  local_3 = (undefined1)((int)((uint)DAT_0043768c._1_1_ * iVar1) / 100);
  FUN_0040e560(&DAT_004365f0,&local_4,0x76,1);
  FUN_0040e600(0x4365f0);
  if (DAT_004344e8 != (int *)0x0) {
    (**(code **)(*DAT_004344e8 + 0x10))();
  }
  if (DAT_004344f0 != (int *)0x0) {
    (**(code **)(*DAT_004344f0 + 0x10))();
  }
  if (DAT_004344ec != (int *)0x0) {
    (**(code **)(*DAT_004344ec + 0x10))();
  }
  return;
}


