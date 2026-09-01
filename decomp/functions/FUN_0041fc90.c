/* 0041fc90 */

void __fastcall FUN_0041fc90(undefined2 *param_1)

{
  undefined2 local_108;
  undefined1 local_106;
  undefined1 local_105;
  CHAR local_104 [260];
  
  local_108 = *param_1;
  local_106 = *(undefined1 *)(param_1 + 1);
  local_105 = 0;
  wsprintfA(&DAT_00435ed0,s_Drive__s_0043410c,&local_108);
  DAT_00434530 = GetLastError();
  switch(DAT_00434530) {
  case 3:
  case 0x13:
    lstrcatA(&DAT_00435ed0,s_Please_check_the_write_protectio_004340b0);
    return;
  default:
    wsprintfA(local_104,s_Could_not_complete_file_operatio_00434008,DAT_00434530);
    lstrcatA(&DAT_00435ed0,local_104);
    return;
  case 5:
  case 0x15:
    lstrcatA(&DAT_00435ed0,s_Please_set_disk__004340d8);
    return;
  case 0xb:
    lstrcatA(&DAT_00435ed0,s_Please_format_disk_00434040);
    return;
  case 0xe:
    lstrcatA(&DAT_00435ed0,s_Not_enough_memory_to_continue__00434090);
    return;
  case 0x1a:
    lstrcatA(&DAT_00435ed0,s_Please_insert_disk_into_drive__004340ec);
    return;
  case 0x70:
    lstrcatA(&DAT_00435ed0,s_Disk_full_please_insert_another_f_00434054);
    return;
  }
}


