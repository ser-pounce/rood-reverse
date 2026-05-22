nonmatching SoundVM_AF_SustainLevel, 0x30

glabel SoundVM_AF_SustainLevel
    /* CCB8 8001C4B8 0000828C */  lw         $v0, 0x0($a0)
    /* CCBC 8001C4BC 06018394 */  lhu        $v1, 0x106($a0)
    /* CCC0 8001C4C0 00004590 */  lbu        $a1, 0x0($v0)
    /* CCC4 8001C4C4 01004224 */  addiu      $v0, $v0, 0x1
    /* CCC8 8001C4C8 000082AC */  sw         $v0, 0x0($a0)
    /* CCCC 8001C4CC F800828C */  lw         $v0, 0xF8($a0)
    /* CCD0 8001C4D0 F0FF6330 */  andi       $v1, $v1, 0xFFF0
    /* CCD4 8001C4D4 00804234 */  ori        $v0, $v0, 0x8000
    /* CCD8 8001C4D8 25186500 */  or         $v1, $v1, $a1
    /* CCDC 8001C4DC F80082AC */  sw         $v0, 0xF8($a0)
    /* CCE0 8001C4E0 0800E003 */  jr         $ra
    /* CCE4 8001C4E4 060183A4 */   sh        $v1, 0x106($a0)
endlabel SoundVM_AF_SustainLevel
