/* 0041adf0 */

void __cdecl FUN_0041adf0(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  bVar1 = FUN_0041f3f0(param_1 + -1,param_2);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    iVar2 = 0x80;
  }
  uVar3 = iVar2 >> 1;
  iVar2 = param_2 + -1;
  bVar1 = FUN_0041f3f0(param_1 + -1,iVar2);
  if (CONCAT31(extraout_var_00,bVar1) == 0) {
    uVar3 = uVar3 | 0x80;
  }
  uVar3 = (int)uVar3 >> 1;
  bVar1 = FUN_0041f3f0(param_1,iVar2);
  if (CONCAT31(extraout_var_01,bVar1) == 0) {
    uVar3 = uVar3 | 0x80;
  }
  uVar3 = (int)uVar3 >> 1;
  bVar1 = FUN_0041f3f0(param_1 + 1,iVar2);
  if (CONCAT31(extraout_var_02,bVar1) == 0) {
    uVar3 = uVar3 | 0x80;
  }
  uVar3 = (int)uVar3 >> 1;
  bVar1 = FUN_0041f3f0(param_1 + 1,param_2);
  if (CONCAT31(extraout_var_03,bVar1) == 0) {
    uVar3 = uVar3 | 0x80;
  }
  uVar3 = (int)uVar3 >> 1;
  iVar2 = param_2 + 1;
  bVar1 = FUN_0041f3f0(param_1 + 1,iVar2);
  if (CONCAT31(extraout_var_04,bVar1) == 0) {
    uVar3 = uVar3 | 0x80;
  }
  uVar3 = (int)uVar3 >> 1;
  bVar1 = FUN_0041f3f0(param_1,iVar2);
  if (CONCAT31(extraout_var_05,bVar1) == 0) {
    uVar3 = uVar3 | 0x80;
  }
  uVar3 = (int)uVar3 >> 1;
  bVar1 = FUN_0041f3f0(param_1 + -1,iVar2);
  if (CONCAT31(extraout_var_06,bVar1) == 0) {
    uVar3 = uVar3 | 0x80;
  }
  if (param_1 == 0) {
    uVar3 = uVar3 & 0x7c;
  }
  if (param_1 == 0x2f) {
    uVar3 = uVar3 & 199;
  }
  if (param_2 == 0) {
    uVar3 = uVar3 & 0xf1;
  }
  if (param_2 == 0x2f) {
    uVar3 = uVar3 & 0x1f;
  }
  *(undefined1 *)(DAT_0043453c + 0x10 + (param_1 * 0x30 + param_2) * 0x18) = (&DAT_00434300)[uVar3];
  return;
}


