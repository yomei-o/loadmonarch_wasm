/* 00420af0 */

void __cdecl FUN_00420af0(int param_1,int param_2,int param_3)

{
  char *pcVar1;
  
  pcVar1 = (char *)(DAT_00434538 + 0xe + param_1 * 0x224);
  *pcVar1 = *pcVar1 + '\x01';
  if (3 < *(byte *)(DAT_00434538 + 0xe + param_1 * 0x224)) {
    FUN_00420b30(param_1,param_2,param_3);
  }
  return;
}


