/* 00408ed0 */

void FUN_00408ed0(void)

{
  LONG LVar1;
  uint uVar2;
  
  uVar2 = (uint)(DAT_0043450c != -1);
  FUN_00409db0(60000,uVar2);
  FUN_00409db0(0xea61,uVar2);
  FUN_00409db0(0xea62,uVar2);
  FUN_00409db0(0xea63,uVar2);
  FUN_00409db0(0xea65,uVar2);
  LVar1 = FUN_0040a0c0(60000);
  FUN_00409d50(60000,(uint)(LVar1 != 0));
  LVar1 = FUN_0040a0c0(0xea61);
  FUN_00409d50(0xea61,(uint)(LVar1 != 0));
  LVar1 = FUN_0040a0c0(0xea63);
  FUN_00409d50(0xea63,(uint)(LVar1 != 0));
  LVar1 = FUN_0040a0c0(0xea62);
  FUN_00409d50(0xea62,(uint)(LVar1 != 0));
  LVar1 = FUN_0040a0c0(0xea65);
  FUN_00409d50(0xea65,(uint)(LVar1 == 0));
  LVar1 = FUN_0040a0c0(0xea65);
  FUN_00409db0(0x9cad,(uint)(LVar1 != 0));
  FUN_00409d50(0x9cad,(uint)(DAT_004376a3 != '\0'));
  FUN_00409d50(0x9c70,(uint)(DAT_004376ae == '\b'));
  FUN_00409d50(0x9c71,(uint)(DAT_004376ae == '\x10'));
  FUN_00409d50(0x9c72,(uint)(DAT_004376ae == ' '));
  LVar1 = FUN_0040a0c0(60000);
  uVar2 = (uint)(LVar1 != 0);
  FUN_00409db0(0x9c70,uVar2);
  FUN_00409db0(0x9c71,uVar2);
  FUN_00409db0(0x9c72,uVar2);
  FUN_00409db0(0x9c90,uVar2);
  FUN_00409db0(0x9c91,uVar2);
  FUN_00409db0(0x9c92,uVar2);
  FUN_00409db0(0x9c93,uVar2);
  return;
}


