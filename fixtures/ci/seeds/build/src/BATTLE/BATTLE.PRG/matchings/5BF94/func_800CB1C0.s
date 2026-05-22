nonmatching func_800CB1C0, 0x48

glabel func_800CB1C0
    /* 629C0 800CB1C0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 629C4 800CB1C4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 629C8 800CB1C8 21808000 */  addu       $s0, $a0, $zero
    /* 629CC 800CB1CC 07000424 */  addiu      $a0, $zero, 0x7
    /* 629D0 800CB1D0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 629D4 800CB1D4 342B030C */  jal        func_800CACD0
    /* 629D8 800CB1D8 02000524 */   addiu     $a1, $zero, 0x2
    /* 629DC 800CB1DC 0F80043C */  lui        $a0, %hi(D_800F4E6B)
    /* 629E0 800CB1E0 0F80033C */  lui        $v1, %hi(D_800F4EA0)
    /* 629E4 800CB1E4 A04E628C */  lw         $v0, %lo(D_800F4EA0)($v1)
    /* 629E8 800CB1E8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 629EC 800CB1EC 40001026 */  addiu      $s0, $s0, 0x40
    /* 629F0 800CB1F0 6B4E90A0 */  sb         $s0, %lo(D_800F4E6B)($a0)
    /* 629F4 800CB1F4 1000B08F */  lw         $s0, 0x10($sp)
    /* 629F8 800CB1F8 00044234 */  ori        $v0, $v0, 0x400
    /* 629FC 800CB1FC A04E62AC */  sw         $v0, %lo(D_800F4EA0)($v1)
    /* 62A00 800CB200 0800E003 */  jr         $ra
    /* 62A04 800CB204 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CB1C0
