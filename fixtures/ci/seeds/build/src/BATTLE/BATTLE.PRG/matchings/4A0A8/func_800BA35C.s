nonmatching func_800BA35C, 0x40

glabel func_800BA35C
    /* 51B5C 800BA35C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51B60 800BA360 1000B0AF */  sw         $s0, 0x10($sp)
    /* 51B64 800BA364 21808000 */  addu       $s0, $a0, $zero
    /* 51B68 800BA368 1400BFAF */  sw         $ra, 0x14($sp)
    /* 51B6C 800BA36C 80FF020C */  jal        vs_battle_getShort
    /* 51B70 800BA370 01000426 */   addiu     $a0, $s0, 0x1
    /* 51B74 800BA374 94FF020C */  jal        func_800BFE50
    /* 51B78 800BA378 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 51B7C 800BA37C 03000592 */  lbu        $a1, 0x3($s0)
    /* 51B80 800BA380 29F2010C */  jal        func_8007C8A4
    /* 51B84 800BA384 21204000 */   addu      $a0, $v0, $zero
    /* 51B88 800BA388 1400BF8F */  lw         $ra, 0x14($sp)
    /* 51B8C 800BA38C 1000B08F */  lw         $s0, 0x10($sp)
    /* 51B90 800BA390 21100000 */  addu       $v0, $zero, $zero
    /* 51B94 800BA394 0800E003 */  jr         $ra
    /* 51B98 800BA398 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA35C
