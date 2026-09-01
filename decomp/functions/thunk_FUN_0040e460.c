/* 0040e300 */

void __fastcall thunk_FUN_0040e460(undefined4 *param_1)

{
  if ((HMENU)*param_1 != (HMENU)0x0) {
    DestroyMenu((HMENU)*param_1);
    *param_1 = 0;
  }
  return;
}


