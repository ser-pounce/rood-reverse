nonmatching PadSetActAlign, 0x38

glabel PadSetActAlign
    /* 1C3D0 8002BBD0 0380023C */  lui        $v0, %hi(D_800335B0)
    /* 1C3D4 8002BBD4 B035428C */  lw         $v0, %lo(D_800335B0)($v0)
    /* 1C3D8 8002BBD8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C3DC 8002BBDC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C3E0 8002BBE0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1C3E4 8002BBE4 09F84000 */  jalr       $v0
    /* 1C3E8 8002BBE8 2180A000 */   addu      $s0, $a1, $zero
    /* 1C3EC 8002BBEC 21204000 */  addu       $a0, $v0, $zero
    /* 1C3F0 8002BBF0 D4B4000C */  jal        _padSetActAlign
    /* 1C3F4 8002BBF4 21280002 */   addu      $a1, $s0, $zero
    /* 1C3F8 8002BBF8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1C3FC 8002BBFC 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C400 8002BC00 0800E003 */  jr         $ra
    /* 1C404 8002BC04 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel PadSetActAlign
