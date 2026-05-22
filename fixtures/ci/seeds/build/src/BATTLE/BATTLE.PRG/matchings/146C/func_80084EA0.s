nonmatching func_80084EA0, 0x4C

glabel func_80084EA0
    /* 1C6A0 80084EA0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1C6A4 80084EA4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1C6A8 80084EA8 2180C000 */  addu       $s0, $a2, $zero
    /* 1C6AC 80084EAC 3000A28F */  lw         $v0, 0x30($sp)
    /* 1C6B0 80084EB0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1C6B4 80084EB4 3B0E020C */  jal        _calculateDamage
    /* 1C6B8 80084EB8 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1C6BC 80084EBC 1C00048E */  lw         $a0, 0x1C($s0)
    /* 1C6C0 80084EC0 F3FF0324 */  addiu      $v1, $zero, -0xD
    /* 1C6C4 80084EC4 24208300 */  and        $a0, $a0, $v1
    /* 1C6C8 80084EC8 06000396 */  lhu        $v1, 0x6($s0)
    /* 1C6CC 80084ECC 08008434 */  ori        $a0, $a0, 0x8
    /* 1C6D0 80084ED0 1C0004AE */  sw         $a0, 0x1C($s0)
    /* 1C6D4 80084ED4 21186200 */  addu       $v1, $v1, $v0
    /* 1C6D8 80084ED8 060003A6 */  sh         $v1, 0x6($s0)
    /* 1C6DC 80084EDC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1C6E0 80084EE0 1800B08F */  lw         $s0, 0x18($sp)
    /* 1C6E4 80084EE4 0800E003 */  jr         $ra
    /* 1C6E8 80084EE8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80084EA0
