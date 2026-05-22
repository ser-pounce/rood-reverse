nonmatching func_80103080, 0x98

glabel func_80103080
    /* 880 80103080 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 884 80103084 1800B2AF */  sw         $s2, 0x18($sp)
    /* 888 80103088 2190A000 */  addu       $s2, $a1, $zero
    /* 88C 8010308C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 890 80103090 1080113C */  lui        $s1, %hi(vs_mainMenu_itemHelp)
    /* 894 80103094 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 898 80103098 1000B0AF */  sw         $s0, 0x10($sp)
    /* 89C 8010309C 04008290 */  lbu        $v0, 0x4($a0)
    /* 8A0 801030A0 4025238E */  lw         $v1, %lo(vs_mainMenu_itemHelp)($s1)
    /* 8A4 801030A4 40100200 */  sll        $v0, $v0, 1
    /* 8A8 801030A8 21104300 */  addu       $v0, $v0, $v1
    /* 8AC 801030AC 00054294 */  lhu        $v0, 0x500($v0)
    /* 8B0 801030B0 0F80053C */  lui        $a1, %hi(D_800F51A4)
    /* 8B4 801030B4 40100200 */  sll        $v0, $v0, 1
    /* 8B8 801030B8 21106200 */  addu       $v0, $v1, $v0
    /* 8BC 801030BC A451A2AC */  sw         $v0, %lo(D_800F51A4)($a1)
    /* 8C0 801030C0 00008294 */  lhu        $v0, 0x0($a0)
    /* 8C4 801030C4 0F80103C */  lui        $s0, %hi(vs_battle_stringBuf)
    /* 8C8 801030C8 40100200 */  sll        $v0, $v0, 1
    /* 8CC 801030CC 21104300 */  addu       $v0, $v0, $v1
    /* 8D0 801030D0 F4FF4594 */  lhu        $a1, -0xC($v0)
    /* 8D4 801030D4 8C4E048E */  lw         $a0, %lo(vs_battle_stringBuf)($s0)
    /* 8D8 801030D8 40280500 */  sll        $a1, $a1, 1
    /* 8DC 801030DC 171A030C */  jal        vs_battle_printf
    /* 8E0 801030E0 21286500 */   addu      $a1, $v1, $a1
    /* 8E4 801030E4 4025258E */  lw         $a1, %lo(vs_mainMenu_itemHelp)($s1)
    /* 8E8 801030E8 21204000 */  addu       $a0, $v0, $zero
    /* 8EC 801030EC 171A030C */  jal        vs_battle_printf
    /* 8F0 801030F0 0A68A524 */   addiu     $a1, $a1, 0x680A
    /* 8F4 801030F4 8C4E028E */  lw         $v0, %lo(vs_battle_stringBuf)($s0)
    /* 8F8 801030F8 00000000 */  nop
    /* 8FC 801030FC 040042AE */  sw         $v0, 0x4($s2)
    /* 900 80103100 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 904 80103104 1800B28F */  lw         $s2, 0x18($sp)
    /* 908 80103108 1400B18F */  lw         $s1, 0x14($sp)
    /* 90C 8010310C 1000B08F */  lw         $s0, 0x10($sp)
    /* 910 80103110 0800E003 */  jr         $ra
    /* 914 80103114 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80103080
