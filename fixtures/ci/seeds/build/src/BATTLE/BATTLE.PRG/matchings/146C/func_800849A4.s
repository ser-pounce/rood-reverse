nonmatching func_800849A4, 0x4C

glabel func_800849A4
    /* 1C1A4 800849A4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C1A8 800849A8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C1AC 800849AC 2180C000 */  addu       $s0, $a2, $zero
    /* 1C1B0 800849B0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1C1B4 800849B4 EA09010C */  jal        vs_main_getRand
    /* 1C1B8 800849B8 04000424 */   addiu     $a0, $zero, 0x4
    /* 1C1BC 800849BC FFF30324 */  addiu      $v1, $zero, -0xC01
    /* 1C1C0 800849C0 1C00048E */  lw         $a0, 0x1C($s0)
    /* 1C1C4 800849C4 01004224 */  addiu      $v0, $v0, 0x1
    /* 1C1C8 800849C8 24208300 */  and        $a0, $a0, $v1
    /* 1C1CC 800849CC 0E000396 */  lhu        $v1, 0xE($s0)
    /* 1C1D0 800849D0 00088434 */  ori        $a0, $a0, 0x800
    /* 1C1D4 800849D4 1C0004AE */  sw         $a0, 0x1C($s0)
    /* 1C1D8 800849D8 21186200 */  addu       $v1, $v1, $v0
    /* 1C1DC 800849DC 0E0003A6 */  sh         $v1, 0xE($s0)
    /* 1C1E0 800849E0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1C1E4 800849E4 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C1E8 800849E8 0800E003 */  jr         $ra
    /* 1C1EC 800849EC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800849A4
