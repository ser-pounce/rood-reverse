nonmatching func_80103F64, 0x70

glabel func_80103F64
    /* 1764 80103F64 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1768 80103F68 1000B0AF */  sw         $s0, 0x10($sp)
    /* 176C 80103F6C 21808000 */  addu       $s0, $a0, $zero
    /* 1770 80103F70 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1774 80103F74 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 1778 80103F78 28000424 */   addiu     $a0, $zero, 0x28
    /* 177C 80103F7C 9223030C */  jal        vs_battle_getMenuItem
    /* 1780 80103F80 1F000424 */   addiu     $a0, $zero, 0x1F
    /* 1784 80103F84 21184000 */  addu       $v1, $v0, $zero
    /* 1788 80103F88 21200002 */  addu       $a0, $s0, $zero
    /* 178C 80103F8C 03000224 */  addiu      $v0, $zero, 0x3
    /* 1790 80103F90 000062A0 */  sb         $v0, 0x0($v1)
    /* 1794 80103F94 12000224 */  addiu      $v0, $zero, 0x12
    /* 1798 80103F98 9223030C */  jal        vs_battle_getMenuItem
    /* 179C 80103F9C 180062A4 */   sh        $v0, 0x18($v1)
    /* 17A0 80103FA0 21184000 */  addu       $v1, $v0, $zero
    /* 17A4 80103FA4 02000224 */  addiu      $v0, $zero, 0x2
    /* 17A8 80103FA8 000062A0 */  sb         $v0, 0x0($v1)
    /* 17AC 80103FAC 9B000224 */  addiu      $v0, $zero, 0x9B
    /* 17B0 80103FB0 180062A4 */  sh         $v0, 0x18($v1)
    /* 17B4 80103FB4 01000224 */  addiu      $v0, $zero, 0x1
    /* 17B8 80103FB8 060062A0 */  sb         $v0, 0x6($v1)
    /* 17BC 80103FBC 3C0060AC */  sw         $zero, 0x3C($v1)
    /* 17C0 80103FC0 070060A0 */  sb         $zero, 0x7($v1)
    /* 17C4 80103FC4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 17C8 80103FC8 1000B08F */  lw         $s0, 0x10($sp)
    /* 17CC 80103FCC 0800E003 */  jr         $ra
    /* 17D0 80103FD0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80103F64
