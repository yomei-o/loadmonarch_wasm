/* 00403100 */

void __cdecl FUN_00403100(int param_1)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  char local_2;
  char local_1;
  
  iVar1 = param_1 * 0x224;
  pbVar2 = (byte *)(DAT_00434538 + 0x10 + iVar1);
  *pbVar2 = *pbVar2 & 0xfb;
  *(undefined1 *)(DAT_00434538 + 0xd + iVar1) = 1;
  iVar3 = FUN_0041e560(&local_2);
  if (iVar3 == 1) {
    FUN_00405250(param_1,(int)local_2,(int)local_1);
    return;
  }
  *(undefined1 *)(DAT_00434538 + 0xc + iVar1) = 6;
  return;
}


