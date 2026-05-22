nonmatching _transitionToSubMenu, 0x60

glabel _transitionToSubMenu
    /* 4BC 80102CBC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4C0 80102CC0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4C4 80102CC4 21808000 */  addu       $s0, $a0, $zero
    /* 4C8 80102CC8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4CC 80102CCC 9223030C */  jal        vs_battle_getMenuItem
    /* 4D0 80102CD0 1F000424 */   addiu     $a0, $zero, 0x1F
    /* 4D4 80102CD4 21184000 */  addu       $v1, $v0, $zero
    /* 4D8 80102CD8 21200002 */  addu       $a0, $s0, $zero
    /* 4DC 80102CDC 02000224 */  addiu      $v0, $zero, 0x2
    /* 4E0 80102CE0 000062A0 */  sb         $v0, 0x0($v1)
    /* 4E4 80102CE4 10000224 */  addiu      $v0, $zero, 0x10
    /* 4E8 80102CE8 180062A4 */  sh         $v0, 0x18($v1)
    /* 4EC 80102CEC A4000224 */  addiu      $v0, $zero, 0xA4
    /* 4F0 80102CF0 9223030C */  jal        vs_battle_getMenuItem
    /* 4F4 80102CF4 010062A0 */   sb        $v0, 0x1($v1)
    /* 4F8 80102CF8 21184000 */  addu       $v1, $v0, $zero
    /* 4FC 80102CFC 03000224 */  addiu      $v0, $zero, 0x3
    /* 500 80102D00 000062A0 */  sb         $v0, 0x0($v1)
    /* 504 80102D04 12000224 */  addiu      $v0, $zero, 0x12
    /* 508 80102D08 180062A4 */  sh         $v0, 0x18($v1)
    /* 50C 80102D0C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 510 80102D10 1000B08F */  lw         $s0, 0x10($sp)
    /* 514 80102D14 0800E003 */  jr         $ra
    /* 518 80102D18 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _transitionToSubMenu
