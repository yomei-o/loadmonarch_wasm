/* 0041e700 */

undefined4 __cdecl FUN_0041e700(uint param_1,int param_2,int param_3)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  bool bVar4;
  undefined3 extraout_var;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char local_2;
  char local_1;
  
  uVar6 = (uint)*(byte *)(DAT_0043453c + (param_2 * 0x30 + param_3) * 0x18);
  if ((uVar6 != 0x40) && (param_1 != uVar6)) {
    iVar5 = uVar6 * 0x224 + DAT_00434538;
    iVar8 = param_1 * 0x224 + DAT_00434538;
    if ((*(char *)(iVar8 + 4) == *(char *)(iVar5 + 4)) &&
       (100000 < (uint)(*(int *)(iVar5 + 8) + *(int *)(iVar8 + 8)))) {
      return 1;
    }
    if (*(char *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) == *(char *)(iVar5 + 4)) {
      return 1;
    }
    if (*(uint *)(iVar8 + 8) <= *(uint *)(iVar5 + 8)) {
      return 1;
    }
  }
  iVar5 = 1;
  do {
    cVar1 = (&DAT_00434400)[iVar5];
    cVar2 = (&DAT_00434410)[iVar5];
    bVar4 = FUN_0041ebb0(param_2 + cVar1,param_3 + cVar2);
    if ((CONCAT31(extraout_var,bVar4) == 1) &&
       (bVar3 = *(byte *)(DAT_0043453c + ((param_2 + cVar1) * 0x30 + param_3 + cVar2) * 0x18),
       bVar3 < 0x40)) {
      iVar8 = (uint)bVar3 * 0x224;
      iVar7 = DAT_00434538 + iVar8;
      if (*(byte *)(iVar7 + 4) != DAT_00437580) {
        if (*(byte *)(DAT_00434534 + 0x1e + DAT_00437580 * 0x38) == *(byte *)(iVar7 + 4)) {
          if (*(int *)(DAT_00434538 + 0x18 + param_1 * 0x224) == 0x1f0) {
            return 1;
          }
        }
        else if (*(int *)(iVar7 + 0x18) == 0x1f0) {
          if (*(uint *)(DAT_00434538 + 8 + param_1 * 0x224) < *(uint *)(iVar7 + 8)) {
            return 1;
          }
        }
        else {
          FUN_0041d6d0(*(byte *)(iVar7 + 0xc) + 4 & 7,&local_2);
          if ((((&DAT_00434400)[iVar5] == local_2) && ((&DAT_00434410)[iVar5] == local_1)) &&
             (*(uint *)(DAT_00434538 + 8 + param_1 * 0x224) < *(uint *)(DAT_00434538 + 8 + iVar8)))
          {
            return 1;
          }
        }
      }
    }
    iVar5 = iVar5 + 1;
    if (4 < iVar5) {
      return 0;
    }
  } while( true );
}


