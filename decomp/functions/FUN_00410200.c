/* 00410200 */

void __thiscall FUN_00410200(void *this,int param_1)

{
  char *pcVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x8c + (int)*(char *)((int)this + param_1 * 0x118 + 0x368);
  *(undefined4 *)((int)this + param_1 * 0x118 + 0x25c) = 1;
  *(undefined1 *)((int)this + param_1 * 0x118 + 0x268) =
       *(undefined1 *)((int)this + iVar3 * 2 + 0x26a);
  uVar2 = *(ushort *)((int)this + iVar3 * 2 + 0x26a);
  if (uVar2 < 0xe) {
    if (9 < uVar2) {
      *(uint *)((int)this + param_1 * 0x118 + 0x25c) =
           (uint)*(ushort *)((int)this + iVar3 * 2 + 0x26c) << 4;
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x02';
      return;
    }
    switch(uVar2) {
    case 0:
    case 2:
    case 4:
    case 6:
      *(char *)((int)this + param_1 * 0x118 + 0x36b) = (char)uVar2;
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x01';
      return;
    }
  }
  else {
    switch(uVar2) {
    case 0xf:
      *(uint *)((int)this + param_1 * 0x118 + 0x25c) =
           (uint)*(ushort *)((int)this + iVar3 * 2 + 0x26c);
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x02';
      return;
    case 0x10:
      *(uint *)((int)this + param_1 * 0x118 + 0x25c) =
           (uint)*(ushort *)((int)this + iVar3 * 2 + 0x26c);
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x02';
      return;
    case 0x12:
      *(byte *)((int)this + param_1 * 0x118 + 0x36a) =
           *(char *)((int)this + param_1 * 0x118 + 0x36c) * '\b' +
           *(char *)((int)this + iVar3 * 2 + 0x26c) | 0xa4;
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x02';
      return;
    case 0x13:
      *(byte *)((int)this + param_1 * 0x118 + 0x36a) =
           *(char *)((int)this + param_1 * 0x118 + 0x36c) * '\b' +
           *(char *)((int)this + iVar3 * 2 + 0x26c) | 0xa0;
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x02';
      return;
    case 0x14:
      *(byte *)((int)this + param_1 * 0x118 + 0x36a) =
           (byte)*(undefined2 *)((int)this + iVar3 * 2 + 0x26c) | 200;
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x02';
      return;
    case 0x15:
      *(undefined4 *)((int)this + param_1 * 0x118 + 0x25c) = 0xffffffff;
      return;
    case 0x16:
      *(uint *)((int)this + 0x5838) = (uint)*(ushort *)((int)this + iVar3 * 2 + 0x26c);
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x02';
      return;
    case 0xff:
      *(undefined1 *)((int)this + param_1 * 0x118 + 600) = 0;
      pcVar1 = (char *)((int)this + param_1 * 0x118 + 0x368);
      *pcVar1 = *pcVar1 + '\x01';
    }
  }
  return;
}


