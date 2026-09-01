/* 004196b0 */

void __fastcall FUN_004196b0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  ((LPOPENFILENAMEA)(param_1 + 0x238))->lStructSize = 0x4c;
  *(undefined4 *)(param_1 + 0x240) = DAT_004344d0;
  *(undefined4 *)(param_1 + 0x23c) = uVar1;
  *(undefined4 *)(param_1 + 0x24c) = 0x100;
  *(int *)(param_1 + 0x254) = param_1 + 900;
  *(undefined4 *)(param_1 + 600) = 0x100;
  *(int *)(param_1 + 0x25c) = param_1 + 0x484;
  *(undefined4 *)(param_1 + 0x260) = 0x100;
  *(undefined4 *)(param_1 + 0x250) = 1;
  *(undefined4 *)(param_1 + 0x26c) = 0x1004;
  FUN_00409490((LPSTR)(param_1 + 0x1c),s_Sound__0043258c,&DAT_0043250c);
  *(LPSTR *)(param_1 + 0x264) = (LPSTR)(param_1 + 0x1c);
  GetOpenFileNameA((LPOPENFILENAMEA)(param_1 + 0x238));
  return;
}


