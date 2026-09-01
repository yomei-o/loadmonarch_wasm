/* 0041cd50 */

bool __cdecl FUN_0041cd50(undefined1 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  *(undefined4 *)(param_1 + 4) = 0x1f0;
  do {
    uVar1 = *(uint *)(DAT_0043453c + iVar3 + 8);
    if ((uVar1 < *(uint *)(param_1 + 4)) && (*(char *)(DAT_0043453c + iVar3 + 0x10) == '\x05')) {
      *(uint *)(param_1 + 4) = uVar1;
      *param_1 = (char)(iVar2 / 0x30);
      param_1[1] = (char)(iVar2 % 0x30);
    }
    iVar3 = iVar3 + 0x18;
    iVar2 = iVar2 + 1;
  } while (iVar3 < 0xd800);
  return *(uint *)(param_1 + 4) < 0x1f0;
}


