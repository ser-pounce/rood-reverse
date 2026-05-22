nonmatching vs_battle_script_playMenuSelectSfx, 0x24

glabel vs_battle_script_playMenuSelectSfx
    /* 52E68 800BB668 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52E6C 800BB66C 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 52E70 800BB670 1000BFAF */  sw         $ra, 0x10($sp)
    /* 52E74 800BB674 6216010C */  jal        vs_main_playSfxDefault
    /* 52E78 800BB678 05000524 */   addiu     $a1, $zero, 0x5
    /* 52E7C 800BB67C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 52E80 800BB680 21100000 */  addu       $v0, $zero, $zero
    /* 52E84 800BB684 0800E003 */  jr         $ra
    /* 52E88 800BB688 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_playMenuSelectSfx
