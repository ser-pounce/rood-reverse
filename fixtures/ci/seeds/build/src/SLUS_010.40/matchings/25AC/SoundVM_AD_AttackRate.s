nonmatching SoundVM_AD_AttackRate, 0x44

glabel SoundVM_AD_AttackRate
    /* CC40 8001C440 0001053C */  lui        $a1, (0x1000000 >> 16)
    /* CC44 8001C444 0000828C */  lw         $v0, 0x0($a0)
    /* CC48 8001C448 F800838C */  lw         $v1, 0xF8($a0)
    /* CC4C 8001C44C 00004690 */  lbu        $a2, 0x0($v0)
    /* CC50 8001C450 01004224 */  addiu      $v0, $v0, 0x1
    /* CC54 8001C454 000082AC */  sw         $v0, 0x0($a0)
    /* CC58 8001C458 3400828C */  lw         $v0, 0x34($a0)
    /* CC5C 8001C45C 00096334 */  ori        $v1, $v1, 0x900
    /* CC60 8001C460 F80083AC */  sw         $v1, 0xF8($a0)
    /* CC64 8001C464 06018394 */  lhu        $v1, 0x106($a0)
    /* CC68 8001C468 25104500 */  or         $v0, $v0, $a1
    /* CC6C 8001C46C FF806330 */  andi       $v1, $v1, 0x80FF
    /* CC70 8001C470 00320600 */  sll        $a2, $a2, 8
    /* CC74 8001C474 25186600 */  or         $v1, $v1, $a2
    /* CC78 8001C478 340082AC */  sw         $v0, 0x34($a0)
    /* CC7C 8001C47C 0800E003 */  jr         $ra
    /* CC80 8001C480 060183A4 */   sh        $v1, 0x106($a0)
endlabel SoundVM_AD_AttackRate
