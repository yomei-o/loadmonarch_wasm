/* 004156c0 */

void __fastcall FUN_004156c0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char local_20 [4];
  int local_1c;
  char **local_18;
  int local_14;
  char *local_10;
  char *local_c;
  char *local_8;
  char *local_4;
  
  local_10 = s_Help__00433bf8;
  local_c = s_No_cash_00433be8;
  local_8 = s_Under_orders_00433bd8;
  local_4 = s_Leader_00433bc8;
  builtin_strncpy(local_20,"\x06\b\n\f",4);
  iVar3 = 0;
  local_14 = 0;
  local_18 = &local_10;
  local_1c = 0;
  do {
    *(undefined4 *)(param_1 + 0x244) = 0;
    do {
      puVar4 = (undefined4 *)(*(int *)(param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar5 = (undefined4 *)
               ((*(int *)(param_1 + 0x244) + iVar3) * 0xa0 + 0xa00 + *(int *)(param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      iVar1 = *(int *)(param_1 + 0x244) + 1;
      *(int *)(param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
    uVar2 = *(uint *)(param_1 + 0x238) & 1;
    if (local_1c == 0x3c00) {
      uVar2 = *(uint *)(param_1 + 0x238) & 3;
    }
    FUN_004244b0(uVar2 + (int)local_20[local_14],0x20,0xa0,0xa0,
                 *(int *)(param_1 + 0x22c) + local_1c + 0xa00);
    iVar1 = iVar3 + 0x18;
    iVar3 = iVar3 + 0x20;
    FUN_0040a870(0x30,iVar1,8,9,*local_18,*(HDC *)(param_1 + 0x224),1,(int *)(param_1 + 0x938c));
    local_18 = local_18 + 1;
    local_1c = local_1c + 0x1400;
    local_14 = local_14 + 1;
  } while (local_1c < 0x5000);
  return;
}


