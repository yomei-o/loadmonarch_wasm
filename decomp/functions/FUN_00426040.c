/* 00426040 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

WPARAM __fastcall FUN_00426040(undefined4 *param_1)

{
  char cVar1;
  ATOM AVar2;
  int iVar3;
  HWND hWnd;
  int *piVar4;
  undefined4 *puVar5;
  HACCEL hAccTable;
  BOOL BVar6;
  undefined4 *unaff_FS_OFFSET;
  uchar local_158 [256];
  tagMSG local_58;
  WNDCLASSA local_3c;
  undefined4 *local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00426355;
  *unaff_FS_OFFSET = &local_10;
  GetModuleFileNameA(DAT_004344d0,&DAT_00437588,0x102);
  FUN_00429160(&DAT_00437588,(uchar *)0x0,(uchar *)0x0,local_158,(uchar *)0x0);
  iVar3 = lstrlenA(&DAT_00437588);
  cVar1 = (&DAT_00437588)[iVar3];
  while (cVar1 != '\\') {
    (&DAT_00437588)[iVar3] = 0;
    cVar1 = (&DAT_00437587)[iVar3];
    iVar3 = iVar3 + -1;
  }
  (&DAT_00437588)[iVar3] = 0x5c;
  (&DAT_00437589)[iVar3] = 0;
  hWnd = FindWindowA(s_DS795_FRAME_004321f4,(LPCSTR)0x0);
  if (hWnd == (HWND)0x0) {
    local_3c.hInstance = (HINSTANCE)*param_1;
    local_3c.cbClsExtra = 0;
    local_3c.cbWndExtra = 0;
    local_3c.style = 0x30c8;
    local_3c.lpfnWndProc = (WNDPROC)&LAB_00426570;
    local_3c.hIcon = LoadIconA(local_3c.hInstance,(LPCSTR)0x6f);
    local_3c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_3c.hbrBackground = GetStockObject(4);
    local_3c.lpszMenuName = (LPCSTR)0x65;
    local_3c.lpszClassName = s_DS795_FRAME_004321f4;
    AVar2 = RegisterClassA(&local_3c);
    if (AVar2 != 0) {
      local_3c.lpszMenuName = (LPCSTR)0x0;
      local_3c.hbrBackground = (HBRUSH)0x0;
      local_3c.style = 0x30cb;
      local_3c.lpfnWndProc = (WNDPROC)&LAB_004264c0;
      local_3c.lpszClassName = s_DS795_WND_0043255c;
      AVar2 = RegisterClassA(&local_3c);
      if (AVar2 != 0) {
        local_14 = (undefined4 *)FUN_00427f90(0x3a8);
        local_8 = 0;
        piVar4 = (int *)0x0;
        if (local_14 != (undefined4 *)0x0) {
          piVar4 = FUN_004070e0(local_14);
        }
        local_8 = 0xffffffff;
        DAT_004344e4 = piVar4;
        if (piVar4 != (int *)0x0) {
          local_14 = (undefined4 *)FUN_00427f90(0x14c);
          local_8 = 1;
          puVar5 = (undefined4 *)0x0;
          if (local_14 != (void *)0x0) {
            puVar5 = FUN_00424e10(local_14,(LPCSTR)local_158);
          }
          local_8 = 0xffffffff;
          DAT_00436460 = puVar5;
          if (puVar5 != (undefined4 *)0x0) {
            FUN_0040bcf0(&DAT_00436468,(undefined2 *)&DAT_00437588);
            FUN_0040e4a0(&DAT_004365f0,0);
            _DAT_00435fe8 = 0;
            _DAT_00435fec = 0;
            _DAT_00435ff0 = 0;
            _DAT_00435ff4 = 0;
            _DAT_00435fd8 = 0x28;
            _DAT_00435ffc = 0;
            _DAT_00435ff8 = 0x100;
            _DAT_00435fe4 = 1;
            _DAT_00435fe6 = 8;
            iVar3 = (**(code **)(*DAT_004344e4 + 4))(0,70000);
            if (iVar3 != 0) {
              BVar6 = 1;
              hAccTable = LoadAcceleratorsA(DAT_004344d0,(LPCSTR)0x71);
              do {
                iVar3 = PeekMessageA(&local_58,(HWND)0x0,0,0,0);
                while ((iVar3 != 0 && (BVar6 = GetMessageA(&local_58,(HWND)0x0,0,0), BVar6 != 0))) {
                  iVar3 = TranslateAcceleratorA(local_58.hwnd,hAccTable,&local_58);
                  if (iVar3 == 0) {
                    TranslateMessage(&local_58);
                    DispatchMessageA(&local_58);
                  }
                  iVar3 = PeekMessageA(&local_58,(HWND)0x0,0,0,0);
                }
                if (DAT_004344e0 == 0) {
                  DAT_004344e0 = 0x1e - DAT_00437698;
                  FUN_0040a5e0();
                  FUN_004263a0();
                }
              } while (BVar6 != 0);
              goto LAB_004260ee;
            }
            (**(code **)(*DAT_004344e4 + 0x3c))();
            DAT_004344e4 = (int *)0x0;
          }
        }
      }
    }
  }
  else {
    BringWindowToTop(hWnd);
    SetForegroundWindow(hWnd);
  }
  local_58.wParam = 0;
LAB_004260ee:
  *unaff_FS_OFFSET = local_10;
  return local_58.wParam;
}


