/* 0042b520 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042b520(UINT param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  
  _DAT_00434898 = 1;
  DAT_00434894 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_00438a94 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_00438a90 + -4), DAT_00438a94 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_00438a94 <= puVar1);
    }
    FUN_0042b5a0((undefined4 *)&DAT_00432054,(undefined4 *)&DAT_0043205c);
  }
  FUN_0042b5a0((undefined4 *)&DAT_00432060,(undefined4 *)&DAT_00432064);
  if (param_3 == 0) {
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  return;
}


