/* 0041cce0 */

bool __cdecl FUN_0041cce0(undefined1 *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 0;
  *(undefined4 *)(param_1 + 4) = 0x1f0;
  do {
    uVar2 = *(uint *)(DAT_0043453c + iVar4 + 8);
    if (uVar2 < *(uint *)(param_1 + 4)) {
      bVar1 = *(byte *)(DAT_0043453c + iVar4 + 0x10);
      if ((bVar1 != 0) && (bVar1 < 5)) {
        *(uint *)(param_1 + 4) = uVar2;
        *param_1 = (char)(iVar3 / 0x30);
        param_1[1] = (char)(iVar3 % 0x30);
      }
    }
    iVar4 = iVar4 + 0x18;
    iVar3 = iVar3 + 1;
  } while (iVar4 < 0xd800);
  return *(uint *)(param_1 + 4) < 0x1f0;
}


