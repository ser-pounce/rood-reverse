nonmatching SoundVM_AE_DecayRate, 0x34

glabel SoundVM_AE_DecayRate
    /* CC84 8001C484 0000828C */  lw         $v0, 0x0($a0)
    /* CC88 8001C488 06018394 */  lhu        $v1, 0x106($a0)
    /* CC8C 8001C48C 00004590 */  lbu        $a1, 0x0($v0)
    /* CC90 8001C490 01004224 */  addiu      $v0, $v0, 0x1
    /* CC94 8001C494 000082AC */  sw         $v0, 0x0($a0)
    /* CC98 8001C498 F800828C */  lw         $v0, 0xF8($a0)
    /* CC9C 8001C49C 0FFF6330 */  andi       $v1, $v1, 0xFF0F
    /* CCA0 8001C4A0 00104234 */  ori        $v0, $v0, 0x1000
    /* CCA4 8001C4A4 00290500 */  sll        $a1, $a1, 4
    /* CCA8 8001C4A8 25186500 */  or         $v1, $v1, $a1
    /* CCAC 8001C4AC F80082AC */  sw         $v0, 0xF8($a0)
    /* CCB0 8001C4B0 0800E003 */  jr         $ra
    /* CCB4 8001C4B4 060183A4 */   sh        $v1, 0x106($a0)
endlabel SoundVM_AE_DecayRate
