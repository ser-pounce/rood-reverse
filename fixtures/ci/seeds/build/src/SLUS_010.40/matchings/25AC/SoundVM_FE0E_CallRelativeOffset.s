nonmatching SoundVM_FE0E_CallRelativeOffset, 0x38

glabel SoundVM_FE0E_CallRelativeOffset
    /* BCA8 8001B4A8 0000828C */  lw         $v0, 0x0($a0)
    /* BCAC 8001B4AC 00000000 */  nop
    /* BCB0 8001B4B0 00004390 */  lbu        $v1, 0x0($v0)
    /* BCB4 8001B4B4 01004590 */  lbu        $a1, 0x1($v0)
    /* BCB8 8001B4B8 02004224 */  addiu      $v0, $v0, 0x2
    /* BCBC 8001B4BC 140082AC */  sw         $v0, 0x14($a0)
    /* BCC0 8001B4C0 0000828C */  lw         $v0, 0x0($a0)
    /* BCC4 8001B4C4 002A0500 */  sll        $a1, $a1, 8
    /* BCC8 8001B4C8 25186500 */  or         $v1, $v1, $a1
    /* BCCC 8001B4CC 001C0300 */  sll        $v1, $v1, 16
    /* BCD0 8001B4D0 031C0300 */  sra        $v1, $v1, 16
    /* BCD4 8001B4D4 21104300 */  addu       $v0, $v0, $v1
    /* BCD8 8001B4D8 0800E003 */  jr         $ra
    /* BCDC 8001B4DC 000082AC */   sw        $v0, 0x0($a0)
endlabel SoundVM_FE0E_CallRelativeOffset
