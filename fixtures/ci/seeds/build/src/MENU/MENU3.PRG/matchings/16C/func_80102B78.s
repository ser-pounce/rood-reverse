nonmatching func_80102B78, 0x6C

glabel func_80102B78
    /* 378 80102B78 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 37C 80102B7C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 380 80102B80 21808000 */  addu       $s0, $a0, $zero
    /* 384 80102B84 1400BFAF */  sw         $ra, 0x14($sp)
    /* 388 80102B88 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 38C 80102B8C 28000424 */   addiu     $a0, $zero, 0x28
    /* 390 80102B90 9223030C */  jal        vs_battle_getMenuItem
    /* 394 80102B94 1F000424 */   addiu     $a0, $zero, 0x1F
    /* 398 80102B98 21184000 */  addu       $v1, $v0, $zero
    /* 39C 80102B9C 21200002 */  addu       $a0, $s0, $zero
    /* 3A0 80102BA0 03000224 */  addiu      $v0, $zero, 0x3
    /* 3A4 80102BA4 000062A0 */  sb         $v0, 0x0($v1)
    /* 3A8 80102BA8 12000224 */  addiu      $v0, $zero, 0x12
    /* 3AC 80102BAC 9223030C */  jal        vs_battle_getMenuItem
    /* 3B0 80102BB0 180062A4 */   sh        $v0, 0x18($v1)
    /* 3B4 80102BB4 21184000 */  addu       $v1, $v0, $zero
    /* 3B8 80102BB8 02000224 */  addiu      $v0, $zero, 0x2
    /* 3BC 80102BBC 000062A0 */  sb         $v0, 0x0($v1)
    /* 3C0 80102BC0 9B000224 */  addiu      $v0, $zero, 0x9B
    /* 3C4 80102BC4 180062A4 */  sh         $v0, 0x18($v1)
    /* 3C8 80102BC8 01000224 */  addiu      $v0, $zero, 0x1
    /* 3CC 80102BCC 060062A0 */  sb         $v0, 0x6($v1)
    /* 3D0 80102BD0 3C0060AC */  sw         $zero, 0x3C($v1)
    /* 3D4 80102BD4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 3D8 80102BD8 1000B08F */  lw         $s0, 0x10($sp)
    /* 3DC 80102BDC 0800E003 */  jr         $ra
    /* 3E0 80102BE0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102B78
