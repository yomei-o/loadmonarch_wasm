/* 0040dfb0 */

undefined4 __fastcall FUN_0040dfb0(int *param_1)

{
  int iVar1;
  MCIERROR MVar2;
  int iVar3;
  
  param_1[0x11] = 10;
  MVar2 = mciSendCommandA((uint)*(ushort *)((int)param_1 + 6),0x80d,0x402,
                          (DWORD_PTR)(param_1 + 0x10));
  param_1[0x13] = MVar2;
  if (MVar2 != 0) {
    (**(code **)(*param_1 + 0xc))();
    return 0;
  }
  param_1[0xe] = 3;
  MVar2 = mciSendCommandA((uint)*(ushort *)((int)param_1 + 6),0x814,0x112,(DWORD_PTR)(param_1 + 0xc)
                         );
  param_1[0x13] = MVar2;
  param_1[0x16] = param_1[0xd];
  if (param_1[0x13] != 0) {
    (**(code **)(*param_1 + 0xc))();
    return 0;
  }
  param_1[0x15] = 0;
  param_1[0xe] = 1;
  iVar3 = 1;
  if (0 < param_1[0xd]) {
    do {
      if (0xff < iVar3) break;
      param_1[0xf] = iVar3;
      MVar2 = mciSendCommandA((uint)*(ushort *)((int)param_1 + 6),0x814,0x112,
                              (DWORD_PTR)(param_1 + 0xc));
      param_1[0x13] = MVar2;
      iVar1 = param_1[0xd];
      param_1[iVar3 + 0x17] = iVar1;
      if (param_1[0x13] != 0) {
        (**(code **)(*param_1 + 0xc))();
        return 0;
      }
      iVar3 = iVar3 + 1;
      param_1[0x15] = param_1[0x15] + iVar1;
    } while (iVar3 <= param_1[0x16]);
  }
  *(undefined1 *)(param_1 + 0x14) = 1;
  return 1;
}


