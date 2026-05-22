nonmatching func_80102BE4, 0x60

glabel func_80102BE4
    /* 3E4 80102BE4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3E8 80102BE8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3EC 80102BEC 21808000 */  addu       $s0, $a0, $zero
    /* 3F0 80102BF0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 3F4 80102BF4 9223030C */  jal        vs_battle_getMenuItem
    /* 3F8 80102BF8 1F000424 */   addiu     $a0, $zero, 0x1F
    /* 3FC 80102BFC 21184000 */  addu       $v1, $v0, $zero
    /* 400 80102C00 21200002 */  addu       $a0, $s0, $zero
    /* 404 80102C04 02000224 */  addiu      $v0, $zero, 0x2
    /* 408 80102C08 000062A0 */  sb         $v0, 0x0($v1)
    /* 40C 80102C0C 10000224 */  addiu      $v0, $zero, 0x10
    /* 410 80102C10 180062A4 */  sh         $v0, 0x18($v1)
    /* 414 80102C14 A4000224 */  addiu      $v0, $zero, 0xA4
    /* 418 80102C18 9223030C */  jal        vs_battle_getMenuItem
    /* 41C 80102C1C 010062A0 */   sb        $v0, 0x1($v1)
    /* 420 80102C20 21184000 */  addu       $v1, $v0, $zero
    /* 424 80102C24 03000224 */  addiu      $v0, $zero, 0x3
    /* 428 80102C28 000062A0 */  sb         $v0, 0x0($v1)
    /* 42C 80102C2C 12000224 */  addiu      $v0, $zero, 0x12
    /* 430 80102C30 180062A4 */  sh         $v0, 0x18($v1)
    /* 434 80102C34 1400BF8F */  lw         $ra, 0x14($sp)
    /* 438 80102C38 1000B08F */  lw         $s0, 0x10($sp)
    /* 43C 80102C3C 0800E003 */  jr         $ra
    /* 440 80102C40 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102BE4
