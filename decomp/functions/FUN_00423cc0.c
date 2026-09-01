/* 00423cc0 */

void __thiscall FUN_00423cc0(void *this,undefined4 param_1,int param_2)

{
  byte *pbVar1;
  uint *puVar2;
  char cVar3;
  bool bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  
  bVar4 = false;
  iVar9 = 0;
  iVar10 = 0;
  do {
    if ((*(byte *)(DAT_00434538 + iVar9 + 0x21c) & 1) != 0) {
      if (DAT_00434548 == 0) {
        cVar3 = *(char *)(DAT_00434538 + iVar9 + 0x220);
        if (cVar3 == '\x03') {
          DAT_00434544 = 1;
        }
        else {
          if (cVar3 != '\x04') goto LAB_00423d3e;
          DAT_00434544 = 0;
        }
        DAT_0043454c = iVar10;
        FUN_004095d0(0x76,0,*(HWND *)(DAT_004344e4 + 8));
      }
LAB_00423d3e:
      if (DAT_00434548 == 2) {
LAB_00423eeb:
        *(undefined1 *)(DAT_00434538 + 0x220 + iVar9) = 0xff;
      }
      else {
        cVar3 = *(char *)(DAT_00434538 + 0x220 + iVar9);
        if (((cVar3 == '\x01') || (DAT_00434548 == 2)) || (cVar3 == -1)) goto LAB_00423eeb;
        bVar4 = true;
        bVar8 = (byte)DAT_004365d8;
        if (param_2 == 1) {
          bVar8 = (byte)DAT_004365d8 | 0x40;
        }
        if (param_2 == 2) {
          bVar8 = bVar8 | 0x80;
        }
        bVar5 = *(byte *)(DAT_00434538 + iVar9 + 0xd) & 0x20;
        if (bVar5 == 0) {
          bVar8 = bVar8 | 0x10;
        }
        else {
          bVar8 = bVar8 & 0xfd | 0xd;
        }
        *(byte *)(DAT_00434538 + iVar9 + 0xd) = bVar8 | bVar5;
        *(undefined1 *)(DAT_00434538 + 2 + iVar9) = *(undefined1 *)((int)this + 0x3c2);
        *(undefined1 *)(DAT_00434538 + 3 + iVar9) = *(undefined1 *)((int)this + 0x3c3);
        pbVar1 = (byte *)(DAT_00434538 + 0x10 + iVar9);
        *pbVar1 = *pbVar1 & 0xf3;
        FUN_00405360();
        FUN_004056f0((byte *)((int)this + 0x3c2));
        FUN_0041a680((uint)*(byte *)(DAT_00434538 + iVar9),(uint)((byte *)(DAT_00434538 + iVar9))[1]
                    );
        *(undefined4 *)(DAT_00434538 + 0x18 + iVar9) = 0x1f0;
        iVar6 = FUN_00405000(iVar10,(uint)*(byte *)((int)this + 0x3c2),
                             (uint)*(byte *)((int)this + 0x3c3));
        if (iVar6 == 1) {
          switch(bVar8 & 0xf) {
          case 6:
          case 7:
          case 9:
          case 10:
          case 0xb:
            FUN_004051b0(iVar10);
          }
switchD_00423e5f_caseD_8:
          iVar6 = DAT_00434538 + iVar9;
          if ((*(byte *)(iVar6 + 0xd) & 0x20) != 0) {
            uVar7 = (uint)*(byte *)(iVar6 + 4);
            if (*(byte *)(DAT_0043453c + 0x10 +
                         ((uint)*(byte *)(iVar6 + 2) * 0x30 + (uint)*(byte *)(iVar6 + 3)) * 0x18) -
                uVar7 == 0x14) {
              puVar2 = (uint *)(DAT_00434534 + 4 + uVar7 * 0x38);
              *puVar2 = *puVar2 & 0xfffffffd;
              puVar2 = (uint *)(DAT_00434534 + 4 + (uint)*(byte *)(DAT_00434538 + 4 + iVar9) * 0x38)
              ;
              *puVar2 = *puVar2 & 0xfffffffb;
            }
            else {
              puVar2 = (uint *)(DAT_00434534 + 4 + uVar7 * 0x38);
              *puVar2 = *puVar2 | 2;
            }
          }
        }
        else if (iVar6 == 10) goto switchD_00423e5f_caseD_8;
      }
      puVar2 = (uint *)(DAT_00434538 + 0x21c + iVar9);
      *puVar2 = *puVar2 & 0xfffffffe;
    }
    iVar9 = iVar9 + 0x224;
    iVar10 = iVar10 + 1;
    if (0x88ff < iVar9) {
      FUN_00409d50(0x9c7e,0);
      FUN_00409d50(0x9c7d,0);
      if (bVar4) {
        FUN_0040a1c0(0x15f92);
      }
      DAT_004321c8 = 0;
      DAT_00434548 = 0;
      DAT_004365dc = 0;
      DAT_00434440 = 0x40;
      return;
    }
  } while( true );
}


