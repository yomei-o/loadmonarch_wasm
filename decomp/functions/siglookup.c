/* 0042d9e0 */

/* Library Function - Single Match
    _siglookup
   
   Library: Visual Studio 1998 Release */

uint __cdecl siglookup(int param_1)

{
  undefined *puVar1;
  
  puVar1 = &DAT_00434ab8;
  do {
    if (*(int *)(puVar1 + 4) == param_1) break;
    puVar1 = puVar1 + 0xc;
  } while (puVar1 < &DAT_00434ab8 + DAT_00434b38 * 0xc);
  return -(uint)(*(int *)(puVar1 + 4) == param_1) & (uint)puVar1;
}


