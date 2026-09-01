/* 0041d5f0 */

void __fastcall FUN_0041d5f0(int param_1)

{
  int iVar1;
  int iVar2;
  char local_1c [12];
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x4a4) != 0) {
    local_1c[0] = '\0';
    local_1c[1] = 0x10;
    local_1c[2] = 0x10;
    local_1c[3] = 0x18;
    local_1c[4] = 0x10;
    local_1c[5] = 0x10;
    local_1c[6] = 0x18;
    local_1c[7] = 0x10;
    local_1c[8] = 0x18;
    local_1c[9] = 0x10;
    local_10 = 0x58;
    local_8 = 0xb0;
    local_c = 0;
    iVar1 = 0;
    do {
      iVar2 = iVar1 + 1;
      local_c = local_c + local_1c[iVar1];
      FUN_00427a90(*(void **)(param_1 + 0x4a4),iVar1 + 70000,iVar1 + 0x9cb9,local_10,local_c,local_8
                   ,local_c + 0x10);
      iVar1 = iVar2;
    } while (iVar2 < 9);
  }
  return;
}


