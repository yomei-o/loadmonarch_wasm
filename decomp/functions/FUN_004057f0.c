/* 004057f0 */

undefined4 FUN_004057f0(void)

{
  int iVar1;
  CHAR local_208 [260];
  CHAR local_104 [260];
  
  FUN_00405790(s_Score_v11_0043210c,local_208);
  iVar1 = FUN_0040bda0(&DAT_00436468,local_104,local_208);
  if (iVar1 != 0) {
    iVar1 = FUN_0040c0d0(local_104,&DAT_00436a00,0xb68);
    if (iVar1 != 0) {
      DAT_004376b5 = 1;
      return 1;
    }
  }
  return 0;
}


