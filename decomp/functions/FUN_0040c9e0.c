/* 0040c9e0 */

int __thiscall FUN_0040c9e0(void *this,HWND param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040cbf8;
  *unaff_FS_OFFSET = &local_10;
  if (param_1 == (HWND)0x0) {
    iVar1 = 0;
  }
  else {
    DAT_00432588 = GetWindowLongA(param_1,-4);
    DAT_00432588 = SetWindowLongA(param_1,-4,0x40e210);
    *(undefined4 *)((int)this + 0x14) = 0;
    puVar2 = (undefined4 *)FUN_00427f90(0x14);
    local_8 = 0;
    puVar3 = (undefined4 *)0x0;
    if (puVar2 != (undefined4 *)0x0) {
      FUN_0040d940(puVar2);
      *puVar2 = &PTR_LAB_004301d8;
      puVar3 = puVar2;
    }
    local_8 = 0xffffffff;
    DAT_004358d8 = puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      puVar3 = (undefined4 *)FUN_00427f90(0x18);
      local_8 = 1;
      puVar2 = (undefined4 *)0x0;
      if (puVar3 != (undefined4 *)0x0) {
        puVar2 = FUN_0040da60(puVar3);
      }
      local_8 = 0xffffffff;
      DAT_004358dc = puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        piVar4 = (int *)FUN_00427f90(0x45c);
        local_8 = 2;
        piVar5 = (int *)0x0;
        if (piVar4 != (int *)0x0) {
          piVar5 = FUN_0040dd20(piVar4);
        }
        local_8 = 0xffffffff;
        DAT_004358d0 = piVar5;
        if (piVar5 != (int *)0x0) {
          puVar3 = (undefined4 *)FUN_00427f90(0x50);
          local_8 = 3;
          if (puVar3 == (undefined4 *)0x0) {
            puVar3 = (undefined4 *)0x0;
          }
          else {
            FUN_0040db50(puVar3);
            *puVar3 = &PTR_LAB_004301e0;
          }
          local_8 = 0xffffffff;
          DAT_004358c8 = puVar3;
          if (puVar3 != (undefined4 *)0x0) {
            puVar3 = (undefined4 *)FUN_00427f90(0x50);
            local_8 = 5;
            if (puVar3 == (undefined4 *)0x0) {
              puVar3 = (undefined4 *)0x0;
            }
            else {
              FUN_0040db50(puVar3);
              *puVar3 = &PTR_LAB_004301f8;
            }
            DAT_004358cc = puVar3;
            if (puVar3 != (undefined4 *)0x0) {
              *(undefined4 *)((int)this + 0x14) = 1;
            }
          }
        }
      }
    }
    local_8 = 0xffffffff;
    FUN_0040d050(this,3);
    if (DAT_00436598 == 5) {
      DAT_004376b4 = 1;
      FUN_0040d410(this);
    }
    iVar1 = *(int *)((int)this + 0x14);
  }
  *unaff_FS_OFFSET = local_10;
  return iVar1;
}


