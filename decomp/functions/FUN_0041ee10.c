/* 0041ee10 */

void __cdecl FUN_0041ee10(int param_1,int param_2,char *param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  param_3[1] = '\0';
  param_3[2] = '\0';
  *param_3 = '\0';
  do {
    cVar1 = (&DAT_00434420)[iVar5];
    cVar2 = (&DAT_00434428)[iVar5];
    uVar4 = (uint)*(byte *)(DAT_0043453c + 0x10 +
                           ((cVar1 + param_1) * 0x30 + param_2 + cVar2) * 0x18);
    if (DAT_00437580 - uVar4 == -0xc) {
      *param_3 = *param_3 + '\x01';
    }
    else if (uVar4 == 0) {
      cVar3 = param_3[1];
      param_3[1] = cVar3 + '\x01';
      if ((char)(cVar3 + '\x01') == '\x01') {
        param_3[3] = (char)(cVar1 + param_1);
        param_3[4] = (char)(param_2 + cVar2);
      }
    }
    else if ((uVar4 < 0xd) && (uVar4 < 0x10)) {
      param_3[2] = param_3[2] + '\x01';
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 8);
  return;
}


