/* 00405250 */

void __cdecl FUN_00405250(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int local_10 [4];
  
  local_10[1] = 1;
  local_10[0] = 0;
  local_10[2] = 2;
  local_10[3] = 3;
  *(undefined4 *)(DAT_00434538 + 0x18 + param_1 * 0x224) = 0;
  iVar1 = param_1 * 0x224;
  *(int *)(DAT_00434538 + 0x14 + iVar1) = local_10[param_3] + local_10[param_2];
  iVar2 = (char)(&DAT_00434130)[param_2 + param_3 * 7] * 3;
  *(undefined *)(DAT_00434538 + 0x1c + iVar1) =
       (&DAT_00434150)[(char)(&DAT_00434130)[param_2 + param_3 * 7] * 3];
  *(undefined *)(DAT_00434538 + 0x1d + iVar1) = (&DAT_00434151)[iVar2];
  *(undefined *)(DAT_00434538 + 0x1e + iVar1) = (&DAT_00434152)[iVar2];
  *(char *)(DAT_00434538 + 2 + iVar1) = (char)DAT_0043644c + (char)param_2;
  *(char *)(DAT_00434538 + 3 + iVar1) = (char)DAT_00436450 + (char)param_3;
  return;
}


