/* 00405860 */

undefined4 FUN_00405860(void)

{
  int iVar1;
  undefined4 *puVar2;
  CHAR local_208 [260];
  CHAR local_104 [260];
  
  FUN_00405790(s_Score_v11_0043210c,local_208);
  iVar1 = FUN_0040bda0(&DAT_00436468,local_104,local_208);
  if (iVar1 == 0) {
    puVar2 = &DAT_00436a00;
    for (iVar1 = 0x2da; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    return 0;
  }
  iVar1 = FUN_0040c010(local_104,&DAT_00436a00,0xb68);
  if (iVar1 == 0) {
    puVar2 = &DAT_00436a00;
    for (iVar1 = 0x2da; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    return 0;
  }
  FUN_0041b240();
  return 1;
}


