/* 0041cdf0 */

int FUN_0041cdf0(void)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar1 = 0;
  iVar2 = 0x900;
  puVar3 = (undefined1 *)(DAT_0043453c + 0x10);
  do {
    switch(*puVar3) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x7b:
      iVar1 = iVar1 + 1;
    }
    puVar3 = puVar3 + 0x18;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return iVar1;
}


