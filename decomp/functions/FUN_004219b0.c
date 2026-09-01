/* 004219b0 */

int FUN_004219b0(void)

{
  byte bVar1;
  int iVar2;
  undefined1 uVar3;
  char local_2;
  char local_1;
  
  uVar3 = 0xb;
  iVar2 = FUN_0041dfb0(&local_2);
  if (iVar2 == 0) {
    uVar3 = 4;
    iVar2 = FUN_0041e0a0(&local_2);
    if (iVar2 == 0) {
      uVar3 = 5;
      iVar2 = FUN_0041e1d0(&local_2);
      goto LAB_004219f9;
    }
LAB_00421a11:
    if (iVar2 == 0) {
      if (*(char *)(DAT_00434538 + 4 + DAT_0043756c * 0x224) != DAT_004365cd) {
        uVar3 = 9;
        iVar2 = FUN_0041e480(&local_2);
      }
      goto LAB_00421a4a;
    }
  }
  else {
LAB_004219f9:
    if (iVar2 == 0) {
      uVar3 = 8;
      iVar2 = FUN_0041e360(&local_2);
      goto LAB_00421a11;
    }
LAB_00421a4a:
    if (iVar2 != 0) goto LAB_00421a66;
    uVar3 = 1;
    iVar2 = FUN_0041e560(&local_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_00421a66:
  *(undefined1 *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) = uVar3;
  FUN_00405250(DAT_0043756c,(int)local_2,(int)local_1);
  bVar1 = *(byte *)(DAT_00434538 + 0xd + DAT_0043756c * 0x224) & 0xf;
  if ((bVar1 == 0xb) || (bVar1 == 9)) {
    FUN_004051b0(DAT_0043756c);
  }
  return iVar2;
}


