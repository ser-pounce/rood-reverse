nonmatching func_80102F64, 0x11C

glabel func_80102F64
    /* 764 80102F64 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 768 80102F68 1800B2AF */  sw         $s2, 0x18($sp)
    /* 76C 80102F6C 2190A000 */  addu       $s2, $a1, $zero
    /* 770 80102F70 0F80073C */  lui        $a3, %hi(vs_battle_stringContext)
    /* 774 80102F74 6851E724 */  addiu      $a3, $a3, %lo(vs_battle_stringContext)
    /* 778 80102F78 1080053C */  lui        $a1, %hi(vs_mainMenu_itemNames)
    /* 77C 80102F7C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 780 80102F80 1400B1AF */  sw         $s1, 0x14($sp)
    /* 784 80102F84 1000B0AF */  sw         $s0, 0x10($sp)
    /* 788 80102F88 13008390 */  lbu        $v1, 0x13($a0)
    /* 78C 80102F8C 1080113C */  lui        $s1, %hi(vs_mainMenu_itemHelp)
    /* 790 80102F90 40100300 */  sll        $v0, $v1, 1
    /* 794 80102F94 21104300 */  addu       $v0, $v0, $v1
    /* 798 80102F98 C0100200 */  sll        $v0, $v0, 3
    /* 79C 80102F9C 9C22A38C */  lw         $v1, %lo(vs_mainMenu_itemNames)($a1)
    /* 7A0 80102FA0 B8174224 */  addiu      $v0, $v0, 0x17B8
    /* 7A4 80102FA4 21186200 */  addu       $v1, $v1, $v0
    /* 7A8 80102FA8 4C00E3AC */  sw         $v1, 0x4C($a3)
    /* 7AC 80102FAC 04008290 */  lbu        $v0, 0x4($a0)
    /* 7B0 80102FB0 4025268E */  lw         $a2, %lo(vs_mainMenu_itemHelp)($s1)
    /* 7B4 80102FB4 40100200 */  sll        $v0, $v0, 1
    /* 7B8 80102FB8 21104600 */  addu       $v0, $v0, $a2
    /* 7BC 80102FBC 1C034294 */  lhu        $v0, 0x31C($v0)
    /* 7C0 80102FC0 00000000 */  nop
    /* 7C4 80102FC4 40100200 */  sll        $v0, $v0, 1
    /* 7C8 80102FC8 2110C200 */  addu       $v0, $a2, $v0
    /* 7CC 80102FCC 4800E2AC */  sw         $v0, 0x48($a3)
    /* 7D0 80102FD0 10008290 */  lbu        $v0, 0x10($a0)
    /* 7D4 80102FD4 00000000 */  nop
    /* 7D8 80102FD8 40100200 */  sll        $v0, $v0, 1
    /* 7DC 80102FDC 21104600 */  addu       $v0, $v0, $a2
    /* 7E0 80102FE0 30034294 */  lhu        $v0, 0x330($v0)
    /* 7E4 80102FE4 00000000 */  nop
    /* 7E8 80102FE8 40100200 */  sll        $v0, $v0, 1
    /* 7EC 80102FEC 2110C200 */  addu       $v0, $a2, $v0
    /* 7F0 80102FF0 4400E2AC */  sw         $v0, 0x44($a3)
    /* 7F4 80102FF4 1080023C */  lui        $v0, %hi(vs_mainMenu_weaponHands)
    /* 7F8 80102FF8 04008390 */  lbu        $v1, 0x4($a0)
    /* 7FC 80102FFC 40214224 */  addiu      $v0, $v0, %lo(vs_mainMenu_weaponHands)
    /* 800 80103000 21186200 */  addu       $v1, $v1, $v0
    /* 804 80103004 FFFF6290 */  lbu        $v0, -0x1($v1)
    /* 808 80103008 00000000 */  nop
    /* 80C 8010300C 40100200 */  sll        $v0, $v0, 1
    /* 810 80103010 21104600 */  addu       $v0, $v0, $a2
    /* 814 80103014 38034294 */  lhu        $v0, 0x338($v0)
    /* 818 80103018 00000000 */  nop
    /* 81C 8010301C 40100200 */  sll        $v0, $v0, 1
    /* 820 80103020 2110C200 */  addu       $v0, $a2, $v0
    /* 824 80103024 4000E2AC */  sw         $v0, 0x40($a3)
    /* 828 80103028 00008294 */  lhu        $v0, 0x0($a0)
    /* 82C 8010302C 0F80103C */  lui        $s0, %hi(vs_battle_stringBuf)
    /* 830 80103030 40100200 */  sll        $v0, $v0, 1
    /* 834 80103034 21104600 */  addu       $v0, $v0, $a2
    /* 838 80103038 FEFF4594 */  lhu        $a1, -0x2($v0)
    /* 83C 8010303C 8C4E048E */  lw         $a0, %lo(vs_battle_stringBuf)($s0)
    /* 840 80103040 40280500 */  sll        $a1, $a1, 1
    /* 844 80103044 171A030C */  jal        vs_battle_printf
    /* 848 80103048 2128C500 */   addu      $a1, $a2, $a1
    /* 84C 8010304C 4025258E */  lw         $a1, %lo(vs_mainMenu_itemHelp)($s1)
    /* 850 80103050 21204000 */  addu       $a0, $v0, $zero
    /* 854 80103054 171A030C */  jal        vs_battle_printf
    /* 858 80103058 F667A524 */   addiu     $a1, $a1, 0x67F6
    /* 85C 8010305C 8C4E028E */  lw         $v0, %lo(vs_battle_stringBuf)($s0)
    /* 860 80103060 00000000 */  nop
    /* 864 80103064 040042AE */  sw         $v0, 0x4($s2)
    /* 868 80103068 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 86C 8010306C 1800B28F */  lw         $s2, 0x18($sp)
    /* 870 80103070 1400B18F */  lw         $s1, 0x14($sp)
    /* 874 80103074 1000B08F */  lw         $s0, 0x10($sp)
    /* 878 80103078 0800E003 */  jr         $ra
    /* 87C 8010307C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80102F64
