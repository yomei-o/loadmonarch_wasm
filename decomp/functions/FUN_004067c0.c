/* 004067c0 */

undefined4 FUN_004067c0(void)

{
  int iVar1;
  
  DAT_004365d4 = 0;
  DAT_0043451c = 0;
  DAT_004365cc = 1;
  DAT_00434510 = 0xffffffff;
  iVar1 = FUN_00405de0(DAT_00436a00);
  if (iVar1 == 0) {
    FUN_00409370(s_Failed_in_loading_map__00432198,0);
    return 0;
  }
  return 1;
}


