/* 004056f0 */

void __cdecl FUN_004056f0(byte *param_1)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = ((uint)*param_1 * 0x30 + (uint)param_1[1]) * 0x18 + DAT_0043453c;
  bVar1 = *(byte *)(iVar2 + 0x10);
  if (bVar1 == 0x7a) {
    *(undefined1 *)(iVar2 + 4) = 0;
    return;
  }
  if (bVar1 == 0x7b) {
    *(undefined1 *)(iVar2 + 4) = 0;
    return;
  }
  if (bVar1 - 0x30 < 0x30) {
    *(undefined1 *)(iVar2 + 4) = 0;
  }
  return;
}


