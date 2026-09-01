/* 00404890 */

void __thiscall FUN_00404890(void *this,int param_1,int param_2,int param_3,int param_4)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar6 = param_3 + param_2 * 4;
  iVar3 = *(int *)((int)this + iVar6 * 0x14 + 0x3a0);
  iVar6 = *(int *)((int)this + iVar6 * 0x14 + 0x3a4);
  if (param_4 == 0) {
    puVar5 = (undefined4 *)
             ((iVar6 - param_1) * *(int *)((int)this + 0x20) + *(int *)((int)this + 0x25c) + iVar3);
    *puVar5 = 0x70707070;
    puVar5[1] = 0x70707070;
    puVar5[2] = 0x70707070;
    puVar5[3] = 0x70707070;
    return;
  }
  iVar6 = iVar6 - param_1;
  puVar5 = (undefined4 *)(*(int *)((int)this + 0x20) * iVar6 + *(int *)((int)this + 0x25c) + iVar3);
  *puVar5 = 0x70707070;
  puVar5[1] = 0x70707070;
  puVar5[2] = 0x70707070;
  puVar5[3] = 0x70707070;
  if (param_2 == 4) {
    iVar3 = *(int *)((int)this + 0x20) * iVar6 + *(int *)((int)this + 0x25c) + iVar3;
    *(undefined4 *)(iVar3 + 1) = 0x76767676;
    *(undefined4 *)(iVar3 + 5) = 0x76767676;
    *(undefined4 *)(iVar3 + 9) = 0x76767676;
    *(undefined2 *)(iVar3 + 0xd) = 0x7676;
    return;
  }
  cVar2 = (char)param_2 + 'q';
  uVar1 = (undefined2)CONCAT31(CONCAT21(0x7070,cVar2),cVar2);
  uVar4 = CONCAT22(uVar1,uVar1);
  iVar3 = *(int *)((int)this + 0x20) * iVar6 + *(int *)((int)this + 0x25c) + iVar3;
  *(undefined4 *)(iVar3 + 1) = uVar4;
  *(undefined4 *)(iVar3 + 5) = uVar4;
  *(undefined4 *)(iVar3 + 9) = uVar4;
  *(undefined2 *)(iVar3 + 0xd) = uVar1;
  return;
}


