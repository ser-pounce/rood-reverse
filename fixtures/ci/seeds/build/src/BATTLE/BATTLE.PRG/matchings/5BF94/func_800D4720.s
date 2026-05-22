nonmatching func_800D4720, 0x2C

glabel func_800D4720
    /* 6BF20 800D4720 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6BF24 800D4724 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6BF28 800D4728 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6BF2C 800D472C 6654030C */  jal        func_800D5198
    /* 6BF30 800D4730 21808000 */   addu      $s0, $a0, $zero
    /* 6BF34 800D4734 0A0002A6 */  sh         $v0, 0xA($s0)
    /* 6BF38 800D4738 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6BF3C 800D473C 1000B08F */  lw         $s0, 0x10($sp)
    /* 6BF40 800D4740 21100000 */  addu       $v0, $zero, $zero
    /* 6BF44 800D4744 0800E003 */  jr         $ra
    /* 6BF48 800D4748 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D4720
