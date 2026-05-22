nonmatching _vectorFixedPointMult, 0x6C

glabel _vectorFixedPointMult
    /* 55EB0 800BE6B0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 55EB4 800BE6B4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 55EB8 800BE6B8 21808000 */  addu       $s0, $a0, $zero
    /* 55EBC 800BE6BC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 55EC0 800BE6C0 2188A000 */  addu       $s1, $a1, $zero
    /* 55EC4 800BE6C4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 55EC8 800BE6C8 2190C000 */  addu       $s2, $a2, $zero
    /* 55ECC 800BE6CC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 55ED0 800BE6D0 0000248E */  lw         $a0, 0x0($s1)
    /* 55ED4 800BE6D4 16FA020C */  jal        _fixedPointMult
    /* 55ED8 800BE6D8 21284002 */   addu      $a1, $s2, $zero
    /* 55EDC 800BE6DC 000002AE */  sw         $v0, 0x0($s0)
    /* 55EE0 800BE6E0 0400248E */  lw         $a0, 0x4($s1)
    /* 55EE4 800BE6E4 16FA020C */  jal        _fixedPointMult
    /* 55EE8 800BE6E8 21284002 */   addu      $a1, $s2, $zero
    /* 55EEC 800BE6EC 040002AE */  sw         $v0, 0x4($s0)
    /* 55EF0 800BE6F0 0800248E */  lw         $a0, 0x8($s1)
    /* 55EF4 800BE6F4 16FA020C */  jal        _fixedPointMult
    /* 55EF8 800BE6F8 21284002 */   addu      $a1, $s2, $zero
    /* 55EFC 800BE6FC 080002AE */  sw         $v0, 0x8($s0)
    /* 55F00 800BE700 21100002 */  addu       $v0, $s0, $zero
    /* 55F04 800BE704 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 55F08 800BE708 1800B28F */  lw         $s2, 0x18($sp)
    /* 55F0C 800BE70C 1400B18F */  lw         $s1, 0x14($sp)
    /* 55F10 800BE710 1000B08F */  lw         $s0, 0x10($sp)
    /* 55F14 800BE714 0800E003 */  jr         $ra
    /* 55F18 800BE718 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _vectorFixedPointMult
