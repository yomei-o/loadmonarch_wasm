/* 0040ebc0 */

void __thiscall FUN_0040ebc0(void *this,HDC param_1)

{
  tagRECT local_10;
  
  GetClientRect(*(HWND *)((int)this + 4),&local_10);
  StretchBlt(param_1,0,0,local_10.right,local_10.bottom,*(HDC *)((int)this + 0x224),0,0,
             local_10.right,local_10.bottom,0xcc0020);
  return;
}


