nonmatching func_8007BDD8, 0x38

glabel func_8007BDD8
    /* 135D8 8007BDD8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 135DC 8007BDDC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 135E0 8007BDE0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 135E4 8007BDE4 0331020C */  jal        func_8008C40C
    /* 135E8 8007BDE8 21808000 */   addu      $s0, $a0, $zero
    /* 135EC 8007BDEC 0F80023C */  lui        $v0, %hi(_firstPersonViewEnabled)
    /* 135F0 8007BDF0 27801000 */  nor        $s0, $zero, $s0
    /* 135F4 8007BDF4 01001032 */  andi       $s0, $s0, 0x1
    /* 135F8 8007BDF8 6C1850AC */  sw         $s0, %lo(_firstPersonViewEnabled)($v0)
    /* 135FC 8007BDFC 21100002 */  addu       $v0, $s0, $zero
    /* 13600 8007BE00 1400BF8F */  lw         $ra, 0x14($sp)
    /* 13604 8007BE04 1000B08F */  lw         $s0, 0x10($sp)
    /* 13608 8007BE08 0800E003 */  jr         $ra
    /* 1360C 8007BE0C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007BDD8
