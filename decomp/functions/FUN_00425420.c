/* 00425420 */

undefined4 __fastcall FUN_00425420(int *param_1)

{
  uint uVar1;
  HWND pHVar2;
  
  uVar1 = param_1[3];
  if (uVar1 < 0x10) {
    if (uVar1 == 0xf) {
      (**(code **)(*param_1 + 0x40))();
      return 0;
    }
    if (uVar1 == 1) {
      (**(code **)(*param_1 + 0x20))();
      return 0;
    }
    if (uVar1 == 2) {
      (**(code **)(*param_1 + 0x68))();
      return 1;
    }
    return 0;
  }
  if (uVar1 < 0x25) {
    if (uVar1 == 0x24) {
      (**(code **)(*param_1 + 0x60))();
      return 0;
    }
    if (uVar1 == 0x10) {
      (**(code **)(*param_1 + 0x3c))();
      return 0;
    }
    return 0;
  }
  if (uVar1 < 0x112) {
    if (uVar1 == 0x111) {
      (**(code **)(*param_1 + 0x24))();
      return 1;
    }
    if (uVar1 == 0x47) {
      (**(code **)(*param_1 + 0x5c))();
      return 1;
    }
    return 0;
  }
  if (uVar1 < 0x201) {
    if (uVar1 == 0x200) {
      (**(code **)(*param_1 + 0x44))();
      return 0;
    }
    if (uVar1 == 0x113) {
      (**(code **)(*param_1 + 100))();
      return 1;
    }
    return 0;
  }
  if (uVar1 < 0x211) {
    if (uVar1 == 0x210) {
      (**(code **)(*param_1 + 0x6c))();
      return 1;
    }
    switch(uVar1) {
    case 0x201:
      SetCapture((HWND)param_1[2]);
      FUN_00425a30((int)param_1);
      (**(code **)(*param_1 + 0x48))();
      if ((HWND)param_1[0x94] != (HWND)0x0) {
        pHVar2 = GetWindow((HWND)param_1[0x94],5);
        if ((HWND)param_1[2] != pHVar2) {
          BringWindowToTop((HWND)param_1[2]);
        }
      }
      return 0;
    case 0x202:
      ClipCursor((RECT *)0x0);
      (**(code **)(*param_1 + 0x4c))();
      ReleaseCapture();
      *(undefined1 *)(param_1 + 0xe1) = 0;
      param_1[0x9a] = -1;
      param_1[0x9b] = -1;
      return 0;
    case 0x203:
      (**(code **)(*param_1 + 0x50))();
      return 0;
    case 0x204:
      SetCapture((HWND)param_1[2]);
      FUN_00425ad0();
      (**(code **)(*param_1 + 0x58))();
      return 0;
    case 0x205:
      ClipCursor((RECT *)0x0);
      (**(code **)(*param_1 + 0x54))();
      ReleaseCapture();
      *(undefined1 *)(param_1 + 0xe1) = 0;
      param_1[0x9a] = -1;
      param_1[0x9b] = -1;
      return 0;
    }
  }
  else {
    if (uVar1 == 0x214) {
      (**(code **)(*param_1 + 0x30))();
      return 1;
    }
    if (uVar1 == 0x216) {
      (**(code **)(*param_1 + 0x2c))();
      return 1;
    }
    if (uVar1 == 0x30f) {
      FUN_0040e640(0x4365f0);
      return 1;
    }
  }
  return 0;
}


