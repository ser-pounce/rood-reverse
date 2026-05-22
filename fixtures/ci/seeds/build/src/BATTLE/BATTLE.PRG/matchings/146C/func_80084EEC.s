nonmatching func_80084EEC, 0x54

glabel func_80084EEC
    /* 1C6EC 80084EEC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1C6F0 80084EF0 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1C6F4 80084EF4 2180C000 */  addu       $s0, $a2, $zero
    /* 1C6F8 80084EF8 3000A28F */  lw         $v0, 0x30($sp)
    /* 1C6FC 80084EFC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1C700 80084F00 3B0E020C */  jal        _calculateDamage
    /* 1C704 80084F04 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1C708 80084F08 CFFF033C */  lui        $v1, (0xFFCFFFFF >> 16)
    /* 1C70C 80084F0C FFFF6334 */  ori        $v1, $v1, (0xFFCFFFFF & 0xFFFF)
    /* 1C710 80084F10 1C00048E */  lw         $a0, 0x1C($s0)
    /* 1C714 80084F14 2000053C */  lui        $a1, (0x200000 >> 16)
    /* 1C718 80084F18 24208300 */  and        $a0, $a0, $v1
    /* 1C71C 80084F1C 3A000396 */  lhu        $v1, 0x3A($s0)
    /* 1C720 80084F20 25208500 */  or         $a0, $a0, $a1
    /* 1C724 80084F24 1C0004AE */  sw         $a0, 0x1C($s0)
    /* 1C728 80084F28 21186200 */  addu       $v1, $v1, $v0
    /* 1C72C 80084F2C 3A0003A6 */  sh         $v1, 0x3A($s0)
    /* 1C730 80084F30 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1C734 80084F34 1800B08F */  lw         $s0, 0x18($sp)
    /* 1C738 80084F38 0800E003 */  jr         $ra
    /* 1C73C 80084F3C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80084EEC
