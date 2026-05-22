nonmatching vs_mainMenu_setGemStats, 0xC4

glabel vs_mainMenu_setGemStats
    /* 4078 800FD878 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 407C 800FD87C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4080 800FD880 21808000 */  addu       $s0, $a0, $zero
    /* 4084 800FD884 21280000 */  addu       $a1, $zero, $zero
    /* 4088 800FD888 20000824 */  addiu      $t0, $zero, 0x20
    /* 408C 800FD88C 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentStats)
    /* 4090 800FD890 C0244924 */  addiu      $t1, $v0, %lo(vs_mainMenu_equipmentStats)
    /* 4094 800FD894 21382001 */  addu       $a3, $t1, $zero
    /* 4098 800FD898 1080033C */  lui        $v1, %hi(vs_mainMenu_gems)
    /* 409C 800FD89C C0101000 */  sll        $v0, $s0, 3
    /* 40A0 800FD8A0 23105000 */  subu       $v0, $v0, $s0
    /* 40A4 800FD8A4 80100200 */  sll        $v0, $v0, 2
    /* 40A8 800FD8A8 5824638C */  lw         $v1, %lo(vs_mainMenu_gems)($v1)
    /* 40AC 800FD8AC E4FF4224 */  addiu      $v0, $v0, -0x1C
    /* 40B0 800FD8B0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 40B4 800FD8B4 21306200 */  addu       $a2, $v1, $v0
  .L800FD8B8:
    /* 40B8 800FD8B8 21200901 */  addu       $a0, $t0, $t1
    /* 40BC 800FD8BC 02000825 */  addiu      $t0, $t0, 0x2
    /* 40C0 800FD8C0 0700A330 */  andi       $v1, $a1, 0x7
    /* 40C4 800FD8C4 2118C300 */  addu       $v1, $a2, $v1
    /* 40C8 800FD8C8 08006290 */  lbu        $v0, 0x8($v1)
    /* 40CC 800FD8CC 0100A524 */  addiu      $a1, $a1, 0x1
    /* 40D0 800FD8D0 00160200 */  sll        $v0, $v0, 24
    /* 40D4 800FD8D4 03160200 */  sra        $v0, $v0, 24
    /* 40D8 800FD8D8 0000E2A4 */  sh         $v0, 0x0($a3)
    /* 40DC 800FD8DC 10006290 */  lbu        $v0, 0x10($v1)
    /* 40E0 800FD8E0 00000000 */  nop
    /* 40E4 800FD8E4 00160200 */  sll        $v0, $v0, 24
    /* 40E8 800FD8E8 03160200 */  sra        $v0, $v0, 24
    /* 40EC 800FD8EC 000082A4 */  sh         $v0, 0x0($a0)
    /* 40F0 800FD8F0 1000A228 */  slti       $v0, $a1, 0x10
    /* 40F4 800FD8F4 F0FF4014 */  bnez       $v0, .L800FD8B8
    /* 40F8 800FD8F8 0200E724 */   addiu     $a3, $a3, 0x2
    /* 40FC 800FD8FC 0500C480 */  lb         $a0, 0x5($a2)
    /* 4100 800FD900 0600C580 */  lb         $a1, 0x6($a2)
    /* 4104 800FD904 0700C680 */  lb         $a2, 0x7($a2)
    /* 4108 800FD908 4AEF030C */  jal        vs_mainMenu_setStrIntAgi
    /* 410C 800FD90C 01000724 */   addiu     $a3, $zero, 0x1
    /* 4110 800FD910 03000424 */  addiu      $a0, $zero, 0x3
    /* 4114 800FD914 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 4118 800FD918 40000324 */  addiu      $v1, $zero, 0x40
    /* 411C 800FD91C 452543A0 */  sb         $v1, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 4120 800FD920 1080023C */  lui        $v0, %hi(D_801024A1)
    /* 4124 800FD924 E3EE030C */  jal        func_800FBB8C
    /* 4128 800FD928 A12450A0 */   sb        $s0, %lo(D_801024A1)($v0)
    /* 412C 800FD92C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4130 800FD930 1000B08F */  lw         $s0, 0x10($sp)
    /* 4134 800FD934 0800E003 */  jr         $ra
    /* 4138 800FD938 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_mainMenu_setGemStats
