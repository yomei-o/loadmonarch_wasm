/* 0041a680 */

void __cdecl FUN_0041a680(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  undefined3 extraout_var;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte local_e;
  byte local_d;
  undefined1 local_8;
  
  local_d = 0;
  if ((((param_1 < 0x2f) && (param_2 < 0x2f)) && (0 < param_1)) && (0 < param_2)) {
    DAT_004358e0._0_1_ = (undefined1)param_1;
    DAT_004359e0 = (undefined1)param_2;
    local_e = 1;
    *(undefined4 *)(DAT_0043453c + 8 + (param_1 * 0x30 + param_2) * 0x18) = 0;
    do {
      uVar5 = (uint)local_d;
      iVar9 = 0;
      local_d = local_d + 1;
      uVar4 = (uint)*(byte *)((int)&DAT_004358e0 + uVar5);
      bVar2 = (&DAT_004359e0)[uVar5];
      do {
        iVar6 = (int)(char)(&DAT_00434401)[iVar9] + uVar4;
        iVar7 = (uint)bVar2 + (int)(char)(&DAT_00434411)[iVar9];
        bVar3 = FUN_0041ebb0(iVar6,iVar7);
        if (CONCAT31(extraout_var,bVar3) != 0) {
          iVar1 = (iVar6 * 0x30 + iVar7) * 0x18;
          iVar8 = DAT_0043453c + iVar1;
          if (0x1ef < *(uint *)(iVar8 + 8)) {
            local_8 = (undefined1)iVar6;
            uVar5 = (uint)local_e;
            local_e = local_e + 1;
            *(undefined1 *)((int)&DAT_004358e0 + uVar5) = local_8;
            iVar6 = DAT_0043453c;
            (&DAT_004359e0)[uVar5] = (char)iVar7;
            iVar6 = *(int *)(iVar6 + 8 + (uVar4 * 0x30 + (uint)bVar2) * 0x18) + 1;
            if (0x1ef < iVar6) {
              *(undefined1 *)(iVar8 + 4) = 1;
              iVar6 = 0x1f0;
            }
            *(int *)(DAT_0043453c + 8 + iVar1) = iVar6;
          }
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < 4);
    } while (local_e != local_d);
  }
  return;
}


