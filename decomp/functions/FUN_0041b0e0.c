/* 0041b0e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041b0e0(void)

{
  _DAT_00436434 = DAT_00436404;
  if (DAT_004365a0 != 0) {
    _DAT_00436434 = DAT_00436404 - *(int *)(&DAT_004369d4 + DAT_004365a0 * 0x38);
  }
  if ((&DAT_00436a0c)[DAT_004365a0 * 0xe] != 0) {
    DAT_00436438 = DAT_00436404 - (&DAT_00436a0c)[DAT_004365a0 * 0xe];
  }
  return;
}


