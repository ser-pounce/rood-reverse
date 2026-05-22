nonmatching _drawFileMenuBg, 0x48

glabel _drawFileMenuBg
    /* 3914 8006C114 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3918 8006C118 00010424 */  addiu      $a0, $zero, 0x100
    /* 391C 8006C11C F038053C */  lui        $a1, (0x38F00000 >> 16)
    /* 3920 8006C120 B000063C */  lui        $a2, (0xB00040 >> 16)
    /* 3924 8006C124 4000C634 */  ori        $a2, $a2, (0xB00040 & 0xFFFF)
    /* 3928 8006C128 1000BFAF */  sw         $ra, 0x10($sp)
    /* 392C 8006C12C DEA9010C */  jal        _drawSprt
    /* 3930 8006C130 9C000724 */   addiu     $a3, $zero, 0x9C
    /* 3934 8006C134 21200000 */  addu       $a0, $zero, $zero
    /* 3938 8006C138 F038053C */  lui        $a1, (0x38F00000 >> 16)
    /* 393C 8006C13C B000063C */  lui        $a2, (0xB00100 >> 16)
    /* 3940 8006C140 0001C634 */  ori        $a2, $a2, (0xB00100 & 0xFFFF)
    /* 3944 8006C144 DEA9010C */  jal        _drawSprt
    /* 3948 8006C148 9A000724 */   addiu     $a3, $zero, 0x9A
    /* 394C 8006C14C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3950 8006C150 00000000 */  nop
    /* 3954 8006C154 0800E003 */  jr         $ra
    /* 3958 8006C158 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _drawFileMenuBg
