nonmatching func_8008DC7C, 0x90

glabel func_8008DC7C
    /* 2547C 8008DC7C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 25480 8008DC80 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x68)
    /* 25484 8008DC84 1000B0AF */  sw         $s0, 0x10($sp)
    /* 25488 8008DC88 601C508C */  lw         $s0, %lo(vs_battle_roomData + 0x68)($v0)
    /* 2548C 8008DC8C 00800634 */  ori        $a2, $zero, 0x8000
    /* 25490 8008DC90 18000012 */  beqz       $s0, .L8008DCF4
    /* 25494 8008DC94 1400BFAF */   sw        $ra, 0x14($sp)
    /* 25498 8008DC98 00000386 */  lh         $v1, 0x0($s0)
    /* 2549C 8008DC9C C3110400 */  sra        $v0, $a0, 7
    /* 254A0 8008DCA0 2B104300 */  sltu       $v0, $v0, $v1
    /* 254A4 8008DCA4 13004010 */  beqz       $v0, .L8008DCF4
    /* 254A8 8008DCA8 C3110500 */   sra       $v0, $a1, 7
    /* 254AC 8008DCAC 02000386 */  lh         $v1, 0x2($s0)
    /* 254B0 8008DCB0 00000000 */  nop
    /* 254B4 8008DCB4 2B104300 */  sltu       $v0, $v0, $v1
    /* 254B8 8008DCB8 0E004010 */  beqz       $v0, .L8008DCF4
    /* 254BC 8008DCBC 43210400 */   sra       $a0, $a0, 5
    /* 254C0 8008DCC0 43290500 */  sra        $a1, $a1, 5
    /* 254C4 8008DCC4 4565020C */  jal        func_80099514
    /* 254C8 8008DCC8 21300000 */   addu      $a2, $zero, $zero
    /* 254CC 8008DCCC FF004630 */  andi       $a2, $v0, 0xFF
    /* 254D0 8008DCD0 04000286 */  lh         $v0, 0x4($s0)
    /* 254D4 8008DCD4 7F00C330 */  andi       $v1, $a2, 0x7F
    /* 254D8 8008DCD8 40180300 */  sll        $v1, $v1, 1
    /* 254DC 8008DCDC 23104300 */  subu       $v0, $v0, $v1
    /* 254E0 8008DCE0 C0100200 */  sll        $v0, $v0, 3
    /* 254E4 8008DCE4 FF7F4230 */  andi       $v0, $v0, 0x7FFF
    /* 254E8 8008DCE8 8000C330 */  andi       $v1, $a2, 0x80
    /* 254EC 8008DCEC 001A0300 */  sll        $v1, $v1, 8
    /* 254F0 8008DCF0 25304300 */  or         $a2, $v0, $v1
  .L8008DCF4:
    /* 254F4 8008DCF4 00140600 */  sll        $v0, $a2, 16
    /* 254F8 8008DCF8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 254FC 8008DCFC 1000B08F */  lw         $s0, 0x10($sp)
    /* 25500 8008DD00 03140200 */  sra        $v0, $v0, 16
    /* 25504 8008DD04 0800E003 */  jr         $ra
    /* 25508 8008DD08 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008DC7C
