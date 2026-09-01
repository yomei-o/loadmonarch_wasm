/* 0041f460 */

undefined4 __cdecl FUN_0041f460(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 < 0) || (0x2f < param_1)) {
    return 1;
  }
  if ((param_2 < 0) || (0x2f < param_2)) {
    return 1;
  }
  uVar1 = (uint)*(byte *)(DAT_0043453c + 0x10 + (param_1 * 0x30 + param_2) * 0x18);
  iVar2 = uVar1 - 0x30;
  if ((-1 < iVar2) && (iVar2 < 0x30)) {
    return 0;
  }
  iVar2 = uVar1 - 0x60;
  if ((-1 < iVar2) && (iVar2 < 0x10)) {
    return 0;
  }
  return 1;
}


