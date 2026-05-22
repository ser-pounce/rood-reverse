nonmatching func_80084F40, 0x54

glabel func_80084F40
    /* 1C740 80084F40 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1C744 80084F44 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1C748 80084F48 2180C000 */  addu       $s0, $a2, $zero
    /* 1C74C 80084F4C 3000A28F */  lw         $v0, 0x30($sp)
    /* 1C750 80084F50 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1C754 80084F54 3B0E020C */  jal        _calculateDamage
    /* 1C758 80084F58 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1C75C 80084F5C F3FF033C */  lui        $v1, (0xFFF3FFFF >> 16)
    /* 1C760 80084F60 FFFF6334 */  ori        $v1, $v1, (0xFFF3FFFF & 0xFFFF)
    /* 1C764 80084F64 1C00048E */  lw         $a0, 0x1C($s0)
    /* 1C768 80084F68 0800053C */  lui        $a1, (0x80000 >> 16)
    /* 1C76C 80084F6C 24208300 */  and        $a0, $a0, $v1
    /* 1C770 80084F70 38000396 */  lhu        $v1, 0x38($s0)
    /* 1C774 80084F74 25208500 */  or         $a0, $a0, $a1
    /* 1C778 80084F78 1C0004AE */  sw         $a0, 0x1C($s0)
    /* 1C77C 80084F7C 21186200 */  addu       $v1, $v1, $v0
    /* 1C780 80084F80 380003A6 */  sh         $v1, 0x38($s0)
    /* 1C784 80084F84 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1C788 80084F88 1800B08F */  lw         $s0, 0x18($sp)
    /* 1C78C 80084F8C 0800E003 */  jr         $ra
    /* 1C790 80084F90 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80084F40
