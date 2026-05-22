nonmatching GetDispEnv, 0x34

glabel GetDispEnv
    /* 19B78 80029378 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 19B7C 8002937C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 19B80 80029380 21808000 */  addu       $s0, $a0, $zero
    /* 19B84 80029384 0380053C */  lui        $a1, %hi(D_800334B0)
    /* 19B88 80029388 B034A524 */  addiu      $a1, $a1, %lo(D_800334B0)
    /* 19B8C 8002938C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 19B90 80029390 A99B000C */  jal        memcpy
    /* 19B94 80029394 14000624 */   addiu     $a2, $zero, 0x14
    /* 19B98 80029398 21100002 */  addu       $v0, $s0, $zero
    /* 19B9C 8002939C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 19BA0 800293A0 1000B08F */  lw         $s0, 0x10($sp)
    /* 19BA4 800293A4 0800E003 */  jr         $ra
    /* 19BA8 800293A8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel GetDispEnv
