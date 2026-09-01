/* 004104d0 */

void __thiscall FUN_004104d0(void *this,int param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  
  bVar2 = false;
  if (*(int *)((int)this + 0x5838) == 0) {
    switch(*(undefined1 *)((int)this + param_1 * 0x118 + 0x268)) {
    case 0:
    case 2:
    case 4:
    case 6:
    case 0x11:
      bVar2 = true;
      break;
    case 10:
      iVar3 = *(int *)((int)this + param_1 * 0x118 + 0x260);
      if ((iVar3 != 0) &&
         (iVar3 = iVar3 - *(char *)((int)this + param_1 * 0x118 + 0x369),
         *(int *)((int)this + param_1 * 0x118 + 0x260) = iVar3, iVar3 < 0)) {
        *(undefined4 *)((int)this + param_1 * 0x118 + 0x260) = 0;
      }
      bVar2 = true;
      break;
    case 0xb:
      iVar3 = *(int *)((int)this + param_1 * 0x118 + 0x260);
      if ((iVar3 < 0x100) &&
         (iVar3 = iVar3 + *(char *)((int)this + param_1 * 0x118 + 0x369),
         *(int *)((int)this + param_1 * 0x118 + 0x260) = iVar3, 0xff < iVar3)) {
        *(undefined4 *)((int)this + param_1 * 0x118 + 0x260) = 0x100;
      }
      bVar2 = true;
      break;
    case 0xc:
      iVar3 = *(int *)((int)this + param_1 * 0x118 + 0x264);
      if (iVar3 < 0x100) {
        *(int *)((int)this + param_1 * 0x118 + 0x264) =
             *(char *)((int)this + param_1 * 0x118 + 0x369) + iVar3;
      }
      bVar2 = true;
      break;
    case 0xd:
      iVar3 = *(int *)((int)this + param_1 * 0x118 + 0x264);
      if (iVar3 != 0) {
        *(int *)((int)this + param_1 * 0x118 + 0x264) =
             *(char *)((int)this + param_1 * 0x118 + 0x369) + iVar3;
      }
      bVar2 = true;
      break;
    case 0xf:
      goto switchD_0041050f_caseD_f;
    }
  }
  iVar3 = *(int *)((int)this + param_1 * 0x118 + 0x264);
  iVar1 = *(int *)((int)this + param_1 * 0x118 + 0x260);
  uVar4 = (int)*(char *)((int)this + param_1 * 0x118 + 0x36b) |
          (uint)*(byte *)((int)this + param_1 * 0x118 + 0x36a);
  *(uint *)((int)this + 0x254) = uVar4;
  if ((bVar2) && ((*(byte *)((int)this + 0x238) & 2) != 0)) {
    *(uint *)((int)this + 0x254) = uVar4 + 1;
  }
  FUN_00424460(*(int *)((int)this + 0x254),0x20,0x100,0x100,
               *(int *)((int)this + 0x22c) + iVar3 * 0x100 + iVar1,DAT_00436440);
switchD_0041050f_caseD_f:
  return;
}


