/* 00422fd0 */

void __thiscall FUN_00422fd0(void *this,int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  
  if ((param_1 < 0x2f) && (param_2 < 0x2f)) {
    uVar3 = *(uint *)((int)this + 0x398);
    iVar1 = (param_1 * 0x30 + param_2) * 0x18;
    iVar5 = (param_2 * uVar3 * 0x30 + param_1) * uVar3;
    FUN_004243c0((uint)*(byte *)(DAT_0043453c + 0x10 + iVar1),uVar3,*(int *)((int)this + 0x20),
                 *(undefined4 *)((int)this + 0x24),
                 (undefined4 *)(*(int *)((int)this + 0x25c) + iVar5),*(int *)((int)this + 0x15c8));
    if (*(byte *)(DAT_0043453c + iVar1) < 0x40) {
      iVar9 = *(int *)((int)this + 0x15cc);
      uVar8 = *(undefined4 *)((int)this + 0x24);
      iVar4 = *(int *)((int)this + 0x25c) + iVar5;
      iVar7 = *(int *)((int)this + 0x20);
      iVar6 = *(int *)((int)this + 0x398);
      uVar3 = FUN_0041b520((uint)*(byte *)(DAT_0043453c + iVar1));
      FUN_00424460(uVar3,iVar6,iVar7,uVar8,iVar4,iVar9);
      bVar2 = *(byte *)(DAT_00434538 + 0x220 + (uint)*(byte *)(DAT_0043453c + iVar1) * 0x224);
      if (bVar2 != 0xff) {
        iVar9 = *(int *)((int)this + 0x398);
        FUN_004244b0((uint)bVar2,iVar9,*(int *)((int)this + 0x20),*(undefined4 *)((int)this + 0x24),
                     iVar9 * iVar9 * -0x30 + *(int *)((int)this + 0x25c) + iVar5);
      }
    }
    bVar2 = *(byte *)(DAT_0043453c + 0x18 + iVar1);
    if ((bVar2 < 0x40) &&
       (bVar2 = *(byte *)(DAT_00434538 + 0x220 + (uint)bVar2 * 0x224), bVar2 != 0xff)) {
      FUN_004244b0((uint)bVar2,*(int *)((int)this + 0x398),*(int *)((int)this + 0x20),
                   *(undefined4 *)((int)this + 0x24),*(int *)((int)this + 0x25c) + iVar5);
    }
  }
  return;
}


