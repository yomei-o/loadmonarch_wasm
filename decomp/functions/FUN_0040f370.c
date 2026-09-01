/* 0040f370 */

void __thiscall FUN_0040f370(void *this,int param_1)

{
  LPSTR lpFileName;
  bool bVar1;
  HANDLE hFindFile;
  DWORD DVar2;
  undefined3 extraout_var;
  int iVar3;
  BOOL BVar4;
  int aiStack_18c [3];
  undefined4 uStack_180;
  ushort uStack_17a;
  undefined4 uStack_168;
  int iStack_15c;
  _WIN32_FIND_DATAA local_140;
  
  lpFileName = (LPSTR)((int)this + 0x1c);
  SendDlgItemMessageA(*(HWND *)((int)this + 4),param_1,0x184,0,0);
  *(undefined4 *)((int)this + 0x234) = 0;
  FUN_0040bda0(&DAT_00436468,lpFileName,s___ds7_0043227c);
  do {
    hFindFile = FindFirstFileA(lpFileName,&local_140);
    if ((hFindFile != (HANDLE)0xffffffff) || ((DVar2 = GetLastError(), 1 < DVar2 && (DVar2 < 4))))
    goto LAB_0040f3ef;
    bVar1 = FUN_0040c2e0();
  } while (CONCAT31(extraout_var,bVar1) != 0);
  (**(code **)(*(int *)this + 0x38))();
LAB_0040f3ef:
  do {
    FUN_0040bda0(&DAT_00436468,lpFileName,local_140.cFileName);
    iVar3 = FUN_0040c010(lpFileName,aiStack_18c,0x4c);
    if ((iVar3 != 0) && (aiStack_18c[0] != -1)) {
      if (iStack_15c == -1) {
        wsprintfA(lpFileName,s__s___Map_d__dLeft____4d__2d__2d_0043352c,local_140.cFileName,
                  aiStack_18c[0] + 1,uStack_168,uStack_180 & 0xffff,(uint)uStack_180._2_2_,
                  (uint)uStack_17a);
      }
      else {
        wsprintfA(lpFileName,s__s___Map_d_Beginning____4d__2d___0043354c,local_140.cFileName,
                  aiStack_18c[0] + 1,uStack_180 & 0xffff,(uint)uStack_180._2_2_,(uint)uStack_17a);
      }
      *(int *)((int)this + 0x234) = *(int *)((int)this + 0x234) + 1;
      SendDlgItemMessageA(*(HWND *)((int)this + 4),param_1,0x180,0,(LPARAM)lpFileName);
    }
    BVar4 = FindNextFileA(hFindFile,&local_140);
  } while (BVar4 != 0);
  if (hFindFile != (HANDLE)0xffffffff) {
    FindClose(hFindFile);
  }
  if (*(int *)((int)this + 0x234) != 0) {
    FUN_0040ed80(this,param_1,1);
  }
  return;
}


