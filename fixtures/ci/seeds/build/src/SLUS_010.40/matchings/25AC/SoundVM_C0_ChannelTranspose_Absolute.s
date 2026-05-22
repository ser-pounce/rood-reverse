nonmatching SoundVM_C0_ChannelTranspose_Absolute, 0x24

glabel SoundVM_C0_ChannelTranspose_Absolute
    /* C300 8001BB00 0000828C */  lw         $v0, 0x0($a0)
    /* C304 8001BB04 00000000 */  nop
    /* C308 8001BB08 00004390 */  lbu        $v1, 0x0($v0)
    /* C30C 8001BB0C 01004224 */  addiu      $v0, $v0, 0x1
    /* C310 8001BB10 000082AC */  sw         $v0, 0x0($a0)
    /* C314 8001BB14 001E0300 */  sll        $v1, $v1, 24
    /* C318 8001BB18 031E0300 */  sra        $v1, $v1, 24
    /* C31C 8001BB1C 0800E003 */  jr         $ra
    /* C320 8001BB20 E20083A4 */   sh        $v1, 0xE2($a0)
endlabel SoundVM_C0_ChannelTranspose_Absolute
