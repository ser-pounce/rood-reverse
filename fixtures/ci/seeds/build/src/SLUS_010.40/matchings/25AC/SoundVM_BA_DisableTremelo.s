nonmatching SoundVM_BA_DisableTremelo, 0x24

glabel SoundVM_BA_DisableTremelo
    /* C7C8 8001BFC8 3400828C */  lw         $v0, 0x34($a0)
    /* C7CC 8001BFCC F800838C */  lw         $v1, 0xF8($a0)
    /* C7D0 8001BFD0 FDFF0524 */  addiu      $a1, $zero, -0x3
    /* C7D4 8001BFD4 EE0080A4 */  sh         $zero, 0xEE($a0)
    /* C7D8 8001BFD8 24104500 */  and        $v0, $v0, $a1
    /* C7DC 8001BFDC 03006334 */  ori        $v1, $v1, 0x3
    /* C7E0 8001BFE0 340082AC */  sw         $v0, 0x34($a0)
    /* C7E4 8001BFE4 0800E003 */  jr         $ra
    /* C7E8 8001BFE8 F80083AC */   sw        $v1, 0xF8($a0)
endlabel SoundVM_BA_DisableTremelo
