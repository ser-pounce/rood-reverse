nonmatching vs_main_stopMusic, 0x3C

glabel vs_main_stopMusic
    /* 35DF4 800455F4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 35DF8 800455F8 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 35DFC 800455FC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 35E00 80045600 38E0508C */  lw         $s0, %lo(vs_main_soundData)($v0)
    /* 35E04 80045604 00000000 */  nop
    /* 35E08 80045608 05000012 */  beqz       $s0, .L80045620
    /* 35E0C 8004560C 1400BFAF */   sw        $ra, 0x14($sp)
    /* 35E10 80045610 7D13010C */  jal        func_80044DF4
    /* 35E14 80045614 21200002 */   addu      $a0, $s0, $zero
    /* 35E18 80045618 1015010C */  jal        vs_main_freeMusic
    /* 35E1C 8004561C 21200002 */   addu      $a0, $s0, $zero
  .L80045620:
    /* 35E20 80045620 1400BF8F */  lw         $ra, 0x14($sp)
    /* 35E24 80045624 1000B08F */  lw         $s0, 0x10($sp)
    /* 35E28 80045628 0800E003 */  jr         $ra
    /* 35E2C 8004562C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_main_stopMusic
