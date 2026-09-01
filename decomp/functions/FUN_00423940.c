/* 00423940 */

undefined4 __thiscall FUN_00423940(void *this,int *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  UINT_PTR UVar5;
  UINT_PTR *pUVar6;
  undefined *puVar7;
  LPCSTR pCVar8;
  undefined1 *this_00;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_40 [32];
  int *local_20;
  int *local_1c;
  HMENU local_18;
  int local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00423c94;
  *unaff_FS_OFFSET = &local_10;
  bVar1 = *(byte *)(DAT_0043453c + 0x10 +
                   ((uint)*(byte *)((int)this + 0x3c2) * 0x30 + (uint)*(byte *)((int)this + 0x3c3))
                   * 0x18);
  if (bVar1 == 0) {
    local_14 = 0;
  }
  else {
    uVar4 = (uint)bVar1;
    if (((int)(uVar4 - 8) < 4) && (-1 < (int)(uVar4 - 8))) {
      local_14 = 1;
    }
    else if (((int)(uVar4 - 0xc) < 4) && (-1 < (int)(uVar4 - 0xc))) {
      local_14 = 2;
    }
    else if (((int)(uVar4 - 1) < 4) && (-1 < (int)(uVar4 - 1))) {
      local_14 = 3;
    }
    else if (bVar1 == 0x7b) {
      local_14 = 4;
    }
    else if (((int)(uVar4 - 0x20) < 0x10) && (-1 < (int)(uVar4 - 0x20))) {
      local_14 = 5;
    }
    else if (bVar1 == 5) {
      local_14 = 6;
    }
    else if (bVar1 == 0x7a) {
      local_14 = 7;
    }
    else if (((int)(uVar4 - 0x30) < 0x30) && (-1 < (int)(uVar4 - 0x30))) {
      local_14 = 8;
    }
    else if (((int)(uVar4 - 0x14) < 4) && (-1 < (int)(uVar4 - 0x14))) {
      local_14 = 9;
    }
    else {
      local_14 = 10;
    }
  }
  UVar5 = 0x200;
  local_1c = this;
  FUN_00428220(local_40,4,8,FUN_0040e2f0,thunk_FUN_0040e460);
  this_00 = local_40;
  local_8 = 0;
  puVar7 = &DAT_00435bca;
  FUN_0040e2f0(&local_18);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_20 = local_1c + 0x5b9;
  do {
    wsprintfA((LPSTR)local_20,s__s_continue_00432470,puVar7);
    FUN_0040e310(this_00,UVar5,&DAT_00435b97,0);
    FUN_0040e310(this_00,UVar5 + 1,&DAT_00435b86,0);
    if (puVar7 != &DAT_00435bfd) {
      wsprintfA((LPSTR)local_20,s__s_continue_00432470,puVar7);
      FUN_0040e310(this_00,UVar5 + 2,(LPCSTR)local_20,0);
    }
    UVar5 = UVar5 + 3;
    this_00 = this_00 + 4;
    puVar7 = puVar7 + 0x11;
  } while (puVar7 < &DAT_00435c52);
  pUVar6 = (UINT_PTR *)&stack0xffffffb0;
  UVar5 = 500;
  pCVar8 = &DAT_00435b86;
  local_20 = (int *)0x0;
  local_14 = local_14 << 4;
  do {
    if (((&DAT_004341af)[local_14 - (int)local_20] == '\x01') ||
       ((&DAT_0043425f)[local_14 - (int)local_20] == '\x01')) {
      if (pCVar8 < (LPCSTR)0x435bca) {
        FUN_0040e310(&local_18,UVar5,pCVar8,0);
      }
      else {
        FUN_0040e390(&local_18,*pUVar6,pCVar8);
      }
    }
    else {
      FUN_0040e310(&local_18,UVar5,pCVar8,1);
    }
    pUVar6 = pUVar6 + 1;
    UVar5 = UVar5 + 3;
    pCVar8 = pCVar8 + 0x11;
    local_20 = (int *)((int)local_20 + 1);
  } while (pCVar8 < &DAT_00435c52);
  FUN_0040e400(&local_18);
  FUN_0040e330(&local_18,60000,0x9cc5,0);
  DAT_004365dc = 3;
  FUN_0040a1c0(0x15f93);
  iVar2 = TrackPopupMenu(local_18,0x102,*param_1,param_1[1],0,(HWND)local_1c[2],(RECT *)0x0);
  if (iVar2 == 60000) {
    DAT_004365dc = 1;
    iVar2 = 0;
  }
  if (iVar2 == 0) {
    iVar2 = 0;
    do {
      if ((*(byte *)(DAT_00434538 + iVar2 + 0x21c) & 1) != 0) {
        *(undefined1 *)(DAT_00434538 + iVar2 + 0x220) = 0;
      }
      iVar2 = iVar2 + 0x224;
    } while (iVar2 < 0x8900);
    (**(code **)(*local_1c + 100))();
    local_8 = local_8 & 0xffffff00;
    FUN_00423c8c();
    local_8 = 0xffffffff;
    FUN_00423c9e();
    uVar3 = 0;
  }
  else {
    DAT_004365d8 = (iVar2 + -500) / 3;
    FUN_00423cc0(local_1c,DAT_004365d8,(iVar2 + -500) % 3);
    local_8 = local_8 & 0xffffff00;
    FUN_00423c8c();
    local_8 = 0xffffffff;
    FUN_00423c9e();
    uVar3 = 1;
  }
  *unaff_FS_OFFSET = local_10;
  return uVar3;
}


