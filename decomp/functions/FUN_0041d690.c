/* 0041d690 */

undefined1 __cdecl FUN_0041d690(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00434538 + 0x18 + param_1 * 0x224);
  if (iVar1 != 0x1f0) {
    return *(undefined1 *)(DAT_00434538 + iVar1 + 0x1c + param_1 * 0x224);
  }
  return 5;
}


