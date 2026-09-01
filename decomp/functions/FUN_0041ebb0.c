/* 0041ebb0 */

bool __cdecl FUN_0041ebb0(int param_1,int param_2)

{
  if ((((param_1 < 0x2f) && (param_2 < 0x2f)) && (0 < param_1)) && (0 < param_2)) {
    return *(char *)(DAT_0043453c + 4 + (param_1 * 0x30 + param_2) * 0x18) == '\0';
  }
  return false;
}


