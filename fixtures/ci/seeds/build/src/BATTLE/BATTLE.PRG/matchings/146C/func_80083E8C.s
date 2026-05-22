nonmatching func_80083E8C, 0x50

glabel func_80083E8C
    /* 1B68C 80083E8C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B690 80083E90 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B694 80083E94 2180C000 */  addu       $s0, $a2, $zero
    /* 1B698 80083E98 0F000424 */  addiu      $a0, $zero, 0xF
    /* 1B69C 80083E9C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B6A0 80083EA0 0804020C */  jal        func_80081020
    /* 1B6A4 80083EA4 21280002 */   addu      $a1, $s0, $zero
    /* 1B6A8 80083EA8 08004010 */  beqz       $v0, .L80083ECC
    /* 1B6AC 80083EAC 00000000 */   nop
    /* 1B6B0 80083EB0 FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B6B4 80083EB4 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B6B8 80083EB8 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B6BC 80083EBC 24186200 */  and        $v1, $v1, $v0
    /* 1B6C0 80083EC0 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 1B6C4 80083EC4 25186200 */  or         $v1, $v1, $v0
    /* 1B6C8 80083EC8 1C0003AE */  sw         $v1, 0x1C($s0)
  .L80083ECC:
    /* 1B6CC 80083ECC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B6D0 80083ED0 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B6D4 80083ED4 0800E003 */  jr         $ra
    /* 1B6D8 80083ED8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083E8C
