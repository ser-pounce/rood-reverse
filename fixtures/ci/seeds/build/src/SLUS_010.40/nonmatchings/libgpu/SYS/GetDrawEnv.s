nonmatching GetDrawEnv, 0x34

glabel GetDrawEnv
    /* 1964C 80028E4C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 19650 80028E50 1000B0AF */  sw         $s0, 0x10($sp)
    /* 19654 80028E54 21808000 */  addu       $s0, $a0, $zero
    /* 19658 80028E58 0380053C */  lui        $a1, %hi(D_80033454)
    /* 1965C 80028E5C 5434A524 */  addiu      $a1, $a1, %lo(D_80033454)
    /* 19660 80028E60 1400BFAF */  sw         $ra, 0x14($sp)
    /* 19664 80028E64 A99B000C */  jal        memcpy
    /* 19668 80028E68 5C000624 */   addiu     $a2, $zero, 0x5C
    /* 1966C 80028E6C 21100002 */  addu       $v0, $s0, $zero
    /* 19670 80028E70 1400BF8F */  lw         $ra, 0x14($sp)
    /* 19674 80028E74 1000B08F */  lw         $s0, 0x10($sp)
    /* 19678 80028E78 0800E003 */  jr         $ra
    /* 1967C 80028E7C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel GetDrawEnv
