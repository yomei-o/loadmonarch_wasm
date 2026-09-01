/* 0041afa0 */

void __cdecl FUN_0041afa0(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  
  bVar4 = 0;
  if ((param_2 != 0) &&
     ((bVar2 = *(byte *)(DAT_0043453c + -8 + (param_1 * 0x30 + param_2) * 0x18), bVar2 == 0 ||
      (4 < bVar2)))) {
    bVar4 = 1;
  }
  if ((param_2 != 0x2f) &&
     ((bVar2 = *(byte *)(DAT_0043453c + 0x28 + (param_1 * 0x30 + param_2) * 0x18), bVar2 == 0 ||
      (4 < bVar2)))) {
    bVar4 = bVar4 | 2;
  }
  iVar1 = (param_1 * 0x30 + param_2) * 0x18;
  iVar3 = DAT_0043453c + iVar1;
  bVar2 = *(byte *)(iVar3 + 0x10);
  if ((bVar2 != 0) && (bVar2 < 5)) {
    *(undefined4 *)(iVar3 + 0xc) = 100;
  }
  *(byte *)(DAT_0043453c + 0x10 + iVar1) = bVar4 + 1;
  return;
}


