/* 0041ef80 */

undefined4 __cdecl FUN_0041ef80(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char local_2;
  char local_1;
  
  iVar2 = 0;
  do {
    FUN_0041d6d0((uint)*(byte *)(DAT_00434538 + 0xc + param_1 * 0x224) + iVar2 & 6,&local_2);
    iVar1 = FUN_0041ec30(param_2,param_3,(int)local_2,(int)local_1);
    if (iVar1 == 1) {
      iVar1 = FUN_00420c60(local_2 + param_2,local_1 + param_3);
      if (iVar1 == 1) {
        return 1;
      }
    }
    iVar2 = iVar2 + 2;
  } while (iVar2 < 8);
  return 0;
}


