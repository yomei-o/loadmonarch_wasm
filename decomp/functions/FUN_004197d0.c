/* 004197d0 */

void __fastcall FUN_004197d0(void *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_104 [260];
  
  uVar1 = FUN_0040edd0(param_1,0x4a8);
  FUN_0040ecc0(param_1,0x4aa,(LPARAM)local_104);
  iVar2 = FUN_0040d490(&DAT_00435db0,uVar1,local_104);
  if (iVar2 != 0) {
    DAT_004376b7 = (undefined1)uVar1;
    FUN_0040d050(&DAT_00435db0,uVar1);
  }
  FUN_0040eb70((int)param_1);
  return;
}


