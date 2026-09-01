/* 0040a020 */

undefined4 __cdecl FUN_0040a020(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  
  iVar1 = param_1 * 0x224;
  iVar3 = DAT_00434538 + iVar1;
  if ((*(char *)(iVar3 + 4) != DAT_004365cd) || ((*(byte *)(iVar3 + 0x10) & 2) != 0)) {
    return 0;
  }
  if ((param_4 == 0) && ((*(byte *)(iVar3 + 0xd) & 0x10) != 0)) {
    return 0;
  }
  FUN_00405360();
  FUN_0041a680(param_2,param_3);
  puVar2 = (uint *)(DAT_00434538 + 0x21c + iVar1);
  *puVar2 = *puVar2 | 1;
  *(undefined1 *)(DAT_00434538 + 0x220 + iVar1) = 0;
  *(undefined1 *)(DAT_00434538 + iVar1 + 0xe) = *(undefined1 *)(DAT_00434538 + iVar1 + 0xc);
  *(undefined1 *)(DAT_00434538 + 0xc + iVar1) = 6;
  return 1;
}


