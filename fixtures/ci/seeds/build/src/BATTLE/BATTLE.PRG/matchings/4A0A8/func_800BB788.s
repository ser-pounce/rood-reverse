nonmatching func_800BB788, 0x3C

glabel func_800BB788
    /* 52F88 800BB788 00008390 */  lbu        $v1, 0x0($a0)
    /* 52F8C 800BB78C 00000000 */  nop
    /* 52F90 800BB790 0A006010 */  beqz       $v1, .L800BB7BC
    /* 52F94 800BB794 FFFF6324 */   addiu     $v1, $v1, -0x1
    /* 52F98 800BB798 01008290 */  lbu        $v0, 0x1($a0)
    /* 52F9C 800BB79C 000083A0 */  sb         $v1, 0x0($a0)
    /* 52FA0 800BB7A0 01004324 */  addiu      $v1, $v0, 0x1
    /* 52FA4 800BB7A4 FF004230 */  andi       $v0, $v0, 0xFF
    /* 52FA8 800BB7A8 21108200 */  addu       $v0, $a0, $v0
    /* 52FAC 800BB7AC 010083A0 */  sb         $v1, 0x1($a0)
    /* 52FB0 800BB7B0 02004290 */  lbu        $v0, 0x2($v0)
    /* 52FB4 800BB7B4 0800E003 */  jr         $ra
    /* 52FB8 800BB7B8 00000000 */   nop
  .L800BB7BC:
    /* 52FBC 800BB7BC 0800E003 */  jr         $ra
    /* 52FC0 800BB7C0 01000224 */   addiu     $v0, $zero, 0x1
endlabel func_800BB788
