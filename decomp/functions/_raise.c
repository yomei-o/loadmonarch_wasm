/* 0042d850 */

/* Library Function - Single Match
    _raise
   
   Library: Visual Studio 1998 Release */

int __cdecl _raise(int _SigNum)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  code *pcVar7;
  undefined4 local_4;
  
  switch(_SigNum) {
  case 2:
    puVar6 = &DAT_004353ec;
    pcVar7 = DAT_004353ec;
    break;
  default:
    return -1;
  case 4:
  case 8:
  case 0xb:
    uVar3 = siglookup(_SigNum);
    puVar6 = (undefined4 *)(uVar3 + 8);
    pcVar7 = (code *)*puVar6;
    break;
  case 0xf:
    puVar6 = &DAT_004353f8;
    pcVar7 = DAT_004353f8;
    break;
  case 0x15:
    puVar6 = &DAT_004353f0;
    pcVar7 = DAT_004353f0;
    break;
  case 0x16:
    puVar6 = &DAT_004353f4;
    pcVar7 = DAT_004353f4;
  }
  uVar2 = DAT_00434b40;
  uVar1 = DAT_00434b3c;
  if (pcVar7 == (code *)0x1) {
    return 0;
  }
  if (pcVar7 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (((_SigNum == 8) || (_SigNum == 0xb)) || (uVar5 = local_4, _SigNum == 4)) {
    DAT_00434b40 = 0;
    uVar5 = uVar2;
    if (_SigNum == 8) {
      DAT_00434b3c = 0x8c;
      local_4 = uVar1;
      goto LAB_0042d91c;
    }
  }
  else {
LAB_0042d91c:
    if (_SigNum == 8) {
      if (DAT_00434b30 < DAT_00434b34 + DAT_00434b30) {
        puVar6 = (undefined4 *)(DAT_00434b30 * 0xc + 0x434ac0);
        iVar4 = DAT_00434b34;
        do {
          *puVar6 = 0;
          puVar6 = puVar6 + 3;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      goto LAB_0042d95d;
    }
  }
  *puVar6 = 0;
LAB_0042d95d:
  if (_SigNum == 8) {
    (*pcVar7)(8,DAT_00434b3c);
  }
  else {
    (*pcVar7)(_SigNum);
    if ((_SigNum != 0xb) && (_SigNum != 4)) {
      return 0;
    }
  }
  if (_SigNum == 8) {
    DAT_00434b3c = local_4;
  }
  DAT_00434b40 = uVar5;
  return 0;
}


