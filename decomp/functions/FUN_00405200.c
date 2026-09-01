/* 00405200 */

undefined4 __cdecl FUN_00405200(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(DAT_00434538 + 0x18 + param_1 * 0x224);
  iVar2 = *piVar1;
  if (iVar2 == 0x1f0) {
    return 0;
  }
  *piVar1 = iVar2 + 1;
  iVar2 = DAT_00434538 + param_1 * 0x224;
  if (*(uint *)(iVar2 + 0x14) <= *(uint *)(iVar2 + 0x18)) {
    *(undefined4 *)(iVar2 + 0x18) = 0x1f0;
    return 0;
  }
  return 1;
}


