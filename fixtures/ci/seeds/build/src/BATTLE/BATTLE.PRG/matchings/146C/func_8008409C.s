nonmatching func_8008409C, 0x50

glabel func_8008409C
    /* 1B89C 8008409C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B8A0 800840A0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B8A4 800840A4 2180C000 */  addu       $s0, $a2, $zero
    /* 1B8A8 800840A8 0E000424 */  addiu      $a0, $zero, 0xE
    /* 1B8AC 800840AC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B8B0 800840B0 3304020C */  jal        func_800810CC
    /* 1B8B4 800840B4 21280002 */   addu      $a1, $s0, $zero
    /* 1B8B8 800840B8 08004010 */  beqz       $v0, .L800840DC
    /* 1B8BC 800840BC 00000000 */   nop
    /* 1B8C0 800840C0 FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B8C4 800840C4 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B8C8 800840C8 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B8CC 800840CC 24186200 */  and        $v1, $v1, $v0
    /* 1B8D0 800840D0 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 1B8D4 800840D4 25186200 */  or         $v1, $v1, $v0
    /* 1B8D8 800840D8 1C0003AE */  sw         $v1, 0x1C($s0)
  .L800840DC:
    /* 1B8DC 800840DC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B8E0 800840E0 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B8E4 800840E4 0800E003 */  jr         $ra
    /* 1B8E8 800840E8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008409C
