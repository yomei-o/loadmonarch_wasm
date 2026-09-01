/* 00411eb0 */

void __fastcall FUN_00411eb0(int param_1)

{
  int local_8 [2];
  
  if (*(int *)(param_1 + 0x23c) == 0) {
    FUN_00424460((uint)*(byte *)(DAT_00434534 + *(int *)(param_1 + 0x234) * 0x38) << 3 | 100,0x20,
                 0x100,0x40,*(int *)(param_1 + 0x22c) + 0x1010,DAT_00436440);
    FUN_00424460((uint)(*(byte *)(DAT_00434534 + 0x1e + *(int *)(param_1 + 0x234) * 0x38) | 0xc) <<
                 3,0x20,0x100,0x40,*(int *)(param_1 + 0x22c) + 0x10d0,DAT_00436440);
    *(undefined1 *)
     (DAT_00434534 + 0x1e +
     (uint)*(byte *)(DAT_00434534 + 0x1e + *(int *)(param_1 + 0x234) * 0x38) * 0x38) = 0x80;
    *(undefined1 *)(DAT_00434534 + 0x1e + *(int *)(param_1 + 0x234) * 0x38) = 0x80;
    local_8[0] = 0x100;
    local_8[1] = 0x40;
    wsprintfA((LPSTR)(param_1 + 0x1c),s_Break_alliance_00433824);
    FUN_0040a870(0x40,0x18,0,1,(LPSTR)(param_1 + 0x1c),*(HDC *)(param_1 + 0x224),1,local_8);
    FUN_0040a1c0(0x15f97);
  }
  return;
}


