nonmatching SoundVM_BE_DisableAutoPan, 0x24

glabel SoundVM_BE_DisableAutoPan
    /* C8E4 8001C0E4 3400828C */  lw         $v0, 0x34($a0)
    /* C8E8 8001C0E8 F800838C */  lw         $v1, 0xF8($a0)
    /* C8EC 8001C0EC FBFF0524 */  addiu      $a1, $zero, -0x5
    /* C8F0 8001C0F0 F00080A4 */  sh         $zero, 0xF0($a0)
    /* C8F4 8001C0F4 24104500 */  and        $v0, $v0, $a1
    /* C8F8 8001C0F8 03006334 */  ori        $v1, $v1, 0x3
    /* C8FC 8001C0FC 340082AC */  sw         $v0, 0x34($a0)
    /* C900 8001C100 0800E003 */  jr         $ra
    /* C904 8001C104 F80083AC */   sw        $v1, 0xF8($a0)
endlabel SoundVM_BE_DisableAutoPan
