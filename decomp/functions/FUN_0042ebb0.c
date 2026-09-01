/* 0042ebb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0042ebb0(uint param_1)

{
  undefined4 *puVar1;
  
  if ((param_1 < DAT_00438984) &&
     (puVar1 = (undefined4 *)
               (*(int *)((int)&DAT_00438990 + ((int)(param_1 & 0xffffffe7) >> 3)) +
               (param_1 & 0x1f) * 8), (*(byte *)(puVar1 + 1) & 1) != 0)) {
    return *puVar1;
  }
  _DAT_00434854 = 9;
  _DAT_00434858 = 0;
  return 0xffffffff;
}


