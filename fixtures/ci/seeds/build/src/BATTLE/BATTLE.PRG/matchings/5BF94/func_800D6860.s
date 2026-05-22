nonmatching func_800D6860, 0x34

glabel func_800D6860
    /* 6E060 800D6860 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6E064 800D6864 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6E068 800D6868 400D8394 */  lhu        $v1, 0xD40($a0)
    /* 6E06C 800D686C 04000224 */  addiu      $v0, $zero, 0x4
    /* 6E070 800D6870 04006214 */  bne        $v1, $v0, .L800D6884
    /* 6E074 800D6874 00000000 */   nop
    /* 6E078 800D6878 440D8490 */  lbu        $a0, 0xD44($a0)
    /* 6E07C 800D687C 1BA7010C */  jal        func_80069C6C
    /* 6E080 800D6880 00000000 */   nop
  .L800D6884:
    /* 6E084 800D6884 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6E088 800D6888 00000000 */  nop
    /* 6E08C 800D688C 0800E003 */  jr         $ra
    /* 6E090 800D6890 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D6860
