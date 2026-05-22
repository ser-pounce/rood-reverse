nonmatching _setWeaponUi, 0x7C

glabel _setWeaponUi
    /* 19E0 801041E0 40FEBD27 */  addiu      $sp, $sp, -0x1C0
    /* 19E4 801041E4 21188000 */  addu       $v1, $a0, $zero
    /* 19E8 801041E8 AC01B1AF */  sw         $s1, 0x1AC($sp)
    /* 19EC 801041EC 2188A000 */  addu       $s1, $a1, $zero
    /* 19F0 801041F0 B001B2AF */  sw         $s2, 0x1B0($sp)
    /* 19F4 801041F4 2190C000 */  addu       $s2, $a2, $zero
    /* 19F8 801041F8 B401B3AF */  sw         $s3, 0x1B4($sp)
    /* 19FC 801041FC 2198E000 */  addu       $s3, $a3, $zero
    /* 1A00 80104200 1000A427 */  addiu      $a0, $sp, 0x10
    /* 1A04 80104204 D001A28F */  lw         $v0, 0x1D0($sp)
    /* 1A08 80104208 21306000 */  addu       $a2, $v1, $zero
    /* 1A0C 8010420C B801BFAF */  sw         $ra, 0x1B8($sp)
    /* 1A10 80104210 A801B0AF */  sw         $s0, 0x1A8($sp)
    /* 1A14 80104214 40110200 */  sll        $v0, $v0, 5
    /* 1A18 80104218 2180C200 */  addu       $s0, $a2, $v0
    /* 1A1C 8010421C 8D0A040C */  jal        vs_menuD_initUiWeapon
    /* 1A20 80104220 21280002 */   addu      $a1, $s0, $zero
    /* 1A24 80104224 1000A427 */  addiu      $a0, $sp, 0x10
    /* 1A28 80104228 21282002 */  addu       $a1, $s1, $zero
    /* 1A2C 8010422C 21304002 */  addu       $a2, $s2, $zero
    /* 1A30 80104230 17F2030C */  jal        vs_mainMenu_setUiWeapon
    /* 1A34 80104234 21386002 */   addu      $a3, $s3, $zero
    /* 1A38 80104238 08001026 */  addiu      $s0, $s0, 0x8
    /* 1A3C 8010423C 000030AE */  sw         $s0, 0x0($s1)
    /* 1A40 80104240 B801BF8F */  lw         $ra, 0x1B8($sp)
    /* 1A44 80104244 B401B38F */  lw         $s3, 0x1B4($sp)
    /* 1A48 80104248 B001B28F */  lw         $s2, 0x1B0($sp)
    /* 1A4C 8010424C AC01B18F */  lw         $s1, 0x1AC($sp)
    /* 1A50 80104250 A801B08F */  lw         $s0, 0x1A8($sp)
    /* 1A54 80104254 0800E003 */  jr         $ra
    /* 1A58 80104258 C001BD27 */   addiu     $sp, $sp, 0x1C0
endlabel _setWeaponUi
