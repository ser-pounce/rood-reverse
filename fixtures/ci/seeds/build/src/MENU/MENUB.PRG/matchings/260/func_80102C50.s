nonmatching func_80102C50, 0x6C

glabel func_80102C50
    /* 450 80102C50 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 454 80102C54 1000B0AF */  sw         $s0, 0x10($sp)
    /* 458 80102C58 21808000 */  addu       $s0, $a0, $zero
    /* 45C 80102C5C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 460 80102C60 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 464 80102C64 28000424 */   addiu     $a0, $zero, 0x28
    /* 468 80102C68 9223030C */  jal        vs_battle_getMenuItem
    /* 46C 80102C6C 1F000424 */   addiu     $a0, $zero, 0x1F
    /* 470 80102C70 21184000 */  addu       $v1, $v0, $zero
    /* 474 80102C74 21200002 */  addu       $a0, $s0, $zero
    /* 478 80102C78 03000224 */  addiu      $v0, $zero, 0x3
    /* 47C 80102C7C 000062A0 */  sb         $v0, 0x0($v1)
    /* 480 80102C80 12000224 */  addiu      $v0, $zero, 0x12
    /* 484 80102C84 9223030C */  jal        vs_battle_getMenuItem
    /* 488 80102C88 180062A4 */   sh        $v0, 0x18($v1)
    /* 48C 80102C8C 21184000 */  addu       $v1, $v0, $zero
    /* 490 80102C90 02000224 */  addiu      $v0, $zero, 0x2
    /* 494 80102C94 000062A0 */  sb         $v0, 0x0($v1)
    /* 498 80102C98 9B000224 */  addiu      $v0, $zero, 0x9B
    /* 49C 80102C9C 180062A4 */  sh         $v0, 0x18($v1)
    /* 4A0 80102CA0 01000224 */  addiu      $v0, $zero, 0x1
    /* 4A4 80102CA4 060062A0 */  sb         $v0, 0x6($v1)
    /* 4A8 80102CA8 3C0060AC */  sw         $zero, 0x3C($v1)
    /* 4AC 80102CAC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4B0 80102CB0 1000B08F */  lw         $s0, 0x10($sp)
    /* 4B4 80102CB4 0800E003 */  jr         $ra
    /* 4B8 80102CB8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102C50
