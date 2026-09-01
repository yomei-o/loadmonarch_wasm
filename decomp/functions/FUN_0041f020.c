/* 0041f020 */

bool __cdecl FUN_0041f020(undefined4 param_1,int param_2,int param_3,char *param_4)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = FUN_0041ec30(param_2,param_3,(int)*param_4,(int)param_4[1]);
  if (iVar1 == 0) {
    return false;
  }
  pbVar2 = (byte *)(((param_2 + *param_4) * 0x30 + param_4[1] + param_3) * 0x18 + DAT_0043453c);
  if (0x2f < pbVar2[0x10]) {
    return false;
  }
  return (bool)('\x01' - (*pbVar2 < 0x40));
}


