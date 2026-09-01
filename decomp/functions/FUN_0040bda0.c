/* 0040bda0 */

undefined4 __thiscall FUN_0040bda0(void *this,LPSTR param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 uVar2;
  HANDLE pvVar3;
  int iVar4;
  byte *pbVar5;
  int *piVar6;
  byte bVar7;
  int iVar8;
  undefined4 *unaff_FS_OFFSET;
  char *lpString2;
  _WIN32_FIND_DATAA local_584;
  undefined1 local_444 [544];
  CHAR local_224 [260];
  CHAR local_120 [260];
  int local_1c;
  byte *local_18;
  void *local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040bff9;
  *unaff_FS_OFFSET = &local_10;
  if (*(int *)((int)this + 0x130) != 0) {
    local_14 = this;
    if (*(int *)((int)this + 0x130) != 5) {
      wsprintfA(param_1,s__sSAVE__s_004324f8,&DAT_00437588,param_2);
      uVar2 = 1;
      goto LAB_0040bdd0;
    }
    if (*(int *)((int)this + 0x134) != 0) {
      FUN_0041f8b0((int)local_444);
      local_8 = 0;
      local_18 = (byte *)((int)local_14 + 0xc);
      do {
        iVar8 = 0x19;
        pbVar5 = local_18;
        do {
          *pbVar5 = 0;
          if (*(int *)(pbVar5 + -8) != -1) {
            wsprintfA(local_120,s__s____004324f0,pbVar5 + -4);
            pvVar3 = FindFirstFileA(local_120,&local_584);
            if (pvVar3 == (HANDLE)0xffffffff) {
              DAT_00434530 = GetLastError();
              if (DAT_00434530 == 0x15) {
                *pbVar5 = 0;
              }
              else {
                iVar4 = FUN_0040c3b0();
                if (iVar4 != 0) goto LAB_0040bec4;
                wsprintfA(local_224,s__s_Disk_unusable__004324dc,pbVar5 + -4);
                FUN_00409370(local_224,0);
              }
            }
            else {
LAB_0040bec4:
              *pbVar5 = 1;
            }
          }
          pbVar5 = pbVar5 + 0xc;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        bVar7 = 0;
        iVar8 = 0x19;
        pbVar5 = local_18;
        do {
          bVar1 = *pbVar5;
          pbVar5 = pbVar5 + 0xc;
          bVar7 = bVar7 | bVar1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        if (bVar7 != 0) {
          iVar8 = 0;
          piVar6 = (int *)((int)local_14 + 4);
          goto LAB_0040bf9c;
        }
        iVar8 = 0;
        wsprintfA(local_120,&DAT_004324d8);
        local_1c = 0x19;
        piVar6 = (int *)((int)local_14 + 4);
        do {
          if (*piVar6 != -1) {
            iVar8 = iVar8 + 1;
            lstrcatA(local_120,s_Drive_004324d0);
            lstrcatA(local_120,(LPCSTR)(piVar6 + 1));
            lstrcatA(local_120,&DAT_004324cc);
          }
          piVar6 = piVar6 + 3;
          local_1c = local_1c + -1;
        } while (local_1c != 0);
        if (iVar8 < 2) {
          lpString2 = s_Please_insert_save_disk__0043247c;
        }
        else {
          lpString2 = s_Please_insert_disk_into_one_of_t_00432498;
        }
        lstrcatA(local_120,lpString2);
        iVar8 = FUN_00409370(local_120,5);
      } while (iVar8 == 4);
      local_8 = 0xffffffff;
      FUN_0040c003();
    }
  }
  goto LAB_0040bdce;
  while( true ) {
    piVar6 = piVar6 + 3;
    iVar8 = iVar8 + 1;
    if (0x18 < iVar8) break;
LAB_0040bf9c:
    if ((*piVar6 != -1) && ((char)piVar6[2] == '\x01')) {
      wsprintfA(param_1,s__sSAVE__s_004324f8,(int)local_14 + iVar8 * 0xc + 8,param_2);
      local_8 = 0xffffffff;
      FUN_0040c003();
      uVar2 = 1;
      goto LAB_0040bdd0;
    }
  }
  local_8 = 0xffffffff;
  FUN_0040c003();
LAB_0040bdce:
  uVar2 = 0;
LAB_0040bdd0:
  *unaff_FS_OFFSET = local_10;
  return uVar2;
}


