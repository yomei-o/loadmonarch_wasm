/* 0040e560 */

void __thiscall FUN_0040e560(void *this,undefined1 *param_1,int param_2,uint param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_3 != 0) {
    puVar2 = &DAT_00436000 + param_2 * 4;
    puVar1 = (undefined1 *)((int)this + param_2 * 4 + 0xc);
    do {
      if ((9 < uVar3 + param_2) && (uVar3 + param_2 < 0xf6)) {
        *puVar1 = *param_1;
        puVar1[1] = param_1[1];
        puVar1[2] = param_1[2];
        puVar1[3] = 1;
        *puVar2 = param_1[2];
        puVar2[1] = param_1[1];
        puVar2[2] = *param_1;
        puVar2[3] = 0;
      }
      puVar2 = puVar2 + 4;
      puVar1 = puVar1 + 4;
      param_1 = param_1 + 4;
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_3);
  }
  return;
}


