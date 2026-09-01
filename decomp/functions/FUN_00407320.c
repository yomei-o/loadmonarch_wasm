/* 00407320 */

undefined4 FUN_00407320(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00437698;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_00436a00;
  for (iVar1 = 0x2da; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_004365a0;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  DAT_004365a0 = 0;
  DAT_004365a4 = 0xffffffff;
  DAT_00434510 = 0xffffffff;
  DAT_00434514 = 0xffffffff;
  DAT_0043781c = 0;
  DAT_004369fc = 0;
  DAT_004377fc = 0;
  DAT_004365bc = 3000;
  DAT_004365c4 = 3000;
  DAT_0043769c = 1;
  DAT_0043769d = 0;
  DAT_004376a3 = 0;
  DAT_004376a2 = 1;
  DAT_004376a4 = 1;
  DAT_004376a5 = 1;
  DAT_004376a6 = 1;
  DAT_004376ab = 1;
  DAT_004376ad = 0;
  DAT_0043769e = 1;
  DAT_0043769f = 1;
  DAT_004376a0 = 1;
  DAT_004376a1 = 1;
  DAT_004376b0 = 1;
  DAT_004376b4 = 0;
  DAT_004376b6 = 0;
  DAT_004376b7 = 0;
  DAT_00437698 = 0x19;
  DAT_004376ae = 0x10;
  DAT_004376ac = 7;
  FUN_004057b0();
  return 1;
}


