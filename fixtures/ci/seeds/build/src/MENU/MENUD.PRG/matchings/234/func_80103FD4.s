nonmatching func_80103FD4, 0x60

glabel func_80103FD4
    /* 17D4 80103FD4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 17D8 80103FD8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 17DC 80103FDC 21808000 */  addu       $s0, $a0, $zero
    /* 17E0 80103FE0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 17E4 80103FE4 9223030C */  jal        vs_battle_getMenuItem
    /* 17E8 80103FE8 1F000424 */   addiu     $a0, $zero, 0x1F
    /* 17EC 80103FEC 21184000 */  addu       $v1, $v0, $zero
    /* 17F0 80103FF0 21200002 */  addu       $a0, $s0, $zero
    /* 17F4 80103FF4 02000224 */  addiu      $v0, $zero, 0x2
    /* 17F8 80103FF8 000062A0 */  sb         $v0, 0x0($v1)
    /* 17FC 80103FFC 10000224 */  addiu      $v0, $zero, 0x10
    /* 1800 80104000 180062A4 */  sh         $v0, 0x18($v1)
    /* 1804 80104004 A4000224 */  addiu      $v0, $zero, 0xA4
    /* 1808 80104008 9223030C */  jal        vs_battle_getMenuItem
    /* 180C 8010400C 010062A0 */   sb        $v0, 0x1($v1)
    /* 1810 80104010 21184000 */  addu       $v1, $v0, $zero
    /* 1814 80104014 03000224 */  addiu      $v0, $zero, 0x3
    /* 1818 80104018 000062A0 */  sb         $v0, 0x0($v1)
    /* 181C 8010401C 12000224 */  addiu      $v0, $zero, 0x12
    /* 1820 80104020 180062A4 */  sh         $v0, 0x18($v1)
    /* 1824 80104024 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1828 80104028 1000B08F */  lw         $s0, 0x10($sp)
    /* 182C 8010402C 0800E003 */  jr         $ra
    /* 1830 80104030 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80103FD4
