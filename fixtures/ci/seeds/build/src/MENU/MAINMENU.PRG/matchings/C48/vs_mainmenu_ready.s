nonmatching vs_mainmenu_ready, 0x50

glabel vs_mainmenu_ready
    /* 11D0 800FA9D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 11D4 800FA9D4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 11D8 800FA9D8 9223030C */  jal        vs_battle_getMenuItem
    /* 11DC 800FA9DC 21200000 */   addu      $a0, $zero, $zero
    /* 11E0 800FA9E0 21204000 */  addu       $a0, $v0, $zero
    /* 11E4 800FA9E4 21180000 */  addu       $v1, $zero, $zero
  .L800FA9E8:
    /* 11E8 800FA9E8 00008290 */  lbu        $v0, 0x0($a0)
    /* 11EC 800FA9EC 00000000 */  nop
    /* 11F0 800FA9F0 0200422C */  sltiu      $v0, $v0, 0x2
    /* 11F4 800FA9F4 06004010 */  beqz       $v0, .L800FAA10
    /* 11F8 800FA9F8 21100000 */   addu      $v0, $zero, $zero
    /* 11FC 800FA9FC 01006324 */  addiu      $v1, $v1, 0x1
    /* 1200 800FAA00 28006228 */  slti       $v0, $v1, 0x28
    /* 1204 800FAA04 F8FF4014 */  bnez       $v0, .L800FA9E8
    /* 1208 800FAA08 40008424 */   addiu     $a0, $a0, 0x40
    /* 120C 800FAA0C 01000224 */  addiu      $v0, $zero, 0x1
  .L800FAA10:
    /* 1210 800FAA10 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1214 800FAA14 00000000 */  nop
    /* 1218 800FAA18 0800E003 */  jr         $ra
    /* 121C 800FAA1C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_mainmenu_ready
