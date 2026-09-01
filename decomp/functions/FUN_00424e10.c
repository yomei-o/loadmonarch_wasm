/* 00424e10 */

undefined4 * __thiscall FUN_00424e10(void *this,LPCSTR param_1)

{
  char cVar1;
  LSTATUS LVar2;
  int iVar3;
  DWORD cbData;
  uint uVar4;
  char *pcVar5;
  DWORD local_110;
  uint local_10c;
  DWORD local_108;
  BYTE local_104 [260];
  
  FUN_00424f60(this,param_1);
  *(undefined4 *)this = 0x2c;
  *(undefined4 *)((int)this + 4) = 0;
  while( true ) {
    LVar2 = RegCreateKeyExA((HKEY)0x80000002,(LPCSTR)((int)this + 0x44),0,(LPSTR)0x0,0,0xf003f,
                            (LPSECURITY_ATTRIBUTES)0x0,(PHKEY)((int)this + 0x148),&local_110);
    if (LVar2 != 0) {
      return this;
    }
    if (local_110 == 1) break;
    local_10c = 0xffffffff;
    pcVar5 = &DAT_00434484;
    do {
      if (local_10c == 0) break;
      local_10c = local_10c - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    local_108 = 1;
    local_10c = ~local_10c;
    LVar2 = RegQueryValueExA(*(HKEY *)((int)this + 0x148),&DAT_00434480,(LPDWORD)0x0,&local_108,
                             local_104,&local_10c);
    if (LVar2 == 0) {
      uVar4 = 0xffffffff;
      pcVar5 = &DAT_00434484;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      iVar3 = _strncmp(&DAT_00434484,(char *)local_104,~uVar4 - 1);
      if (iVar3 == 0) {
        return this;
      }
    }
    RegDeleteKeyA((HKEY)0x80000002,(LPCSTR)((int)this + 0x44));
  }
  cbData = lstrlenA(s_LordMonarch_00434498);
  RegSetValueExA(*(HKEY *)((int)this + 0x148),s_DisplayName_0043448c,0,1,
                 (BYTE *)s_LordMonarch_00434498,cbData);
  uVar4 = 0xffffffff;
  pcVar5 = &DAT_00434484;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  RegSetValueExA(*(HKEY *)((int)this + 0x148),&DAT_00434480,0,1,&DAT_00434484,~uVar4);
  return this;
}


