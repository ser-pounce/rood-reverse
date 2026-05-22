nonmatching SoundVM_AA_ChannelPan, 0x34

glabel SoundVM_AA_ChannelPan
    /* C004 8001B804 0000828C */  lw         $v0, 0x0($a0)
    /* C008 8001B808 F800858C */  lw         $a1, 0xF8($a0)
    /* C00C 8001B80C 00004390 */  lbu        $v1, 0x0($v0)
    /* C010 8001B810 01004224 */  addiu      $v0, $v0, 0x1
    /* C014 8001B814 0300A534 */  ori        $a1, $a1, 0x3
    /* C018 8001B818 000082AC */  sw         $v0, 0x0($a0)
    /* C01C 8001B81C 900080A4 */  sh         $zero, 0x90($a0)
    /* C020 8001B820 F80085AC */  sw         $a1, 0xF8($a0)
    /* C024 8001B824 40006324 */  addiu      $v1, $v1, 0x40
    /* C028 8001B828 FF006330 */  andi       $v1, $v1, 0xFF
    /* C02C 8001B82C 001A0300 */  sll        $v1, $v1, 8
    /* C030 8001B830 0800E003 */  jr         $ra
    /* C034 8001B834 8E0083A4 */   sh        $v1, 0x8E($a0)
endlabel SoundVM_AA_ChannelPan
