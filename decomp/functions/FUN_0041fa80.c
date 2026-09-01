/* 0041fa80 */

undefined4 __thiscall FUN_0041fa80(void *this,LPVOID param_1,DWORD param_2,int param_3)

{
  uint nNumberOfBytesToRead;
  undefined4 uVar1;
  BOOL BVar2;
  int iVar3;
  LPVOID *ppvVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_38 [3];
  LPVOID local_2c [2];
  DWORD local_24;
  uint local_20;
  LPVOID local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0041fb8c;
  *unaff_FS_OFFSET = &local_10;
  if (param_3 == 0) {
    BVar2 = ReadFile(*(HANDLE *)((int)this + 0x108),param_1,param_2,(LPDWORD)((int)this + 0x10c),
                     (LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      FUN_0041fc90(this);
      uVar1 = 0;
      goto LAB_0041fb79;
    }
    if (*(LPDWORD)((int)this + 0x10c) != param_2) {
      uVar1 = 0;
      goto LAB_0041fb79;
    }
  }
  else {
    FUN_00425bd0(local_38);
    local_8 = 0;
    nNumberOfBytesToRead = FUN_0041fbe0((int)this);
    local_14 = (LPVOID)FUN_00425c00(local_38,nNumberOfBytesToRead);
    if (local_14 == (LPVOID)0x0) {
      local_8 = 0xffffffff;
      FUN_0041fb96();
      uVar1 = 0;
      goto LAB_0041fb79;
    }
    BVar2 = ReadFile(*(HANDLE *)((int)this + 0x108),local_14,nNumberOfBytesToRead,
                     (LPDWORD)((int)this + 0x10c),(LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      FUN_0041fc90(this);
      local_8 = 0xffffffff;
      FUN_0041fb96();
      uVar1 = 0;
      goto LAB_0041fb79;
    }
    if (*(LPDWORD)((int)this + 0x10c) != nNumberOfBytesToRead) {
      local_8 = 0xffffffff;
      FUN_0041fb96();
      uVar1 = 0;
      goto LAB_0041fb79;
    }
    ppvVar4 = local_2c;
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppvVar4 = (LPVOID)0x0;
      ppvVar4 = ppvVar4 + 1;
    }
    local_2c[0] = param_1;
    local_2c[1] = local_14;
    local_24 = param_2;
    local_20 = nNumberOfBytesToRead;
    iVar3 = FUN_0041fe40(this,local_2c);
    local_8 = 0xffffffff;
    if (iVar3 != 0) {
      FUN_0041fb96();
      uVar1 = 0;
      goto LAB_0041fb79;
    }
    FUN_0041fb96();
  }
  uVar1 = 1;
LAB_0041fb79:
  *unaff_FS_OFFSET = local_10;
  return uVar1;
}


