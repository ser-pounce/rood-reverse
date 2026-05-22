nonmatching func_800CB114, 0x44

glabel func_800CB114
    /* 62914 800CB114 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 62918 800CB118 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6291C 800CB11C 0F80103C */  lui        $s0, %hi(vs_battle_menuItems)
    /* 62920 800CB120 C0B9028E */  lw         $v0, %lo(vs_battle_menuItems)($s0)
    /* 62924 800CB124 00000000 */  nop
    /* 62928 800CB128 07004010 */  beqz       $v0, .L800CB148
    /* 6292C 800CB12C 1400BFAF */   sw        $ra, 0x14($sp)
    /* 62930 800CB130 70F8010C */  jal        func_8007E1C0
    /* 62934 800CB134 06000424 */   addiu     $a0, $zero, 0x6
    /* 62938 800CB138 C0B9048E */  lw         $a0, %lo(vs_battle_menuItems)($s0)
    /* 6293C 800CB13C 180F010C */  jal        vs_main_freeHeapR
    /* 62940 800CB140 00000000 */   nop
    /* 62944 800CB144 C0B900AE */  sw         $zero, %lo(vs_battle_menuItems)($s0)
  .L800CB148:
    /* 62948 800CB148 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6294C 800CB14C 1000B08F */  lw         $s0, 0x10($sp)
    /* 62950 800CB150 0800E003 */  jr         $ra
    /* 62954 800CB154 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CB114
