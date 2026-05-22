nonmatching PadChkVsync, 0x20

glabel PadChkVsync
    /* 1BFE4 8002B7E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1BFE8 8002B7E8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1BFEC 8002B7EC F8AF000C */  jal        _padChkVsync
    /* 1BFF0 8002B7F0 00000000 */   nop
    /* 1BFF4 8002B7F4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1BFF8 8002B7F8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1BFFC 8002B7FC 0800E003 */  jr         $ra
    /* 1C000 8002B800 00000000 */   nop
endlabel PadChkVsync
