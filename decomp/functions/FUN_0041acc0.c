/* 0041acc0 */

void __cdecl FUN_0041acc0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_8;
  
  local_8 = -1;
  do {
    iVar4 = -1;
    iVar3 = local_8 + param_2;
    do {
      iVar1 = iVar4 + param_1;
      if ((((0 < param_1) || (param_1 < 0x2f)) || (0 < param_2)) || (param_2 < 0x2f)) {
        uVar2 = (uint)*(byte *)(DAT_0043453c + 0x10 + (iVar1 * 0x30 + iVar3) * 0x18);
        if (((int)(uVar2 - 0x30) < 0) || (0x2f < (int)(uVar2 - 0x30))) {
          if (((int)(uVar2 - 0x20) < 0) || (0xf < (int)(uVar2 - 0x20))) {
            if (((int)(uVar2 - 1) < 0) || (3 < (int)(uVar2 - 1))) {
              if ((-1 < (int)(uVar2 - 0x60)) && ((int)(uVar2 - 0x60) < 0x10)) {
                FUN_0041b050(iVar1,iVar3);
              }
            }
            else {
              FUN_0041afa0(iVar1,iVar3);
            }
          }
          else {
            FUN_0041af10(iVar1,iVar3);
          }
        }
        else {
          FUN_0041adf0(iVar1,iVar3);
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    local_8 = local_8 + 1;
  } while (local_8 < 2);
  return;
}


