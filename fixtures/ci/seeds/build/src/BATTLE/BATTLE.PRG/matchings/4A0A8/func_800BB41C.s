nonmatching func_800BB41C, 0x34

glabel func_800BB41C
    /* 52C1C 800BB41C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52C20 800BB420 1000B0AF */  sw         $s0, 0x10($sp)
    /* 52C24 800BB424 1400BFAF */  sw         $ra, 0x14($sp)
    /* 52C28 800BB428 84F5020C */  jal        func_800BD610
    /* 52C2C 800BB42C 21808000 */   addu      $s0, $a0, $zero
    /* 52C30 800BB430 01000392 */  lbu        $v1, 0x1($s0)
    /* 52C34 800BB434 1400BF8F */  lw         $ra, 0x14($sp)
    /* 52C38 800BB438 1000B08F */  lw         $s0, 0x10($sp)
    /* 52C3C 800BB43C 24106200 */  and        $v0, $v1, $v0
    /* 52C40 800BB440 26186200 */  xor        $v1, $v1, $v0
    /* 52C44 800BB444 2B100300 */  sltu       $v0, $zero, $v1
    /* 52C48 800BB448 0800E003 */  jr         $ra
    /* 52C4C 800BB44C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BB41C
