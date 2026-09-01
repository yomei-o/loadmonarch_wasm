/* 0041a800 */

undefined4 __cdecl FUN_0041a800(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  FUN_00405360();
  iVar1 = param_1 * 0x224;
  FUN_004056f0((byte *)(DAT_00434538 + iVar1 + 2));
  FUN_00405510(param_1);
  FUN_0041a680(param_2,param_3);
  iVar2 = FUN_00405000(param_1,(uint)*(byte *)(DAT_00434538 + iVar1 + 2),
                       (uint)*(byte *)(DAT_00434538 + iVar1 + 3));
  if (iVar2 == 0) {
    return 0;
  }
  switch(*(byte *)(DAT_00434538 + 0xd + iVar1) & 0xf) {
  case 6:
  case 7:
  case 9:
  case 10:
  case 0xb:
    FUN_004051b0(param_1);
  }
  *(undefined1 *)(DAT_00434538 + 0xf + iVar1) = 4;
  return 1;
}


