nonmatching func_80083C18, 0x50

glabel func_80083C18
    /* 1B418 80083C18 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B41C 80083C1C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B420 80083C20 2180C000 */  addu       $s0, $a2, $zero
    /* 1B424 80083C24 14000424 */  addiu      $a0, $zero, 0x14
    /* 1B428 80083C28 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B42C 80083C2C 0804020C */  jal        func_80081020
    /* 1B430 80083C30 21280002 */   addu      $a1, $s0, $zero
    /* 1B434 80083C34 08004010 */  beqz       $v0, .L80083C58
    /* 1B438 80083C38 00000000 */   nop
    /* 1B43C 80083C3C FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B440 80083C40 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B444 80083C44 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B448 80083C48 24186200 */  and        $v1, $v1, $v0
    /* 1B44C 80083C4C 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 1B450 80083C50 25186200 */  or         $v1, $v1, $v0
    /* 1B454 80083C54 1C0003AE */  sw         $v1, 0x1C($s0)
  .L80083C58:
    /* 1B458 80083C58 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B45C 80083C5C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B460 80083C60 0800E003 */  jr         $ra
    /* 1B464 80083C64 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083C18
