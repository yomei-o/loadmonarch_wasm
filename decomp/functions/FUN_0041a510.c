/* 0041a510 */

undefined4 __thiscall FUN_0041a510(void *this,LPCSTR param_1)

{
  int *this_00;
  UINT UVar1;
  int iVar2;
  LPSTR lpReturnedString;
  uint uVar3;
  uint uVar4;
  CHAR local_104 [260];
  
  UVar1 = GetPrivateProfileIntA(s_entry_00432618,&DAT_00433f98,0,param_1);
  if ((UVar1 != 0) && (UVar1 < 0x35)) {
    this_00 = (int *)((int)this + 8);
    *(UINT *)((int)this + 4) = UVar1;
    FUN_00425c80(this_00);
    FUN_00425c20(this_00);
    iVar2 = FUN_00425c00(this_00,UVar1 * 0x208);
    *(int *)this = iVar2;
    if (iVar2 != 0) {
      GetPrivateProfileStringA
                (s_entry_00432618,s_QESTNAME_00433f84,s_no_qest_00433f90,(LPSTR)((int)this + 0x14),
                 0x104,param_1);
      if (*(int *)((int)this + 4) != 0) {
        iVar2 = 0;
        uVar3 = 0;
        do {
          uVar4 = uVar3 + 1;
          wsprintfA(local_104,&DAT_00432608,uVar3);
          GetPrivateProfileStringA
                    (local_104,&DAT_00433f7c,&DAT_00433f7c,(LPSTR)(*(int *)this + iVar2 + 0x104),
                     0x104,param_1);
          lpReturnedString = (LPSTR)(*(int *)this + iVar2);
          iVar2 = iVar2 + 0x208;
          GetPrivateProfileStringA
                    (local_104,&DAT_00432620,s_no_name_00432628,lpReturnedString,0x104,param_1);
          uVar3 = uVar4;
        } while (uVar4 < *(uint *)((int)this + 4));
      }
      return 1;
    }
  }
  return 0;
}


