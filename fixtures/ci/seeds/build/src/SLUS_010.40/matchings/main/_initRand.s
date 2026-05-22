nonmatching _initRand, 0x5C

glabel _initRand
    /* 32F4C 8004274C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 32F50 80042750 01000424 */  addiu      $a0, $zero, 0x1
    /* 32F54 80042754 1800BFAF */  sw         $ra, 0x18($sp)
    /* 32F58 80042758 1400B1AF */  sw         $s1, 0x14($sp)
    /* 32F5C 8004275C B59B000C */  jal        srand
    /* 32F60 80042760 1000B0AF */   sw        $s0, 0x10($sp)
    /* 32F64 80042764 21880000 */  addu       $s1, $zero, $zero
    /* 32F68 80042768 0580023C */  lui        $v0, %hi(randArr)
    /* 32F6C 8004276C 88FF5024 */  addiu      $s0, $v0, %lo(randArr)
  .L80042770:
    /* 32F70 80042770 B19B000C */  jal        rand
    /* 32F74 80042774 01003126 */   addiu     $s1, $s1, 0x1
    /* 32F78 80042778 000002AE */  sw         $v0, 0x0($s0)
    /* 32F7C 8004277C 6100222A */  slti       $v0, $s1, 0x61
    /* 32F80 80042780 FBFF4014 */  bnez       $v0, .L80042770
    /* 32F84 80042784 04001026 */   addiu     $s0, $s0, 0x4
    /* 32F88 80042788 0580033C */  lui        $v1, %hi(randIndex)
    /* 32F8C 8004278C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 32F90 80042790 1400B18F */  lw         $s1, 0x14($sp)
    /* 32F94 80042794 1000B08F */  lw         $s0, 0x10($sp)
    /* 32F98 80042798 60000224 */  addiu      $v0, $zero, 0x60
    /* 32F9C 8004279C 0C0162AC */  sw         $v0, %lo(randIndex)($v1)
    /* 32FA0 800427A0 0800E003 */  jr         $ra
    /* 32FA4 800427A4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _initRand
