nonmatching func_80102C0C, 0x4C

glabel func_80102C0C
    /* 40C 80102C0C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 410 80102C10 1000B0AF */  sw         $s0, 0x10($sp)
    /* 414 80102C14 21808000 */  addu       $s0, $a0, $zero
    /* 418 80102C18 0B000512 */  beq        $s0, $a1, .L80102C48
    /* 41C 80102C1C 1400BFAF */   sw        $ra, 0x14($sp)
    /* 420 80102C20 0F80023C */  lui        $v0, %hi(vs_battle_menuItems)
    /* 424 80102C24 C0B9428C */  lw         $v0, %lo(vs_battle_menuItems)($v0)
    /* 428 80102C28 80210500 */  sll        $a0, $a1, 6
    /* 42C 80102C2C 80291000 */  sll        $a1, $s0, 6
    /* 430 80102C30 40000624 */  addiu      $a2, $zero, 0x40
    /* 434 80102C34 21204400 */  addu       $a0, $v0, $a0
    /* 438 80102C38 7000030C */  jal        vs_battle_copyAligned
    /* 43C 80102C3C 21284500 */   addu      $a1, $v0, $a1
    /* 440 80102C40 E4FE030C */  jal        vs_mainMenu_deactivateMenuItem
    /* 444 80102C44 21200002 */   addu      $a0, $s0, $zero
  .L80102C48:
    /* 448 80102C48 1400BF8F */  lw         $ra, 0x14($sp)
    /* 44C 80102C4C 1000B08F */  lw         $s0, 0x10($sp)
    /* 450 80102C50 0800E003 */  jr         $ra
    /* 454 80102C54 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102C0C
