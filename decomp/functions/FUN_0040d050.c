/* 0040d050 */

undefined4 __thiscall FUN_0040d050(void *this,undefined4 param_1)

{
  int iVar1;
  CHAR local_208 [260];
  CHAR local_104 [260];
  
  wsprintfA(local_104,s_USnd_02d_cfg_004325a8,param_1);
  FUN_00409490(local_208,s_SAVE__004325a0,local_104);
  iVar1 = FUN_0040d0e0(this,local_208);
  if (iVar1 == 0) {
    FUN_00409490(local_208,s_Sound__0043258c,s_Sound_cfg_00432594);
    FUN_0040d0e0(this,local_208);
    return 0;
  }
  return 1;
}


