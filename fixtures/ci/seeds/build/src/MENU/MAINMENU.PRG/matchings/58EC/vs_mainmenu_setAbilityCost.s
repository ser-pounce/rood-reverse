nonmatching vs_mainmenu_setAbilityCost, 0x64

glabel vs_mainmenu_setAbilityCost
    /* 6900 80100100 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6904 80100104 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6908 80100108 2190C000 */  addu       $s2, $a2, $zero
    /* 690C 8010010C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6910 80100110 2188E000 */  addu       $s1, $a3, $zero
    /* 6914 80100114 1080033C */  lui        $v1, %hi(vs_mainMenu_isLevelledSpell)
    /* 6918 80100118 01000224 */  addiu      $v0, $zero, 0x1
    /* 691C 8010011C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6920 80100120 00810400 */  sll        $s0, $a0, 4
    /* 6924 80100124 D42262A0 */  sb         $v0, %lo(vs_mainMenu_isLevelledSpell)($v1)
    /* 6928 80100128 1080023C */  lui        $v0, %hi(_textHeaders)
    /* 692C 8010012C 58254224 */  addiu      $v0, $v0, %lo(_textHeaders)
    /* 6930 80100130 21800202 */  addu       $s0, $s0, $v0
    /* 6934 80100134 21200002 */  addu       $a0, $s0, $zero
    /* 6938 80100138 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 693C 8010013C 0D33030C */  jal        vs_battle_rMemcpy
    /* 6940 80100140 0E000624 */   addiu     $a2, $zero, 0xE
    /* 6944 80100144 0E0011A2 */  sb         $s1, 0xE($s0)
    /* 6948 80100148 0F0012A2 */  sb         $s2, 0xF($s0)
    /* 694C 8010014C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6950 80100150 1800B28F */  lw         $s2, 0x18($sp)
    /* 6954 80100154 1400B18F */  lw         $s1, 0x14($sp)
    /* 6958 80100158 1000B08F */  lw         $s0, 0x10($sp)
    /* 695C 8010015C 0800E003 */  jr         $ra
    /* 6960 80100160 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_mainmenu_setAbilityCost
