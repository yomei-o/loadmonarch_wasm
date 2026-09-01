/* 004215a0 */

undefined4 __cdecl FUN_004215a0(int param_1)

{
  int iVar1;
  
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  *(undefined2 *)(DAT_00434538 + 2 + DAT_0043756c * 0x224) =
       *(undefined2 *)(DAT_00434538 + param_1 * 0x224);
  iVar1 = DAT_0043756c * 0x224 + DAT_00434538;
  iVar1 = FUN_00405000(DAT_0043756c,(uint)*(byte *)(iVar1 + 2),(uint)*(byte *)(iVar1 + 3));
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = 2;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  return 1;
}


