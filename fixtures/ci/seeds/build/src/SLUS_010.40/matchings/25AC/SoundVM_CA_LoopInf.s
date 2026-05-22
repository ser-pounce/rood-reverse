nonmatching SoundVM_CA_LoopInf, 0x54

glabel SoundVM_CA_LoopInf
    /* D068 8001C868 D0008394 */  lhu        $v1, 0xD0($a0)
    /* D06C 8001C86C 00000000 */  nop
    /* D070 8001C870 40180300 */  sll        $v1, $v1, 1
    /* D074 8001C874 21188300 */  addu       $v1, $a0, $v1
    /* D078 8001C878 72006294 */  lhu        $v0, 0x72($v1)
    /* D07C 8001C87C 00000000 */  nop
    /* D080 8001C880 01004224 */  addiu      $v0, $v0, 0x1
    /* D084 8001C884 720062A4 */  sh         $v0, 0x72($v1)
    /* D088 8001C888 D0008294 */  lhu        $v0, 0xD0($a0)
    /* D08C 8001C88C 00000000 */  nop
    /* D090 8001C890 80100200 */  sll        $v0, $v0, 2
    /* D094 8001C894 21108200 */  addu       $v0, $a0, $v0
    /* D098 8001C898 0400438C */  lw         $v1, 0x4($v0)
    /* D09C 8001C89C D0008294 */  lhu        $v0, 0xD0($a0)
    /* D0A0 8001C8A0 00000000 */  nop
    /* D0A4 8001C8A4 40100200 */  sll        $v0, $v0, 1
    /* D0A8 8001C8A8 21108200 */  addu       $v0, $a0, $v0
    /* D0AC 8001C8AC 000083AC */  sw         $v1, 0x0($a0)
    /* D0B0 8001C8B0 7A004294 */  lhu        $v0, 0x7A($v0)
    /* D0B4 8001C8B4 0800E003 */  jr         $ra
    /* D0B8 8001C8B8 700082A4 */   sh        $v0, 0x70($a0)
endlabel SoundVM_CA_LoopInf
