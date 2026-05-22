nonmatching vs_battle_equipArmor, 0x6C

glabel vs_battle_equipArmor
    /* 2CB8 8006B4B8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2CBC 8006B4BC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2CC0 8006B4C0 0F80103C */  lui        $s0, %hi(vs_battle_characterState)
    /* 2CC4 8006B4C4 C0100400 */  sll        $v0, $a0, 3
    /* 2CC8 8006B4C8 23104400 */  subu       $v0, $v0, $a0
    /* 2CCC 8006B4CC C0100200 */  sll        $v0, $v0, 3
    /* 2CD0 8006B4D0 FC19038E */  lw         $v1, %lo(vs_battle_characterState)($s0)
    /* 2CD4 8006B4D4 23104400 */  subu       $v0, $v0, $a0
    /* 2CD8 8006B4D8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2CDC 8006B4DC 3C00638C */  lw         $v1, 0x3C($v1)
    /* 2CE0 8006B4E0 80100200 */  sll        $v0, $v0, 2
    /* 2CE4 8006B4E4 21104300 */  addu       $v0, $v0, $v1
    /* 2CE8 8006B4E8 44AC010C */  jal        vs_battle_applyArmor
    /* 2CEC 8006B4EC B8034424 */   addiu     $a0, $v0, 0x3B8
    /* 2CF0 8006B4F0 FC19028E */  lw         $v0, %lo(vs_battle_characterState)($s0)
    /* 2CF4 8006B4F4 00000000 */  nop
    /* 2CF8 8006B4F8 3C00448C */  lw         $a0, 0x3C($v0)
    /* 2CFC 8006B4FC 83AC010C */  jal        vs_battle_nop0
    /* 2D00 8006B500 00000000 */   nop
    /* 2D04 8006B504 85AC010C */  jal        func_8006B214
    /* 2D08 8006B508 00000000 */   nop
    /* 2D0C 8006B50C B5AC010C */  jal        func_8006B2D4
    /* 2D10 8006B510 00000000 */   nop
    /* 2D14 8006B514 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2D18 8006B518 1000B08F */  lw         $s0, 0x10($sp)
    /* 2D1C 8006B51C 0800E003 */  jr         $ra
    /* 2D20 8006B520 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_equipArmor
