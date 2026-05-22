nonmatching func_800D5198, 0x40

glabel func_800D5198
    /* 6C998 800D5198 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C99C 800D519C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C9A0 800D51A0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6C9A4 800D51A4 5C54030C */  jal        func_800D5170
    /* 6C9A8 800D51A8 21808000 */   addu      $s0, $a0, $zero
    /* 6C9AC 800D51AC 21200002 */  addu       $a0, $s0, $zero
    /* 6C9B0 800D51B0 5C54030C */  jal        func_800D5170
    /* 6C9B4 800D51B4 21804000 */   addu      $s0, $v0, $zero
    /* 6C9B8 800D51B8 FF001032 */  andi       $s0, $s0, 0xFF
    /* 6C9BC 800D51BC FF004230 */  andi       $v0, $v0, 0xFF
    /* 6C9C0 800D51C0 00120200 */  sll        $v0, $v0, 8
    /* 6C9C4 800D51C4 25100202 */  or         $v0, $s0, $v0
    /* 6C9C8 800D51C8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6C9CC 800D51CC 1000B08F */  lw         $s0, 0x10($sp)
    /* 6C9D0 800D51D0 0800E003 */  jr         $ra
    /* 6C9D4 800D51D4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D5198
