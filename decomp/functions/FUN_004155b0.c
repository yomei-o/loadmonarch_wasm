/* 004155b0 */

void __fastcall FUN_004155b0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_20;
  char **local_1c;
  int local_18;
  char *local_14;
  char *local_10;
  char *local_c;
  char *local_8;
  char *local_4;
  
  local_14 = s_Selected__00433bb4;
  local_10 = s_Can_t_go__00433ba0;
  local_c = s_Can_go__00433b8c;
  local_8 = s_Powerful_enemy_00433b78;
  local_4 = s_Unit_in_way_00433b64;
  iVar2 = 0;
  local_1c = &local_14;
  local_18 = 0;
  local_20 = 0;
  do {
    *(undefined4 *)(param_1 + 0x244) = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)(param_1 + 0x244) * 0x100 + 0x3a000 + DAT_00435fd4);
      puVar4 = (undefined4 *)
               ((*(int *)(param_1 + 0x244) + iVar2) * 0xa0 + *(int *)(param_1 + 0x22c));
      for (iVar1 = 0x28; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar1 = *(int *)(param_1 + 0x244) + 1;
      *(int *)(param_1 + 0x244) = iVar1;
    } while (iVar1 < 0x20);
    FUN_004244b0(local_18,0x20,0xa0,0xa0,*(int *)(param_1 + 0x22c) + local_20);
    iVar1 = iVar2 + 8;
    iVar2 = iVar2 + 0x20;
    FUN_0040a870(0x30,iVar1,8,9,*local_1c,*(HDC *)(param_1 + 0x224),1,(int *)(param_1 + 0x938c));
    local_1c = local_1c + 1;
    local_20 = local_20 + 0x1400;
    local_18 = local_18 + 1;
  } while (local_20 < 0x6400);
  return;
}


