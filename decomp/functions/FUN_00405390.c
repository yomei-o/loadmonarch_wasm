/* 00405390 */

void __cdecl FUN_00405390(byte param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  do {
    uVar3 = (uint)*(byte *)(DAT_0043453c + iVar2 + 0x10);
    switch(uVar3) {
    case 8:
    case 9:
    case 10:
    case 0xb:
      if (uVar3 - param_1 != 8) {
        iVar1 = *(byte *)(DAT_00434534 + 0x1e + (uint)param_1 * 0x38) - uVar3;
joined_r0x00405410:
        if (iVar1 != -8) {
          *(undefined1 *)(DAT_0043453c + iVar2 + 4) = 1;
        }
      }
      break;
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
      if (uVar3 - param_1 != 0xc) {
        iVar1 = *(byte *)(DAT_00434534 + 0x1e + (uint)param_1 * 0x38) - uVar3;
        goto joined_r0x00405410;
      }
    }
    iVar2 = iVar2 + 0x18;
    if (0xd7ff < iVar2) {
      return;
    }
  } while( true );
}


