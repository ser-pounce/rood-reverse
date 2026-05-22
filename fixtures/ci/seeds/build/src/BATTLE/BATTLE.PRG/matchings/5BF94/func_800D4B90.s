nonmatching func_800D4B90, 0x40

glabel func_800D4B90
    /* 6C390 800D4B90 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C394 800D4B94 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C398 800D4B98 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6C39C 800D4B9C 5C54030C */  jal        func_800D5170
    /* 6C3A0 800D4BA0 21808000 */   addu      $s0, $a0, $zero
    /* 6C3A4 800D4BA4 FF004230 */  andi       $v0, $v0, 0xFF
    /* 6C3A8 800D4BA8 08000492 */  lbu        $a0, 0x8($s0)
    /* 6C3AC 800D4BAC 21280002 */  addu       $a1, $s0, $zero
    /* 6C3B0 800D4BB0 26208200 */  xor        $a0, $a0, $v0
    /* 6C3B4 800D4BB4 B751030C */  jal        func_800D46DC
    /* 6C3B8 800D4BB8 0100842C */   sltiu     $a0, $a0, 0x1
    /* 6C3BC 800D4BBC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6C3C0 800D4BC0 1000B08F */  lw         $s0, 0x10($sp)
    /* 6C3C4 800D4BC4 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C3C8 800D4BC8 0800E003 */  jr         $ra
    /* 6C3CC 800D4BCC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D4B90
