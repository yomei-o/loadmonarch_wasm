/* 00429080 */

undefined4 __cdecl FUN_00429080(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  LPVOID pvVar3;
  
  uVar1 = FUN_0042b630(DAT_00438a94);
  if (uVar1 < (uint)((int)DAT_00438a90 + (4 - (int)DAT_00438a94))) {
    iVar2 = FUN_0042b630(DAT_00438a94);
    pvVar3 = FUN_0042b5c0(DAT_00438a94,iVar2 + 0x10);
    if (pvVar3 == (LPVOID)0x0) {
      return 0;
    }
    DAT_00438a90 = (undefined4 *)
                   (((int)DAT_00438a90 - (int)DAT_00438a94 & 0xfffffffcU) + (int)pvVar3);
    DAT_00438a94 = pvVar3;
  }
  *DAT_00438a90 = param_1;
  DAT_00438a90 = DAT_00438a90 + 1;
  return param_1;
}


