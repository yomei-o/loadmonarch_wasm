/* 0041b140 */

undefined4 FUN_0041b140(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = DAT_004365a0;
  uVar2 = DAT_00436430;
  uVar5 = 0;
  DAT_0043643c = 0;
  DAT_0043643d = 0;
  if (DAT_00436404 != 0) {
    iVar1 = DAT_004365a0 * 0x38;
    DAT_0043643d = (&DAT_00436a0c)[DAT_004365a0 * 0xe] != 0;
    if (DAT_00436404 <= (uint)(&DAT_00436a0c)[DAT_004365a0 * 0xe]) {
      return 0;
    }
    DAT_0043643c = 1;
    if ((!(bool)DAT_0043643d) && (DAT_00436a00 <= DAT_004365a0)) {
      DAT_00436a00 = DAT_00436a00 + 1;
    }
    (&DAT_00436a08)[DAT_004365a0 * 0xe] = DAT_004365c8;
    uVar3 = DAT_0043641c;
    (&DAT_00436a18)[iVar4 * 0xe] = uVar2;
    uVar5 = DAT_00436418;
    (&DAT_00436a10)[iVar4 * 0xe] = uVar3;
    uVar2 = DAT_00436414;
    *(undefined4 *)(&DAT_00436a34 + iVar1) = uVar5;
    uVar5 = DAT_00436428;
    *(undefined4 *)(&DAT_00436a30 + iVar1) = uVar2;
    uVar2 = DAT_00436424;
    *(undefined4 *)(&DAT_00436a3c + iVar1) = uVar5;
    uVar5 = DAT_00436420;
    *(undefined4 *)(&DAT_00436a38 + iVar1) = uVar2;
    uVar2 = DAT_00436408;
    (&DAT_00436a28)[iVar4 * 0xe] = uVar5;
    uVar5 = DAT_00436410;
    *(undefined4 *)(&DAT_00436a2c + iVar1) = uVar2;
    uVar2 = DAT_0043642c;
    (&DAT_00436a20)[iVar4 * 0xe] = uVar5;
    *(undefined4 *)(&DAT_00436a14 + iVar1) = uVar2;
    FUN_0041b240();
    uVar5 = 1;
  }
  return uVar5;
}


