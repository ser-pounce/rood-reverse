nonmatching SoundVM_B6_DisableVibrato, 0x24

glabel SoundVM_B6_DisableVibrato
    /* C660 8001BE60 3400828C */  lw         $v0, 0x34($a0)
    /* C664 8001BE64 F800838C */  lw         $v1, 0xF8($a0)
    /* C668 8001BE68 FEFF0524 */  addiu      $a1, $zero, -0x2
    /* C66C 8001BE6C EC0080A4 */  sh         $zero, 0xEC($a0)
    /* C670 8001BE70 24104500 */  and        $v0, $v0, $a1
    /* C674 8001BE74 10006334 */  ori        $v1, $v1, 0x10
    /* C678 8001BE78 340082AC */  sw         $v0, 0x34($a0)
    /* C67C 8001BE7C 0800E003 */  jr         $ra
    /* C680 8001BE80 F80083AC */   sw        $v1, 0xF8($a0)
endlabel SoundVM_B6_DisableVibrato
