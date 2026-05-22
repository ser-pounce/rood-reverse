nonmatching func_80103118, 0x64

glabel func_80103118
    /* 918 80103118 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 91C 8010311C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 920 80103120 2188A000 */  addu       $s1, $a1, $zero
    /* 924 80103124 1080033C */  lui        $v1, %hi(vs_mainMenu_itemHelp)
    /* 928 80103128 1000B0AF */  sw         $s0, 0x10($sp)
    /* 92C 8010312C 0F80103C */  lui        $s0, %hi(vs_battle_stringBuf)
    /* 930 80103130 60000624 */  addiu      $a2, $zero, 0x60
    /* 934 80103134 1800BFAF */  sw         $ra, 0x18($sp)
    /* 938 80103138 00008294 */  lhu        $v0, 0x0($a0)
    /* 93C 8010313C 4025638C */  lw         $v1, %lo(vs_mainMenu_itemHelp)($v1)
    /* 940 80103140 40100200 */  sll        $v0, $v0, 1
    /* 944 80103144 21104300 */  addu       $v0, $v0, $v1
    /* 948 80103148 E8FE4594 */  lhu        $a1, -0x118($v0)
    /* 94C 8010314C 8C4E048E */  lw         $a0, %lo(vs_battle_stringBuf)($s0)
    /* 950 80103150 40280500 */  sll        $a1, $a1, 1
    /* 954 80103154 7800030C */  jal        vs_battle_memcpy
    /* 958 80103158 21286500 */   addu      $a1, $v1, $a1
    /* 95C 8010315C 8C4E028E */  lw         $v0, %lo(vs_battle_stringBuf)($s0)
    /* 960 80103160 00000000 */  nop
    /* 964 80103164 040022AE */  sw         $v0, 0x4($s1)
    /* 968 80103168 1800BF8F */  lw         $ra, 0x18($sp)
    /* 96C 8010316C 1400B18F */  lw         $s1, 0x14($sp)
    /* 970 80103170 1000B08F */  lw         $s0, 0x10($sp)
    /* 974 80103174 0800E003 */  jr         $ra
    /* 978 80103178 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80103118
