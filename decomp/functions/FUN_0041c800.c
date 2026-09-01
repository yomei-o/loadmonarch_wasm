/* 0041c800 */

bool __cdecl FUN_0041c800(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar2 = 0;
  local_4 = 0;
  param_1[4] = -0x10;
  param_1[5] = '\x01';
  param_1[6] = '\0';
  param_1[7] = '\0';
  do {
    iVar3 = 0;
    do {
      if (*(char *)(DAT_0043453c + 0x10 + local_4) == '{') {
        iVar4 = 0;
        do {
          if (*(uint *)(DAT_0043453c + 8 +
                       (((char)(&DAT_00434420)[iVar4] + iVar2) * 0x30 +
                        (int)(char)(&DAT_00434428)[iVar4] + iVar3) * 0x18) < *(uint *)(param_1 + 4))
          {
            param_1[2] = (&DAT_00434420)[iVar4] + (char)iVar2;
            cVar1 = (&DAT_00434428)[iVar4];
            *param_1 = (char)iVar2;
            param_1[3] = cVar1 + (char)iVar3;
            param_1[1] = (char)iVar3;
            *(undefined4 *)(param_1 + 4) =
                 *(undefined4 *)
                  (DAT_0043453c + 8 +
                  (((char)(&DAT_00434420)[iVar4] + iVar2) * 0x30 + (int)(char)(&DAT_00434428)[iVar4]
                  + iVar3) * 0x18);
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 4);
      }
      local_4 = local_4 + 0x18;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x30);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x30);
  return *(uint *)(param_1 + 4) < 0x1f0;
}


