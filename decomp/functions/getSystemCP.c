/* 0042b8c0 */

/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Release */

int __cdecl getSystemCP(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_004349bc = 1;
                    /* WARNING: Could not recover jumptable at 0x0042b8dd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_004349bc = 1;
                    /* WARNING: Could not recover jumptable at 0x0042b8f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_004353a0;
  }
  DAT_004349bc = (uint)bVar2;
  return param_1;
}


