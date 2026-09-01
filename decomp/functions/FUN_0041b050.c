/* 0041b050 */

void __cdecl FUN_0041b050(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = 0;
  if (param_1 != 0) {
    iVar1 = FUN_0041f380(param_1 + -1,param_2);
    if (iVar1 == 0) {
      bVar2 = 1;
    }
  }
  if (param_2 != 0) {
    iVar1 = FUN_0041f380(param_1,param_2 + -1);
    if (iVar1 == 0) {
      bVar2 = bVar2 | 2;
    }
  }
  if (param_1 != 0x2f) {
    iVar1 = FUN_0041f380(param_1 + 1,param_2);
    if (iVar1 == 0) {
      bVar2 = bVar2 | 4;
    }
  }
  if (param_2 != 0x2f) {
    iVar1 = FUN_0041f380(param_1,param_2 + 1);
    if (iVar1 == 0) {
      bVar2 = bVar2 | 8;
    }
  }
  *(byte *)(DAT_0043453c + 0x10 + (param_1 * 0x30 + param_2) * 0x18) = bVar2 + 0x60;
  return;
}


