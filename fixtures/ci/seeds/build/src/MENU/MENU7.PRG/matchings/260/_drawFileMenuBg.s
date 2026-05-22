nonmatching _drawFileMenuBg, 0x48

glabel _drawFileMenuBg
    /* 3880 80106080 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3884 80106084 00010424 */  addiu      $a0, $zero, 0x100
    /* 3888 80106088 F038053C */  lui        $a1, (0x38F00000 >> 16)
    /* 388C 8010608C B000063C */  lui        $a2, (0xB00040 >> 16)
    /* 3890 80106090 4000C634 */  ori        $a2, $a2, (0xB00040 & 0xFFFF)
    /* 3894 80106094 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3898 80106098 B011040C */  jal        _drawSprt
    /* 389C 8010609C 9C000724 */   addiu     $a3, $zero, 0x9C
    /* 38A0 801060A0 21200000 */  addu       $a0, $zero, $zero
    /* 38A4 801060A4 F038053C */  lui        $a1, (0x38F00000 >> 16)
    /* 38A8 801060A8 B000063C */  lui        $a2, (0xB00100 >> 16)
    /* 38AC 801060AC 0001C634 */  ori        $a2, $a2, (0xB00100 & 0xFFFF)
    /* 38B0 801060B0 B011040C */  jal        _drawSprt
    /* 38B4 801060B4 9A000724 */   addiu     $a3, $zero, 0x9A
    /* 38B8 801060B8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 38BC 801060BC 00000000 */  nop
    /* 38C0 801060C0 0800E003 */  jr         $ra
    /* 38C4 801060C4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _drawFileMenuBg
