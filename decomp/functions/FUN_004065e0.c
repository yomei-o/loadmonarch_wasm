/* 004065e0 */

void __cdecl FUN_004065e0(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  char local_40 [64];
  
  if (0 < (int)param_2) {
    uVar1 = param_2;
    pcVar2 = (char *)(param_3 + 0x8000);
    pcVar3 = local_40 + 2;
    do {
      *pcVar3 = *pcVar2 << 4;
      pcVar3[-2] = pcVar2[1] << 4;
      uVar1 = uVar1 - 1;
      pcVar3[-1] = pcVar2[2] << 4;
      pcVar3[1] = '\x01';
      pcVar2 = pcVar2 + 3;
      pcVar3 = pcVar3 + 4;
    } while (uVar1 != 0);
  }
  FUN_0040e560(&DAT_004365f0,local_40,param_1,param_2);
  return;
}


