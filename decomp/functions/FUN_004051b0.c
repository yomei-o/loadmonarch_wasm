/* 004051b0 */

undefined4 __cdecl FUN_004051b0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = DAT_00434538 + param_1 * 0x224;
  if (*(int *)(iVar2 + 0x18) == 0x1f0) {
    return 0;
  }
  piVar1 = (int *)(iVar2 + 0x14);
  *piVar1 = *piVar1 + -1;
  iVar2 = DAT_00434538 + param_1 * 0x224;
  if (*(int *)(iVar2 + 0x14) < 1) {
    *(undefined4 *)(iVar2 + 0x18) = 0x1f0;
    return 0;
  }
  return 1;
}


