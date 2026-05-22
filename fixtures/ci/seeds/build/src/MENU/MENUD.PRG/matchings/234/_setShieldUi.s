nonmatching _setShieldUi, 0x74

glabel _setShieldUi
    /* 1A5C 8010425C 78FEBD27 */  addiu      $sp, $sp, -0x188
    /* 1A60 80104260 21188000 */  addu       $v1, $a0, $zero
    /* 1A64 80104264 7801B0AF */  sw         $s0, 0x178($sp)
    /* 1A68 80104268 2180A000 */  addu       $s0, $a1, $zero
    /* 1A6C 8010426C 7C01B1AF */  sw         $s1, 0x17C($sp)
    /* 1A70 80104270 2188C000 */  addu       $s1, $a2, $zero
    /* 1A74 80104274 8001B2AF */  sw         $s2, 0x180($sp)
    /* 1A78 80104278 2190E000 */  addu       $s2, $a3, $zero
    /* 1A7C 8010427C 1000A427 */  addiu      $a0, $sp, 0x10
    /* 1A80 80104280 9801A28F */  lw         $v0, 0x198($sp)
    /* 1A84 80104284 21306000 */  addu       $a2, $v1, $zero
    /* 1A88 80104288 8401BFAF */  sw         $ra, 0x184($sp)
    /* 1A8C 8010428C 40280200 */  sll        $a1, $v0, 1
    /* 1A90 80104290 2128A200 */  addu       $a1, $a1, $v0
    /* 1A94 80104294 00290500 */  sll        $a1, $a1, 4
    /* 1A98 80104298 0004A524 */  addiu      $a1, $a1, 0x400
    /* 1A9C 8010429C EC0A040C */  jal        vs_menuD_initUiShield
    /* 1AA0 801042A0 2128C500 */   addu      $a1, $a2, $a1
    /* 1AA4 801042A4 1000A427 */  addiu      $a0, $sp, 0x10
    /* 1AA8 801042A8 21280002 */  addu       $a1, $s0, $zero
    /* 1AAC 801042AC 21302002 */  addu       $a2, $s1, $zero
    /* 1AB0 801042B0 3AF3030C */  jal        vs_mainMenu_setUiShield
    /* 1AB4 801042B4 21384002 */   addu      $a3, $s2, $zero
    /* 1AB8 801042B8 8401BF8F */  lw         $ra, 0x184($sp)
    /* 1ABC 801042BC 8001B28F */  lw         $s2, 0x180($sp)
    /* 1AC0 801042C0 7C01B18F */  lw         $s1, 0x17C($sp)
    /* 1AC4 801042C4 7801B08F */  lw         $s0, 0x178($sp)
    /* 1AC8 801042C8 0800E003 */  jr         $ra
    /* 1ACC 801042CC 8801BD27 */   addiu     $sp, $sp, 0x188
endlabel _setShieldUi
