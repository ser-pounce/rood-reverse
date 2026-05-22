nonmatching func_8009DC38, 0x54

glabel func_8009DC38
    /* 35438 8009DC38 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3543C 8009DC3C 0F80033C */  lui        $v1, %hi(D_800F4538)
    /* 35440 8009DC40 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 35444 8009DC44 80100400 */  sll        $v0, $a0, 2
    /* 35448 8009DC48 21104300 */  addu       $v0, $v0, $v1
    /* 3544C 8009DC4C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 35450 8009DC50 1000B0AF */  sw         $s0, 0x10($sp)
    /* 35454 8009DC54 0000508C */  lw         $s0, 0x0($v0)
    /* 35458 8009DC58 00000000 */  nop
    /* 3545C 8009DC5C 06000012 */  beqz       $s0, .L8009DC78
    /* 35460 8009DC60 00000000 */   nop
    /* 35464 8009DC64 2377020C */  jal        func_8009DC8C
    /* 35468 8009DC68 00000000 */   nop
    /* 3546C 8009DC6C 1A0000A6 */  sh         $zero, 0x1A($s0)
    /* 35470 8009DC70 180000A6 */  sh         $zero, 0x18($s0)
    /* 35474 8009DC74 340000AE */  sw         $zero, 0x34($s0)
  .L8009DC78:
    /* 35478 8009DC78 1400BF8F */  lw         $ra, 0x14($sp)
    /* 3547C 8009DC7C 1000B08F */  lw         $s0, 0x10($sp)
    /* 35480 8009DC80 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 35484 8009DC84 0800E003 */  jr         $ra
    /* 35488 8009DC88 00000000 */   nop
endlabel func_8009DC38
