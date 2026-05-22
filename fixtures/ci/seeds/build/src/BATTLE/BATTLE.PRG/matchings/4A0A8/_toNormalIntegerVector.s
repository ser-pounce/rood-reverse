nonmatching _toNormalIntegerVector, 0x4C

glabel _toNormalIntegerVector
    /* 56140 800BE940 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 56144 800BE944 2000BFAF */  sw         $ra, 0x20($sp)
    /* 56148 800BE948 0000828C */  lw         $v0, 0x0($a0)
    /* 5614C 800BE94C 00000000 */  nop
    /* 56150 800BE950 03130200 */  sra        $v0, $v0, 12
    /* 56154 800BE954 1000A2AF */  sw         $v0, 0x10($sp)
    /* 56158 800BE958 0400828C */  lw         $v0, 0x4($a0)
    /* 5615C 800BE95C 00000000 */  nop
    /* 56160 800BE960 03130200 */  sra        $v0, $v0, 12
    /* 56164 800BE964 1400A2AF */  sw         $v0, 0x14($sp)
    /* 56168 800BE968 0800828C */  lw         $v0, 0x8($a0)
    /* 5616C 800BE96C 1000A427 */  addiu      $a0, $sp, 0x10
    /* 56170 800BE970 03130200 */  sra        $v0, $v0, 12
    /* 56174 800BE974 A506010C */  jal        VectorNormal
    /* 56178 800BE978 1800A2AF */   sw        $v0, 0x18($sp)
    /* 5617C 800BE97C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 56180 800BE980 00000000 */  nop
    /* 56184 800BE984 0800E003 */  jr         $ra
    /* 56188 800BE988 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _toNormalIntegerVector
