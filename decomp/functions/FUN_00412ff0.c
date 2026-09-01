/* 00412ff0 */

undefined4 __fastcall FUN_00412ff0(void *param_1)

{
  byte bVar1;
  int iVar2;
  void *this;
  int *this_00;
  UINT_PTR UVar3;
  byte *pbVar4;
  char *pcVar5;
  
  FUN_0040a1c0(0x15f96);
  if (DAT_00434544 == 0) {
    pcVar5 = s_Passage_blocked_by_friendly_unit_00433a1c;
  }
  else {
    if (DAT_00434544 != 1) goto LAB_0041302a;
    pcVar5 = s_Powerful_enemies_in_path__00433a00;
  }
  wsprintfA((LPSTR)((int)param_1 + 0x1c),pcVar5);
LAB_0041302a:
  iVar2 = DAT_0043454c;
  *(int *)((int)param_1 + 0x23c) = DAT_0043454c;
  bVar1 = *(byte *)(DAT_00434538 + 0x220 + iVar2 * 0x224);
  iVar2 = 0;
  *(undefined4 *)((int)param_1 + 0x234) = 0;
  *(uint *)((int)param_1 + 0x238) = (uint)bVar1;
  do {
    if ((*(byte *)(DAT_00434538 + 0x21c + iVar2) & 1) != 0) {
      *(int *)((int)param_1 + 0x234) = *(int *)((int)param_1 + 0x234) + 1;
    }
    iVar2 = iVar2 + 0x224;
  } while (iVar2 < 0x8900);
  if (1 < *(int *)((int)param_1 + 0x234)) {
    FUN_0040ed80(param_1,3,1);
    FUN_0040ed80(param_1,4,1);
  }
  FUN_0040ed20(param_1,0x42b,(LPCSTR)((int)param_1 + 0x1c));
  this = (void *)FUN_0040a0c0(60000);
  if (this != (void *)0x0) {
    pbVar4 = (byte *)(*(int *)((int)param_1 + 0x23c) * 0x224 + DAT_00434538);
    FUN_00423f90(this,(uint)*pbVar4,(uint)pbVar4[1],(undefined4 *)((int)param_1 + 0x244),1);
  }
  this_00 = (int *)FUN_0040a0c0(0xea61);
  if (this_00 != (int *)0x0) {
    FUN_004271b0(this_00,(byte *)(*(int *)((int)param_1 + 0x23c) * 0x224 + DAT_00434538));
    (**(code **)(*this_00 + 100))();
  }
  UVar3 = SetTimer(*(HWND *)((int)param_1 + 4),0x16,100,(TIMERPROC)0x0);
  *(UINT_PTR *)((int)param_1 + 0x230) = UVar3;
  return 1;
}


