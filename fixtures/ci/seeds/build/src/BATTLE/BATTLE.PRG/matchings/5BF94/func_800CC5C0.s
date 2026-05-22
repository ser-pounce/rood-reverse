nonmatching func_800CC5C0, 0x40

glabel func_800CC5C0
    /* 63DC0 800CC5C0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 63DC4 800CC5C4 2138A000 */  addu       $a3, $a1, $zero
    /* 63DC8 800CC5C8 03E4033C */  lui        $v1, (0xE403BC00 >> 16)
    /* 63DCC 800CC5CC 00BC6334 */  ori        $v1, $v1, (0xE403BC00 & 0xFFFF)
    /* 63DD0 800CC5D0 00E3053C */  lui        $a1, (0xE3000000 >> 16)
    /* 63DD4 800CC5D4 3F01E624 */  addiu      $a2, $a3, 0x13F
    /* 63DD8 800CC5D8 00E5023C */  lui        $v0, (0xE5000000 >> 16)
    /* 63DDC 800CC5DC 2528E500 */  or         $a1, $a3, $a1
    /* 63DE0 800CC5E0 2530C300 */  or         $a2, $a2, $v1
    /* 63DE4 800CC5E4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 63DE8 800CC5E8 2E33030C */  jal        func_800CCCB8
    /* 63DEC 800CC5EC 2538E200 */   or        $a3, $a3, $v0
    /* 63DF0 800CC5F0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 63DF4 800CC5F4 00000000 */  nop
    /* 63DF8 800CC5F8 0800E003 */  jr         $ra
    /* 63DFC 800CC5FC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CC5C0
