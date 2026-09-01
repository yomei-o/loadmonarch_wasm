/* 0040bcb0 */

undefined1 * __fastcall FUN_0040bcb0(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = 0x19;
  *(undefined4 *)(param_1 + 0x134) = 0;
  puVar1 = param_1;
  do {
    puVar1[0xc] = 0;
    iVar2 = iVar2 + -1;
    *(undefined4 *)(puVar1 + 4) = 0xffffffff;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
    puVar1 = puVar1 + 0xc;
  } while (iVar2 != 0);
  return param_1;
}


