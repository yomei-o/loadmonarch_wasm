/* 00413220 */

void __fastcall FUN_00413220(int param_1)

{
  if ((*(byte *)(param_1 + 0x240) & 1) == 0) {
    *(undefined1 *)(DAT_00434538 + 0x220 + *(int *)(param_1 + 0x23c) * 0x224) = 1;
  }
  else {
    *(undefined1 *)(DAT_00434538 + 0x220 + *(int *)(param_1 + 0x23c) * 0x224) =
         *(undefined1 *)(param_1 + 0x238);
  }
  if (DAT_004344e8 != (int *)0x0) {
    (**(code **)(*DAT_004344e8 + 100))();
  }
  if (DAT_004344f0 != (int *)0x0) {
    (**(code **)(*DAT_004344f0 + 100))();
  }
  *(int *)(param_1 + 0x240) = *(int *)(param_1 + 0x240) + 1;
  return;
}


