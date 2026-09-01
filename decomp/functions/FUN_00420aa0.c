/* 00420aa0 */

void __cdecl FUN_00420aa0(int param_1,undefined1 param_2)

{
  int iVar1;
  byte *pbVar2;
  byte bVar3;
  
  iVar1 = param_1 * 0x224;
  pbVar2 = (byte *)(DAT_00434538 + 0x10 + param_1 * 0x224);
  bVar3 = *pbVar2;
  if ((bVar3 & 2) == 0) {
    *pbVar2 = bVar3 | 2;
    *(undefined1 *)(DAT_00434538 + 0xf + iVar1) = param_2;
    *(undefined1 *)(DAT_00434538 + 0xe + iVar1) = 0;
  }
  *(undefined4 *)(DAT_00434538 + 8 + iVar1) = 0;
  return;
}


