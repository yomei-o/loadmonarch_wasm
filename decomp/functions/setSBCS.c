/* 0042b970 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_004348a0;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_004349b0 = 0;
  DAT_004349a4 = 0;
  _DAT_004349a8 = 0;
  DAT_004349b4 = 0;
  DAT_004349b8 = 0;
  return;
}


