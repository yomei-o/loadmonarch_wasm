/* 00404960 */

void __thiscall FUN_00404960(void *this,int param_1,int param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  iVar6 = param_3 + param_2 * 4;
  iVar3 = *(int *)((int)this + iVar6 * 0x14 + 0x3a0);
  iVar4 = *(int *)((int)this + iVar6 * 0x14 + 0x3a4);
  uVar8 = (uint)*(byte *)((int)this + iVar6 * 0x14 + 0x39c);
  uVar5 = (DAT_00435b1c & 2) >> 1;
  if (uVar8 == 0xf0) {
    if ((*(byte *)((int)this + iVar6 * 0x14 + 0x39d) & 2) == 0) {
      bVar2 = *(byte *)((int)this + iVar6 * 0x14 + 0x39e);
      if (bVar2 == 0) {
        if (param_1 < 0x15) {
          if (10 < param_1) {
            uVar5 = uVar5 + 2;
          }
        }
        else {
          uVar5 = uVar5 + 4;
        }
      }
      else {
        uVar5 = bVar2 + 5;
        *(byte *)((int)this + iVar6 * 0x14 + 0x39e) = bVar2 - 1;
      }
    }
    else {
      cVar1 = *(char *)((int)this + iVar6 * 0x14 + 0x39e);
      if (cVar1 != '\x04') {
        *(char *)((int)this + iVar6 * 0x14 + 0x39e) = cVar1 + '\x01';
      }
      uVar5 = *(byte *)((int)this + iVar6 * 0x14 + 0x39e) + 5;
    }
    iVar6 = uVar5 << 4;
    iVar9 = 0;
    do {
      iVar10 = DAT_00435fd4 + iVar6;
      iVar6 = iVar6 + 0x100;
      puVar7 = (undefined4 *)
               (((iVar4 - param_1) + iVar9 + -0x10) * *(int *)((int)this + 0x20) +
                *(int *)((int)this + 0x25c) + iVar3);
      iVar9 = iVar9 + 1;
      *puVar7 = *(undefined4 *)(iVar10 + 0x1d000);
      puVar7[1] = *(undefined4 *)(iVar10 + 0x1d004);
      puVar7[2] = *(undefined4 *)(iVar10 + 0x1d008);
      puVar7[3] = *(undefined4 *)(iVar10 + 0x1d00c);
    } while (iVar9 < 0x10);
  }
  else if (uVar8 == 0xf1) {
    if ((*(byte *)((int)this + iVar6 * 0x14 + 0x39d) & 2) == 0) {
      bVar2 = *(byte *)((int)this + iVar6 * 0x14 + 0x39e);
      if (bVar2 == 0) {
        if (param_1 < 0x15) {
          if (10 < param_1) {
            uVar5 = uVar5 + 2;
          }
        }
        else {
          uVar5 = uVar5 + 4;
        }
      }
      else {
        uVar5 = bVar2 + 5;
        *(byte *)((int)this + iVar6 * 0x14 + 0x39e) = bVar2 - 1;
      }
    }
    else {
      cVar1 = *(char *)((int)this + iVar6 * 0x14 + 0x39e);
      if (cVar1 != '\x04') {
        *(char *)((int)this + iVar6 * 0x14 + 0x39e) = cVar1 + '\x01';
      }
      uVar5 = *(byte *)((int)this + iVar6 * 0x14 + 0x39e) + 5;
    }
    iVar6 = uVar5 << 4;
    iVar9 = 0;
    do {
      iVar10 = DAT_00435fd4 + iVar6;
      iVar6 = iVar6 + 0x100;
      puVar7 = (undefined4 *)
               (((iVar4 - param_1) + iVar9 + -0x10) * *(int *)((int)this + 0x20) +
                *(int *)((int)this + 0x25c) + iVar3);
      iVar9 = iVar9 + 1;
      *puVar7 = *(undefined4 *)(iVar10 + 0x1e000);
      puVar7[1] = *(undefined4 *)(iVar10 + 0x1e004);
      puVar7[2] = *(undefined4 *)(iVar10 + 0x1e008);
      puVar7[3] = *(undefined4 *)(iVar10 + 0x1e00c);
    } while (iVar9 < 0x10);
  }
  else if (uVar8 != 0xff) {
    uVar5 = uVar5 + uVar8;
    if ((*(byte *)((int)this + iVar6 * 0x14 + 0x39d) & 2) == 0) {
      bVar2 = *(byte *)((int)this + iVar6 * 0x14 + 0x39e);
      if (bVar2 == 0) {
        if ((param_2 != 4) && (param_3 == 1)) {
          if (param_1 < 0x51) {
            if (0x14 < param_1) {
              uVar5 = uVar5 | 0x20;
            }
          }
          else {
            uVar5 = uVar5 | 0x40;
          }
        }
      }
      else {
        if (param_2 == 4) {
          iVar9 = 0xa8;
        }
        else {
          iVar9 = (-(uint)(param_3 == 0) & 4) + 0xa0;
        }
        *(byte *)((int)this + iVar6 * 0x14 + 0x39e) = bVar2 - 1;
        uVar5 = (uint)bVar2 + param_2 * 8 + -1 + iVar9;
      }
    }
    else {
      iVar9 = 0xa8;
      if (param_2 != 4) {
        iVar9 = (-(uint)(param_3 == 0) & 4) + 0xa0;
      }
      cVar1 = *(char *)((int)this + iVar6 * 0x14 + 0x39e);
      if (cVar1 != '\x04') {
        *(char *)((int)this + iVar6 * 0x14 + 0x39e) = cVar1 + '\x01';
      }
      uVar5 = (uint)*(byte *)((int)this + iVar6 * 0x14 + 0x39e) + param_2 * 8 + -1 + iVar9;
    }
    FUN_004243c0(uVar5,0x10,*(int *)((int)this + 0x20),*(undefined4 *)((int)this + 0x24),
                 (undefined4 *)
                 (((iVar4 - param_1) + -0x10) * *(int *)((int)this + 0x20) +
                  *(int *)((int)this + 0x25c) + iVar3),DAT_00436444);
  }
  puVar7 = (undefined4 *)
           (((iVar4 - param_1) + -0x11) * *(int *)((int)this + 0x20) + *(int *)((int)this + 0x25c) +
           iVar3);
  *puVar7 = 0x70707070;
  puVar7[1] = 0x70707070;
  puVar7[2] = 0x70707070;
  puVar7[3] = 0x70707070;
  return;
}


