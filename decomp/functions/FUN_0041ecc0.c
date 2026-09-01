/* 0041ecc0 */

undefined4 __cdecl FUN_0041ecc0(int param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  bool bVar5;
  undefined3 extraout_var;
  int iVar6;
  int iVar7;
  char local_4;
  char local_3;
  char local_2;
  char local_1;
  
  iVar7 = 0;
  do {
    cVar2 = (&DAT_00434400)[iVar7];
    cVar3 = (&DAT_00434410)[iVar7];
    bVar5 = FUN_0041ebb0(param_2 + cVar2,param_3 + cVar3);
    if ((CONCAT31(extraout_var,bVar5) == 1) &&
       (bVar4 = *(byte *)(DAT_0043453c + ((param_2 + cVar2) * 0x30 + param_3 + cVar3) * 0x18),
       bVar4 < 0x40)) {
      iVar6 = DAT_00434538 + param_1 * 0x224;
      iVar1 = (uint)bVar4 * 0x224;
      if ((*(char *)(iVar6 + 4) != *(char *)(DAT_00434538 + 4 + iVar1)) &&
         (*(int *)(DAT_00434538 + iVar1 + 0x18) != 0x1f0)) {
        FUN_0041d6d0((uint)*(byte *)(iVar6 + 0xc),&local_4);
        FUN_0041d6d0(*(byte *)(DAT_00434538 + 0xc + iVar1) + 4 & 7,&local_2);
        if ((local_2 == local_4) && (local_1 == local_3)) {
          iVar6 = DAT_00434538 + param_1 * 0x224;
          if (*(char *)(DAT_00434534 + 0x1e + (uint)*(byte *)(iVar6 + 4) * 0x38) ==
              *(char *)(DAT_00434538 + iVar1 + 4)) {
            return 1;
          }
          if (*(uint *)(iVar6 + 8) < *(uint *)(DAT_00434538 + iVar1 + 8)) {
            return 1;
          }
        }
      }
    }
    iVar7 = iVar7 + 1;
    if (3 < iVar7) {
      return 0;
    }
  } while( true );
}


