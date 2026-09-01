/* 0040bd30 */

undefined4 __fastcall FUN_0040bd30(int param_1)

{
  UINT UVar1;
  int *piVar2;
  int iVar3;
  char local_4 [4];
  
  local_4[1] = 0x3a;
  local_4[2] = 0x5c;
  local_4[3] = 0;
  piVar2 = (int *)(param_1 + 4);
  iVar3 = 0;
  do {
    local_4[0] = (char)iVar3 + 'A';
    UVar1 = GetDriveTypeA(local_4);
    if (UVar1 == 2) {
      *piVar2 = iVar3;
      *(char *)(piVar2 + 1) = (char)iVar3 + 'A';
      *(undefined1 *)((int)piVar2 + 5) = 0x3a;
      *(undefined1 *)((int)piVar2 + 6) = 0x5c;
      *(undefined1 *)((int)piVar2 + 7) = 0;
      *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + 1;
    }
    piVar2 = piVar2 + 3;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x19);
  return *(undefined4 *)(param_1 + 0x134);
}


