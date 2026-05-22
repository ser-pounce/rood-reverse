nonmatching func_80083D7C, 0x70

glabel func_80083D7C
    /* 1B57C 80083D7C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1B580 80083D80 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1B584 80083D84 2188C000 */  addu       $s1, $a2, $zero
    /* 1B588 80083D88 1D000424 */  addiu      $a0, $zero, 0x1D
    /* 1B58C 80083D8C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B590 80083D90 3000B08F */  lw         $s0, 0x30($sp)
    /* 1B594 80083D94 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1B598 80083D98 0804020C */  jal        func_80081020
    /* 1B59C 80083D9C 21282002 */   addu      $a1, $s1, $zero
    /* 1B5A0 80083DA0 0D000012 */  beqz       $s0, .L80083DD8
    /* 1B5A4 80083DA4 0F80033C */   lui       $v1, %hi(vs_battle_actors)
    /* 1B5A8 80083DA8 00002292 */  lbu        $v0, 0x0($s1)
    /* 1B5AC 80083DAC 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 1B5B0 80083DB0 80100200 */  sll        $v0, $v0, 2
    /* 1B5B4 80083DB4 21104300 */  addu       $v0, $v0, $v1
    /* 1B5B8 80083DB8 0000428C */  lw         $v0, 0x0($v0)
    /* 1B5BC 80083DBC 00000000 */  nop
    /* 1B5C0 80083DC0 3C00448C */  lw         $a0, 0x3C($v0)
    /* 1B5C4 80083DC4 00000000 */  nop
    /* 1B5C8 80083DC8 5409828C */  lw         $v0, 0x954($a0)
    /* 1B5CC 80083DCC 0200033C */  lui        $v1, (0x20000 >> 16)
    /* 1B5D0 80083DD0 25104300 */  or         $v0, $v0, $v1
    /* 1B5D4 80083DD4 540982AC */  sw         $v0, 0x954($a0)
  .L80083DD8:
    /* 1B5D8 80083DD8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1B5DC 80083DDC 1400B18F */  lw         $s1, 0x14($sp)
    /* 1B5E0 80083DE0 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B5E4 80083DE4 0800E003 */  jr         $ra
    /* 1B5E8 80083DE8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80083D7C
