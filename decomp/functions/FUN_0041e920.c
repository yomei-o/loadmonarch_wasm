/* 0041e920 */

undefined4 __cdecl FUN_0041e920(uint param_1,uint param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char local_e;
  char local_d;
  uint local_c;
  int local_8;
  int local_4;
  
  local_8 = param_1 * 0x224;
  if (((*(byte *)(DAT_00434538 + 0xd + local_8) & 0x20) != 0) &&
     (iVar5 = DAT_00437580 * 0x38 + DAT_00434534, *(byte *)(iVar5 + 8) == param_2)) {
    uVar4 = (uint)*(byte *)(iVar5 + 9);
    if (param_3 == uVar4) {
      return 0;
    }
    if ((int)(param_3 - uVar4) < 3) {
      cVar1 = '\x02';
      iVar5 = param_3 - 1;
      local_c = param_2;
LAB_0041ea4e:
      *(char *)(DAT_00434538 + 0xc + local_8) = cVar1;
      *(undefined4 *)(DAT_00434538 + 0x18 + local_8) = 0x1f0;
      iVar2 = FUN_00420c60(local_c,iVar5);
      if (iVar2 != 0) {
        return 1;
      }
      iVar2 = FUN_00420610(local_c,iVar5);
      if (iVar2 != 0) {
        return 1;
      }
      iVar2 = (local_c * 0x30 + iVar5) * 0x18;
      if (*(byte *)(DAT_0043453c + iVar2) < 0x40) {
        return 0;
      }
      iVar3 = FUN_004208b0(local_c,iVar5);
      if (iVar3 != 1) {
        *(undefined1 *)(DAT_0043453c + (param_2 * 0x30 + param_3) * 0x18) = 0x40;
        *(undefined1 *)(DAT_0043453c + iVar2) = (undefined1)DAT_0043756c;
        *(undefined1 *)(DAT_00434538 + DAT_0043756c * 0x224) = (undefined1)local_c;
        *(char *)(DAT_00434538 + 1 + DAT_0043756c * 0x224) = (char)iVar5;
        return 1;
      }
      return 1;
    }
  }
  iVar2 = 0;
  local_4 = 0;
  do {
    FUN_0041d6d0((uint)*(byte *)(DAT_00434538 + 0xc + local_8) + iVar2 & 6,&local_e);
    iVar5 = FUN_0041ec30(param_2,param_3,(int)local_e,(int)local_d);
    if (iVar5 == 1) {
      local_c = (int)local_e + param_2;
      iVar5 = (int)local_d + param_3;
      if ((*(byte *)(DAT_0043453c + 0x10 + (local_c * 0x30 + iVar5) * 0x18) < 0x30) &&
         (iVar3 = FUN_0041e700(param_1,local_c,iVar5), iVar3 == 0)) {
        cVar1 = ((byte)local_4 & 3) * '\x02';
        goto LAB_0041ea4e;
      }
    }
    iVar2 = iVar2 + 2;
    local_4 = local_4 + 1;
    if (7 < iVar2) {
      return 1;
    }
  } while( true );
}


