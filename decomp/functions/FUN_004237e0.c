/* 004237e0 */

undefined4 FUN_004237e0(int param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  
  FUN_00405360();
  FUN_00405510(param_1);
  bVar3 = *param_2;
  bVar4 = param_2[1];
  FUN_004056f0(param_2);
  iVar1 = param_1 * 0x224;
  FUN_0041a680((uint)*(byte *)(DAT_00434538 + iVar1),(uint)((byte *)(DAT_00434538 + iVar1))[1]);
  iVar2 = ((uint)bVar3 * 0x30 + (uint)bVar4) * 0x18;
  if (*(uint *)(DAT_0043453c + 8 + iVar2) < 0x1f0) {
    *(undefined1 *)(DAT_00434538 + 0x220 + iVar1) = 2;
    return 1;
  }
  FUN_00405360();
  FUN_00405440(param_1);
  FUN_004056f0(param_2);
  FUN_0041a680((uint)*(byte *)(DAT_00434538 + iVar1),(uint)((byte *)(DAT_00434538 + iVar1))[1]);
  if (0x1ef < *(uint *)(DAT_0043453c + 8 + iVar2)) {
    FUN_00405360();
    FUN_004056f0(param_2);
    FUN_0041a680((uint)*(byte *)(DAT_00434538 + iVar1),(uint)((byte *)(DAT_00434538 + iVar1))[1]);
    if (0x1ef < *(uint *)(DAT_0043453c + 8 + iVar2)) {
      *(undefined1 *)(DAT_00434538 + 0x220 + iVar1) = 1;
      return 0;
    }
    *(undefined1 *)(DAT_00434538 + 0x220 + iVar1) = 4;
    return 1;
  }
  *(undefined1 *)(DAT_00434538 + 0x220 + iVar1) = 3;
  return 1;
}


