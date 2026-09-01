/* 0041ad90 */

void FUN_0041ad90(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  FUN_00405330();
  do {
    iVar2 = DAT_00434538 + iVar3;
    if (((*(byte *)(iVar2 + 0x10) & 0x80) == 0) && (*(int *)(iVar2 + 0x18) == 0x1f0)) {
      cVar1 = *(char *)(iVar2 + 0xd);
      if ((cVar1 == '\0') || ((*(char *)(iVar2 + 4) != DAT_004365cd && (cVar1 == '\x02')))) {
        *(char *)(iVar2 + 0xd) = '\x01';
      }
    }
    iVar3 = iVar3 + 0x224;
  } while (iVar3 < 0x8900);
  return;
}


