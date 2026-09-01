/* 0041bf70 */

undefined4 __thiscall FUN_0041bf70(void *this,uint param_1)

{
  int iVar1;
  HRSRC hResInfo;
  HGLOBAL hResData;
  short *psVar2;
  undefined4 *puVar3;
  ushort uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  InitCommonControls();
  *(undefined4 *)((int)this + 0x18) = 0;
  *(LPCSTR *)((int)this + 0x2c) = (LPCSTR)(param_1 & 0xffff);
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  hResInfo = FindResourceA(DAT_004344d0,(LPCSTR)(param_1 & 0xffff),(LPCSTR)0xf1);
  if (hResInfo != (HRSRC)0x0) {
    hResData = LoadResource(DAT_004344d0,hResInfo);
    if (hResData != (HGLOBAL)0x0) {
      psVar2 = LockResource(hResData);
      if ((psVar2 != (short *)0x0) && (*psVar2 == 1)) {
        *(uint *)this = (uint)(ushort)psVar2[1];
        *(uint *)((int)this + 4) = (uint)(ushort)psVar2[2];
        *(uint *)((int)this + 8) = (ushort)psVar2[1] + 7;
        *(uint *)((int)this + 0xc) = (ushort)psVar2[2] + 7;
        *(uint *)((int)this + 0x24) = (uint)(ushort)psVar2[3];
        uVar6 = FUN_00427f90((uint)(ushort)psVar2[3] * 0x14);
        *(undefined4 *)((int)this + 0x18) = uVar6;
        puVar3 = *(undefined4 **)((int)this + 0x18);
        for (uVar5 = (uint)(ushort)psVar2[3] * 0x14 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
        uVar4 = 0;
        while (uVar4 < (ushort)psVar2[3]) {
          iVar1 = (uint)uVar4 * 0x14;
          *(uint *)(*(int *)((int)this + 0x18) + 4 + iVar1) = (uint)(ushort)psVar2[uVar4 + 4];
          *(undefined1 *)(*(int *)((int)this + 0x18) + 8 + iVar1) = 4;
          puVar3 = (undefined4 *)(*(int *)((int)this + 0x18) + iVar1);
          if (puVar3[1] == 0) {
            *(undefined1 *)((int)puVar3 + 9) = 1;
            uVar4 = uVar4 + 1;
          }
          else {
            uVar4 = uVar4 + 1;
            *puVar3 = *(undefined4 *)((int)this + 0x20);
            *(int *)((int)this + 0x20) = *(int *)((int)this + 0x20) + 1;
            *(undefined1 *)(*(int *)((int)this + 0x18) + 9 + iVar1) = 0;
          }
        }
        uVar6 = 1;
      }
      FreeResource(hResData);
    }
  }
  return uVar6;
}


