/* 0041f3f0 */

bool __cdecl FUN_0041f3f0(int param_1,int param_2)

{
  uint uVar1;
  
  if ((param_1 < 0) || (0x2f < param_1)) {
    return true;
  }
  if ((param_2 < 0) || (0x2f < param_2)) {
    return true;
  }
  uVar1 = (uint)*(byte *)(DAT_0043453c + 0x10 + (param_1 * 0x30 + param_2) * 0x18);
  if ((-1 < (int)(uVar1 - 0x30)) && ((int)(uVar1 - 0x30) < 0x30)) {
    return true;
  }
  if ((-1 < (int)(uVar1 - 0x20)) && ((int)(uVar1 - 0x20) < 0x10)) {
    return true;
  }
  return uVar1 == 0x7a;
}


