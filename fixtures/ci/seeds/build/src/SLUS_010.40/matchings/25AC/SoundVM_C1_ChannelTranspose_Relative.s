nonmatching SoundVM_C1_ChannelTranspose_Relative, 0x2C

glabel SoundVM_C1_ChannelTranspose_Relative
    /* C324 8001BB24 0000828C */  lw         $v0, 0x0($a0)
    /* C328 8001BB28 00000000 */  nop
    /* C32C 8001BB2C 00004390 */  lbu        $v1, 0x0($v0)
    /* C330 8001BB30 01004224 */  addiu      $v0, $v0, 0x1
    /* C334 8001BB34 000082AC */  sw         $v0, 0x0($a0)
    /* C338 8001BB38 E2008294 */  lhu        $v0, 0xE2($a0)
    /* C33C 8001BB3C 001E0300 */  sll        $v1, $v1, 24
    /* C340 8001BB40 031E0300 */  sra        $v1, $v1, 24
    /* C344 8001BB44 21104300 */  addu       $v0, $v0, $v1
    /* C348 8001BB48 0800E003 */  jr         $ra
    /* C34C 8001BB4C E20082A4 */   sh        $v0, 0xE2($a0)
endlabel SoundVM_C1_ChannelTranspose_Relative
