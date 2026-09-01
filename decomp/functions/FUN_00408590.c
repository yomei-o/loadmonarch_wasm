/* 00408590 */

undefined4 __thiscall FUN_00408590(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040879c;
  *unaff_FS_OFFSET = &local_10;
  piVar2 = (int *)FUN_0040a0c0(param_1);
  if (piVar2 == (int *)0x0) {
    switch(param_1) {
    case 60000:
      puVar4 = (undefined4 *)FUN_00427f90(0x17f8);
      local_8 = 0;
      piVar2 = (int *)0x0;
      if (puVar4 != (undefined4 *)0x0) {
        piVar2 = FUN_00422610(puVar4);
      }
      break;
    case 0xea61:
      puVar4 = (undefined4 *)FUN_00427f90(0x4ac);
      local_8 = 1;
      piVar2 = (int *)0x0;
      if (puVar4 != (undefined4 *)0x0) {
        piVar2 = FUN_00426630(puVar4);
      }
      break;
    case 0xea62:
      puVar4 = (undefined4 *)FUN_00427f90(0x4ac);
      local_8 = 2;
      piVar2 = (int *)0x0;
      if (puVar4 != (undefined4 *)0x0) {
        piVar2 = FUN_004198e0(puVar4);
      }
      break;
    case 0xea63:
      puVar4 = (undefined4 *)FUN_00427f90(0x1628);
      piVar2 = (int *)0x0;
      local_8 = 3;
      if (puVar4 != (undefined4 *)0x0) {
        piVar2 = FUN_004042b0(puVar4);
      }
      break;
    default:
      goto switchD_004085e8_caseD_ea64;
    case 0xea65:
      puVar4 = (undefined4 *)FUN_00427f90(0x3a0);
      piVar2 = (int *)0x0;
      local_8 = 4;
      if (puVar4 != (undefined4 *)0x0) {
        piVar2 = FUN_0041b700(puVar4);
      }
      break;
    case 0xea66:
    case 0xea67:
    case 0xea68:
    case 0xea69:
      puVar4 = (undefined4 *)FUN_00427f90(0x4a8);
      piVar2 = (int *)0x0;
      local_8 = 5;
      if (puVar4 != (undefined4 *)0x0) {
        piVar2 = FUN_0041cee0(puVar4);
      }
    }
    local_8 = 0xffffffff;
    FUN_00408de0(1);
    if (piVar2 != (int *)0x0) {
      iVar1 = *piVar2;
      iVar5 = (**(code **)(iVar1 + 4))(*(undefined4 *)((int)this + 8),param_1);
      if (iVar5 == 0) {
        (**(code **)(iVar1 + 0x3c))();
      }
    }
    FUN_00408e40();
    FUN_00408de0(0);
    uVar3 = 1;
  }
  else {
    (**(code **)(*piVar2 + 0x3c))();
switchD_004085e8_caseD_ea64:
    uVar3 = 0;
  }
  *unaff_FS_OFFSET = local_10;
  return uVar3;
}


