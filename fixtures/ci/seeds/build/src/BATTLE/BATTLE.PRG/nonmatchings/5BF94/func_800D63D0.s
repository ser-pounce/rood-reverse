nonmatching func_800D63D0, 0x48

glabel func_800D63D0
    /* 6DBD0 800D63D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6DBD4 800D63D4 21288000 */  addu       $a1, $a0, $zero
    /* 6DBD8 800D63D8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6DBDC 800D63DC 1C0DA394 */  lhu        $v1, 0xD1C($a1)
    /* 6DBE0 800D63E0 04000224 */  addiu      $v0, $zero, 0x4
    /* 6DBE4 800D63E4 04006214 */  bne        $v1, $v0, .L800D63F8
    /* 6DBE8 800D63E8 00000000 */   nop
    /* 6DBEC 800D63EC 200DA490 */  lbu        $a0, 0xD20($a1)
    /* 6DBF0 800D63F0 00590308 */  j          .L800D6400
    /* 6DBF4 800D63F4 21280000 */   addu      $a1, $zero, $zero
  .L800D63F8:
    /* 6DBF8 800D63F8 260DA484 */  lh         $a0, 0xD26($a1)
    /* 6DBFC 800D63FC 200DA524 */  addiu      $a1, $a1, 0xD20
  .L800D6400:
    /* 6DC00 800D6400 88B2010C */  jal        func_8006CA20
    /* 6DC04 800D6404 00000000 */   nop
    /* 6DC08 800D6408 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6DC0C 800D640C 00000000 */  nop
    /* 6DC10 800D6410 0800E003 */  jr         $ra
    /* 6DC14 800D6414 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D63D0
