/* 00421d30 */

undefined4 FUN_00421d30(void)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  char cVar3;
  undefined4 local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  local_c = 0x1f0;
  cVar3 = '\x01';
  FUN_0041a9f0(DAT_0043756c,DAT_0043644c,DAT_00436450);
  iVar2 = FUN_0041c410((undefined1 *)&local_10);
  if (iVar2 == 1) {
    switch(*(undefined1 *)
            (DAT_0043453c + 0x10 + ((local_10 & 0xff) * 0x30 + (local_10 >> 8 & 0xff)) * 0x18)) {
    case 0:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
      cVar3 = '\x05';
      break;
    default:
      cVar3 = '\b';
      break;
    case 5:
      cVar3 = '\v';
      break;
    case 8:
    case 9:
    case 10:
    case 0xb:
      cVar3 = '\x04';
    }
    local_10 = CONCAT22((undefined2)local_10,(undefined2)local_10);
  }
  else {
    bVar1 = FUN_0041c800((char *)&local_8);
    if ((CONCAT31(extraout_var,bVar1) == 1) && (local_4 < local_c)) {
      cVar3 = '\t';
      local_10 = local_8;
      local_c = local_4;
    }
    bVar1 = FUN_0041c8e0((char *)&local_8);
    if ((CONCAT31(extraout_var_00,bVar1) == 1) && (local_4 + 0x14 < local_c)) {
      cVar3 = '\a';
      local_10 = local_8;
      local_c = local_4;
    }
    if (0x1ef < local_c) {
      return 0;
    }
    if (*(uint *)(DAT_00434538 + 8 + DAT_0043756c * 0x224) <= local_c * 2) {
      return 0;
    }
  }
  *(char *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = cVar3;
  *(undefined1 *)(DAT_00434538 + 0xf + DAT_0043756c * 0x224) = 4;
  *(undefined2 *)(DAT_00434538 + 2 + DAT_0043756c * 0x224) = (undefined2)local_10;
  iVar2 = FUN_00405000(DAT_0043756c,local_10 >> 0x10 & 0xff,local_10 >> 0x18);
  if (iVar2 == 0) {
    return 0;
  }
  if (cVar3 == '\v') {
    FUN_004051b0(DAT_0043756c);
  }
  return 1;
}


