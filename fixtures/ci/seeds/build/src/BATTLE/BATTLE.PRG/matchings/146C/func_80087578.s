nonmatching func_80087578, 0x50

glabel func_80087578
    /* 1ED78 80087578 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1ED7C 8008757C 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 1ED80 80087580 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 1ED84 80087584 80100400 */  sll        $v0, $a0, 2
    /* 1ED88 80087588 21104300 */  addu       $v0, $v0, $v1
    /* 1ED8C 8008758C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1ED90 80087590 0000428C */  lw         $v0, 0x0($v0)
    /* 1ED94 80087594 00000000 */  nop
    /* 1ED98 80087598 27004390 */  lbu        $v1, 0x27($v0)
    /* 1ED9C 8008759C 80000224 */  addiu      $v0, $zero, 0x80
    /* 1EDA0 800875A0 03006214 */  bne        $v1, $v0, .L800875B0
    /* 1EDA4 800875A4 00000000 */   nop
    /* 1EDA8 800875A8 03008014 */  bnez       $a0, .L800875B8
    /* 1EDAC 800875AC 00000000 */   nop
  .L800875B0:
    /* 1EDB0 800875B0 DA4E020C */  jal        func_80093B68
    /* 1EDB4 800875B4 00000000 */   nop
  .L800875B8:
    /* 1EDB8 800875B8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1EDBC 800875BC 00000000 */  nop
    /* 1EDC0 800875C0 0800E003 */  jr         $ra
    /* 1EDC4 800875C4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80087578
