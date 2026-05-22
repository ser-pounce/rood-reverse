nonmatching func_800B76A8, 0x64

glabel func_800B76A8
    /* 4EEA8 800B76A8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4EEAC 800B76AC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4EEB0 800B76B0 21808000 */  addu       $s0, $a0, $zero
    /* 4EEB4 800B76B4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4EEB8 800B76B8 80FF020C */  jal        vs_battle_getShort
    /* 4EEBC 800B76BC 01000426 */   addiu     $a0, $s0, 0x1
    /* 4EEC0 800B76C0 94FF020C */  jal        func_800BFE50
    /* 4EEC4 800B76C4 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4EEC8 800B76C8 0F80043C */  lui        $a0, %hi(D_800E9B58)
    /* 4EECC 800B76CC 589B8424 */  addiu      $a0, $a0, %lo(D_800E9B58)
    /* 4EED0 800B76D0 05000792 */  lbu        $a3, 0x5($s0)
    /* 4EED4 800B76D4 03000592 */  lbu        $a1, 0x3($s0)
    /* 4EED8 800B76D8 04000692 */  lbu        $a2, 0x4($s0)
    /* 4EEDC 800B76DC 82190700 */  srl        $v1, $a3, 6
    /* 4EEE0 800B76E0 21186400 */  addu       $v1, $v1, $a0
    /* 4EEE4 800B76E4 21204000 */  addu       $a0, $v0, $zero
    /* 4EEE8 800B76E8 00006390 */  lbu        $v1, 0x0($v1)
    /* 4EEEC 800B76EC 3F00E730 */  andi       $a3, $a3, 0x3F
    /* 4EEF0 800B76F0 8180020C */  jal        func_800A0204
    /* 4EEF4 800B76F4 21286500 */   addu      $a1, $v1, $a1
    /* 4EEF8 800B76F8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4EEFC 800B76FC 1000B08F */  lw         $s0, 0x10($sp)
    /* 4EF00 800B7700 21100000 */  addu       $v0, $zero, $zero
    /* 4EF04 800B7704 0800E003 */  jr         $ra
    /* 4EF08 800B7708 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B76A8
