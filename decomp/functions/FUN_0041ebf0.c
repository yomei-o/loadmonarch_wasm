/* 0041ebf0 */

bool __cdecl FUN_0041ebf0(int param_1,int param_2)

{
  if ((((param_2 < 0x2f) && (param_1 < 0x2f)) && (0 < param_1)) && (0 < param_2)) {
    return *(char *)(DAT_0043453c + 5 + (param_1 * 0x30 + param_2) * 0x18) == '\0';
  }
  return false;
}


