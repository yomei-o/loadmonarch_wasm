/* 0042b650 */

/* Library Function - Single Match
    __mbsnbcpy
   
   Library: Visual Studio 1998 Release */

uchar * __cdecl __mbsnbcpy(uchar *_Dest,uchar *_Source,size_t _Count)

{
  byte bVar1;
  uchar *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  size_t sVar5;
  
  pbVar4 = _Dest;
  if (DAT_004349a4 == 0) {
    puVar2 = (uchar *)FUN_0042d780((char *)_Dest,(char *)_Source,_Count);
    return puVar2;
  }
  do {
    while( true ) {
      pbVar3 = pbVar4;
      pbVar4 = pbVar3;
      sVar5 = _Count;
      if (_Count == 0) goto joined_r0x0042b6b3;
      sVar5 = _Count - 1;
      bVar1 = *_Source;
      if ((*(byte *)((int)&DAT_004348a0 + bVar1 + 1) & 4) == 0) break;
      *pbVar3 = bVar1;
      pbVar4 = pbVar3 + 1;
      if (sVar5 == 0) {
        *pbVar3 = 0;
        goto joined_r0x0042b6b3;
      }
      bVar1 = _Source[1];
      sVar5 = _Count - 2;
      *pbVar4 = bVar1;
      pbVar4 = pbVar3 + 2;
      _Source = _Source + 2;
      _Count = sVar5;
      if (bVar1 == 0) {
        *pbVar3 = 0;
        goto joined_r0x0042b6b3;
      }
    }
    *pbVar3 = bVar1;
    pbVar4 = pbVar3 + 1;
    _Source = _Source + 1;
    _Count = sVar5;
  } while (bVar1 != 0);
joined_r0x0042b6b3:
  for (; sVar5 != 0; sVar5 = sVar5 - 1) {
    *pbVar4 = 0;
    pbVar4 = pbVar4 + 1;
  }
  return _Dest;
}


