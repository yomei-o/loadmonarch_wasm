/* 0041c8e0 */

bool __cdecl FUN_0041c8e0(char *param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_c;
  int local_8;
  
  iVar5 = FUN_0041ec60(500);
  if (iVar5 == 0) {
    return false;
  }
  local_c = 0;
  local_8 = 0;
  *(undefined1 *)(DAT_0043453c + (DAT_0043644c * 0x30 + DAT_00436450) * 0x18) = 0x40;
  param_1[4] = -0x10;
  param_1[5] = '\x01';
  param_1[6] = '\0';
  param_1[7] = '\0';
  do {
    if (*(char *)(DAT_0043453c + 0x10 + local_8) == 'z') {
      iVar5 = local_c / 0x30;
      iVar6 = local_c % 0x30;
      iVar7 = (iVar5 * 0x30 + iVar6) * 0x18 + DAT_0043453c;
      if ((*(byte *)(iVar7 + -0x14) & *(byte *)(iVar7 + 0x484) & *(byte *)(iVar7 + 0x1c) &
           *(byte *)(iVar7 + -0x47c) & 1) == 0) {
        bVar4 = true;
        iVar7 = 0;
        do {
          bVar1 = *(byte *)(DAT_0043453c +
                           (((char)(&DAT_00434420)[iVar7] + iVar5) * 0x30 +
                            (int)(char)(&DAT_00434428)[iVar7] + iVar6) * 0x18);
          if ((bVar1 < 0x40) &&
             ((uVar3 = *(uint *)(DAT_00434538 + 8 + (uint)bVar1 * 0x224),
              *(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) >> 2 < uVar3 || (0x1000 < uVar3))))
          {
            bVar4 = false;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < 4);
        if (bVar4) {
          iVar7 = 0;
          do {
            if (*(uint *)(DAT_0043453c + 8 +
                         (((char)(&DAT_00434420)[iVar7] + iVar5) * 0x30 +
                          (int)(char)(&DAT_00434428)[iVar7] + iVar6) * 0x18) <
                *(uint *)(param_1 + 4)) {
              param_1[2] = (&DAT_00434420)[iVar7] + (char)iVar5;
              cVar2 = (&DAT_00434428)[iVar7];
              *param_1 = (char)iVar5;
              param_1[3] = cVar2 + (char)iVar6;
              param_1[1] = (char)iVar6;
              *(undefined4 *)(param_1 + 4) =
                   *(undefined4 *)
                    (DAT_0043453c + 8 +
                    (((char)(&DAT_00434420)[iVar7] + iVar5) * 0x30 +
                     (int)(char)(&DAT_00434428)[iVar7] + iVar6) * 0x18);
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < 4);
        }
      }
    }
    local_8 = local_8 + 0x18;
    local_c = local_c + 1;
  } while (local_8 < 0xd800);
  *(undefined1 *)(DAT_0043453c + (DAT_0043644c * 0x30 + DAT_00436450) * 0x18) =
       (undefined1)DAT_0043756c;
  return *(uint *)(param_1 + 4) < 0x1f0;
}


