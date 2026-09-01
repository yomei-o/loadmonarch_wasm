/* 0040a870 */

void __cdecl
FUN_0040a870(int param_1,int param_2,int param_3,int param_4,LPCSTR param_5,HDC param_6,int param_7,
            int *param_8)

{
  int iVar1;
  BOOL BVar2;
  tagSIZE *psizl;
  COLORREF local_38 [12];
  tagSIZE local_8;
  
  if (param_8 != (int *)0x0) {
    DAT_004321e0 = param_8;
  }
  local_38[0] = 0xffffff;
  local_38[1] = 0;
  local_38[2] = 0xffffff;
  local_38[3] = 0;
  local_38[5] = 0x505050;
  local_38[6] = 0x505050;
  local_38[7] = 0xffffff;
  local_38[8] = 0xffffff;
  local_38[10] = 0;
  local_38[0xb] = 0xffffff;
  local_38[4] = 0xf5;
  local_38[9] = 0xc80000;
  if (param_7 != 0) {
    psizl = &local_8;
    iVar1 = lstrlenA(param_5);
    BVar2 = GetTextExtentPoint32A(param_6,param_5,iVar1,psizl);
    if ((BVar2 != 0) && (DAT_004321e0 != (int *)0x0)) {
      param_1 = (*DAT_004321e0 - local_8.cx) / 2;
    }
  }
  SetTextColor(param_6,local_38[param_4]);
  iVar1 = lstrlenA(param_5);
  TextOutA(param_6,param_1 + 1,param_2 + 1,param_5,iVar1);
  SetTextColor(param_6,local_38[param_3]);
  iVar1 = lstrlenA(param_5);
  TextOutA(param_6,param_1,param_2,param_5,iVar1);
  return;
}


