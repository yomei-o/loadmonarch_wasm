/* 0041ac90 */

undefined1 __cdecl FUN_0041ac90(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  
  if (param_4 == param_2) {
    if (param_3 == param_1) {
      uVar1 = 6;
    }
    else {
      uVar1 = 0;
      if (param_1 < param_3) {
        return 4;
      }
    }
  }
  else {
    uVar1 = 2;
    if (param_2 < param_4) {
      return 6;
    }
  }
  return uVar1;
}


