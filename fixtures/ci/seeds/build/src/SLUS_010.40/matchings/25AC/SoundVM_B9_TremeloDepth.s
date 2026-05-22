nonmatching SoundVM_B9_TremeloDepth, 0x24

glabel SoundVM_B9_TremeloDepth
    /* C734 8001BF34 0000828C */  lw         $v0, 0x0($a0)
    /* C738 8001BF38 00000000 */  nop
    /* C73C 8001BF3C 00004390 */  lbu        $v1, 0x0($v0)
    /* C740 8001BF40 01004224 */  addiu      $v0, $v0, 0x1
    /* C744 8001BF44 000082AC */  sw         $v0, 0x0($a0)
    /* C748 8001BF48 7F006330 */  andi       $v1, $v1, 0x7F
    /* C74C 8001BF4C 001A0300 */  sll        $v1, $v1, 8
    /* C750 8001BF50 0800E003 */  jr         $ra
    /* C754 8001BF54 BA0083A4 */   sh        $v1, 0xBA($a0)
endlabel SoundVM_B9_TremeloDepth
