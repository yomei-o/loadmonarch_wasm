/* 0042d4d0 */

byte __cdecl FUN_0042d4d0(uint param_1)

{
  if (DAT_00438984 <= param_1) {
    return 0;
  }
  return *(byte *)(*(int *)((int)&DAT_00438990 + ((int)(param_1 & 0xffffffe7) >> 3)) + 4 +
                  (param_1 & 0x1f) * 8) & 0x40;
}


