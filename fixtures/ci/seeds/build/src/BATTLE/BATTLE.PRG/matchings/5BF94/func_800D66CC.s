nonmatching func_800D66CC, 0x30

glabel func_800D66CC
    /* 6DECC 800D66CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6DED0 800D66D0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6DED4 800D66D4 340D8394 */  lhu        $v1, 0xD34($a0)
    /* 6DED8 800D66D8 05000224 */  addiu      $v0, $zero, 0x5
    /* 6DEDC 800D66DC 03006214 */  bne        $v1, $v0, .L800D66EC
    /* 6DEE0 800D66E0 00000000 */   nop
    /* 6DEE4 800D66E4 9CB3010C */  jal        func_8006CE70
    /* 6DEE8 800D66E8 380D8424 */   addiu     $a0, $a0, 0xD38
  .L800D66EC:
    /* 6DEEC 800D66EC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6DEF0 800D66F0 00000000 */  nop
    /* 6DEF4 800D66F4 0800E003 */  jr         $ra
    /* 6DEF8 800D66F8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D66CC
